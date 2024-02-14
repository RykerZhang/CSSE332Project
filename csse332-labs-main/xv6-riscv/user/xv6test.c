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
	//printf("arg1: %d arg2: %d arg3: %d\n", *(int *)arg, *(int *)arg2, *(int *)arg3);
	//printf("child: %d:\n", g);
	//g++;
	//printf("child new %d:\n", g);
	int hh = 1000;
	printf("Hello world %d\n", hh);
	hh = 1010;

	exit(0);
}

void goodbyeWorld(void *arg, void *arg2, void *arg3){
	//printf("arg1: %d arg2: %d arg3: %d\n", *(int *)arg, *(int *)arg2, *(int *)arg3);
	//printf("child: %d:\n", g);
	//g++;
	//printf("child new %d:\n", g);
	int hh = 0;
	sleep(10);
	printf("goodbye %d\n", hh);
	exit(0);
}
void main(int argc, char **argv){

	
	int test = 100;
	int test2 = 79;
	int test3 = 69;
//	int status;

	thread_create(0, helloWorld, &test, &test2, &test3);
	thread_create(0, goodbyeWorld, &test, &test2, &test3);
	//wait(&status);
	//thread_create(3, helloWorld, &test, &test2, &test3);
	//wait(&status);
	//thread_create(2, helloWorld, 0);

	sleep(15);
	//if(g == 8800){
	//	printf();
	//}
	printf("%d\n", g);
	exit(1);
}
