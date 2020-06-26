/* REO 02 - Algoritmos em Grafos
 * URI 2585: DOMINÓ INCOMPLETO
 * 
 * RESUMO DO PROBLEMA: Encontrar a maior sequencia de peças em um domino de 55 peças.
 * 
 * SOLUÇÃO: A dupla optou por utilizar Busca em Largura..
 * 
 * ALUNOS: Kellyson Santos da Silva - 2018200366 - 10A
 * 		   Layse Cristina Silva Garcia - 201811177 - 10A
 * 
 * 23/06/2020
 */

#include <bits/stdc++.h>
using namespace std;

// Quantidade máxima de vértices, de acordo com o enunciado V(0 a 9)
#define MAX_VERTICES 10

class Grafo {    
public: 

	// Criação do grafo
	vector<unsigned int> meuGrafo[MAX_VERTICES];
	
	// Construtor
	Grafo(){
		this->limpa();
	}
	
	// Função responsável por conectar um vértice ao outro, após a verificação de vizinhos
	void insereAresta(int verticeDe, int verticePara);  
	
	// Utilização da Busca em Largura 
	int buscaEmLargura(int inicio, int V);
	
	// Função que limpa o grafo
	void limpa();
	
}; 

void Grafo::limpa(){
	
	// Limpa o grafo
	for (unsigned i = 0; i < MAX_VERTICES; i++)
		meuGrafo[i].clear();
}

void Grafo::insereAresta(int verticeDe, int verticePara){
	
	// Adiciona o verticePara para a lista do verticeDe
	meuGrafo[verticeDe].push_back(verticePara);
	meuGrafo[verticePara].push_back(verticeDe);
	
}

int Grafo::buscaEmLargura(int inicio, int V) {
	
	int calculaDistancia[V]; // Vetor que armazena as distancias para a sequencia
	bool existeLoop[V]; // Vetor para armazenar quando se encontra um loop (Pedras com as pontas iguais)
	bool *visitado = new bool[V]; // Vetor para armazenar os vertices visitados
	
	// Inicializando os vetores acima como falso e distancias em 0
	for(int i = 0; i < V; i++){
		visitado[i] = false; 
		existeLoop[i] = false;
		calculaDistancia[i] = 0;
	}
	
	// Criação da fila para a Busca em Largura
	list<int> fila; 
	
	// Marco o vértice que foi passado como parametro como visitado
	// Como a fila garante a ordem de chegada, coloco na fila
	visitado[inicio] = true;
	fila.push_back(inicio); 
 
	int maiorSequencia = 0;
	
	// Enquanto a fila não estiver vazia
	while(!fila.empty()){
		
		// Acesso o primeiro elemento da fila e depois retiro
		unsigned int verticeAtual = fila.front();
		fila.pop_front(); 
		
		// Pego os vertices vizinhos do vertice retirado.
		for (unsigned int i = 0; i < meuGrafo[verticeAtual].size(); i++){
			
			// Recupero os vzinhos do vértice retirado 
			unsigned int umVizinho = meuGrafo[verticeAtual][i];
			
			if(umVizinho == verticeAtual){
				existeLoop[umVizinho] = true;
			}
			
			// Se o vizinho ainda não foi visitado, faço todo o processo de enfileirar e marcar como visitado
			if (!visitado[umVizinho]){ 
				
				// Somo as passagens pelos vizinhos
				if (umVizinho != verticeAtual) {
					calculaDistancia[umVizinho] = calculaDistancia[verticeAtual] + 1;
				}
				
				fila.push_back(umVizinho);
				visitado[umVizinho] = true;
			}
			
			maiorSequencia = calculaDistancia[verticeAtual];
		} 
		
	}
	
	// Contador de peças com lados iguais
	int cont = 0;
	for(int i = 0; i < V; i++)
		if(existeLoop[i])
			cont ++;
	
	// Adiciona peças com lados iguais aos dominós
	maiorSequencia = maiorSequencia + cont;
	
	// Retorno a quantidade de peças
	return maiorSequencia;
	
} 

int main() { 
	
	int totalLinhas; // Entrada do usuário, quantidade de inserções/arestas
	bool continua = false; // Booleana para controle de execução
	int verticeDe = 0, verticePara = 0; // Entradas do usuário, vertice de origem e vertice de destino
	
	cin >> totalLinhas;
	
	// TRATAMENTO: Caso as entradas não correpondam ao intervalo permitido pelo enunciado, o programa não é executado
	if((totalLinhas <= 0) or (totalLinhas > 55)){
		continua = false;
	}else{
		continua = true;
	}
	
	while(continua){
		
		Grafo meuGrafo;
		meuGrafo.limpa();
		
		// Entrada do usuário conectando um vértice ao outro
		for(int i = 0; i < totalLinhas; i++){
			cin >> verticeDe >> verticePara;
			meuGrafo.insereAresta(verticeDe, verticePara);
			meuGrafo.insereAresta(verticePara, verticeDe);
		}
		
		int sequencia = 0;
		// Busco a maior sequência iniciando de todos os vertices
		for(int i = 0; i < MAX_VERTICES; i++){
			sequencia = max(meuGrafo.buscaEmLargura(i, 10), sequencia);
		}
		
		// Imprimo a quantidade da maior sequencia de peças
		cout << sequencia << endl;
		
		// Aguardo por nova entrada
		cin >> totalLinhas;
		
		// TRATAMENTO: Caso as entradas não correpondam ao intervalo permitido pelo enunciado, o programa não é executado
		if((totalLinhas <= 0) or (totalLinhas > 55)){
			continua = false;
		}else{
			continua = true;
		}
	}
	
	

	return 0; 
}

