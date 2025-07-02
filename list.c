#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libthings.h"

typedef struct lista {
    char** elementar;
    int tam, cap;
} list_t;

list_t* create(){
    list_t* lisa = (list_t*) malloc(sizeof(list_t));
    lisa->elementar = (char**) malloc(sizeof(char*)*1);
    lisa->tam = 0;
    lisa->cap = 1;
    return lisa;}

void addlist(list_t* L, char* val) {
    if (L->tam >= L->cap) {L->cap *= 2;
        L->elementar = realloc(L->elementar, sizeof(char*) * L->cap);}
    L->elementar[L->tam] = strdup(val);
    L->tam++;}

void history(list_t* l){for (int i = 0; i < l->tam; i++){printf("%s\n", l->elementar[i]);}}

int tama(list_t* l){return l->tam;}

void destruction(list_t* lia){
    for (int i = 0; i < lia->tam; i++) {free(lia->elementar[i]);}
    free(lia->elementar);free(lia);}
