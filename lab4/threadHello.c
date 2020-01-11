// Name: Alex Cherekdjian
// Date: January 29, 2019
// Title: Lab4 – task 1
// Description: threadHello.c - simple multi-threaded program.  
//              compile with: >gcc -lpthread threadHello.c -o threadHello
//              Winter 2019                                              

#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

#define NTHREADS 10

void *go(void *);
pthread_t threads[NTHREADS]; // init thread array

int main() {
    static int i;
    
    // creating the threads
    for (i = 0; i < NTHREADS; i++)  
        pthread_create(&threads[i], NULL, go, (void *)(size_t)i);

    // joining threads
    for (i = 0; i < NTHREADS; i++) {
        pthread_join(threads[i],NULL);
	    printf("Thread %d returned \n", i);
    }

    printf("Main thread done.\n");
}
void *go(void *arg) {
    // function to print out thread ID and self
    printf("Hello from thread %d with thread ID %d \n", (int)arg, (int)pthread_self());
    return (NULL);
}

