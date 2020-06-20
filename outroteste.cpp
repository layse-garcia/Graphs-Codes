#include <bits/stdc++.h>
 using namespace std;
 
#define INF 9999999

typedef pair<int, int> meuPar; 
 
vector<vector<meuPar>> meuGrafo;
vector<int> distancia;

vector<string> aux;

void triagemCaractere(vector<vector<meuPar>> grafo, int N, int coluna, vector<string> auxiliar) {

	for (int i = 0 ; i < N; i++){
		for (int j = 0; j < coluna; j++){
			if (auxiliar[i][j] == '.'){
				cout << endl << "Entrei aqui: " << i << " - " << j << endl;
				if (i > 0){
					cout << "I>0" << endl;
					if (auxiliar[i - 1][j] == '.'){
						cout << "i-1[j]" << endl;
						grafo[coluna * i + j].push_back(make_pair(1, coluna * (j - 1) + j));
					}
				}
				if (i < N - 1){
					cout << ">> I<N-1" << endl;
					if (auxiliar[i + 1][j] == '.'){
						cout << "i+1[j]" << endl;
						grafo[coluna * i + j].push_back(make_pair(1, coluna * (i + 1) + j));
					}
				}
				if (j > 0){
					cout << ">> J > 0" << endl;
					if (auxiliar[i][j - 1] == '.'){
						cout << "i[j-1]" << endl;
						grafo[coluna * i + j].push_back(make_pair(1, coluna * i + j - 1));
					}
				}
				if (j < coluna - 1){
					cout << " >> J < COLUNA -1" << endl;
					if (auxiliar[i][j + 1] == '.'){
						cout << "i[j+1]" << endl;
						grafo[coluna * i + j].push_back(make_pair(1, coluna * i + j + 1));
					}
				}
			}
		}
	}
}

	void dijkstra(int source, int M){
		distancia.clear();
		distancia.assign(M * M + 2, INF);
		distancia[source] = 0;
		
		priority_queue<meuPar, vector<meuPar>, greater<meuPar>> filaPrioridade; 
		
		filaPrioridade.push(meuPar(0, source));
		int maior = 0;
		while(!filaPrioridade.empty()){
			meuPar v = filaPrioridade.top();
			filaPrioridade.pop();
			
			
			for (unsigned i = 0 ; i < meuGrafo[v.second].size(); i++){
				maior = distancia[v.second] + 1;
				if (distancia[meuGrafo[v.second][i].second] > maior){
					distancia[meuGrafo[v.second][i].second] = distancia[v.second] + 1;
					filaPrioridade.push(meuPar(distancia[meuGrafo[v.second][i].second], meuGrafo[v.second][i].second));
				}
				cout << distancia[meuGrafo[v.second][i].second];
			}
		}
}
/*
string pegaValores(){
	vector<string>::iterator v = aux.begin();
   while( v != aux.end()) {
     // cout << "value of v = " << *v << endl;
      v++;    return *v ;
   }

}*/

int main(){
	int totalLinhas;
	int totalColunas;
	string caractere;
	bool continua = false;

	ios_base :: sync_with_stdio(0); cin.tie(0);
	
	cin >> totalLinhas >> totalColunas;
	while(continua and totalLinhas > 0 and totalColunas > 0){
		if ((totalLinhas <= 4) or (totalColunas <=4) or (totalLinhas > 500) or (totalColunas > 500)){
			continua = false;
		} else {
			meuGrafo.assign(totalColunas * totalColunas + 2, vector<meuPar>());
			
			for (int i = 0 ; i < totalLinhas ; i++){
				cin >> caractere;
				aux.push_back(caractere);
			}
			//for (int i = 0 ; i < n ; i++){
				//pegaValores();
			//}
		
			triagemCaractere(meuGrafo, totalLinhas, totalColunas, aux);
			unsigned p = 0;

			for (unsigned p = 0; p < meuGrafo.size(); p++){
				if (meuGrafo[p].size()){
					//cout << meuGrafo[p].size() << endl;
					break;
				}
			}
			
			dijkstra(p,totalColunas);
			int resultado = INT_MIN;
			
			for (unsigned i = 0 ; i < distancia.size(); i++){
				if (distancia[i] != INF && distancia[i] > resultado){
					resultado = distancia[i];
					p = i;
				}
			}
			dijkstra(p,totalColunas);
			resultado = INT_MIN;
			for (unsigned i = 0 ; i < distancia.size(); i++){
				if (distancia[i] != INF && distancia[i] > resultado){
					resultado = distancia[i];
				}
			}
			
			cout << resultado << endl;

			meuGrafo.clear();		
			aux.clear();
			cin >> totalLinhas >> totalColunas;
		}
	}
	
}
