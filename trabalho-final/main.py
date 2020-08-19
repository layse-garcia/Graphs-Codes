# coding: utf-8
'''------------------------------------------------------------Imports------------------------------------------------------------'''
from classes.Reader import XlsReaderHelper
from classes.Grafo import Grafo
'''-------------------------------------------------------------------------------------------------------------------------------'''

def main():

    arquivo = 'files/resultadopesquisa.xlsx'
    planilha = 'respostas'
    pessoas = XlsReaderHelper(arquivo, planilha).buscarPessoas()

    grafo = Grafo(pessoas)
    grafo.gerarHorario()
    # Até aqui já temos um grafo bipartido
    # Imprime a cor do vértice
    # -999 todos os vizinhos já tem alguma das cores disponíveis
    grafo.GEROU_GRAFO()

if __name__ == "__main__":
    main()
