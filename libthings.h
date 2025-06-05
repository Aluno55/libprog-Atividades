#ifndef LIBPRG_LIBPRG_H
#define LIBPRG_LIBPRG_H
#include <stdbool.h>

typedef struct FIFO queue_t;
queue_t* creation();
void add(char* word, queue_t * fila);
char* removes(queue_t* fila);
void destroy(queue_t* fia);

typedef struct LIFO pill_t;
pill_t* creator();
void push(pill_t* pinha, char* value);
char *pop(pill_t* pinha);
void destruct(pill_t* pinha);

typedef struct lista list_t;
list_t* create();
int search(list_t* L, const char* val);
void addlist(list_t* L, char* val);
char* remover(list_t* L, char* val);
void destruction(list_t* lia);

#endif