// Name: Alex Cherekdjian
// Date: January 29, 2019
// Title: Lab4 – task 3
// Description: threadHello.c - simple multi-threaded program that computes matrix multiplication 
//              compile with: >gcc -lpthread threadHello3.c -o threadHello3
//              Winter 2019      

#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE 1024

void matrixMultiplyOneThread();
void* matrixMultiplyTwoThreads(void *);
void isCorrect();
void matrixPrint(float x[][SIZE]);
void initMatrices();
int irand(int start, int end);

float a[SIZE][SIZE], b[SIZE][SIZE], c[SIZE][SIZE], d[SIZE][SIZE]; // init arrays
pthread_t threads[SIZE]; // init thread array

int main() {
    int i;

    initMatrices(); // initiliazing arrays with values
    matrixMultiplyOneThread(); // get initial result with single array
    
    // create the threads
    for (i = 0; i < SIZE; i++){ 
        pthread_create(&threads[i], NULL, matrixMultiplyTwoThreads, (void *)(size_t)i);
    }

    // join the threads
    for (i = 0; i < SIZE; i++) {
        pthread_join(threads[i],NULL);
    }

    // print out results
    printf("A:\n");
    matrixPrint(a);

    printf("B:\n");
    matrixPrint(b);

    printf("C:\n");
    matrixPrint(c);

    printf("D:\n");
    matrixPrint(d);

    // test correctness
    isCorrect();
}

void initMatrices(){
    int i,j;
    for (i = 0; i < SIZE; i++){
        for (j = 0; j < SIZE; j++){

            // init a and b with random numbers from 0-5
            a[i][j] = (float)irand(0, 5);
            b[i][j] = (float)irand(0, 5);

            // init final arrays with zeros
            c[i][j] = (float)0.0;
            d[i][j] = (float)0.0;
        }
    }
}

 void matrixMultiplyOneThread(){
    int i,j,k;
    for (i = 0; i < SIZE; i ++){
        for (j = 0; j < SIZE; j ++){
            for (k = 0; k < SIZE; k++){
                c[i][j] += a[i][k] * b[k][j]; // calculate the entire matrix
            }
        }
    }
}

 void* matrixMultiplyTwoThreads(void *i){
    int j,k;
    int x = (int)i; // casting pointer to int

    for (j = 0; j < SIZE; j ++){
        for (k = 0; k < SIZE; k++){
            d[x][j] += a[x][k] * b[k][j]; // calculate a row of a matrix
        }
    }
    return (NULL);
}

void isCorrect(){
    bool incorrect = false;
    int i,j;

    for (i = 0; i < SIZE; ++i){
        for (j = 0; j < SIZE; ++j){
            if(c[i][j] != d[i][j]){
                incorrect = true; // if incorrect set flag
            }
        }
    }

    // if flag is up, notify user it is incorrect
    if(incorrect)
        printf("Not Correct!\n");
    else
        printf("It's Correct!\n");
}

void matrixPrint(float x[][SIZE]){
    int i,j;

    // utility print function for matrices
    for (i = 0; i < SIZE; i++){
        for (j = 0; j < SIZE; j++){
            printf ("%.2f ",x[i][j]); // print out floats to 2 decimals
        }
        printf("\n");
    }
    printf("\n");
}

int irand(int start, int end){
    int range = end - start + 1;
    
    return rand() & range + start; // creates random numbers from start to end 

}