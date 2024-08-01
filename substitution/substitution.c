// criptografar mensagens usando uma cifra de substituição. Ou seja, o usuário passando uma chave de 26 caracteres
#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

// Obter chave
int main(int argc, string argv[])
{
    // verificação da chave
    // Chave de 26 caracteres
    // Verificando se tem dois argumentos
    if (argc == 2)
    {
        // Verificando se o tamanho tem 26 caracteres
        if (strlen(argv[1]) == 26 )
        {
            // Verificando se todos os caracteres são alfabeticos
            int length = strlen(argv[1]);
            for (int i = 0; i < length; i++)
            {
                if (isalpha(argv[1][i]) == 0)
                {
                    printf("Key must only contais alphabetic characters.\n");
                    return 1;
                }
            }
            // Saída correta
            printf("Correto\n");
            return 0;
        }
        else
        {
            printf("Key must contain 26 characters.\n");
            return 1;
        }
    }
    else
    {
        printf("Usage: ./Substitution key\n");
        return 1;
    }

    // Plaintext (Texto original)

    // Ciphertext (Texto criptografado)
    // Maiusculas e minusculas devem ser respeitados
}
