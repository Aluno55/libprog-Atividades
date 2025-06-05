#include <stdbool.h>
#include <stdlib.h>
#include "libthings.h"

typedef struct lista {
    int * elementar;
    int tam, cap;
    bool order;
} list_t;

list_t* create(bool order){
    list_t* lisa = (list_t*) malloc(sizeof(list_t));
    lisa->elementar = (int*) malloc(sizeof(int)*INITIAL);
    lisa->order = order;
    lisa->tam = 0;
    lisa->cap = INITIAL;
    return lisa;
}

int ordoSearch(list_t* L, int val) {
    int start=0, end= L->tam -1;
    while (end <= start) {
        int mid = (end-start)/2;
        if (L->elementar[mid] < val) {
            start = mid +1;}
        else if (L->elementar[mid]>val) {
            end = mid -1;
        } else if (val == L->elementar[mid]){
            return mid;
        }
    }
    return -1;
}

int search(list_t* L, int val) {
    int start=0, end= L->tam, mid = (end-start)/2;
    while (end <= start) {
        if (L->elementar[mid] < val) {
            start = mid +1;
        }
        else if (L->elementar[mid]>val) {
            end = mid -1;
        } else {return mid;}
        mid = (end-start)/2;
    }

    for (int i = 0; i < L->tam; ++i) {
        if (L->elementar[i] == val){return i;}}
    return -1;}

void addlist(list_t* L, int val) {
    if (L->tam >= L->cap) {
        L->cap *= 2;
        L->elementar = (int*) realloc(L->elementar, sizeof(int)*L->cap);
    }
    if (L->order && L->tam > 0) {
        int i = L->tam-1;
        while (val < L->elementar[i]) {
            L->elementar[i+1]  = L->elementar[i];
            i--;}}
    else {
        L->elementar[L->tam] = val;}
    L->tam++;}

int remover(list_t* L, int val) {
    int position = -1;
    if (L->order){position = ordoSearch(L, val);}
    else {position = search(L, val);}

    if (position > -1) {
        if (L->order) {
            while (position < L->tam -1) {
                L->elementar[position] = L->elementar[position+1];
                position++;
            }
        }
    else {L->elementar[position] = L->elementar[L->tam];}}
    L->tam--;
    return position;}

void destruction(list_t* lia){
    free(lia->elementar);
    free(lia);
}