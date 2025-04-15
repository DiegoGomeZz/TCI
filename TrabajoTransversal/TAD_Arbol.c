
#include "TAD_Arbol.h"

TDA start_tree(){
	
	return NULL;
	
}
TDA free_load(int ce, TDA *A1){
	int op;
	TDA aux;
	aux=*A1;
	
	if(ce==0){
		
		return *A1;
		
	}
	else if(ce>0){
		
		printf("\n Ingrese el tipo de dato a almacenar: ");
		printf("\n 1_ Tipo de Dato: Strng.");
		printf("\n 2_Tipo de Dato: List.");
		printf("\n 3_ Tipo de Dato: Set.");
		printf("\n Su eleccion: ");
		scanf("%d", &op);
		switch(op){
			case 1: {
				while(aux->sig!=NULL){
					aux=aux->sig;
				}
				aux->sig=crearNodoChar();
				ce--;
				free_load(ce,&aux);
				break;
			}
			case 2: {
				list L1;
				L1=create_list();
				while (aux->sig!=NULL){
					aux=aux->sig;
				}
				aux->sig=crearNodoList(L1);
				ce--;
				free_load(ce,&aux);
				break;
			}
			case 3:{
				while(aux->sig!=NULL){
					aux=aux->sig;
				}
				set S1;
				S1=create_set();
				aux->sig=crearNodoSet(S1);
				ce--;
				free_load(ce,&aux);
				break;
			}
		}
	}
	return aux;
}

TDA crearNodoChar(){
	TDA nuevo;
	nuevo=(struct dataType *) malloc(sizeof(struct dataType));
/*	nuevo->dataStr=load2("Hello Motherfuckers");*/
	nuevo->dataStr=load();
	nuevo->nodeType=STR;
	nuevo->sig=NULL;
	return nuevo;
}

TDA crearNodoList (list* L1){
	TDA nuevo;
	nuevo=(struct dataType *) malloc(sizeof(struct dataType));
	nuevo->dato=L1;
	nuevo->nodeType=LIS;
	nuevo->sig=NULL;
	return nuevo;
}
	
TDA crearNodoSet (set* S1){
	TDA nuevo;
	nuevo=(struct dataType*) malloc(sizeof(struct dataType));
	nuevo->dato=S1;
	nuevo->nodeType=SET;
	nuevo->sig=NULL;
	return nuevo;
}

void show_tree(TDA arbol){
	TDA aux=arbol;
	printf("{ ");
	while(aux->sig!=NULL){
		switch(aux->nodeType){
			case 1: {
/*				printf("\n Cadena dentro del arbol: ");*/
				print(aux->dataStr);
				printf(", ");
				break;
			}
			case 2: {
/*				printf("\n Lista dentro del arbol: ");*/
				show(aux->dataStr);
				printf(", ");
				break;
			}
			case 3:{
/*				printf("\n Conjunto dentro del arbol: ");*/
				show_set(aux->dataStr);
				printf(", ");
				break;
			}
		}
		aux=aux->sig;
	}
	switch(aux->nodeType){
		case 1: {
/*			printf("\n Cadena dentro del arbol: ");*/
			print(aux->dataStr);
			break;
		}
		case 2: {
/*			printf("\n Lista dentro del arbol: ");*/
			show(aux->dataStr);
			break;
		}
		case 3:{
/*			printf("\n Conjunto dentro del arbol");*/
			show_set(aux->dataStr);
			break;
		}
	}
	printf(" }\n");
}
/*arbol(nodo(dato,dataStr)->nodo(dato,dataStr)->nodo(dato,dataStr)->NULL)->arbol(nodo(dato,dataStr)->NULL)*/
/*[a,b,c{aa,bb,cc},d,e]*/
/*arbol(nodoList(nodo,a)->nodoList(nodoList,b)->nodoList(nodoSet,c)->nodoSet(nodoSet,aa)->nodoSet(nodoSet,bb)->*/
/*nodoSet(nodoList,cc)->nodoList(nodoList,d)->nocoList(NULL,e))*/
