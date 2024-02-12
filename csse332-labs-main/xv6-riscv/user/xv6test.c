#include "kernel/param.h"
#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"
#include "kernel/fs.h"
#include "kernel/fcntl.h"
#include "kernel/syscall.h"
#include "kernel/memlayout.h"
#include "kernel/riscv.h"
void helloWorld(void *arg){

	printf("Hello World");
}


int main(int argc, char **argv){


	thread_create(1, helloWorld, 0);
	return 1;
}
