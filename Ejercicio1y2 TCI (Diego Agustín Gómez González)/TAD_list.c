#include "TAD_list.h"
#include <stdio.h>
#include <stdlib.h>

Tlist createList(){
	Tlist list;
	list=NULL;
	return list;
}
Tlist creaNodoList(str cad){
	Tlist nodo;
	nodo=(Tlist)malloc(sizeof(Tnodo2));
	nodo->dato = cad;
	nodo->sig = NULL;
	return nodo;
}
void aniadirPorCola(Tlist *list, Tlist nodo){
	Tlist aux;
	if(*list!=NULL){
		aux=*list;
		while(aux->sig!=NULL)
			aux=aux->sig;
		aux->sig = nodo;
	}
	else *list = nodo;
}
void aniadirElemento(Tlist *list, str cad){
	Tlist nodo;
	nodo = creaNodoList(cad);
	aniadirPorCola(list, nodo);
}
void showList(Tlist list){
	if(list!=NULL){
		printf("\n[ ");
		while(list->sig!=NULL){
			printf("'");
			show(list->dato);
			list=list->sig;
			printf("'");
			printf(", ");
		}
		printf("'");
		show(list->dato);
		printf("'");
		printf(" ]");
	}
	else printf("\n\n  lista vacia");
}
Tlist concatenar(Tlist a, Tlist b){
	Tlist nueList, nodo, aux;
	nueList=createList();
	if(a==NULL) nueList = b;
	else if(b==NULL) nueList = a;
	else{
		aux=a;
		while(aux!=NULL){
			nodo=creaNodoList(aux->dato);
			aniadirPorCola(&nueList, nodo);
			aux=aux->sig;
		}
		aux=b;
		while(aux!=NULL){
			nodo=creaNodoList(aux->dato);
			aniadirPorCola(&nueList, nodo);
			aux=aux->sig;
		}
	}
	return nueList;
}
Tlist strToList(str cad){
	Tlist lista, nodo;
	lista = createList();
	nodo = creaNodoList(cad);
	aniadirPorCola(&lista, nodo);
	return lista;
}
str listToStr(Tlist list){	
	str cad, nodo, aux;
	cad = create();
	while(list!=NULL){
		aux=list->dato;
		while(aux!=NULL){
			nodo = crea_nodo(aux->dato);
			agrega_por_cola(&cad, nodo);
			aux = aux->sig;
		}
		list=list->sig;
	}
	return cad;
}

	
	
	
	
	


