#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max voters and candidates
#define MAX_VOTERS 100
#define MAX_CANDIDATES 9

// preferences[i][j] is jth preference for voter i
int preferences[MAX_VOTERS][MAX_CANDIDATES];

// Candidates have name, vote count, eliminated status
typedef struct
{
    string name;
    int votes;
    bool eliminated;
} candidate;

// Array of candidates
candidate candidates[MAX_CANDIDATES];

// Numbers of voters and candidates
int voter_count;
int candidate_count;

// Function prototypes
bool vote(int voter, int rank, string name);
void tabulate(void);
bool print_winner(void);
int find_min(void);
bool is_tie(int min);
void eliminate(int min);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: runoff [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX_CANDIDATES)
    {
        printf("Maximum number of candidates is %i\n", MAX_CANDIDATES);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
        candidates[i].eliminated = false;
    }

    voter_count = get_int("Number of voters: ");
    if (voter_count > MAX_VOTERS)
    {
        printf("Maximum number of voters is %i\n", MAX_VOTERS);
        return 3;
    }

    // Keep querying for votes
    for (int i = 0; i < voter_count; i++)
    {

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            // Record vote, unless it's invalid
            if (!vote(i, j, name))
            {
                printf("Invalid vote.\n");
                return 4;
            }
        }

        printf("\n");
    }

    // Keep holding runoffs until winner exists
    while (true)
    {
        // Calculate votes given remaining candidates
        tabulate();

        // Check if election has been won
        bool won = print_winner();
        if (won)
        {
            break;
        }

        // Eliminate last-place candidates
        int min = find_min();
        bool tie = is_tie(min);

        // If tie, everyone wins
        if (tie)
        {
            for (int i = 0; i < candidate_count; i++)
            {
                if (!candidates[i].eliminated)
                {
                    printf("%s\n", candidates[i].name);
                }
            }
            break;
        }

        // Eliminate anyone with minimum number of votes
        eliminate(min);

        // Reset vote counts back to zero
        for (int i = 0; i < candidate_count; i++)
        {
            candidates[i].votes = 0;
        }
    }
    return 0;
}

// Calcular as preferencias dos votos
// Record preference if vote is valid
bool vote(int voter, int rank, string name)
{
    for (int i = 0; i < candidate_count; i++)
    {
        // Verifica se o candidato existe no array
        if (strcmp(name, candidates[i].name) == 0)
        {
            // Armazena a ordem de preferência
            // Voter é o eleitor e o rank a ordem de preferencia
            preferences[voter][rank] = i;
            return true;
        }
    }
    return false;
}

// Atualizar a quantidade de votos para cada candidato
// Tabulate votes for non-eliminated candidates
void tabulate(void)
{
    // Percorrer os eleitores
    for (int i = 0; i < voter_count; i++)
    {
        // Verificar preferências
        for (int j = 0; j < candidate_count; j++)
        {
            int candidate_index = preferences[i][j];
            // Verificar se o candidato não foi eliminado
            if (!candidates[candidate_index].eliminated)
            {
                // incrementar votos
                candidates[candidate_index].votes++;
                break;
            }
        }
    }
    return;
}

// Imprima o vencedor da eleição, se houver um
// Print the winner of the election, if there is one
bool print_winner(void)
{
    // Calculando maioria dos votos
    int maioria_votos = (voter_count / 2);

    // Percorrendo candidatos e vendo quem tem mais que a a mioria dos votos
    for (int i = 0; i < candidate_count; i++)
    {
        // Comparando quantidade de votos do candidato atual com a maioriua dos votos
        if (candidates[i].votes > maioria_votos)
        {
            // Printando o ganhador e retornando true
            printf("%s\n", candidates[i].name);
            return true;
        }
    }
    // TODO
    return false;
}

// Devolver o número mínimo de votos que qualquer candidato restante tem
// Calcular quem tem menos votos
// Return the minimum number of votes any remaining candidate has
int find_min(void)
{
    // Ddeclarando o menos votos com o máximo de votos
    int menos_votos = 100;

    // Loop por cada candidato
    for (int i = 0; i < candidate_count; i++)
    {
        // Verificar se o candidato não foi eliminado
        if (!candidates[i].eliminated)
        {
            // comparação dos votos
            if (candidates[i].votes < menos_votos)
            {
                menos_votos = candidates[i].votes;
            }
        }
    }
    return menos_votos;
}

// Retorne verdadeiro se a eleição estiver ligada entre todos os candidatos, falsa caso contrário
// Return true if the election is tied between all candidates, false otherwise
bool is_tie(int min)
{
    for (int i = 0; i < candidate_count; i++)
    {
        // Verificar se o candidato não foi eliminado
        if (!candidates[i].eliminated)
        {
            if (candidates[i].votes != min)
            {
                return false;
            }
        }
    }
    // TODO
    return true;
}

// Elimine o candidato (ou candidatos) em último lugar
// Eliminate the candidate (or candidates) in last place
void eliminate(int min)
{
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes <= min)
        {
            candidates[i].eliminated = true;
        }
    }
    // TODO
    return;
}
