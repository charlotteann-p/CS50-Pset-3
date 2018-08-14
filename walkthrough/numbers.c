#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

int main(int argc, string argv[]) {
  // accepts an input in the form xx-0000
  // the letters will be initials
  // the numbers will be passcodes
  // two arguments 1.) xx-0000 [the code] 2.) hash integer from 1 - 9999
  // 死にたい
  if (argc != 3) {
    printf("Usage: ./numbers xx-0000 1-9999\n");
    return 1;
  }
  // validate parameters
  string passcode = argv[1];
  double hash = atol(argv[2]);
  if (strlen(argv[1]) != 7) {
    printf("Parameter 1 must be 7 characters");
    return 1;
  }
  // set up an array for the numeric code
  char numbers[5];
  char letters[3];
  int x = 0;
  int y = 0;
  int z = 0;
  while (x < 8) {
    if (isdigit(passcode[x])) {
      numbers[y++] = passcode[x];
      // y++;
    } else if (isalpha(passcode[x])) {
      letters[z++] = passcode[x];
      // z++;
    }
    x++;
  }
  printf("よくできました！\n");
  printf("%s\n", numbers);
  int code = atoi(numbers);
  if (strcmp(letters, "xy") != 0) { /// so if instead of xy it was A, B, C, etc. then you could do something with notes
    printf("Your four digit code is: %i\n", code);
    double securecode = code/2;
    printf("Your super-secure code is: %lf\n", pow(securecode, hash));
  } else {
    printf("Your super-secure code [think frequency] is: %i\n", code + 1);
    // 2^n/12 * 440
  }
  return 0;
}