#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Prompt user to enter a number between 0 and 23
    int height;
    do
    {
        height = get_int("Height: ");
    }
    while (height < 0 || height > 23);

    int spaces = height - 1;
    int blocks = 2;
    // Print the rows
    for (int i = 0; i < height; i++)
    {
        // Print the spaces
        for (int j = 0; j < spaces; j++)
        {
            printf(" ");
        }

        // Print the blocks
        for (int k = 0; k < blocks; k++)
        {
            printf("#");
        }

        spaces--;
        blocks++;
        printf("\n");
    }
}
