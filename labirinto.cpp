/* REO 02 - Algoritmos em Grafos
 * URI 1621: LABIRINTO
 * 
 * RESUMO DO PROBLEMA: A partir da entrada e saída do usuário, o código deve calcular
 * 					   o caminho para terminar o Labirinto.
 * 
 * ALUNOS: Kellyson Santos da Silva - 2018200366 - 10A
 * 		   Layse Cristina Silva Garcia - 201811177 - 10A
 * 
 * 19/06/2020
 */

#include <bits/stdc++.h>
using namespace std;


// A classe Grafo utiliza uma lista de adjacência
class Grafo { 
    
    // Numero de Vertices encontrados
    int V; 
  
    // Ponteiro da lista de adjacências do Grafo
    list<int> *adj;    
public: 
    // Função responsável por conectar um vértice ao outro, após a verificação de vizinhos
    void insereAresta(int verticeDe, int verticePara);  
	
	// Função que retorna a Saída do Labirinto
	int saidaLabirinto(int distancia);
	
    // Utilização da Busca em Largura 
    int BFS(int inicio);
    
    // Construtor
    Grafo(int meuVertice) { 
		V = meuVertice; 
		adj = new list<int>[V]; 
		
	} 
	
}; 
void Grafo::insereAresta(int verticeDe, int verticePara){
	
	// Adiciona o verticePara para a lista do verticeDe
	// EXEMPLO: [0 -> 1 - > 2 , 1 -> 0 , 2 -> 0]
    adj[verticeDe].push_back(verticePara);
   
    // adj[verticePara].push_back(verticeDe);
    
} 

int Grafo::saidaLabirinto(int distancia){

	int primeiraVez, ultimaVez;
	primeiraVez = BFS(distancia);
	ultimaVez = BFS(primeiraVez);
	return ultimaVez;
	
}
  
//meuPar Grafo::BFS(int inicio) { 
int Grafo::BFS(int inicio) { 
	
	// Vetor que armazena as distancias para o caminho
	int calculaDistancia[V];
	
    // Para todos os vertices, visitado é iniciado como falso e inicializo a distancia dos vertices
    bool *visitado = new bool[V]; 
    for(int i = 0; i < V; i++){
        visitado[i] = false; 
        calculaDistancia[i] = -1;
	}
    // Criação da fila para a Busca em Largura e distancia dada como 0
    list<int> fila; 
	calculaDistancia[inicio] = 0;
	
    // Marco o vértice que foi passado como parametro como visitado e o coloco na fila
    visitado[inicio] = true; 
    fila.push_back(inicio); 
  
    // será usado para pegar todos os vertices vizinhos do vértice
    list<int>::iterator i; 
  
	// Enquanto a fila não estiver vazia
    while(!fila.empty()){ 
        // Acesso o primeiro elemento da fila e depois retiro
        int primeiroElemento = fila.front();
        fila.pop_front(); 
		
		// Pego os vertices vizinhos do vertice retirado.
		
        for (i = adj[primeiroElemento].begin(); i != adj[primeiroElemento].end(); ++i){ 
			// Se o vizinho ainda não foi visitado, faço todo o processo de enfileirar e marcar como visitado
            if (!visitado[*i]){ 
                visitado[*i] = true; 
                fila.push_back(*i); 
                calculaDistancia[*i] = calculaDistancia[primeiroElemento]+1;
            } 
        } 
    } 
    
   
    int maior = 0;
    int verticeDistante = 0;
    // Para cada vértice, comparo se a distancia do meu vetor em i é maior que maior
    for(int i = 0; i < V; i++){
		if(calculaDistancia[i] > maior){
			maior = calculaDistancia[i];
			// E assim troco quem é o vertice mais distante
			verticeDistante = i;
		}
	}
    return maior;
    
} 
  

int main() { 
	
    // totalLinhas e totalColunas são variaveis que o usuário irá inserir para definir a matriz
    int totalLinhas, totalColunas;
    
    // Booleana que permite que o programe continue ou pare
    bool continua = false;
    
    // Variável e vetor String para armazenar as entradas e depois manipulá-las
    string caractere;
    vector<string> caracterePorLinha;
    
    // Entradas da matriz
    cin >> totalLinhas >> totalColunas;
    
    // Caso as entradas não correpondam ao intervalo permitido pelo enunciado, o programa não é executado
    if((totalLinhas <= 4) or (totalColunas <=4) or (totalLinhas > 500) or (totalColunas > 500)){
		continua = false;
	}else{
		continua = true;
	}
    while(continua and totalLinhas!=0 and totalColunas!=0){
		// Criação da matriz com os valores do usuário
		int matrizVertices[totalLinhas][totalColunas];
		
		// Incrementador para saber a quantidade de vértices do Caso
		int totalVertices = 0;
		
		for(int i = 0; i < totalLinhas; i++){
			// Entrada do teclado do usuário
			cin >> caractere;
			for (int j = 0; j < totalColunas; j++){
				// Se achei., posso dizer que um vértice foi encontrado
				if(caractere[j]=='.'){
					matrizVertices[i][j] = totalVertices;
					totalVertices++;
				}else{
					matrizVertices[i][j] = -1;
				}
			}
			// Insiro a linha de caractere no meu vector
			caracterePorLinha.push_back(caractere);
		}
		
		/* BLOCO DE TESTES
		// Imprime total de Vertices do problema
		cout<<totalVertices;
		//Imprime cada Linha
		for(auto i: caracterePorLinha){
			cout<< i << endl;
		}
		// Imprime a matrizz de vertices
		for(int i = 0; i < totalLinhas; i++){
			for(int j =0; j < totalColunas; j++){
				cout << matrizVertices[i][j] << " ";
			}
			cout << endl;
		}
		*/
		// Criação do Grafo
		Grafo meuGrafo(totalVertices); 
		
		/*	|0|1|2|3|4|
			|o # o o o|0
			|o o X # #|1
			|o # o # #|2 
			|o # o o o|3 
			|# # # # #|4
		*/
		
		// Verificação de vizinhos
		for(int i = 0; i < totalLinhas; i++){
			for(int j =0; j < totalColunas; j++){
				if (caracterePorLinha[i][j]=='.'){
					// Se meu vizinho está acima de mim(X), então insiro uma Aresta com o vértice de Cima
					if(i > 0){
						if(caracterePorLinha[i-1][j] == '.'){
							meuGrafo.insereAresta(matrizVertices[i][j], matrizVertices[i-1][j]);
						}
					}
					// Se meu vizinho está abaixo de mim(X), então insiro uma Aresta com o vértice de Baixo
					if(i > totalLinhas - 1){
						if(caracterePorLinha[i+1][j] == '.'){
							meuGrafo.insereAresta(matrizVertices[i][j], matrizVertices[i+1][j]);
						}
					}
					// Se meu vizinho está a esquerda de mim(X), então insiro uma Aresta com o vértice da Esquerda
					if(j > 0){
						if(caracterePorLinha[i][j-1] == '.'){
							meuGrafo.insereAresta(matrizVertices[i][j], matrizVertices[i][j-1]);
						}
					}
					// Se meu vizinho está a direita de mim(X), então insiro uma Aresta com o vértice da Direita
					if(j < totalColunas - 1){
						if(caracterePorLinha[i][j+1] == '.'){
							meuGrafo.insereAresta(matrizVertices[i][j], matrizVertices[i][j+1]);
						}
					}
				}
			}
		}
		cout << endl << endl;
		cout << meuGrafo.saidaLabirinto(0) << endl;
		
		// Novas Entradas
		cin >> totalLinhas >> totalColunas;
		
		// Caso as entradas não correpondam ao intervalo permitido pelo enunciado, o programa não é executado
		if((totalLinhas <= 4) or (totalColunas <=4) or (totalLinhas > 500) or (totalColunas > 500)){
			continua = false;
		}else{
			
			// Variáveis que possuem valor são limpas para o próximo caso
			continua = true;
			caracterePorLinha.clear();
			totalVertices = 0;
		}
	}
    
    
  
    return 0; 
} 
