// Name: Alex Cherekdjian
// Date: March 5, 2019
// Title: Lab9 – step2
// Description: reads a file from argv1 with buffer of argv2

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]){

	int BUFFER_SIZE = atoi(argv[2]); // init buffer size
	char buffer[BUFFER_SIZE]; // init char buffer
    FILE *fptr; // init file pointer
	int bytes = 0; // init bytes

	fptr = fopen(argv[1], "rb"); // open file read only

	while(1){
		bytes = fread(buffer, 1, BUFFER_SIZE,fptr); // read from file and store #bytes

		if(bytes < BUFFER_SIZE){
			break; // if less than buffer == last read so break
		}
	}
	
	fclose(fptr); // close file
	return 0;
}
