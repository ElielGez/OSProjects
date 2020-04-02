#include <stdio.h>
#include <unistd.h>

int main(){
	fork();
	printf("%s","main1_1: my app 2 processes is running\n");
	return 0;
}
