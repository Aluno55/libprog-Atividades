#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libthings.h"

typedef struct FIFO {
    struct {
        char wordle[100], desc[280];
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
    return filha;}

void add(struct call c, queue_t * fila) {
    if (fila->counter >= fila->capacity) {
        int cap = fila->capacity, new = cap*2;
        fila->capacity *= 2;
        typeof(*fila->elements)* novo = malloc(sizeof(*fila->elements) * new);
        for (int i = 0; i < fila->counter; ++i) {
            int troço = (i+ fila->head) % cap;
            novo[i]= fila->elements[troço];}
        free(fila->elements);fila->elements=novo;
        fila->capacity= new; fila->head=0; fila->tail=fila->counter;}

    strcpy(fila->elements[fila->tail].wordle, c.name);
    strcpy(fila->elements[fila->tail].desc, c.info);
    fila->elements[fila->tail].priority = c.priority;
    fila->tail = (fila->tail+1)%fila->capacity;
    fila->counter++;}

char *removes(queue_t *fila) {
    if (fila->counter == 0) {
        printf("ERROR [UNDERFLOW]");
        return NULL;
    }
    char *valor = strdup(fila->elements[fila->head].wordle);
    fila->head = (fila->head + 1) % fila->capacity;
    fila->counter--;
    return valor;
}

void display(queue_t *f) {
    int coisa = f->head;
    for (int i = 0; i < f->counter; i++) {
        printf("Nome: %s\nNivel de Prioridade: %d\n", f->elements[coisa].wordle, f->elements[coisa].priority);
        printf("Descrição: %s\n", f->elements[coisa].desc);
        coisa=(coisa + 1) % f->capacity;}}

void destroy(queue_t* fia){free(fia->elements);free(fia);}

int vacuo(queue_t* f){return f->counter == 0;}