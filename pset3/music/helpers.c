// Helper functions for music

#include <cs50.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

#include "helpers.h"

// Converts a fraction formatted as X/Y to eighths
int duration(string fraction)
{
    int numerator = fraction[0] - '0';
    // Multiplies numerator based on demoninator value
    if (fraction[2] == '8')
    {
        return numerator;
    }
    else if (fraction[2] == '4')
    {
        return numerator * 2;
    }
    else if (fraction[2] == '2')
    {
        return numerator * 4;
    }
    else if (fraction[2] == '1')
    {
        return numerator * 8;
    }
    else
    {
        return 0;
    }
}

// Calculates frequency (in Hz) of a note
int frequency(string note)
{
    double freq = 0.0;
    int octave = 0;
    // Determine if parsed note has accidental
    // If there is accidental, octave is note[2]
    // If there is no accidental, octave is note[1]
    if (note[1] == '#' || note[1] == 'b')
    {
        octave = note[2] - '0';
    }
    else
    {
        octave = note[1] - '0';
    }
    // Counter for incrementing or decrementing depending on if octave > 4 or octave < 4
    int counter = octave - 4;

    // Determine which letter note it is
    // If octave is 4, frequency is defaulted to the result in this switch statement
    switch (note[0])
    {
        case 'A':
            freq = 440.0;
            break;
        case 'B':
            freq = 440.0 * pow(2, 2.0 / 12.0);
            break;
        case 'C':
            freq = 440.0 / pow(2, 9.0 / 12.0);
            break;
        case 'D':
            freq = 440.0 / pow(2, 7.0 / 12.0);
            break;
        case 'E':
            freq = 440.0 / pow(2, 5.0 / 12.0);
            break;
        case 'F':
            freq = 440.0 / pow(2, 4.0 / 12.0);
            break;
        case 'G':
            freq = 440.0 / pow(2, 2.0 / 12.0);
            break;
        default:
            return 0;
    }
    // Make adjustment to frequency according to octave
    // Only used if octave is not 4
    if (octave > 4)
    {
        // Keep multiplying frequency by 2 based on octave number
        while (counter != 0)
        {
            freq *= 2.0;
            counter--;
        }
    }
    else if (octave < 4)
    {
        // Keep dividing frequency by 2 based on octave number
        while (counter != 0)
        {
            freq /= 2.0;
            counter++;
        }
    }
    // Make adjustment to frequency according to accidental
    // Only used if accidental if parsed note has accidental
    if (note[1] == '#')
    {
        // To make a note sharp multiply by 2^(1/12)
        freq *= pow(2, 1.0 / 12.0);
    }
    else if (note[1] == 'b')
    {
        // To make a note flat divide by 2^(1/12)
        freq /= pow(2, 1.0 / 12.0);
    }
    // Round frequency into a whole number
    int answer = round(freq);
    return answer;
}

// Determines whether a string represents a rest
bool is_rest(string s)
{
    if (strcmp(s, "") == 0)
    {
        return true;
    }
    return false;
}
