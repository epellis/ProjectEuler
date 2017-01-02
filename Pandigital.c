#include <stdio.h>

/* Arrays with all digits for usage tracking */
int numbers[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

unsigned long sum;

/* Creates a factor based on indexes and used numbers */
int numberCreator(int length, int usage[], int start) {
  int multiplier = 1;
  int num = 0;
  int index = start;

  while (length > 0) {

    while (usage[index] != 0) {
      index = index + 1;
    }

    usage[index] = 1;
    num = num + (multiplier * numbers[index]);
    multiplier = multiplier * 10;
    length = length - 1;

  }

  return num;
}

/* Returns 0 if product contains already used numbers */
int productChecker(int product, int usage[]) {
  int newProduct = product;
  int remain = newProduct % 10;
  while (newProduct > 0) {
    if (usage[remain - 1] != 0) {
      return 0;
    }
    else {
      usage[remain - 1] = 1;
    }
    newProduct = newProduct / 10;
  }
  int i;
  for (i = 0; i < 10; i = i + 1) {
    if (usage[i] == 0) {
      return 0;
    }
  }
  return product;

}

int iterate() {
  int startA;
  int startB;
  int aLength;
  int bLength;
  a = 0;
  b = 0;

  for (aLength = 1; aLength < 2; aLength = aLength + 1) {
    for (bLength = 1; bLength < 3; bLength = bLength + 1) {
      for (startA = 0; startA < 10; startA = startA + 1) {
        for (startB = 0; startB < 10; startB = startB + 1) {

          int usage[9] = { 0 };
          a = numberCreator(aLength, usage, startA);
          b = numberCreator(bLength, usage, startB);
          int c = productChecker(a * b, usage);
          printf("%d * %d = %d", a, b, a * b);
          sum = sum + c;
          if (c == 0) {
            printf("\t False");
          }
          else {
            printf("\t True");
          }
          printf("\n");

          // printf("%d%d %d%d\t", aLength, bLength, startA, startB);
          // printf("%d %d\n", a, b);
        }
      }
    }
  }

  return 0;
}

int main() {
  iterate();
  printf("The sum is %d", sum);
  return 0;
}
