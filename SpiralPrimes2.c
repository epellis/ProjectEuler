#include <stdio.h>
#include <math.h>
#include <float.h>

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
  float numberator;
  float denominator;
  int side;

  while (ratio > 0.50) {
    numberator = 0;

    // Generate corners for that layer
    int i, j;
    for (i = 2; i <= layer; i++) {
      side = (1 + ((i - 1) * 2));
      printf("Layer %d: ", i);

      static int arr[4];
      int corner = side * side;
      int i;
      for (i = 0; i < 4; i++) {
        arr[i] = corner;
        corner = corner - side + 1;
      }

      for (j = 0; j < 4; j++) {
        printf("%d, ", arr[j]);
      }
      printf("\n");

      for (j = 0; j < 4; j++) {
        numberator = numberator + isPrime(arr[j]);
        }
      }

    denominator = getDenominator(layer);
    ratio = numberator / denominator;
    printf("Ratio of layer %d = %f / %f = %f\n\n", layer, numberator, denominator, ratio);
    layer++;
  }

  return 0;
}
