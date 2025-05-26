from cs50 import get_int

while True:
    # Pedindo valor ao usuário
    height = get_int("Height: ")
    # Verificando condição
    while height < 1 or height > 8:
        print("Digite um número entre 1 e 8")
        height = get_int("Height: ")
    # Condição verdadeira, quebra o loop
    if height > 0 or height < 9:
        break

for linhas in range(height):
    # Fórmula para os espaços
    # ex: altura = 5, linha - 0, - 1 = 4 espaços
    for espacos in range((height - linhas - 1)):
        print(" ", end="")
    for colunas in range(linhas + 1):
        print("#", end="")

    # Fazer loop da escada para direita
    # espaço do centro
    print("  ", end="")
    for colunas in range(linhas + 1):
        print("#", end="")
    print()
