// Name: Alex Cherekdjian
// Date: February 5, 2019
// Title: Lab5 
// Description: threadSyn.c - simple multi-threaded programi with sychronization.
// compile with: >gcc -lpthread threadSync.c -o threadSync           
// Winter 2019                                                      

#include <stdio.h>
#include <unistd.h>
#include <pthread.h> 
#include <semaphore.h> 
#include <stdlib.h>
#include <fcntl.h>

#define NUM_PRODUCERS 50
#define NUM_CONSUMERS 1
#define BUFF_SIZE 5

int buffer[BUFF_SIZE];
int producer_index;

pthread_t threadsProducers[NUM_PRODUCERS];
pthread_t threadsConsumers[NUM_CONSUMERS];

sem_t *mutex; 
sem_t *full;
sem_t *empty;

void* consumer(void* arg) { 

	do {
		int item_consumed;

	    sem_wait(full);
		sem_wait(mutex); //entry section
	    
		if(producer_index > 0){
	    	item_consumed = buffer[producer_index-1];
	    	producer_index--;
	    	printf("Consumer %d | Consumed item %d, stored in buff at index %d. \n", (int)arg, item_consumed, producer_index);
	    	fflush(stdout);

		}else{
			printf("consumer waiting . . .\n");
		}
	    
	    sem_post(mutex);
	    sem_post(empty);


	} while (1);
	
	sem_post(mutex); //exit section 

	return (NULL);
} 

void* producer(void* arg) { 

	do { 
		
		int item_produced = rand() & 100 + 0; // choose random number from 100 to 0

		sem_wait(empty);
		sem_wait(mutex); //entry section

		if(producer_index < BUFF_SIZE){
			buffer[producer_index] = item_produced;
			printf("Producer %d | Produced item %d, stored in buff at index %d. \n", (int)arg, item_produced, producer_index);
			producer_index++;
			fflush(stdout);

		}else{
			printf("producer waiting . . .\n");
		}
		

		sem_post(mutex);
		sem_post(full);

	} while (1);

	sem_post(mutex); //exit section 

	return (NULL);
} 


int main() {
	producer_index = 0;

	mutex = sem_open("Semaphore", O_CREAT, 0644, 1);
	full = sem_open("full",  O_CREAT, 0644, 1);
	empty = sem_open("empty",  O_CREAT, 0644, 1);
	
	sem_post(empty);
	sem_post(mutex);

	static int i;

	for (i = 0; i < NUM_PRODUCERS; i++){  
		pthread_create(&threadsProducers[i], NULL, producer, (void *)(size_t)i);
	}

	for (i = 0; i < NUM_CONSUMERS; i++){  
		pthread_create(&threadsConsumers[i], NULL, consumer, (void *)(size_t)i);
	}

	for (i = 0; i < NUM_CONSUMERS; i++) {
			pthread_join(threadsConsumers[i],NULL);
	}

	for (i = 0; i < NUM_PRODUCERS; i++) {
			pthread_join(threadsProducers[i],NULL);
	}

	printf("Main thread done.\n");
	sem_unlink("Semaphore"); 
	sem_unlink("empty"); 
	sem_unlink("full"); 
	return 0; 
} 

