#include <stdio.h>
#include <math.h>

unsigned long found[100] = { 0 };
int foundIndex = 0;

int isPrime(unsigned long num) {
  int i;

  for (i = 2; i <= num / 2; ++i) {
    if (num % i == 0) {
      return 0;
    }
  }

  return 1;
}

int foundPrimes(unsigned long n) {
  int i = 0;
  printf("hi");
  while (found[i] != 0) {
    if (found[i] == n) {
      printf("%d is already found", n);
      return 0;
    }
    printf("hello");
  }
  return 1;
}

int truncateRight(unsigned long num) {
  while (num > 0) {
    if (isPrime(num) == 0 || foundPrimes(num) == 0) {
      return 0;
    }
    num = num / 10;
  }
  return 1;
}

int truncateLeft(unsigned long num) {
  while (num > 0) {
    int exponent = (round(floor(log10(num))));
    if (isPrime(num) == 0  || foundPrimes(num) == 0) {
      return 0;
    }
    int digit = num / round(pow(10, exponent));
    num = num - (digit * round(pow(10, exponent)));
  }
  return 1;
}

int main() {
  unsigned long index = 8;
  unsigned long total = 25;
  unsigned long sum = 0;

  while (total > 0) {
    if (isPrime(index) == 1) {
      if (truncateRight(index) == 1) {
        if (truncateLeft(index) == 1) {
          printf("%d\n", index);

          found[foundIndex] = index;
          foundIndex = foundIndex + 1;

          sum = sum + index;
          total = total - 1;
        }
      }
    }
    index = index + 1;
  }

  printf("\nSum is: %d\n", sum);

  return 0;
}
