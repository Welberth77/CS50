#include <cs50.h>
#include <stdio.h>

void print_grid(int size);
void print_grid(int size);

int main(void)
{
  // Pegar o tamanho
  int get_size();

  // Mostrando a parede de blocos
  print_grid(n);
}


int get_size(void)
{
    int n;
    do
    {
        n = get_int("Size: ");
    }
    while(n < 1);
    return n;
}


void print_grid(int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            printf("#");
        }
        printf("\n")
    }
}
