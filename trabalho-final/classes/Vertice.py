# coding: utf-8

###############################################################################
######            TRABALHO PRÁTICO : ALGORITMO EM GRAFOS                 ######
######                  TEMA: COLORAÇÃO EM GRAFOS                        ######
######                                                                   ######
######      KELLYSON SANTOS DA SILVA - 201820366 - 10A                   ######
######      LAYSE CRISTINA SILVA GARCIA - 201811177 - 10A                ######
###############################################################################

from Pessoa import Pessoa

class Vertice:
    # Construtor do Vertice
    def __init__(self, pessoa):
        self.pessoa = pessoa
        self.cor = (-1, -1)
        self.vizinhos = []

	def getPessoa(self):
		return self.pessoa

	def getCor(self):
		return self.cor

    def setCor(self, cor):
        self.cor = cor

    def getVizinhos(self):
        return self.vizinhos

    def add(self, vertice):
        self.vizinhos.append(vertice)

    def getCoresVizinhas(self):
        return [vizinho.cor for vizinho in self.vizinhos]

	# Destrutor - chamando o destrutor
    #def __del__(self):
        #print('Destruindo um vértice para que o mundo possa sobreviver')

    # Método que decide se um vértice é incompatível com outro
    # Retorna TRUE se deve ser criada uma aresta
    def compare(self, vertice):

        saoGrupoRisco = self.pessoa.getQuadroDeRisco() != vertice.pessoa.getQuadroDeRisco()

        return saoGrupoRisco
