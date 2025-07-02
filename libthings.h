#ifndef LIBPRG_LIBPRG_H
#define LIBPRG_LIBPRG_H

typedef struct call {
    char name[100];
    char info[280];
    char priority[50];
};

typedef struct FIFO queue_t;
queue_t* creation();
void add(struct call c, queue_t * fila);
char* removes(queue_t* fila, char* val); //val = priority
void destroy(queue_t* fia);
int vacuo(queue_t* f);

typedef struct LIFO pill_t;
pill_t* creator();
void push(pill_t* pinha, char* value);
char *pop(pill_t* pinha);
void destruct(pill_t* pinha);
int vazio(pill_t* p);

typedef struct lista list_t;
list_t* create();
void addlist(list_t* L, char* val);
void destruction(list_t* lia);
int tama(list_t* l);
void history(list_t* l);

#endif
