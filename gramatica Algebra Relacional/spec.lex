%{
#include "yystype.h"
#include "yygrammar.h"
%}
%%

	/*Símbolos unitários*/
"<"	{yylval.stringval = "<"; return '<';}
">"	{return '>';}
"("	{return '(';}
")"	{return ')';}
";"	{return ';';}
","	{return ',';}
"="	{return '=';}
"\""    {return '"';}
"!"	{return '!';}
	/*Operadores aritméticos*/
"+"     {return '+';}
"-"     {return '-';}
"*"     {return '*';}
"/"     {return '/';}
	/*Operadores lógicos*/
"AND" {return AND;}
"OR" {return OR;}
"NOT" {return NOT;}
	/*Operadores de algébra relacional*/
"SIGMA" {return SIGMA;}
"PI" { return PI;}
"ASSIGNMENT" { return ASSIGNMENT;}
"RHO" {return RHO;}
"UNION" {return UNION;}
"INTERSECTION" {return INTERSECTION;}
"SUBTRACTION" {return SUBTRACTION;}
"PRODUCT_CARTESIAN" {return PRODUCT_CARTESIAN;}
"JOIN" {return JOIN;}
"NATURAL_JOIN" {return NATURAL_JOIN;}
"DIVISION" {return DIVISION;}
"FSCRIPT" {return FSCRIPT;}
"LEFT_OUTER_JOIN" {return LEFT_OUTER_JOIN;}
"RIGHT_OUTER_JOIN" {return RIGHT_OUTER_JOIN;}
"COMPLETE_OUTER_JOIN" {return COMPLETE_OUTER_JOIN;}
	/* Funções de agregação*/
"COUNT" {return COUNT;}
"AVERAGE" {return AVERAGE;}
"MAX" {return MAX;}
"MIN" {return MIN;}
"SUM" {return SUM;}
	/*Expressão regular para números inteiros e reais*/
([+-]?([0-9]*)(\.([0-9]+))?) {
                            char *res = (char *) malloc((strlen(yytext) + 1) * sizeof(char));
                            strcpy(res, yytext);
                            yylval.stringval = res;
                            return NUMERO;
}
	/*Expressão regular para strings com ou sem acento*/
['a-zà-úA-ZÀ-Ú0-9_\.']+ {
		char *res = (char *) malloc((strlen(yytext) + 1) * sizeof(char));
		strcpy(res, yytext);
		yylval.stringval = res;		
		return NOME;
}
	/*Expressão regular para comentários, semelhante a linguagem C*/
"/*"([^*]|\*+[^*/])*\*+"/" {return COMENTARIO;}
" "    { /* skip blank*/ }
\n     { yypos++; /* adjust linenumber and skip newline */ }






