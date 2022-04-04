// Implements a dictionary's functionality

#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include "dictionary.h" // Dict header

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = 1000; // Assume this number work,  I have no ideas :D.

// Hash table
node *table[N];

// Define number of word
unsigned int number_word = 0;
unsigned int hash_index;

// Hashes word to a number
unsigned int hash(const char *word)
{
    unsigned int value = 0;
    unsigned int key_len = strlen(word);
    for (int i = 0; i < key_len; i++)
    {
        value = value + 37 * tolower(word[i]);
    }
    value = value % N;
    return value;
}
/*/
source: https://collinsnote.com/cs50-speller-solution-2020-my-explanation/?unapproved=765&moderation-hash=606becda75a023d48ecc8bbcd7552c3f#comment-765
/*/


// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO

    // Open dictionary file
    FILE *dict = fopen(dictionary, "r");
    if (dict == NULL)
    {
        printf("Could not open the file\n");
        return false;
    }
    // Read strings from file one at a time
    char newword[LENGTH + 1];
    int a;
    while ((fscanf(dict, "%s", newword) != EOF))
    {
        // Create a new node for each word
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            free(n);
            return false;
        }

        strcpy(n->word, newword); // add new string into a node
        n->next = NULL; //set new node
        hash_index = hash(newword); // Hash newword

        if (table[hash_index] == NULL)
        {
            table[hash_index] = n; // Create the new node to this address
        }
        else
        {
            n->next = table[hash_index]; // Assign the new node to the table first to keep track with all other nodes
            table[hash_index] = n; // Point to new node
        }
        number_word++; //  Keep track the number of word that has been load
    }
    fclose(dict);
    return true;
}





// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return number_word;
}


// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    hash_index = hash(word);
    node *cursor = table[hash_index];
    while (cursor != NULL)
    {
        if (strcasecmp(cursor->word, word) == 0)
        {
            return true;
        }
        cursor = cursor->next;
    }
    return false;
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
            node *cache = cursor;
            cursor = cursor->next;
            free(cache);
        }
    }
    return true;
}