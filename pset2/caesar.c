// Caesars algorithm which encrypts a word with a key by shifting each characters by key-many times
//
// Bojan Simic
// Pset2: caesar (less comfortable)

#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Prototype */
void caesarsAlgorithm(int shiftBy);

int main(int argCount, string argument[])
{
    if (argCount == 2)
    {
        int key = atoi(argument[1]);

        // Proceeds to encrypt
        caesarsAlgorithm(key);
    }
    else
    {
        printf("Error. Only one argument allowed.\n");
        return 1;
    }
}

/* Encrypts a word with a given key */
void caesarsAlgorithm(int shiftBy)
{
    string plaintext = get_string("plaintext: ");

    /* Encrypts 'plaintext' */

    // Makes sure that rotation doesn't exceed 26 characters
    int rotateByThisManyTimes = shiftBy % 26;
    int ascii;

    printf("ciphertext: ");

    for (int i = 0, n = strlen(plaintext); i < n; i++)
    {
        if (plaintext[i] >= 'A' && plaintext[i] <= 'Z')
        {
            ascii = plaintext[i] + rotateByThisManyTimes;

            // If 'ascii' > 90, then it needs to be wrapped around
            if (ascii > 'Z')
            {
                printf("%c", 'A' + (ascii - 91));
            }
            else
            {
                printf("%c", ascii);
            }
        }
        else if (plaintext[i] >= 'a' && plaintext[i] <= 'z')
        {
            ascii = plaintext[i] + rotateByThisManyTimes;

            // If 'ascii' > 122, it needs to be wrapped around
            if (ascii > 'z')
            {
                printf("%c", 'a' + (ascii - 123));
            }
            else
            {
                printf("%c", ascii);
            }
        }
        else
        {
            printf("%c", plaintext[i]);
        }
    }

    printf("\n");
}