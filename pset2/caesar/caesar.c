#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, string argv[])
{
    // Check to see that only one argument is given after ./caesar
    if (argc != 2)
    {
        printf("Usage: ./caesar k\n");
        return 1;
    }

    // Prompt user for a plaintext
    string plaintext = get_string("plaintext: ");

    // Use alphabetical index instead of ASCII to wrap around alphabet
    string alphabetical_index_upper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string alphabetical_index_lower = "abcdefghijklmnopqrstuvwxyz";
    char character;

    // Convert string to integer of key e.g. "5" to 5
    int key = atoi(argv[1]);

    // For each character in plaintext string, check if it is an alphabet while preserving case and shift by key
    for (int i = 0, n = strlen(plaintext); i < n; i++)
    {
        if (isalpha(plaintext[i]))
        {
            if (isupper(plaintext[i]))
            {
                character = plaintext[i] - 'A';
                plaintext[i] = alphabetical_index_upper[(character + key) % 26];
            }
            else
            {
                character = plaintext[i] - 'a';
                plaintext[i] = alphabetical_index_lower[(character + key) % 26];
            }
        }
    }
    printf("ciphertext: %s\n", plaintext);
    return 0;
}