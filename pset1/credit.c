// Checks the validity of a CC with Luhns algorithm and if valid, prints the CC institute
//
// Bojan Simic
// Pset1: credit (more comfortable)

#include <stdio.h>
#include <cs50.h>

/* Prototypes */
void luhnsAlgorithm(long ccNumber);
int numberOfDigits(long ccNumber);

int main(void)
{
    // Prompt user
    long userInput = get_long_long("Number: ");

    luhnsAlgorithm(userInput);
}

/* Checks validity of a given CC number */
void luhnsAlgorithm(long ccNumber)
{
    // Calculates number of digits in 'userInput'
    int ccNumberOfDigits = numberOfDigits(ccNumber);

    /* Taking apart ccNumber and saving digits in array 'ccDigits' */
    int ccDigits[ccNumberOfDigits];
    int iterationVar1 = 0;

    while (ccNumber != 0)
    {
        // Saves remainder (last digit)
        int leastSignificantDigit = ccNumber % 10;
        // 'ccNumber' is being reversed
        ccDigits[iterationVar1] = leastSignificantDigit;
        iterationVar1++;
        // Get rid of float
        ccNumber /= 10;
    }

    /* Block extracts every second digit from 'ccDigits' */
    int ccEvery2ndDigit[ccNumberOfDigits];

    // Intialize array with 0s so that when calling an unassigned element won't result in a big (signed) int in block /* calculates sum2 */
    for (int i = 0; i < ccNumberOfDigits; i++)
    {
        ccEvery2ndDigit[i] = 0;
    }

    int sum1 = 0;

    for (int i = 0; i < ccNumberOfDigits; i++)
    {
        // Extract every second int from 'ccDigits'
        if (i % 2 == 1)
        {
            ccEvery2ndDigit[i] = ccDigits[i] * 2;
        }
        // Calculates the sum of every 2nd digit starting from first number in 'ccNumber'
        else
        {
            sum1 = sum1 + ccDigits[i];
        }
    }

    /* Calculates sum2 */
    // Array to take apart int if its >= 10 (&& <=18 (2*9) ) and store digits separately
    int doubleDigit[2];
    int digitSum = 0;
    int sum2 = 0;

    for (int i = 0; i < ccNumberOfDigits; i++)
    {
        if (ccEvery2ndDigit[i] >= 10)
        {
            // Reset 'iterationVar2' back to zero
            int iterationVar2 = 0;

            // Splitting up double digits
            while (ccEvery2ndDigit[i] != 0)
            {
                int leastSignificantDigit = ccEvery2ndDigit[i] % 10;
                doubleDigit[iterationVar2] = leastSignificantDigit;
                ccEvery2ndDigit[i] /= 10;
                iterationVar2++;
            }

            digitSum = doubleDigit[0] + doubleDigit[1];
            sum2 = sum2 + digitSum;

        }
        else
        {
            sum2 = sum2 + ccEvery2ndDigit[i];
        }
    }

    /* Check validity and institute */
    int sum = sum1 + sum2;

    if (sum % 10 == 0)
    {
        // 'ccNumberOfDigits - 1' checks actually the first number of the credit card
        // VISA (13 or 16 digits; starts with 4)
        if (((ccNumberOfDigits == 13) || (ccNumberOfDigits == 16)) && (ccDigits[ccNumberOfDigits - 1] == 4))
        {
            printf("VISA\n");
        }
        // AMEX (15 digits; starts either with 34 or 37)
        else if (((ccNumberOfDigits == 15) && ((ccDigits[ccNumberOfDigits - 1] == 3) && ((ccDigits[ccNumberOfDigits - 2] == 4)
                                               || (ccDigits[ccNumberOfDigits - 2] == 7)))))
        {
            printf("AMEX\n");
        }
        // MasterCard (16 digits; starts either with 51, 52, 53, 54 or 55)
        else if (((ccNumberOfDigits == 16) && (ccDigits[ccNumberOfDigits - 1] == 5) && ((ccDigits[ccNumberOfDigits - 2] == 1)
                  || (ccDigits[ccNumberOfDigits - 2] == 2)
                  || (ccDigits[ccNumberOfDigits - 2] == 3)
                  || (ccDigits[ccNumberOfDigits - 2] == 4) || (ccDigits[ccNumberOfDigits - 2] == 5))))
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

/* Calculates number of digits */
int numberOfDigits(long ccNumber)
{
    int iterationVar = 0;

    while (ccNumber != 0)
    {
        ccNumber /= 10;
        iterationVar++;
    }

    return iterationVar;
}