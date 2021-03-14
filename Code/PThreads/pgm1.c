#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int i;
void *odd(void *max)
{
  FILE *fd;

  fd = fopen("odd_num", "w");
  for (i = 1; i < *(int *)max; i+= 2)
    fprintf(fd, "%d\n", i);
}

void *even(void *max)
{
  FILE *fd;
 
  fd = fopen("even_num", "w");
  for (i = 2; i < *(int *)max; i+= 2)
    fprintf(fd, "%d\n", i);
}

int main()
{
  int max = 50, max1 = 100, max2 = 200;

  FILE *fd;

  pthread_t *th1, *th2;

  // Create thread 1, Returns 0 if successful
  th1 = (pthread_t *) malloc(sizeof(pthread_t));
  if (pthread_create(th1, NULL, odd, (void *)&max1)) {
    perror("error creating the first thread");
    exit(1);
  }
  printf("created the first thread\n");


  // Create thread 2; Returns 0 if successful
  th2 = (pthread_t *) malloc(sizeof(pthread_t));
  if (pthread_create(th2, NULL, even, (void *)&max2)) {
    perror("error creating the second thread");
    exit(1);
  }
  printf("created the second thread\n");

  fd = fopen("whole_num", "w");

  for (i = 1; i < max; i++)
    fprintf(fd, "%d\n", i);

   // Blocks the calling thread until the specified thread_id thread terminates
  pthread_join(*th1, 0);
  pthread_join(*th2, 0);
}
