#include <cs50.h>
#include <stdio.h>

int get_size(void);

int main(void)
{
    // TODO: Prompt for start size
    int start_size = get_size();

    // TODO: Prompt for end size

    // TODO: Calculate number of years until we reach threshold

    // TODO: Print number of years
}

// Get start size
int get_size(void)
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
int get_size(void)
{
    int n;
    do
    {
        n = get_int("Start size: ");
    }
    while ( n < 9);
    return n;
}
