class Vertice:
  # Construtor do Vertice
  def __init__(self, pessoa, tipoPessoa):
	self.pessoa = pessoa
	self.cor = -1
	self.tipoPessoa = tipoPessoa
	
	def getPessoa(self):
		return self.pessoa
	
	def getCor(self):
		return self.cor
		
	def getTipoPessoa(self):
		return self.tipoPessoa
		
	# Destrutor - chamando o destrutor
    def __del__(self): 
        print('Destrutor chamado.') 
  
v1 = Vertice() 
del v1 
		
listaPessoas = []
listaPessoas.append(Pessoa(idade, sexo, cidade, quadroDeRisco, tempoMedio, horarioDePreferencia, diasDaSemana, sintomas))

# A class to represent the adjacency list of the node 
class AdjNode: 
	def __init__(self, data): 
		self.vertex = data 
		self.next = None

class Grafo:
	# Construtor do Grafo
	def __init__(self, vertices): 
		self.V = vertices 
		#self.listaAdjacencia = [{0 for column in range(vertices)}\for row in range(vertices)] #Ver se funciona
		self.listaAdjacencia = [None] * self.V
		
	# Função que adiciona uma aresta em um grafo não direcionado
	def adicionaAresta(self, src, dest):
		# Adicionando o nó para o vértice De
		noh = AdjNode(dest) 
		noh.next = self.listaAdjacencia[src] 
		self.listaAdjacencia[src] = noh 
  
		# Adicionando o nó para o vértice Para
		# it is the undirected graph 
		noh = AdjNode(src) 
		noh.next = self.listaAdjacencia[dest] 
		self.listaAdjacencia[dest] = noh 
       
# Exemplo
meuGrafo = Grafo(4) 
#meuGrafo.listaAdjacencia = [[0, 1, 1, 1], [1, 0, 1, 0], [1, 1, 0, 1], [1, 0, 1, 0]]

meuGrafo.adicionaAresta(0, 1) 
meuGrafo.adicionaAresta(0, 2) 
meuGrafo.adicionaAresta(1, 2) 
