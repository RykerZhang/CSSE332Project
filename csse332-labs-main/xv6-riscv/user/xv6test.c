#include "kernel/param.h"
#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"
#include "kernel/fs.h"
#include "kernel/fcntl.h"
#include "kernel/syscall.h"
#include "kernel/memlayout.h"
#include "kernel/riscv.h"
#include <stddef.h>

int g = 8800;

void helloWorld(void *arg, void *arg2, void *arg3){
	
	printf("arg1: %d arg2: %d arg3: %d\n", *(int *)arg, *(int *)arg2, *(int *)arg3);
	printf("child: %d:\n", g);
	g++;
	sleep(5);
	printf("child new %d:\n", g);
	exit(1);
}


int main(int argc, char **argv){
	int test = 100;
	int test2 = 79;
	int test3 = 69;

	thread_create(1, helloWorld, &test, &test2, &test3);
	thread_create(2, helloWorld, &test, &test2, &test3);
	sleep(15);
	//thread_create(2, helloWorld, 0);

	//sleep(10);
	//if(g == 8800){
	//	printf();
	//}
	printf("%d\n", g);
	return 1;
}
