#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <strings.h>
#include <sys/time.h>
#include <string.h>
#include <stdint.h>
#include "stats.h"

#define BUFSIZE 1024
char buf[BUFSIZE];
char name[BUFSIZE];
static char *prog_name;
static char *topdir;

#define NITER 100
#define DOSTATS 0


static uint64_t
usec_now()
{
  struct timeval tv;

  gettimeofday(&tv, NULL);

  uint64_t res = tv.tv_sec;
  res *= 1000000;
  res += tv.tv_usec;
  return res;
}

int main(int argc, char **argv)
{
  int fd;
  int r;
  int i;
  int iter;
  uint64_t start, end;

  sprintf(name, "%s/write1", argv[1]);
  prog_name = argv[0];
  topdir = argv[1];

  printf("%s %s\n", prog_name, topdir);
  printf("%s %s\n\n",__DATE__, __TIME__);
  printf ( "Running write1 test on %s\n", argv[0] );
  printf ( "File Size = %d bytes\n", BUFSIZE );
  printf ( "Iterations = %d bytes\n\n", NITER );
  printf ( "Iteration    Time(usec) \n" );
  printf ( "---------    --------- \n" );

  for (iter = 0; iter < NITER; iter++) {

    if((fd = open(name, O_CREAT | O_TRUNC | O_RDWR, 0666)) < 0) {
      perror("open");
      exit(1);
    }

#if DOSTATS
    printstats(argv[1], 1);
#endif
    
    start = usec_now();

    for (i = 0; i < BUFSIZE; i++) buf[i] = 'a';

    if ((r = write(fd, buf, BUFSIZE)) < 0) {
      perror("write");
      exit(1);
    }

#if DOSTATS
    printstats(argv[1], 0);
#endif
  
    end = usec_now();
    printf ( "%d\t\t%ld\n", iter, end-start );

    if ((r = close(fd)) < 0) {
      perror("close");
    }

    if ((r = unlink(name)) < 0) {
      perror("unlink");
    }

  }

  return 0;
}
