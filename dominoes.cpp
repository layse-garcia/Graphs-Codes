//
// Algoritmo para verificar o maior caminho possível
// a partir de um determinado conjunto de peças de dominó
//
// UFLA - 2020/1
// Algoritimos em Grafos
// Kellyson Santos da Silva e Layse Cristina Silva Garcia
//

#include <iostream> 
#include <list> 

using namespace std; 

// Classe grafo - Utilizando lista de adjacência
class Grafo {
	
	private:
		int vertices; //Total de vértices
		list<int> *lista; //Array de listas de adjacência
	
	public:
		Grafo(int vertices);
	
		void novaAresta(int v1, int v2); //Método para adicionar uma nova aresta no grafo
		int calcularAltura(int raiz); //Calcula a altura da árvore
		int maiorAlcance(int raiz); //Método que calcula o caminho
	
}; 

Grafo::Grafo(int vertices) {
	
	this->vertices = vertices;
	lista = new list<int>[vertices];
	
} 

void Grafo::novaAresta(int v1, int v2) { 
	lista[v1].push_back(v2); //Adicionar v2 aos vizinhos de v1
}

int Grafo::calcularAltura(int raiz) {
	
	int altura = 0;
	
	list<int> listaAtual = lista[raiz];
	list<int> alturas(vertices);
	list<int> pilha;
	
	pilha.push_back(raiz);
	
	
	/*
	while(!pilha.empty()){
		
		
		
	}
	
	*/
	
	return altura;
	
}

int Grafo::maiorAlcance(int umVertice) {
	
	//Iniciando os vértices como não visitados
	bool *visitados = new bool[vertices];
	for(int i = 0; i < vertices; i++)
		visitados[i] = false;
	
	//Cria a fila para a busca em largura
	list<int> fila;
	
	//Nó atual é visitado
	visitados[umVertice] = true;
	fila.push_back(umVertice);
	
	//Iterador para acessar os vértices adjacentes
	list<int>::iterator i;
	
	Grafo arvore(vertices);
	
	while(!fila.empty()) {
		
		//Desenfileira um vertice
		umVertice = fila.front();
		fila.pop_front();
	
		// Adiciona os vértices vizinhos à árvore da BFS
		for (i = lista[umVertice].begin(); i != lista[umVertice].end(); ++i) {
			
			if (!visitados[*i]) {
				
				visitados[*i] = true;
				arvore.novaAresta(umVertice, *i);
				fila.push_back(*i);
				
			}
		}
	}
	
	return 999;
} 

// Driver program to test methods of graph class 
int main() 
{ 
	// Create a graph given in the above diagram 
	Grafo g(4); 
	g.novaAresta(0, 1); 
	g.novaAresta(0, 2); 
	g.novaAresta(1, 2); 
	g.novaAresta(2, 0); 
	g.novaAresta(2, 3); 
	g.novaAresta(3, 3); 

	cout << "Following is Breadth First Traversal "
		<< "(starting from vertex 2) \n"; 
	g.maiorAlcance(2); 

	return 0; 
} 
