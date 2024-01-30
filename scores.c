#include <cs50.h>
#include <stdio.h>

const int N = 3;
float media(int array[]);

int main(void)
{
    int scores[3];
    for (int i = 0; i < 3; i++)
    {
        scores[i] = get_int("Score: ");
    }

    printf("Média: %f\n", (scores[0] + scores[1] + scores[2]) / (float) 3);
}

float media(int array[])
{
    int sum = 0;
    for (int i = 0; i < N; i++)
    {
        
    }
}
