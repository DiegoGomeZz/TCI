#ifndef TAD_LIST_H
#define TAD_LIST_H

typedef struct nodo{
	str dato;
	struct nodo *sig;
}Tnodo;
typedef Tnodo *Tlist;

Tlist createList();
void añadirPorCola(Tlist*);
Tlist concatenar(Tlist, Tlist);
void showList();
str listToStr(Tlist);
Tlist strToList(str);
void append(Tlist*, str);



#endif
