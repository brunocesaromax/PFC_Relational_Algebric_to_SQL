#line 1 "spec.acc"

#include "yystype.h"
#include "Node.c"
#include "Tree.c"


# line 9 "yygrammar.c"
#include "yygrammar.h"

YYSTART ()
{
   switch(yyselect()) {
   case 47: {
      consulta();
      get_lexval();
      } break;
   }
}

consulta ()
{
   switch(yyselect()) {
   case 1: {
#line 10 "spec.acc"
_tool_initialize();
# line 28 "yygrammar.c"
      while (1) {
         switch (yyselect()) {
         case 48: {
            operacao_consulta();
            } break;
         case 49: {
            get_lexval();
            } break;
         default: goto yy1;
         }
      }
      yy1: ;
#line 10 "spec.acc"
_build_tree();
# line 43 "yygrammar.c"
      } break;
   }
}

operacao_consulta ()
{
   switch(yyselect()) {
   case 2: {
      get_lexval();
#line 14 "spec.acc"
_add_node_stack("(");
# line 55 "yygrammar.c"
      operacao_consulta();
      get_lexval();
#line 16 "spec.acc"
_add_node_stack(")");
# line 60 "yygrammar.c"
      } break;
   case 3: {
      switch (yyselect()) {
      case 50: {
         operacao_unaria();
         } break;
      case 51: {
         operacao_binaria();
         } break;
      default: printf("???\n"); exit(1);
      }
      } break;
   }
}

operacao_unaria ()
{
   switch(yyselect()) {
   case 4: {
      selecao();
      } break;
   case 5: {
      projecao();
      } break;
   case 6: {
      renomeacao1();
      } break;
   case 7: {
      renomeacao2();
      } break;
   case 8: {
      agrupamento();
      } break;
   }
}

operacao_binaria ()
{
   YYSTYPE y;
   switch(yyselect()) {
   case 9: {
      switch (yyselect()) {
      case 52: {
         get_lexval();
         y = yylval;
#line 40 "spec.acc"
_add_node_stack(y.stringval);
# line 108 "yygrammar.c"
         } break;
      case 53: {
         operacao_consulta();
         } break;
      case 54: {
         get_lexval();
#line 44 "spec.acc"
_add_node_stack("(");
# line 117 "yygrammar.c"
         get_lexval();
         y = yylval;
#line 45 "spec.acc"
_add_node_stack(y.stringval);
# line 122 "yygrammar.c"
         get_lexval();
#line 46 "spec.acc"
_add_node_stack(")");
# line 126 "yygrammar.c"
         } break;
      default: printf("???\n"); exit(1);
      }
      tipo_operacao_binaria();
      switch (yyselect()) {
      case 55: {
         get_lexval();
         y = yylval;
#line 50 "spec.acc"
_add_node_stack(y.stringval);
# line 137 "yygrammar.c"
         } break;
      case 56: {
         operacao_consulta();
         } break;
      case 57: {
         get_lexval();
#line 54 "spec.acc"
_add_node_stack("(");
# line 146 "yygrammar.c"
         get_lexval();
         y = yylval;
#line 55 "spec.acc"
_add_node_stack(y.stringval);
# line 151 "yygrammar.c"
         get_lexval();
#line 56 "spec.acc"
_add_node_stack(")");
# line 155 "yygrammar.c"
         } break;
      default: printf("???\n"); exit(1);
      }
      } break;
   case 10: {
      switch (yyselect()) {
      case 58: {
         get_lexval();
         y = yylval;
#line 60 "spec.acc"
_add_node_stack(y.stringval);
# line 167 "yygrammar.c"
         } break;
      case 59: {
         operacao_consulta();
         } break;
      case 60: {
         get_lexval();
#line 64 "spec.acc"
_add_node_stack("(");
# line 176 "yygrammar.c"
         get_lexval();
         y = yylval;
#line 65 "spec.acc"
_add_node_stack(y.stringval);
# line 181 "yygrammar.c"
         get_lexval();
#line 66 "spec.acc"
_add_node_stack(")");
# line 185 "yygrammar.c"
         } break;
      default: printf("???\n"); exit(1);
      }
      get_lexval();
#line 68 "spec.acc"
_add_node_stack("JUNCAO_NATURAL");
# line 192 "yygrammar.c"
      renomeacao2();
      } break;
   }
}

tipo_operacao_binaria ()
{
   switch(yyselect()) {
   case 11: {
      get_lexval();
#line 74 "spec.acc"
_add_node_stack("UNIAO");
# line 205 "yygrammar.c"
      } break;
   case 12: {
      get_lexval();
#line 76 "spec.acc"
_add_node_stack("INTERSECCAO");
# line 211 "yygrammar.c"
      } break;
   case 13: {
      get_lexval();
#line 78 "spec.acc"
_add_node_stack("SUBTRACAO");
# line 217 "yygrammar.c"
      } break;
   case 14: {
      get_lexval();
#line 80 "spec.acc"
_add_node_stack("PRODUTO_CARTESIANO");
# line 223 "yygrammar.c"
      } break;
   case 15: {
      get_lexval();
      predicado();
#line 83 "spec.acc"
_add_node_stack("JUNCAO");
# line 230 "yygrammar.c"
      } break;
   case 16: {
      get_lexval();
#line 85 "spec.acc"
_add_node_stack("JUNCAO_NATURAL");
# line 236 "yygrammar.c"
      } break;
   case 17: {
      get_lexval();
      predicado();
#line 88 "spec.acc"
_add_node_stack("JUNCAO_EXTERNA_ESQUERDA");
# line 243 "yygrammar.c"
      } break;
   case 18: {
      get_lexval();
      predicado();
#line 91 "spec.acc"
_add_node_stack("JUNCAO_EXTERNA_DIREITA");
# line 250 "yygrammar.c"
      } break;
   case 19: {
      get_lexval();
      predicado();
#line 94 "spec.acc"
_add_node_stack("JUNCAO_EXTERNA_COMPLETA");
# line 257 "yygrammar.c"
      } break;
   case 20: {
      get_lexval();
#line 96 "spec.acc"
_add_node_stack("DIVISAO");
# line 263 "yygrammar.c"
      } break;
   }
}

selecao ()
{
   YYSTYPE y;
   switch(yyselect()) {
   case 21: {
      get_lexval();
      predicado();
#line 101 "spec.acc"
_add_node_stack("SIGMA");
# line 277 "yygrammar.c"
      get_lexval();
#line 102 "spec.acc"
_add_node_stack("(");
# line 281 "yygrammar.c"
      switch (yyselect()) {
      case 61: {
         get_lexval();
         y = yylval;
#line 104 "spec.acc"
_add_node_stack(y.stringval);
# line 288 "yygrammar.c"
         } break;
      case 62: {
         operacao_consulta();
         } break;
      default: printf("???\n"); exit(1);
      }
      get_lexval();
#line 108 "spec.acc"
_add_node_stack(")");
# line 298 "yygrammar.c"
      } break;
   }
}

projecao ()
{
   YYSTYPE y;
   switch(yyselect()) {
   case 22: {
      get_lexval();
      lista_atributos();
#line 113 "spec.acc"
_add_node_stack("PI");
# line 312 "yygrammar.c"
      get_lexval();
#line 114 "spec.acc"
_add_node_stack("(");
# line 316 "yygrammar.c"
      switch (yyselect()) {
      case 63: {
         get_lexval();
         y = yylval;
#line 116 "spec.acc"
_add_node_stack(y.stringval);
# line 323 "yygrammar.c"
         } break;
      case 64: {
         operacao_consulta();
         } break;
      default: printf("???\n"); exit(1);
      }
      get_lexval();
#line 120 "spec.acc"
_add_node_stack(")");
# line 333 "yygrammar.c"
      } break;
   }
}

renomeacao1 ()
{
   YYSTYPE y;
   switch(yyselect()) {
   case 23: {
      get_lexval();
      y = yylval;
      switch (yyselect()) {
      case 65: {
         get_lexval();
         lista_atributos();
#line 125 "spec.acc"
_add_node_stack(y.stringval);
# line 351 "yygrammar.c"
         get_lexval();
         } break;
      default: ;
      }
      get_lexval();
#line 126 "spec.acc"
_add_node_stack("ATRIBUICAO");
# line 359 "yygrammar.c"
      operacao_consulta();
      } break;
   }
}

renomeacao2 ()
{
   YYSTYPE y;
   switch(yyselect()) {
   case 24: {
      get_lexval();
      get_lexval();
      y = yylval;
#line 132 "spec.acc"
_add_symbols_attribute(y.stringval,1);
# line 375 "yygrammar.c"
#line 133 "spec.acc"
 _add_node_stack("RHO");
# line 378 "yygrammar.c"
      get_lexval();
#line 134 "spec.acc"
_add_node_stack("(");
# line 382 "yygrammar.c"
      switch (yyselect()) {
      case 66: {
         get_lexval();
         y = yylval;
#line 136 "spec.acc"
_add_node_stack(y.stringval);
# line 389 "yygrammar.c"
         } break;
      case 67: {
         operacao_consulta();
         } break;
      default: printf("???\n"); exit(1);
      }
      get_lexval();
#line 140 "spec.acc"
_add_node_stack(")");
# line 399 "yygrammar.c"
      } break;
   case 25: {
      get_lexval();
      get_lexval();
      y = yylval;
#line 143 "spec.acc"
_add_symbols_attribute(y.stringval,1);
# line 407 "yygrammar.c"
      get_lexval();
#line 144 "spec.acc"
_add_symbols_attribute("(",1);
# line 411 "yygrammar.c"
      lista_atributos();
      get_lexval();
#line 146 "spec.acc"
_add_symbols_attribute(")",1);
# line 416 "yygrammar.c"
#line 147 "spec.acc"
_add_node_stack("RHO");
# line 419 "yygrammar.c"
      get_lexval();
#line 148 "spec.acc"
_add_node_stack("(");
# line 423 "yygrammar.c"
      switch (yyselect()) {
      case 68: {
         get_lexval();
         y = yylval;
#line 150 "spec.acc"
_add_node_stack(y.stringval);
# line 430 "yygrammar.c"
         } break;
      case 69: {
         operacao_consulta();
         } break;
      default: printf("???\n"); exit(1);
      }
      get_lexval();
#line 154 "spec.acc"
_add_node_stack(")");
# line 440 "yygrammar.c"
      } break;
   case 26: {
      get_lexval();
      get_lexval();
#line 157 "spec.acc"
_add_symbols_attribute("(",1);
# line 447 "yygrammar.c"
      lista_atributos();
      get_lexval();
#line 159 "spec.acc"
_add_symbols_attribute(")",1);
# line 452 "yygrammar.c"
#line 160 "spec.acc"
_add_node_stack("RHO");
# line 455 "yygrammar.c"
      get_lexval();
#line 161 "spec.acc"
_add_node_stack("(");
# line 459 "yygrammar.c"
      switch (yyselect()) {
      case 70: {
         get_lexval();
         y = yylval;
#line 163 "spec.acc"
_add_node_stack(y.stringval);
# line 466 "yygrammar.c"
         } break;
      case 71: {
         operacao_consulta();
         } break;
      default: printf("???\n"); exit(1);
      }
      get_lexval();
#line 167 "spec.acc"
_add_node_stack(")");
# line 476 "yygrammar.c"
      } break;
   }
}

agrupamento ()
{
   YYSTYPE y;
   switch(yyselect()) {
   case 27: {
      switch (yyselect()) {
      case 72: {
         lista_atributos();
         } break;
      default: ;
      }
      get_lexval();
      lista_funcoes_agregadas();
#line 173 "spec.acc"
 _add_node_stack("FSCRIPT");
# line 496 "yygrammar.c"
      get_lexval();
      switch (yyselect()) {
      case 73: {
         get_lexval();
         y = yylval;
#line 176 "spec.acc"
_add_node_stack(y.stringval);
# line 504 "yygrammar.c"
         } break;
      case 74: {
         operacao_consulta();
         } break;
      default: printf("???\n"); exit(1);
      }
      get_lexval();
      } break;
   }
}

predicado ()
{
   switch(yyselect()) {
   case 28: {
      condicao();
      } break;
   case 29: {
      condicao();
      operador_booleano();
      predicado();
      } break;
   case 30: {
      get_lexval();
#line 190 "spec.acc"
_add_symbols_predicate("(");
# line 531 "yygrammar.c"
      predicado();
      get_lexval();
#line 192 "spec.acc"
_add_symbols_predicate(")");
# line 536 "yygrammar.c"
      switch (yyselect()) {
      case 75: {
         operador_booleano();
         predicado();
         } break;
      default: ;
      }
      } break;
   }
}

condicao ()
{
   YYSTYPE a;
   switch(yyselect()) {
   case 31: {
      get_lexval();
#line 197 "spec.acc"
_add_symbols_predicate("(");
# line 556 "yygrammar.c"
      condicao();
      get_lexval();
#line 199 "spec.acc"
_add_symbols_predicate(")");
# line 561 "yygrammar.c"
      } break;
   case 32: {
      switch (yyselect()) {
      case 76: {
         get_lexval();
         a = yylval;
#line 202 "spec.acc"
_add_symbols_predicate(a.stringval);
# line 570 "yygrammar.c"
         } break;
      case 77: {
         get_lexval();
         a = yylval;
#line 204 "spec.acc"
_add_symbols_predicate(a.stringval);
# line 577 "yygrammar.c"
         } break;
      default: printf("???\n"); exit(1);
      }
      operador_comparacao();
      switch (yyselect()) {
      case 78: {
         get_lexval();
         a = yylval;
#line 208 "spec.acc"
_add_symbols_predicate(a.stringval);
# line 588 "yygrammar.c"
         } break;
      case 79: {
         get_lexval();
         a = yylval;
#line 210 "spec.acc"
_add_symbols_predicate(a.stringval);
# line 595 "yygrammar.c"
         } break;
      default: printf("???\n"); exit(1);
      }
      } break;
   }
}

operador_comparacao ()
{
   switch(yyselect()) {
   case 33: {
      get_lexval();
#line 215 "spec.acc"
_add_symbols_predicate("=");
# line 610 "yygrammar.c"
      } break;
   case 34: {
      get_lexval();
#line 217 "spec.acc"
_add_symbols_predicate("<");
# line 616 "yygrammar.c"
      } break;
   case 35: {
      get_lexval();
#line 219 "spec.acc"
_add_symbols_predicate(">");
# line 622 "yygrammar.c"
      } break;
   case 36: {
      get_lexval();
      get_lexval();
#line 221 "spec.acc"
_add_symbols_predicate("<=");
# line 629 "yygrammar.c"
      } break;
   case 37: {
      get_lexval();
      get_lexval();
#line 223 "spec.acc"
_add_symbols_predicate(">=");
# line 636 "yygrammar.c"
      } break;
   case 38: {
      get_lexval();
      get_lexval();
#line 225 "spec.acc"
_add_symbols_predicate("!=");
# line 643 "yygrammar.c"
      } break;
   }
}

operador_aritmetico ()
{
   switch(yyselect()) {
   case 39: {
      get_lexval();
#line 229 "spec.acc"
_add_symbols_attribute("+",1);
# line 655 "yygrammar.c"
      } break;
   case 40: {
      get_lexval();
#line 231 "spec.acc"
_add_symbols_attribute("-",1);
# line 661 "yygrammar.c"
      } break;
   case 41: {
      get_lexval();
#line 233 "spec.acc"
_add_symbols_attribute("*",1);
# line 667 "yygrammar.c"
      } break;
   case 42: {
      get_lexval();
#line 235 "spec.acc"
_add_symbols_attribute("/",1);
# line 673 "yygrammar.c"
      } break;
   }
}

operador_booleano ()
{
   switch(yyselect()) {
   case 43: {
      get_lexval();
#line 239 "spec.acc"
_add_symbols_predicate(" AND ");
# line 685 "yygrammar.c"
      } break;
   case 44: {
      get_lexval();
#line 241 "spec.acc"
_add_symbols_predicate(" OR ");
# line 691 "yygrammar.c"
      } break;
   }
}

lista_atributos ()
{
   YYSTYPE a;
   switch(yyselect()) {
   case 45: {
      switch (yyselect()) {
      case 80: {
         get_lexval();
         a = yylval;
#line 246 "spec.acc"
_add_symbols_attribute(a.stringval,1);
# line 707 "yygrammar.c"
         } break;
      case 81: {
         get_lexval();
         a = yylval;
#line 248 "spec.acc"
_add_symbols_attribute(a.stringval,1);
# line 714 "yygrammar.c"
         } break;
      default: printf("???\n"); exit(1);
      }
      while (1) {
         switch (yyselect()) {
         case 84: {
            operador_aritmetico();
            switch (yyselect()) {
            case 82: {
               get_lexval();
               a = yylval;
#line 253 "spec.acc"
_add_symbols_attribute(a.stringval,1);
# line 728 "yygrammar.c"
               } break;
            case 83: {
               get_lexval();
               a = yylval;
#line 255 "spec.acc"
_add_symbols_attribute(a.stringval,1);
# line 735 "yygrammar.c"
               } break;
            default: printf("???\n"); exit(1);
            }
            } break;
         default: goto yy2;
         }
      }
      yy2: ;
      switch (yyselect()) {
      case 85: {
         get_lexval();
#line 258 "spec.acc"
_add_symbols_attribute(",",1);
# line 749 "yygrammar.c"
         lista_atributos();
         } break;
      default: ;
      }
      } break;
   }
}

lista_funcoes_agregadas ()
{
   YYSTYPE y;
   switch(yyselect()) {
   case 46: {
      switch (yyselect()) {
      case 86: {
         get_lexval();
#line 263 "spec.acc"
_add_symbols_attribute("COUNT ",2);
# line 768 "yygrammar.c"
         } break;
      case 87: {
         get_lexval();
#line 265 "spec.acc"
_add_symbols_attribute("AVERAGE ",2);
# line 774 "yygrammar.c"
         } break;
      case 88: {
         get_lexval();
#line 267 "spec.acc"
_add_symbols_attribute("MAX ",2);
# line 780 "yygrammar.c"
         } break;
      case 89: {
         get_lexval();
#line 269 "spec.acc"
_add_symbols_attribute("MIN ",2);
# line 786 "yygrammar.c"
         } break;
      case 90: {
         get_lexval();
#line 271 "spec.acc"
_add_symbols_attribute("SUM ",2);
# line 792 "yygrammar.c"
         } break;
      default: printf("???\n"); exit(1);
      }
      get_lexval();
      y = yylval;
#line 273 "spec.acc"
_add_symbols_attribute(y.stringval,2);
# line 800 "yygrammar.c"
      switch (yyselect()) {
      case 91: {
         get_lexval();
#line 274 "spec.acc"
_add_symbols_attribute(",",2);
# line 806 "yygrammar.c"
         lista_funcoes_agregadas();
         } break;
      default: ;
      }
      } break;
   }
}

extern YYSTYPE yylval;
YYSTYPE yylval;
extern long yypos;
long yypos = 1;
/* GentleFlag = no */

typedef struct LEXELEMSTRUCT {
   YYSTYPE val;
   long pos;
   long sym;
   char * text;
   struct LEXELEMSTRUCT *next;
} LEXELEM;
   
LEXELEM *first_lexelem, *cur_lexelem;

init_lexelem()
{
   cur_lexelem = first_lexelem;
}

first_lexval () {
   LEXELEM *p;
   p = (LEXELEM *)malloc(sizeof(LEXELEM));
   if (! p) yymallocerror();
   p->val = yylval;
   p->pos = yypos;
   p->next = 0;
   cur_lexelem = p;
   first_lexelem = p;
}

next_lexval() {
   LEXELEM *p;
   p = (LEXELEM *)malloc(sizeof(LEXELEM));
   if (! p) yymallocerror();
   cur_lexelem-> next = p;
   p->val = yylval;
   p->pos = yypos;
   p->next = 0;
   cur_lexelem = p;
}

get_lexval() {
   extern int FREE_LEXELEMS;
   LEXELEM *p;
   yylval = cur_lexelem->val;
   yypos = cur_lexelem->pos;
   p = cur_lexelem;
   cur_lexelem = cur_lexelem->next;
   free(p);
}

extern int c_length;
int c_length = 460;
extern int yygrammar[];
int yygrammar[] = {
0,
/* 1 */ 0,
/* 2 */ 6,
/* 3 */ 50000,
/* 4 */ -1,
/* 5 */ 47,
/* 6 */ 0,
/* 7 */ 10,
/* 8 */ -6,
/* 9 */ 1,
/* 10 */ 15,
/* 11 */ 23,
/* 12 */ 10,
/* 13 */ -10,
/* 14 */ 48,
/* 15 */ 20,
/* 16 */ 50281,
/* 17 */ 10,
/* 18 */ -10,
/* 19 */ 49,
/* 20 */ 0,
/* 21 */ -10,
/* 22 */ 92,
/* 23 */ 29,
/* 24 */ 50040,
/* 25 */ 23,
/* 26 */ 50041,
/* 27 */ -23,
/* 28 */ 2,
/* 29 */ 0,
/* 30 */ 33,
/* 31 */ -23,
/* 32 */ 3,
/* 33 */ 37,
/* 34 */ 41,
/* 35 */ -33,
/* 36 */ 50,
/* 37 */ 0,
/* 38 */ 61,
/* 39 */ -33,
/* 40 */ 51,
/* 41 */ 45,
/* 42 */ 159,
/* 43 */ -41,
/* 44 */ 4,
/* 45 */ 49,
/* 46 */ 175,
/* 47 */ -41,
/* 48 */ 5,
/* 49 */ 53,
/* 50 */ 191,
/* 51 */ -41,
/* 52 */ 6,
/* 53 */ 57,
/* 54 */ 207,
/* 55 */ -41,
/* 56 */ 7,
/* 57 */ 0,
/* 58 */ 260,
/* 59 */ -41,
/* 60 */ 8,
/* 61 */ 67,
/* 62 */ 73,
/* 63 */ 115,
/* 64 */ 87,
/* 65 */ -61,
/* 66 */ 9,
/* 67 */ 0,
/* 68 */ 101,
/* 69 */ 50270,
/* 70 */ 207,
/* 71 */ -61,
/* 72 */ 10,
/* 73 */ 77,
/* 74 */ 50257,
/* 75 */ -73,
/* 76 */ 52,
/* 77 */ 81,
/* 78 */ 23,
/* 79 */ -73,
/* 80 */ 53,
/* 81 */ 0,
/* 82 */ 50040,
/* 83 */ 50257,
/* 84 */ 50041,
/* 85 */ -73,
/* 86 */ 54,
/* 87 */ 91,
/* 88 */ 50257,
/* 89 */ -87,
/* 90 */ 55,
/* 91 */ 95,
/* 92 */ 23,
/* 93 */ -87,
/* 94 */ 56,
/* 95 */ 0,
/* 96 */ 50040,
/* 97 */ 50257,
/* 98 */ 50041,
/* 99 */ -87,
/* 100 */ 57,
/* 101 */ 105,
/* 102 */ 50257,
/* 103 */ -101,
/* 104 */ 58,
/* 105 */ 109,
/* 106 */ 23,
/* 107 */ -101,
/* 108 */ 59,
/* 109 */ 0,
/* 110 */ 50040,
/* 111 */ 50257,
/* 112 */ 50041,
/* 113 */ -101,
/* 114 */ 60,
/* 115 */ 119,
/* 116 */ 50265,
/* 117 */ -115,
/* 118 */ 11,
/* 119 */ 123,
/* 120 */ 50266,
/* 121 */ -115,
/* 122 */ 12,
/* 123 */ 127,
/* 124 */ 50267,
/* 125 */ -115,
/* 126 */ 13,
/* 127 */ 131,
/* 128 */ 50268,
/* 129 */ -115,
/* 130 */ 14,
/* 131 */ 136,
/* 132 */ 50269,
/* 133 */ 284,
/* 134 */ -115,
/* 135 */ 15,
/* 136 */ 140,
/* 137 */ 50270,
/* 138 */ -115,
/* 139 */ 16,
/* 140 */ 145,
/* 141 */ 50278,
/* 142 */ 284,
/* 143 */ -115,
/* 144 */ 17,
/* 145 */ 150,
/* 146 */ 50279,
/* 147 */ 284,
/* 148 */ -115,
/* 149 */ 18,
/* 150 */ 155,
/* 151 */ 50280,
/* 152 */ 284,
/* 153 */ -115,
/* 154 */ 19,
/* 155 */ 0,
/* 156 */ 50271,
/* 157 */ -115,
/* 158 */ 20,
/* 159 */ 0,
/* 160 */ 50258,
/* 161 */ 284,
/* 162 */ 50040,
/* 163 */ 167,
/* 164 */ 50041,
/* 165 */ -159,
/* 166 */ 21,
/* 167 */ 171,
/* 168 */ 50257,
/* 169 */ -167,
/* 170 */ 61,
/* 171 */ 0,
/* 172 */ 23,
/* 173 */ -167,
/* 174 */ 62,
/* 175 */ 0,
/* 176 */ 50259,
/* 177 */ 388,
/* 178 */ 50040,
/* 179 */ 183,
/* 180 */ 50041,
/* 181 */ -175,
/* 182 */ 22,
/* 183 */ 187,
/* 184 */ 50257,
/* 185 */ -183,
/* 186 */ 63,
/* 187 */ 0,
/* 188 */ 23,
/* 189 */ -183,
/* 190 */ 64,
/* 191 */ 0,
/* 192 */ 50257,
/* 193 */ 198,
/* 194 */ 50260,
/* 195 */ 23,
/* 196 */ -191,
/* 197 */ 23,
/* 198 */ 204,
/* 199 */ 50040,
/* 200 */ 388,
/* 201 */ 50041,
/* 202 */ -198,
/* 203 */ 65,
/* 204 */ 0,
/* 205 */ -198,
/* 206 */ 93,
/* 207 */ 215,
/* 208 */ 50261,
/* 209 */ 50257,
/* 210 */ 50040,
/* 211 */ 236,
/* 212 */ 50041,
/* 213 */ -207,
/* 214 */ 24,
/* 215 */ 226,
/* 216 */ 50261,
/* 217 */ 50257,
/* 218 */ 50040,
/* 219 */ 388,
/* 220 */ 50041,
/* 221 */ 50040,
/* 222 */ 244,
/* 223 */ 50041,
/* 224 */ -207,
/* 225 */ 25,
/* 226 */ 0,
/* 227 */ 50261,
/* 228 */ 50040,
/* 229 */ 388,
/* 230 */ 50041,
/* 231 */ 50040,
/* 232 */ 252,
/* 233 */ 50041,
/* 234 */ -207,
/* 235 */ 26,
/* 236 */ 240,
/* 237 */ 50257,
/* 238 */ -236,
/* 239 */ 66,
/* 240 */ 0,
/* 241 */ 23,
/* 242 */ -236,
/* 243 */ 67,
/* 244 */ 248,
/* 245 */ 50257,
/* 246 */ -244,
/* 247 */ 68,
/* 248 */ 0,
/* 249 */ 23,
/* 250 */ -244,
/* 251 */ 69,
/* 252 */ 256,
/* 253 */ 50257,
/* 254 */ -252,
/* 255 */ 70,
/* 256 */ 0,
/* 257 */ 23,
/* 258 */ -252,
/* 259 */ 71,
/* 260 */ 0,
/* 261 */ 269,
/* 262 */ 50277,
/* 263 */ 427,
/* 264 */ 50040,
/* 265 */ 276,
/* 266 */ 50041,
/* 267 */ -260,
/* 268 */ 27,
/* 269 */ 273,
/* 270 */ 388,
/* 271 */ -269,
/* 272 */ 72,
/* 273 */ 0,
/* 274 */ -269,
/* 275 */ 94,
/* 276 */ 280,
/* 277 */ 50257,
/* 278 */ -276,
/* 279 */ 73,
/* 280 */ 0,
/* 281 */ 23,
/* 282 */ -276,
/* 283 */ 74,
/* 284 */ 288,
/* 285 */ 309,
/* 286 */ -284,
/* 287 */ 28,
/* 288 */ 294,
/* 289 */ 309,
/* 290 */ 380,
/* 291 */ 284,
/* 292 */ -284,
/* 293 */ 29,
/* 294 */ 0,
/* 295 */ 50040,
/* 296 */ 284,
/* 297 */ 50041,
/* 298 */ 301,
/* 299 */ -284,
/* 300 */ 30,
/* 301 */ 306,
/* 302 */ 380,
/* 303 */ 284,
/* 304 */ -301,
/* 305 */ 75,
/* 306 */ 0,
/* 307 */ -301,
/* 308 */ 95,
/* 309 */ 315,
/* 310 */ 50040,
/* 311 */ 309,
/* 312 */ 50041,
/* 313 */ -309,
/* 314 */ 31,
/* 315 */ 0,
/* 316 */ 321,
/* 317 */ 337,
/* 318 */ 329,
/* 319 */ -309,
/* 320 */ 32,
/* 321 */ 325,
/* 322 */ 50257,
/* 323 */ -321,
/* 324 */ 76,
/* 325 */ 0,
/* 326 */ 50256,
/* 327 */ -321,
/* 328 */ 77,
/* 329 */ 333,
/* 330 */ 50257,
/* 331 */ -329,
/* 332 */ 78,
/* 333 */ 0,
/* 334 */ 50256,
/* 335 */ -329,
/* 336 */ 79,
/* 337 */ 341,
/* 338 */ 50061,
/* 339 */ -337,
/* 340 */ 33,
/* 341 */ 345,
/* 342 */ 50060,
/* 343 */ -337,
/* 344 */ 34,
/* 345 */ 349,
/* 346 */ 50062,
/* 347 */ -337,
/* 348 */ 35,
/* 349 */ 354,
/* 350 */ 50060,
/* 351 */ 50061,
/* 352 */ -337,
/* 353 */ 36,
/* 354 */ 359,
/* 355 */ 50062,
/* 356 */ 50061,
/* 357 */ -337,
/* 358 */ 37,
/* 359 */ 0,
/* 360 */ 50033,
/* 361 */ 50061,
/* 362 */ -337,
/* 363 */ 38,
/* 364 */ 368,
/* 365 */ 50043,
/* 366 */ -364,
/* 367 */ 39,
/* 368 */ 372,
/* 369 */ 50045,
/* 370 */ -364,
/* 371 */ 40,
/* 372 */ 376,
/* 373 */ 50042,
/* 374 */ -364,
/* 375 */ 41,
/* 376 */ 0,
/* 377 */ 50047,
/* 378 */ -364,
/* 379 */ 42,
/* 380 */ 384,
/* 381 */ 50262,
/* 382 */ -380,
/* 383 */ 43,
/* 384 */ 0,
/* 385 */ 50263,
/* 386 */ -380,
/* 387 */ 44,
/* 388 */ 0,
/* 389 */ 394,
/* 390 */ 402,
/* 391 */ 419,
/* 392 */ -388,
/* 393 */ 45,
/* 394 */ 398,
/* 395 */ 50257,
/* 396 */ -394,
/* 397 */ 80,
/* 398 */ 0,
/* 399 */ 50256,
/* 400 */ -394,
/* 401 */ 81,
/* 402 */ 408,
/* 403 */ 364,
/* 404 */ 411,
/* 405 */ 402,
/* 406 */ -402,
/* 407 */ 84,
/* 408 */ 0,
/* 409 */ -402,
/* 410 */ 96,
/* 411 */ 415,
/* 412 */ 50257,
/* 413 */ -411,
/* 414 */ 82,
/* 415 */ 0,
/* 416 */ 50256,
/* 417 */ -411,
/* 418 */ 83,
/* 419 */ 424,
/* 420 */ 50044,
/* 421 */ 388,
/* 422 */ -419,
/* 423 */ 85,
/* 424 */ 0,
/* 425 */ -419,
/* 426 */ 97,
/* 427 */ 0,
/* 428 */ 433,
/* 429 */ 50257,
/* 430 */ 453,
/* 431 */ -427,
/* 432 */ 46,
/* 433 */ 437,
/* 434 */ 50272,
/* 435 */ -433,
/* 436 */ 86,
/* 437 */ 441,
/* 438 */ 50273,
/* 439 */ -433,
/* 440 */ 87,
/* 441 */ 445,
/* 442 */ 50274,
/* 443 */ -433,
/* 444 */ 88,
/* 445 */ 449,
/* 446 */ 50275,
/* 447 */ -433,
/* 448 */ 89,
/* 449 */ 0,
/* 450 */ 50276,
/* 451 */ -433,
/* 452 */ 90,
/* 453 */ 458,
/* 454 */ 50044,
/* 455 */ 427,
/* 456 */ -453,
/* 457 */ 91,
/* 458 */ 0,
/* 459 */ -453,
/* 460 */ 98,
0
};
extern int yyannotation[];
int yyannotation[] = {
0,
/* 1 */ 0,
/* 2 */ 0,
/* 3 */ 50000,
/* 4 */ -1,
/* 5 */ 0,
/* 6 */ 0,
/* 7 */ 1,
/* 8 */ -6,
/* 9 */ 1,
/* 10 */ 15,
/* 11 */ 1,
/* 12 */ 1,
/* 13 */ -10,
/* 14 */ 1,
/* 15 */ 20,
/* 16 */ 50281,
/* 17 */ 1,
/* 18 */ -10,
/* 19 */ 2,
/* 20 */ 0,
/* 21 */ -10,
/* 22 */ 3,
/* 23 */ 29,
/* 24 */ 50040,
/* 25 */ 1,
/* 26 */ 50041,
/* 27 */ -23,
/* 28 */ 1,
/* 29 */ 0,
/* 30 */ 1,
/* 31 */ -23,
/* 32 */ 2,
/* 33 */ 37,
/* 34 */ 1,
/* 35 */ -33,
/* 36 */ 1,
/* 37 */ 0,
/* 38 */ 1,
/* 39 */ -33,
/* 40 */ 2,
/* 41 */ 45,
/* 42 */ 1,
/* 43 */ -41,
/* 44 */ 1,
/* 45 */ 49,
/* 46 */ 1,
/* 47 */ -41,
/* 48 */ 2,
/* 49 */ 53,
/* 50 */ 1,
/* 51 */ -41,
/* 52 */ 3,
/* 53 */ 57,
/* 54 */ 1,
/* 55 */ -41,
/* 56 */ 4,
/* 57 */ 0,
/* 58 */ 1,
/* 59 */ -41,
/* 60 */ 5,
/* 61 */ 67,
/* 62 */ 1,
/* 63 */ 1,
/* 64 */ 1,
/* 65 */ -61,
/* 66 */ 1,
/* 67 */ 0,
/* 68 */ 1,
/* 69 */ 50270,
/* 70 */ 1,
/* 71 */ -61,
/* 72 */ 2,
/* 73 */ 77,
/* 74 */ 50257,
/* 75 */ -73,
/* 76 */ 1,
/* 77 */ 81,
/* 78 */ 1,
/* 79 */ -73,
/* 80 */ 2,
/* 81 */ 0,
/* 82 */ 50040,
/* 83 */ 50257,
/* 84 */ 50041,
/* 85 */ -73,
/* 86 */ 3,
/* 87 */ 91,
/* 88 */ 50257,
/* 89 */ -87,
/* 90 */ 1,
/* 91 */ 95,
/* 92 */ 1,
/* 93 */ -87,
/* 94 */ 2,
/* 95 */ 0,
/* 96 */ 50040,
/* 97 */ 50257,
/* 98 */ 50041,
/* 99 */ -87,
/* 100 */ 3,
/* 101 */ 105,
/* 102 */ 50257,
/* 103 */ -101,
/* 104 */ 1,
/* 105 */ 109,
/* 106 */ 1,
/* 107 */ -101,
/* 108 */ 2,
/* 109 */ 0,
/* 110 */ 50040,
/* 111 */ 50257,
/* 112 */ 50041,
/* 113 */ -101,
/* 114 */ 3,
/* 115 */ 119,
/* 116 */ 50265,
/* 117 */ -115,
/* 118 */ 1,
/* 119 */ 123,
/* 120 */ 50266,
/* 121 */ -115,
/* 122 */ 2,
/* 123 */ 127,
/* 124 */ 50267,
/* 125 */ -115,
/* 126 */ 3,
/* 127 */ 131,
/* 128 */ 50268,
/* 129 */ -115,
/* 130 */ 4,
/* 131 */ 136,
/* 132 */ 50269,
/* 133 */ 1,
/* 134 */ -115,
/* 135 */ 5,
/* 136 */ 140,
/* 137 */ 50270,
/* 138 */ -115,
/* 139 */ 6,
/* 140 */ 145,
/* 141 */ 50278,
/* 142 */ 1,
/* 143 */ -115,
/* 144 */ 7,
/* 145 */ 150,
/* 146 */ 50279,
/* 147 */ 1,
/* 148 */ -115,
/* 149 */ 8,
/* 150 */ 155,
/* 151 */ 50280,
/* 152 */ 1,
/* 153 */ -115,
/* 154 */ 9,
/* 155 */ 0,
/* 156 */ 50271,
/* 157 */ -115,
/* 158 */ 10,
/* 159 */ 0,
/* 160 */ 50258,
/* 161 */ 1,
/* 162 */ 50040,
/* 163 */ 1,
/* 164 */ 50041,
/* 165 */ -159,
/* 166 */ 1,
/* 167 */ 171,
/* 168 */ 50257,
/* 169 */ -167,
/* 170 */ 1,
/* 171 */ 0,
/* 172 */ 1,
/* 173 */ -167,
/* 174 */ 2,
/* 175 */ 0,
/* 176 */ 50259,
/* 177 */ 1,
/* 178 */ 50040,
/* 179 */ 1,
/* 180 */ 50041,
/* 181 */ -175,
/* 182 */ 1,
/* 183 */ 187,
/* 184 */ 50257,
/* 185 */ -183,
/* 186 */ 1,
/* 187 */ 0,
/* 188 */ 1,
/* 189 */ -183,
/* 190 */ 2,
/* 191 */ 0,
/* 192 */ 50257,
/* 193 */ 1,
/* 194 */ 50260,
/* 195 */ 1,
/* 196 */ -191,
/* 197 */ 1,
/* 198 */ 204,
/* 199 */ 50040,
/* 200 */ 1,
/* 201 */ 50041,
/* 202 */ -198,
/* 203 */ 1,
/* 204 */ 0,
/* 205 */ -198,
/* 206 */ 2,
/* 207 */ 215,
/* 208 */ 50261,
/* 209 */ 50257,
/* 210 */ 50040,
/* 211 */ 1,
/* 212 */ 50041,
/* 213 */ -207,
/* 214 */ 1,
/* 215 */ 226,
/* 216 */ 50261,
/* 217 */ 50257,
/* 218 */ 50040,
/* 219 */ 1,
/* 220 */ 50041,
/* 221 */ 50040,
/* 222 */ 1,
/* 223 */ 50041,
/* 224 */ -207,
/* 225 */ 2,
/* 226 */ 0,
/* 227 */ 50261,
/* 228 */ 50040,
/* 229 */ 1,
/* 230 */ 50041,
/* 231 */ 50040,
/* 232 */ 1,
/* 233 */ 50041,
/* 234 */ -207,
/* 235 */ 3,
/* 236 */ 240,
/* 237 */ 50257,
/* 238 */ -236,
/* 239 */ 1,
/* 240 */ 0,
/* 241 */ 1,
/* 242 */ -236,
/* 243 */ 2,
/* 244 */ 248,
/* 245 */ 50257,
/* 246 */ -244,
/* 247 */ 1,
/* 248 */ 0,
/* 249 */ 1,
/* 250 */ -244,
/* 251 */ 2,
/* 252 */ 256,
/* 253 */ 50257,
/* 254 */ -252,
/* 255 */ 1,
/* 256 */ 0,
/* 257 */ 1,
/* 258 */ -252,
/* 259 */ 2,
/* 260 */ 0,
/* 261 */ 1,
/* 262 */ 50277,
/* 263 */ 1,
/* 264 */ 50040,
/* 265 */ 1,
/* 266 */ 50041,
/* 267 */ -260,
/* 268 */ 1,
/* 269 */ 273,
/* 270 */ 1,
/* 271 */ -269,
/* 272 */ 1,
/* 273 */ 0,
/* 274 */ -269,
/* 275 */ 2,
/* 276 */ 280,
/* 277 */ 50257,
/* 278 */ -276,
/* 279 */ 1,
/* 280 */ 0,
/* 281 */ 1,
/* 282 */ -276,
/* 283 */ 2,
/* 284 */ 288,
/* 285 */ 1,
/* 286 */ -284,
/* 287 */ 1,
/* 288 */ 294,
/* 289 */ 1,
/* 290 */ 1,
/* 291 */ 1,
/* 292 */ -284,
/* 293 */ 2,
/* 294 */ 0,
/* 295 */ 50040,
/* 296 */ 1,
/* 297 */ 50041,
/* 298 */ 1,
/* 299 */ -284,
/* 300 */ 3,
/* 301 */ 306,
/* 302 */ 1,
/* 303 */ 1,
/* 304 */ -301,
/* 305 */ 1,
/* 306 */ 0,
/* 307 */ -301,
/* 308 */ 2,
/* 309 */ 315,
/* 310 */ 50040,
/* 311 */ 1,
/* 312 */ 50041,
/* 313 */ -309,
/* 314 */ 1,
/* 315 */ 0,
/* 316 */ 1,
/* 317 */ 1,
/* 318 */ 1,
/* 319 */ -309,
/* 320 */ 2,
/* 321 */ 325,
/* 322 */ 50257,
/* 323 */ -321,
/* 324 */ 1,
/* 325 */ 0,
/* 326 */ 50256,
/* 327 */ -321,
/* 328 */ 2,
/* 329 */ 333,
/* 330 */ 50257,
/* 331 */ -329,
/* 332 */ 1,
/* 333 */ 0,
/* 334 */ 50256,
/* 335 */ -329,
/* 336 */ 2,
/* 337 */ 341,
/* 338 */ 50061,
/* 339 */ -337,
/* 340 */ 1,
/* 341 */ 345,
/* 342 */ 50060,
/* 343 */ -337,
/* 344 */ 2,
/* 345 */ 349,
/* 346 */ 50062,
/* 347 */ -337,
/* 348 */ 3,
/* 349 */ 354,
/* 350 */ 50060,
/* 351 */ 50061,
/* 352 */ -337,
/* 353 */ 4,
/* 354 */ 359,
/* 355 */ 50062,
/* 356 */ 50061,
/* 357 */ -337,
/* 358 */ 5,
/* 359 */ 0,
/* 360 */ 50033,
/* 361 */ 50061,
/* 362 */ -337,
/* 363 */ 6,
/* 364 */ 368,
/* 365 */ 50043,
/* 366 */ -364,
/* 367 */ 1,
/* 368 */ 372,
/* 369 */ 50045,
/* 370 */ -364,
/* 371 */ 2,
/* 372 */ 376,
/* 373 */ 50042,
/* 374 */ -364,
/* 375 */ 3,
/* 376 */ 0,
/* 377 */ 50047,
/* 378 */ -364,
/* 379 */ 4,
/* 380 */ 384,
/* 381 */ 50262,
/* 382 */ -380,
/* 383 */ 1,
/* 384 */ 0,
/* 385 */ 50263,
/* 386 */ -380,
/* 387 */ 2,
/* 388 */ 0,
/* 389 */ 1,
/* 390 */ 1,
/* 391 */ 1,
/* 392 */ -388,
/* 393 */ 1,
/* 394 */ 398,
/* 395 */ 50257,
/* 396 */ -394,
/* 397 */ 1,
/* 398 */ 0,
/* 399 */ 50256,
/* 400 */ -394,
/* 401 */ 2,
/* 402 */ 408,
/* 403 */ 1,
/* 404 */ 1,
/* 405 */ 1,
/* 406 */ -402,
/* 407 */ 1,
/* 408 */ 0,
/* 409 */ -402,
/* 410 */ 2,
/* 411 */ 415,
/* 412 */ 50257,
/* 413 */ -411,
/* 414 */ 1,
/* 415 */ 0,
/* 416 */ 50256,
/* 417 */ -411,
/* 418 */ 2,
/* 419 */ 424,
/* 420 */ 50044,
/* 421 */ 1,
/* 422 */ -419,
/* 423 */ 1,
/* 424 */ 0,
/* 425 */ -419,
/* 426 */ 2,
/* 427 */ 0,
/* 428 */ 1,
/* 429 */ 50257,
/* 430 */ 1,
/* 431 */ -427,
/* 432 */ 1,
/* 433 */ 437,
/* 434 */ 50272,
/* 435 */ -433,
/* 436 */ 1,
/* 437 */ 441,
/* 438 */ 50273,
/* 439 */ -433,
/* 440 */ 2,
/* 441 */ 445,
/* 442 */ 50274,
/* 443 */ -433,
/* 444 */ 3,
/* 445 */ 449,
/* 446 */ 50275,
/* 447 */ -433,
/* 448 */ 4,
/* 449 */ 0,
/* 450 */ 50276,
/* 451 */ -433,
/* 452 */ 5,
/* 453 */ 458,
/* 454 */ 50044,
/* 455 */ 1,
/* 456 */ -453,
/* 457 */ 1,
/* 458 */ 0,
/* 459 */ -453,
/* 460 */ 2,
0
};
extern int yycoordinate[];
int yycoordinate[] = {
0,
/* 1 */ 9999,
/* 2 */ 9009,
/* 3 */ 9999,
/* 4 */ 9999,
/* 5 */ 9009,
/* 6 */ 9999,
/* 7 */ 10027,
/* 8 */ 9999,
/* 9 */ 10005,
/* 10 */ 9999,
/* 11 */ 10029,
/* 12 */ 10045,
/* 13 */ 9999,
/* 14 */ 10045,
/* 15 */ 9999,
/* 16 */ 9999,
/* 17 */ 10058,
/* 18 */ 9999,
/* 19 */ 10058,
/* 20 */ 9999,
/* 21 */ 9999,
/* 22 */ 10058,
/* 23 */ 9999,
/* 24 */ 9999,
/* 25 */ 15009,
/* 26 */ 9999,
/* 27 */ 9999,
/* 28 */ 14009,
/* 29 */ 9999,
/* 30 */ 18009,
/* 31 */ 9999,
/* 32 */ 18009,
/* 33 */ 9999,
/* 34 */ 19013,
/* 35 */ 9999,
/* 36 */ 19027,
/* 37 */ 9999,
/* 38 */ 21013,
/* 39 */ 9999,
/* 40 */ 21028,
/* 41 */ 9999,
/* 42 */ 27009,
/* 43 */ 9999,
/* 44 */ 27015,
/* 45 */ 9999,
/* 46 */ 29009,
/* 47 */ 9999,
/* 48 */ 29016,
/* 49 */ 9999,
/* 50 */ 31009,
/* 51 */ 9999,
/* 52 */ 31019,
/* 53 */ 9999,
/* 54 */ 33009,
/* 55 */ 9999,
/* 56 */ 33019,
/* 57 */ 9999,
/* 58 */ 35009,
/* 59 */ 9999,
/* 60 */ 35019,
/* 61 */ 9999,
/* 62 */ 39009,
/* 63 */ 48009,
/* 64 */ 49009,
/* 65 */ 9999,
/* 66 */ 39009,
/* 67 */ 9999,
/* 68 */ 59009,
/* 69 */ 9999,
/* 70 */ 69009,
/* 71 */ 9999,
/* 72 */ 59009,
/* 73 */ 9999,
/* 74 */ 9999,
/* 75 */ 9999,
/* 76 */ 40021,
/* 77 */ 9999,
/* 78 */ 42018,
/* 79 */ 9999,
/* 80 */ 42034,
/* 81 */ 9999,
/* 82 */ 9999,
/* 83 */ 9999,
/* 84 */ 9999,
/* 85 */ 9999,
/* 86 */ 44017,
/* 87 */ 9999,
/* 88 */ 9999,
/* 89 */ 9999,
/* 90 */ 50021,
/* 91 */ 9999,
/* 92 */ 52018,
/* 93 */ 9999,
/* 94 */ 52034,
/* 95 */ 9999,
/* 96 */ 9999,
/* 97 */ 9999,
/* 98 */ 9999,
/* 99 */ 9999,
/* 100 */ 54018,
/* 101 */ 9999,
/* 102 */ 9999,
/* 103 */ 9999,
/* 104 */ 60020,
/* 105 */ 9999,
/* 106 */ 62017,
/* 107 */ 9999,
/* 108 */ 62033,
/* 109 */ 9999,
/* 110 */ 9999,
/* 111 */ 9999,
/* 112 */ 9999,
/* 113 */ 9999,
/* 114 */ 64017,
/* 115 */ 9999,
/* 116 */ 9999,
/* 117 */ 9999,
/* 118 */ 74013,
/* 119 */ 9999,
/* 120 */ 9999,
/* 121 */ 9999,
/* 122 */ 76019,
/* 123 */ 9999,
/* 124 */ 9999,
/* 125 */ 9999,
/* 126 */ 78017,
/* 127 */ 9999,
/* 128 */ 9999,
/* 129 */ 9999,
/* 130 */ 80026,
/* 131 */ 9999,
/* 132 */ 9999,
/* 133 */ 83009,
/* 134 */ 9999,
/* 135 */ 82014,
/* 136 */ 9999,
/* 137 */ 9999,
/* 138 */ 9999,
/* 139 */ 85022,
/* 140 */ 9999,
/* 141 */ 9999,
/* 142 */ 88009,
/* 143 */ 9999,
/* 144 */ 87031,
/* 145 */ 9999,
/* 146 */ 9999,
/* 147 */ 91009,
/* 148 */ 9999,
/* 149 */ 90030,
/* 150 */ 9999,
/* 151 */ 9999,
/* 152 */ 94009,
/* 153 */ 9999,
/* 154 */ 93031,
/* 155 */ 9999,
/* 156 */ 9999,
/* 157 */ 9999,
/* 158 */ 96015,
/* 159 */ 9999,
/* 160 */ 9999,
/* 161 */ 101005,
/* 162 */ 9999,
/* 163 */ 103005,
/* 164 */ 9999,
/* 165 */ 9999,
/* 166 */ 100009,
/* 167 */ 9999,
/* 168 */ 9999,
/* 169 */ 9999,
/* 170 */ 104020,
/* 171 */ 9999,
/* 172 */ 106017,
/* 173 */ 9999,
/* 174 */ 106033,
/* 175 */ 9999,
/* 176 */ 9999,
/* 177 */ 113005,
/* 178 */ 9999,
/* 179 */ 115005,
/* 180 */ 9999,
/* 181 */ 9999,
/* 182 */ 112006,
/* 183 */ 9999,
/* 184 */ 9999,
/* 185 */ 9999,
/* 186 */ 116020,
/* 187 */ 9999,
/* 188 */ 118017,
/* 189 */ 9999,
/* 190 */ 118033,
/* 191 */ 9999,
/* 192 */ 9999,
/* 193 */ 125009,
/* 194 */ 9999,
/* 195 */ 127009,
/* 196 */ 9999,
/* 197 */ 124012,
/* 198 */ 9999,
/* 199 */ 9999,
/* 200 */ 125015,
/* 201 */ 9999,
/* 202 */ 9999,
/* 203 */ 125011,
/* 204 */ 9999,
/* 205 */ 9999,
/* 206 */ 125011,
/* 207 */ 9999,
/* 208 */ 9999,
/* 209 */ 9999,
/* 210 */ 9999,
/* 211 */ 135009,
/* 212 */ 9999,
/* 213 */ 9999,
/* 214 */ 131011,
/* 215 */ 9999,
/* 216 */ 9999,
/* 217 */ 9999,
/* 218 */ 9999,
/* 219 */ 145009,
/* 220 */ 9999,
/* 221 */ 9999,
/* 222 */ 149009,
/* 223 */ 9999,
/* 224 */ 9999,
/* 225 */ 142011,
/* 226 */ 9999,
/* 227 */ 9999,
/* 228 */ 9999,
/* 229 */ 158009,
/* 230 */ 9999,
/* 231 */ 9999,
/* 232 */ 162009,
/* 233 */ 9999,
/* 234 */ 9999,
/* 235 */ 156011,
/* 236 */ 9999,
/* 237 */ 9999,
/* 238 */ 9999,
/* 239 */ 136025,
/* 240 */ 9999,
/* 241 */ 138022,
/* 242 */ 9999,
/* 243 */ 138038,
/* 244 */ 9999,
/* 245 */ 9999,
/* 246 */ 9999,
/* 247 */ 150025,
/* 248 */ 9999,
/* 249 */ 152022,
/* 250 */ 9999,
/* 251 */ 152038,
/* 252 */ 9999,
/* 253 */ 9999,
/* 254 */ 9999,
/* 255 */ 163025,
/* 256 */ 9999,
/* 257 */ 165022,
/* 258 */ 9999,
/* 259 */ 165038,
/* 260 */ 9999,
/* 261 */ 171005,
/* 262 */ 9999,
/* 263 */ 173005,
/* 264 */ 9999,
/* 265 */ 175005,
/* 266 */ 9999,
/* 267 */ 9999,
/* 268 */ 171005,
/* 269 */ 9999,
/* 270 */ 171006,
/* 271 */ 9999,
/* 272 */ 171020,
/* 273 */ 9999,
/* 274 */ 9999,
/* 275 */ 171020,
/* 276 */ 9999,
/* 277 */ 9999,
/* 278 */ 9999,
/* 279 */ 176020,
/* 280 */ 9999,
/* 281 */ 178017,
/* 282 */ 9999,
/* 283 */ 178033,
/* 284 */ 9999,
/* 285 */ 184009,
/* 286 */ 9999,
/* 287 */ 184016,
/* 288 */ 9999,
/* 289 */ 186009,
/* 290 */ 187009,
/* 291 */ 188009,
/* 292 */ 9999,
/* 293 */ 186016,
/* 294 */ 9999,
/* 295 */ 9999,
/* 296 */ 191009,
/* 297 */ 9999,
/* 298 */ 193009,
/* 299 */ 9999,
/* 300 */ 190009,
/* 301 */ 9999,
/* 302 */ 193010,
/* 303 */ 193028,
/* 304 */ 9999,
/* 305 */ 193026,
/* 306 */ 9999,
/* 307 */ 9999,
/* 308 */ 193026,
/* 309 */ 9999,
/* 310 */ 9999,
/* 311 */ 198009,
/* 312 */ 9999,
/* 313 */ 9999,
/* 314 */ 197009,
/* 315 */ 9999,
/* 316 */ 201009,
/* 317 */ 206009,
/* 318 */ 207009,
/* 319 */ 9999,
/* 320 */ 201009,
/* 321 */ 9999,
/* 322 */ 9999,
/* 323 */ 9999,
/* 324 */ 202024,
/* 325 */ 9999,
/* 326 */ 9999,
/* 327 */ 9999,
/* 328 */ 204026,
/* 329 */ 9999,
/* 330 */ 9999,
/* 331 */ 9999,
/* 332 */ 208024,
/* 333 */ 9999,
/* 334 */ 9999,
/* 335 */ 9999,
/* 336 */ 210026,
/* 337 */ 9999,
/* 338 */ 9999,
/* 339 */ 9999,
/* 340 */ 215009,
/* 341 */ 9999,
/* 342 */ 9999,
/* 343 */ 9999,
/* 344 */ 217009,
/* 345 */ 9999,
/* 346 */ 9999,
/* 347 */ 9999,
/* 348 */ 219009,
/* 349 */ 9999,
/* 350 */ 9999,
/* 351 */ 9999,
/* 352 */ 9999,
/* 353 */ 221009,
/* 354 */ 9999,
/* 355 */ 9999,
/* 356 */ 9999,
/* 357 */ 9999,
/* 358 */ 223009,
/* 359 */ 9999,
/* 360 */ 9999,
/* 361 */ 9999,
/* 362 */ 9999,
/* 363 */ 225009,
/* 364 */ 9999,
/* 365 */ 9999,
/* 366 */ 9999,
/* 367 */ 229009,
/* 368 */ 9999,
/* 369 */ 9999,
/* 370 */ 9999,
/* 371 */ 231009,
/* 372 */ 9999,
/* 373 */ 9999,
/* 374 */ 9999,
/* 375 */ 233009,
/* 376 */ 9999,
/* 377 */ 9999,
/* 378 */ 9999,
/* 379 */ 235009,
/* 380 */ 9999,
/* 381 */ 9999,
/* 382 */ 9999,
/* 383 */ 239011,
/* 384 */ 9999,
/* 385 */ 9999,
/* 386 */ 9999,
/* 387 */ 241010,
/* 388 */ 9999,
/* 389 */ 245005,
/* 390 */ 250005,
/* 391 */ 258005,
/* 392 */ 9999,
/* 393 */ 245005,
/* 394 */ 9999,
/* 395 */ 9999,
/* 396 */ 9999,
/* 397 */ 246020,
/* 398 */ 9999,
/* 399 */ 9999,
/* 400 */ 9999,
/* 401 */ 248022,
/* 402 */ 9999,
/* 403 */ 251013,
/* 404 */ 252013,
/* 405 */ 251031,
/* 406 */ 9999,
/* 407 */ 251031,
/* 408 */ 9999,
/* 409 */ 9999,
/* 410 */ 251031,
/* 411 */ 9999,
/* 412 */ 9999,
/* 413 */ 9999,
/* 414 */ 253028,
/* 415 */ 9999,
/* 416 */ 9999,
/* 417 */ 9999,
/* 418 */ 255030,
/* 419 */ 9999,
/* 420 */ 9999,
/* 421 */ 258048,
/* 422 */ 9999,
/* 423 */ 258007,
/* 424 */ 9999,
/* 425 */ 9999,
/* 426 */ 258007,
/* 427 */ 9999,
/* 428 */ 262005,
/* 429 */ 9999,
/* 430 */ 274005,
/* 431 */ 9999,
/* 432 */ 262005,
/* 433 */ 9999,
/* 434 */ 9999,
/* 435 */ 9999,
/* 436 */ 263021,
/* 437 */ 9999,
/* 438 */ 9999,
/* 439 */ 9999,
/* 440 */ 265023,
/* 441 */ 9999,
/* 442 */ 9999,
/* 443 */ 9999,
/* 444 */ 267019,
/* 445 */ 9999,
/* 446 */ 9999,
/* 447 */ 9999,
/* 448 */ 269019,
/* 449 */ 9999,
/* 450 */ 9999,
/* 451 */ 9999,
/* 452 */ 271019,
/* 453 */ 9999,
/* 454 */ 9999,
/* 455 */ 274046,
/* 456 */ 9999,
/* 457 */ 274007,
/* 458 */ 9999,
/* 459 */ 9999,
/* 460 */ 274007,
0
};
/* only for BIGHASH (see art.c)
extern int DHITS[];
int DHITS[462];
*/
int TABLE[99][256];
init_dirsets() {
TABLE[47][0] = 1;
TABLE[47][281] = 1;
TABLE[47][40] = 1;
TABLE[47][270] = 1;
TABLE[47][271] = 1;
TABLE[47][280] = 1;
TABLE[47][279] = 1;
TABLE[47][278] = 1;
TABLE[47][269] = 1;
TABLE[47][268] = 1;
TABLE[47][267] = 1;
TABLE[47][266] = 1;
TABLE[47][265] = 1;
TABLE[47][258] = 1;
TABLE[47][259] = 1;
TABLE[47][257] = 1;
TABLE[47][261] = 1;
TABLE[47][277] = 1;
TABLE[47][256] = 1;
TABLE[1][0] = 1;
TABLE[1][281] = 1;
TABLE[1][40] = 1;
TABLE[1][270] = 1;
TABLE[1][277] = 1;
TABLE[1][261] = 1;
TABLE[1][257] = 1;
TABLE[1][259] = 1;
TABLE[1][258] = 1;
TABLE[1][265] = 1;
TABLE[1][266] = 1;
TABLE[1][267] = 1;
TABLE[1][268] = 1;
TABLE[1][269] = 1;
TABLE[1][278] = 1;
TABLE[1][279] = 1;
TABLE[1][280] = 1;
TABLE[1][271] = 1;
TABLE[1][256] = 1;
TABLE[48][0] = 1;
TABLE[48][281] = 1;
TABLE[48][40] = 1;
TABLE[48][270] = 1;
TABLE[48][271] = 1;
TABLE[48][280] = 1;
TABLE[48][279] = 1;
TABLE[48][278] = 1;
TABLE[48][269] = 1;
TABLE[48][268] = 1;
TABLE[48][267] = 1;
TABLE[48][266] = 1;
TABLE[48][265] = 1;
TABLE[48][258] = 1;
TABLE[48][259] = 1;
TABLE[48][257] = 1;
TABLE[48][261] = 1;
TABLE[48][277] = 1;
TABLE[48][256] = 1;
TABLE[49][281] = 1;
TABLE[92][0] = 1;
TABLE[2][40] = 1;
TABLE[3][281] = 1;
TABLE[3][0] = 1;
TABLE[3][41] = 1;
TABLE[3][270] = 1;
TABLE[3][277] = 1;
TABLE[3][261] = 1;
TABLE[3][257] = 1;
TABLE[3][259] = 1;
TABLE[3][258] = 1;
TABLE[3][265] = 1;
TABLE[3][266] = 1;
TABLE[3][267] = 1;
TABLE[3][268] = 1;
TABLE[3][269] = 1;
TABLE[3][278] = 1;
TABLE[3][279] = 1;
TABLE[3][280] = 1;
TABLE[3][271] = 1;
TABLE[3][40] = 1;
TABLE[3][256] = 1;
TABLE[50][281] = 1;
TABLE[50][40] = 1;
TABLE[50][270] = 1;
TABLE[50][265] = 1;
TABLE[50][266] = 1;
TABLE[50][267] = 1;
TABLE[50][268] = 1;
TABLE[50][269] = 1;
TABLE[50][278] = 1;
TABLE[50][279] = 1;
TABLE[50][280] = 1;
TABLE[50][271] = 1;
TABLE[50][0] = 1;
TABLE[50][41] = 1;
TABLE[50][258] = 1;
TABLE[50][259] = 1;
TABLE[50][257] = 1;
TABLE[50][261] = 1;
TABLE[50][277] = 1;
TABLE[50][256] = 1;
TABLE[51][281] = 1;
TABLE[51][0] = 1;
TABLE[51][41] = 1;
TABLE[51][270] = 1;
TABLE[51][40] = 1;
TABLE[51][257] = 1;
TABLE[51][271] = 1;
TABLE[51][280] = 1;
TABLE[51][279] = 1;
TABLE[51][278] = 1;
TABLE[51][269] = 1;
TABLE[51][268] = 1;
TABLE[51][267] = 1;
TABLE[51][266] = 1;
TABLE[51][265] = 1;
TABLE[51][258] = 1;
TABLE[51][259] = 1;
TABLE[51][261] = 1;
TABLE[51][277] = 1;
TABLE[51][256] = 1;
TABLE[4][258] = 1;
TABLE[5][259] = 1;
TABLE[6][257] = 1;
TABLE[7][261] = 1;
TABLE[8][281] = 1;
TABLE[8][40] = 1;
TABLE[8][270] = 1;
TABLE[8][261] = 1;
TABLE[8][259] = 1;
TABLE[8][258] = 1;
TABLE[8][265] = 1;
TABLE[8][266] = 1;
TABLE[8][267] = 1;
TABLE[8][268] = 1;
TABLE[8][269] = 1;
TABLE[8][278] = 1;
TABLE[8][279] = 1;
TABLE[8][280] = 1;
TABLE[8][271] = 1;
TABLE[8][0] = 1;
TABLE[8][41] = 1;
TABLE[8][277] = 1;
TABLE[8][256] = 1;
TABLE[8][257] = 1;
TABLE[9][257] = 1;
TABLE[9][40] = 1;
TABLE[9][270] = 1;
TABLE[9][277] = 1;
TABLE[9][261] = 1;
TABLE[9][259] = 1;
TABLE[9][258] = 1;
TABLE[9][265] = 1;
TABLE[9][266] = 1;
TABLE[9][267] = 1;
TABLE[9][268] = 1;
TABLE[9][269] = 1;
TABLE[9][278] = 1;
TABLE[9][279] = 1;
TABLE[9][280] = 1;
TABLE[9][271] = 1;
TABLE[9][256] = 1;
TABLE[10][257] = 1;
TABLE[10][40] = 1;
TABLE[10][270] = 1;
TABLE[10][277] = 1;
TABLE[10][261] = 1;
TABLE[10][259] = 1;
TABLE[10][258] = 1;
TABLE[10][265] = 1;
TABLE[10][266] = 1;
TABLE[10][267] = 1;
TABLE[10][268] = 1;
TABLE[10][269] = 1;
TABLE[10][278] = 1;
TABLE[10][279] = 1;
TABLE[10][280] = 1;
TABLE[10][271] = 1;
TABLE[10][256] = 1;
TABLE[52][257] = 1;
TABLE[53][40] = 1;
TABLE[53][270] = 1;
TABLE[53][271] = 1;
TABLE[53][280] = 1;
TABLE[53][279] = 1;
TABLE[53][278] = 1;
TABLE[53][269] = 1;
TABLE[53][268] = 1;
TABLE[53][267] = 1;
TABLE[53][266] = 1;
TABLE[53][265] = 1;
TABLE[53][258] = 1;
TABLE[53][259] = 1;
TABLE[53][257] = 1;
TABLE[53][261] = 1;
TABLE[53][277] = 1;
TABLE[53][256] = 1;
TABLE[54][40] = 1;
TABLE[55][257] = 1;
TABLE[56][281] = 1;
TABLE[56][0] = 1;
TABLE[56][41] = 1;
TABLE[56][40] = 1;
TABLE[56][270] = 1;
TABLE[56][271] = 1;
TABLE[56][280] = 1;
TABLE[56][279] = 1;
TABLE[56][278] = 1;
TABLE[56][269] = 1;
TABLE[56][268] = 1;
TABLE[56][267] = 1;
TABLE[56][266] = 1;
TABLE[56][265] = 1;
TABLE[56][258] = 1;
TABLE[56][259] = 1;
TABLE[56][257] = 1;
TABLE[56][261] = 1;
TABLE[56][277] = 1;
TABLE[56][256] = 1;
TABLE[57][40] = 1;
TABLE[58][257] = 1;
TABLE[59][40] = 1;
TABLE[59][270] = 1;
TABLE[59][271] = 1;
TABLE[59][280] = 1;
TABLE[59][279] = 1;
TABLE[59][278] = 1;
TABLE[59][269] = 1;
TABLE[59][268] = 1;
TABLE[59][267] = 1;
TABLE[59][266] = 1;
TABLE[59][265] = 1;
TABLE[59][258] = 1;
TABLE[59][259] = 1;
TABLE[59][257] = 1;
TABLE[59][261] = 1;
TABLE[59][277] = 1;
TABLE[59][256] = 1;
TABLE[60][40] = 1;
TABLE[11][265] = 1;
TABLE[12][266] = 1;
TABLE[13][267] = 1;
TABLE[14][268] = 1;
TABLE[15][269] = 1;
TABLE[16][270] = 1;
TABLE[17][278] = 1;
TABLE[18][279] = 1;
TABLE[19][280] = 1;
TABLE[20][271] = 1;
TABLE[21][258] = 1;
TABLE[61][257] = 1;
TABLE[62][41] = 1;
TABLE[62][40] = 1;
TABLE[62][270] = 1;
TABLE[62][271] = 1;
TABLE[62][280] = 1;
TABLE[62][279] = 1;
TABLE[62][278] = 1;
TABLE[62][269] = 1;
TABLE[62][268] = 1;
TABLE[62][267] = 1;
TABLE[62][266] = 1;
TABLE[62][265] = 1;
TABLE[62][258] = 1;
TABLE[62][259] = 1;
TABLE[62][257] = 1;
TABLE[62][261] = 1;
TABLE[62][277] = 1;
TABLE[62][256] = 1;
TABLE[22][259] = 1;
TABLE[63][257] = 1;
TABLE[64][41] = 1;
TABLE[64][40] = 1;
TABLE[64][270] = 1;
TABLE[64][271] = 1;
TABLE[64][280] = 1;
TABLE[64][279] = 1;
TABLE[64][278] = 1;
TABLE[64][269] = 1;
TABLE[64][268] = 1;
TABLE[64][267] = 1;
TABLE[64][266] = 1;
TABLE[64][265] = 1;
TABLE[64][258] = 1;
TABLE[64][259] = 1;
TABLE[64][257] = 1;
TABLE[64][261] = 1;
TABLE[64][277] = 1;
TABLE[64][256] = 1;
TABLE[23][257] = 1;
TABLE[65][40] = 1;
TABLE[93][260] = 1;
TABLE[24][261] = 1;
TABLE[25][261] = 1;
TABLE[26][261] = 1;
TABLE[66][257] = 1;
TABLE[67][41] = 1;
TABLE[67][40] = 1;
TABLE[67][270] = 1;
TABLE[67][271] = 1;
TABLE[67][280] = 1;
TABLE[67][279] = 1;
TABLE[67][278] = 1;
TABLE[67][269] = 1;
TABLE[67][268] = 1;
TABLE[67][267] = 1;
TABLE[67][266] = 1;
TABLE[67][265] = 1;
TABLE[67][258] = 1;
TABLE[67][259] = 1;
TABLE[67][257] = 1;
TABLE[67][261] = 1;
TABLE[67][277] = 1;
TABLE[67][256] = 1;
TABLE[68][257] = 1;
TABLE[69][41] = 1;
TABLE[69][40] = 1;
TABLE[69][270] = 1;
TABLE[69][271] = 1;
TABLE[69][280] = 1;
TABLE[69][279] = 1;
TABLE[69][278] = 1;
TABLE[69][269] = 1;
TABLE[69][268] = 1;
TABLE[69][267] = 1;
TABLE[69][266] = 1;
TABLE[69][265] = 1;
TABLE[69][258] = 1;
TABLE[69][259] = 1;
TABLE[69][257] = 1;
TABLE[69][261] = 1;
TABLE[69][277] = 1;
TABLE[69][256] = 1;
TABLE[70][257] = 1;
TABLE[71][41] = 1;
TABLE[71][40] = 1;
TABLE[71][270] = 1;
TABLE[71][271] = 1;
TABLE[71][280] = 1;
TABLE[71][279] = 1;
TABLE[71][278] = 1;
TABLE[71][269] = 1;
TABLE[71][268] = 1;
TABLE[71][267] = 1;
TABLE[71][266] = 1;
TABLE[71][265] = 1;
TABLE[71][258] = 1;
TABLE[71][259] = 1;
TABLE[71][257] = 1;
TABLE[71][261] = 1;
TABLE[71][277] = 1;
TABLE[71][256] = 1;
TABLE[27][277] = 1;
TABLE[27][257] = 1;
TABLE[27][256] = 1;
TABLE[72][256] = 1;
TABLE[72][257] = 1;
TABLE[94][277] = 1;
TABLE[73][257] = 1;
TABLE[74][41] = 1;
TABLE[74][40] = 1;
TABLE[74][270] = 1;
TABLE[74][271] = 1;
TABLE[74][280] = 1;
TABLE[74][279] = 1;
TABLE[74][278] = 1;
TABLE[74][269] = 1;
TABLE[74][268] = 1;
TABLE[74][267] = 1;
TABLE[74][266] = 1;
TABLE[74][265] = 1;
TABLE[74][258] = 1;
TABLE[74][259] = 1;
TABLE[74][257] = 1;
TABLE[74][261] = 1;
TABLE[74][277] = 1;
TABLE[74][256] = 1;
TABLE[28][40] = 1;
TABLE[28][256] = 1;
TABLE[28][257] = 1;
TABLE[29][40] = 1;
TABLE[29][256] = 1;
TABLE[29][257] = 1;
TABLE[30][40] = 1;
TABLE[75][262] = 1;
TABLE[75][263] = 1;
TABLE[95][281] = 1;
TABLE[95][40] = 1;
TABLE[95][270] = 1;
TABLE[95][277] = 1;
TABLE[95][261] = 1;
TABLE[95][257] = 1;
TABLE[95][259] = 1;
TABLE[95][258] = 1;
TABLE[95][265] = 1;
TABLE[95][266] = 1;
TABLE[95][267] = 1;
TABLE[95][268] = 1;
TABLE[95][269] = 1;
TABLE[95][278] = 1;
TABLE[95][279] = 1;
TABLE[95][280] = 1;
TABLE[95][271] = 1;
TABLE[95][256] = 1;
TABLE[95][0] = 1;
TABLE[95][41] = 1;
TABLE[31][40] = 1;
TABLE[32][257] = 1;
TABLE[32][256] = 1;
TABLE[76][257] = 1;
TABLE[77][256] = 1;
TABLE[78][257] = 1;
TABLE[79][256] = 1;
TABLE[33][61] = 1;
TABLE[34][60] = 1;
TABLE[35][62] = 1;
TABLE[36][60] = 1;
TABLE[37][62] = 1;
TABLE[38][33] = 1;
TABLE[39][43] = 1;
TABLE[40][45] = 1;
TABLE[41][42] = 1;
TABLE[42][47] = 1;
TABLE[43][262] = 1;
TABLE[44][263] = 1;
TABLE[45][257] = 1;
TABLE[45][256] = 1;
TABLE[80][257] = 1;
TABLE[81][256] = 1;
TABLE[84][43] = 1;
TABLE[84][45] = 1;
TABLE[84][42] = 1;
TABLE[84][47] = 1;
TABLE[96][44] = 1;
TABLE[96][40] = 1;
TABLE[96][41] = 1;
TABLE[96][277] = 1;
TABLE[82][257] = 1;
TABLE[83][256] = 1;
TABLE[85][44] = 1;
TABLE[97][40] = 1;
TABLE[97][41] = 1;
TABLE[97][277] = 1;
TABLE[46][272] = 1;
TABLE[46][273] = 1;
TABLE[46][274] = 1;
TABLE[46][275] = 1;
TABLE[46][276] = 1;
TABLE[86][272] = 1;
TABLE[87][273] = 1;
TABLE[88][274] = 1;
TABLE[89][275] = 1;
TABLE[90][276] = 1;
TABLE[91][44] = 1;
TABLE[98][40] = 1;
}

extern int yydirset();
int yydirset(i,j)
   int i,j;
{
   return TABLE[i][j];
}
int yytransparent(n)
   int n;
{
   switch(n) {
      case 1: return 1; break;
      case 6: return 1; break;
      case 10: return 1; break;
      case 23: return 1; break;
      case 33: return 1; break;
      case 41: return 1; break;
      case 61: return 1; break;
      case 73: return 1; break;
      case 87: return 1; break;
      case 101: return 1; break;
      case 115: return 0; break;
      case 159: return 0; break;
      case 167: return 1; break;
      case 175: return 0; break;
      case 183: return 1; break;
      case 191: return 0; break;
      case 198: return 1; break;
      case 207: return 0; break;
      case 236: return 1; break;
      case 244: return 1; break;
      case 252: return 1; break;
      case 260: return 1; break;
      case 269: return 1; break;
      case 276: return 1; break;
      case 284: return 0; break;
      case 301: return 1; break;
      case 309: return 0; break;
      case 321: return 0; break;
      case 329: return 0; break;
      case 337: return 0; break;
      case 364: return 0; break;
      case 380: return 0; break;
      case 388: return 0; break;
      case 394: return 0; break;
      case 402: return 1; break;
      case 411: return 0; break;
      case 419: return 1; break;
      case 427: return 0; break;
      case 433: return 0; break;
      case 453: return 1; break;
   }
}
char * yyprintname(n)
   int n;
{
   if (n <= 50000)
      switch(n) {
         case 1: return "YYSTART"; break;
         case 6: return "consulta"; break;
         case 10: return "Subphrase"; break;
         case 23: return "operacao_consulta"; break;
         case 33: return "Subphrase"; break;
         case 41: return "operacao_unaria"; break;
         case 61: return "operacao_binaria"; break;
         case 73: return "Subphrase"; break;
         case 87: return "Subphrase"; break;
         case 101: return "Subphrase"; break;
         case 115: return "tipo_operacao_binaria"; break;
         case 159: return "selecao"; break;
         case 167: return "Subphrase"; break;
         case 175: return "projecao"; break;
         case 183: return "Subphrase"; break;
         case 191: return "renomeacao1"; break;
         case 198: return "Subphrase"; break;
         case 207: return "renomeacao2"; break;
         case 236: return "Subphrase"; break;
         case 244: return "Subphrase"; break;
         case 252: return "Subphrase"; break;
         case 260: return "agrupamento"; break;
         case 269: return "Subphrase"; break;
         case 276: return "Subphrase"; break;
         case 284: return "predicado"; break;
         case 301: return "Subphrase"; break;
         case 309: return "condicao"; break;
         case 321: return "Subphrase"; break;
         case 329: return "Subphrase"; break;
         case 337: return "operador_comparacao"; break;
         case 364: return "operador_aritmetico"; break;
         case 380: return "operador_booleano"; break;
         case 388: return "lista_atributos"; break;
         case 394: return "Subphrase"; break;
         case 402: return "Subphrase"; break;
         case 411: return "Subphrase"; break;
         case 419: return "Subphrase"; break;
         case 427: return "lista_funcoes_agregadas"; break;
         case 433: return "Subphrase"; break;
         case 453: return "Subphrase"; break;
   }
   else 
      switch(n-50000) {
         case 281: return "COMENTARIO"; break;
         case 280: return "JUNCAO_EXTERNA_COMPLETA"; break;
         case 279: return "JUNCAO_EXTERNA_DIREITA"; break;
         case 278: return "JUNCAO_EXTERNA_ESQUERDA"; break;
         case 277: return "FSCRIPT"; break;
         case 276: return "SUM"; break;
         case 275: return "MIN"; break;
         case 274: return "MAX"; break;
         case 273: return "AVERAGE"; break;
         case 272: return "COUNT"; break;
         case 271: return "DIVISAO"; break;
         case 270: return "JUNCAO_NATURAL"; break;
         case 269: return "JUNCAO"; break;
         case 268: return "PRODUTO_CARTESIANO"; break;
         case 267: return "SUBTRACAO"; break;
         case 266: return "INTERSECCAO"; break;
         case 265: return "UNIAO"; break;
         case 264: return "NOT"; break;
         case 263: return "OR"; break;
         case 262: return "AND"; break;
         case 261: return "RHO"; break;
         case 260: return "ATRIBUICAO"; break;
         case 259: return "PI"; break;
         case 258: return "SIGMA"; break;
         case 257: return "NOME"; break;
         case 256: return "NUMERO"; break;
      }
   return "special_character";
}
