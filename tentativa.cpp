/* REO 04 - Algoritmos em Grafos
 * URI 1948: COMPILADOR
 * 
 * RESUMO DO PROBLEMA: Utilizar 3 tipos de registradores para duas instruções
 * 						de atribuição e de soma.
 * 
 * SOLUÇÃO: Capturar as variaveis, inserir em uma matriz de adjacências,
 * 			aplicar um algoritmo de coloração e verificar se a quantidade de cores
 * 			é superior que 3 para imprimir "Compilation Error", caso contrário "Ok".
 * 
 * ALUNOS: Kellyson Santos da Silva - 2018200366 - 10A
 * 		   Layse Cristina Silva Garcia - 201811177 - 10A
 * 
 * 02/07/2020
 */ 
#include <bits/stdc++.h> 
using namespace std; 
/*
 * 	Classe Grafo
 * 	A modelagem para o problema foi:
 * 		Não me importa o resultado final da soma, com os registradores utilizados
 * 		crio a matriz de adjacencias, onde os valores incidem em 1. Exemplo:
 * 			a := 0;
 * 			b := 1;
 * 			c := a + b;
 * 			d := a + b; 
 * 		   a b c d
 * 		a  1 0 0 0         ---> Atribuição na variavel a
 *		b  0 1 0 0		   --->  Atribuição na variavel b
 * 		c  1 1 0 0		   ---> Soma na variavel c, das variaveis a + b
 * 		d  1 1 0 0		   ---> Soma na variavel c, das variaveis a + b
 * */
class Grafo{
	private:
		int vertices;
		int** meuGrafoMatriz;
	public:
		Grafo(int numVertices){
			vertices = numVertices;
			//cout << "oi";
			meuGrafoMatriz = new int*[numVertices];
			for (int i = 0; i < numVertices; i++) {
				meuGrafoMatriz[i] = new int[numVertices];
				//cout << "up" << endl;
			}
			for (int i = 0; i < numVertices; i++) {
				for (int j = 0; j < numVertices; j++){
					meuGrafoMatriz[i][j] = -1;
				}
				//cout << "todos inf" << endl;
			}
			//cout << "finished" << endl;
		}
	void pegaValor(unsigned int i, string instrucao, int id);
	void colorindoGrafo(); 
};

/*	Como possui registradores com até 8 caracteres, "quebro" a minha linha(String)
 * 	a procura de duas ou três informações. Suponha o exemplo:
 * 				abcde := 1;
 * 				abcdf := 2;
 * 				abcdg := abcde + abcdf;
 * 	Utilizo uma id na função para encontrar "onde estou", ou seja, se meu registrador
 * 	recebeu um valor ou uma soma.
 * */
void Grafo::pegaValor(unsigned int i, string instrucao, int id){
	// abcdef_:=_oioi_+_x\0
	vertices++; // cada linha um vértice
	string atribui, valorAtribui, valorSoma;
	unsigned int cont = 0;
	if(id == 0){ // Tenho o meu registrador fonte já criado
		while(cont < i){
			atribui = instrucao[cont];
			cont++;
		}
		meuGrafoMatriz[vertices][vertices] = 1;
	}else if(id == 1){ // O meu registrador fonte está recebendo um valor;
		while(instrucao[i] == ' ' or instrucao[i] == '\0'){
			valorAtribui = instrucao[i];
			i++;
		}
		meuGrafoMatriz[vertices][vertices] = 1;
	}else{		// O meu registrador fonte está recebendo uma soma.
		while((i >= instrucao.length())or instrucao[cont] == '\0'){
			valorSoma = instrucao[cont];
			cont++;
		}
	}
	unsigned int j = 0;
	
	while(j < instrucao.length()){
		meuGrafoMatriz[vertices][j] = 1;
		meuGrafoMatriz[j][vertices] = 1;
		j++;
	}
	
}

void Grafo::colorindoGrafo(){
	int resultado[vertices]; 
	int contador;
	
    // inicializo a cor com 0
    resultado[0]  = 0; 
    
     // inicializo V-1 vertices como não colorido
    for (int u = 1; u < vertices; u++) 
        resultado[u] = -1; 
        
    // Um vetor temporário de possiveis cores.[visitado] 
    // Caso verdade a cor já foi utilizada em algum vizinho.
    bool available[vertices]; 
    for (int cr = 0; cr < vertices; cr++) 
        available[cr] = false; // se falso, é porque não foi visitado
  
    // Coloro V-1 vertices 
    for (int u = 1; u < vertices; u++) 
    { 
        // Processa todos vizinhos e suas cores caso não visitado 
        for (int j = 0; j != vertices; ++j) 
            if (resultado[j] != -1) 
                available[resultado[j]] = true; 
  
        // Encontro a primeira cor encontrada
        int cr; 
        for (cr = 0; cr < vertices; cr++) 
            if (available[cr] == false) 
                break; 
  
        resultado[u] = cr; // Pego a cor(numero) encontrada
		
		// Reinicio os valores de falso para a proximo interação
        for (int j = 0; j != vertices; ++j) 
            if (resultado[j] != -1) 
                available[resultado[j]] = false; 
        contador = cr;
    } 
	// Verifico quantidade de cores utilizadas
    for (int u = 0; u < vertices; u++) 
       // cout << "Vertex " << u << " --->  Color " << resultado[u] << endl;  
		if(resultado[u] < 4){
			cout << "OK";
		}
		
	// Imprimo o resultado 
	if(contador < 4){
		cout << "OK";
	}else{
		cout << "Compilation Error";
	}
}

int main(){  
	int quantidadeInstrucoes = 0;
	bool continua = true;
	
	string registrador = "";
	int i;
	Grafo meuGrafo(2000);
	while(getline(cin, registrador) and continua){
		if(quantidadeInstrucoes == 10 or continua == false){
			cout << "Compilation Error" << endl;
			return 0;
		}
		quantidadeInstrucoes++;
		
		i = 0;
		while (i < int(registrador.length()))
            i++;
        if (i < int(registrador.length())){
            if (registrador[i] == ' ')
                meuGrafo.pegaValor(i-1, registrador, 0); //0: Recebe
            i++;
            if (registrador[i] == ':')
				i++;
            if (registrador[i] == '=')
				i++;
            if (registrador[i] == ' ')
                 meuGrafo.pegaValor(i+1, registrador, 1); // 1: Atribuição
            i++;
            if (registrador[i] == ' ')
				i++;
            if (registrador[i] == '+')
				i++;
            if (registrador[i] == ' ')
                 meuGrafo.pegaValor(i+1, registrador, 2); // 2: Soma
            i++;
		}
		
		//cout << "QTD:" << quantidadeInstrucoes << endl;
	}
	meuGrafo.colorindoGrafo();
	return 0;
}
