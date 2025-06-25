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
    return lisa;
}

int search(list_t* L, char* val) {
    for (int i = 0; i < L->tam; i++) {
        if (strcmp(L->elementar[i], val) == 0) {
            return i;
        }
    }
    return -1;}

void addlist(list_t* L, char* val) {
    if (L->tam >= L->cap) {
        L->cap *= 2;
        L->elementar = realloc(L->elementar, sizeof(char*) * L->cap);
    }
    L->elementar[L->tam] = strdup(val);
    L->tam++;
}

char* remover(list_t* L, char* val) {
    int position = search(L, val);
    if (position == -1) return NULL;

    char* removed = L->elementar[position];
    for (int i = position; i < L->tam - 1; i++) {
        L->elementar[i] = L->elementar[i + 1];
    }
    L->tam--;
    return removed;}

int listless(list_t* L){return L->tam == 0;}

void history(list_t* l){
    for (int i = 0; i < l->tam; i++){
        printf("%s\n", l->elementar[i]);
    }}

int tama(list_t* l){return l->tam;}

void destruction(list_t* lia){
    for (int i = 0; i < lia->tam; i++) {free(lia->elementar[i]);}
    free(lia->elementar);
    free(lia);
}
