#include <stdio.h>

int main(void)
{
    // Obtendo número inteiro com scanf
    int n;
    printf("n: ");
    // Vai para o endereço de n e altera o valor
    scanf("%i", &n);
    printf("n: %i\n", n);


    // Obtendo string com o scanf
    char s[4];
    printf("s: ");
    scanf("%s", s);
    printf("s: %s\n", s);
}
