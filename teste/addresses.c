#include <cs50.h>
#include <stdio.h>

int main (void)
{
    int n = 50;
    // declara a variável que armazenará um endereço
    int *p = &n;
    // Mostra o endereço que está a variável
    printf("%p\n", p);
}
