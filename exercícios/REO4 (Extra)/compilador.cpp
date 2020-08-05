#include <bits/stdc++.h>
using namespace std;

class Grafo {
	public:
		int V;
	//private String registrador;
	//private bool declarado = false;
	//bool saida[];
	
		int** meuGrafoMatriz;
	 
	// declarado = true: A := B
	// declarado = false SOMA A := A := B + C
	Grafo(int cont){
		V = cont;
		
		
		//cout << "oi";
		meuGrafoMatriz = new int*[cont];
		for (int i = 0; i < cont; i++) {
			meuGrafoMatriz[i] = new int[cont];
			//saida[cont] = false;
			//cout << "up" << endl;
		}
		for (int i = 0; i < cont; i++) {
			for (int j = 0; j < cont; j++){
				meuGrafoMatriz[i][j] = 0;
			}
			//cout << "todos inf" << endl;
		}
		//cout << "finished" << endl;
		
	}
	
	void minhaEstrutura(int l, int c, char recebe, char valor1, char valor2){
		cout << "Linha: " << l << " Coluna: " << c << endl;
		cout << "Recebe: " << recebe << " Valor1: " << valor1 << " Valor2: " << valor2 <<endl;
		/*for(int i = 0; i < V; i++){
			for(int j = 0; j < V; j++){
				if(auxiliar == '.'){ //to atribuindo valor
					if(l == i and c == j){
						meuGrafoMatriz[i][j] = 1;
					}
				}else{
						
				}
			
			}
		}*/
	}
	
	void solucao(){
		
		
		list<int> fila;
	}
	
};

int main() { 
    
    // Booleana que permite que o programe continue ou pare
    bool continua = true;
    
    // Variável e vetor String para armazenar as entradas e depois manipulá-las
    string caractere; //caractere
    vector<string> caracterePorLinha;
    
    // Entradas da matriz
    cin >> caractere;
    
    // TRATAMENTO: Caso as entradas não correpondam ao intervalo permitido pelo enunciado, o programa não é executado
    /*if(instrucao.size() <= 8){
		continua = false;
	}else{
		continua = true;
	}*/
	
    while(continua){
		// Criação da matriz com os valores do usuário
		int contador = 1;
		while(contador < 5){
			// Entrada do teclado do usuário
			cin >> caractere;
			// Insiro a linha de caractere no meu vector
			caracterePorLinha.push_back(caractere);
			contador++;
		}
		
		Grafo meuGrafo(contador); 
		
		for(int i = 0; i < contador; i++){
			char a,b,c;
			for (unsigned int j = 0; j < caracterePorLinha[i].size(); j++){
				// Se achei., posso dizer que um vértice foi encontrado
				if(caractere[j]==':'){
					a = caractere.front();
					b = caractere.at(5);
					meuGrafo.minhaEstrutura( i, j, a,b,c); // X := B
				//}else if(caractere[j]==':=' && caractere[j]=='+'){
					if(caractere[j] == '+'){
						c = caractere.at(9);
						meuGrafo.minhaEstrutura( i, j, a,b,c); // X := B + G
					}
				}
			}
		}
		
		
	}
    
    
  
    return 0; 
} 
