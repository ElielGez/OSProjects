#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main( int argc, char *argv[] ) {
  
    int fd = open("hello.txt", O_RDWR | O_CREAT);
    int fd2 = open("hello.txt", O_RDWR | O_CREAT);

    printf("\n pid = %d\n", getpid());
    printf(" fd = %d\n", fd);
    printf(" fd2 = %d\n", fd2);

    lseek(fd, 5, SEEK_SET);
    printf("\n Press any symbol once you grab lsof output");
    getchar();
    close(fd);
    close(fd2);
}
