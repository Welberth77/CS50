// Nivel de leitura do texto
#import <cs50.h>
#import <ctype.h>
#import <math.h>
#import <stdio.h>
#import <string.h>


int contar_letras(string text);
int contar_palavras(string text);
int contar_frases(string text);


int main(void)
{
    // Entrada do texto
    string text = get_string("Text: ");

    // Contar o número de letras
    int total_letras = contar_letras(text);

    // Contar número de palavras
    int total_palavras = contar_palavras(text);

    // Contar número de frases
    int total_frases = contar_frases(text);

    // Calculando nível do texto
    // Fórmula index = 0.0588 * L - 0.296 * S - 15.8
    // onde (L) é o número médio de letras por 100 palavras no texto, e (S) é o número médio de frases por 100 palavras no texto.
    long L = (total_letras / total_palavras) * 100;
    long S = (total_frases / total_palavras) * 100;

    int grade = round(0.0588 * L * 0.296 * S - 15.8);

    // Imprimindo nota e nível do texto
    if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (grade > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", grade);
    }
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

    // Tamanho do texto
    int length = strlen(text);
    for (int i = 0; i < length; i++)
    {
        // Verificando se é espaço
        if (isblank(text[i]) != 0)
        {
            // Acrescentando +1 para as palavras
            palavras++;
        }
    }
    return palavras;
}


// Palavras que terminem com (., !, ?) serão consideradas fim de frases
int contar_frases(string text)
{
    // Variável para as frases
    int frases = 0;

    // Recebendo tamanho do texto
    int length = strlen(text);
    for (int i = 0; i <= length; i++)
    {
        // Verificanod se existe algum desses caracteres
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            // Acrescentando +1 em frase
            frases++;
        }
    }
    return frases;
}
