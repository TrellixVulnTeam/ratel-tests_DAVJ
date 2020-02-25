#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define LOOP_COUNT 10000

int
main(int ac, char** av)
{
  char* base = av[1];

  for (int i = 0; i < LOOP_COUNT; i++) {
    char fn[256];
    sprintf(fn, "%s/f%d.txt", base, i);
    int fd = open(fn, O_CREAT | O_RDWR | O_EXCL, 0666);
    if (fd < 0)
      perror("open");

    close(fd);
  }
}
