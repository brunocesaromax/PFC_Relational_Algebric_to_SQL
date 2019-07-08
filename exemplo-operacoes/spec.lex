%{
#include "yystype.h"
#include "yygrammar.h"
%}
%%
"+"    { return '+'; }
"-"    { return '-'; }
"*"    { return '*'; }
"/"    { return '/'; }
[0-9]+ { yylval.intval = atoi(yytext); return NUMBER; }
" "    { /* skip blank */ }
\n     { yypos++; /* adjust linenumber and skip newline */ }
.      { yyerror("illegal token"); }
