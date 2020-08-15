/* REO 05 - Algoritmos em Grafos
 * URI 2440: FAMÍLIAS DE TROIA
 * 
 * RESUMO DO PROBLEMA: Após uma guerra foram encontrados escritos sobre os sobreviventes.
 * 					   Os escritos haviam uma relação com parentesco de certa população.
 * 					   Logo é preciso encontrar a quantidade de famílias diferentes que existem.
 * 
 * SOLUÇÃO: Na primeira tentativa, utilizamos um grafo direcionado.
 * 			Como não tivemos resultados iguais ao solicitado na primeira tentativa, 
 * 			e depois de redesenhar o grafo, mudamos para um grafo não direcionado.
 * 			Optamos por utilizar a Busca em Profundidade. 
 * 			Sabemos que com a Busca em Profundidade, conseguimos encontrar quantidade de componentes conexas, 
 * 			ou seja, a quantidade de famílias com pessoas conectadas/parentes.
 * 
 * ALUNOS: Kellyson Santos da Silva - 2018200366 - 10A
 * 		   Layse Cristina Silva Garcia - 201811177 - 10A
 * 
 * 02/07/2020
 */ 
#include <bits/stdc++.h>
using namespace std; 

// Classe Grafo que utiliza lista de adjacências para armazenar seus valores.
class Grafo{ 
	private:
		int V;    // Numero de vértices
		list<int> *minhaListaAdj;    // Lista de adjacências
  
		void preencherPilha(int v, bool visitado[], stack<int> &minhaPilha); 
  
		// Busca em Profundidade recursiva, começando em v
		void buscaProfundidadeRecursiva(int v, bool visitado[]); 
	public: 
		Grafo(int vertices); 
		void adicionaAresta(int verticeDe, int verticePara); 
  
		// Encontra e imprime a quantidade de componentes conectadas
		void imprimirComponentes(); 
  
}; 
  
// Construtor da classe
Grafo::Grafo(int vertices){ 
	V = vertices; 
	minhaListaAdj = new list<int>[vertices]; 
} 
  
// Adiciona a representação da aresta do grafo na minha lista de adjacencias.
void Grafo::adicionaAresta(int verticeDe, int verticePara){ 
	minhaListaAdj[verticeDe].push_back(verticePara); // Adiciona no parenteDe o parentePara
	
	// Realmente, para alcançar o resultado desejado era preciso ser não direcionado
	minhaListaAdj[verticePara].push_back(verticeDe); // Adiciona no parentePara o parenteDe
} 

// Busca em Profundida recursiva, começando em v
void Grafo::buscaProfundidadeRecursiva(int v, bool visitado[]){
	// Marco o vértice atual como visitado
	visitado[v] = true; 
	// cout << v+1 << " "; //DEBUGGGGGG
  
	// Para todos os vértices vizinhos desse vértice, faço
	list<int>::iterator i; 
	for (i = minhaListaAdj[v].begin(); i != minhaListaAdj[v].end(); ++i){
		if (!visitado[*i]){
			buscaProfundidadeRecursiva(*i, visitado);
		}
	}
} 

// Método que preenche a pilha com vértices em ordem de quem fechou primeiro.
// Observe que o topo, terá o tempo de fechamento máximo
void Grafo::preencherPilha(int v, bool visitado[], stack<int> &minhaPilha){ 
	// Marco o vértice atual como visitado
	visitado[v] = true; 
	//cout << "PILHA " << v+1 << " "; //impressao para teste
	
	// Para todos os vértices vizinhos desse vértice, faço
	list<int>::iterator i; 
	for(i = minhaListaAdj[v].begin(); i != minhaListaAdj[v].end(); ++i){
		if(!visitado[*i]){
			preencherPilha(*i, visitado, minhaPilha); 
		}
	} 
	// Todos os vértices alcancaveis de V são processados agora, push v
	minhaPilha.push(v); 
} 
  
// Encontra e imprime a quantidade de componentes conectadas
void Grafo::imprimirComponentes(){
	stack<int> Pilha; 
  
	// Para primeira Busca em Profundidade, marco todos os vértices como não visitados
	bool *visitado = new bool[V]; 
	for(int i = 0; i < V; i++){
		visitado[i] = false; 
	}
	
	// Preencho a pilha de acordo com o tempo de fechamento
	for(int i = 0; i < V; i++){
		if(visitado[i] == false){
			preencherPilha(i, visitado, Pilha); 
		}
	}
  
	// Para a segunda Busca em Profundidade, marco todos os vértices como não visitados
	for(int i = 0; i < V; i++){
		visitado[i] = false; 
	}
	
	int contador = 0;
	// Agora, pego todos os vértices definidos na ordem da pilha
	while(Pilha.empty() == false){ 
		// Pego o topo da pilha
		int v = Pilha.top(); 
		// desempilho
		Pilha.pop(); 

		// Imprimo a componente conexa daquele vértice do topo retirado
		if(visitado[v] == false){ 
			buscaProfundidadeRecursiva(v, visitado); 
			contador++;
			//cout << endl; 
		} 
	}
	cout << contador << endl;
} 



int main(){  
	// Variáveis que determinam quantidade de vértices, arestas, e os parentes
	int qtdVertices, qtdArestas, parenteDe, parentePara;
	
	// entrada de dados
	cin >> qtdVertices >> qtdArestas;
	
	// Se minha quantidade de vértices for igual ou menor que 0, então encerro o código
	if(qtdVertices <= 0){
		return 0;
	}else{
		// crio o grafo com a quantidade de vértices passada
		Grafo meuGrafo(qtdVertices); 
		for(int i = 0; i < qtdArestas; i++){
			cin >> parenteDe >> parentePara;
			// adiciono as arestas na minha estrutura de dados
			meuGrafo.adicionaAresta(parenteDe-1, parentePara-1); 
		}
		meuGrafo.imprimirComponentes();
	}

	return 0;
}
