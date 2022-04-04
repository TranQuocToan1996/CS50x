#include <cs50.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <math.h>

int main(void)
{
    // Ask for credit card number
    long long cardnumber = 0;
    do
    {
        cardnumber = get_long_long("Input: ");
    }
    while (cardnumber < 0);

    // Check sum and card length
    int count = 0;
    long long digit = cardnumber;
    while (digit > 0)
    {
        digit = digit / 10;
        count++;
    }

    if ((count != 13) && (count != 15) && (count != 16))
    {
        printf("INVALID\n");
        return 0;
    }
    int number[count];
    digit = cardnumber; // Reset digit to before continue calculate
    for (int i = count - 1 ; i >= 0; i--)
    {
        number[i] = digit % 10;
        digit = digit / 10;
    }
    int checksum = 0;
    for (int i = count - 2; i >= 0; i -= 2)
    {
        if (number[i] * 2 >= 10)
        {
            checksum += 1 + (2 * number[i]) % 10; // Maximum is 9*2=18 so the first number always be 1
        }
        else
        {
            checksum += 2 * number[i];
        }
    }

    for (int i = count - 1; i >= 0; i -= 2)
    {
        checksum += number[i];
    }

    printf("%i", checksum);
    if (checksum % 10 != 0)
    {
        printf("INVALID\n");
        return 0;
    }

    // Print name of the card

    if (count == 15 && number[0] == 3 && (number[1] == 4 || number[1] == 7))
    {
        printf("AMEX\n");
        return 0;
    }

    else if (count == 16 && number[0] == 5 && (number[1] == 1 || number[1] == 2 || number[1] == 3 || number[1] == 4 || number[1] == 5))
    {
        printf("MASTERCARD\n");
        return 0;
    }

    else if ((count == 13 || count == 16) && number[0] == 4)
    {
        printf("VISA\n");
        return 0;
    }
    else
    {
        printf("INVALID\n");
        return 0;
    }
}