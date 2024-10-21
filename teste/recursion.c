// Aplicando recursão no código
#include <cs50.h>
#include <stdio.h>

void draw(int n);

int main(void)
{
    // Pedindo altura
    int height = get_int("height: ");
    draw(height);
}

void draw(int n)
{
    // Printa a pirâmide com altura n - 1
    draw(n - 1);

    // Printa mais uma linha
    for (int i = 0; i < n; i++)
    {
        printf("#");
    }
    printf("\n");
}
