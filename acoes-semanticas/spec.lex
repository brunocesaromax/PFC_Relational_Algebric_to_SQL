%{
#include "yygrammar.h"
%}
%%

"a"    {return 'a';}
"b"	{return 'b';}
"c"	{return 'c';}
[0-9]+ { yylval = atoi(yytext); return NUMBER; }
" "    { /* skip blank */ }
\n     { yypos++; /* adjust linenumber and skip newline */ }
.      { yyerror("illegal token"); }
