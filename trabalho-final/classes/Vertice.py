# coding: utf-8
from Pessoa import Pessoa

class Vertice:
    # Construtor do Vertice
    def __init__(self, pessoa):
        self.pessoa = pessoa
        self.cor = -1
        self.vizinhos = []

	def getPessoa(self):
		return self.pessoa

	def getCor(self):
		return self.cor

    def getVizinhos(self):
        return self.vizinhos

    def add(self, vetice):
        self.vizinhos.append(vertice)

	# Destrutor - chamando o destrutor
    #def __del__(self):
        #print('Destruindo um vértice para que o mundo possa sobreviver')

    # Método que decide se um vértice é incompatível com outro
    # Retorna TRUE se deve ser criada uma aresta
    def compare(self, vertice):
        print('Implementar método de comparação')
        return False
