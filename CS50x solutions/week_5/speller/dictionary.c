// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <strings.h>
#include <stdlib.h>
#include <string.h>

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
int word_count = 0;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    unsigned int n = hash(word);

    node *cursor = table[n];

    while (cursor != NULL)
    {
        if (strcasecmp(word, cursor -> word) == 0)
        {
            return true;
        }

        cursor = cursor -> next;
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    unsigned int hash_value = 0;

    for (int i = 0, n = strlen(word); i < n; i++)
    {
         hash_value = (hash_value << 2) ^ word[i];
    }

    return hash_value % N;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    FILE *dict = fopen(dictionary, "r");
    char word[LENGTH + 1];

    // Check for memory issue with dict
    if(dict == NULL)
    {
        printf("Dictionary is null\n");
        unload();
        return false;
    }

    // Read string 1 word at a time
    while (fscanf(dict, "%s", word) != EOF)
    {
        node *n = malloc(sizeof(node));

        if (n == NULL)
        {
            return false;
        }

        strcpy(n -> word, word);

        word_count++;

        // Index word using hash function
        int dict_index = hash(word);

        // Insert into hash table if already empty
        if (table[dict_index] == NULL)
        {
            n -> next = NULL;
        }

        // Insert work as new node if not empyty
        else
        {
            n -> next = table[dict_index];
        }

        table[dict_index] = n;

    }

    // Close dictionary file
    fclose(dict);

    // Indicate success
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    return word_count;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    for (int i = 0; i < N; i++)
    {

        node *cursor = table[i];

        while (cursor)
        {
            node *temp = cursor;
            cursor = cursor->next;
            free(temp);
        }
    }
    return true;
}

