#include <stdio.h>
#include <stdlib.h>
#include "libthings.h"

typedef struct LIFO {
    char* *elemental;
    int top, capacity;
} pill_t;

pill_t* creator() {
    pill_t *pillbug = (pill_t*) malloc(sizeof(pill_t));
    pillbug->elemental = (char**) malloc(sizeof(char*)* 1);
    pillbug->top = -1;
    pillbug->capacity = 1;
    return pillbug;}

void push(pill_t* pinha, char* value) {
    if (pinha->top +1 >= pinha->capacity) {
        pinha->capacity *= 2;
        pinha->elemental = (char**) realloc(pinha->elemental, sizeof(char*)*pinha->capacity);}
    pinha->top++;
    pinha->elemental[pinha->top] = value;
}

char *pop(pill_t* pinha) {
    if (pinha->top < 0) {printf("empty");return NULL;}
    char* value = pinha->elemental[pinha->top];
    pinha->top--;
    return value;
}

void destruct(pill_t* pinha){
    free(pinha->elemental);
    free(pinha);
}

int vazio(pill_t* p) {return p->top == -1;}
