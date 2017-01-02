#include <stdio.h>

unsigned long sumTotal = 0;
unsigned long squareTotal = 0;
int max = 100;
int diff;

int sum(int max) {
  int i = 1;

  while (i <= max) {
    sumTotal = sumTotal + (i * i);
    i = i + 1;
  }

  printf("Sum total is %d\n", sumTotal);
  return 0;
}

int square(int max) {
  int i = 1;

  while (i <= max) {
    squareTotal = squareTotal + i;
    i = i + 1;
  }

  squareTotal = squareTotal * squareTotal;

  printf("Square total is %d\n", squareTotal);
  return 0;
}

int main() {
  sum(max);
  square(max);
  diff = sumTotal - squareTotal;
  printf("%d", diff);
  return 0;
}
