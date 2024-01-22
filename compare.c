#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int a = 1;
    int b = 2;
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
