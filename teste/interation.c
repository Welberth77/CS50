#include <cs50.H>
#include <stdio.h>

void draw(int n);

int main(void)
{
    // Pedindo altura
    int height = geti_int("height: ");
    draw(height);
}

void draw(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i + 1; j++)
        {
            printf("#");
        }
        printf("\n");
    }
}
