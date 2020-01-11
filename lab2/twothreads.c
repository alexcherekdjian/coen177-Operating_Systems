// Name: Alex Cherekdjian
// Date: January 15, 2019
// Title: Lab2 – task2  
// Description: Creates two threading processes that print out to the commmand line

#include <stdio.h>      /* printf, stderr */

#include <sys/types.h>  /* pid_t */

#include <unistd.h>     /* fork */

#include <stdlib.h>     /* atoi */

#include <errno.h>      /* errno */ 

#include <pthread.h> // for thread command

/* main function with command-line arguments to pass */

void *printOne();
void *printTwo();
int n; // global time to delay

int main(int argc, char *argv[]){

	n = atoi(argv[1]); // n microseconds to input from keyboard for delay
    printf("\n Before threading.\n");
	
	// creating thread variables
	pthread_t thread1;
    pthread_t thread2;

   	// creating thread1, print if successful or error
    if(pthread_create(&thread1, NULL, &printOne, NULL)){
    	printf("ERROR creating thread1.\n");
	}else{
	    printf("Thread1 started\n");
	}

   	// creating thread2, print if successful or error
    if(pthread_create(&thread2, NULL, &printTwo, NULL)){
    	printf("ERROR creating thread2.\n");
	}else{
	    printf("Thread2 started\n");
	}
	
	// join both threads in order to make sure main doesnt quit until they are finished
	pthread_join(thread1,NULL);
	pthread_join(thread2,NULL);
	
    return 0;
}

void *printOne(){
		int i;
		for (i=0;i<100;i++) {
            printf("\t \t \t Thread1 Process %d \n",i); // print for thread 1
            usleep(n); // sleep
        }
}

void *printTwo(){
		int i;
		for (i=0;i<100;i++) {
            printf("\t \t \t Thread2 Process %d \n",i); // print for thread 2
            usleep(n); // sleep
        }
}
