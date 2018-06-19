// Encrypts a plaintext with a keyword with Vignere´s Algorithm
//
// Bojan Simic
// Pset2: vigenere (more comfortable)

#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

/* Prototypes */
void vigenereAlgorithm(string plaintext, string keyword);
int addIndex(char character);

int main(int argumentCount, string keyArgument[])
{
    string keyInput = keyArgument[1];

    // Checks if only one argument ('keyword') was typed in
    if (argumentCount == 2)
    {
        for (int i = 0, n = strlen(keyArgument[1]); i < n; i++)
        {
            // Checks for non-aphabetical characters
            if (!((keyInput[i] >= 'A' && keyInput[i] <= 'Z') || (keyInput[i] >= 'a' && keyInput[i] <= 'z')))
            {
                printf("Error. Non-alphabetical characters are not allowed.\n");
                return 1;
            }
        }

        // Proceeds with obfuscation if everything is correct
        string plainInput = get_string("plaintext: ");
        vigenereAlgorithm(plainInput, keyInput);
    }
    else
    {
        printf("Error. Keyword is necessary and no more than one is allowed.\n");
        return 1;
    }
}

/* Encrypts a given word with a given key */
void vigenereAlgorithm(string plaintext, string keyword)
{
    /* Transfers 'keyword' to lowercase so that it can be compared in func 'addIndex()' */
    int keywordLength = strlen(keyword);
    char lowerCaseKeyword[keywordLength];

    for (int i = 0; i < keywordLength; i++)
    {
        lowerCaseKeyword[i] = tolower(keyword[i]);
    }

    /* Obfuscates plaintext with keyword */
    int plaintextLength = strlen(plaintext);
    char cipher[plaintextLength];
    int ascii;
    int skip = 0;

    for (int i = 0; i < plaintextLength; i++)
    {
        // Capital letters (ASCII range 65 - 90)
        if (plaintext[i] >= 'A' &&  plaintext[i] <= 'Z')
        {
            ascii = (int) plaintext[i] + addIndex(lowerCaseKeyword[(i - skip) % keywordLength]);

            // Start from 'A' again if ASCII > 90
            if (ascii > 'Z')
            {
                cipher[i] = 'A' + (ascii - 91); // SOURCE: Asked on SO to help identify bug (https://goo.gl/LpMLFg)
            }
            else
            {
                cipher[i] = ascii;
            }
        }
        // Small letters (ASCII range 97 - 122)
        else if (plaintext[i] >= 'a' && plaintext[i] <= 'z')
        {
            ascii = plaintext[i] + addIndex(lowerCaseKeyword[(i - skip) % keywordLength]);

            // Start from 'a' again if ASCII > 122
            if (ascii > 'z')
            {
                cipher[i] = 'a' + (ascii - 123); // SOURCE: Asked on SO to help identify bug (https://goo.gl/LpMLFg)
            }
            else
            {
                cipher[i] = ascii;
            }
        }
        // Copy over non-aphabetical character
        else
        {
            cipher[i] = plaintext[i];
            // 'skip' counts the number of times a character was not obfuscated so that the char in 'keyword' doesn´t get skipped
            skip++;
        }
    }

    /* Prints obfuscated word */
    printf("ciphertext: ");

    for (int i = 0; i < plaintextLength; i++)
    {
        printf("%c", cipher[i]);
    }

    printf("\n");
}

/* Calculates index, which will be used to generate obfuscated letter (e.g. ASCII B: 66 + index e: 4 = ASCII F: 70) */
int addIndex(char character)
{
    string abc = "abcdefghijklmnopqrstuvwxyz";

    for (int i = 0; i < 26; i++)
    {
        if (character == abc[i])
        {
            return i;
        }
    }

    // ATTETNTION: might return false information but is needed due to compiler bitching around
    return 0;
}