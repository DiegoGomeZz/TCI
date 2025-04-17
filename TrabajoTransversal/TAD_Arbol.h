#ifndef TAD_ARBOL_H
#include "TAD_String.h"
#include "TAD_Lista.h"
#include "TAD_Set.h"
#define TAD_ARBOL_H

#define STR 1
#define LIS 2
#define SET 3

typedef struct dataType{
	int nodeType;
	union{
		str *dataStr;
		struct{
			struct dataType *dato;
			struct dataType *sig;
		};
	};
}dataType;

typedef dataType *TDA;

TDA free_load();
TDA crearNodoChar();
TDA crearNodoList();
TDA crearNodoSet ();
void show_tree(TDA);
#endif

/*nodo(dato)->nodo(dato)*/
/*arbol(nodo(dato))->arbol(nodo->nodo)*/
/*{a,b,c,[aa,bb,cc,dd,{1,2,3}][hola,vaca,casa]}*/
