#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>
#include <sys/wait.h>
 
 int main(int argc, char *argv[])
 {
     int pid = atoi(argv[1]);
     int signal_type = atoi(argv[2]); // 2 - SIGINT , 10 - SIGUSR1
     int amount = atoi(argv[3]);
     if(!pid || !signal_type || !amount) {
         printf("Please insert numbers only");
         return 0;
     }
     printf("pid: %d, signal_type: %d, amount: %d \n",pid,signal_type,amount);
     if(signal_type == SIGINT){
         printf("Starting sending server SIGINT... \n");
         while(amount > 0){
             kill(pid,SIGINT);
             amount--;
         }
         printf("Finishing sending server SIGINT... \n");
         return 0;
     }
     else if(signal_type == SIGUSR1){
         printf("Starting sending server SIGUSR1... \n");
         kill(pid,SIGUSR1);
         printf("Finishing sending server SIGUSR1... \n");
         return 0;
     }
     return 0;
 }