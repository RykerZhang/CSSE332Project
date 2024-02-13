#include "kernel/param.h"
#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"
#include "kernel/fs.h"
#include "kernel/fcntl.h"
#include "kernel/syscall.h"
#include "kernel/memlayout.h"
#include "kernel/riscv.h"

int g = 8800;

void helloWorld(void *arg){
	
	printf("arg: %d\n", *(int *)arg);
	g++;
	return;
}


int main(int argc, char **argv){
	int test = 100;
	
	thread_create(1, helloWorld, &test);
	sleep(15);
	//thread_create(2, helloWorld, 0);

	//sleep(10);
	//printf("%d\n", g);
	return 1;
}
