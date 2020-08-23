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
from classes.XlsHelper import Reader, Writer
from classes.Grafo import Grafo
'''-------------------------------------------------------------------------------------------------------------------------------'''

'''
    Método main que executa o código.
'''
def main():

    # Recebe o nome do arquivo que está armazenando os dados da pesquisa
    arquivoEntrada = 'files/resultadopesquisa.xlsx'

    # Armazena o nome da aba
    planilha = 'respostas'

    # Faz a leitura do arquivo
    pessoas = Reader(arquivoEntrada, planilha).buscarPessoas()

    # Após a leitura do arquivo, cria o Grafo com os dados capturados
    grafo = Grafo(pessoas)

    # Inicializa o processo de coloração
    grafo.iniciarColoracao()

    # Inicia o processo de otimização nos resultados
    grafo.refinarColoracao()

    # Transfere o Grafo para a Schedule(Agenda)
    grafo.prepararAgenda()

    grafo.refinarAgenda(5)

    # Determina qual será o arquivo com os horários de compra, após o algoritmo
    arquivoResultado = 'files/agendaDeHorarios.xlsx'

    # Gera a planilha para imprimir os resultados
    planilhaResultado = Writer(arquivoResultado).CriaPlanilha(grafo.schedule, nomeDaAba = 'Todos')

if __name__ == "__main__":
    main()
