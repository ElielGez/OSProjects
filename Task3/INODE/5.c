#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

int main( int argc, char *argv[] ) {
  int fd = open("hello.txt", O_RDWR | O_CREAT);

  if (argc != 2) {
      printf("\n Wrong number of parameters, pass one argument");
      return 0;
  }

  printf("\n pid = %d\n", getpid());
  printf(" fd = %d\n", fd);

  int n = atoi(argv[1]);
  lseek(fd, n, SEEK_SET);
  printf("\n Press any symbol once you grab lsof output");
  getchar();
  close(fd);
}

