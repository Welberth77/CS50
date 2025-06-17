# Verificar se o cartão é válido
from cs50 import get_int

numeroCartao = get_int("Number: ")

# Algoritmo de Luhn
# 1 - Multiplique cada outro dígito por 2, começando pelo penúltimo dígito do número, e depois some os dígitos desses produtos.
