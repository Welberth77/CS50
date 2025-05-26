#include <cs50.h>
#include <stdio.h>

int get_size_start(void);
int get_size_end(int i);
int calculator_year(int start, int end);

int main(void)
{
    // Pedindo tamanho inicial
    int start_size = get_size_start();

    // Pedindo tamanho final
    int end_size = get_size_end(start_size);

    // TODO: Calculando número de anos que until we reach threshold
    int year = calculator_year(start_size, end_size);

    // Escrevendo o número de anos
    printf("Years: %i\n", year);
}

// Validando tamanho inicial
int get_size_start(void)
{
    int n;
    do
    {
        n = get_int("Start size: ");
    }
    while ( n < 9);
    return n;
}


// Validando tamanho final
int get_size_end(int i)
{
    int n;
    do
    {
        n = get_int("End size: ");
    }
    while (n < i);
    return n;
}

// Calculando anos
int calculator_year(int start, int end)
{
    int year = 0;
    int n = start;
    do
    {
        n = n + (n / 3) - (n / 4);
        year++;
    }
    while(n < end);
    return year;
}
