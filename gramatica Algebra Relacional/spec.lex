%{
#include "yystype.h"
#include "yygrammar.h"
#include "treefunctions.h"
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
"PI" { PROJECTION; return PI;}
"ATRIBUICAO" { return ATRIBUICAO;}
"RHO" {return RHO;}
"UNIAO" {return UNIAO;}
"INTERSECCAO" {return INTERSECCAO;}
"SUBTRACAO" {return SUBTRACAO;}
"PRODUTO_CARTESIANO" {return PRODUTO_CARTESIANO;}
"JUNCAO" {return JUNCAO;}
"JUNCAO_NATURAL" {return JUNCAO_NATURAL;}
"DIVISAO" {return DIVISAO;}
"FSCRIPT" {return FSCRIPT;}
"JUNCAO_EXTERNA_ESQUERDA" {return JUNCAO_EXTERNA_ESQUERDA;}
"JUNCAO_EXTERNA_DIREITA" {return JUNCAO_EXTERNA_DIREITA;}
"JUNCAO_EXTERNA_COMPLETA" {return JUNCAO_EXTERNA_COMPLETA;}
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
['a-zà-úA-ZÀ-Ú0-9_']+ {
		char *res = (char *) malloc((strlen(yytext) + 1) * sizeof(char));
		strcpy(res, yytext);
		yylval.stringval = res;		
		return NOME;
}
	/*Expressão regular para comentários, semelhante a linguagem C*/
"/*"([^*]|\*+[^*/])*\*+"/" {return COMENTARIO;}
" "    { /* skip blank*/ }
\n     { yypos++; /* adjust linenumber and skip newline */ }
.      { yyerror("illegal token"); }






