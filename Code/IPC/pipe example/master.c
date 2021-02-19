#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>


main()

{
  int max = 100, i, c1, c2;
  FILE *fd;
  int mcpipe1[2], mcpipe2[2], status;
  char mc0[10], mc1[10], cc0[10], cc1[10];

  if (c1 = pipe(mcpipe2)) /* Create a pipe for master and a child
                                                          process */ {
    perror("unable to create the first pipe");
    exit(1);
  }
  if (c1 = pipe(mcpipe1)) /* Create a pipe for master and the other
                                                    child process */ {
    perror("unable to create the second pipe");
    exit(1);
  }
  sprintf(mc0, "%d", mcpipe1[0]);
  sprintf(mc1, "%d", mcpipe1[1]);
  sprintf(cc0, "%d", mcpipe2[0]);
  sprintf(cc1, "%d", mcpipe2[1]);
  if ((c1 = fork()) == -1) /* Create the first child process */ {
    perror("unable to fork first child");
    exit(1);
  }
  else if (c1 == 0) {
    /* This is the first child process */
    printf("first child pid = %d\n", getpid());
    execl("sqr", "sqr", mc0, mc1, cc0, cc1, NULL);
    exit(1);
  }
  else {
    if ((c2 = fork()) == -1) /* Create the second child process */ {
      perror("unable to fork second child");
      exit(1);
    }
    else if (c2 == 0) {
      /* This is the second child process */
      printf("second child pid = %d\n", getpid());
      execl("cube", "cube", cc0, cc1, NULL);
      exit(1);
    }
  }
  close(mcpipe1[0]);
  close(mcpipe2[0]);
  fd = fopen("whole_num", "w");
  for (i = 0; i < max; i++) {
    fprintf(fd, "%d\n", i);
    write(mcpipe1[1], (void *)&i, sizeof(int));
    write(mcpipe2[1], (void *)&i, sizeof(int));
  }
  fclose(fd);
  wait(&status);
  wait(&status);
  printf("master pid = %d\n", getpid());
}

