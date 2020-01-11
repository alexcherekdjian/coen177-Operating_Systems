// Alex Cherekdjian
// COEN 177 (Lab #8)
// Tuesday 2:15pm
// February 26, 2019
// Description: Simulates FIFO paging algorithm

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

int main(int argc, char *argv[]){

	int cache_size = atoi(argv[1]); // cache size
	int array [cache_size]; // array to hold all pages
	int array_spots_used = 0; // keep track of array spots used
	int page_num = 0; // init value to store inputed page number
	int replace_pointer = 0; // index pointer to track where in array to replace

	while (scanf("%d", &page_num) != EOF){

		int i = 0;
		bool found = false;

		for (i = 0; i < array_spots_used; ++i){
			if(array[i] == page_num){
			   found = true; // if value found in the array label true
			}
		}
		
		if(found){
			continue; // if found continue to next value
			
		}else{
			// page fault made so report it
			printf("Page %d caused a page fault.\n", page_num);

			if(array_spots_used < cache_size){
				array[array_spots_used] = page_num; // if still space in array, insert at end
				array_spots_used++; // increment used

			}else{
				
				array[replace_pointer] = page_num; // array is full
				replace_pointer++; // increment the fifo pointer

				if(replace_pointer == cache_size){
					replace_pointer = 0; // if at out of bounds of array, loop around
				}

			}
		}

	}

    return 0;
}