#include <cs50.h>
#include <stdio.h>
#include <string.h>


int main(void) {
    string s = get_string("Antes: ");
    printf("Depois: ");

    int length = strlen(s);
    for (int i = 0; i < length; i++) {
        if (s[i] >= 'a' && s[i] <= 'z') {
            printf("%c", s[i] - 32);
        }
        else {
            printf("%c", s[i]);
        }
    }
    printf("\n");
}
