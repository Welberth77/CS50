// Métodos de pesquisa
#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    // Pesquisa com números inteiros
    // int numbers[] = {20, 500, 10, 5, 100, 1, 50};

    // int n = get_int("Number: ");

    // for (int i = 0; i < 7; i++)
    // {
    //     if (numbers[i] == n)
    //     {
    //         printf("Found (Encontrado)\n");
    //         // Vai encerrar o código nestta linha e retornar 0
    //         return 0;
    //     }
    // }
    // printf("Not found (Não encontrado)\n");
    // // Retorna 1 e encerra o código
    // return 1;


    // Pesquisa com string
    // strcmp -> Para comparar duas strings
    string strings[] = {"banana", "maçã", "pera", "batata", "limão", "manga"};

    string s = get_string("String: ");

    for (int i = 0; i < 6; i++)
    {
        if (strcmp(strings[i], s))
        {
            printf("Found (Encontrado)\n");
            // Vai encerrar o código nestta linha e retornar 0
            return 0;
        }
    }
    printf("Not found (Não encontrado)\n");
    // Retorna 1 e encerra o código
    return 1;
}
