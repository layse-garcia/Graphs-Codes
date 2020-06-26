/* REO 02 - Algoritmos em Grafos
 * URI 2585: DOMINÓ INCOMPLETO
 * 
 * RESUMO DO PROBLEMA: Encontrar a maior sequencia de peças em um domino de 55 peças.
 * 
 * SOLUÇÃO: A dupla..
 * 
 * ALUNOS: Kellyson Santos da Silva - 2018200366 - 10A
 * 		   Layse Cristina Silva Garcia - 201811177 - 10A
 * 
 * 23/06/2020
 */

#include <bits/stdc++.h>
using namespace std;

// Quantidade máxima de vértices, de acordo com o enunciado V(1 ≤ V ≤ 55)
#define MAX_VERTICES 55

class Grafo {    
public: 

	// Criação do grafo
	vector<unsigned int> meuGrafo[MAX_VERTICES];
	
	// Construtor
	Grafo(){
		for (unsigned i = 0; i < MAX_VERTICES; i++){
			
			// Limpa o grafo, pode-se dizer que limpa os valores lixos, caso houver
			meuGrafo[i].clear();
			
		}
	}
	
    // Função responsável por conectar um vértice ao outro, após a verificação de vizinhos
    void insereAresta(int verticeDe, int verticePara);  
	
    // Utilização da Busca em Largura 
    int buscaEmLargura(int inicio, int V);
    
}; 

void Grafo::insereAresta(int verticeDe, int verticePara){
	
	// Adiciona o verticePara para a lista do verticeDe
	// EXEMPLO: [0 -> 1, 1 -> 2 , 2 -> 4]
    meuGrafo[verticeDe].push_back(verticePara);
    
}

int Grafo::buscaEmLargura(int inicio, int V) { 
	// Vetor que armazena as distancias para a sequencia
	int calculaDistancia[V];
	
    // Para todos os vertices, visitado é iniciado como falso
    // Inicializo a distancia dos vertices em 0
    bool *visitado = new bool[V]; 
    for(int i = 0; i < V; i++){
        visitado[i] = false; 
        calculaDistancia[i] = 0;
	}
	
    // Criação da fila para a Busca em Largura
    list<int> fila; 
	
    // Marco o vértice que foi passado como parametro como visitado
    // Como a fila garante a ordem de chegada, coloco na fila
    visitado[inicio] = true;
    fila.push_back(inicio); 
  
    // Será usado para pegar todos os vertices vizinhos do vértice
    list<int>::iterator i; 
	int maiorSequencia = 0;
	// Enquanto a fila não estiver vazia
    while(!fila.empty()){ 
		
        // Acesso o primeiro elemento da fila e depois retiro
        int primeiroElemento = fila.front();
        //cout << "primeiro elemento da fila" << primeiroElemento << endl;
        fila.pop_front(); 
		
		// Pego os vertices vizinhos do vertice retirado.
        for (unsigned int i = 0; i < meuGrafo[primeiroElemento].size(); i++){
			
			// Recupero os vzinhos do vértice retirado 
			int recupera = meuGrafo[primeiroElemento][i];
			
			// Se o vizinho ainda não foi visitado, faço todo o processo de enfileirar e marcar como visitado
            if (!visitado[recupera]){ 
                fila.push_back(recupera);
                visitado[i] = true;
                
                // Somo as passagens pelos vizinhos
                calculaDistancia[recupera] = calculaDistancia[primeiroElemento]+1;
                //cout << "distancia " << calculaDistancia[recupera] << endl;
            }  
            maiorSequencia = calculaDistancia[recupera];
        } 
    } 
    
    // retorno a quantidade de peças
    return maiorSequencia;
    
} 
  

int main() { 
	// Entrada do usuário, quantidade de inserções
    int totalLinhas;
    
    // Booleana que permite que o programe continue ou pare
    bool continua = false;
    
    // Entradas do usuário, queais são os vertices
    int verticeDe, verticePara;
    
    // Entradas da matriz
    cin >> totalLinhas;
    
    // TRATAMENTO: Caso as entradas não correpondam ao intervalo permitido pelo enunciado, o programa não é executado
    if((totalLinhas <= 0) or (totalLinhas > 55)){
		continua = false;
	}else{
		continua = true;
	}
	
    while(continua){
		Grafo meuGrafo;
		
		// Entrada do usuário conectando um vértice ao outro
		for(int i = 0; i < totalLinhas; i++){
			cin >> verticeDe >> verticePara;
			meuGrafo.insereAresta(verticeDe-1, verticePara-1);
		}
		
		int sequencia = 0;
		// Ao passar por todas as minhas linhas, busco a maior sequência
		for(int i = 0; i < totalLinhas; i++){
			sequencia = max(meuGrafo.buscaEmLargura(i,totalLinhas), sequencia);
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

