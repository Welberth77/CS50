# Medir o nível de escolaridade do texto
from cs50 import get_string

text = get_string("Text: ")

# Calcular o número de letras, palavras e frases

# Calculando quantas letras tem no texto
letras = 0

for i in text:
    # isalpha() verifica se é uma letra
    if i.isalpha():
        letras += 1

# Calculando o número de palavras no texto
# Sequência de caracteres separados por espaço
palavras = 0

for j in text:
    if j == " ":
        palavras += 1
# Mais 1 no final para a apalavra final que termina com ponto
palavras += 1

# Calculando o número de frases no texto
# Frases são separadas por (.),(!),(?)
frases = 0

for f in text:
    if f == ".":
        frases += 1
    elif f == "!":
        frases += 1
    elif f == "?":
        frases += 1

# Fórmula para calcular

# Número médio de letras por 100 palavras
L = (letras / palavras) * 100

# Número médio de frases por 100 palavras
S = (frases / palavras) * 100

index = 0.0588 * L - 0.296 * S - 15.8

# Arredondar par ao número inteiro mais próximo
grade = round(index)

# Imprimindo na tela de acordo com a grade

if grade < 1:
    print("Before Grade 1")
elif grade > 16:
    print("Grade 16+")
else:
    print(f"Grade {grade}")
