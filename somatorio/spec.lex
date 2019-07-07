%{
#include "yystype.h"
#include "yygrammar.h"
%}
%%

"<"	{return '<'; }
">"	{return '>';}
"("	{return '(';}
")"	{return ')';}
"{"	{return '{';}
"}"	{return '}';}
";"	{return ';';}
","	{return ',';}
"="	{return '=';}
"%"	{return '%';}
"\""    {return '"';}
"+"     {return '+';}
"&"	{return '&';}
"include" {return INCLUDE;}
"#" 	{yylval.string = yytext; return '#';}
"return" {return RETORNO;}
"stdio.h" { return STDIO;}
"stdlib.h" {return STDLIB;}
"int"      { return INT;}
"void"      {return VOID;}
"float"      {return FLOAT;}
"char"      {return CHAR;}
"for" 	{return FOR;}
"++"    {return INC;}
"--"    {return DEC;}
[0-9]+ { return NUMBER; }
[a-zA-Z]+ {return NAME;}
" "    { /* skip blank */ }
\n     { yypos++; /* adjust linenumber and skip newline */ }
.      { yyerror("illegal token"); }






