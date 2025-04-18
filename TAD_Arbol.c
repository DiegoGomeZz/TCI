
#include "TAD_Arbol.h"

TDA start_tree(){
	
	return NULL;
	
}

	
TDA crearNodoChar(){
	TDA nuevo;
	nuevo=(struct dataType *) malloc(sizeof(struct dataType));
	/*	nuevo->dataStr=load2("Hello Motherfuckers");*/
	nuevo->dataStr=load();
	nuevo->nodeType=STR;
	return nuevo;
}
	
TDA crearNodoList (TDA L1){
	TDA nuevo;
	nuevo=(struct dataType *) malloc(sizeof(struct dataType));
	nuevo->dato=L1;
	nuevo->nodeType=LIS;
	return nuevo;
}

TDA crearNodoSet (TDA S1){
	TDA nuevo;
	nuevo=(struct dataType*) malloc(sizeof(struct dataType));
	nuevo->dato=S1;
	nuevo->nodeType=SET;
	return nuevo;
}

/*TDA free_load_list(TDA *A1){*/
/*	int op;*/
/*	TDA aux=*A1;*/
/*		printf("\n Ingrese el tipo de dato a almacenar: ");*/
/*		printf("\n 1_ Tipo de Dato: Strng.");*/
/*		printf("\n 2_Tipo de Dato: List.");*/
/*		printf("\n 3_ Tipo de Dato: Set.");*/
/*		printf("\n Su eleccion: ");*/
/*		scanf("%d", &op);*/
/*		switch(op){*/
/*		case 1: {*/
/*			if(aux==NULL){*/
/*				aux=crearNodoChar();*/
/*				aux=aux->sig;*/
/*				break;*/
/*			}*/
/*			else {*/
/*				while(aux->sig!=NULL){*/
/*					aux=aux->sig;*/
/*				}*/
/*				aux->sig=crearNodoChar();*/
/*				break;*/
/*			}*/
/*		}*/
/*		case 2: {*/
/*			if(aux==NULL){*/
/*				aux=crearNodoList();*/
/*				aux->dato=free_load(&aux);*/
/*				break;*/
/*			}*/
/*			else{*/
/*				while (aux->sig!=NULL){*/
/*					aux=aux->sig;*/
/*				}*/
/*				aux->sig=crearNodoList();*/
/*				aux=aux->sig;*/
/*				aux->dato=free_load(&aux);*/
/*				break;	*/
/*			}*/
/*		}*/
		
/*		case 3:{*/
/*			while(aux->sig!=NULL){*/
/*				aux=aux->sig;*/
/*			}*/
/*			aux->sig=crearNodoSet();*/
/*			aux=aux->sig;*/
/*			break;*/
/*		}*/
/*	}*/
/*	return  aux;*/
/*}*/

TDA free_load(TDA *A1){
	int op;
	TDA aux;
	aux=*A1;
		printf("\n Ingrese el tipo de dato a almacenar: ");
		printf("\n 1_ Tipo de Dato: Strng.");
		printf("\n 2_Tipo de Dato: List.");
		printf("\n 3_ Tipo de Dato: Set.");
		printf("\n Su eleccion: ");
		scanf("%d", &op);
		switch(op){
			case 1: {
				if(aux==NULL){
					aux=crearNodoChar();
					break;
				}
				else{
					TDA aux1=aux;
					while(aux1->sig!=NULL){
						aux1=aux1->sig;
					}
					aux1->sig=crearNodoChar();
					aux1=aux1->sig;
					break;
				}
				break;
			}
			case 2: {
				if(aux==NULL){
					int n=0;
					printf("ingrese cantidad de elementos a almacenar en la lista: ");
					scanf("%d", &n);
					while(n>0){
						aux=crearNodoList(free_load(&aux));
						n--;
					}
					break;
				}
				else {
					TDA aux1=aux;
					while (aux1->sig!=NULL){
						aux1=aux1->sig;
					}
					int n=0;
					printf("ingrese cantidad de elementos a almacenar en la lista: ");
					scanf("%d", &n);
					while(n>0){
						aux1->sig=crearNodoList(free_load(&aux1->sig));
						n--;
					}
/*					aux=aux->sig;*/
/*					printf("ingrese cantidad de elementos a almacenar en la lista: ");*/
/*					scanf("%d", &n);*/
/*					while(n>0){*/
/*					aux->dato=free_load(&aux);*/
/*					n--;*/
/*					}*/
					break;
				}
			}
			case 3:{
				if(aux==NULL){
					int n=0;
					printf("ingrese cantidad de elementos a almacenar en el Conjunto: ");
					scanf("%d", &n);
					while(n>0){
						aux=crearNodoSet(free_load(&aux));
						n--;
					}
					break;
				}
				else {
					TDA aux1=aux;
					while (aux1->sig!=NULL){
						aux1=aux1->sig;
					}
					int n=0;
					printf("ingrese cantidad de elementos a almacenar en el Conjunto: ");
					scanf("%d", &n);
					while(n>0){
						aux1->sig=crearNodoSet(free_load(&aux1->sig));
						n--;
					}
				break;
			}
		}
	}
	return aux;
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
/*				printf(", ");*/
				printf("]");
				break;
			}
			case 3:{
				TDA auxs=aux;
				printf("{");
/*				printf("\n Conjunto dentro del arbol: ");*/
				show_tree(auxs->dato);
/*				printf(", ");*/
				printf("}");
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
