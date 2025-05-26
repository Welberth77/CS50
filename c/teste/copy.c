#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    // Pegando a váriavel em forma de string
    char *s = get_string("s: ");

    // Se a string estiver vazia
    if (s == NULL)
    {
        return 1;
    }

    // copia toda a string e \0
    // Malloc define quanto de espaço precisaremos para armazenar a variável t
    char *t = malloc(strlen(s) + 1);

    // Se não houver memória suficiente
    if (t == NULL)
    {
        return 1;
    }

    // Loop para copiar todos os caracteres, incluindo o \0
    // fique atento com as vígulas (,) e ponto e vírgula (;)
    for (int i = 0, n = strlen(s); i <= n; i++)
    {
        t[i] = s[i];
    }

    // Faz a cópia da string completa
    strcpy(t, s);

    if (strlen(t) > 0)
    {
        // Deixa o primeiro caractere maiúsculo
        t[0] = toupper(t[0]);
    }

    printf("%s\n", s);
    printf("%s\n", t);

    // Devolve a memória ao computador
    free(t);
    return 0;
}
