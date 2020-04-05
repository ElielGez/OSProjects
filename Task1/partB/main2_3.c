#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <syslog.h>
#include <string.h>

int main(void){
	printf("main1_3: Hello from app with deamon thread\n");
	pid_t pid, sid;
	pid = fork();
	if(pid>0){
		exit(EXIT_SUCCESS);
	}
	
	umask(0);

	sid = setsid();
	printf("my pid is: %d\n",getpid());

	if((chdir("/")) < 0) exit(EXIT_FAILURE);

	
	close(STDIN_FILENO);
	close(STDOUT_FILENO);
	close(STDERR_FILENO);
	

	while(1){
		printf("I am a deamon process ... \n");
		printf("Saying hello ... \n");
		sleep(2);
	}
	exit(EXIT_SUCCESS);
	return 0;
}
