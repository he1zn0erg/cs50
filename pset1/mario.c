// Prints two half-pyramids whose sizes are defined by the users input
//
// Bojan Simic
// Pset1: mario (more comfortable)

#include <stdio.h>
#include <cs50.h>

// Prototypes
int prompt(void);
void marioWorld(int pyramidHeight);

int main(void)
{
    int userInputHeight;

    do
    {
        userInputHeight = prompt();
    }
    while ((userInputHeight > 23) || (userInputHeight < 0));

    marioWorld(userInputHeight);
}

// When called, prompts user to input height
int prompt(void)
{
    return get_int("Height: ");
}

// Will print pyramid based on user input
void marioWorld(int pyramidHeight)
{
    for (int row = 1; row <= pyramidHeight; row++)
    {
        // Spaces of 1st half-pyramid
        for (int space = 1; space <= (-1 * row + pyramidHeight); space++)
        {
            printf(" ");
        }

        // 1st half-pyramids hashes
        for (int hash = 1; hash <= row; hash++)
        {
            printf("#");
        }

        // Middle spaces
        printf("  ");

        // 2nd half-pyramids hashes
        for (int hash = 1; hash <= row; hash++)
        {
            printf("#");
        }

        printf("\n");
    }
}