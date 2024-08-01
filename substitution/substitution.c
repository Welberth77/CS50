// criptografar mensagens usando uma cifra de substituição. Ou seja, o usuário passando uma chave de 26 caracteres
#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(int argc, string argv[])
{
    // Chave de 26 caracteres
    if (strlen(argv) != 26)
    {
        printf("A chave precisa ter 26 caracteres\n");
        return 1;
    }
    else
    {
        printf("Correto\n");
        return 0;
    }
}
