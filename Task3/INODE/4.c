#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

int main( int argc, char *argv[] ) {
    int fd = open("hello.txt", O_RDWR | O_CREAT);

    printf("parent, pid = %d\n", getpid());
    printf("parent, fd = %d\n", fd);
    
    int forkId = fork();
    
    if (forkId == 0) {//child
      printf("\n child, pid = %d\n", getpid());
      printf(" child, fd = %d\n", fd);
      printf("\n Press any symbol once you grab lsof");
      getchar();
      exit(0);
    }

    lseek(fd, 5, SEEK_SET);
    //printf("\n Press any symbol once you grab lsof from parent");
    getchar();
    close(fd);
}

