// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <ctype.h>
#include <strings.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 26;

// Hash table
node *table[N];

int d_size = 0;

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    int hashv = hash(word);
    node *n = table[hashv];
    while (n != NULL)
    {
        if (strcasecmp(word, n->word) == 0)
        {
            return true;
        }
        n = n->next;
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    char s = toupper(word[0]);
    return s - 'A';
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    FILE *dict = fopen(dictionary, "r");

    if (dictionary == NULL)
    {
        printf("can't open file");
        return false;
    }

    char nword[LENGTH + 1];

    while (fscanf(dict, "%s", nword) != EOF)
    {
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            return false;
        }

        strcpy(n->word, nword);

        int hashv = hash(nword);

        n->next = table[hashv];

        table[hashv] = n;
        d_size++;
    }

    fclose(dict);

    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return d_size;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    for (int i = 0; i < N; i++)
    {
        node *n = table[i];

        while (n != NULL)
        {
            node *an = n;
            // Point cursor to next element
            n = n->next;
            free(an);
        }
        if (n == NULL && i == N - 1)
        {
            return true;
        }
    }
    return false;
}
