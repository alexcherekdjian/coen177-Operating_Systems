// Name: Alex Cherekdjian
// Date: January 29, 2019
// Title: Lab4 – task 2
// Description: threadHello.c - simple multi-threaded program without the join function  
//              compile with: >gcc -lpthread threadHello2.c -o threadHello2
//              Winter 2019      

#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

#define NTHREADS 10

void *go(void *);
pthread_t threads[NTHREADS];// init thread array

int main() {
    static int i;

    // creating the threads
    for (i = 0; i < NTHREADS; i++)  
        pthread_create(&threads[i], NULL, go, (void *)(size_t)i);

    printf("Main thread done.\n");
}
void *go(void *arg) {
    // function to print out thread ID and self
    printf("Hello from thread %d with thread ID %d \n", (int)arg, (int)pthread_self());
    return (NULL);
}

