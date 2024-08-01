// criptografar mensagens usando uma cifra de substituição. Ou seja, o usuário passando uma chave de 26 caracteres
#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(int argc, string argv[])
{
    // Chave de 26 caracteres
    // Verificando se tem dois argumentos
    if (argc == 2)
    {
        // Verificando se o tamanho tem 26 caracteres
        if (strlen(argv[1]) == 26 )
        {
            printf("correto\n");
            return 0;
        }
        else
        {
            printf("Key must contain 26 characters.\n");
            return 2;
        }
    }
    else
    {
        printf("./Substitution key\n");
        return 1;
    }
}
