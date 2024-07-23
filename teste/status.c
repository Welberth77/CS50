#include <cs50.h>
#include <stdio.h>

int main(int argc, string argv[]) {
    if (argc != 2) {
        printf("Argumento da linha de comando ausente\n");
        return 1;
    }
    printf("Hello, %s", argv[1]);
    return 0;
}
