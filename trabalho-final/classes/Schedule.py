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
    Classe Schedule que representa a Agenda de horários na semana

    Em termos de coloração, a estrutura armazena as cores, onde
    cada posição na matriz armazena os vértices que possuem a cor

    A decisão foi tomada para facilitar o acesso durante a coloração.
'''
class Schedule:

    # Construtor da classe
    def __init__(self):
        self.horariosUtilizados = 0
        self.naoAlocados = []
        self.dias = [[[] for j in range(11)] for i in range(6)]

    # Insere pessoa em um dia e hora na "agenda"
    def insert(self, alguem, dia, hora):

        if self.contarAgendados(dia, hora) == 0:
            self.horariosUtilizados += 1

        self.dias[dia][hora].append(alguem)

    # Retorna o dia e hora da semana
    def get(self, dia, hora):
        return self.dias[dia][hora]

    # Conta quantas pessoas foram agendadas naquele horário
    def contarAgendados(self, dia, hora):
        return len(self.dias[dia][hora])

    # Método que insere pessoas em determinado horário, caso sua capacidade chegue
    # ao limite, as pessoas que coincidiram com aquele mesmo horário são armazenadas
    # em uma lista de Não Alocados, a fim de serem realocados novamente
    def refinar(self, maximo):
        for dia in self.dias:
            for horario in dia:

                while len(horario) > maximo:

                    elementoAvulso = horario.pop()
                    realocado = self.procurarUmNovoHorario(elementoAvulso, maximo)

                    if not realocado:
                        self.naoAlocados.append(elementoAvulso)
                        print(str(elementoAvulso.pessoa.index) + " não alocado")

    # Método que procura um novo horário para a pessoa, caso o limite de pessoas
    # naquele horário tenha chegado na sua capacidade
    def procurarUmNovoHorario(self, elemento, max):

        for id, dia in enumerate(self.dias):
            for ih, horario in enumerate(dia):

                if len(horario) < max:

                    disponivel = False

                    if len(horario) == 0:
                        disponivel = True
                    elif elemento.pessoa.getQuadroDeRisco() == horario[0].pessoa.getQuadroDeRisco():
                        disponivel = True

                    if disponivel:
                        self.realocar(id, ih, elemento)
                        return True

        return False

    # Método que adiciona a pessoa em tal dia e horário
    def realocar(self, dia, horario, elemento):
        print("realocando " + str(elemento.pessoa.index) + " de " + str(elemento.cor) +" na " + str(dia) + " " + str(horario))
        self.dias[dia][horario].append(elemento)
        elemento.cor = (dia, horario)
