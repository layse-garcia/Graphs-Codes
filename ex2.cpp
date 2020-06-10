// Biblioteca com todas as bibliotecas mais utilizadas: iostream, vector...
// LINK: https://www.geeksforgeeks.org/prims-algorithm-using-priority_queue-stl/
#include <bits/stdc++.h>
using namespace std;
// Valor que representa INIFITO
# define INF 99999999

// Um tipo de pair é construído
typedef pair<unsigned, unsigned> meuPar; 

// Função responsável por adicionar uma aresta valorada
void adicionaAresta(vector<pair<unsigned, unsigned>> grafo[], unsigned de, unsigned para, unsigned valor) 
{ 
    grafo[de].push_back(make_pair(para, valor)); 
    grafo[para].push_back(make_pair(de, valor)); 
} 

void primAGM(vector<pair<unsigned,unsigned> > grafo[], unsigned vertice){
	// Create a priority queue to store vertices that 
    // are being preinMST. This is weird syntax in C++. 
    // Refer below link for details of this syntax 
    // http://geeksquiz.com/implement-min-heap-using-stl/ 
	priority_queue<meuPar, vector<meuPar>, greater<meuPar>> filaPrioridade; 
  
    int inicio = 0; // Taking vertex 0 as source 
  
    // Create a vector for keys and initialize all 
    // keys as infinite (INF) 
    vector<unsigned> valor(vertice, INF); 
  
    // To store parent array which in turn store MST 
    vector<int> pai(vertice, -1); 
  
    // To keep track of vertices included in MST 
    vector<bool> inserido(vertice, false); 
  
    // Insert source itself in priority queue and initialize 
    // its key as 0. 
    filaPrioridade.push(make_pair(0, inicio)); 
    valor[inicio] = 0; 
  
    /* Looping till priority queue becomes empty */
    while (!filaPrioridade.empty()) 
    { 
        // The first vertex in pair is the minimum key 
        // vertex, extract it from priority queue. 
        // vertex label is stored in second of pair (it 
        // has to be done this way to keep the vertices 
        // sorted key (key must be first item 
        // in pair) 
        unsigned u = filaPrioridade.top().second; 
        filaPrioridade.pop(); 
  
        inserido[u] = true; // Include vertex in MST 
  
        // Traverse all adjacent of u 
        for (auto x : grafo[u]) 
        { 
            // Get vertex label and weight of current adjacent 
            // of u. 
            unsigned v = x.first; 
            unsigned valorU = x.second; 
  
            // If v is not in MST and weight of (u,v) is smaller 
            // than current key of v 
            if (inserido[v] == false && valor[v] > valorU) 
            { 
                // Updating key of v
                valor[v] = valorU; 
                filaPrioridade.push(make_pair(valor[v], v)); 
                pai[v] = u;
            } 
        } 
    } 
	unsigned soma = 0;
    // Print edges of MST using parent array 
	for (unsigned i = 1; i < vertice; i++){
		printf("%d - %d\n", pai[i], i); 
		soma += valor[i];
	}
	cout << soma << endl;
}


int main(){
	unsigned totalVertices, totalArestas, deVertice, paraVertice, custoAresta;

	cin >> totalVertices >> totalArestas;
	while((totalVertices >= 2 || totalVertices <= 1000) && (totalArestas >=0 || totalArestas <= (totalVertices*(totalVertices-1)/2))){
		// Criação do grafo(Matriz de Adjacencias
		vector<meuPar> meuGrafo[totalVertices];
		
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
			adicionaAresta(meuGrafo, deVertice, paraVertice, custoAresta);
		}
		
		primAGM(meuGrafo, totalVertices);
		cin >> totalVertices >> totalArestas;
	}
	
}
