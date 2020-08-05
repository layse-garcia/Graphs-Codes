#include <bits/stdc++.h>
using namespace std;
// Valor que representa INIFITO
# define INF 99999999

// Definindo o par pair<int, int> como meuPar
// para facilitar a legibilidade
typedef pair<int, int> meuPar; 

// Função responsável por adicionar uma aresta valorada
void adicionaAresta(vector<pair<int, int>> grafo[], int de, int para, int valor) {

	grafo[de].push_back(make_pair(para, valor));
	grafo[para].push_back(make_pair(de, valor));

}

void primAGM(vector<pair<int,int> > grafo[], int vertice, int aresta){

	// Fila de prioridade para armazenar os vertices para a AGM
	priority_queue<meuPar, vector<meuPar>, greater<meuPar>> filaPrioridade; 

	int inicio = 0;

	// Criando vetor para as chaves e inicializa como infinito
	vector<int> valor(vertice, INF); 

	// Vetor para armazenar os pais
	vector<int> pai(vertice, -1); 

	// Vetor para armazenar os vertices já inseridos na AGM
	vector<bool> inserido(vertice, false); 

	// Inserindo a raiz na fila de prioridade
	filaPrioridade.push(make_pair(0, inicio)); 
	valor[inicio] = 0; 

	// Loop até a fila ficar vazia
	while (!filaPrioridade.empty()){ 
		
		int u = filaPrioridade.top().second; 
		filaPrioridade.pop(); 

		inserido[u] = true; // Inclui o vertice na AGM
		
		// Percorre os vizinhos de u
		for (auto x : grafo[u]){

			// Resgatando borda da aresta e seu custo
			int v = x.first;
			int custo = x.second;

			// Se v não está na AGM e seu custo é menor do que o custo atual
			if (inserido[v] == false && valor[v] > custo){

				// Alterando custo de V
				valor[v] = custo;
				filaPrioridade.push(make_pair(valor[v], v));
				pai[v] = u;

			}

		}

	}
	
	// Verificando se o grafo é conexo
	// Se todos os vértices estão na AGM, o grafo é conexo
	bool conexo = true;
	
	for(bool verticeInserido : inserido){

		if (conexo && !verticeInserido){
			conexo = false;
		}

	}
	
	if(conexo){
		
		int soma = 0;
		
		// Somando os custos da AGM
		for (int custo : valor){
			soma += custo;
		}
		
		cout << soma << endl;
		
	} else {
		cout << "impossivel" << endl;
	}

}

int main(){
	
	int totalVertices, totalArestas, deVertice, paraVertice, custoAresta;
	cin >> totalVertices >> totalArestas;
	
	while((totalVertices >= 2 || totalVertices <= 1000) && totalArestas <= (totalVertices*(totalVertices-1)/2)){
		
		// Criação do grafo
		vector<meuPar> meuGrafo[totalVertices];
		
		// Limpa a estrutra
		for(auto item : meuGrafo){
			item.clear();
		}
		
		for(int i = 0; i < totalArestas; i++){
			
			cin >> deVertice >> paraVertice >> custoAresta;
			
			// Inserção das arestas/custos
			adicionaAresta(meuGrafo, deVertice-1, paraVertice-1, custoAresta);
			
		}
		
		primAGM(meuGrafo, totalVertices, totalArestas);
		cin >> totalVertices >> totalArestas;
	}
	
}
