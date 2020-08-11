/* REO 05 - Algoritmos em Grafos
 * URI 2088: Combate à Dengue
 * 
 * RESUMO DO PROBLEMA: João pegou dengue e suspeita que há focos próximo a sua casa.
 * 					   Quando melhorar, João quer passar por todos os focos apenas uma 
 * 					   vez para destruí-los e retornar para sua casa. Logo, é preciso 
 * 					   calcular a distância mínima a ser percorrida.
 * 
 * SOLUÇÃO: EM DESENVOLVIMENTO
 * 
 * ALUNOS: Kellyson Santos da Silva - 2018200366 - 10A
 * 		   Layse Cristina Silva Garcia - 201811177 - 10A
 * 
 * 02/07/2020
 */ 
#include <bits/stdc++.h> 
#include <math.h>

using namespace std; 
// Valor simbólico de infinito
#define INF 9999999
// Quantidade de focos possíveis 15 + 1(origem)
#define MAX_FOCOS 16

// Classe Grafo
class Grafo{
	private:
		int vertices; // numero de vértices
		int pontosX[MAX_FOCOS]; // armazeno todos os pontosX de foco
		int pontosY[MAX_FOCOS]; // armazeno todos os pontosX de foco
		double** meuGrafoMatriz; // matriz que armazena as distancias
		
	public:
		// Construtor da classe e suas atribuições
		Grafo(int numVertices){
			vertices = numVertices;
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
		
		void imprimeMatriz();
		void capturaPontos(int X, int Y, int posicao);
		void calculaDistancia();
		double distanciaEntreDoisPontos(int pX1, int pY1, int pX2, int pY2);
		double travllingSalesmanProblem(int s);
		
};

// Função para debugar a matriz
void Grafo::imprimeMatriz(){
	for(int i =0 ; i < vertices; i++){
		for(int j = 0 ; j < vertices; j++){
			cout << meuGrafoMatriz[i][j] << " ";	
		}
		cout << endl;
	}
}


// Armazeno os pontos de Foco em um vetor
void Grafo::capturaPontos(int X, int Y, int posicao){
	pontosX[posicao] = X;
	pontosY[posicao] = Y;
}

// Calculo a distancia dos pontos X e Y, criando a "aresta" na minha estrutura
void Grafo::calculaDistancia(){
	for (int i = 0; i < vertices; i++){
		for (int j = i; j < vertices; j++){
			meuGrafoMatriz[i][j] = distanciaEntreDoisPontos(pontosX[i], pontosY[i], pontosX[j], pontosY[j]);
			meuGrafoMatriz[j][i] = distanciaEntreDoisPontos(pontosX[i], pontosY[i], pontosX[j], pontosY[j]);
		}
	}	
}

// Fórmula para encontrar a distância entre dois pontos(tamanho da aresta)
double Grafo::distanciaEntreDoisPontos(int pX1, int pY1, int pX2, int pY2){
	double dist;
	dist = sqrt((pow(pX1 - pX2, 2) + pow(pY1 - pY2, 2)));
	return dist;
}

// Problema resolvido com TSP
double Grafo::travllingSalesmanProblem(int s){  
    // Pego todos os vértices a partir do vértice passado por parâmetro
    vector<int> verticesTSP; 
    for (int i = 0; i < vertices; i++){
        if (i != s) {
            verticesTSP.push_back(i);
		}
	}
	
    // Recupero a menor distância do Grafo Hamiltoniano(ciclo)
    double min_path = INT_MAX; 
    
    // Função que reorganiza os elementos no intervalo [primeiro, último)
    // na próxima permutação lexicograficamente maior.
    while(next_permutation(verticesTSP.begin(), verticesTSP.end())){
		// Inicializo a minha variável de caminho Atual como 0
        double caminhoAtual = 0; 
          
        // Incremento as distâncias
        int k = s; 
        for (int i = 0; i < (int)verticesTSP.size(); i++) { 
            caminhoAtual += meuGrafoMatriz[k][verticesTSP[i]]; 
            k = verticesTSP[i]; 
        } 
        caminhoAtual += meuGrafoMatriz[k][s]; 
  
        // Atualizo o menor caminho
        min_path = min(caminhoAtual, min_path); 
	}
	// Retorno o menor caminho
    return min_path; 
} 

int main(){
	int qtdFocos;
	// Entrada de quantidade de focos
	cin >> qtdFocos;
	while(qtdFocos > 0){
		// Adiciono mais um, para considerar o índice 0 como origem
		qtdFocos = qtdFocos+1;
		int pontoX, pontoY;
		
		// Crio meu grafo
		Grafo meuGrafo(qtdFocos);

		// Guardo os valores dos focos em vetores
		for (int i = 0; i < qtdFocos; i++){
			cin >> pontoX >> pontoY;
			meuGrafo.capturaPontos(pontoX, pontoY, i);
		}
		// Insere as distâncias na Matriz de Adjacências
		meuGrafo.calculaDistancia();
		// DEBUG: analisar a matriz
		// meuGrafo.imprimeMatriz();
		
		int s = 0;
		// Como estamos utilizando double, já configuramos a saída para sair
		// duas casas decimais
		printf("%.2f\n",  meuGrafo.travllingSalesmanProblem(s)); 
		cin >> qtdFocos;
	}
	return 0;
}
