#include <stdio.h>
#include "TAD_set.h"

int main(){
	
	set conj, conj2, conj3;
	
	str cad1, cad2, cad3, cad5;
	
	char c;
	
	cad1 = load2("hola");
	cad2 = load2("soy");
	cad3 = load2("diego");
	cad5 = load2("a,b,cd,efg");
	
	conj=createSet();
	conj2=createSet();
	conj3=createSet();
	printf("\n\n CONJUNTO 1: ");
	showSet(conj);
	
	printf("\n\nagrego cad1 ");
	agregar(&conj, cad1);
	printf("\n\n CONJUNTO 1: ");
	showSet(conj);
	
	printf("\n\nagrego cad2 ");
	agregar(&conj, cad2);
	printf("\n\n CONJUNTO 1: ");
	showSet(conj);
	
	printf("\n\nagrego cad3 ");
	agregar(&conj, cad3);
	printf("\n\n CONJUNTO 1: ");
	showSet(conj);
	
	printf("\n\n\n\ncad5: ");
	show(cad5);
	printf("\n\n ingrese un caracter para str to set: ");
	fflush(stdin);
	scanf("%c",&c);
	conj2 = strToSetToken(cad5 , c);
	printf("\n CONJUNTO 2: ");
	showSet(conj2);
	
	printf("\n\n\nagrego cad1 a conjunto2 ");
	agregar(&conj2, cad1);
	printf("\n\n CONJUNTO 2: ");
	showSet(conj2);
	
	printf("\n\n\n UNION DE CONJUNTO 1 Y 2: ");
	conj3 = unionSets(conj, conj2);
	showSet(conj3);
	
	if(contenido(conj, conj3)==1)
		printf("\n\n el conjunto1 esta contenido en el conjunto 3");
	
	printf("\n\n\n INTERSECCION DE CONJUNTO 1 Y 2: ");
	conj3 = interseccion(conj, conj2);
	showSet(conj3);
	
	printf("\n\n\n DIFERENCIA DE CONJUNTO 1 Y 2: ");
	conj3 = diferencia(conj, conj2);
	showSet(conj3);
	
	return 0;
}
