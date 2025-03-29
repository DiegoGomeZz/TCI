#ifndef TAD_LIST_H
#define TAD_LIST_H

#include "TAD_string.h"

typedef struct nodo2{
	str dato;
	struct nodo2 *sig;
}Tnodo2;
typedef Tnodo2 *Tlist;

Tlist createList();
void aniadirElemento(Tlist*, str);
Tlist concatenar(Tlist, Tlist);
void showList(Tlist);
Tlist strToList(str);
str listToStr(Tlist);





#endif
