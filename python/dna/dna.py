import csv
import sys


def main():

    # TODO: Check for command-line usage
    if len(sys.argv) != 3:
        print("forma inválida")
        sys.exit(1)
    else:
        # TODO: Read database file into a variable
        with open(sys.argv[1], 'r', newline='') as arquivo_csv_small:
            leitor = csv.DictReader(arquivo_csv_small)
            # Salva todas as pessoas como dicionários
            dados = list(leitor)
            colunas = leitor.fieldnames[1:]  # ignora a primeira coluna ("name")

        # TODO: Read DNA sequence file into a variable
        with open(sys.argv[2], 'r', newline='') as sequencia_dna:
            sequencia = sequencia_dna.read()

        # TODO: Find longest match of each STR in DNA sequence
        valores = {}
        for j in colunas:
            repeticoes = longest_match(sequencia, j)
            valores[j] = repeticoes

        # TODO: Check database for matching profiles
        # Perfil que corresponde a esse dna
        for pessoa in dados:
            # Compara todas as chaves e repeticoes de valores, o (all) precisa desse iteravel dentro
            if all(int(pessoa[chave]) == valores[chave] for chave in colunas):
                # Se for tudo igual printa o nome da pessoa que o dna é igual
                print(f"{pessoa['name']}")
                break
        else:
            # Se for algo diferente, não é igual
            print("No match")

        return


def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):

        # Initialize count of consecutive runs
        count = 0

        # Check for a subsequence match in a "substring" (a subset of characters) within sequence
        # If a match, move substring to next potential match in sequence
        # Continue moving substring and checking for matches until out of consecutive matches
        while True:

            # Adjust substring start and end
            start = i + count * subsequence_length
            end = start + subsequence_length

            # If there is a match in the substring
            if sequence[start:end] == subsequence:
                count += 1

            # If there is no match in the substring
            else:
                break

        # Update most consecutive matches found
        longest_run = max(longest_run, count)

    # After checking for runs at each character in seqeuence, return longest run found
    return longest_run


main()
