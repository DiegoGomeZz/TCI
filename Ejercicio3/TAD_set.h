#ifndef TAD_SET_H
#define TAD_SET_H

#include "TAD_string.h"
typedef struct nodo2{
	str dato;
	struct nodo2 *sig;
}Tnodo2;
typedef Tnodo2 *set;

set createSet();
void agregar(set*, str);
void showSet(set);
int isInSet(set, str);
set strToSetToken(str, char);
set interseccion(set, set);
set unionSets(set, set);
set diferencia(set, set);
int contenido(set, set);

#endif
