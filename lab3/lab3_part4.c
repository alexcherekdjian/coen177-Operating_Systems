// Name: Alex Cherekdjian
// Date: January 22, 2019
// Title: Lab3 -part 4
// Description: This program implements the shell command cat/etc/passwd | grep root

#include <sys/types.h> 
#include <sys/ipc.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h> 
#include <sys/wait.h> 

int main() {
	int fds[2];
	pipe(fds);
	
	/*child 1 duplicates downstream into stdin */
	if (fork() == 0) {
		dup2(fds[0], 0);
		close(fds[1]);
		execlp("grep","grep","root", 0); // use whats in the stream as input for grep and root as argument
	}
	/*child 2 duplicates upstream into stdout */
	else if (fork() == 0) {
		dup2(fds[1], 1);
		close(fds[0]);
		execlp("cat","cat","/etc/passwd", 0); // send the cat command with arg /etc/passwd to downstream child 1
	}
	
	else { /*parent closes both ends and wait for children*/
		close(fds[0]);
		close(fds[1]);
		wait(0);
		wait(0); 
	}
	return 0;
}
