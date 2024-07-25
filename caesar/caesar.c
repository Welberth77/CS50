// Croptografia de césar
#import <cs50.h>
#import <ctype.h>
#import <stdio.h>
#import <stdlib.h>
#import <string.h>

bool apenas_digitos(string s);
char rotate(char c, int n);

// Recebendo a chave k direto no prompt de comando
int main(int argc, string argv[])
{
    // Validando informações
    if (argc != 2)
    {
        // Verificando se tem mais de dois argumentos no prompt
        printf("Usage: ./caesar Key\n");
        return 1;
    }
    else
    {
        // Verificando se tem apenas digitos no prompt
        bool resultado = apenas_digitos(argv[1]);
        if (resultado != true)
        {
            printf("Usage: ./caesar Key\n");
            return 1;
        }
        else
        {
            // Conventendo string para número inteiro
            int key = atoi(argv[1]);

            // Imprimindo chave
            printf("%i\n", key);

            // Solicitando texto simples
            string plaintext = get_string("Plaintext: ");

            // Imprimindo texto descriptografado
            printf("ciphertext: ");

            // Criptografando todo o texto letra por letra
            int length = strlen(plaintext);
            for (int i = 0; i < length; i++)
            {
                // Imprimindo cada uma das letras
                char result = rotate(plaintext[i], key);
                printf("%c", result);
            }
            
            // Quebrando a linha no final
            printf("\n");
            return 0;
        }
    }
}

bool apenas_digitos(string s)
{
    // Armazenando resultado
    bool resultado = false;

    int length = strlen(s);
    for (int i = 0; i < length; i++)
    {
        // Verificando se é um digito decimal
        if (isdigit(s[i]) != 0)
        {
            resultado = true;
        }
        else
        {
            resultado = false;
        }
    }
    return resultado;
}

char rotate(char c, int n)
{
    // Fórmula Ci = (pi + k) % 26
    char char_criptografado = c;

    // Verificando se é um caractere alfabético
    if (isalpha(c))
    {
        // Verificando se é maiúsculo
        if (isupper(c))
        {
            char_criptografado = ((c - 'A') + n) % 26 + 'A';
        }
        // Verificando se é minusculo
        else if (islower(c))
        {
            char_criptografado = ((c - 'a') + n) % 26 + 'a';
        }
    }
    else
    {
        // Se não for maiusculo nem minusculo
        return char_criptografado;
    }
    return char_criptografado;
}
