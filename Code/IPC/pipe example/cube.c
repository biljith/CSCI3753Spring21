#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

main(int argc, char *argv[])

{
  int i, max = 100;
  FILE *fd;
  int mcpipe2[2], num;

  mcpipe2[0] = atoi(argv[1]);
  mcpipe2[1] = atoi(argv[2]);

  fd = fopen("cubes", "w");
  for (i = 0; i < max; i++) {
    read(mcpipe2[0], (char *)&num, sizeof(int));
    fprintf(fd, "%d\n", num*num*num);
  }
  fclose(fd);
}
