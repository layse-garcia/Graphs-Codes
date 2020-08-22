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

'''
    Classe Schedule que representa a Agenda de horários na semana

    Em termos de coloração, a estrutura armazena as cores, onde
    cada posição na matriz armazena os vértices que possuem a cor

    A decisão foi tomada para facilitar o acesso durante a coloração
'''
class Schedule:

    # Construtor da classe
    def __init__(self):
        self.horariosUtilizados = 0
        self.schedule = [[[] for j in range(11)] for i in range(6)]

    # Insere pessoa em um dia e hora na "agenda"
    def insert(self, alguem, dia, hora):

        if self.contarAgendados(dia, hora) == 0:
            self.horariosUtilizados += 1
            
        self.schedule[dia][hora].append(alguem)


    # Retorna o dia e hora da semana
    def get(self, dia, hora):
        return self.schedule[dia][hora]

    # Conta quantas pessoas foram agendadas naquele horário
    def contarAgendados(self, dia, hora):
        return len(self.schedule[dia][hora])

    def ordenarPredilecao(self, dias, horas):

        lista = []

        for dia in dias:
            for hora in horas:
                lista.append((dia, hora))

        lista.sort(key = lambda (self, x) : self.contarAgendados(x[0], x[1]))

        return lista

    # Imprime a agenda
    def printSchedule(self):
        for i in range(11):
            for j in range(6):
                print "",
