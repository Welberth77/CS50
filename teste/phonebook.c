// Lista telegônica
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Estrutura de dados
typedef struct
{
    string name;
    string number;
}
person;

int main(void)
{
    // Criando uma matriz (array) de 3 pessoas
    person peopole[3];

    // Atribuindo valores a estrutura
    person[0].name = "Carter";
    person[0].numer = "1234";

    person[1].name = "David";
    person[1].number = "456";

    person[2].name = "John";
    person[2].number = "7898";

    // Pedindo valor ao usuário
    string name = get_string("Name: ");

    for (int i = 0; i < 3; i++)
    {
        if (strcmp(person[i].name, name) == 0)
        {
            printf("Found\n");
            return 0;
        }
    }
    printf("Not found\n");
    return 1;
}
