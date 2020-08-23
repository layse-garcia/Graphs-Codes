# coding: utf-8

###############################################################################
######             TRABALHO PRÁTICO : ALGORITMO EM GRAFOS                ######
######                   TEMA: COLORAÇÃO EM GRAFOS                       ######
######                                                                   ######
######                      Python Version: 2.7                          ######
######                                                                   ######
######      KELLYSON SANTOS DA SILVA - 201820366 - 10A                   ######
######      LAYSE CRISTINA SILVA GARCIA - 201811177 - 10A                ######
###############################################################################
'''
    Classe Enums é utilizada como o dicionário do Trabalho. Armazena dias da semana,
    com seus respectivos IDs; assim como, horários; e letra das colunas,
    para gerar a planilha.
'''
class Enums:

    # Representação dos Dias da Semana
    DIAS = {
        0 : "Segunda-Feira",
        1 : "Terça-Feira",
        2 : "Quarta-Feira",
        3 : "Quinta-Feira",
        4 : "Sexta-Feira",
        5 : "Sábado"
    }

    # Representação dos horários de funcionamento utilizados
    HORARIOS = {
        0 : "08:00",
        1 : "09:00",
        2 : "10:00",
        3 : "11:00",
        4 : "12:00",
        5 : "13:00",
        6 : "14:00",
        7 : "15:00",
        8 : "16:00",
        9 : "17:00",
        10 : "18:00"
    }
    # Armazena as colunas que serão utilizadas para gerar a planilha de resultados
    DIA_COLUNA = {
        0 : "B",
        1 : "C",
        2 : "D",
        3 : "E",
        4 : "F",
        5 : "G"
    }
