def get_int(prompt):
    # Fica pedindo um valor até ser realmente um inteiro
    while True:
        try:
            return int(input(prompt))
        # Se der erro de valor
        except ValueError:
            print("Not an integer") # Não é um número inteiro


def main():
    x = get_int("X: ")
    y = get_int("Y: ")

    print(x + y)

main()
