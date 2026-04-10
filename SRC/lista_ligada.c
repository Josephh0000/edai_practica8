#include <stdlib.h>
#include "lista_ligada.h"


Dlista* lista_crear() {
    Dlista *nueva_lista = (Dlista*)malloc(sizeof(Dlista));
    if (nueva_lista != NULL) {
        nueva_lista->head = NULL;
        nueva_lista->tail = NULL;
    }
    return nueva_lista;
}

bool lista_es_vacia(Dlista *l) {
    if (l == NULL) return true;
    return (l->head == NULL);
}

int lista_num_nodos(Dlista *l) {
    if (l == NULL) return 0; 
    
    int i = 0;
    for (Nodo *tmp = l->head; tmp != NULL; tmp = tmp->sig, i++);
    
    return i;
}



bool lista_insertar_vacia(Dlista *l, void *info, size_t size) {
    if (l == NULL || l->head != NULL) return false;

    Nodo *nuevo = nodo_crear(info, size);
    if (nuevo == NULL) return false;

    l->head = nuevo;
    l->tail = nuevo;
    return true;
}

bool lista_insertar_inicio(Dlista *l, void *info, size_t size) {
    if (l == NULL) return false;
    
    if (l->head == NULL) return lista_insertar_vacia(l, info, size);

    Nodo *nuevo = nodo_crear(info, size);
    if (nuevo == NULL) return false;

    nuevo->sig = l->head;
    l->head->ant = nuevo;
    l->head = nuevo; 
    return true;
}

bool lista_insertar_fin(Dlista *l, void *info, size_t size) {
    if (l == NULL) return false;

    if (l->head == NULL) return lista_insertar_vacia(l, info, size);

    Nodo *nuevo = nodo_crear(info, size);
    if (nuevo == NULL) return false;

    nuevo->ant = l->tail;
    l->tail->sig = nuevo;
    l->tail = nuevo; 
    return true;
}

bool lista_insertar_x_pos(Dlista *l, int pos, void *info, size_t size) {
    if (l == NULL || pos < 0) return false;

    if (pos == 0) return lista_insertar_inicio(l, info, size);

    Nodo *temp = l->head;
    int i = 0;

    while (temp != NULL && i < pos) {
        temp = temp->sig;
        i++;
    }

    if (temp == NULL) return lista_insertar_fin(l, info, size);

    Nodo *nuevo = nodo_crear(info, size);
    if (nuevo == NULL) return false;

    nuevo->sig = temp;
    nuevo->ant = temp->ant;
    
    if (temp->ant != NULL) {
        temp->ant->sig = nuevo;
    }
    temp->ant = nuevo;

    return true;
}
