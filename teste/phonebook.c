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
    person people[3];

    // Atribuindo valores a estrutura
    people[0].name = "Carter";
    people[0].number = "1234";

    people[1].name = "david";
    people[1].number = "456";

    people[2].name = "John";
    people[2].number = "7898";

    // Pedindo valor ao usuário
    string name = get_string("Name: ");

    for (int i = 0; i < 3; i++)
    {
        if (strcmp(people[i].name, name) == 0)
        {
            printf("Found %s\n", people[i].number);
            return 0;
        }
    }
    printf("Not found\n");
    return 1;
}
