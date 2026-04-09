#include "nodo.h"

Nodo *nodo_crear(void *info, size_t size){
    Nodo *n = (Nodo*)malloc(sizeof(Nodo));
    if (!n) return;
    n->info=malloc(size);

    if(!n->info { free(n); return}
    memcpy(n->info, info, size);
    n->ant=n->sig=NULL
}
void nodo_eliminiar(Nodo *nodo){
    if(!n){
        printf("No hay nodos a liberar \n")
    }else{
        free(n);
        n=NULL;
    }
}

bool nodo_actualizar(void *info, size_t size){
    nodo->info = realloc(nodo->info, size);
    if (!nodo->info) return false;
    memcpy(nodo->info, info, size);
}