# coding: utf-8
from Vertice import Vertice
from Pessoa import Pessoa

'''
A classe Grafo ('-')

Ela representa a parte principal do projeto, armazenando o grafo em
uma estrutura, e contendo em seus métodos os algoritmos necessários
para a execução do projeto como um todo.

Neste problema utilizamos lista de adjacencias para representar
nosso grafo :)
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

    # Só serve pra imprimeir quantos vizinhos tem cada vértice
    # Nada mais
    def GEROU_GRAFO(self):
        for node in self.graph:
            print(len(node.vizinhos))
