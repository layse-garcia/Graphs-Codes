# coding: utf-8

###############################################################################
######             TRABALHO PRÁTICO : ALGORITMO EM GRAFOS                ######
######                   TEMA: COLORAÇÃO EM GRAFOS                       ######
######                                                                   ######
######                      Python Version: 3.4                          ######
######                                                                   ######
######      KELLYSON SANTOS DA SILVA - 201820366 - 10A                   ######
######      LAYSE CRISTINA SILVA GARCIA - 201811177 - 10A                ######
###############################################################################

'''------------------------------------------------------------Imports------------------------------------------------------------'''
from Vertice import Vertice
from Pessoa import Pessoa
from Schedule import Schedule
from enum.Enums import Enums

import copy
import random
'''-------------------------------------------------------------------------------------------------------------------------------'''

'''
A classe Grafo ( '-')

Ela representa a parte principal do projeto, armazenando o grafo em
uma estrutura, e contendo em seus métodos os algoritmos necessários
para a execução do projeto como um todo.

Neste problema utilizamos lista de adjacências para representar
nosso grafo :)
'''

'''
Resultados computacionais:
~ Instância teste: apresente a instância real que você vai resolver.
Priorize a resolução de instâncias reais. Caso os dados que você testará forem
proprietários, crie um esquema de geração de dados artificiais baseados no que
você viu na prática.
Isso é importante, para que sua simulação seja validada;
~ Experimentos: execute o seu algoritmo, indicando o valor da função objetivo
(distância, número de cores, etc), tempo computacional, e o impacto que sua
solução teria na prática;
~ Forças e fraquezas: explique as forças e fraquezas de sua abordagem, e comente
o que poderia ser melhorado (se for o caso);
'''

class Grafo:

    # O construtor da nossa instância
    def __init__(self, pessoas):

        if len(pessoas) > 0:
            self.totalVertices = len(pessoas)
            self.graph = self.prepararGrafo(pessoas)

        else:
            raise PessoasException('Não temos pessoas aqui, algo de errado não está certo')

    # Através das pessoas recebidas inicia um Grafo
    # e trata de criar as arestas iniciais
    def prepararGrafo(self, pessoas):

        lista = []

        for pessoa in pessoas:
            if not pessoa.getSintomas():
                lista.append(Vertice(pessoa))

        for vertex in lista:
            for innerVertex in lista:

                if vertex.compare(innerVertex):
                    vertex.add(innerVertex)

        return lista

    def iniciarColoracao(self, limite = 5, priorizarGR = False):

        if priorizarGR:
            self.priorizarGrupoDeRisco()

        # Percorre cada vértice do grafo
        for vertice in self.graph:

            horariosPossiveis = vertice.pessoa.horarioDePreferencia
            diasPossiveis = vertice.pessoa.diasDaSemana

            vertice.cor = self.encontrarHorario(diasPossiveis, horariosPossiveis, vertice.horariosImpedidos())

    def realocarUmVertice(self, notForeverAlone):

        indice = [i for i in range(len(self.graph))]
        random.shuffle(indice)

        grafo = self.graph

        for i in indice:

            ambosMesmoGrupo = grafo[i].pessoa.getQuadroDeRisco() == notForeverAlone.pessoa.getQuadroDeRisco()
            corValida = grafo[i].cor != (-404, -404)

            if ambosMesmoGrupo and corValida:
                return grafo[i].cor

    def refinarColoracao(self):
        for vertice in self.graph:
            if vertice.cor == (-404, -404):
                vertice.cor = self.realocarUmVertice(vertice)

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

    def refinarAgenda(self, maximo):
        if maximo > 0:
            self.schedule.refinar(maximo)

    # Só serve pra imprimeir quantos vizinhos tem cada vértice
    # Nada mais
    def GEROU_GRAFO(self):

        semana = [[[] for i in range(11)] for i in range(6)]

        for node in self.graph:
            if(node.cor[0] >= 0):
                semana[node.cor[0]][node.cor[1]].append(node.pessoa.quadroDeRisco)
            else:
                print(str(node.pessoa.index) + " não alocada")
                #print(str(node.pessoa.index) + ' no dia ' + Enums.DIAS[node.cor[1]] + ' às ' + Enums.HORARIOS[node.cor[0]])

        for idx, dia in enumerate(semana):
            print(Enums.DIAS[idx] + ":\n")

            for midx, horario in enumerate(dia):

                string = Enums.HORARIOS[midx] + " - "
                for carinha in horario:

                    string += str(carinha)# if carinha else "-"
                    string += ", "

                print(string)

            print("\n------\n")

        print("HORARIOS OCUPADOS: " + str(self.schedule.horariosUtilizados) + "/66")
