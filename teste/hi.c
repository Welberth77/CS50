#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Definindo tamanho do array
    string words[2];

    // Colocando valores no array
    words[0] = "HI!";
    words[1] = "BYE!";

    // Imprimindo valores do array
    printf("%s\n", words[0]);
    printf("%s\n", words[1]);

    // Imprimindo valores do array de outra forma (O que acontece debaixo de capô)
    printf("%c%c%c\n", words[0][0], words[0][1], words[0][2]);
    printf("%c%c%c%c\n", words[1][0], words[1][1], words[1][2], words[1][3]);
}
