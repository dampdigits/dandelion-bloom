// Implements a dictionary's functionality

#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

int dict_size = 0;
// TODO: Choose number of buckets in hash table
const unsigned int N = (LENGTH + 1) * 'z';

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // find hash number
    unsigned int index = hash(word);
    node *cursor = table[index];

    // traverse through hash-table
    while (cursor != NULL)
    {
        // check if word has been found
        if (strcasecmp(cursor->word, word) == 0)
        {
            return true;
        }
        cursor = cursor->next;
    }

    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    int word_length = strlen(word);
    unsigned int hash_value = 0;

    // calculate hash value of a word
    for (int i = 0; i < word_length; i++)
    {
        hash_value += tolower(word[i]);
    }

    return (hash_value % N);
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // Open dictionary
    FILE *dict = fopen(dictionary, "r");
    // check if unable to open dictionary
    if (dict == NULL)
    {
        printf("\nOut of memory :(\n");
        return false;
    }

    int ret;
    char buffer[LENGTH + 1];

    // add each word from dictionary to hash table one at a time
    while ((ret = fscanf(dict, "%s", buffer)) != EOF)
    {
        buffer[LENGTH] = '\0';

        // create a new node
        node *new = malloc(sizeof(node));
        // check for node creation failure
        if (new == NULL)
        {
            printf("\nOut of memory :(\n");
            return false;
        }
        // copy word from dictionary to node
        strcpy(new->word, buffer);

        // find hash number
        unsigned int index = hash(new->word);

        // insert node in linked list of hash table
        new->next = table[index];
        table[index] = new;

        // count words in dictionary
        ++dict_size;
    }
    // close dictionary
    fclose(dict);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return dict_size;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    for (int i = 0; i < N; i++)
    {
        node *cursor = table[i];
        while (cursor != NULL)
        {
            node *tmp = cursor;
            cursor = cursor->next;
            free(tmp);
        }
    }
    return true;
}
