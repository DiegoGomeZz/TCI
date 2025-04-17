
#include "TAD_Arbol.h"

TDA start_tree(){
	
	return NULL;
	
}

TDA free_load_list(TDA *A1){
	int op;
	TDA aux=*A1;
	TDA nuevo=start_tree();
	
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
			nuevo=crearNodoChar();
			aux->sig=nuevo;
			break;
		}
		case 2: {
			while (aux->sig!=NULL){
				aux=aux->sig;
			}
			nuevo=crearNodoList();
			nuevo->sig=free_load_list(&nuevo);
			break;
		}
		
		case 3:{
			while(aux->sig!=NULL){
				aux=aux->sig;
			}
			aux->sig=crearNodoSet();
			break;
		}
	}
	return  aux;
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
				if(aux==NULL){
					aux->sig=crearNodoChar();
					aux=aux->sig;
					ce--;
					break;
				}
				else{
					while(aux->sig!=NULL){
						aux=aux->sig;
					}
					aux->sig=crearNodoChar();
					aux=aux->sig;
					ce--;
					break;
				}
			}
			case 2: {
				while (aux->sig!=NULL){
					aux=aux->sig;
				}
				int n=0;
				aux->sig=crearNodoList();
				ce--;
				aux=aux->sig;
				printf("ingrese cantidad de elementos a almacenar en la lista: ");
				scanf("%d", &n);
				while(n>0){
				aux->dato=free_load_list(&aux);
				n--;
				}
				break;
			}
			case 3:{
				while(aux->sig!=NULL){
					aux=aux->sig;
				}
				aux->sig=crearNodoSet();
				ce--;
				aux=aux->sig;
				aux->dato=free_load_list(&A1);
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

TDA crearNodoList (){
	TDA nuevo;
	nuevo=(struct dataType *) malloc(sizeof(struct dataType));
	nuevo->dato=NULL;
	nuevo->nodeType=LIS;
	nuevo->sig=NULL;
	return nuevo;
}
	
TDA crearNodoSet (){
	TDA nuevo;
	nuevo=(struct dataType*) malloc(sizeof(struct dataType));
	nuevo->dato=NULL;
	nuevo->nodeType=SET;
	nuevo->sig=NULL;
	return nuevo;
}

void show_tree(TDA arbol){
	TDA aux=arbol;
	while(aux->sig!=NULL){
		switch(aux->nodeType){
			case 1: {
				print(aux->dato);
				printf(", ");
				break;
			}
			case 2: {
				TDA auxl=aux;
				printf("[");
				show_tree(auxl->dato);
				printf(", ");
				printf("]");
				break;
			}
			case 3:{
				TDA auxs=aux;
/*				printf("\n Conjunto dentro del arbol: ");*/
				show_tree(auxs->dato);
				printf(", ");
				break;
			}
		}
		aux=aux->sig;
	}
	switch(aux->nodeType){
		case 1: {
			print(aux->dato);
			break;
		}
		case 2: {
			TDA auxl=aux;
/*			printf("\n Lista dentro del arbol: ");*/
			show_tree(auxl->dato);
			break;
		}
		case 3:{
			TDA auxs=aux;
/*			printf("\n Conjunto dentro del arbol");*/
			show_tree(auxs->dato);
			break;
		}
	}
/*	printf(" }\n");*/
}
/*arbol(nodo(dato,dataStr)->nodo(dato,dataStr)->nodo(dato,dataStr)->NULL)->arbol(nodo(dato,dataStr)->NULL)*/
/*[a,b,c{aa,bb,cc},d,e]*/
/*arbol(nodoList(nodo,a)->nodoList(nodoList,b)->nodoList(nodoSet,c)->nodoSet(nodoSet,aa)->nodoSet(nodoSet,bb)->*/
/*nodoSet(nodoList,cc)->nodoList(nodoList,d)->nocoList(NULL,e))*/
