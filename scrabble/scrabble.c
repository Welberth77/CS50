// Palavras Cruzadas
#import <cs50.h>
#import <stdio.h>

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
    return 0;
}
