#include <stdio.h>
#include <math.h>

unsigned long max = 1000000;
unsigned long num;
unsigned long sum = 0;

int isPrime(unsigned long num) {
  int i;

  for (i = 2; i <= num / 2; ++i) {
    if (num % i == 0) {
      return 1;
    }
  }

  return 0;
}

int isCircularPrime(unsigned long num) {
  int exponent = (round(floor(log10(num))));
  int original = num;
  int lastDigit = num % 10;
  num = num / 10;
  num = num + (lastDigit * round(pow(10, exponent)));
  if (isPrime(num) != 0) {
    return 1;
  }
  while (num != original) {
    int exponent = (round(floor(log10(num))));
    int original = num;
    int lastDigit = num % 10;
    num = num / 10;
    num = num + (lastDigit * round(pow(10, exponent)));
    if (isPrime(num) != 0) {
      return 1;
    }
  }
  return 0;
}

int main() {
  for (num = 2; num < max; ++num) {
    if (isPrime(num) == 0) {
      if (isCircularPrime(num) == 0) {
        printf("%d\t", num);
        sum = sum + 1;
      }
    }
  }

  printf("\n%d circular prime numbers exist below %d", sum, max);

  return 0;
}
