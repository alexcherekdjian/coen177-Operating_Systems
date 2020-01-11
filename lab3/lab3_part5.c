// Name: Alex Cherekdjian
// Date: January 22, 2019
// Title: Lab3 -part 5
// Description: This program implements the producer-consumer message communication using pipes

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h> 
#include <string.h>
#include <sys/wait.h> 
// main
int main(int argc,char *argv[]){
   int  fds[2]; // init var fr pipe identifiers
   char buff[500]; // buffer for inputs
   int count; // var for while loop
   int i =0; // var for for loop
   pipe(fds);  // creating the pipe
   
   // strings for producer processes to send into pipe
   char stringOne[25] = "Hello from producer1\n";
   char stringTwo[25] = "Hello from producer2\n";

   if (fork()==0){
      // producer process 1
       close(fds[0]);
       
       while (i != 10){
       		write(fds[1], stringOne, (strlen(stringOne))); // write out string
       		usleep(1000);
			i++;
	   }
       exit(0);
   }
   else if(fork()==0){
       // producer process 2
       close(fds[0]);
       
       while (i != 10){
       		write(fds[1], stringTwo, (strlen(stringOne))); // write out string to same pipe
       		usleep(1000);
			i++;
	   }
	   
       exit(0);
    }
   else{
   	   // consumer process 1
       while((count=read(fds[0],buff,500))>0){
           for(i=0;i<count;i++){
               write(1,buff+i,1); // read out all values submitted from both children
           }
           printf("\n");
       }
   
      close(fds[0]);
      close(fds[1]);
      wait(0);
      wait(0);

   }
   

return 0;
}
