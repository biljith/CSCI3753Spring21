#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>

main(int argc, char *argv[])

{
  int i, max = 100;
  FILE *fd;
  int mcpipe1[2], mcpipe2[2], num;

  mcpipe1[0] = atoi(argv[1]);
  mcpipe1[1] = atoi(argv[2]);
  mcpipe2[0] = atoi(argv[3]);
  mcpipe2[1] = atoi(argv[4]);
  close(mcpipe1[1]);
  close(mcpipe2[0]);
  close(mcpipe2[1]);
  fd = fopen("squares", "w");
  for (i = 0; i < max; i++) {
    read(mcpipe1[0], (char *)&num, sizeof(int));
    fprintf(fd, "%d\n", num * num);
  }
  fclose(fd);
}

