#include <cs50.h>
#include <stdio.h>

// Declarando um váriavel constante
const int N = 3;

// Prototipo da função média que usaremos depois
float media(int array[]);

int main(void)
{
    // Criando e definindo tamanho do array
    int scores[N];
    for (int i = 0; i < 3; i++)
    {
        // Solicitando notas para cada lugar do array
        scores[i] = get_int("Score: ");
    }

    // Printando a média e chamando a função média
    printf("Média: %f\n", media(scores));
}

// Calculando a média
float media(int array[])
{
    // Variável para guardar a soma
    int sum = 0;
    for (int i = 0; i < N; i++)
    {
        // Somandos cada um dos valores do array
        sum = sum + array[i];
    }
    // Retornando um valor float
    return sum / (float) N;
}
