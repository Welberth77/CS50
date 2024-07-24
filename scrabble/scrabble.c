// Palavras Cruzadas
#import <cs50.h>
#import <stdio.h>
#import <string.h>
#import <ctype.h>

// Pontuação das letras do alfabeto
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);

int main(void) {
    // Solicitando palavras
    string word_player1 = get_string("Player 1: ");
    string word_player2 = get_string("Player 2: ");

    // Calcular resultado
    int score_player1 = compute_score(word_player1);
    int score_player2 = compute_score(word_player2);

    // Imprimir resultado
}

int compute_score(string word) {
    int score = 0;

    int length = strlen(word);
    for (int i = 0; i < length; i++) {
        

    }
}
