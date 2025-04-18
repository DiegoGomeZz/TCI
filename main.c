/*#include "TAD_String.h"*/
/*#include "TAD_Lista.h"*/
#include "TAD_Arbol.h"
#include <windows.h>


void menu_list(str*,str*,str*,list*,list*, set, set, TDA*);
void menu_set(str*,str*,str*,list*,list*, set, set, TDA);
void menu_string(str*,str*,str*,list*,list*, set, set, TDA);
void menu(str*,str*,str*,list*,list*, set, set, TDA*); /*Declaracion del menu recursivo, utilizando como puntero las variables creadas en el main*/

int main(){	
	set S1,S2;
	list L1, L2, L3; /*Declaro dos listas para hacer que una de ellas cargue elementos a travez del teclado y la otra para que almacene la String convertida en Lista*/
	str cad1,cad2,cad3; /*Declaro 3 variables de tipo String*/
	TDA A1=NULL;
	cad2=load2("Hola Mundo"); /*Inicializo cad2*/
	menu(&cad1,&cad2,&cad3,&L1,&L2,S1,S2,&A1);/*Invoco el menu recursivo encargado de manejar el programa*/
	return 0;
}

void menu_arbol(str *cad1,str *cad2,str *cad3, list *L1, list *L2, set S1, set S2, TDA *A1){
	int op;
	printf("\n \n Seleccione la accion a realizar: ");
	printf("\n 1_ Realizar diferencia.");
	printf("\n 2_ Realizar union.");
	printf("\n 3_ Realizar interseccion.");
	printf("\n 4_ Mostrar el Arbol.");
	printf("\n 5_ Carga libre.");
	printf("\n 0_ Volver al menu principal.");
	printf("\n Su eleccion: ");
	scanf("%d", &op);
	switch(op){
		case 1: {
			break;
		};
		case 2:{
			break;
		};
		case 3:{
		
		};
		case 4:{
			show_tree(*A1);
			menu_arbol(cad1,cad2,cad3,L1,L2,S1,S2,A1);
			break;
		};
		case 5: {
			*A1=free_load(A1);
			menu_arbol(cad1,cad2,cad3,L1,L2,S1,S2,A1);
/*			list L3;*/
/*			A1=crearNodoChar();*/
/*			L3=Strtolist(A1->dato);*/
/*			A1->sig=crearNodoList(L3);*/
/*			printf("\n Lista resultante de convertir la cadena ingresada en lista: ");*/
/*			show(L3);*/
/*			printf("\n Arbol resultante: ");*/
/*			show_tree(A1);*/
			printf("\n Presione ENTER para limpiar la pantalla");
			fflush(stdin);
			getchar();
			system("cls");
			break;
		};
		case 0: {
			menu(cad1,cad2,cad3,L1,L2,S1,S2,A1);
			break;
		};
	}
	
}

void menu_list(str *cad1,str *cad2,str *cad3, list *L1, list *L2, set S1, set S2, TDA *A1){
	int op;
	printf("\n Seleccione la accion a realizar: ");
	printf("\n 1- Ingresar una Lista de Strings por teclado.");
	printf("\n 2- Mostrar la Lista de Strings ingresada por teclado.");
	printf("\n 3- Anexar una String a una Lista y Mostrar el cambio.");
	printf("\n 4- Convertir una Lista pasada por parametro en String y mostrar la String resultante.");
	printf("\n 0- Volver al menu principla.");
	printf("\n Su eleccion: ");
	scanf("%d",&op); /*Almaceno la decision del usuario en la variable opcion declarada previamente*/
	
	switch(op){
		
	case 1: { /*Case encargado de almacenar los String ingresados por teclado en una Lista*/
		*L1=create_list(); /*Inicializo L1 utilizando el metodo "create_list" del "TAD Lista"*/
		system("cls"); /*Utilizo el metodo "system" con la propiedad "cls" para limpiar la consola y que la vista del usuario no este sobrecargada de informacion
		irrelevante*/
		menu_list(cad1,cad2,cad3,L1,L2,S1,S2,A1); /*Llamada recursiva del menu*/
		break;
	}
	case 2: { /*Case encargado de mostrar la lista de los Strings ingresados por teclado posteriormente*/
		printf("\n Lista ingresada: ");
		show(*L1); /*Utilizo el metodo "show" del "TAD Lista"*/
		printf("\n");
		menu_list(cad1,cad2,cad3,L1,L2,S1,S2,A1); /*Llamada recursiva del menu*/
		break;
	}
	case 3: { /*Case encargado de hacer el anexo de una String nueva a una Lista previamente creada*/
		if((*L1)->dat == NULL){ /*Condicion impuesta de control para verificar que haya una lista a la cual cargar la String*/
			printf("\n Lista vacia, cargue una lista primero. \n");
			menu_list(cad1,cad2,cad3,L1,L2,S1,S2,A1);/*Llamada recursiva del menu*/
			break;
		}
		else if((*cad1)->dat == ' '){ /*Condicion impuesta de control para verificar que la String ingresada no sea vacia o que en efecto se haya cargado alguna
		String*/
			printf("\n String vacia, cargue una String primero. \n");
			menu_list(cad1,cad2,cad3,L1,L2,S1,S2,A1); /*Llamada recursiva del menu*/
			break;
		}
		else{	/*En caso de que ambas condiciones de control sean satisfechas, entonces se procede a hacer el anexo*/		
			printf("\n Lista antes de anexar: ");
			show(*L1); /*Muestro la lista antes del anexo utilizando el metodo "show" del "TAD Lista"*/
			printf("\n Lista despues de anexar: ");
			append(L1, *cad1);/*Utilizo el metodo "append" del "TAD Lista"*/
			show(*L1);/*Utilizo el metodo "show" del "TAD Lista"*/
			printf("\n");
			menu_list(cad1,cad2,cad3,L1,L2,S1,S2,A1);/*Llamada recursiva del menu*/
			break;
		}
	}
	case 4: { /*Case encargado de la conversion de una Lista a una String*/
		list aux=*L1; /*Se declara e inicializa una nueva lista auxiliar que permitira trabajar mas comodo con el manejo de los datos*/
		if(aux->dat == NULL){ /*Condicion impuesta de control para controlar que la lista no este vacia*/
			printf("\n Lista Vacia, cargue una lista primero.");
			printf("\n");
			menu_list(cad1,cad2,cad3,L1,L2,S1,S2,A1); /*Llamada recursiva del menu*/
			break;
		}
		else{
			*cad3=toStr(aux); /*Utilizo el metodo "toStr" del "TAD String" */
			printf("\n String creada a partir de una lista dada: ");
			print(*cad3); /*Utilizo el metodo "print" del "TAD String"*/
			printf("\n");
			menu_list(cad1,cad2,cad3,L1,L2,S1,S2,A1);/*Llamada recursiva del menu*/
			break;
		}
	}
	case 0:{
		system("cls");
		menu(cad1,cad2,cad3,L1,L2,S1,S2,A1);
		break;
	}
	
	}
}
void menu_set(str *cad1,str *cad2,str *cad3, list *L1, list *L2, set S1, set S2,TDA A1){
	int op;
	printf("\n Nota: Cargar dos conjuntos para poder realizar correctamente las operaciones entre conjuntos.");
	printf("\n Seleccione la accion a realizar: ");
	printf("\n 1_ Cargar dos conjuntos.");
	printf("\n 2_ Mostrar los conjuntos cargados.");
	printf("\n 3_ Realizar la interseccion entre los dos conjuntos ingresados y mostar el nuevo conjunto resultante.");
	printf("\n 4_ Realizar la union entre los dos conjuntos ingresados y mostrar el nuevo conjunto resultante.");
	printf("\n 0_ Volver al menu principal.");
	printf("\n Su eleccion: ");
	scanf("%d",&op);
	
	switch(op){
	case 1: {
		S1=create_set();
		S2=create_set();
		system("cls");
		menu_set(cad1,cad2,cad3,L1,L2,S1,S2,A1);
		break;
	}
	case 2:{
		if(S1 !=NULL && S2 != NULL){
			printf("\n Primer Conjunto: \n");
			show_set(S1);
			printf("\n Segundo Conjunto: \n");
			show_set(S2);
			menu_set(cad1,cad2,cad3,L1,L2,S1,S2,A1);
			break;
		}
		else {
			printf("\n Error en el ingreso de alguno de los conjuntos.");
			system("cls");
			menu_set(cad1,cad2,cad3,L1,L2,S1,S2,A1);
			break;
		}
	}
	case 3: {
		set S3;
		S3=intersec(S1,S2);
		printf("\n La Interseccion entre los conjuntos ingresados S1 y S2 es: ");
		show_set(S3);
		menu_set(cad1,cad2,cad3,L1,L2,S1,S2,A1);
		break;
		}
	case 4: {
		set S4;
		S4=bound(S1,S2);
		printf("\n La Union entre los conjuntos ingresados S1 y S2 es: ");
		show_set(S4);
		menu_set(cad1,cad2,cad3,L1,L2,S1,S2,A1);
		break;
	}
	case 0: {
		system("cls");
		menu(cad1,cad2,cad3,L1,L2,S1,S2,&A1);
		break;
	}
	
	}
}
void menu_string(str *cad1,str *cad2,str *cad3, list *L1, list *L2, set S1, set S2,TDA A1){
	int op;
	printf("\n Seleccione la accion a realizar: ");
	printf("\n 1- Ingresar una String por teclado.");
	printf("\n 2- Mostrar la String ingresada por teclado.");
	printf("\n 3- Mostrar una String pasada por parametro.");
	printf("\n 4- Convertir una String pasada por parametro en Lista y  mostrar la Lista resultante.");
	printf("\n 0- Volver al menu principal.");
	printf("\n Su eleccion: ");
	scanf("%d",&op); /*Almaceno la decision del usuario en la variable opcion declarada previamente*/
	switch(op){ /*Utilizo el metodo switch para poder operar de acuerdo a la decision del usuario*/
		
	case 1: { /*Case encargado del almacenamiento de una String Ingresada por teclado*/
		*cad1=load(); /*Inicializo cad1 utilizando el metodo "load" del TAD String*/
		system("cls");/*Utilizo el metodo "system" con la propiedad "cls" para limpiar la consola y que la vista del usuario no este sobrecargada de informacion
		irrelevante*/
		menu_string(cad1,cad2,cad3,L1,L2,S1,S2,A1);/*Llamada recursiva del menu*/
		break;
	}
	case 2: { /*Case encargado de mostrar la String ingresada por teclado*/
		printf("\n String ingresada por teclado: ");
		print(*cad1); /*Utilizo el metodo "print" del TAD String*/
		printf("\n");
		menu_string(cad1,cad2,cad3,L1,L2,S1,S2,A1);/*Llamada recursiva del menu*/
		break;
	}
	case 3:{ /*Case encargado de mostrar una String cargada previamente pasada por parametro a la funcion "load2" del TAD String*/
		printf("\n String pasada por parametro: ");
		print(*cad2); /*Utilizo el metodo "print" del TAD String*/
		printf("\n");
		menu_string(cad1,cad2,cad3,L1,L2,S1,S2,A1); /*Llamada recursiva del menu*/
		break;
	}
	case 4: { /*Case encargado de realizar la conversion de una string a una Lista*/
			list L3;
			L3=Strtolist(*cad2); /*Utilizo el metodo "Strtolist" del "TAD Lista"*/
			printf("\n Lista creada a partir de una string dada: ");
			show(L3);/*Utilizo el metodo "show" del "TAD Lista" */
			printf("\n");
			menu_string(cad1,cad2,cad3,L1,L2,S1,S2,A1); /*Llamada recursiva del menu*/
			break;
	}
	case 0: {
		system("cls");
		menu(cad1,cad2,cad3,L1,L2,S1,S2,&A1);
		break;
	}
	
	}
}


void menu (str *cad1,str *cad2,str *cad3, list *L1, list *L2, set S1, set S2, TDA *A1){ /*Implementacion del menu recursivo*/
	
	int op; /*Declaro variable entera llamada opcion*/
	printf("\n Seleccione la accion a realizar: ");
	printf("\n 1- Menu para operar con tipo de dato String.");
	printf("\n 2- Menu para operar con tipo de dato List.");
	printf("\n 3- Menu para operar con tipo de dato Set.");
	printf("\n 4- Menu para operar con tipo de dato Arbol.");
	printf("\n 0- Salir del programa.");
	printf("\n Su eleccion: ");
	scanf("%d",&op); /*Almaceno la decision del usuario en la variable opcion declarada previamente*/
	
	switch(op){ /*Utilizo el metodo switch para poder operar de acuerdo a la decision del usuario*/
		
	case 1: { /*Case encargado del almacenamiento de una String Ingresada por teclado*/
		menu_string(cad1,cad2,cad3,L1,L2,S1,S2,*A1);
		menu(cad1,cad2,cad3,L1,L2,S1,S2,A1);;/*Llamada recursiva del menu*/
		break;
	}
	case 2: { /*Case encargado de mostrar la String ingresada por teclado*/
		menu_list(cad1,cad2,cad3,L1,L2,S1,S2,A1);
		menu(cad1,cad2,cad3,L1,L2,S1,S2,A1);/*Llamada recursiva del menu*/
		break;
	}
	case 3:{ /*Case encargado de mostrar una String cargada previamente pasada por parametro a la funcion "load2" del TAD String*/
		menu_set(cad1,cad2,cad3,L1,L2,S1,S2,*A1);
		menu(cad1,cad2,cad3,L1,L2,S1,S2,A1); /*Llamada recursiva del menu*/
		break;
	}
	case 4:{
		menu_arbol(cad1,cad2,cad3,L1,L2,S1,S2,A1);
		break;
	}
	case 0: { /*Caso encargado de ser la condicion de salida del menu recursivo*/
		break;
	}

}
	
	
}
