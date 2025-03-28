#include "TAD_string.h"
#include <stdio.h>
#include <stdlib.h>

str create(){
	str cad;
	cad=NULL;
	return cad;
}
str crea_nodo(char c){
	str nodo;
	nodo=(str)malloc(sizeof(Tnodo));
	nodo->dato=c;
	nodo->sig=NULL;
	return nodo;
}
void agrega_por_cola(str *cad, str nodo){
	str aux;
	if(*cad==NULL)
		*cad=nodo;
	else{
		aux=*cad;
		while(aux->sig!=NULL)
			aux=aux->sig;
		aux->sig=nodo;
	}
}
str load(){
	char c;
	str nodo, lista;
	lista=create();
	c=getchar();
	fflush(stdin);
	while(c!='0'){
		nodo=crea_nodo(c);
		agrega_por_cola(&lista, nodo);
		c=getchar();
		fflush(stdin);
	}
	return lista;
}
str load2(const char* cad){
	int i=0;
	str nodo, lista;
	lista=create();
	while(cad[i]!='\0'){
		nodo=crea_nodo(cad[i]);
		agrega_por_cola(&lista, nodo);
		i++;
	}
	return lista;
}
void show(str lista){
	if(lista!=NULL){
		while(lista!=NULL){
			printf("%c",lista->dato);
			lista=lista->sig;
		}
	}
	else printf("\n cadena vacia");
}
str beforeToken(str cad, char bus){
	str nueCad, nodo;
	nueCad=create();
	while(cad!=NULL && cad->dato!=bus){
		nodo=crea_nodo(cad->dato);
		agrega_por_cola(&nueCad, nodo);
		cad=cad->sig;
	}
	return nueCad;
}
str afterToken(str cad, char bus){
	str nueCad, aux;
	nueCad=create();
	aux=cad;
	while(aux->dato!=bus && aux!=NULL)
		aux=aux->sig;
	if(aux!=NULL){
		aux=aux->sig;
		nueCad=aux;
	}
	return nueCad;
}
	str conCat(str a, str b){
		str nueCad, nodo, aux;
		if(a==NULL) return b;
		else if(b==NULL) return a;
		else{
			nueCad=create();
			while(a!=NULL){
				nodo=crea_nodo(a->dato);
				agrega_por_cola(&nueCad, nodo);
				a=a->sig;
			}
			while(b!=NULL){
				nodo=crea_nodo(b->dato);
				agrega_por_cola(&nueCad, nodo);
			}
			return nueCad;
		}
	}
	
	
	
	
	
	
	
	
	
