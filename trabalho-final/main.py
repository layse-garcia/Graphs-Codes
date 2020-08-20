# coding: utf-8

###############################################################################
######            TRABALHO PRÁTICO : ALGORITMO EM GRAFOS                 ######
######                  TEMA: COLORAÇÃO EM GRAFOS                        ######
######                                                                   ######
######      KELLYSON SANTOS DA SILVA - 201820366 - 10A                   ######
######      LAYSE CRISTINA SILVA GARCIA - 201811177 - 10A                ######
###############################################################################

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
