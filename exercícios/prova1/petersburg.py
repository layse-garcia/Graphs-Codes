# coding: utf-8

# PROVA 1 - Algoritmos em Grafos
# URI 1209: Festas de São Petersburgo
#
# RESUMO DO PROBLEMA:  São Petesburgo é uma das cidades mais alternativas.
# 					   Logo percebeu que a cidade poderia se transformar em um
# 					   grande centro de encontros(festas, raves...).
# 					   As festas de São Petersburgo sempre cheias, devido a amizade
# 					   dos participantes em redes sociais. Logo, a pessoa precisa ter
# 					   pelo menos um número K de amigos na lista de convidados.
#
# SOLUÇÃO:  Após fazermos o esboço do primeiro exemplo do exercício e rabiscar,
#           chegamos a conclusão de que a maneira mais rápida de encontrar o resultado
#           era percorrendo o grafo a cada iteração, cortando aresta e removendo os vértices com grau
#           menor que o valor "k" indicado
#
#           O algoritmo encerra para o grafo quando em uma iteração ele não remove nenhum vértice
#
# ALUNOS: Kellyson Santos da Silva - 2018200366 - 10A
#		  Layse Cristina Silva Garcia - 201811177 - 10A
#
# 20/08/2020
#

# Classe Vértice
class Vertice:
    # Construtor da Classe Vértice
    def __init__(self, id):
        self.id = id
        self.vizinhos = []

    # Adiciona vizinhos no vértice
    def add(self, vertice):
        self.vizinhos.append(vertice)

    # Remove o vizinho do vértice
    def removerVizinho(self, vertice):
        if self.vizinhos.count(vertice) > 0:
            self.vizinhos.remove(vertice)

    # Retorna a lista de vizinhos
    def getGrau(self):
        return len(self.vizinhos)

    # Retorna o ID do vértice
    def getId(self):
        return self.id

# Classe Grafo : Grafo não direcionado
class Grafo:
    # Construtor da Classe
    def __init__(self, tamanho):
        self.vertices = [Vertice(i + 1) for i in range(tamanho)]

    # Método que adiciona a aresta no grafo
    def adicionarAresta(self, aresta):
        v1 = self.getVerticePeloIndex(aresta[0])
        v2 = self.getVerticePeloIndex(aresta[1])
        v1.add(v2)
        v2.add(v1)

    # Obtém o vértice através do índice
    def getVerticePeloIndex(self, index):
        return self.vertices[index - 1]

    # Método que retira as arestas do vértice que não possui a restrição
    def removerVizinhoDosVertices(self, vertice):
        for item in self.vertices:
            item.removerVizinho(vertice)

    # Removo os vizinhos do vértice que estou, chamando a função acima
    def removerVertice(self, vertice):
        removerVizinhoDosVertices(vertice)

    # A cada iteração percorre os vértices do grafo
    # e remove aqueles que não possuem amigos suficientes
    # para participar da festa, até que todos possam participar
    def tratarConvidados(self, k):
        continua = True

        while continua:
            continua = False
            for vertice in self.vertices:
                if vertice.getGrau() < k:
                    continua = True
                    self.removerVizinhoDosVertices(vertice)
                    self.vertices.remove(vertice)

        return self.vertices

def main():
    declaracoes = input().split(" ")
    declaracoes = integerList(declaracoes)

    # Captura os valores de:
    #    pessoas = pessoas da Comunidade,
    #    conexoes = relacoes de Amizade
    #    k = número minimo de Amigos
    pessoas, conexoes, k = declaracoes[0], declaracoes[1], declaracoes[2]

    # Cria o Grafo baseado na quantidade de pessoas
    grafo = Grafo(pessoas)

    # Adiciono aresta ao receber os pares de amizade
    for i in range(conexoes):
        aresta = integerList(input().split(" "))
        grafo.adicionarAresta(aresta)

    # Vou removendo os vértices que não obedecem a minha restrição
    verticesRestantes = grafo.tratarConvidados(k)
    resultado = formatarResposta(verticesRestantes) if len(verticesRestantes) > 0 else "0"

    # Imprimo o resultado já em formato exigido
    print(resultado)

# Auxiliar: converte o tipo da lista dada para <int>
def integerList(lista):
    return list(map(int, lista))

# Formata a resposta de acordo com o exigido no enunciado
def formatarResposta(lista):

    resposta = ""
    end = len(lista) - 1

    for idx, item in enumerate(lista):
        resposta += str(item.getId())
        if idx != end:
            resposta += " "

    return resposta

# Inicia o algoritmo e encerra quando EOF
while True:
    try:
        main()
    except:
        break
