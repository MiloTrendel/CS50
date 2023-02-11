#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

int main(int argc, string argv[])
{
    // verify if the key input is correct
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    // verifies if the key contains 26 characters
    if (strlen(argv[1]) != 26)
    {
        printf("Key must contain 26 characters\n");
        return 1;
    }

    string key = argv[1];

    // creates bool varible to keep track of the upper characters and if the character was printed
    bool isUpper = false;
    bool isPrinted = false;

    // puts the whole key to lowercase
    for (int i = 0; i < strlen(key); i++)
    {
        key[i] = tolower(key[i]);
    }

    // verifies that the whole key contains alphabetical characters
    for (int i = 0; i < strlen(key); i++)
    {
        if (!isalpha(key[i]))
        {
            printf("Usage: ./substitution key\n");
            return 1;
        }
    }

    // verifies if the key doesn't contains duplicate characters
    for (int i = 0; i < strlen(key); i++)
    {
        for (int j = i + 1; j < strlen(key) - i; j++)
        {
            if (key[i] == key[j])
            {
                printf("Usage ./substitution key");
                return 1;
            }
        }
    }

    // gets the input from the user
    string text = get_string("plaintext: ");

    printf("ciphertext: ");

    for (int i = 0; i < strlen(text); i++)
    {
        isPrinted = false;

        // checks if the current character is uppercase or lowercase
        if (isupper(text[i]))
        {
            isUpper = true;
        }
        for (int j = 97; j < 123; j++)
        {
            int a = j - 97;

            if (!isspace(text[i]))
            {
                // checks if it is a ponctuation
                if (text[i] == '.' || text[i] == ',' || text[i] == '!' || text[i] == '?')
                {
                    printf("%c", text[i]);
                    isPrinted = true;
                    break;
                }
                //checks if it is the current letter uppercase or not
                else if (text[i] == j || text[i] == j - 32)
                {
                    // printf the character considering if it is uppercase or lowercase
                    if (isUpper)
                    {
                        printf("%c", toupper(key[a]));
                        isUpper = false;
                        isPrinted = true;
                        break;
                    }
                    else
                    {
                        printf("%c", key[a]);
                        isPrinted = true;
                        break;
                    }
                }
                // checks if it is a number
                else if (text[i] >= 48 && text[i] <= 57)
                {
                    printf("%c", text[i]);
                    isPrinted = true;
                    break;
                }
            }
            // prints if it is a space
            else
            {
                printf("%c", text[i]);
                isPrinted = true;
                break;
            }
        }
        // prints characters that didn't verified all of the previous requirement 
        if (!isPrinted)
        {
            printf("%c", text[i]);
        }
    }
    printf("\n");
}