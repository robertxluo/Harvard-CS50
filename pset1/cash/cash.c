#include <cs50.h>
#include <math.h>
#include <stdio.h>

int main(void)
{
    // Prompt user for an amount of change
    float change;
    do
    {
        change = get_float("Change owed: ");
    }
    while (change < 0);


    int coin = 0;

    // Convert dollars to cents
    int amount = (int)round(change * 100);

    // Check how many quarters fit in change
    if (amount % 25 != amount)
    {
        coin += amount / 25;
        amount = amount % 25;

    }

    // Check how many dimes fit in change
    if (amount % 10 != amount)
    {
        coin += amount / 10;
        amount = amount % 10;

    }

    // Check how many nickels fit in change
    if (amount % 5 != amount)
    {
        coin += amount / 5;
        amount = amount % 5;

    }

    // Check how many pennies fit in change
    if (amount % 1 != amount)
    {
        coin += amount / 1;
        amount = amount % 1;
    }

    printf("%d\n", coin);
}