// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#include "dictionary.h"

// Represents a node in a hash table
// No, tem valor e ponteiro que aponta para o próximo nó
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 26;

// Hash table
node *table[N];

// Contagem de palavras no dicionario
unsigned int word_count = 0;

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // Olha onde a palavra esta armazenada usando a função hash
    int index = hash(word);

    // Cria um cursor para percorrer a lista encadeada
    node *cursor = table[index];

    // Percorre a lista
    while (cursor != NULL)
    {
        // Compara a palavra da lista com a palavra dada
        if (strcasecmp(cursor->word, word) == 0)
        {
            // Se for igual, encontrou!
            return true;
        }

        // Se não for igual, move para o próximo nó
        cursor = cursor->next;
    }

    // Se chegou aqui, a palavra não foi encontrada
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // Variavel para armazenar o total da soma das letras
    unsigned int total = 0;
    // Percorre todas as letras da palavra
    for (int i = 0; word[i] != '\0'; i++)
    {
        // Soma os valores das letras
        // O 31 serve para dar peso às letras, fazendo a ordem delas influenciar o valor final do hash e espalhando melhor as palavras diferentes.
        total = (total * 31) + toupper(word[i]);
    }
    return total % N;
}

// Loads dictionary into memory, returning true if successful, else false
// Pegar o dicionário e colocar em uma tabela hash (chave e valor)
bool load(const char *dictionary)
{
    // Recebe o texto e retorna quuantos elementos tem comceçando essa letra
    // Lendo arquivo
    FILE *leitura = fopen(dictionary, "r");
    // Verificar se abriu o arquivo com sucesso
    if (leitura == NULL)
    {
        return false;
    }

    // Criar variável para armazenar as palavras lidas
    char word[LENGTH + 1];

    // Lendo as palavras do dicionário
    // EOF -> Significa que não tem mais palavras
    while (fscanf(leitura, "%s", word) != EOF)
    {
        // Alocando memória
        node *palavra = malloc(sizeof(node));
        if (palavra == NULL)
        {
            return false;
        }
        // Para cada palavra eu escrevo em um nó que terá valor e ponteiro para o próximo
        strcpy(palavra->word, word);

        // Adicionar palavras a tabela hash
        // Usar a função hash para saber onde colocar
        int index = hash(word);

        // Inserir o nó no começo da lista (modo mais simples)
        palavra->next = table[index];
        table[index] = palavra;

        // Contagem de palavras
        word_count++;
    }
    // Fechando o arquivo do dicionário
    fclose(leitura);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // Retorna o número de palavras
    return word_count;
}

// Unloads dictionary from memory, returning true if successful, else false
// liberar a memória
bool unload(void)
{
    // Percorre todos os índices da tabela hash
    for (int i = 0; i < N; i++)
    {
        // Cria um cursor para percorrer a lista ligada daquele índice
        node *cursor = table[i];

        // Enquanto houver nós na lista
        while (cursor != NULL)
        {
            // Guarda o nó atual temporariamente
            node *temp = cursor;

            // Avança o cursor para o próximo nó
            cursor = cursor->next;

            // Libera o nó atual
            free(temp);
        }
    }

    // Se chegar até aqui, toda a memória foi liberada
    return true;
}
