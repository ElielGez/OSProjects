#include <sched.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define SCHED_IDLE 5
#define SCHED_DEADLINE 6
 
 int main(int argc, char *argv[])
 {
   //  printf("SCHED_OTHER: %d\n",SCHED_OTHER); //  0 
   //  printf("SCHED_FIFO: %d\n",SCHED_FIFO); // 1
   //  printf("SCHED_RR : %d\n",SCHED_RR); // 2
   //  printf("SCHED_IDLE: %d\n",SCHED_IDLE); // 5
   //  printf("SCHED_DEADLINE : %d\n",SCHED_DEADLINE); // 6
    
    int policy = atoi(argv[1]);
    if(policy != SCHED_OTHER && policy != SCHED_FIFO && policy != SCHED_RR && policy != SCHED_IDLE && policy != SCHED_DEADLINE){
       printf("Please insert valid policy\n");
       return 1;
    }
    int priority = atoi(argv[2]);
    struct sched_param sp = { .sched_priority = priority };

    int result = sched_setscheduler(0, policy, &sp);
    if (result == -1) {
        printf("sched_setscheduler error , please check chrt -m to see min/max of priorties\n");
        return 1;
    }
    sleep(30000);
    return 0;
 }