#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <stddef.h>

void print(const char *name)
{
    for(int i=0; i<10; i++)
    {
    usleep(100000);
    printf("Hello from %s \n", name);
    }
}

int main() 
{ 
    int pid, pid1, pid2; 
  
    // variable pid will store the 
    // value returned from fork() system call 
    pid = fork(); 
  
    // If fork() returns zero then it 
    // means it is child process. 
    if (pid == 0) { 
  
        // First child needs to be printed 
        // later hence this process is made 
        // to sleep for 3 seconds. 
    
  
        // This is first child process 
        // getpid() gives the process 
        // id and getppid() gives the 
        // parent id of that process. 
         char * args [] = {"./main2_1", NULL};
        execvp(args[0],args); 
    } 
  
    else { 
        pid1 = fork(); 
        if (pid1 == 0) {  
            char * args [] = {"./main2_2", NULL};
        execvp(args[0],args); 
        sleep(3);
        } 
        else { 
            pid2 = fork(); 
            if (pid2 == 0) { 
                // This is third child which is 
                // needed to be printed first.
                         char * args [] = {"./main2_3", NULL};
        execvp(args[0],args);  
                        sleep(4); 

            } 
  
            // If value returned from fork() 
            // in not zero and >0 that means 
            // this is parent process. 
            else { 
                // This is asked to be printed at last 
                // hence made to sleep for 3 seconds.  
                sleep(4); 
                print("parent");
            } 
        } 
    } 
    return 0;
} 

