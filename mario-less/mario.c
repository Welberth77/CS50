#include <cs50.h>
#include <stdio.h>

int get_height(void);

int main(void)
{
    // Pedindo altura, entre 4 e 8 e maior que 0
    int height = get_height();

    // Imprimindo pirâmide
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
