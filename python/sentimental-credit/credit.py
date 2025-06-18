# Verificar se o cartão é válido
from cs50 import get_int

numeroCartao = get_int("Number: ")

# America Express
# 15 digitos, começa com 34 ou 37

# Mastercard
# 16 Digitos, comeca com 51, 52, 53, 54 ou 55

# Visa
# 13 ou 16 digitos, comeca com 4

# Algoritmo de Luhn
# 1 - Multiplique cada outro dígito por 2, começando pelo penúltimo dígito do número, e depois some os dígitos desses produtos.
# 2 - Adicione a soma à soma dos dígitos que não foram multiplicados por 2.
# 3 - Se o último dígito do total for 0 (ou, em termos mais formais, se o total módulo 10 for congruente a 0), o número é válido!

for i in range(numeroCartao):
    print(numeroCartao[i])
