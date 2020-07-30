#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main( int argc, char *argv[] ) {
  int fd = open("hello.txt", O_RDWR);// | O_CREAT);
  int newfd = dup(fd);

  printf("\n pid = %d\n", getpid());
  printf(" fd = %d\n", fd);
  printf(" newfd = %d\n", newfd);    
  char* s = "hello world\n";

  write(fd, s, strlen(s));
  lseek(fd, 5, SEEK_SET);
  printf("\n Enter any symbol once you run lsof");
  getchar();
  close(fd);
}
