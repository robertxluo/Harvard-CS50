// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "dictionary.h"

// Declare first node of the trie
node *root;

// Initialize global variable of how many words are in the dictionary
int dictionary_size = 0;

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    // Cursor pointer to trie root node
    node *cursor = root;

    // Iterate through word to check if it can go through the trie
    for (int i = 0; word[i] != '\0'; i++)
    {
        if (word[i] == '\'')
        {
            // Check if apostrophe specifically exists
            if (cursor->children[26] == NULL)
            {
                return false;
            }
            cursor = cursor->children[26];
        }
        else if (cursor->children[tolower(word[i]) - 'a'] == NULL)
        {
            return false;
        }
        else
        {
            cursor = cursor->children[tolower(word[i]) - 'a'];
        }
    }

    // Make sure that is_word is true at the cursor to denote that it is indeed a word in the dictionary
    if (cursor->is_word == true)
    {
        return true;
    }

    return false;
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    // Open dictionary file
    FILE *fp = fopen(dictionary, "r");
    if (fp == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", dictionary);
        return false;
    }

    // Allocate the first node of the trie
    root = calloc(1, sizeof(node));

    // Cursor pointer to trie root node
    node *cursor = root;

    // Iterate through dictionary to generate trie data structure
    for (int c = fgetc(fp); c != EOF; c = fgetc(fp))
    {
        if (isalpha(c) || c == '\'')
        {
            // Check apostrophe first because ASCII arithmetic won't work for it
            if (c == '\'')
            {
                if (cursor->children[26] == NULL)
                {
                    cursor->children[26] = calloc(1, sizeof(node));
                }
                cursor = cursor->children[26];
            }
            else if (cursor->children[c - 'a'] == NULL)
            {
                cursor->children[c - 'a'] = calloc(1, sizeof(node));
            }

            // Only traverse if it is not an apostrophe here to prevent traversing twice
            if (c != '\'')
            {
                cursor = cursor->children[c - 'a'];
            }
        }

        // If c is a newline, it means a new word has begun
        if (c == '\n')
        {
            cursor->is_word = true;
            dictionary_size++;
            cursor = root;
        }
    }

    fclose(fp);
    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    return dictionary_size;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    node *cursor = root;
    recursive_free(cursor);
    return true;
}

// Recursive function to free trie nodes bottom up
void recursive_free(node *children)
{
    for (int i = 0; i < 27; i++)
    {
        if (children->children[i] != NULL)
        {
            recursive_free(children->children[i]);
        }
    }

    free(children);
}