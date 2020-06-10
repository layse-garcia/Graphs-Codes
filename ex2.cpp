// Biblioteca com todas as bibliotecas mais utilizadas: iostream, vector...
// LINK: https://www.geeksforgeeks.org/prims-algorithm-using-priority_queue-stl/
#include <bits/stdc++.h>
using namespace std;
// Valor que representa INIFITO
# define INF 99999999

// Um tipo de pair é construído
typedef pair<unsigned, unsigned> meuPar; 

// Função responsável por adicionar uma aresta valorada
void adicionaAresta(vector<pair<unsigned, unsigned>> grafo[], unsigned de, unsigned para, unsigned valor) {

	grafo[de].push_back(make_pair(para, valor));
	grafo[para].push_back(make_pair(de, valor));

}

void primAGM(vector<pair<unsigned,unsigned> > grafo[], unsigned vertice, unsigned aresta){


	// Fila de prioridade para armazenar os vertices para a AGM
	priority_queue<meuPar, vector<meuPar>, greater<meuPar>> filaPrioridade; 

	int inicio = 0;

	// Criando vetor para as chaves e inicializa como infinito
	vector<unsigned> valor(vertice, INF); 

	// Vetor para armazenar os pais
	vector<int> pai(vertice, -1); 

	// Vetor para armazenar os vertices já inseridos na AGM
	vector<bool> inserido(vertice, false); 

	// Inserindo a raiz na fila de prioridade
	filaPrioridade.push(make_pair(0, inicio)); 
	valor[inicio] = 0; 

	// Loop até a fila ficar vazia
	while (!filaPrioridade.empty()){ 
		
		unsigned u = filaPrioridade.top().second; 
		filaPrioridade.pop(); 

		inserido[u] = true; // Inclui o vertice na AGM
		
		
		
		// Percorre os vizinhos de u
		for (auto x : grafo[u]){

			// Resgatando borda da aresta e seu custo
			unsigned v = x.first;
			unsigned custo = x.second;

			// Se v não está na AGM e seu custo é menor do que o custo atual
			if (inserido[v] == false && valor[v] > custo){

				// Alterando custo de V
				valor[v] = custo;
				filaPrioridade.push(make_pair(valor[v], v));
				pai[v] = u;

			}

		}

	}
	bool conexo = true;
	for(auto k: inserido){
		cout << k << " ";
		if (conexo && !k){
			conexo = false;
		}
	}
	cout << endl;
	if(conexo){
		unsigned soma = 0;
		// Print edges of MST using parent array 
		for (unsigned i = 1; i < vertice; i++){
			//printf("%d - %d\n", pai[i], i); 
			soma += valor[i];
		}
		
		cout << soma << endl;
	} else {
		cout << "impossivel" << endl;
	}
}


int main(){
	unsigned totalVertices, totalArestas, deVertice, paraVertice, custoAresta;

	cin >> totalVertices >> totalArestas;
	while((totalVertices >= 2 || totalVertices <= 1000) && (totalArestas >=0 || totalArestas <= (totalVertices*(totalVertices-1)/2))){
		// Criação do grafo(Matriz de Adjacencias
		vector<meuPar> meuGrafo[totalVertices];
		// Criação do grafo(Matriz de Adjacencias
		
		// Limpa a estrutra, pode-se dizer que limpa os valores lixos, caso houver
		for(unsigned i = 0; i < totalVertices; i++){
			for(unsigned j = 0; j < totalVertices; j++){
				meuGrafo[j].clear();
			}
			meuGrafo[i].clear();
		}
		for(unsigned i = 0; i < totalArestas; i++){
			cin >> deVertice >> paraVertice >> custoAresta;
			
			// Chama a função responsável pela inserção das arestas/custos
			adicionaAresta(meuGrafo, deVertice-1, paraVertice-1, custoAresta);
		}
		
		primAGM(meuGrafo, totalVertices, totalArestas);
		cin >> totalVertices >> totalArestas;
	}
	
}
