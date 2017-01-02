#include <stdio.h>
#include <math.h>
#include <float.h>
#include <pthread.h>
#include <time.h>


unsigned long top = 0;
unsigned long bottom = 1;

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void* checkPrime(void *arg)
{
  unsigned long num = *(unsigned long *) arg;
  for (unsigned long i = 2; i <= num / 2; i++)
  {
    if (num % i == 0) {
      pthread_exit(NULL);
      return NULL;
    }
  }
  pthread_mutex_lock(&mutex);
  top ++;
  pthread_mutex_unlock(&mutex);

  pthread_exit(NULL);
  return NULL;
}

int main()
{
  // Initialize tracking variables
  double ratio = 1;
  unsigned long layer = 1;
  unsigned long corner[4];
  unsigned long side;
  float threshold = 0.2;

  clock_t tic = clock();

  // Initialize 3 compute threads in an array
  pthread_t prime[3];

  while (ratio > threshold) {
    // Set corners to new values
    side = (1 + ((layer - 1) * 2));
    corner[0] = side * side;
    printf("%d ", corner[0]);
    for (int i = 1; i < 3; i++)
    {
      corner[i] = corner[i - 1] - (side - 1);
      printf("%d ", corner[i]);
    }

    // Send data to compute threads
    for (int i = 0; i < 2; i++)
    {
      pthread_create(&prime[i], NULL, checkPrime, &corner[i + 1]);
    }

    // Wait until all computations are finished
    pthread_join(prime[0], NULL);
    pthread_join(prime[1], NULL);
    pthread_join(prime[2], NULL);

    // Increment values and iterate
    bottom += 4;
    layer ++;
    ratio = (double)top / (double)bottom;
    printf("Ratio of layer %d = %d / %d = %lf\n", layer, top, bottom, ratio);
    // printf("%d\t%lf\n", layer, ratio);
  }
  clock_t toc = clock();
  printf("Elapsed: %f seconds\n", (double)(toc - tic) / CLOCKS_PER_SEC);
  return 0;
}
