# Verificar se o cartão é válido
from cs50 import get_int

numeroCartao = get_int("Number: ")

# Algoritmo de Luhn
# 1 - Multiplique cada outro dígito por 2, começando pelo penúltimo dígito do número, e depois some os dígitos desses produtos.
# 2 - Adicione a soma à soma dos dígitos que não foram multiplicados por 2.
# 3 - Se o último dígito do total for 0 (ou, em termos mais formais, se o total módulo 10 for congruente a 0), o número é válido!
