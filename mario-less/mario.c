#include <cs50.h>
#include <stdio.h>

int get_height(void);
void print_pyramid(int h);

int main(void)
{
    // Pedindo altura, entre 4 e 8 e maior que 0
    int height = get_height();

    // Imprimindo pirâmide
    print_pyramid(height);
}


// Obtendo e válidando altura
int get_height(void)
{
    int n;
    do
    {
        n = get_int("Height: ");
    }
    while (n < 1 || n > 8);
    return n;
}

void print_pyramid(int h)
{
    for (int i = 0; i < h; i++)
    {
        printf("#\n");
        for (int j = 0; j < i; j++)
        {
            printf("o");
        }
    }
    printf("\n");
}
