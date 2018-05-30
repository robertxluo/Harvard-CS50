#include <cs50.h>
#include <math.h>
#include <stdio.h>

int main(void)
{
    // Prompt user to enter credit card number
    long long cc_number = get_long_long("Number: ");

    // Get the length of the credit card number
    int count = 0;
    long long digits = cc_number;
    while (digits > 0)
    {
        digits /= 10;
        count++;
    }

    // Check credit card length to see if it is a valid number based on LENGTH
    if (count != 13 && count != 15 && count != 16)
    {
        printf("INVALID\n");
        return 0;
    }

    // Get the sum of digits of every other number multiplied by 2
    long long cc_number_copy = cc_number;
    int every_other[count];
    int every_other_sum = 0;
    for (int i = 0; i < count; i++)
    {
        every_other[i] = (cc_number_copy / 10) % 10 * 2;
        cc_number_copy /= 100;

        // Extract the two digit number into one digit and sum them (e.g. 14 = 1 + 4)
        if (every_other[i] > 9)
        {
            every_other[i] = every_other[i] % 10 + every_other[i] / 10;
        }
        every_other_sum += every_other[i];
    }

    // Get the sum of digits not multiplied by 2
    int non_multiplied_sum = 0;
    cc_number_copy = cc_number;
    for (int i = 0; i < count; i++)
    {
        non_multiplied_sum += cc_number_copy % 10;
        cc_number_copy /= 100;
    }

    // Check credit card company and checksum to see if valid
    int checksum = every_other_sum + non_multiplied_sum;
    checksum %= 10;
    if (checksum != 0)
    {
        printf("INVALID\n");
    }
    else if (((cc_number >= 340000000000000 && cc_number <= 349999999999999) || (cc_number >= 370000000000000
            && cc_number <= 379999999999999)))
    {
        printf("AMEX\n");
    }
    else if (cc_number >= 5100000000000000 && cc_number <= 5599999999999999)
    {
        printf("MASTERCARD\n");
    }
    else if (((cc_number >= 4000000000000 && cc_number <= 4999999999999) || (cc_number >= 4000000000000000
              && cc_number <= 4999999999999999)))
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }

    return 0;
}