#include <cs50.h>
#include <stdio.h>

int start_size();

int main(void)
{
    // TODO: Prompt for start size
    start_size

    // TODO: Prompt for end size

    // TODO: Calculate number of years until we reach threshold

    // TODO: Print number of years
}

int start_size(void)
{
    int start_size;
    do
    {
        start_size = get_int("Start size: ");
    }
    while ( start_size < 9);
    return start_size;
}
