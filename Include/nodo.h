#ifndef __NODO_H__
#define __NODO_H__

#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Nodo Nodo;

struct Nodo{
    void *info;
    Nodo *sig;
    Nodo *ant;
};

Nodo *nodo_crear(void *info, size_t size);
void nodo_eliminiar(Nodo *nodo);
bool nodo_actualizar(void *info, size_t size);

#endif