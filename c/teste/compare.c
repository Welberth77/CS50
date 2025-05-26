#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int a = get_int("Valor de A: ");
    int b = get_int("Valor de B: ");
    if (a < b)
    {
        printf("A é menor que B\n");
    }
    else if (a > b)
    {
        printf("A é maior que B\n");
    }
    else
    {
        printf("A e B são iguais\n");
    }
}
