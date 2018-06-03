#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, string argv[])
{
    // Check to see that only one argument is given after ./vigenere
    if (argc == 2)
    {
        // Check 2nd command line argument is alphabetical
        for (int i = 0; i < strlen(argv[1]); i++)
        {
            if (isalpha(argv[1][i]))
            {
                continue;
            }
            else
            {
                printf("Usage: ./vigenere k\n");
                return 1;
            }
        }
        // Prompt user for a plaintext
        string plaintext = get_string("plaintext: ");

        // Use alphabetical index instead of ASCII to wrap around alphabet
        string alphabetical_index_upper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        string alphabetical_index_lower = "abcdefghijklmnopqrstuvwxyz";
        char character;
        char sub_key;
        string key = argv[1];
        int key_length = strlen(argv[1]);
        int count = 0;

        // For each character in plaintext string, check if it is an alphabet while preserving case and shift by key
        for (int i = 0, n = strlen(plaintext); i < n; i++)
        {
            // Check if plaintext letter is an alphabet, if not, skip to next letter
            if (isalpha(plaintext[i]))
            {
                if (isupper(plaintext[i]))
                {
                    // The count % key_length is used to wraparound key using count off method
                    // The % 26 are used to ensure it works with the alphabetical index
                    sub_key = (toupper(key[count % key_length]) - 'A') % 26;
                    character = (plaintext[i] - 'A') % 26;
                    plaintext[i] = alphabetical_index_upper[(character + sub_key) % 26];
                }
                else
                {
                    sub_key = (tolower(key[count % key_length]) - 'a') % 26;
                    character = (plaintext[i] - 'a') % 26;
                    plaintext[i] = alphabetical_index_lower[(character + sub_key) % 26];
                }

                // Used to move to the next letter of the key
                count++;
            }
        }
        printf("ciphertext: %s\n", plaintext);
        return 0;
    }
    else
    {
        printf("Usage: ./vigenere k\n");
        return 1;
    }
}