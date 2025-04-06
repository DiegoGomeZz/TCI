#include "TAD_set.h"
#include <stdio.h>
#include <stdlib.h>

set createSet(){
	set conjunto;
	conjunto = NULL;
	return conjunto;
}
set creaNodoSet(str cad){
	set nodo;
	nodo = (set)malloc(sizeof(Tnodo2));
	nodo->dato = cad;
	nodo->sig = NULL;
	return nodo;
}
void agregar(set *conj, str cad){
	set nodo, aux;
	if(isInSet(*conj, cad)==0){
		nodo = creaNodoSet(cad);
		if(*conj!=NULL){
			aux=*conj;
			while(aux->sig!=NULL)
				aux=aux->sig;
			aux->sig = nodo;
		}
		else 
		   *conj = nodo;
	}
}
int isInSet(set conj, str cad){
	while( conj != NULL && strComp( conj->dato , cad) == 0)
		conj= conj->sig;
	if(conj!=NULL)
		return 1;
	else 
		return 0;
}
void showSet(set conj){
	if(conj!=NULL){
		printf("{ ");
		while(conj->sig!=NULL){
			printf("'");
			show(conj->dato);
			printf("' ");
			conj=conj->sig;
		}
		printf("'");
		show(conj->dato);
		printf("'");
		printf(" }");
	}
	else 
	   printf("\n\n conjunto vacio");
}
set interseccion(set a, set b){
	set conj;
	conj = createSet();
	while(a!=NULL){
		if(isInSet(b, a->dato)==1)
			agregar(&conj, a->dato);
		a = a->sig;
	}
	while(b!=NULL){
		if(isInSet(a, b->dato)==1)
			agregar(&conj, b->dato);
		b = b->sig;
	}
	return conj;
}
set unionSets(set a, set b){
	set conj, aux;
	conj=createSet();
	if(a==NULL) conj = b;
	else if(b==NULL) conj = a;
	else{
		aux=a;
		while(aux!=NULL){
			agregar(&conj, aux->dato);
			aux=aux->sig;
		}
		aux=b;
		while(aux!=NULL){
			agregar(&conj, aux->dato);
			aux=aux->sig;
		}
	}
	return conj;
}
set diferencia(set a, set b){
	set conj;
	conj = createSet();
	while(a!=NULL){
		if(isInSet(b, a->dato)==0)
			agregar(&conj, a->dato);
		a = a->sig;
	}
	return conj;
}
set strToSetToken(str cad, char token){
	set conj = createSet();
	str cadenita, nodoStr;
	cadenita = create();
	while(cad!=NULL){
		if(cad->dato!=token){
			nodoStr = crea_nodo(cad->dato);
			agrega_por_cola(&cadenita, nodoStr);
			cad=cad->sig;
		}
		else{
			agregar(&conj, cadenita);
			cad=cad->sig;
			cadenita = create();
		}
	}
	agregar(&conj, cadenita);
	return conj;
}
int contenido(set a, set b){
	int band=1;
	while(a!=NULL && band==1){
		if(isInSet(b,a->dato)==1)
			a=a->sig;
		else band=0;
	}
	return band;
}


















