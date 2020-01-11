// Name: Alex Cherekdjian
// Date: January 22, 2019
// Title: Lab3 -part 3
// Description: This program creates two pipes through forking and passes the ls command to the upstream end of the pipe

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h> 
#include <string.h>
#include <sys/wait.h> 
// main
int main(int argc,char *argv[]){
   int  fds[2]; // creating pipe variable
   char buff[60]; // creating the buffer
   int count; // count var for while loop
   int i; // i for for loop
   pipe(fds); // creating the pipe   
   
   if (fork()==0){
       printf("\nWriter on the upstream end of the pipe -> %d arguments \n",argc);
       close(fds[0]); // closing f[0] end of pipe

       dup2(fds[1],1); // instead of outting to standard stream, send as input to fds[1]
       execlp("ls", "ls", 0); // sending ls command
 
       exit(0);
   }
   else if(fork()==0){
       printf("\nReader on the downstream end of the pipe \n");
       close(fds[1]); // closing f[1] end of pipe
       
       while((count=read(fds[0],buff,60))>0){
           for(i=0;i<count;i++){
               write(1,buff+i,1); // writing out to buffer
               write(1," ",1);

           }
       }
       exit(0); // exiting
    }
   else{     
      close(fds[0]);
      close(fds[1]);
      wait(0);
      wait(0);
   }
return 0;
}
