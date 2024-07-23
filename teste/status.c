// Numerando erros encontrados, quando retornamos 0 quer dizer que tudo deu certo
// Quando retornamos valores acima de zero são os tipos de erros encontrados no código, deu algo errado
#include <cs50.h>
#include <stdio.h>

int main(int argc, string argv[]) {
    if (argc != 2) {
        printf("Argumento da linha de comando ausente\n");
        return 1;
    }
    printf("Hello, %s\n", argv[1]);
    return 0;
}
