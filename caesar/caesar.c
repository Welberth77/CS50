// Croptografia de césar
#import <cs50.h>
#import <ctype.h>
#import <stdio.h>
#import <string.h>

bool apenas_digitos(string s);

int main(int argc, string argv[])
{
    // Receber a chave k direto no prompt de comando
    if (argc != 2)
    {
        printf("Usage: ./caesar Key\n");
    }
    else
    {
        bool resultado = apenas_digitos(argv[1]);
        if (resultado != true)
        {
            printf("Usage: ./caesar Key\n");
        }
        else
        {
            printf("%s\n", argv[1]);
        }
    }

    // Texto simples

    // Criptografando o texto
    // Mudar apenas textos alfabéticos
    // Maiúsculos e minusculos continuam

    // Imprimindo texto descriptografado
}

bool apenas_digitos(string s)
{
    bool resultado = false;

    int length = strlen(s);
    for (int i = 0; i < length; i++)
    {
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
