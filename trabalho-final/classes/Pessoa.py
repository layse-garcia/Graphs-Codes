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
'''
    Classe Pessoa que armazena os dados coletados no formulários referente a uma
    pessoa que preencheu. A classe também possui métodos para retornar os devidos
    dados de tal objeto.
'''
class Pessoa:
    # Construtor
    def __init__(self, index, idade, sexo, cidade, quadroDeRisco, tempoDeCompra, horarioDePreferencia, diasDaSemana, sintomas):
        self.index = index
        self.idade = idade
        self.sexo = sexo
        self.cidade = cidade
        self.quadroDeRisco = quadroDeRisco
        self.tempoDeCompra = tempoDeCompra
        self.horarioDePreferencia = horarioDePreferencia
        self.diasDaSemana = diasDaSemana
        self.sintomas = sintomas

    # Idade da pessoa
    def getIdade(self):
    	return self.idade

    # Retorna o Sexo da pessoa, podendo ser Feminino, Masculino ou ND(não identificou)
    def getSexo(self):
    	return self.sexo

    # Retorna a cidade da pessoa
    def getCidade(self):
    	return self.cidade

    # Retorna se a pessoa está no quadro de risco. Observe que se a pessoa, não
    # tiver preenchido que pertence ao quadro de risco e possui idade de 60 anos
    # ou mais, a mesma é classificada automaticamente como pertencente ao grupo
    # de risco
    def getQuadroDeRisco(self):
    	return self.quadroDeRisco or self.idade >= 60

    # Tempo Médio de Compras em minutos
    def getTempoDeCompra(self):
    	return self.tempoDeCompra

    # Retorna o(s) horário(s) de preferência para fazer compras
    def getHorarioDePreferencia(self):
    	return self.horarioDePreferencia

    # Retorna o(s) dia(s) da semana preenchido(s)
    def getDiasDaSemana(self):
    	return self.diasDaSemana

    # Retorna um booleano, caso a pessoa apresente sintomas de gripe
    def getSintomas(self):
    	return self.sintomas
