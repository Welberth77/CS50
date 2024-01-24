#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // TODO: Prompt for start size
    while (true)
    {
        int start_size = get_int("Start size: ");
        if (start_size >= 9)
        {
            break;
        }
    }
    // TODO: Prompt for end size

    // TODO: Calculate number of years until we reach threshold

    // TODO: Print number of years
}

