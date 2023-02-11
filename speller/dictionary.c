#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>
#include <strings.h>

#include "dictionary.h"

typedef struct node
{
    char word[LENGTH - 1];
    struct node *next;
} node;

int word_count;

// TODO: Choose number of buckets in hash table
const unsigned int N = 26;

// Hash table
node *table[N];

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // Open dictionnary file
    FILE *input_file = fopen(dictionary, "r");

    // Checks if the file has been opened
    if (input_file == NULL)
    {
        printf("Cannot open file\n");
        return false;
    }

    char temp_word[46];


    while (fscanf(input_file, "%s", temp_word) != EOF)
    {
        node *temp = malloc(sizeof(node));
        if (temp == 0)
        {
            printf("Could not allocate memory");
            return false;
        }

        int hashed = hash(temp_word);

        strcpy(temp->word, temp_word);
        temp->next = table[hashed];

        table[hashed] = temp;
        word_count++;
    }
    if (feof(input_file))
    {
        fclose(input_file);
        return true;
    }
    fclose(input_file);
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    return tolower(word[0]) - 'a';
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    return word_count;
}

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    int hashed = hash(word);
    for (node *temp = table[hashed]; temp != NULL; temp = temp->next)
    {
        if (strcasecmp(temp->word, word) == 0)
        {
            return true;
        }
    }
    return false;
}
// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    for (int i = 0; i < N; i++)
    {
        node *cursor = table[i];
        node *temp = cursor;

        while (cursor != NULL)
        {
            cursor = cursor ->next;
            free(temp);
            temp = cursor;
        }
    }
    return true;
}
