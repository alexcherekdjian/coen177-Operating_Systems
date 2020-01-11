// Name: Alex Cherekdjian
// Date: January 22, 2019
// Title: Lab3 -part 1
// Description: This program creates two child streams that duplicate the stin and stout down and upstreams
 
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
		execlp("sort", "sort", 0); 
	}
	/*child 2 duplicates upstream into stdout */
	else if (fork() == 0) {
		dup2(fds[1], 1);
		close(fds[0]);
		execlp("ls", "ls", 0); 
	}
	
	else { /*parent closes both ends and wait for children*/
		close(fds[0]);
		close(fds[1]);
		wait(0);
		wait(0); 
	}
	return 0;
}
