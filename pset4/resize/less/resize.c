// Resizes (i.e., enlarges) 24-bit uncompressed BMPs by a factor of n.

#include <stdio.h>
#include <stdlib.h>

#include "bmp.h"

int main(int argc, char *argv[])
{
    // ensure proper usage
    if (argc != 4)
    {
        fprintf(stderr, "Usage: ./resize n infile outfile\n");
        return 1;
    }

    // remember filenames
    char *infile = argv[2];
    char *outfile = argv[3];

    // The factor
    int n = atoi(argv[1]);

    if (n <= 0 || n > 100)
    {
        fprintf(stderr, "Usage: n must be a positive integer less than or equal to 100");
        return 1;
    }

    // open input file
    FILE *inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", infile);
        return 2;
    }

    // open output file
    FILE *outptr = fopen(outfile, "w");
    if (outptr == NULL)
    {
        fclose(inptr);
        fprintf(stderr, "Could not create %s.\n", outfile);
        return 3;
    }

    // read infile's BITMAPFILEHEADER
    BITMAPFILEHEADER bf, new_bf;
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);
    new_bf = bf;

    // read infile's BITMAPINFOHEADER
    BITMAPINFOHEADER bi, new_bi;
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);
    new_bi = bi;

    // ensure infile is (likely) a 24-bit uncompressed BMP 4.0
    if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 ||
        bi.biBitCount != 24 || bi.biCompression != 0)
    {
        fclose(outptr);
        fclose(inptr);
        fprintf(stderr, "Unsupported file format.\n");
        return 4;
    }

    // Scale the new BITMAPINFOHEADER's width and height to be factor of n
    new_bi.biWidth = bi.biWidth * n;
    new_bi.biHeight = bi.biHeight * n;

    // determine padding for scanlines
    int padding = (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
    // Determine new padding for resized version of bit map
    int new_padding = (4 - (new_bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;

    // Determine new size image for header info
    new_bi.biSizeImage = (sizeof(RGBTRIPLE) * new_bi.biWidth + new_padding) * abs(new_bi.biHeight);
    new_bf.bfSize = new_bi.biSizeImage + sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER);

    // write outfile's BITMAPFILEHEADER
    fwrite(&new_bf, sizeof(BITMAPFILEHEADER), 1, outptr);

    // write outfile's BITMAPINFOHEADER
    fwrite(&new_bi, sizeof(BITMAPINFOHEADER), 1, outptr);

    // iterate over infile's scanlines
    for (int i = 0, biHeight = abs(bi.biHeight); i < biHeight; i++)
    {
        // Read each scanline n factor of times
        for (int j = 0; j < n; j++)
        {
            // iterate over pixels in scanline
            for (int k = 0; k < bi.biWidth; k++)
            {
                // temporary storage
                RGBTRIPLE triple;

                // read RGB triple from infile
                fread(&triple, sizeof(RGBTRIPLE), 1, inptr);

                // write RGB triple to outfile n number of times to scale it horizontally
                for (int l = 0; l < n; l++)
                {
                    fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);
                }
            }

            // Add new padding
            for (int l = 0; l < new_padding; l++)
            {
                fputc(0x00, outptr);
            }

            // Move cursor back to beginning to rewrite a line
            if (j < n - 1)
            {
                fseek(inptr, sizeof(RGBTRIPLE) * -bi.biWidth, SEEK_CUR);
            }
        }

        // skip over padding, if any
        fseek(inptr, padding, SEEK_CUR);
    }

    // close infile
    fclose(inptr);

    // close outfile
    fclose(outptr);

    // success
    return 0;
}
