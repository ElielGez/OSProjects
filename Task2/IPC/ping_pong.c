#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>
#include <sys/wait.h>

#define STOP_NUMBER 5

int WAIT_FIRST_SIGNAL = 1;
int WAIT_SECOND_SIGNAL = 1;
int fd[2];
int counter;
pid_t id;


void parent_handler(int sign)
{

    if(sign == SIGUSR1){
        /* Read from pipe */
        read(fd[0],&counter,sizeof(counter));

        printf("%d\n",counter);
        counter++;
        if(counter == STOP_NUMBER)
            WAIT_FIRST_SIGNAL = 0;

        write(fd[1],&counter,sizeof(counter));
        kill(id,SIGUSR1);
    }
    else if(sign == SIGUSR2) {
        WAIT_FIRST_SIGNAL = 0;
        kill(id, SIGKILL);
    }
}

void child_handler(int sign)
{

    if(sign == SIGUSR1)
    {
        /* Read from pipe */
        read(fd[0],&counter,sizeof(counter));

        printf("%d\n",counter);
        counter++;

        if(counter - 1 == STOP_NUMBER) {
            WAIT_SECOND_SIGNAL = 0;
            return;
        }
        else{
            write(fd[1],&counter,sizeof(counter));
            kill(getppid(),SIGUSR1);
        }
         
    }
}

int main()
{
    /*Create pipe */
    if(pipe(fd) < 0){
        printf("Failed to create pipe..\n");
        return -1;
    }

//    printf("%d\n", getpid());
    pid_t pid = fork();
//    printf("%d\n", getpid());
    id = pid;

    if(pid == 0) {
        if(signal(SIGUSR1,child_handler) == SIG_ERR)
            printf("Error while creating signal...\n");

        counter = 0;
        write(fd[1],&counter,sizeof(counter));
        kill(getppid(),SIGUSR1);

        while(WAIT_SECOND_SIGNAL && counter != STOP_NUMBER);
        kill(getppid(),SIGUSR2);
    }
    else{
        if(signal(SIGUSR1,parent_handler)==SIG_ERR || signal(SIGUSR2,parent_handler)==SIG_ERR)
            printf("Error while creating signal...\n");

        while(WAIT_FIRST_SIGNAL && counter != STOP_NUMBER -1 );
        
        WAIT_FIRST_SIGNAL = 1;
        while (WAIT_FIRST_SIGNAL);
        
        printf("sleep of 5 seconds to check the command: cat /proc/%d/status | grep SigCgt\n",pid);
        sleep(5);
        printf("Child is terminated...\n");
        printf("Parent is terminated... \n");       

    }
    return 1;
}
