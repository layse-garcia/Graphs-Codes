/* PROVA 1 - Algoritmos em Grafos
 * URI 1209: Festas de São Petersburgo
 * 
 * RESUMO DO PROBLEMA: São Petesburgo é uma das cidades mais alternativas. 
 * 					   Logo percebeu que a cidade poderia se transformar em um
 * 					   grande centro de encontros(festas...).
 * 					   As festas de São Petersburgo sempre cheias, devido a amizade
 * 					   dos participantes em redes sociais. Logo, a pessoa precisa ter 
 * 					   pelo menos um número K de amigos na lista de convidados.
 * 
 * SOLUÇÃO: Pensamos em utilizar uma DFS em cada nó não visitado. Como nosso grafo é
 * 			não direcionado, conseguimos encontrar ciclos. Se o grafo é conexo, consigo
 * 			encontrar árvores. Em qualquer nó visitado, se houver uma outra aresta não visitada,
 * 			conclua-se que haverá um loop e o retorno será verdadeiro. Assim, afirmamos que as
 * 			pessoas daquele ciclo vão ser convidadas para a festa.
 * 
 * ALUNOS: Kellyson Santos da Silva - 2018200366 - 10A
 * 		   Layse Cristina Silva Garcia - 201811177 - 10A
 * 
 * 02/07/2020
 */ 
#include <bits/stdc++.h>

using namespace std; 

// Classe Grafo. Grafo não direcionado.
class Grafo{
	private:
		int vertices; 			  // numero de vértices
		int minimoAmigos;		  // minimo de amigos
		vector<int> grau;		  // grau do vértice
		list<int> *meuGrafoListAdj;     // matriz que armazena as amizades
	
	public:
		// Construtor da classe e suas atribuições
		Grafo(int numVertices, int minAmigos){
			vertices = numVertices;
			meuGrafoListAdj = new list<int>[vertices]; 
	
		}
		
		// Métodos da minha classe Grafo
		void imprimeEstrutura();
		void adicionaAresta(int verticeDe, int verticePara);
		bool ehCicloRecursivo(int v, bool visitado[], int meuPai);
		bool ehCiclo();
		void imprimeVerticesDoCiclo(int indiceCiclo);
		void ordenaEstrutura();
};

// Método que faz a ordenação em ordem crescente nos vizinhos do vértice
void Grafo::ordenaEstrutura(){
	
	for(int i = 0; i < vertices; i++){
		meuGrafoListAdj[i].sort(); 
	}
}

// Função para debugar a matriz e contar a quantidade de vizinhos
void Grafo::imprimeEstrutura(){
	
	for(int i = 0; i < vertices; i++){
		int contador = 0;
		cout << "[" << i + 1 << "]";
		for(auto it = meuGrafoListAdj[i].begin(); it != meuGrafoListAdj[i].end(); it++){
			cout << "-> " << *it + 1;
			contador++;
		}
		grau.push_back(contador);
		cout << "\n";
		
		//cout << "CONEXOES DO VERTICE " << i << " : " << grau[i] << endl;
	}
}

// Função para debugar a matriz
void Grafo::imprimeVerticesDoCiclo(int indiceCiclo){
	for(int i = 0; i < vertices; i++){ 
		if(indiceCiclo == i){
			for(auto it= meuGrafoListAdj[i].begin(); it!=meuGrafoListAdj[i].end(); it++){
				cout << *it + 1 << " ";
			}
			cout << "\n";
		}
		
	}
}


// Método que adiciona aresta na lista de adjacências - não direcionado
void Grafo::adicionaAresta(int verticeDe, int verticePara){
	meuGrafoListAdj[verticeDe].push_back(verticePara); // Adiciona vérticePara na lista do vérticeDe
    meuGrafoListAdj[verticePara].push_back(verticeDe); // Add v to w’s list. 
}

// Função recursiva que usa o vetor booleano visitado[] e o pai para 
// encontrar o ciclo em um subgrafo alcancável a partir do vértice v
bool Grafo::ehCicloRecursivo(int v, bool visitado[], int meuPai){ 
    // Marco o nó atual como visitado
    visitado[v] = true; 
    
    int auxiliar = -99;
    
    // Repete para todos os vértices adjacentes a este vértice
    list<int>::iterator i; 
    for (i = meuGrafoListAdj[v].begin(); i != meuGrafoListAdj[v].end(); ++i){ 
        // Se um vértice vizinho não foi visitado, então volto para o meu vizinho
        if (!visitado[*i]){ 
           if (ehCicloRecursivo(*i, visitado, v)) 
              return true; 
        } 
  
        // Se meu vizinho foi visitado e não é o pai do vértice atual, então
        // posso dizer que encontrei um ciclo 
        else if (*i != meuPai) {
			auxiliar = *i;
			cout << *i + 1 << " ";
			imprimeVerticesDoCiclo(auxiliar);
			return true; 
        }
    }
    return false; 
}

// Retorna verdadeiro se o grafo conter um ciclo, caso não tenha, retorna falso.
bool Grafo::ehCiclo(){ 
	
	// Marco todos os vértices como não visitados
	bool *visitado = new bool[vertices]; 
	for (int i = 0; i < vertices; i++){ 
		visitado[i] = false; 
	}
	
	// Chamo recursivamente a função que detecta ciclo em diferentes árvores da DFS
    for (int u = 0; u < vertices; u++) 
        if (!visitado[u]) // Não repete se já tiver visitado
          if (ehCicloRecursivo(u, visitado, -1)) 
             return true; 
  
    return false; 
} 


int main(){
	int pessoasComunidade, relacoesAmizade, minimoAmigos;
	bool continua = true;
	// Entrada de quantidade de pessoas da Comunidade, quantidade de relações
	// na Comunidade e o mínimo de Amigos;
	cin >> pessoasComunidade;
	if(pessoasComunidade <= 0){
		continua = false;
	}
	while(continua){
		cin >> relacoesAmizade >> minimoAmigos;
		
		
		// Crio meu grafo
		Grafo meuGrafo(pessoasComunidade, minimoAmigos);
		
		int amigoDe, amigoPara;
		// Coloco as pessoas que são amigas na minha estrutura
		for (int i = 0; i < relacoesAmizade; i++){
			cin >> amigoDe >> amigoPara;
			meuGrafo.adicionaAresta(amigoDe-1, amigoPara-1);
		}
		
		// DEBUG: analisar a lista de adjacencia antes de ordenar
		meuGrafo.imprimeEstrutura(); cout << endl;
		meuGrafo.ordenaEstrutura();
		
		//DEBUG: lista de adjacencia ordenada
		meuGrafo.imprimeEstrutura(); cout << endl;
		
		meuGrafo.ehCiclo()? cout << "": cout << "0\n"; 
		
		cin >> pessoasComunidade;
		// Se a quantidade de pessoas da comunidade for menor ou igual a 0, encerro
		if(pessoasComunidade <= 0){
			continua = false;
		}
		
	}
	return 0;
}
