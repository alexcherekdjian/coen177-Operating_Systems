// Name: Alex Cherekdjian
// Date: January 15, 2019
// Title: Lab2 – task4 
// Description: Creates two processes, child runs ls, parent waits till child is done then prints to command line then exits

#include <stdio.h>      /* printf, stderr */

#include <sys/types.h>  /* pid_t */

#include <unistd.h>     /* fork */

#include <stdlib.h>     /* atoi */

#include <errno.h>      /* errno */ 

/* main function with command-line arguments to pass */

int main(int argc, char *argv[]){

    pid_t  pid; // initialize fork variable
    int i, n = atoi(argv[1]); // n microseconds to input from keyboard for delay

    printf("\n Before forking.\n");

    pid = fork(); // fork program

    if (pid == -1) {
        fprintf(stderr, "can't fork, error %d\n", errno); // if error print message

    }
        
    if(pid == 0){
    	// child code
        execlp("/bin/ls", "ls", NULL);
        
    }else{
    	// parent code
        wait(NULL); // wait till child done
        printf("\nChild Complete\n");
        
        for (i=0;i<100;i++) {
            printf("\t \t \t Parent Process %d \n",i); // do parent process
            usleep(n); // sleep for n
        }
        
        exit(0); // exit program
    }

    return 0;
}
