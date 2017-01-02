#include <stdio.h>
#include <math.h>
#include <float.h>
#include <time.h>

int isPrime(unsigned long num)
{
  int i;

  for (i = 2; i <= num / 2; ++i) {
    if (num % i == 0) {
      return 0;
    }
  }

  return 1;
}

int getDenominator(int layer) {
  return 1 + ((layer - 1) * 4);
}

int * generateCorners(int side)
{
  static int arr[4];
  int corner = side * side;
  int i;
  for (i = 0; i < 4; i++) {
    arr[i] = corner;
    corner = corner - side + 1;
  }

  return arr;
}

int main()
{
  int layer = 2;
  float ratio = 1;
  float numberator = 0;
  float denominator = 1;
  int side;
  int num;
  float threshold = 0.12;

  clock_t tic = clock();

  while (ratio > threshold) {
    denominator += 4;

    side = (1 + ((layer - 1) * 2));
    int corner = side * side;
    int i;
      for (i = 0; i < 4; i++) {
        num = corner;
        numberator = numberator + isPrime(num);
        corner = corner - side + 1;
      }

    ratio = numberator / denominator;
    // printf("Ratio of layer %d = %f / %f = %f\n", layer, numberator, denominator, ratio);
    printf("%d\t%f\n", layer, ratio);
    layer++;
  }
  clock_t toc = clock();
  printf("Elapsed: %f seconds\n", (double)(toc - tic) / CLOCKS_PER_SEC);
  return 0;
}
