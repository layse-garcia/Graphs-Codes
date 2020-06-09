// Biblioteca com todas as bibliotecas mais utilizadas: iostream, vector...
#include <bits/stdc++.h>
using namespace std;

// Quantidade máxima de vértices, de acordo com o enunciado V(1 ≤ V ≤ 20)
#define MAX_VERTICES 20
// Valor que representa INIFITO
#define INF 99999999
// Criação do grafo
vector<unsigned int> meuGrafo[MAX_VERTICES];
// Criação do vetor de visitados
bool vis[MAX_VERTICES];
bool vis2[MAX_VERTICES];

void dfs(unsigned a, unsigned espacamento){
	
	// Se o vertice (a) foi visitado, então true.
	vis[a] = true;
	for (unsigned i = 0; i < meuGrafo[a].size(); i++){
		
		for (unsigned k = 0; k < espacamento * 2; k++){
			cout << " ";
		}
		
		if(!vis[meuGrafo[a][i]]){
			
			cout << a << "-" << meuGrafo[a][i] << " pathR(G," << meuGrafo[a][i] << ")" << endl;
			espacamento++;
			dfs(meuGrafo[a][i], espacamento);
			espacamento--;
			
        }else{
			// Se um dos vértices já foi explorado.
			cout << a << "-" << meuGrafo[a][i] << endl;
		}
	}
	
}

int main(){
	
	/*
	 *  VARIÁVEIS UTILIZADAS:
	 *   qtdCasos: quantidade de Casos de teste
	 *   totalVertices: quantidade de vertices que serão criados para aquele determinado caso
	 *   totalArestas: quantidade de arestas que serão inseridas para aquele determinado caso
	 *   vDe: De um vértice (ligando como se fosse uma aresta)
	 *   vPara: Para outro vértice (ligando como se fosse uma aresta)
	 */
	unsigned qtdCasos, totalVertices, totalArestas, vDe, vPara;
	
	// Entrada da quantidade de Casos
	cin >> qtdCasos;
	
	for (unsigned i = 0; i < qtdCasos; i++){
		
		// Entrada da quantidadde de vértices e arestas a serem inseridas
		cin >> totalVertices >> totalArestas;
		
		for (unsigned j = 0; j < totalVertices; j++){
			
			// Limpa o grafo, pode-se dizer que limpa os valores lixos, caso houver
			meuGrafo[j].clear();
			
			// Inicializando todos as posições do visitados como falso.
			vis[j] = false;
			vis2[j] = false;
			
		}
		
		// Indicação das arestas
		for (unsigned j = 0; j < totalArestas; j++){
			
			cin >> vDe >> vPara;
			// Coloca o elemento vPara na última posição da lista do indice vDe
			meuGrafo[vDe].push_back(vPara);
			vis2[vDe] = true;
			vis2[vPara] = true;
			
		}
		
		cout << "Caso " << i + 1 << endl;
		
		for (unsigned j = 0; j < totalVertices; j++){
			
			// Pega qualquer valor entre início e o fim do grafo
			sort(meuGrafo[j].begin(), meuGrafo[j].end());
			// Se o vértice não foi visitado
			if (!vis[j]){
				
				// Faz a DFS no indice do loop
				dfs(j, 1); 
				// Se j já foi visitado, então salto uma linha
				if (vis2[j]){ 
					cout << endl;
				}
				
			}
			
		}
	}
}
