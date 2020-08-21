#include <bits/stdc++.h>

using namespace std;
//[listaAdjacencia[l] representa a l-esima linha da lista de adjacencia
int numCaminhosDistintos(const vector<vector<int> > &listaAdjacencia, int x, int y) {
    // Criação da fila para a Busca em Largura
    vector<int> queue = new vector<int>();

    // Todos os vértices do Grafo são marcados como não visitados
    int size = listaAdjacencia.size();
    vector<int> pai = new vector<int>(size, -1);

    // Marca o nó X como visitado e é colocado na fila
    pai[x] = null;
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
            // Se o vértice ainda não foi visitado, encontra ele e o marca
            if(!visitado[*i]){
                visitado[*i] = true;
                queue.push_back(*i);

                return PATH; //Mas quem é o PATH?
            }
        }


    }

}
