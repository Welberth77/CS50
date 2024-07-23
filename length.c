#include <cs50.h>
#include <stdio.h>


int main(void) {
    // Solicitando nome ao usuário
    string name = get_string("Nome: ");

    // Definindo variável inicial
    int n = 0;
    // Enquanto o caractere não chegar ao \0 continua a contagem
    // Lembrando que toda string termina com \0
    while (name[n] != '\0') {
        // Atribuindo valor ao n
        n++;
    }

    // Printando o número de caracteres
    printf("%i\n", n);
}
