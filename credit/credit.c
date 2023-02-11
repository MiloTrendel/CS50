#include <stdio.h>
#include <cs50.h>
#include <math.h>
#include <string.h>

int main(void)
{
    // get credit card number
    string cardNumber = get_string("Credit Card Number: ");

    int add = 0;
    int mult = 0;

    int total = 0;

    // this variable is used to keep track of when to multiply or when to add the current number
    int either = 1;

    // variable that will store which card it is 0 = American Express, 1 = MasterCard and 2 = Visa
    int card = 0;

    // calculate checksum
    for (int i = strlen(cardNumber) - 1; i >= 0; i--)
    {
        int number = (int)cardNumber[i] - 48;

        if (either == 0)
        {
            number *= 2;
            if (number > 9)
            {
                mult += number % 10;
                number /= 10;
                mult += number;
                either++;
            }
            else
            {
                mult += number;
                either++;
            }
        }
        else if (either == 1)
        {
            add += number;
            either--;
        }
    }
    total = mult + add;

    // check if the card is valid
    if (total % 10 != 0)
    {
        printf("INVALID\n");
        return 0;
    }
    // prints what card it is
    int IcardNumber1 = cardNumber[0] - 48;
    int IcardNumber2 = cardNumber[1] - 48;
    int STRcardNumber = strlen(cardNumber);

    // checks if the card is an AMERICAN EXPRESS
    if (STRcardNumber == 15 && (IcardNumber1 == 3) && (IcardNumber2 == 4 || IcardNumber2 == 7))
    {
        printf("AMEX\n");
    }

    // checks if the card is a VISA
    else if (STRcardNumber == 13)
    {
        printf("VISA\n");
    }
    else if (STRcardNumber == 16)
    {
        // checks if the card is a VISA
        if (IcardNumber1 == 4)
        {
            printf("VISA\n");
        }

        // checks if the card is a MASTERCARD
        else if (IcardNumber1 == 5 && (IcardNumber2 == 1 || IcardNumber2 == 2 || IcardNumber2 == 3 || IcardNumber2 == 4
                                       || IcardNumber2 == 5))
        {
            printf("MASTERCARD\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}