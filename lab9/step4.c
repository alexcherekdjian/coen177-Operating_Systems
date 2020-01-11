// Name: Alex Cherekdjian
// Date: March 5, 2019
// Title: Lab9 – step4
// Description: reads a file from argv1 with buffer of argv2 and uses argv3 number threads to make n copies

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>

void *fileCopy(void *x);

int BUFFER_SIZE; // init buffer size

// structure for thread function definition
struct args 
{ 
   int i_val; // current file value
   char* file_arg; // file copy arg
};

int main(int argc, char* argv[]){

	int numThreads = atoi(argv[3]); // init num threads
	pthread_t threads[numThreads]; // init array of threads
	BUFFER_SIZE = atoi(argv[2]); // init buffer size
    
	for (int i = 0; i < numThreads; ++i){
		struct args *data = (struct args *)malloc(sizeof(struct args)); // create a structure
		data->file_arg = argv[1]; // assign file to file_arg
		data->i_val = i; // assign file number to ival
		pthread_create(&threads[i], NULL, &fileCopy, (void*) data); // create the thread
	}

	for (int i = 0; i < numThreads; ++i){
		pthread_join(threads[i], NULL); // join threads
	}
	
	return 0;
}

void *fileCopy(void *input){

	char buffer[BUFFER_SIZE]; // create buffer of size buffer
	int bytes = 0; // init bytes read
	char filename[80]; // init filename array

	sprintf(filename, "copy%d", ((struct args*)input)->i_val); // concatenate ival to keyword "copy"

	FILE *fptr_w = fopen(filename, "wb"); // init file pointer to write to
	FILE *fptr = fopen(((struct args*)input)->file_arg, "rb"); // init read pointer to read from

	while(1){
		bytes = fread(buffer, 1, BUFFER_SIZE,fptr); // read from file and store bytes

		if(bytes < BUFFER_SIZE){
			break; // if less than buffer == last read so break
		}

		fwrite(buffer, 1, BUFFER_SIZE, fptr_w);// write to other file
	}
	
	fclose(fptr_w); // close file pointers
	fclose(fptr);

	return NULL;
}