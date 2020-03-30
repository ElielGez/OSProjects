#include <stddef.h>
#include <stdbool.h>
#include <stdio.h>
#include <dlfcn.h>

void (*printHello)();

bool init_library(){
	void *hdl = dlopen("./libHelloAriel.so",RTLD_LAZY);
	if(hdl == NULL)
		return false;
	printHello = (void(*)())dlsym(hdl,"printHello");
	if(printHello == NULL)
		return false;
	return true;
}

int main(){
	if(init_library())
		printHello();
	else
		printf("Library was not loaded \n");
	return 0;
}
