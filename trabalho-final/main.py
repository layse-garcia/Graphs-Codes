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
    # Só imprime quantos vizonhos tem cada vértice :)
    # Até aqui já temos um grafo bipartido
    #grafo.GEROU_GRAFO()

    grafo.gerarHorario()

if __name__ == "__main__":
    main()
