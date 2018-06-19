// Helper functions for music
//
// Bojan Simic
// Pset3: music

#include <cs50.h>
#include "helpers.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

// Converts a fraction formatted as X/Y to eighths
int duration(string fraction)
{
    int numerator = atoi(&fraction[0]);
    int denominator = atoi(&fraction[2]);

    float division = numerator / (float) denominator;

    int numberOfEighths = division / (1 / 8.0);

    return numberOfEighths;
}

// Calculates frequency (in Hz) of a note
int frequency(string note)
{
    string notesList[] = {"C", "C#", "D", "D#", "E", "F", "F#", "G", "G#", "A", "A#", "B"};
    char keyboardNote[3];
    int octave;
    // Needs to be initialized becuase if 'note' doesn't have accidental (else-loop) it would stay uninitialized
    int numberOfSemitones = 0;

    if (strlen(note) == 3)
    {
        sprintf(keyboardNote, "%c%c", note[0], note[1]);

        octave = atoi(&note[2]);

        if (note[1] == 'b')
        {
            sprintf(keyboardNote, "%c", note[0]);
            numberOfSemitones = -1;
        }
    }
    // 'if (strlen(note) == 2)'
    else
    {
        sprintf(keyboardNote, "%c", note[0]);
        octave = atoi(&note[1]);
    }

    numberOfSemitones += 12 * (octave - 4);
    // Needs to be initialized, otherwise could store garbage value if folliwing for-loop doesn't assign a value to this variable
    int keyDifferenceToA = 0;


    for (int i = 0; i < 12; i++)
    {
        if (strcmp(notesList[i], keyboardNote) == 0)
        {
            keyDifferenceToA = i - 9;
            break;
        }
    }

    numberOfSemitones += keyDifferenceToA;

    float frequency = pow(2, numberOfSemitones / 12.0) * 440;

    return round(frequency);
}

// Determines whether a string represents a rest
bool is_rest(string s)
{
    if (strcmp(s, "") == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
