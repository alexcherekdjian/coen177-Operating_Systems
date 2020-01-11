// Alex Cherekdjian
// COEN 177 (Lab #8)
// Tuesday 2:15pm
// February 26, 2019
// Description: Simulates LRU paging algorithm

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

int main(int argc, char *argv[]){
	int cache_size = atoi(argv[1]); // get cache size
	int array [cache_size]; // array to store pages
	int lru_array[cache_size]; // array to hold clock count
	int i; // loop var init
	int clock = 1;// clock variable
	int array_spots_used = 0; // keep track of number of elements used
	int page_num = 0; // init value from scanf
	
	for(i = 0; i < cache_size; i++){
		lru_array[i] = 0; // init all values in array to 0
	}
		
	while (scanf("%d", &page_num) != EOF){

		int index_found = 0;
		bool found = false;
		
		for (i = 0; i < array_spots_used; ++i){
			if(array[i] == page_num){
				index_found = i; // if page found, store index and label true
				found = true;
			}
		}
		
		if(found){
			lru_array[index_found] = clock; // if found, assign clock value to lru array and increment clock
			clock++;
			
		}else{
			// value not found so report page fault
			printf("Page %d caused a page fault.\n", page_num);
			if(array_spots_used < cache_size){
				array[array_spots_used] = page_num; // if array still empty, assign new page to last element in array
				lru_array[array_spots_used] = clock; // assign it to clock
				clock++; // inc clock
				array_spots_used++; // inc number spots used in array

			}else{
				
				int smallest = lru_array[0]; 
				int min_index = 0;
				
				for(i = 1; i < cache_size; i++){
					if(lru_array[i] < smallest){
						smallest = lru_array[i]; // if array is full, find the smallest clock value
						min_index = i; // keep smallest clock value index
					}
				}
				
				array[min_index] = page_num; // replace at the smallest value index the new page
				lru_array[min_index] = clock; // replace at the smallest value index the clock
				clock++; // increment the clock
				
			}
		}
	}
    return 0;
}
