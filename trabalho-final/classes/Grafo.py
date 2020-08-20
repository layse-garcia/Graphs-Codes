# coding: utf-8

###############################################################################
######            TRABALHO PRÁTICO : ALGORITMO EM GRAFOS                 ######
######                  TEMA: COLORAÇÃO EM GRAFOS                        ######
######                                                                   ######
######      KELLYSON SANTOS DA SILVA - 201820366 - 10A                   ######
######      LAYSE CRISTINA SILVA GARCIA - 201811177 - 10A                ######
###############################################################################

from Vertice import Vertice
from Pessoa import Pessoa
from enum.Enums import Enums
import copy

'''
A classe Grafo ('-')

Ela representa a parte principal do projeto, armazenando o grafo em
uma estrutura, e contendo em seus métodos os algoritmos necessários
para a execução do projeto como um todo.

Neste problema utilizamos lista de adjacencias para representar
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

    def gerarHorario(self):

        self.priorizarGrupoDeRisco()

        # Percorre cada vértice do grafo
        for vertice in self.graph:

            horariosPossiveis = vertice.pessoa.horarioDePreferencia
            diasPossiveis = vertice.pessoa.diasDaSemana

            counter = 0
            disponivel = False

            vertice.cor = self.horariosPossiveis(vertice.vizinhos, diasPossiveis, horariosPossiveis)

            # Caso encontre, insere essa pessoa nesse horário
            # if disponivel:
            #     vertice.setCor(corAtual)
            # else:
            #     vertice.setCor(-999)

    '''
        Ainda não testei o método abaixo
        Mas ele retorna um possível horário de acordo com as combinações dadas e seus vizinhos
    '''
    def horariosPossiveis(self, vizinhos, dias, horarios):

        for vizinho in vizinhos:

            for horario in horarios:
                for dia in dias:

                    umHorario = (horario, dia)
                    if vizinho.cor != umHorario:
                        return umHorario

        return (-3, -3) # Tecnicamente um erro aleatorio só para identificarmos que ocorreu

    # Em relação aos horários nesta aplicação, pessoas de risco têm preferência
    def priorizarGrupoDeRisco(self):

        lista = list(self.graph)

        for vertice in self.graph:
            if (vertice.pessoa.quadroDeRisco):
                lista.remove(vertice)
                lista.insert(0, vertice)

        self.graph = lista

    # Só serve pra imprimeir quantos vizinhos tem cada vértice
    # Nada mais
    def GEROU_GRAFO(self):
        for node in self.graph:
            print(str(node.pessoa.index) + ' no dia ' + Enums.DIAS[node.cor[1]] + ' às ' + Enums.HORARIOS[node.cor[0]])

        print("Criei um index com a linha :)")
