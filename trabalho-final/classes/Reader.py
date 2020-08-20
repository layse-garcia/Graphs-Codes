# coding: utf-8
import openpyxl #install from: pip install openpyxl
from Pessoa import Pessoa
from enum.Enums import Enums

class XlsReaderHelper:

    # Construtor da classe inicializa o leitor do arquivo
    def __init__(self, arquivo, aba):
        workBook = openpyxl.load_workbook(arquivo)
        self.workSheet = workBook[aba]
        self.maxRow =  self.workSheet.max_row

    def getCell(self, linha, coluna):
        return self.workSheet.cell(row = linha, column = coluna).value

    def buscarPessoas(self):

        pessoas = []

        integer = 2
        for linha in range(2, self.maxRow + 1): # +1 não inclusivo

            idade = self.getCell(linha, 2)
            sexo = self.getCell(linha, 3)
            cidade = self.getCell(linha, 4)
            quadroDeRisco = self.getCell(linha, 5)
            tempoMedio = self.getCell(linha, 6)

            horarioDePreferencia = str(self.getCell(linha, 7)).split(' - ')
            horarioDePreferencia = toInteger(horarioDePreferencia)

            diasDaSemana = str(self.getCell(linha, 8)).split(' - ')
            diasDaSemana = toInteger(diasDaSemana)

            sintomas = self.getCell(linha, 9)

            pessoa = Pessoa(linha - 1, idade, sexo, cidade, quadroDeRisco, tempoMedio, horarioDePreferencia, diasDaSemana, sintomas)
            pessoas.append(pessoa)

        return pessoas

def toInteger(lista):
    return list(map(int, lista))
