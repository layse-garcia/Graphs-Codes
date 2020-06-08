// Biblioteca com todas as bibliotecas mais utilizadas: iostream, vector...
#include <bits/stdc++.h>
#define MAXN 105
#define INF 0x3F3F3F3F

using namespace std;
vector<int> meuGrafo[MAXN]; //g
//vector<string> ans;
bool vis[MAXN];
bool vis2[MAXN];

int dfs(int a, int espacamento){
	
	// Se o vertice (a) foi visitado, true. Identificando vértice CINZA
	vis[a] = true;
	for (unsigned i = 0; i < meuGrafo[a].size(); i++){
		
		for (int k = 0; k < espacamento * 2; k++){
			cout << " ";
		}
		
		if(!vis[meuGrafo[a][i]]){
			
			cout << a << "-" << meuGrafo[a][i] << " pathR(G," << meuGrafo[a][i] << ")" << endl;
			espacamento++;
			dfs(meuGrafo[a][i], espacamento); //g
			espacamento--;
			
        }else{
			// Se um dos vértices já foi explorado.
			cout << a << "-" << meuGrafo[a][i] << endl;
		}
	}
	
}

int main(){
	
	/* -- > VARIÁVEIS UTILIZADAS:
		* qtdCasos: quantidade de Casos de teste
		* totalVertices: quantidade de vertices que serão criados para aquele determinado caso
		* totalArestas: quantidade de arestas que serão inseridas para aquele determinado caso
		* vDe: De um vértice (ligando como se fosse uma aresta)
		* vPara: Para outro vértice (ligando como se fosse uma aresta)
	 */
	int qtdCasos, totalVertices, totalArestas, vDe, vPara;
	
	// Entrada da quantidade de Casos
	cin >> qtdCasos; //a
	
	for (int i = 0; i < qtdCasos; i++){
		
		// Entrada da quantidadde de vértices e arestas a serem inseridas
		cin >> totalVertices >> totalArestas;
		
		for (int j = 0; j < totalVertices; j++){
			
			// Limpa o grafo, pode-se dizer que limpa os valores lixos, caso houver
			meuGrafo[j].clear();
			
			// ################# explicar isso aqui melhor
			vis[j] = false;
			vis2[j] = false;
			//memset(vis, 0, sizeof vis);
			//memset(vis2, 0, sizeof vis2);
			
		}
		
		// Indicação das arestas
		for (int j = 0; j < totalArestas; j++){
			
			cin >> vDe >> vPara; // d>>e
			// Coloca o elemento na última posição do vetor ## MELHORAR
			meuGrafo[vDe].push_back(vPara);//[d] (e)
			vis2[vDe] = true; //d
			vis2[vPara] = true; //e
			
		}
		
		cout << "Caso " << i + 1 << endl;
		
		for (int j = 0; j < totalVertices; j++){
			
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

/*
void iniciaGrafo(int vertices, vector<int> grafo[]){
	for (int j = 0; j < vertices; j++){//b
		// Limpa o grafo, pode-se dizer que limpa os valores lixos, caso houver
		grafo[j].clear();
			
		// ################# explicar isso aqui melhor
		memset(vis, 0, sizeof vis);
		memset(vis2, 0, sizeof vis2);
	}
}

int main(){
	/* -- > VARIÁVEIS UTILIZADAS:
		* qtdCasos: quantidade de Casos de teste
		* totalVertices: quantidade de vertices que serão criados para aquele determinado caso
		* totalArestas: quantidade de arestas que serão inseridas para aquele determinado caso
		* vDe: De um vértice (ligando como se fosse uma aresta)
		* vPara: Para outro vértice (ligando como se fosse uma aresta)
	 
	int qtdCasos, totalVertices, totalArestas, vDe, vPara; // a,b,c,d,e
	
	// Entrada da quantidade de Casos
	cin >> qtdCasos; //a
	
	for (int i = 0; i < qtdCasos; i++){ //a
		
		// Entrada da quantidadde de vértices e arestas a serem inseridas
		cin >> totalVertices >> totalArestas; //b>>c
		
		iniciaGrafo(totalVertices, &meuGrafo[i]);
		
		// Indicação das arestas
		for (int j = 0; j < totalArestas; j++){ //c
			cin >> vDe >> vPara; // d>>e
			// Coloca o elemento na última posição do vetor ## MELHORAR
			meuGrafo[vDe].push_back(vPara);//[d] (e)
			vis2[vDe] = true; //d
			vis2[vPara] = true; //e
		}
		cout << "Caso " << i + 1 << endl;
		
		for (int j = 0; j < totalVertices; j++){ //b
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
*/
