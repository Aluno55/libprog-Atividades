#include <stdio.h>
#include <stdlib.h>
#include "libthings.h"

typedef struct FIFO {
    char**elements;
    int head, tail, counter, capacity, priority;
} queue_t;

queue_t* creation(){
    queue_t* filha = (queue_t*) malloc(sizeof(queue_t));
    filha->elements = (char**) malloc(sizeof(char*)*1);
    filha->head=0;
    filha->priority=0;
    filha->tail=0;
    filha->capacity=1;
    filha->counter=0;
    return filha;
}

//probably need to use malloc for pointers?
void add(char* word, queue_t * fila) {
    if (fila->counter >= fila->capacity) {
        fila->capacity *= 2;
        fila->elements = (char**) realloc(fila->elements, sizeof(char*)*fila->capacity);
    }
    fila->elements[fila->tail] = word;
    fila->tail = (fila->tail+1)%fila->capacity;
    fila->counter++;
}

char* removes(queue_t* fila) {
    if (fila->counter == 0){printf("ERROR [UNDERFLOW]");
        exit(EXIT_FAILURE);}
    char* valor = fila->elements[fila->head];
    fila->head = (fila->head+1)%fila->capacity;
    fila->counter--;
    return valor;
}

void destroy(queue_t* fia){
    free(fia->elements);
    free(fia);
}
