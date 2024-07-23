#include <cs50.h>
#include <stdio.h>
#include <string.h>


int main(void) {
    string s = get_string("Input: ");
    printf("Output: ");

    for (int i = 0; strlen(s); i++) {
        printf("%c", i);
    }
}
