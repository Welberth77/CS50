// Palavras Cruzadas
#import <cs50.h>
#import <stdio.h>
#import <string.h>
#import <ctype.h>

// Pontuação das letras do alfabeto
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);

int main(void)
{
    // Solicitando palavras
    string word_player1 = get_string("Player 1: ");
    string word_player2 = get_string("Player 2: ");

    // Calcular resultado
    int score_player1 = compute_score(word_player1);
    int score_player2 = compute_score(word_player2);

    // Imprimir vencedor
    if (score_player1 > score_player2)
    {
        printf("Player 1 wins");
    }
    else if (score_player2 > score_player1)
    {
        printf("Player 2 wins");
    }
    else
    {
        printf("Tie!\n");
    }
}


int compute_score(string word) {
    // Variável para armazenar pontuação
    int score = 0;

    // Armazenando tamanho do texto
    int length = strlen(word);
    for (int i = 0; i < length; i++)
    {

        // Verificando se é letra maiuscula
        if (isupper(word[i]))
        {
            // diminuindo pela tabela ascii
            score = score + POINTS[word[i] - 'A'];
        }

        // Verificando se é letra minuscula
        else if (islower(word[i]))
        {
            // Diminuindo pela tabela ascii
            score = score + POINTS[word[i] - 'a'];
        }
    }
    return score;
}
