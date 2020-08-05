/* REO 03 - Algoritmos em Grafos
 * URI 1454: O PAÍS DAS BICICLETAS
 * 
 * RESUMO DO PROBLEMA: Mr. Lee mora em uma cidade montanhosa na China e não consegue
 * 					   mais pedalar, devido a idade. Através das informações(entradas),
 * 					   é necessário calcular a maior altitude pela origem e destino passada.
 * 
 * SOLUÇÃO: Considerando que haverá diferentes origens, ao declarar número de pares(origem,destino),
 * 			a melhor opção seria Floyd-Warshall, visto que seu funcionamento é em qualquer início.
 * 			Em até 400 vértices possui um excelente desempenho e também, estamos a procura da aresta 
 * 			mais pesada ao definir a origem e destino.
 * 
 * ALUNOS: Kellyson Santos da Silva - 2018200366 - 10A
 * 		   Layse Cristina Silva Garcia - 201811177 - 10A
 * 
 * 02/07/2020
 */
// C++ Program for Floyd Warshall Algorithm  
#include <bits/stdc++.h> 
using namespace std; 

// Quantidade máxima de vértices, de acordo com o enunciado V >= 0 e V <= 100
#define MAX_VERTICES 100

// Valor simbólico que representa o INFINITO
#define INF 99999999 

// Classe Grafo contendo número de vértices, estrutura de dado: Matriz de adjacencia
class Grafo{
	private:
		int vertices;
		int meuGrafoMatriz[MAX_VERTICES][MAX_VERTICES];
	public:
	// Construtor do vetor, inicializando todos como INF
	Grafo(int numVertices){
		vertices = numVertices;
		//cout << "oi";
		for (int i = 0; i < numVertices; i++) {
			for (int j = 0; j < numVertices; j++){
				meuGrafoMatriz[i][j] = INF;
			}
			//cout << "todos inf" << endl;
		}
		//cout << "finished" << endl;
	}
	void adicionaAresta(int verticeD, int verticeP, int h);
	
	void imprimeMatriz();
	int floydWarshall(int o, int d);
	int valor(int origem, int destino);
};

// Grafo não direcionado, função que adiciona aresta de um vértice para outro, com peso(altitude)
void Grafo::adicionaAresta(int verticeD, int verticeP, int h){
	meuGrafoMatriz[verticeD][verticeP] = min( meuGrafoMatriz[verticeD][verticeP], h);
	meuGrafoMatriz[verticeP][verticeD] = min( meuGrafoMatriz[verticeP][verticeD], h);
}

// TESTES -- Função para imprimir 
void Grafo::imprimeMatriz(){
	for (int i = 0; i < vertices; i++) {
		cout << "Linha: " << i;
		for (int j = 0; j < vertices; j++){
			cout << meuGrafoMatriz[i][j] << " ";
		}
		cout << endl;
	}
}

// Algoritmo utilizado para resolução do problema, passando Origem e Destino
int Grafo::floydWarshall(int o, int d){
	
	// Vetor de distancias baseado na Matriz de Adj
	int distancia[vertices][vertices];
	for (int i = 0; i < vertices; i++){
		for (int j = 0; j < vertices; j++){  
			distancia[i][j] = meuGrafoMatriz[i][j];
		}
	}
	//imprimeMatriz();
	int retorno = 0;
	for(int k = 0 ; k < vertices; k++){
		for (int i = 0; i < vertices; i++){
			for (int j = 0; j < vertices; j++){
				// Se a distancia que estou for maior que distancia máxima de onde estou com o meu intermediario
				// até meu intermediario e destino, faço a mudança de valor
				if(distancia[i][j] > max(distancia[i][k], distancia[k][j])){
					distancia[i][j] = max(distancia[i][k], distancia[k][j]);
				}
			}
		}
	}
	
	// Se a distância é diferente de INF, retorno a maior aresta de um ponto ao outro
	if(distancia[o][d] != INF){
		retorno = distancia[o][d];
	}
	
	// Se origem e destino forem iguais, isso significa que estou no mesmo lugar
	if(o == d){
		retorno = 0;
	}
	
	return retorno;
}

int main(){  
	// Entradas para o usuário
	int quantidadeIntersecoesN, quantidadeRuasM;
	
	// Contador para mais entradas
	int contadorInstancias = 1;
	
	// Booleana para controle de execução
	bool continua = false;
	
	cin >> quantidadeIntersecoesN >> quantidadeRuasM;
	
	// TRATAMENTO: Caso as entradas não correpondam ao intervalo permitido pelo enunciado, o programa não é executado
	if(quantidadeIntersecoesN < 1 and quantidadeRuasM < 1){
		continua = false;
	}else{
		continua = true;
	}
	
	while(continua){
		
		Grafo meuGrafo(quantidadeIntersecoesN);	
		int verticeDe, verticePara, altitude, numeroPares, origem, destino;
		
		// Entradas para inserir aresta no Grafo
		for(int i = 0; i < quantidadeRuasM; i++){
			cin >> verticeDe >> verticePara >> altitude;
			meuGrafo.adicionaAresta(verticeDe-1, verticePara-1, altitude);
		}
		
		
		cin >> numeroPares;
		
		// Impressão do resultado
		int imprimeResultado[numeroPares][2];
		for(int i = 0; i < numeroPares ; i++){
			cin >> origem;
			imprimeResultado[i][0] = origem-1;
			cin >> destino;
			imprimeResultado[i][1] = destino-1;
		}
		cout << "Instancia: " << contadorInstancias++ << endl;
		for(int i = 0; i < numeroPares ; i++){
			cout << meuGrafo.floydWarshall(imprimeResultado[i][0], imprimeResultado[i][1]) << endl;
		}
		
		// Novo caso
		cin >> quantidadeIntersecoesN >> quantidadeRuasM;
	
		// TRATAMENTO: Caso as entradas não correpondam ao intervalo permitido pelo enunciado, o programa não é executado
		if(quantidadeIntersecoesN < 1 and quantidadeRuasM < 1){
			continua = false;
		}else{
			continua = true;
		}
		
		
	}
		
	
	return 0;
	  
}  

/*
4 4
1 2 1
2 3 5
3 4 -1
4 1 2
5
1 3
2 3
3 4
4 4
4 1
*/
/*
12 17
1 4 4
4 7 6
7 10 6
2 5 4
5 8 5
8 11 2
3 6 5
6 9 3
9 12 1
1 2 1
2 3 9
4 5 3
5 6 7
7 8 7
8 9 2
10 11 1
11 12 2
4
1 5
6 8
6 7
11 10
*/
/*PROBLEMA AQUI
3 2
*/
