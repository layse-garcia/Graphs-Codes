#include <bits/stdc++.h>
#define ROOT -99999

using namespace std;

//[listaAdjacencia[l] representa a l-esima linha da lista de adjacencia
int numCaminhosDistintos(const vector<vector<int> > &listaAdjacencia, int x, int y) {
    // Criação da fila para a Busca em Largura
    vector<int> queue = new vector<int>();

    // Todos os vértices do Grafo são marcados como não visitados
    int size = listaAdjacencia.size();
    vector<int> pai = new vector<int>(size, -1);

    // Marca o nó X como visitado e é colocado na fila
    pai[x] = ROOT;
    queue.push_back(x);

    // Ponteiro que vai percorrer os elementos da lista de adjacencia
    list<int>::iterator i;

    // Enquanto a fila não estiver vazia, faz...
    while(!queue.empty()){
        // Retira-se o vértice da fila e imprime
        x = queue.front();
        cout << x << " ";
        queue.pop_front();

        // Para toda lista da vértice retirado..
        for(i = listaAdjacencia[x].begin(); i != listaAdjacencia[x].end(); i++){

            if(*i == y){
              return ;
            }

            if(pai[*i] < 0){
                pai[*i] = x;
                queue.push_back(*i);
            }
        }


    }

}
