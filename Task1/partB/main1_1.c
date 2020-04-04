#include <stdio.h>
#include <unistd.h>

int main(){	
	printf("%s","main1_1: father process\n");
	int pid = fork();
	printf("%s","main1_1: child process\n");
	if(pid == 0){
		fork();
		printf("%s","main1_1: grand-child process\n");
	}
//	sleep(50);
	return 0;
}
