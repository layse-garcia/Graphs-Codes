# coding: utf-8

###############################################################################
######             TRABALHO PRÁTICO : ALGORITMO EM GRAFOS                ######
######                   TEMA: COLORAÇÃO EM GRAFOS                       ######
######                                                                   ######
######                      Python Version: 2.7                          ######
######                                                                   ######
######      KELLYSON SANTOS DA SILVA - 201820366 - 10A                   ######
######      LAYSE CRISTINA SILVA GARCIA - 201811177 - 10A                ######
###############################################################################

'''------------------------------------------------------------Imports------------------------------------------------------------'''
from .Vertice import Vertice
from .Pessoa import Pessoa
from .Schedule import Schedule
from .enum.Enums import Enums

import copy
import random
import sys
'''-------------------------------------------------------------------------------------------------------------------------------'''

'''
A classe Grafo ( '-')

Ela representa a parte principal do projeto, armazenando o grafo em
uma estrutura, e contendo em seus métodos os algoritmos necessários
para a execução do projeto como um todo.

Neste problema utilizamos lista de adjacências para representar
nosso grafo :)
'''

class Grafo:

    # O construtor da nossa instância
    def __init__(self, pessoas, cidade):

        if len(pessoas) > 0:
            self.totalVertices = len(pessoas)
            self.graph = self.prepararGrafo(pessoas, cidade)

        else:
            raise PessoasException('Não temos pessoas aqui, algo de errado não está certo')

    # Através das pessoas recebidas inicia um Grafo
    # e trata de criar as arestas iniciais
    def prepararGrafo(self, pessoas, cidade):

        lista = []

        for pessoa in pessoas:
            if not pessoa.getSintomas():
                if cidade == 'Todos' or pessoa.getCidade() == cidade:
                    lista.append(Vertice(pessoa))

        # Encerra o programa caso não encontrem dados com as informações fornecidas
        if len(lista) < 1:
            print('\nOps! Nenhum dado foi encontrado através das informações fornecidas :(\nVerifique as informações e tente novamente.\n')
            sys.exit()

        for vertex in lista:
            for innerVertex in lista:

                if vertex.compare(innerVertex):
                    vertex.add(innerVertex)

        return lista

    # Método que incializa a Coloração podendo ou não dar prioridade as pessoas
    # do Grupo de Risco. Também chama a função que encontra o melhor horário, de
    # acordo com os dados fornecidos da pessoa e analisa os horários já preenchidos.
    def iniciarColoracao(self, limite = 5, priorizarGR = False):

        if priorizarGR:
            self.priorizarGrupoDeRisco()

        # Percorre cada vértice do grafo
        for vertice in self.graph:

            horariosPossiveis = vertice.pessoa.horarioDePreferencia
            diasPossiveis = vertice.pessoa.diasDaSemana

            vertice.cor = self.encontrarHorario(diasPossiveis, horariosPossiveis, vertice.horariosImpedidos())

    # Método que realoca uma pessoa em algum diae horário possível.
    # Define que se existir uma pessoa do mesmo Grupo em um horário coincidente
    # ao possível realocamento, então continua retornando a cor.
    def realocarUmVertice(self, notForeverAlone):

        indice = [i for i in range(len(self.graph))]
        random.shuffle(indice)

        grafo = self.graph

        for i in indice:

            ambosMesmoGrupo = grafo[i].pessoa.getQuadroDeRisco() == notForeverAlone.pessoa.getQuadroDeRisco()
            corValida = grafo[i].cor != (-404, -404)

            if ambosMesmoGrupo and corValida:
                return grafo[i].cor

    # Método que identifica os vértices não coloridos e tenta os realocar
    def refinarColoracao(self):
        for vertice in self.graph:
            if vertice.cor == (-404, -404):
                vertice.cor = self.realocarUmVertice(vertice)

    # Método que cria a Agenda baseado no Grafo criado
    def prepararAgenda(self):

        self.schedule = Schedule()

        for pessoa in self.graph:
            self.schedule.insert(pessoa, pessoa.cor[0], pessoa.cor[1])

        print("Sua agenda foi gerada")

    # Método que calcula um possível horário para alocar
    def encontrarHorario(self, dias, horarios, impedimentos):

        # Tentativa de espalhar os horários randomicamente
        random.shuffle(dias)
        random.shuffle(horarios)

        for dia in dias:
            for horario in horarios:
                if impedimentos.count((dia, horario)) == 0:
                    return(dia, horario)

        return (-404, -404) # Definido como erro de horario não encontrado no nosso projeto

    # Em relação aos horários nesta aplicação, pessoas de risco têm preferência
    def priorizarGrupoDeRisco(self):

        lista = list(self.graph)

        for vertice in self.graph:
            if (vertice.pessoa.quadroDeRisco):
                lista.remove(vertice)
                lista.insert(0, vertice)

        self.graph = lista

    # Chama o método de refinamento dos horários da agenda
    def refinarAgenda(self, maximo):
        if maximo > 0:
            self.schedule.refinar(maximo)
