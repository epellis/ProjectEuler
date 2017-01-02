#include <stdio.h>
#include <math.h>
#include <float.h>

double estimate(float a, float b)
{
  double sum = 1;
  float counter = 0;

  /* While b > 0 */
  while (counter < b - 1) {
    sum = sum * ((a - counter) / (b - counter));
    counter++;
  }
  sum = sum * (a - counter);
  return sum;
}

int main()
{
  int total = 0;
  int max = 100;
  unsigned long n, r, val;

  for (n = 1; n <= max; n++) {
    for (r = 1; r <= n; r++) {
      double num = estimate(n, r);
      printf("%d C %d = %f\n", n, r, num);
      if (num >= 1000000) {
        total++;
      }
    }
  }

  printf("Total is: %d", total);

  return 0;
}
