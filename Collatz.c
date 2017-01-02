#include <stdio.h>
#include <pthread.h>

unsigned long maxRange = 1000000;    // Largest chain to check length

unsigned long maxIndex = 1;     // Stores the largest chain index
unsigned long maxLength = 1;     // Stores the largest chain length

/*
  collatz() iterates through one chain until the current number is zero. Once this
  occurs, it updates maxIndex and maxLength, if the new values are now larger.

  int start: integer for collatz chain to begin at
*/
int collatz(int start) {
  unsigned long length = 0;
  unsigned long num = start;

  printf("%d\n", start);

  while (num != 1) {
    length = length + 1;

    // printf("%d -> ", num);

    /* Even function */
    if (num % 2 == 0) {
      num = num / 2;
    }

    /* Odd function */
    else if (num % 2 == 1) {
      num = (3 * num) + 1;
    }
  }

  // printf("1 \n\n");

  if (length > maxLength) {
    maxLength = length;
    maxIndex = start;
  }

  return 0;
}

/*
  main() iterates through all chains and stores the largest chain index and
  largest chain length in maxIndex and maxLength respectively.
*/
int main() {
  unsigned long i;

  for (i = 1; i < maxRange; i = i + 1) {
    collatz(i);
  }

  printf("The largest chain begins at ");
  printf("%d", maxIndex);
  printf(" and has a total length of ");
  printf("%d", maxLength);

  return 0;
}
