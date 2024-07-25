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

            //Imprimindo chave
            printf("%i\n", key);

            // Solicitando texto simples
            string plaintext = get_string("Plaintext: ");

            // Criptografando o texto
            char result = rotate(plaintext[0], key);
            printf("%c\n", result);
            return 0;
        }
    }
    // Tabela ascii
    // Maiusculos de 65 até 90
    // Minusculos de 97 até 122
    // Fórmula Ci = (pi + k) % 26

    // Imprimindo texto descriptografado
}

bool apenas_digitos(string s)
{
    // Armazenando resultado
    bool resultado = false;

    int length = strlen(s);
    for (int i = 0; i < length; i++)
    {
        // Verificando se é um digito decial
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

    char resultado = c;
    // Mudando letras
    if (isalpha(c))
    {
        if (isupper(c))
        {
            resultado = ((c - 'A') + n) % 26 + 'A';
        }
        else if (islower(c))
        {
            resultado = ((c - 'a') + n) % 26 + 'a';
        }
    }
    else
    {
        return resultado;
    }
    return resultado;
}
