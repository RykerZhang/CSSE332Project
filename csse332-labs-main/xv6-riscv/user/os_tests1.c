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

int g = 10;


void test_func1(void *arg) {
	//printf("first thread with arg: %d\n", *(int *)arg);
        t_exit(0);
}

void test_func2(void *arg, void *arg2) {
        int first = *(int *)arg;
	int second = *(int *)arg2;
        if(first == 1 && second == 2) {
          printf("Test passed!\n");
        } else {
          printf("Test failed!\n");
        }

        t_exit(0);
}

void test_func3(void *arg1, void *arg2, void *arg3) {

        int first = *(int *)arg1, second = *(int *)arg2, third = *(int *)arg3;
        int sum = first + second + third;

        if(first == 1 && second == 2 && third == 3 && sum == 6) {
          printf("Test passed!\n");
        } else {
          printf("Test failed!\n");
        }

        t_exit(0);
}

void test_func4(void *arg1){
	int d = g;
	printf("Global variable g is: %d. ", g);
	if(d == 10){
		printf("Test passed!\n");
	} else {
		printf("Test failed!\n");
	}
	t_exit(0);
}



void test_func5(void *arg1){
	printf("Global variable g was: %d. ", g);
	g++;
	printf("g is now increased by 1!\n ");
	t_exit(0);
}


void test_func6(void *arg1){
	printf("Global variable g is: %d. ", g);
	if(g == 11){
		printf("Test passed!\n");
	}else {
		printf("Test failed!\n");
	}
	t_exit(0);
}


void test_thread_create_1() {
        // Test 1
        // test if thread_create works
        printf("Testing [thread_create_1] Test 1: ");
        if(thread_create(0, test_func1, NULL, NULL, NULL) >= 0) {
           printf("Test passed!\n");
        } else {
           printf("Test failed!\n");
        }
	thread_join(0);
        // Test 2
        // test if thread_create can take one argument
        int var1 = 1;
	int var2 = 2;
        printf("Testing [thread_create_1] Test 2: ");
        thread_create(1, test_func2, &var1, &var2, NULL);
	thread_join(1);
        // Test 3
        // test if thread_create can take multiple arguments
        int var3 = 2;
        int var4 = 3;

        printf("Testing [thread_create_1] Test 3: ");
        thread_create(2, test_func3, &var1, &var3, &var4);
	thread_join(2);




        printf("Testing [thread_create_1] Test 4: ");
        thread_create(3, test_func4, NULL, NULL, NULL);
	thread_join(3);



        printf("Testing [thread_create_1] Test 5: ");
        thread_create(4, test_func5, NULL, NULL, NULL);
	thread_join(4);


        thread_create(5, test_func6, NULL, NULL, NULL);
	thread_join(5);

}

void main(int argc, char **argv){
	//int arg1 = 10;
	//int arg2_1 = 1;
	//int arg2_2 = 2;
        //thread_create(1, test_func1, &arg1, NULL, NULL);
	//thread_join(1);
        //thread_create(2, test_func2, &arg2_1, &arg2_2, NULL);
	//thread_join(2);
	test_thread_create_1();
	printf("All tests Done for features 1 - 6\n");

}
