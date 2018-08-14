// Helper functions for music

#include <cs50.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#include "helpers.h"






// Converts a fraction formatted as X/Y to eighths
int duration(string fraction)
{
    if (fraction[0] == '1')
    {
      if (fraction[2] == '1')
      {
          return 8;
      }
      else if (fraction[2] == '2')
      {
          return 4;
      }
      else if (fraction[2] == '4')
      {
          return 2;
      }
      else if (fraction[2] == '8')
      {
          return 1;
      }
      else
      {
          return 0;
      }
    }
    else if (fraction[0] == '3')
    {
      if (fraction[2] == '4')
      {
          return 6;
      }
      else if (fraction[2] == '8')
      {
          return 3;
      }
      else
      {
          return 0;
      }
    }
    else if (fraction[0] == '5')
    {
      if (fraction[2] == '8')
      {
          return 5;
      }
      else
      {
          return 0;
      }
    }
    else if (fraction[0] == '7')
    {
        if (fraction[2] == '8')
        {
            return 7;
        }
        else
        {
            return 0;
        }
    }
    else
    {
        return 0;
    }
}

// Calculates frequency (in Hz) of a note
int frequency(string note)
{
    // note = get_string("Input a note (THIS IS PLACEHOLDER): ");
    double freq; // default at octave 4
    double freqOct = 0; // frequency customized to whatever octave
    int i;
    for (i = 0; i <= strlen(note); i++) {
      switch(note[0])
      {
        case 'A':
            freq = 440;
            break;
        case 'B':
            freq = 493.88;
            break;
        case 'C':
            freq = 261.63;
            break;
        case 'D':
            freq = 293.66;
            break;
        case 'E':
            freq = 329.63;
            break;
        case 'F':
            freq = 349.23;
            break;
        case 'G':
            freq = 392;
            break;
      }
      if (strlen(note) == 2) {
        switch(note[1])
        {
            case '0':
                freqOct = freq / 16;
                break;
            case '1':
                freqOct = freq / 8;
                break;
            case '2':
                freqOct = freq / 4;
                break;
            case '3':
                freqOct = freq / 2;
                break;
            case '4':
                freqOct = freq;
                break;
            case '5':
                freqOct = freq * 2;
                break;
            case '6':
                freqOct = freq * 4;
                break;
            case '7':
                freqOct = freq * 8;
                break;
            case '8':
                freqOct = freq * 16;
                break;
        }
      } else if (strlen(note) == 3) {
        switch(note[1])
        {
            case '#':
                freq = freq * (pow(2, 0.0833333333333333333333333));
                break;
            case 'b':
                freq = freq / (pow(2, 0.0833333333333333333333333));
                break;
        }
        switch(note[2])
        {
            case '0':
                freqOct = freq / 16;
                break;
            case '1':
                freqOct = freq / 8;
                break;
            case '2':
                freqOct = freq / 4;
                break;
            case '3':
                freqOct = freq / 2;
                break;
            case '4':
                freqOct = freq;
                break;
            case '5':
                freqOct = freq * 2;
                break;
            case '6':
                freqOct = freq * 4;
                break;
            case '7':
                freqOct = freq * 8;
                break;
            case '8':
                freqOct = freq * 16;
                break;
        }
      }
      else
      {
          printf("Please input a note in the following format: A4, E#3, etc...");
          return 1;
      }
    return round(freqOct); // ok???
    }
    printf("The frequency is: %f\n", freqOct);
    return 0;
}

// Determines whether a string represents a rest
bool is_rest(string s)
{
    if (strlen(s) == 0) {
        return true;
    } else {
        return false;
    }
}