// Nivel de leitura do texto
#import <cs50.h>
#import <ctype.h>
#import <math.h>
#import <stdio.h>
#import <string.h>


int contar_letras(string text);
int contar_palavras(string text);


int main(void)
{
    // Entrada do texto
    string text = get_string("Text: ");

    // Contar o número de letras, palavras e frases no texto
    int total_letras = contar_letras(text);
    printf("%i\n", total_letras);

    int total_palavras = contar_palavras(text);
    printf("%i\n", total_palavras);



    // Calculando nível do texto
    // Fórmula index = 0.0588 * L - 0.296 * S - 15.8
    // onde (L) é o número médio de letras por 100 palavras no texto, e (S) é o número médio de frases por 100 palavras no texto.

    // Imprimindo nota e nível do texto
}

int contar_letras(string text)
{
    // Variavel para armazenar quantidade de letras
    int letras = 0;

    int length = strlen(text);
    // Loop que passa letra por letra
    for (int i = 0; i < length; i++)
    {
        // Verificando se o caractere é um texto
        if (isalpha(text[i]) != 0)
        {
            // Acrescentando 1 ao número de letras
            letras++;
        }
    }
    return letras;
}


// Contamos os espaços que existem, assim descobrimos as palavras separadas por espaços
int contar_palavras(string text)
{
    // Váriavel para armazenar as palavras
    int palavras = 1;

    int length = strlen(text);
    for (int i = 0; i < length; i++)
    {
        if (isalpha(text[i]) == 0)
        {
            palavras++;
        }
    }
    return palavras;
}


// Palavras que terminem com (., !, ?) serão consideradas fim de frases
int contar_frases(string text)
{
    int frases = 0;

    int length = strlen(text);
    for (int i = 0; i < length; i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            frases++;
        }
    }
    return frases;
}
