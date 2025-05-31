# Número minimo para troco
from cs50 import get_float

# Se o número for negativo não passa
while True:
    troco = get_float("Change: ")

    if troco > 0:
        break

# Moedas de 0.25, 0.10, 0.5, 0.1 centavos
moedas = 0

while True:
    # Troco de 0.25
    if troco >= 0.25:
        troco = troco - 0.25
        # Arredondando troco para duas casas decimais
        troco = round(troco, 2)
        # Contagem das moedas
        moedas = moedas + 1
    # Troco de 0.10
    elif troco >= 0.10:
        troco = troco - 0.10
        # Arredondando troco para duas casas decimais
        troco = round(troco, 2)
        # Contagem das moedas
        moedas = moedas + 1
    # Troco de 0.05
    elif troco >= 0.05:
        troco = troco - 0.05
        # Arredondando troco para duas casas decimais
        troco = round(troco, 2)
        # Contagem das moedas
        moedas = moedas + 1
    # Troco de 0.01
    elif troco >= 0.01:
        troco = troco - 0.01
        # Arredondando troco para duas casas decimais
        troco = round(troco, 2)
        # Contagem das moedas
        moedas = moedas + 1
    else:
        break

print(moedas)
