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
            int media = (image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue) / 3.0;
            int round(int media);

            // Alterando rgb para a escala cinza baseada na média
            image[i][j].rgbtRed = media;
            image[i][j].rgbtGreen = media;
            image[i][j].rgbtBlue = media;
        }
    }

    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}

// Blur image
// Desfocar imagem
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}
