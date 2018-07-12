// Recovers JPEGs from a forensic image

#include <stdio.h>
#include <stdlib.h>

#define BLOCK 512

int main(int argc, char *argv[])
{
    // Ensure proper usage
    if (argc != 2)
    {
        fprintf(stderr, "Usage: ./recover image\n");
        return 1;
    }

    char *raw_file = argv[1];

    // Open memory card file
    FILE *inptr = fopen(raw_file, "r");
    if (inptr == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", raw_file);
        return 2;
    }

    // Output file pointer to be written
    FILE *outptr = NULL;

    // Counter for how many jpegs found
    int jpeg_count = 0;

    // Flag to check if first jpeg is already found
    int jpeg_found = 0;

    // Creating size of filenames of jpeg files
    char title[8];

    unsigned char buffer[BLOCK];

    while (fread(buffer, BLOCK, 1, inptr) == 1)
    {
        // Check first 4 bytes to see if beginning of JPEG is found
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            // Check if any jpeg has already been found and close it to start a new jpeg file
            if (jpeg_found == 1)
            {
                // Close the file to start a new one because jpeg has been found
                fclose(outptr);
            }
            else
            {
                // Start first jpeg file and mark that a jpeg has been found
                jpeg_found = 1;
            }

            // Naming the jpeg files
            sprintf(title, "%03d.jpg", jpeg_count++);
            outptr = fopen(title, "w");
        }

        // Start writing the jpeg since it's been found
        if (jpeg_found == 1)
        {
            fwrite(&buffer, BLOCK, 1, outptr);
        }
    }

    // Close files
    if (outptr != NULL)
    {
        fclose(outptr);
    }
    fclose(inptr);

    return 0;
}