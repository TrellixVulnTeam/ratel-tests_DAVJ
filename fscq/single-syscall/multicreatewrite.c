#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define LOOP_COUNT 10000

int
main(int ac, char** av)
{
  char* fn = av[1];

  for (int i = 0; i < LOOP_COUNT; i++) {
    int fd = open(fn, O_CREAT | O_RDWR | O_EXCL, 0666);
    if (fd < 0)
      perror("open");

    char buf[128];
    write(fd, buf, sizeof(buf));

    close(fd);

    unlink(fn);
  }
}
