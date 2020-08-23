# coding: utf-8

###############################################################################
######             TRABALHO PRÁTICO : ALGORITMO EM GRAFOS                ######
######                   TEMA: COLORAÇÃO EM GRAFOS                       ######
######                                                                   ######
######                      Python Version: 3.8                          ######
######                                                                   ######
######      KELLYSON SANTOS DA SILVA - 201820366 - 10A                   ######
######      LAYSE CRISTINA SILVA GARCIA - 201811177 - 10A                ######
###############################################################################
'''------------------------------------------------------------Imports------------------------------------------------------------'''
from .Pessoa import Pessoa
'''-------------------------------------------------------------------------------------------------------------------------------'''

'''
    Classe Vértice é responsável por armazenar uma Pessoa. O vértice representa
    a pessoa e sua cor é dada pelo horário. Observe que é necessário ver quem são
    seus vizinhos e quais as cores dos mesmos.
    A Classe Vértice define as ligações das pessoas. Pessoas de Risco se ligam a
    Pessoas de Não Risco.
'''

class Vertice:

    # Construtor do Vertice
    def __init__(self, pessoa):
        self.pessoa = pessoa
        self.cor = (-1, -1)
        self.vizinhos = []

    # Retorna o objeto pessoa
    def getPessoa(self):
        return self.pessoa

    # Retorna a cor do vértice(representando o horário)
    def getCor(self):
        return self.cor

    # Define a cor do vértice
    def setCor(self, cor):
        self.cor = cor

    # Retorna os vizinhos do vértice
    def getVizinhos(self):
        return self.vizinhos

    # Método que adiciona os vértice vizinhos na lista de vizinhos
    def add(self, vertice):
        self.vizinhos.append(vertice)

    # Pega as cores vizinhas dos vértices
    def getCoresVizinhas(self):
        return [vizinho.cor for vizinho in self.vizinhos]

    def horariosImpedidos(self):
        return [vizinho.cor for vizinho in self.vizinhos]

    # Método que decide se um vértice é incompatível com outro
    # Retorna TRUE se deve ser criada uma aresta
    def compare(self, vertice):
        saoGrupoRisco = self.pessoa.getQuadroDeRisco() != vertice.pessoa.getQuadroDeRisco()
        return saoGrupoRisco
