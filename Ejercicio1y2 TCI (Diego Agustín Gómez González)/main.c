#include "TAD_string.h"
#include "TAD_list.h"
#include <stdio.h>

// ------------// REALIZADO POR DIEGO AGUSTÍN GÓMEZ GONZÁLEZ // ------------ //

int main(){
	//  ------------- PRUEBAS PARA EJERCICIO 1  -------------
	/*str cadena1, cadena2, beforeTokenCad, conCatCad, afterTokenCad;
	char c;
	int is;
	
	cadena1=load2("hola");
	cadena2=load2("mundo");
	
	printf("\n\ncadena 1: ");
	show(cadena1);
	
	printf("\n\ncadena 2: ");
	show(cadena2);
	
	printf("\n\ningrese un caracter para before token: ");
	fflush(stdin);
	scanf("%c",&c);
	beforeTokenCad = beforeToken(cadena1, c);
	show(beforeTokenCad);
	
	printf("\n\ningrese un caracter para after token: ");
	fflush(stdin);
	scanf("%c",&c);
	afterTokenCad = afterToken(cadena1, c);
	show(afterTokenCad);
	
	printf("\n\n cadenas 1 y 2 concatenadas: ");
	conCatCad = conCat(cadena1, cadena2);
	show(conCatCad);
	
	printf("\n\n ingrese un caracter para buscar en cadena 1: ");
	fflush(stdin);
	scanf("%c",&c);
	is = isIn(cadena1, c);
	if (is==1) printf("\n el caracter ingresado si se encuentra en la cadena");
	else printf("\n el caracter ingresado NO se encuentra en la cadena");*/
	
	//   ---------  PRUEBAS PARA EJERCICIO 2 -------------
	str cadena1, cadena2, cadena3, cadena4, cadena5, cad;
	
	cadena1 = load2("hola ");
	cadena2 = load2("mundo");
	cadena3 = load2(" me llamo diego");
	cadena4 = load2("le agrego esto");
	cadena5 = load2("y tambien esto");
	
	//INICIALIZO LAS LIST1 Y LIST2 Y LIST3
	Tlist list1, list2, list3, list4;
	list1 = createList();
	list2 = createList();
	list3 = createList();
	
	//AÑADO CADENAS A LIST1 Y MUESTRO LIST1
	aniadirElemento(&list1, cadena1);
	aniadirElemento(&list1, cadena2);
	aniadirElemento(&list1, cadena3);
	printf("\n     ---------- LISTA 1 ----------\n");
	showList(list1);
	
	//AÑADO CADENAS A LIST2 Y MUESTRO LIST2
	aniadirElemento(&list2, cadena4);
	aniadirElemento(&list2, cadena5);
	printf("\n\n\n     ---------- LISTA 2 ---------- \n");
	showList(list2);
	
	//CONCATENO LIST1 Y LIS2 EN UNA NUEVA LISTA LIST3 Y LA MUESTRO
	list3 = concatenar(list1, list2);
	printf("\n\n\n     ---------- LISTA 3 ---------- (lista 1 y lista 2 concatenadas)\n");
	showList(list3);
	
	//STR A LISTA
	printf("\n\n\n\n Cadena1: ");
	show(cadena1);
	printf("\n\n Cadena1 a lista: \n");
	list4 = strToList(cadena1);
	showList(list4);
	
	//LIST A STR					
	printf("\n\n\n\n list1: ");
	showList(list1);
	printf("\n\n list1 a str: \n");
	cad = listToStr(list1);
	show(cad);
	
	return 0;
}

// ------------// REALIZADO POR DIEGO AGUSTÍN GÓMEZ GONZÁLEZ // ------------ //
	
	
	
	
	
