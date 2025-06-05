#include <stdio.h>
#include <stdlib.h>
#include "libthings.h"

typedef struct FIFO {
    struct {
        char* wordle;
        int priority;
    } *elements;
    int head, tail, counter, capacity;
} queue_t;

queue_t* creation(){
    queue_t* filha = (queue_t*) malloc(sizeof(queue_t));
    filha->elements = malloc(sizeof(*filha->elements) * 1);
    filha->head=0;
    filha->tail=0;
    filha->capacity=1;
    filha->counter=0;
    return filha;
}

//probably need to use malloc for pointers?
void add(char* word, int hier, queue_t * fila) {
    if (fila->counter >= fila->capacity) {
        fila->capacity *= 2;
        fila->elements = realloc(fila->elements, sizeof(*fila->elements) * fila->capacity);
    }
    fila->elements[fila->tail].wordle = word;
    fila->elements[fila->tail].priority = hier;
    fila->tail = (fila->tail+1)%fila->capacity;
    fila->counter++;
}

char* removes(queue_t* fila, pill_t* pinha, char* action) {
    if (fila->counter == 0){printf("ERROR [UNDERFLOW]");
        exit(EXIT_FAILURE);}
    char* valor = fila->elements[fila->head].wordle;
    fila->head = (fila->head+1)%fila->capacity;
    fila->counter--;
    push(pinha, action);
    return valor;
}

void destroy(queue_t* fia){
    free(fia->elements);
    free(fia);
}