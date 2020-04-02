#define _GNU_SOURCE
#include <stdio.h>
#include <sched.h>
#include <stdlib.h>
#include <sys/wait.h>

int secondProcessFn(void *arg){
	printf("main1_2: Hello from second process\n");
	int i = 0;
	int n = atoi(arg);
	for(i=1;i<=10;i++)
		printf("%d + %d = %d\n",n,i,n+i);
	return 0;
}

int main(int arc, char *argv[]){
	printf("main1_2: Hello parent app is running\n");
	void *pchild_mem = malloc(1024*1024);
	if(pchild_mem == NULL){
		printf("ERROR: unable to allocate memory\n");
		exit(EXIT_FAILURE);
	}
	int pid = clone(secondProcessFn,pchild_mem + (1024*1024),SIGCHLD, argv[1]);
	if(pid < 0){
		printf("ERROR: unable to create the second process\n");
		exit(EXIT_FAILURE);
	}
	wait(NULL);
	free(pchild_mem);
	return 0;
}
