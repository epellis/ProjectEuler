#include <stdio.h>
#include <math.h>
#include <float.h>
#include <pthread.h>

#define THREADCOUNT 4

unsigned long sum = 0;
unsigned long max = 1000000000;

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void* count(void *arg)
{
  int offset = *(int *) arg;
  for (int i = 0; i < max; i++) {
    // Start critical section
    pthread_mutex_lock(&mutex);
    sum += offset;
    pthread_mutex_unlock(&mutex);
    // End critical section
  }

  pthread_exit(NULL);
}

int main(void)
{
  // Spawn threads
  pthread_t id1;
  int offset1 = 1;
  pthread_create(&id1, NULL, count, &offset1);
  pthread_t id2;
  int offset2 = -1;
  pthread_create(&id2, NULL, count, &offset2);

  // Wait for threads to finish
  pthread_join(id1, NULL);
  pthread_join(id2, NULL);


  printf("Sum is: %d", sum);
  return 0;
}
