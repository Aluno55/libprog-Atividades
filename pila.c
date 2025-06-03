#include <stdio.h>
#include <stdlib.h>
#include "libthings.h"

typedef struct LIFO {
    int*elemental;
    int top;
    int capacity;
} pill_t;

pill_t* creator() {
    pill_t *pillbug = (pill_t*) malloc(sizeof(pill_t));
    pillbug->elemental = (int*) malloc(sizeof(int)* INITIAL);
    pillbug->top = -1;
    pillbug->capacity = INITIAL;
    return pillbug;}

void push(pill_t* pinha, int value) {
    if (pinha->top+1 >= pinha->capacity) {
        printf("I'm filled to the brim!"); exit(EXIT_FAILURE);}
    pinha->elemental[pinha->top] = value;
    pinha->top++;}

int pop(pill_t* pinha) {
    int value = pinha->elemental[pinha->top];
    pinha->top--;
    if (pinha->top < 0) {
        printf("I'm empty!");exit(EXIT_FAILURE);}
        return value;}

void destruct(pill_t* pinha){
    free(pinha->elemental);
    free(pinha);
}
