// Name: Alex Cherekdjian
// Date: March 5, 2019
// Title: Lab9 – step3
// Description: reads a file from argv1 with buffer of argv2 and writes to another file

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]){

	int BUFFER_SIZE = atoi(argv[2]); // init buffer size
	char buffer[BUFFER_SIZE]; // init char buffer
	int bytes = 0; // init bytes

    FILE *fptr = fopen(argv[1], "rb"); // open file read only
	FILE *fptr_w = fopen("test", "wb"); // open file write only

	while(1){
		bytes = fread(buffer, 1, BUFFER_SIZE,fptr); // read from file and store bytes

		if(bytes < BUFFER_SIZE){
			break; // if less than buffer == last read so break
		}

		fwrite(buffer, 1, BUFFER_SIZE, fptr_w); // write to other file
	}

	fclose(fptr); // close file pointers
	fclose(fptr_w);
	return 0;
}
