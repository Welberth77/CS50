#include "helpers.h"
#include <math.h>

// Convert image to grayscale
// Cinza (Preto e branco)
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    // Definir a tonalidade do cinza baseado na média
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Calculando a média do rgb original
            // Tranformando a média no número inteiro mais próximo
            int media = round((image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue) / 3.0);

            // Alterando rgb para a escala cinza baseada na média
            image[i][j].rgbtRed = media;
            image[i][j].rgbtGreen = media;
            image[i][j].rgbtBlue = media;
        }
    }

    return;
}

// Convert image to sepia
// Filtro meio amarelado (marrom avermelhado)
// Existe um algoritmo que calcula quanto cada cor deve ter para ficar nesse filtro
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Aplicando filtro do sépia
            // Arredondando para o inteiro mais próximo
            int sepiaRed = round(.393 * image[i][j].rgbtRed + .769 * image[i][j].rgbtGreen + .189 * image[i][j].rgbtBlue);
            int sepiaGreen = round(.349 * image[i][j].rgbtRed + .686 * image[i][j].rgbtGreen + .168 * image[i][j].rgbtBlue);
            int sepiaBlue = round(.272 * image[i][j].rgbtRed + .534 * image[i][j].rgbtGreen + .131 * image[i][j].rgbtBlue);

            // Verificações se o valor passa de 255
            if (sepiaRed > 255)
            {
                sepiaRed = 255;
            }
            if (sepiaGreen > 255)
            {
                sepiaGreen = 255;
            }
            if (sepiaBlue > 255)
            {
                sepiaBlue = 255;
            }

            // Aplicando filtro aos pixels originais
            image[i][j].rgbtRed = sepiaRed;
            image[i][j].rgbtGreen = sepiaGreen;
            image[i][j].rgbtBlue = sepiaBlue;
        }
    }
    return;
}

// Reflect image horizontally
// Imagem espelhada, inverter horizontalmente
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Os valores das linhas devem ser totalmente invertidos
        }
    }
    return;
}

// Blur image
// Desfocar imagem
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}
