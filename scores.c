#include <cs50.h>
#include <stdio.h>

// Declarando um váriavel constante
const int N = 3;

float media(int array[]);

int main(void)
{
    int scores[N];
    for (int i = 0; i < 3; i++)
    {
        scores[i] = get_int("Score: ");
    }

    printf("Média: %f\n", media(scores));
}

// Calculando a média
float media(int array[])
{
    int sum = 0;
    for (int i = 0; i < N; i++)
    {
        sum = sum + array[i];
    }
    return sum / (float) N;
}
