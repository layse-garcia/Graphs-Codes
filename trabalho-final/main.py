# coding: utf-8

###############################################################################
######             TRABALHO PRÁTICO : ALGORITMOS EM GRAFOS               ######
######                   TEMA: COLORAÇÃO EM GRAFOS                       ######
######                                                                   ######
######                      Python Version: 3.8                          ######
######                                                                   ######
######      KELLYSON SANTOS DA SILVA - 201820366 - 10A                   ######
######      LAYSE CRISTINA SILVA GARCIA - 201811177 - 10A                ######
###############################################################################

'''------------------------------------------------------------Imports------------------------------------------------------------'''
from classes.XlsHelper import Reader, Writer
from classes.Grafo import Grafo

import sys
'''-------------------------------------------------------------------------------------------------------------------------------'''

'''
    Método main que executa o código.
'''
def main():

    # Recebe o nome do arquivo que está armazenando os dados da pesquisa
    arquivoEntrada = 'files/resultadopesquisa.xlsx'
    # Determina qual será o arquivo com os horários de compra, após o algoritmo
    arquivoResultado = 'files/agendaDeHorarios.xlsx'

    # Armazena o nome da aba
    planilha = 'respostas'

    # Faz a leitura do arquivo
    pessoas = Reader(arquivoEntrada, planilha).buscarPessoas()

    cidade = input("Digite uma cidade sem os acentos para filtrar: (Caso não queira, pressione ENTER)\n- ")

    # Caso não tenha sido escolhida nenhuma cidade, atribui "Todos" à variável
    if len(cidade) == 0:
        cidade = 'Todos'

    # Verifica se a cidade contém apenas caracteres ASCII
    if all(ord(c) < 128 for c in cidade):
        print("\nA agenda será gerada para " + cidade + " e salva no arquivo " + arquivoResultado)
    else:
        # Encerra o programa quando a string possui algum caractere unicode
        print("Provavelmente você digitou o nome da cidade com caracteres especiais. Revise por favor e tente novamente.")
        sys.exit()

    # Após a leitura do arquivo, cria o Grafo com os dados capturados
    grafo = Grafo(pessoas, cidade)

    # Inicializa o processo de coloração
    grafo.iniciarColoracao()

    # Inicia o processo de otimização nos resultados
    grafo.refinarColoracao()

    # Transfere o Grafo para a Schedule(Agenda)
    grafo.prepararAgenda()

    # Restringe a quantidade de pessoas, de acordo com o valor do parâmetro
    grafo.refinarAgenda(5)

    # Gera a planilha para imprimir os resultados
    planilhaResultado = Writer(arquivoResultado).CriaPlanilha(grafo.schedule, nomeDaAba = cidade)

if __name__ == "__main__":
    main()
