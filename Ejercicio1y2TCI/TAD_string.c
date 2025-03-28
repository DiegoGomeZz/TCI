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
	str nueCad, nodo, aux;
	nueCad=create();
	aux=cad;
	while(aux!=NULL && aux->dato!=bus){
		nodo=crea_nodo(aux->dato);
		agrega_por_cola(&nueCad, nodo);
		aux=aux->sig;
	}
	return nueCad;
}
str afterToken(str cad, char bus){
	str nueCad, aux, nodo;
	nueCad=create();
	aux=cad;
	while(aux->dato!=bus && aux->sig!=NULL)
		aux=aux->sig;
	aux=aux->sig;
	while(aux!=NULL){
		nodo=crea_nodo(aux->dato);
		agrega_por_cola(&nueCad, nodo);
		aux=aux->sig;
	}
	return nueCad;
}
str conCat(str a, str b){
	str nueCad, nodo, aux;
	nueCad=create();
	if(a==NULL) nueCad = b;
	else if(b==NULL) nueCad = a;
	else{
		aux=a;
		while(aux!=NULL){
			nodo=crea_nodo(aux->dato);
			agrega_por_cola(&nueCad, nodo);
			aux=aux->sig;
		}
		aux=b;
		while(aux!=NULL){
			nodo=crea_nodo(aux->dato);
			agrega_por_cola(&nueCad, nodo);
			aux=aux->sig;
		}
	}
	return nueCad;
}
	
	
	
	
	
	
	
	
	
