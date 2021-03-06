/* Calculadora de notaci?n infija (usual) */

%{
#include <math.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
extern FILE *yyin;
%}

%union
{
 float real;
}

%token <real> NUM
%type <real> exp

%left '+' '-'
%right '*' '/'
%nonassoc '^'


%% /* A continuaci?n las reglas gramaticales y las acciones */

input:    /* vac?o */
        | input line
;

line:     '\n'
        | exp '\n'  { printf ("\t %f\n", $1); }
;

exp:    NUM               { $$ = $1             }
        |'(' '-' NUM ')'  { $$ = - $3           }
        | exp '+' exp     { $$ = $1 + $3;       }
        | exp '-' exp     { $$ = $1 - $3;       }
        | exp '*'  exp     { $$ = $1 * $3;       }
        | exp '/' exp     { $$ = $1 / $3;       }
        | exp '^' exp     { $$ = pow($1,$3);    }
;
%%

yyerror (s)  /* Llamada por yyparse ante un error */
     char *s;
{
  printf ("%s\n", s);
}

main ()
{
  yyin = fopen("Hola.txt","r+");
  yyparse ();
}
