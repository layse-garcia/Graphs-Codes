class Pessoa:
    # Construtor
    def __init__(self, idade, sexo, cidade, quadroDeRisco, tempoDeCompra, horarioDePreferencia, diasDaSemana, sintomas):
        self.idade = idade
        self.sexo = sexo
        self.cidade = cidade
        self.quadroDeRisco = quadroDeRisco
        self.tempoDeCompra = tempoDeCompra
        self.horarioDePreferencia = horarioDePreferencia
        self.diasDaSemana = diasDaSemana
        self.sintomas = sintomas

    def getIdade(self):
    	return self.idade

    def getSexo(self):
    	return self.sexo

    def getCidade(self):
    	return self.cidade

    def getQuadroDeRisco(self):
    	return self.quadroDeRisco or self.idade >= 60

    def getTempoDeCompra(self):
    	return self.tempoDeCompra

    def getHorarioDePreferencia(self):
    	return self.horarioDePreferencia

    def getDiasDaSemana(self):
    	return self.diasDaSemana

    def getSintomas(self):
    	return self.sintomas
