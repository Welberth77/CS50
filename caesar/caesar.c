// Croptografia de césar
#import <cs50.h>
#import <ctype.h>
#import <stdio.h>
#import <stdlib.h>
#import <string.h>

bool apenas_digitos(string s);
string rotate(string s, int n);

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
            string result = rotate(plaintext, key);
            printf("%s\n", result);
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


string rotate(string s, int n)
{
    string texto_criptografado;

    int length = strlen(s);
    for (int i = 0; i < length; i++)
    {
    //Verificando se é um caractere alfabético
    if (isalpha(s[i]))
    {
        // Verificando se é maiúsculo
        if (isupper(s[i]))
        {
            //
            texto_criptografado[i] = ((s[i] - 'A') + n) % 26 + 'A';
        }
        // Verificando se é minusculo
        else if (islower(s[i]))
        {
            texto_criptografado[i] = ((s[i] - 'a') + n) % 26 + 'a';
        }
    }
    else
    {
        texto_criptografado[i] = s[i];
    }
    }
    return texto_criptografado;
}
