#include "TAD_string.h"
#include <stdio.h>

int main(){
	str cadena1, cadena2, beforeTokenCad, conCatCad, afterTokenCad;
	char c;
	
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

	
	return 0;
}
