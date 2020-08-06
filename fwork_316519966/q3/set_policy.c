#include <sched.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdint.h>
#include <linux/sched.h>
#include <sys/syscall.h>

#define SCHED_IDLE 5
#define SCHED_DEADLINE 6
static volatile int done;

// FOR DEADLINE POLICY
 struct sched_attr {
    uint32_t size;
    uint32_t sched_policy;
    uint64_t sched_flags;
    int32_t sched_nice;
    uint32_t sched_priority;
    uint64_t sched_runtime;
    uint64_t sched_deadline;
    uint64_t sched_period;
};
int sched_setattr(pid_t pid, 
          const struct sched_attr *attr, 
                          unsigned int flags) {
    return syscall(__NR_sched_setattr, pid, attr, flags);
}
void *run_deadline()
{
   struct sched_attr attr;
   int ret;
   attr.size = sizeof(attr);
   attr.sched_flags = 0;
   attr.sched_nice = 0;
   attr.sched_priority = 0;

   /* This creates a 10ms/30ms reservation */
   attr.sched_policy = SCHED_DEADLINE;
   attr.sched_runtime = 10 * 1000 * 1000;
   attr.sched_period = attr.sched_deadline = 30 * 1000 * 1000;

   ret = sched_setattr(0, &attr, 0);
   if (ret < 0) {
		done = 0;
		perror("deadline error");
		exit(-1);
	}
   return NULL;

}

 int main(int argc, char *argv[])
 {
   //  printf("SCHED_OTHER: %d\n",SCHED_OTHER); //  0 
   //  printf("SCHED_FIFO: %d\n",SCHED_FIFO); // 1
   //  printf("SCHED_RR : %d\n",SCHED_RR); // 2
   //  printf("SCHED_IDLE: %d\n",SCHED_IDLE); // 5
   //  printf("SCHED_DEADLINE : %d\n",SCHED_DEADLINE); // 6
    
    int policy = atoi(argv[1]);
    int priority = atoi(argv[2]);
    if(policy != SCHED_OTHER && policy != SCHED_FIFO && policy != SCHED_RR && policy != SCHED_IDLE && policy != SCHED_DEADLINE){
       printf("Please insert valid policy\n");
       return 1;
    }
    if(policy == SCHED_DEADLINE){
       run_deadline();
    }
    else{
       struct sched_param sp = { .sched_priority = priority };
       int result = sched_setscheduler(0, policy, &sp);
       if (result == -1) {
         printf("sched_setscheduler error , please check chrt -m to see min/max of priorties\n");
         return 1;
       }
    }
    sleep(5000);
    return 0;
 }