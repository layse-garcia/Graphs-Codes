# coding: utf-8
import openpyxl #install from: pip install openpyxl
from Pessoa import Pessoa
from enum.Enums import Enums

class XlsReaderHelper:
    @staticmethod
    def buscarPessoas(nomeArquivo, nomeDaAba):

        pessoas = []
        dias = Enums.DIAS
        horarios = Enums.HORARIOS
        # Carrego o meu arquivo
        workBook = openpyxl.load_workbook(nomeArquivo)
        workSheet = workBook[nomeDaAba]

        for linha in range(2, workSheet.max_row + 1): # +1 não inclusivo
            idade = workSheet.cell(row = linha, column = 2).value
            sexo = workSheet.cell(row = linha, column = 3).value
            cidade = workSheet.cell(row = linha, column = 4).value
            quadroDeRisco = workSheet.cell(row = linha, column = 5).value
            tempoMedio = workSheet.cell(row = linha, column = 6).value
            horarioDePreferencia = str(workSheet.cell(row = linha, column = 7).value).split(' - ')
            diasDaSemana = str(workSheet.cell(row = linha, column = 8).value).split(' - ')
            sintomas = workSheet.cell(row = linha, column = 9).value

            pessoa = Pessoa(idade, sexo, cidade, quadroDeRisco, tempoMedio, horarioDePreferencia, diasDaSemana, sintomas)
            pessoas.append(pessoa)

        return pessoas
