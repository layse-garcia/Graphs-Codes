# coding: utf-8

###############################################################################
######             TRABALHO PRÁTICO : ALGORITMO EM GRAFOS                ######
######                   TEMA: COLORAÇÃO EM GRAFOS                       ######
######                                                                   ######
######                      Python Version: 3.4                          ######
######                                                                   ######
######      KELLYSON SANTOS DA SILVA - 201820366 - 10A                   ######
######      LAYSE CRISTINA SILVA GARCIA - 201811177 - 10A                ######
###############################################################################

'''------------------------------------------------------------Imports------------------------------------------------------------'''
from classes.Reader import XlsReaderHelper
from classes.Grafo import Grafo
'''-------------------------------------------------------------------------------------------------------------------------------'''

'''
    Método main que executa o código.
'''
def main():

    arquivo = 'files/resultadopesquisa.xlsx'
    planilha = 'respostas'
    pessoas = XlsReaderHelper(arquivo, planilha).buscarPessoas()

    grafo = Grafo(pessoas)

    grafo.iniciarColoracao()
    grafo.refinarColoracao()

    grafo.prepararAgenda()
    #grafo.refinarAgenda(5)

    # PARA FINS DE TESTE
    grafo.GEROU_GRAFO()

if __name__ == "__main__":
    main()
