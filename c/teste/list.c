// Trabalhando com ponteiros
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int number;
    // ponteiro que aponta para o próximo nó
    struct node *next;
} node;

int main(int argc, char *argv[])
{
    // lista vazia da estrutura do node
    node *list = NULL;

    // Pegando argumentos da linha de comando
    for (int i = 1; i < argc; i++)
    {
        // convertendo para número inteiro
        int number = atoi(argv[i]);

        // Pedindo o tamanho do nó
        // Malloc reserva um pedaço da mémoria que caiba o tamanho desse número
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            // Memória livre até agora
            return 1;
        }
        // n (Aponta para a memória de tamanho suficiente para caber o nó)
        // n->numer (Vai pra esse pedaço da memória, está apontando pra ele)
        // number (Atualiza o número para a entrada do usuário)
        n->number = number;
        n->next = NULL;

        // Se a lista estiver vazia
        if (list == NULL)
        {
            list = n;
        }

        // Se os números pertencem ao inicio da lista
        // Se o número for menor que o resto da lista, adiciona ele no inicio
        else if (n->number < list->number)
        {
            n->next = list;
            list = n;
        }

        // Se os números pertencem ao meio ou final da lista
        else
        {
            // Iterando sobre toda a lista
            for (node *ptr = list; ptr != NULL; ptr = ptr->next)
            {
                // Se o número é o maior da lista
                if (ptr->next = NULL)
                {
                    // Adiona node
                    ptr->next = n;
                    break;
                }

                // Se está no meio da lista
                // Se o número atual é menor que o próximo número da lista
                if (n->number < ptr->next->number)
                {
                    n->next  = ptr->next;
                    ptr->next = n;
                    break;
                }
            }
        }
    }

}
