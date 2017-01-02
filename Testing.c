#include <stdio.h>
#include <math.h>
#include <pthread.h>

int main(void)
{
  char key[3];
  key[0] = 'a';
  key[1] = 'a';
  key[2] = 'a';

  for (int a = 0; a < 3; a++) {
    printf("%c", key[a]);
  }

  for (int i = 0; i < 26; i++) {
    for (int j = 0; j < 26; j++) {
      for (int k = 0; k < 26; k++) {
        for (int a = 0; a < 3; a++) {
          printf("%c", key[a]);
        }
        printf("\n");
        key[0]++;
      }
      key[0] = 'a';
      key[1]++;
    }
    key[1] = 'a';
    key[2]++;
  }

  return 0;
}
