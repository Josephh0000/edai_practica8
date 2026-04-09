#include "lista_ligada.h"

int lista_num_nodos(Dlista *l){
    int i=0
    for(Nodo *tmp = l->head; tmp !=NULL;tmp->sig, i++);
    return i;git
}