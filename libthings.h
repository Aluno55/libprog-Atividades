#ifndef LIBPRG_LIBPRG_H
#define LIBPRG_LIBPRG_H
#include <stdbool.h>

typedef struct FIFO queue_t;
queue_t* creation();
void add(int num, queue_t * fila);
int removes(queue_t* fila);
void destroy(queue_t* fia);

typedef struct LIFO pill_t;
pill_t* creator();
void push(pill_t* pinha, int value);
int pop(pill_t* pinha);
void destruct(pill_t* pinha);

typedef struct lista list_t;
list_t* create(bool order);
int ordoSearch(list_t* L, int val);
int search(list_t* L, int val)
void addlist(list_t* L, int val)
int remover(list_t* L, int val) {
void destruction(list_t* lia)

#endif
