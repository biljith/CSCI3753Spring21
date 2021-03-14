#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/time.h>

#define MYSTACKSIZE 40960

// pthread_mutex_t m;

void *odd(void *max)
{
  int i;
  struct timeval tp;

  for (i = 0; i < 10; i++){
    printf("odd %d\n", i);
    sleep(1);
  }
}

void *even(void *max)
{
  int i;
  struct timeval tp;
 
  for (i = 0; i < 10; i++) {
    printf("even %d\n", i);
    sleep(1);
  }
}

main()
{
  // int max = 50, max1 = 100, max2 = 200, i;
  pthread_attr_t attr;
  pthread_t *th1, *th2;
  void *st1, *st2;
  size_t sz;
  int policy;
  struct timeval tp;



  pthread_attr_init(&attr);


  // Create stack for thread 1
  st1 = (void *) malloc(MYSTACKSIZE);

  // need stack size > 1 MB default or less
  pthread_attr_setstacksize(&attr, MYSTACKSIZE);

  // When you specify the size of a thread stack, be sure to account for the 
  // allocations needed by the invoked function and by each function called
  pthread_attr_setstack(&attr, st1, MYSTACKSIZE);


  // pthread_attr_getstacksize(&attr, &sz);

  // When a thread is created nondetached (PTHREAD_CREATE_JOINABLE), 
  // it is assumed that you will be waiting for it. 
  // That is, it is assumed that you will be executing a pthread_join() on the thread.
  pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);

  // The thread competes for resources with all other threads in the same process.
  pthread_attr_setscope(&attr, PTHREAD_SCOPE_PROCESS);

  // the attributes from the pthread_create() call are to be used
  pthread_attr_setinheritsched(&attr, PTHREAD_EXPLICIT_SCHED);

  th1 = (pthread_t *) malloc(sizeof(pthread_t));
  if (pthread_create(th1, &attr, odd, &max1)) {
    perror("error creating the first thread");
    exit(1);
  }
  printf("created the first thread\n");
 
  st2 = (void *)malloc(MYSTACKSIZE);
  pthread_attr_setstacksize(&attr, MYSTACKSIZE);
  pthread_attr_setstack(&attr, st2, MYSTACKSIZE);
  
  th2 = (pthread_t *) malloc(sizeof(pthread_t));
  if (pthread_create(th2, &attr, even, &max2)) {
    perror("error creating the second thread");
    exit(1);
  }
  printf("created the second thread\n");

  for (i = 0; i < 10; i++) {
    printf("main %d\n", i);
    sleep(1);
  }
  pthread_join(*th1, 0);
  pthread_join(*th2, 0);
}
