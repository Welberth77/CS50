#include <cs50.h>
#include <stdio.h>
#include <string.h>


int string_length(string s);


int main(void) {
    // Solicitando nome ao usuário
    string name = get_string("Nome: ");
    // Chamando função manual
    int length = string_length(name);
    printf("%i\n", length);

    // Chamando função strlen disponível no string.h
    int length_2 = strlen(name);
    printf("%i\n", length);

}

int string_length(string s) {
    // Definindo variável inicial
    int n = 0;
    // Enquanto o caractere não chegar ao \0 continua a contagem
    // Lembrando que toda string termina com \0
    while (s[n] != '\0') {
        // Atribuindo valor ao n
        n++;
    }

    // retornando o número de caracteres
    return n;

}
