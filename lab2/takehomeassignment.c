// Name: Alex Cherekdjian
// Date: January 15, 2019
// Title: Lab2 – task3 
// Description: Makes a binary tree of seven node processes 

#include <stdio.h>      /* printf, stderr */

#include <sys/types.h>  /* pid_t */

#include <unistd.h>     /* fork */

#include <stdlib.h>     /* atoi */

#include <errno.h>      /* errno */ 

/* main function with command-line arguments to pass */

int main(void){

    pid_t  pid1, pid2, pid3, pid4, pid5, pid6;

    printf("\n Parent Process 1\n");
	
    pid1 = fork(); // fork initial branch (right child of root)
    if(pid1){printf("\n %d\n", pid1);} // print id if created
	
	// left branch
 	if(pid1 > 0){
 		pid2 = fork(); // for root create the left child
 		if(pid2){printf("\n %d \n", pid2);} // print id if created
 	
 	 	if(pid2 == 0){
		pid3 = fork(); // from left root child, create first child
			if(pid3){printf("\n %d \n", pid3);} // print id if created
			
			if(pid3 > 0){
				pid4 = fork(); // from left root child, create second child
				if(pid4){printf("\n %d \n", pid4);} // print id if created
			}	
		}
 	}
 	
 	// right branch
 	if(pid1 == 0){
 		pid5 = fork(); // for right root child, create first child
 		if(pid5){printf("\n %d \n", pid5);} // print id if created
 		
 		if(pid5 > 0){
 			pid6 = fork(); // for right root child, create second child
 			if(pid6){printf("\n %d \n", pid6);} // print id if created	 		
 		}
 	
 	}
 
    return 0;
}
