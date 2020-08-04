#include <stdio.h>
#include <signal.h>
#include <unistd.h>
int SIGINT_COUNTER = 0;  
 
void SIGINTHandler(int signum) {
  SIGINT_COUNTER++;
}
void SIGUSR1Handler(int signum) {
  printf("\n Number of SIGINT that recieved is: %d \n", SIGINT_COUNTER);
}
 
int main () {
printf("Server is starting...\n");
  signal(SIGINT, SIGINTHandler);
  signal(SIGUSR1, SIGUSR1Handler);
 
  while (1) {
  }
}