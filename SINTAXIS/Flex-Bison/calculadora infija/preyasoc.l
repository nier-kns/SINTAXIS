
%{
#include "preyasoc.tab.h"
#include <stdlib.h>
#include <ctype.h>
#include <stdio.h>
%}


%%

[0-9]+("."[0-9]+)?  {yylval.real = atof(yytext); return NUM;}
"+"     {return '+';}
"-"     {return '-';}
"*"     {return '*';}
"/"     {return '/';}
"^"     {return '^';}
"("     {return '(';}
")"     {return ')';}
"\n"    {return '\n';}

%%
