#ifndef TAD_STRING_H
#define TAD_STRING_H

typedef struct nodo{
	char dato;
	struct nodo *sig;
}Tnodo;
typedef Tnodo *str;

str create();
str load();
str load2(const char*);
void show(str);
str conCat(str, str);
str beforeToken(str, char);

#endif
