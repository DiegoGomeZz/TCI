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
	if(cad!=NULL){
		while(cad!=NULL && cad->dato!=bus){
			nodo=crea_nodo(cad->dato);
			agrega_por_cola(&nueCad, nodo);
			cad=cad->sig;
		}
	}
	else printf("  cadena vacia, no se puede aplicar 'before token'");
	return nueCad;
}
str conCat(str a, str b){
	str nueCad, nodo, aux;
	nueCad=create();
	if(a==NULL)
		nueCad=b;
	else if(b==NULL)
		nueCad=a;
	else if(a==NULL && b==NULL)
		nueCad=NULL;
	else{
		while(a!=NULL){
			nodo=crea_nodo(a->dato);
			agrega_por_cola(&nueCad, nodo);
			a=a->sig;
		}
		aux=nueCad;
		while(nueCad->sig!=NULL)
			aux=aux->sig;
		aux->sig=b;
	}
	return nueCad;
}
	
	
	
	
	
	
	
	
	
