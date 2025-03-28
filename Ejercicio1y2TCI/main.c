#include "TAD_string.h"
#include <stdio.h>

int main(){
	str cadena1, cadena2, beforeTokenCad, conCatCad;
	char c;
	
	printf("\n\n    carga de cadena 1: ");
	cadena1=load();
	printf("\n\n    carga de cadena 2: ");
	cadena2=load();
	
	printf("\n\ncadena 1: ");
	show(cadena1);
	
	printf("\n\ncadena 2: ");
	show(cadena2);
	
	printf("\n\ningrese un caracter para before token: ");
	fflush(stdin);
	scanf("%c",&c);
	
	beforeTokenCad = beforeToken(cadena1, c);
	show(beforeTokenCad);
	
	conCatCad = conCat(cadena1, cadena2);
	printf("\n\n cadenas 1 y 2 concaenadas: ");
	show(conCatCad);
	
	return 0;
}
