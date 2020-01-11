// Alex Cherekdjian
// COEN 177 (Lab #8)
// Tuesday 2:15pm
// February 26, 2019
// Description: Simulates secondChance paging algorithm

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

int main(int argc, char *argv[]){
    
	int cache_size = atoi(argv[1]); // get cache size
	int array [cache_size]; // array to store pages
	int second_chance_array[cache_size]; // array to hold 0 or 1
	int i; // loop var init
	int second_chance_tracker = 0; // track which variable we left on at the second chance marker
	int array_spots_used = 0; // keep track of number of elements used
	int page_num = 0; // init value from scanf
	
	for(i = 0; i < cache_size; i++){
		second_chance_array[i] = 0; // init all values in array to 0
	}

	while (scanf("%d", &page_num) != EOF){

		int index_found = 0;
		bool found = false;

		for (i = 0; i < array_spots_used; ++i){
			if(array[i] == page_num){
				index_found = i;
				found = true; // if value is found in the array, keep index and label true
				break;
			}
		}

		if(found){
			second_chance_array[index_found] = 1; // if value found, set in the second chance array to 1
			
		}else{
			// value not found so report page fault
			printf("Page %d caused a page fault.\n", page_num);
			if(array_spots_used < cache_size){
				array[array_spots_used] = page_num; // if the array is not full, add to the end
				array_spots_used++; // increment number used

			}else{

				for(i = second_chance_tracker; i < array_spots_used; i = i % cache_size){
					if(second_chance_array[i] == 1){
						second_chance_array[i] = 0;	// array is full. look through second chance array, if found 1, set to 0 and continue
						i++;
					
					}else{
						array[i] = page_num; // if found zero, then replace the value in array with the new page number
						second_chance_tracker = i; // init second chance tracker to value after insertion
						second_chance_tracker++;

						if(second_chance_tracker == cache_size){
							second_chance_tracker = 0; // if the tracker is out of bounds of array, then wrap it arround
						}

						break;
	
					}
					
				}
			}
		}
	}
    return 0;
}
