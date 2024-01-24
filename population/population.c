#include <cs50.h>
#include <stdio.h>

int get_size_start(void);
int get_size_end(int i);
int calculator_year(int start, int end);

int main(void)
{
    // TODO: Prompt for start size
    int start_size = get_size_start();

    // TODO: Prompt for end size
    int end_size = get_size_end(start_size);

    // TODO: Calculate number of years until we reach threshold

    // TODO: Print number of years
}

// Get start size
int get_size_start(void)
{
    int n;
    do
    {
        n = get_int("Start size: ");
    }
    while ( n < 9);
    return n;
}


// Get end size
int get_size_end(int i)
{
    int n;
    do
    {
        n = get_int("End size: ");
    }
    while (n < i);
    return n;
}

// Calculator years
int calculator_year(int start, int end)
{
    for (start; start >= end; start = )
}
