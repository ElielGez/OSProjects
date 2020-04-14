#include <stdio.h>
#include <unistd.h>

int main(){	
	printf("%s","main2_1: father process\n");
	int pid = fork();

	if(pid == 0){
		fork();
		printf("%s","main2_1: child process\n");
	}
 	sleep(50);
	return 0;
}
