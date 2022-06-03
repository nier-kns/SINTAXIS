#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int strlong(const char *);

int esVacio(const char *);

char * concatenate(const char *, const char *);

int main(void)
{
	char *str = "holaaa";
	char *str2 = "";
	char *str3 = "Hello", *str4 = " World!";
	int a=0;
	//printf("Ej 1\nCadena: %s\nLongitud: %d", str, strlong(str));
	//printf("\nEj 2\nCadena: %s\nEs vacio?: %c", str2, esVacio(str2) != 0? 'Y':'N');	
	//printf("\nEj 3\nCadena1: %s, Cadena2: %s\nConcatenado: %s", str3, str4, concatenate(str3, str4));
	
	
	return a=2;
}

int strlong(const char *s)
{
	char *c = s;
	int i;
	
	while(*c != '\0')
	{
		c++;
		i++;
	}
	
	return i;
}

int esVacio(const char *s)
{
	return *s == '\0' || *s == '\n';
}

char * concatenate(const char *s1, const char *s2)
{
	int i = 0;
	char *newstr, *cs1 = s1, *cs2 = s2;
	newstr = malloc(strlen(s1)+strlen(s2));

	while(*cs1 != '\0')
	{
		*newstr = *cs1;
		newstr++;
		cs1++;
		i++;
	}
	while(*cs2 != '\0')
	{
		*newstr = *cs2;
		newstr++;
		cs2++;
		i++;
	}
	while(i > 0)
	{
		newstr--;
		i--;
	}
	
	return newstr;
}
