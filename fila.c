#include <stdio.h>
#include <stdlib.h>
#include "libthings.h"

typedef struct FIFO {
    int*elements;
    int capacity, head, tail, counter;
} queue_t;

queue_t* creation(){
    queue_t* filha = (queue_t*) malloc(sizeof(queue_t));
    filha->elements = (int*) malloc(sizeof(int)*INITIAL);
    filha->head=0;
    filha->tail=0;
    filha->capacity=INITIAL;
    filha->counter=0;
    return filha;
}

void add(int num, queue_t * fila) {
    if (fila->counter==fila->capacity) {
        printf("ERROR [OVERFLOW]");
        exit(EXIT_FAILURE);}
    fila->elements[fila->tail]=num;
    fila->tail++%fila->capacity;
    fila->counter++;
}

int removes(queue_t* fila) {
    if (fila->counter == 0){printf("ERROR [UNDERFLOW]");
        exit(EXIT_FAILURE);}
    int valor = fila->elements[fila->head];
    fila->head++%fila->capacity;
    fila->counter--;
    return valor;
}

void destroy(queue_t* fia){
    free(fia->elements);
    free(fia);
}
