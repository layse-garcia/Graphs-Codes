/* REO 05 - Algoritmos em Grafos
 * URI 2088: Combate à Dengue
 * 
 * RESUMO DO PROBLEMA: 
 * 
 * SOLUÇÃO: 
 * 
 * ALUNOS: Kellyson Santos da Silva - 2018200366 - 10A
 * 		   Layse Cristina Silva Garcia - 201811177 - 10A
 * 
 * 02/07/2020
 */ 
#include <bits/stdc++.h> 
#include <math.h>

using namespace std; 

// Valor simbólico que representa o INFINITO
#define INF 99999
// Maximo de focos possíveis, de acordo com o problema
#define MAX_FOCOS 15

// Classe Grafo
class Grafo{
	private:
		unsigned int vertices; // numero de vértices
		int origemX; // armazeno a origemX passada
		int origemY; // armazeno a origemY passada
		int pontosX[MAX_FOCOS]; // armazeno todos os pontosX de foco
		int pontosY[MAX_FOCOS]; // armazeno todos os pontosX de foco
		double** meuGrafoMatriz; // matriz que armazena as distancias
		
	public:
		// Construtor da classe e suas atribuições
		Grafo(int numVertices, int oX, int oY){
			vertices = numVertices;
			origemX = oX;
			origemY = oY;
			
			meuGrafoMatriz = new double*[numVertices];
			for (int i = 0; i < numVertices; i++) {
				meuGrafoMatriz[i] = new double[numVertices];
			}
			
			for (int i = 0; i < numVertices; i++) {
				for (int j = 0; j < numVertices; j++){
					meuGrafoMatriz[i][j] = INF;
					if(i == j){
						meuGrafoMatriz[i][j] = 0;
					}
				}
				//cout << "todos inf" << endl;
			}
			//cout << "finished" << endl;
		}
		//void adicionaAresta(int pX, int pY, int distancia);
		void capturaPontos(int X, int Y, int posicao);
		void calculaDistancia(int posicao);
		void imprimeMatriz();
		double travllingSalesmanProblem(unsigned int s);
		void segundaMenorDistancia(int focos);
};

// Grafo não direcionado, função que adiciona aresta de um vértice para
// outro, com o valor da distância
/*void Grafo::adicionaAresta(int pX, int pY, int distancia){
	meuGrafoMatriz[pX][pY] = distancia;
	meuGrafoMatriz[pY][pX] = distancia;
}*/

// Armazeno os pontos de Foco em um vetor
void Grafo::capturaPontos(int X, int Y, int posicao){
	pontosX[posicao] = X;
	pontosY[posicao] = Y;
}

// Verifico a distancia de todos os pontos de foco em relação a origem e pego a segunda menor distancia
void Grafo::segundaMenorDistancia(int focos){
	double segundaMenorDistancia[focos];
	int ordenaPosicao[focos];
	for(int i = 0; i < focos; i++){
		segundaMenorDistancia[i] = sqrt((pow(pontosX[i] - origemX, 2) + pow(pontosY[i] - origemY, 2)));
		cout << "Indice: " << i << " " << segundaMenorDistancia[i] << endl;
		ordenaPosicao[i] = i;
	}
	double aux;
	int ajuda;
	for(int i = 0; i < focos; i++){
		for (int j = 0; j < focos; j++){
			if (segundaMenorDistancia[i] < segundaMenorDistancia[j]){
				//aqui acontece a troca, do maior cara  vaia para a direita e o menor para a esquerda
				aux = segundaMenorDistancia[i];
				segundaMenorDistancia[i] = segundaMenorDistancia[j];
				segundaMenorDistancia[j] = aux;
				
				ajuda = ordenaPosicao[i];
				ordenaPosicao[i] = ordenaPosicao[j];
				ordenaPosicao[j] = ajuda;
				
			}
		}
	}
	for(int i = 0; i < focos; i++){
		//cout << "OLD POS: " << ordenaPosicao[i] << " " << segundaMenorDistancia[i] << endl;
		// fecho o grafo
		if(i == ordenaPosicao[1]){
			meuGrafoMatriz[i][0] = segundaMenorDistancia[1];
			meuGrafoMatriz[0][i] = segundaMenorDistancia[1];
		}
	}
	//return segundaMenorDistancia[1];
}

void Grafo::imprimeMatriz(){
	for(unsigned int i =0 ; i < vertices; i++){
		for(unsigned int j = 0 ; j < vertices; j++){
			cout << meuGrafoMatriz[i][j] << " ";	
		}
		cout << endl;
	}
}

void Grafo::calculaDistancia(int posicao){
	double dist;
	
	
	if(posicao == 0){ //meu primeiro foco, conecto com a origem
		dist = sqrt((pow(pontosX[posicao] - origemX, 2) + pow(pontosY[posicao] - origemY, 2)));
		meuGrafoMatriz[posicao+1][0] = dist;
		meuGrafoMatriz[0][posicao+1] = dist;
		
	}else if(posicao > 0){ // segundo foco em diante
		dist = sqrt(pow(pontosX[posicao] - pontosX[posicao-1], 2) + pow(pontosY[posicao] - pontosY[posicao-1], 2));
		meuGrafoMatriz[posicao][posicao+1] = dist;
		meuGrafoMatriz[posicao+1][posicao] = dist;
	}
	
	/*
					  // 0   1    2    3   4
						{0,2.24,9999,1.41,9999}, // 0
						{2.24,0,1.41,9999,9999}, // 1
						{9999,1.41,0,9999,1},    // 2
						{1.41,9999,9999,0,2.83}, // 3
						{9999,9999,1,2.83,0}     // 4
						
						0      2.24 2.83 INF  INF
						2.24     0  1.41 INF  INF
						2.83   1.41  0    1   INF
						INF    INF   1    0   1.41
						INF    INF  INF  1.41  0
						
	 * */
	//return (double)dist;
}

double Grafo::travllingSalesmanProblem(unsigned int s){ 
    // store all vertex apart from source vertex 
    vector<unsigned int> verticesTSP; 
    for (unsigned int i = 0; i < vertices; i++){
        if (i != s) {
            verticesTSP.push_back(i);
		}
	}
    // store minimum weight Hamiltonian Cycle. 
    double min_path = INT_MAX; 
    do { 
  
        // store current Path weight(cost) 
        double caminhoAtual = 0; 
          
        // compute current path weight 
        unsigned int k = s; 
        for (unsigned int i = 0; i < verticesTSP.size(); i++) { 
            caminhoAtual += meuGrafoMatriz[k][verticesTSP[i]]; 
            k = verticesTSP[i]; 
        } 
        caminhoAtual += meuGrafoMatriz[k][s]; 
  
        // update minimum 
        min_path = min(min_path, caminhoAtual); 
         
    } while (next_permutation(verticesTSP.begin(), verticesTSP.end())); 
  
    return min_path; 
} 

int main () { 
	 
	// Variáveis que determinam quantidade de vértices, arestas, e os parentes
	
	int focoX, focoY, qtdFocos, origemX, origemY;
	
	
	
	while(qtdFocos != 0){
		// entrada de dados
		cin >> qtdFocos;
		// Se minha quantidade de vértices for igual ou menor que 0, então não continuo o código
		if(qtdFocos == 0){
			break;
			return 0;
		}
		cin >> origemX >> origemY;
		// crio o grafo com a quantidade de vértices passada
		Grafo meuGrafo(qtdFocos+1, origemX, origemY);
		
		for(int i = 0; i < qtdFocos; i++){
			cin >> focoX >> focoY;
			meuGrafo.capturaPontos(focoX, focoY, i);
			
			meuGrafo.calculaDistancia(i);
			
		}
		
		meuGrafo.segundaMenorDistancia(qtdFocos);
		meuGrafo.imprimeMatriz();
		
		
		unsigned int s = 0; 
		printf("%.2f\n",  meuGrafo.travllingSalesmanProblem(s)); 
		
		
	}
	return 0;
}

