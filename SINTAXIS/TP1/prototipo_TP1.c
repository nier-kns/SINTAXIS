#include <stdio.h>
#include <stdlib.h>

#define TABLE_ROW 7
#define TABLE_COL 7

void start(void);

void next(int [][TABLE_COL], int *, char);

int translate(int);

void write(int, FILE *);

int main(void)
{
	start();

	return 0;
}

void start(void)
{
	FILE *originalfp = fopen("EjemploIn.txt", "r+"), *procfp = fopen("EjemploOut.txt", "w+");
	char ch;
	int estados[7][7] = { {1, 2, 2, 6, 6, 6, 6},
						  {5, 5, 6, 6, 6, 3, 6},
						  {2, 2, 2, 6, 6, 6, 6},
						  {4, 4, 4, 4, 4, 6, 6},
						  {4, 4, 4, 4, 4, 6, 6},
						  {5, 5, 6, 6, 6, 6, 6},
						  {6, 6, 6, 6, 6, 6, 6} };
	int ultimoEstado;
						 
	if (originalfp != NULL)
	{
		printf("File loaded\n");
		
		ch = fgetc(originalfp);
		
		while(ch != EOF)
		{
			ultimoEstado = 0;
			
			while(ch != ',' && ch != EOF)
			{
				
				next(estados, &ultimoEstado, ch);
				fputc(ch, procfp);
				ch = fgetc(originalfp);
			}
			ch = fgetc(originalfp);
			
			while(ch == ' ')
				ch = fgetc(originalfp);
			
			fputs(": ", procfp);
			write(translate(ultimoEstado), procfp);
		}
	}
	else
		printf("No file found\n");
		
	fclose(originalfp);
	fclose(procfp);
	return;
}

void next(int tabla[][TABLE_COL], int* estado, char ch)
{
	int chartype;
	
	if (ch == '0') // caracter 0 
		chartype = 0;
	else if (ch >= '1' && ch <= '7')
		chartype = 1;
	else if (ch == '8' || ch == '9')
		chartype = 2;
	else if (ch >= 'a' && ch <= 'f')
		chartype = 3;
	else if (ch >= 'A' && ch <= 'F')
		chartype = 4;
	else if (ch == 'x' || ch == 'X')
		chartype = 5;
	else if (ch == ',')
		;
	else
		chartype = 6;

	*estado = tabla[*estado][chartype];
	
	return;
}

int translate(int estado)
{
	switch(estado)
	{
		case 1:
			return 3;
		case 2:
			return 1;
		case 3:
			return -1;
		case 4:
			return 2;
		case 5:
			return 3;
		case 6:
			return -1;	
	}
	
	return 0;
}

void write(int decType, FILE *fp)
{
	if(decType == 1)
		fputs("DECIMAL\n", fp);
	else if(decType == 2)
		fputs("HEXADECIMAL\n", fp);
	else if (decType == 3)
		fputs("OCTAL\n", fp);
	else
		fputs("NO DEFINIDO\n", fp);
	
	return;
}


