#include <stdio.h>
#include <unistd.h>

void helloWorld(void *arg){

	printf("Hello World");
}


int main(int argc, char **argv){


	thread_create(1, helloWorld, 0);
	return 1;
}
