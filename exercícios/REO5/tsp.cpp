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
		int vertices; 			  // numero de vértices
		int pontosX[MAX_FOCOS];   // armazeno todos os pontosX de foco
		int pontosY[MAX_FOCOS];   // armazeno todos os pontosX de foco
		double** meuGrafoMatriz;  // matriz que armazena as distancias
		bool** solucaoEncontrada; // marca quais soluções já foram encontradas
		double** valorEncontrado; // salva os valores encontrados para cada solução

	public:
		// Construtor da classe e suas atribuições
		Grafo(int numVertices){
			vertices = numVertices;
			meuGrafoMatriz = new double*[numVertices];
			solucaoEncontrada = new bool*[numVertices];
			valorEncontrado = new double*[numVertices];

			// Para cada vertice, temos a possibilidade de ele já ter sido ou não visitado
			// logo temos 2^numVertices possibilidades
			int numPossibilidades = 1 << numVertices; // 1<<n é o mesmo que 2^n

			for (int i = 0; i < numVertices; i++) {
				meuGrafoMatriz[i] = new double[numVertices];
				solucaoEncontrada[i] = new bool[numPossibilidades];
				valorEncontrado[i] = new double[numPossibilidades];
			}

			for (int i = 0; i < numVertices; i++) {
				for (int j = 0; j < numVertices; j++){
					meuGrafoMatriz[i][j] = INF;
					if(i == j){
						meuGrafoMatriz[i][j] = 0;
					}
				}
				// A principio nenhuma solução foi encontrada
				for (int j = 0; j < numPossibilidades; j++){
					solucaoEncontrada[i][j] = false;
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
		double encontraSolucao(int at, int vis, int nVis, int s);
		bool visitado(int vertice, int verticesVisitados);
		int visita(int vertice, int verticesVisitados);
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

// Checa se um vertice já foi visitado
bool Grafo::visitado(int vertice, int verticesVisitados){
	return ((1 << vertice) & verticesVisitados) > 0;
}

// Marca um vértice como visitado
int Grafo::visita(int vertice, int verticesVisitados){
	return (1 << vertice) | verticesVisitados;
}

double Grafo::encontraSolucao(int at, int vis, int nVis, int s){
	// Se todos os vertices já foram visitados, retorna para casa
	if (nVis == vertices){
		return meuGrafoMatriz[at][s];
	}
	// Procura a solução para o caso atual somente se ela ainda não foi encontrada
	if (!solucaoEncontrada[at][vis]){
		double melhorSolucao = INT_MAX;

		for (int i = 0; i < vertices; i++){
			// Verifica se o vertice 'i' ainda não foi visitado
			if(!visitado(i, vis)){
				// Uma possivel solução é visitar o vertice 'i' após o vertice 'at'
				// Soma a distancia para ir do vertice 'at' ao vertice 'i'
				double solucao = encontraSolucao(i, visita(i, vis), nVis+1, s) + meuGrafoMatriz[at][i];

				melhorSolucao = min(melhorSolucao, solucao);
			}
		}
		// Marca que a solução para o caso atual ja foi encontrada
		solucaoEncontrada[at][vis] = true;
		// Salva o valor encontrado para evitar a necessidade de calculá-lo novamente
		valorEncontrado[at][vis] = melhorSolucao;

	}
	// retorna o valor encontrado para o caso atual
	return valorEncontrado[at][vis];
}

// Problema resolvido com TSP
double Grafo::travllingSalesmanProblem(int s){
	// Começa a procura da solução partindo do ponto inicial,
	// somente o vertice s foi visitado até o momento
	return encontraSolucao(s, visita(s, 0), 1, s);

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
