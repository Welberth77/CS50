#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(int argc, char *argv[])
{
    // Accept a single command-line argument
    if (argc != 2)
    {
        printf("Usage: ./recover FILE\n");
        return 1;
    }

    // Open the memory card
    FILE *card = fopen(argv[1], "r");

    // Create a buffer for a block of data
    uint8_t buffer[512];

    // Variáveis para criar arquivos JPEG
    FILE *img = NULL;
    int img_count = 0;

    // While there's still data left to read from the memory card
    while (fread(buffer, 1, 512, card) == 512)
    {
        // Create JPEGs from the data
        // Verificar se é o início de um JPEG
        if (buffer[0] == 0xff &&
            buffer[1] == 0xd8 &&
            buffer[2] == 0xff &&
            (buffer[3] & 0xf0) == 0xe0)
        {
            // Se já existe um JPEG aberto, fechar
            if (img != NULL)
            {
                fclose(img);
            }

            // Nome do novo arquivo (000.jpg, 001.jpg, ...)
            char filename[8];
            sprintf(filename, "%03i.jpg", img_count);

            img = fopen(filename, "w");
            if (img == NULL)
            {
                fclose(card);
                return 1;
            }

            img_count++;
        }

        // Se já temos um JPEG aberto, escrever nele
        if (img != NULL)
        {
            fwrite(buffer, 1, 512, img);
        }
    }

    // Fechar arquivos
    if (img != NULL)
    {
        fclose(img);
    }
    fclose(card);
}
