#line 1 "spec.acc"

#include "yystype.h"
#include "treefunctions.c"

# line 7 "yygrammar.c"
#include "yygrammar.h"

YYSTART ()
{
   switch(yyselect()) {
   case 48: {
      consulta();
      get_lexval();
      } break;
   }
}

consulta ()
{
   switch(yyselect()) {
   case 1: {
#line 8 "spec.acc"
_tool_initialize();
# line 26 "yygrammar.c"
      while (1) {
         switch (yyselect()) {
         case 49: {
            operacao_consulta();
            } break;
         default: goto yy1;
         }
      }
      yy1: ;
#line 8 "spec.acc"
_build_tree();
# line 38 "yygrammar.c"
      } break;
   }
}

operacao_consulta ()
{
   switch(yyselect()) {
   case 2: {
      switch (yyselect()) {
      case 50: {
         get_lexval();
#line 12 "spec.acc"
_add_node_stack("(");
# line 52 "yygrammar.c"
         } break;
      default: ;
      }
      switch (yyselect()) {
      case 51: {
         operacao_unaria();
         } break;
      case 52: {
         operacao_binaria();
         } break;
      default: printf("???\n"); exit(1);
      }
      switch (yyselect()) {
      case 53: {
         get_lexval();
#line 12 "spec.acc"
_add_node_stack(")");
# line 70 "yygrammar.c"
         } break;
      default: ;
      }
      } break;
   case 3: {
      get_lexval();
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
      case 54: {
         get_lexval();
         y = yylval;
#line 30 "spec.acc"
_add_node_stack(y.stringval);
# line 113 "yygrammar.c"
         } break;
      case 55: {
         operacao_consulta();
         } break;
      default: printf("???\n"); exit(1);
      }
      tipo_operacao_binaria();
      switch (yyselect()) {
      case 56: {
         get_lexval();
         y = yylval;
#line 30 "spec.acc"
_add_node_stack(y.stringval);
# line 127 "yygrammar.c"
         } break;
      case 57: {
         operacao_consulta();
         } break;
      case 58: {
         get_lexval();
#line 30 "spec.acc"
_add_node_stack("(");
# line 136 "yygrammar.c"
         get_lexval();
         y = yylval;
#line 30 "spec.acc"
_add_node_stack(y.stringval);
# line 141 "yygrammar.c"
         get_lexval();
#line 30 "spec.acc"
_add_node_stack(")");
# line 145 "yygrammar.c"
         } break;
      default: printf("???\n"); exit(1);
      }
      } break;
   case 10: {
      switch (yyselect()) {
      case 59: {
         get_lexval();
         y = yylval;
#line 32 "spec.acc"
_add_node_stack(y.stringval);
# line 157 "yygrammar.c"
         } break;
      case 60: {
         operacao_consulta();
         } break;
      default: printf("???\n"); exit(1);
      }
      get_lexval();
#line 32 "spec.acc"
_add_node_stack("JUNCAO_NATURAL");
# line 167 "yygrammar.c"
      renomeacao2();
      } break;
   }
}

tipo_operacao_binaria ()
{
   switch(yyselect()) {
   case 11: {
      get_lexval();
#line 36 "spec.acc"
_add_node_stack("UNIAO");
# line 180 "yygrammar.c"
      } break;
   case 12: {
      get_lexval();
#line 38 "spec.acc"
_add_node_stack("INTERSECCAO");
# line 186 "yygrammar.c"
      } break;
   case 13: {
      get_lexval();
#line 40 "spec.acc"
_add_node_stack("SUBTRACAO");
# line 192 "yygrammar.c"
      } break;
   case 14: {
      get_lexval();
#line 42 "spec.acc"
_add_node_stack("PRODUTO_CARTESIANO");
# line 198 "yygrammar.c"
      } break;
   case 15: {
      get_lexval();
      predicado();
#line 44 "spec.acc"
_add_node_stack("JUNCAO");
# line 205 "yygrammar.c"
      } break;
   case 16: {
      get_lexval();
#line 46 "spec.acc"
_add_node_stack("JUNCAO_NATURAL");
# line 211 "yygrammar.c"
      } break;
   case 17: {
      get_lexval();
      predicado();
#line 48 "spec.acc"
_add_node_stack("JUNCAO_EXTERNA_ESQUERDA");
# line 218 "yygrammar.c"
      } break;
   case 18: {
      get_lexval();
      predicado();
#line 50 "spec.acc"
_add_node_stack("JUNCAO_EXTERNA_DIREITA");
# line 225 "yygrammar.c"
      } break;
   case 19: {
      get_lexval();
      predicado();
#line 52 "spec.acc"
_add_node_stack("JUNCAO_EXTERNA_COMPLETA");
# line 232 "yygrammar.c"
      } break;
   case 20: {
      get_lexval();
#line 54 "spec.acc"
_add_node_stack("DIVISAO");
# line 238 "yygrammar.c"
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
#line 58 "spec.acc"
_add_node_stack("SIGMA");
# line 252 "yygrammar.c"
      get_lexval();
#line 58 "spec.acc"
_add_node_stack("(");
# line 256 "yygrammar.c"
      switch (yyselect()) {
      case 61: {
         get_lexval();
         y = yylval;
#line 58 "spec.acc"
_add_node_stack(y.stringval);
# line 263 "yygrammar.c"
         } break;
      case 62: {
         operacao_consulta();
         } break;
      default: printf("???\n"); exit(1);
      }
      get_lexval();
#line 58 "spec.acc"
_add_node_stack(")");
# line 273 "yygrammar.c"
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
#line 62 "spec.acc"
_add_node_stack("PI");
# line 287 "yygrammar.c"
      get_lexval();
#line 62 "spec.acc"
_add_node_stack("(");
# line 291 "yygrammar.c"
      switch (yyselect()) {
      case 63: {
         get_lexval();
         y = yylval;
#line 62 "spec.acc"
_add_node_stack(y.stringval);
# line 298 "yygrammar.c"
         } break;
      case 64: {
         operacao_consulta();
         } break;
      default: printf("???\n"); exit(1);
      }
      get_lexval();
#line 62 "spec.acc"
_add_node_stack(")");
# line 308 "yygrammar.c"
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
#line 66 "spec.acc"
_add_node_stack(y.stringval);
# line 322 "yygrammar.c"
      get_lexval();
#line 66 "spec.acc"
_add_node_stack("ATRIBUICAO");
# line 326 "yygrammar.c"
      operacao_consulta();
      } break;
   case 24: {
      get_lexval();
      y = yylval;
      get_lexval();
      lista_atributos();
#line 68 "spec.acc"
_add_node_stack(y.stringval);
# line 336 "yygrammar.c"
      get_lexval();
      get_lexval();
#line 68 "spec.acc"
_add_node_stack("ATRIBUICAO");
# line 341 "yygrammar.c"
      operacao_consulta();
      } break;
   }
}

renomeacao2 ()
{
   YYSTYPE y;
   switch(yyselect()) {
   case 25: {
      get_lexval();
      get_lexval();
      y = yylval;
#line 72 "spec.acc"
_add_symbols_attribute(y.stringval,1);
# line 357 "yygrammar.c"
#line 72 "spec.acc"
 _add_node_stack("RHO");
# line 360 "yygrammar.c"
      get_lexval();
#line 72 "spec.acc"
_add_node_stack("(");
# line 364 "yygrammar.c"
      switch (yyselect()) {
      case 65: {
         get_lexval();
         y = yylval;
#line 72 "spec.acc"
_add_node_stack(y.stringval);
# line 371 "yygrammar.c"
         } break;
      case 66: {
         operacao_consulta();
         } break;
      default: printf("???\n"); exit(1);
      }
      get_lexval();
#line 72 "spec.acc"
_add_node_stack(")");
# line 381 "yygrammar.c"
      } break;
   case 26: {
      get_lexval();
      get_lexval();
      y = yylval;
#line 74 "spec.acc"
_add_symbols_attribute(y.stringval,1);
# line 389 "yygrammar.c"
      get_lexval();
#line 74 "spec.acc"
_add_symbols_attribute("(",1);
# line 393 "yygrammar.c"
      lista_atributos();
      get_lexval();
#line 74 "spec.acc"
_add_symbols_attribute(")",1);
# line 398 "yygrammar.c"
#line 74 "spec.acc"
_add_node_stack("RHO");
# line 401 "yygrammar.c"
      get_lexval();
#line 74 "spec.acc"
_add_node_stack("(");
# line 405 "yygrammar.c"
      switch (yyselect()) {
      case 67: {
         get_lexval();
         y = yylval;
#line 74 "spec.acc"
_add_node_stack(y.stringval);
# line 412 "yygrammar.c"
         } break;
      case 68: {
         operacao_consulta();
         } break;
      default: printf("???\n"); exit(1);
      }
      get_lexval();
#line 74 "spec.acc"
_add_node_stack(")");
# line 422 "yygrammar.c"
      } break;
   case 27: {
      get_lexval();
      get_lexval();
#line 76 "spec.acc"
_add_symbols_attribute("(",1);
# line 429 "yygrammar.c"
      lista_atributos();
      get_lexval();
#line 76 "spec.acc"
_add_symbols_attribute(")",1);
# line 434 "yygrammar.c"
#line 76 "spec.acc"
_add_node_stack("RHO");
# line 437 "yygrammar.c"
      get_lexval();
#line 76 "spec.acc"
_add_node_stack("(");
# line 441 "yygrammar.c"
      switch (yyselect()) {
      case 69: {
         get_lexval();
         y = yylval;
#line 76 "spec.acc"
_add_node_stack(y.stringval);
# line 448 "yygrammar.c"
         } break;
      case 70: {
         operacao_consulta();
         } break;
      default: printf("???\n"); exit(1);
      }
      get_lexval();
#line 76 "spec.acc"
_add_node_stack(")");
# line 458 "yygrammar.c"
      } break;
   }
}

agrupamento ()
{
   YYSTYPE y;
   switch(yyselect()) {
   case 28: {
      switch (yyselect()) {
      case 71: {
         lista_atributos();
         } break;
      default: ;
      }
      get_lexval();
      lista_funcoes_agregadas();
#line 80 "spec.acc"
 _add_node_stack("FSCRIPT");
# line 478 "yygrammar.c"
      get_lexval();
      switch (yyselect()) {
      case 72: {
         get_lexval();
         y = yylval;
#line 80 "spec.acc"
_add_node_stack(y.stringval);
# line 486 "yygrammar.c"
         } break;
      case 73: {
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
   case 29: {
      condicao();
      } break;
   case 30: {
      condicao();
      operador_booleano();
      predicado();
      } break;
   case 31: {
      get_lexval();
#line 88 "spec.acc"
_add_symbols_predicate("(");
# line 513 "yygrammar.c"
      condicao();
      operador_booleano();
      predicado();
      get_lexval();
#line 88 "spec.acc"
_add_symbols_predicate(")");
# line 520 "yygrammar.c"
      switch (yyselect()) {
      case 74: {
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
   case 32: {
      get_lexval();
#line 92 "spec.acc"
_add_symbols_predicate("(");
# line 540 "yygrammar.c"
      switch (yyselect()) {
      case 75: {
         get_lexval();
         a = yylval;
#line 92 "spec.acc"
_add_symbols_predicate(a.stringval);
# line 547 "yygrammar.c"
         } break;
      case 76: {
         get_lexval();
         a = yylval;
#line 92 "spec.acc"
_add_symbols_predicate(a.stringval);
# line 554 "yygrammar.c"
         } break;
      default: printf("???\n"); exit(1);
      }
      operador_comparacao();
      switch (yyselect()) {
      case 77: {
         get_lexval();
         a = yylval;
#line 92 "spec.acc"
_add_symbols_predicate(a.stringval);
# line 565 "yygrammar.c"
         } break;
      case 78: {
         get_lexval();
         a = yylval;
#line 92 "spec.acc"
_add_symbols_predicate(a.stringval);
# line 572 "yygrammar.c"
         } break;
      default: printf("???\n"); exit(1);
      }
      get_lexval();
#line 92 "spec.acc"
_add_symbols_predicate(")");
# line 579 "yygrammar.c"
      } break;
   case 33: {
      switch (yyselect()) {
      case 79: {
         get_lexval();
         a = yylval;
#line 93 "spec.acc"
_add_symbols_predicate(a.stringval);
# line 588 "yygrammar.c"
         } break;
      case 80: {
         get_lexval();
         a = yylval;
#line 93 "spec.acc"
_add_symbols_predicate(a.stringval);
# line 595 "yygrammar.c"
         } break;
      default: printf("???\n"); exit(1);
      }
      operador_comparacao();
      switch (yyselect()) {
      case 81: {
         get_lexval();
         a = yylval;
#line 93 "spec.acc"
_add_symbols_predicate(a.stringval);
# line 606 "yygrammar.c"
         } break;
      case 82: {
         get_lexval();
         a = yylval;
#line 93 "spec.acc"
_add_symbols_predicate(a.stringval);
# line 613 "yygrammar.c"
         } break;
      default: printf("???\n"); exit(1);
      }
      } break;
   }
}

operador_comparacao ()
{
   switch(yyselect()) {
   case 34: {
      get_lexval();
#line 97 "spec.acc"
_add_symbols_predicate("=");
# line 628 "yygrammar.c"
      } break;
   case 35: {
      get_lexval();
#line 99 "spec.acc"
_add_symbols_predicate("<");
# line 634 "yygrammar.c"
      } break;
   case 36: {
      get_lexval();
#line 101 "spec.acc"
_add_symbols_predicate(">");
# line 640 "yygrammar.c"
      } break;
   case 37: {
      get_lexval();
      get_lexval();
#line 103 "spec.acc"
_add_symbols_predicate("<=");
# line 647 "yygrammar.c"
      } break;
   case 38: {
      get_lexval();
      get_lexval();
#line 105 "spec.acc"
_add_symbols_predicate(">=");
# line 654 "yygrammar.c"
      } break;
   case 39: {
      get_lexval();
      get_lexval();
#line 107 "spec.acc"
_add_symbols_predicate("!=");
# line 661 "yygrammar.c"
      } break;
   }
}

operador_aritmetico ()
{
   switch(yyselect()) {
   case 40: {
      get_lexval();
#line 111 "spec.acc"
_add_symbols_attribute("+",1);
# line 673 "yygrammar.c"
      } break;
   case 41: {
      get_lexval();
#line 113 "spec.acc"
_add_symbols_attribute("-",1);
# line 679 "yygrammar.c"
      } break;
   case 42: {
      get_lexval();
#line 115 "spec.acc"
_add_symbols_attribute("*",1);
# line 685 "yygrammar.c"
      } break;
   case 43: {
      get_lexval();
#line 117 "spec.acc"
_add_symbols_attribute("/",1);
# line 691 "yygrammar.c"
      } break;
   }
}

operador_booleano ()
{
   switch(yyselect()) {
   case 44: {
      get_lexval();
#line 121 "spec.acc"
_add_symbols_predicate(" AND ");
# line 703 "yygrammar.c"
      } break;
   case 45: {
      get_lexval();
#line 123 "spec.acc"
_add_symbols_predicate(" OR ");
# line 709 "yygrammar.c"
      } break;
   }
}

lista_atributos ()
{
   YYSTYPE a;
   switch(yyselect()) {
   case 46: {
      switch (yyselect()) {
      case 83: {
         get_lexval();
         a = yylval;
#line 127 "spec.acc"
_add_symbols_attribute(a.stringval,1);
# line 725 "yygrammar.c"
         } break;
      case 84: {
         get_lexval();
         a = yylval;
#line 127 "spec.acc"
_add_symbols_attribute(a.stringval,1);
# line 732 "yygrammar.c"
         } break;
      default: printf("???\n"); exit(1);
      }
      while (1) {
         switch (yyselect()) {
         case 87: {
            operador_aritmetico();
            switch (yyselect()) {
            case 85: {
               get_lexval();
               a = yylval;
#line 127 "spec.acc"
_add_symbols_attribute(a.stringval,1);
# line 746 "yygrammar.c"
               } break;
            case 86: {
               get_lexval();
               a = yylval;
#line 127 "spec.acc"
_add_symbols_attribute(a.stringval,1);
# line 753 "yygrammar.c"
               } break;
            default: printf("???\n"); exit(1);
            }
            } break;
         default: goto yy2;
         }
      }
      yy2: ;
      switch (yyselect()) {
      case 88: {
         get_lexval();
#line 127 "spec.acc"
_add_symbols_attribute(",",1);
# line 767 "yygrammar.c"
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
   case 47: {
      switch (yyselect()) {
      case 89: {
         get_lexval();
#line 131 "spec.acc"
_add_symbols_attribute("COUNT ",2);
# line 786 "yygrammar.c"
         } break;
      case 90: {
         get_lexval();
#line 131 "spec.acc"
_add_symbols_attribute("AVERAGE ",2);
# line 792 "yygrammar.c"
         } break;
      case 91: {
         get_lexval();
#line 131 "spec.acc"
_add_symbols_attribute("MAX ",2);
# line 798 "yygrammar.c"
         } break;
      case 92: {
         get_lexval();
#line 131 "spec.acc"
_add_symbols_attribute("MIN ",2);
# line 804 "yygrammar.c"
         } break;
      case 93: {
         get_lexval();
#line 131 "spec.acc"
_add_symbols_attribute("SUM ",2);
# line 810 "yygrammar.c"
         } break;
      default: printf("???\n"); exit(1);
      }
      get_lexval();
      y = yylval;
#line 131 "spec.acc"
_add_symbols_attribute(y.stringval,2);
# line 818 "yygrammar.c"
      switch (yyselect()) {
      case 94: {
         get_lexval();
#line 131 "spec.acc"
_add_symbols_attribute(",",2);
# line 824 "yygrammar.c"
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
int c_length = 476;
extern int yygrammar[];
int yygrammar[] = {
0,
/* 1 */ 0,
/* 2 */ 6,
/* 3 */ 50000,
/* 4 */ -1,
/* 5 */ 48,
/* 6 */ 0,
/* 7 */ 10,
/* 8 */ -6,
/* 9 */ 1,
/* 10 */ 15,
/* 11 */ 18,
/* 12 */ 10,
/* 13 */ -10,
/* 14 */ 49,
/* 15 */ 0,
/* 16 */ -10,
/* 17 */ 95,
/* 18 */ 24,
/* 19 */ 28,
/* 20 */ 35,
/* 21 */ 43,
/* 22 */ -18,
/* 23 */ 2,
/* 24 */ 0,
/* 25 */ 50281,
/* 26 */ -18,
/* 27 */ 3,
/* 28 */ 32,
/* 29 */ 50040,
/* 30 */ -28,
/* 31 */ 50,
/* 32 */ 0,
/* 33 */ -28,
/* 34 */ 96,
/* 35 */ 39,
/* 36 */ 50,
/* 37 */ -35,
/* 38 */ 51,
/* 39 */ 0,
/* 40 */ 70,
/* 41 */ -35,
/* 42 */ 52,
/* 43 */ 47,
/* 44 */ 50041,
/* 45 */ -43,
/* 46 */ 53,
/* 47 */ 0,
/* 48 */ -43,
/* 49 */ 97,
/* 50 */ 54,
/* 51 */ 156,
/* 52 */ -50,
/* 53 */ 4,
/* 54 */ 58,
/* 55 */ 172,
/* 56 */ -50,
/* 57 */ 5,
/* 58 */ 62,
/* 59 */ 188,
/* 60 */ -50,
/* 61 */ 6,
/* 62 */ 66,
/* 63 */ 203,
/* 64 */ -50,
/* 65 */ 7,
/* 66 */ 0,
/* 67 */ 256,
/* 68 */ -50,
/* 69 */ 8,
/* 70 */ 76,
/* 71 */ 82,
/* 72 */ 112,
/* 73 */ 90,
/* 74 */ -70,
/* 75 */ 9,
/* 76 */ 0,
/* 77 */ 104,
/* 78 */ 50270,
/* 79 */ 203,
/* 80 */ -70,
/* 81 */ 10,
/* 82 */ 86,
/* 83 */ 50257,
/* 84 */ -82,
/* 85 */ 54,
/* 86 */ 0,
/* 87 */ 18,
/* 88 */ -82,
/* 89 */ 55,
/* 90 */ 94,
/* 91 */ 50257,
/* 92 */ -90,
/* 93 */ 56,
/* 94 */ 98,
/* 95 */ 18,
/* 96 */ -90,
/* 97 */ 57,
/* 98 */ 0,
/* 99 */ 50040,
/* 100 */ 50257,
/* 101 */ 50041,
/* 102 */ -90,
/* 103 */ 58,
/* 104 */ 108,
/* 105 */ 50257,
/* 106 */ -104,
/* 107 */ 59,
/* 108 */ 0,
/* 109 */ 18,
/* 110 */ -104,
/* 111 */ 60,
/* 112 */ 116,
/* 113 */ 50265,
/* 114 */ -112,
/* 115 */ 11,
/* 116 */ 120,
/* 117 */ 50266,
/* 118 */ -112,
/* 119 */ 12,
/* 120 */ 124,
/* 121 */ 50267,
/* 122 */ -112,
/* 123 */ 13,
/* 124 */ 128,
/* 125 */ 50268,
/* 126 */ -112,
/* 127 */ 14,
/* 128 */ 133,
/* 129 */ 50269,
/* 130 */ 280,
/* 131 */ -112,
/* 132 */ 15,
/* 133 */ 137,
/* 134 */ 50270,
/* 135 */ -112,
/* 136 */ 16,
/* 137 */ 142,
/* 138 */ 50278,
/* 139 */ 280,
/* 140 */ -112,
/* 141 */ 17,
/* 142 */ 147,
/* 143 */ 50279,
/* 144 */ 280,
/* 145 */ -112,
/* 146 */ 18,
/* 147 */ 152,
/* 148 */ 50280,
/* 149 */ 280,
/* 150 */ -112,
/* 151 */ 19,
/* 152 */ 0,
/* 153 */ 50271,
/* 154 */ -112,
/* 155 */ 20,
/* 156 */ 0,
/* 157 */ 50258,
/* 158 */ 280,
/* 159 */ 50040,
/* 160 */ 164,
/* 161 */ 50041,
/* 162 */ -156,
/* 163 */ 21,
/* 164 */ 168,
/* 165 */ 50257,
/* 166 */ -164,
/* 167 */ 61,
/* 168 */ 0,
/* 169 */ 18,
/* 170 */ -164,
/* 171 */ 62,
/* 172 */ 0,
/* 173 */ 50259,
/* 174 */ 404,
/* 175 */ 50040,
/* 176 */ 180,
/* 177 */ 50041,
/* 178 */ -172,
/* 179 */ 22,
/* 180 */ 184,
/* 181 */ 50257,
/* 182 */ -180,
/* 183 */ 63,
/* 184 */ 0,
/* 185 */ 18,
/* 186 */ -180,
/* 187 */ 64,
/* 188 */ 194,
/* 189 */ 50257,
/* 190 */ 50260,
/* 191 */ 18,
/* 192 */ -188,
/* 193 */ 23,
/* 194 */ 0,
/* 195 */ 50257,
/* 196 */ 50040,
/* 197 */ 404,
/* 198 */ 50041,
/* 199 */ 50260,
/* 200 */ 18,
/* 201 */ -188,
/* 202 */ 24,
/* 203 */ 211,
/* 204 */ 50261,
/* 205 */ 50257,
/* 206 */ 50040,
/* 207 */ 232,
/* 208 */ 50041,
/* 209 */ -203,
/* 210 */ 25,
/* 211 */ 222,
/* 212 */ 50261,
/* 213 */ 50257,
/* 214 */ 50040,
/* 215 */ 404,
/* 216 */ 50041,
/* 217 */ 50040,
/* 218 */ 240,
/* 219 */ 50041,
/* 220 */ -203,
/* 221 */ 26,
/* 222 */ 0,
/* 223 */ 50261,
/* 224 */ 50040,
/* 225 */ 404,
/* 226 */ 50041,
/* 227 */ 50040,
/* 228 */ 248,
/* 229 */ 50041,
/* 230 */ -203,
/* 231 */ 27,
/* 232 */ 236,
/* 233 */ 50257,
/* 234 */ -232,
/* 235 */ 65,
/* 236 */ 0,
/* 237 */ 18,
/* 238 */ -232,
/* 239 */ 66,
/* 240 */ 244,
/* 241 */ 50257,
/* 242 */ -240,
/* 243 */ 67,
/* 244 */ 0,
/* 245 */ 18,
/* 246 */ -240,
/* 247 */ 68,
/* 248 */ 252,
/* 249 */ 50257,
/* 250 */ -248,
/* 251 */ 69,
/* 252 */ 0,
/* 253 */ 18,
/* 254 */ -248,
/* 255 */ 70,
/* 256 */ 0,
/* 257 */ 265,
/* 258 */ 50277,
/* 259 */ 443,
/* 260 */ 50040,
/* 261 */ 272,
/* 262 */ 50041,
/* 263 */ -256,
/* 264 */ 28,
/* 265 */ 269,
/* 266 */ 404,
/* 267 */ -265,
/* 268 */ 71,
/* 269 */ 0,
/* 270 */ -265,
/* 271 */ 98,
/* 272 */ 276,
/* 273 */ 50257,
/* 274 */ -272,
/* 275 */ 72,
/* 276 */ 0,
/* 277 */ 18,
/* 278 */ -272,
/* 279 */ 73,
/* 280 */ 284,
/* 281 */ 307,
/* 282 */ -280,
/* 283 */ 29,
/* 284 */ 290,
/* 285 */ 307,
/* 286 */ 396,
/* 287 */ 280,
/* 288 */ -280,
/* 289 */ 30,
/* 290 */ 0,
/* 291 */ 50040,
/* 292 */ 307,
/* 293 */ 396,
/* 294 */ 280,
/* 295 */ 50041,
/* 296 */ 299,
/* 297 */ -280,
/* 298 */ 31,
/* 299 */ 304,
/* 300 */ 396,
/* 301 */ 280,
/* 302 */ -299,
/* 303 */ 74,
/* 304 */ 0,
/* 305 */ -299,
/* 306 */ 99,
/* 307 */ 315,
/* 308 */ 50040,
/* 309 */ 321,
/* 310 */ 353,
/* 311 */ 329,
/* 312 */ 50041,
/* 313 */ -307,
/* 314 */ 32,
/* 315 */ 0,
/* 316 */ 337,
/* 317 */ 353,
/* 318 */ 345,
/* 319 */ -307,
/* 320 */ 33,
/* 321 */ 325,
/* 322 */ 50257,
/* 323 */ -321,
/* 324 */ 75,
/* 325 */ 0,
/* 326 */ 50256,
/* 327 */ -321,
/* 328 */ 76,
/* 329 */ 333,
/* 330 */ 50257,
/* 331 */ -329,
/* 332 */ 77,
/* 333 */ 0,
/* 334 */ 50256,
/* 335 */ -329,
/* 336 */ 78,
/* 337 */ 341,
/* 338 */ 50257,
/* 339 */ -337,
/* 340 */ 79,
/* 341 */ 0,
/* 342 */ 50256,
/* 343 */ -337,
/* 344 */ 80,
/* 345 */ 349,
/* 346 */ 50257,
/* 347 */ -345,
/* 348 */ 81,
/* 349 */ 0,
/* 350 */ 50256,
/* 351 */ -345,
/* 352 */ 82,
/* 353 */ 357,
/* 354 */ 50061,
/* 355 */ -353,
/* 356 */ 34,
/* 357 */ 361,
/* 358 */ 50060,
/* 359 */ -353,
/* 360 */ 35,
/* 361 */ 365,
/* 362 */ 50062,
/* 363 */ -353,
/* 364 */ 36,
/* 365 */ 370,
/* 366 */ 50060,
/* 367 */ 50061,
/* 368 */ -353,
/* 369 */ 37,
/* 370 */ 375,
/* 371 */ 50062,
/* 372 */ 50061,
/* 373 */ -353,
/* 374 */ 38,
/* 375 */ 0,
/* 376 */ 50033,
/* 377 */ 50061,
/* 378 */ -353,
/* 379 */ 39,
/* 380 */ 384,
/* 381 */ 50043,
/* 382 */ -380,
/* 383 */ 40,
/* 384 */ 388,
/* 385 */ 50045,
/* 386 */ -380,
/* 387 */ 41,
/* 388 */ 392,
/* 389 */ 50042,
/* 390 */ -380,
/* 391 */ 42,
/* 392 */ 0,
/* 393 */ 50047,
/* 394 */ -380,
/* 395 */ 43,
/* 396 */ 400,
/* 397 */ 50262,
/* 398 */ -396,
/* 399 */ 44,
/* 400 */ 0,
/* 401 */ 50263,
/* 402 */ -396,
/* 403 */ 45,
/* 404 */ 0,
/* 405 */ 410,
/* 406 */ 418,
/* 407 */ 435,
/* 408 */ -404,
/* 409 */ 46,
/* 410 */ 414,
/* 411 */ 50257,
/* 412 */ -410,
/* 413 */ 83,
/* 414 */ 0,
/* 415 */ 50256,
/* 416 */ -410,
/* 417 */ 84,
/* 418 */ 424,
/* 419 */ 380,
/* 420 */ 427,
/* 421 */ 418,
/* 422 */ -418,
/* 423 */ 87,
/* 424 */ 0,
/* 425 */ -418,
/* 426 */ 100,
/* 427 */ 431,
/* 428 */ 50257,
/* 429 */ -427,
/* 430 */ 85,
/* 431 */ 0,
/* 432 */ 50256,
/* 433 */ -427,
/* 434 */ 86,
/* 435 */ 440,
/* 436 */ 50044,
/* 437 */ 404,
/* 438 */ -435,
/* 439 */ 88,
/* 440 */ 0,
/* 441 */ -435,
/* 442 */ 101,
/* 443 */ 0,
/* 444 */ 449,
/* 445 */ 50257,
/* 446 */ 469,
/* 447 */ -443,
/* 448 */ 47,
/* 449 */ 453,
/* 450 */ 50272,
/* 451 */ -449,
/* 452 */ 89,
/* 453 */ 457,
/* 454 */ 50273,
/* 455 */ -449,
/* 456 */ 90,
/* 457 */ 461,
/* 458 */ 50274,
/* 459 */ -449,
/* 460 */ 91,
/* 461 */ 465,
/* 462 */ 50275,
/* 463 */ -449,
/* 464 */ 92,
/* 465 */ 0,
/* 466 */ 50276,
/* 467 */ -449,
/* 468 */ 93,
/* 469 */ 474,
/* 470 */ 50044,
/* 471 */ 443,
/* 472 */ -469,
/* 473 */ 94,
/* 474 */ 0,
/* 475 */ -469,
/* 476 */ 102,
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
/* 15 */ 0,
/* 16 */ -10,
/* 17 */ 2,
/* 18 */ 24,
/* 19 */ 1,
/* 20 */ 1,
/* 21 */ 1,
/* 22 */ -18,
/* 23 */ 1,
/* 24 */ 0,
/* 25 */ 50281,
/* 26 */ -18,
/* 27 */ 2,
/* 28 */ 32,
/* 29 */ 50040,
/* 30 */ -28,
/* 31 */ 1,
/* 32 */ 0,
/* 33 */ -28,
/* 34 */ 2,
/* 35 */ 39,
/* 36 */ 1,
/* 37 */ -35,
/* 38 */ 1,
/* 39 */ 0,
/* 40 */ 1,
/* 41 */ -35,
/* 42 */ 2,
/* 43 */ 47,
/* 44 */ 50041,
/* 45 */ -43,
/* 46 */ 1,
/* 47 */ 0,
/* 48 */ -43,
/* 49 */ 2,
/* 50 */ 54,
/* 51 */ 1,
/* 52 */ -50,
/* 53 */ 1,
/* 54 */ 58,
/* 55 */ 1,
/* 56 */ -50,
/* 57 */ 2,
/* 58 */ 62,
/* 59 */ 1,
/* 60 */ -50,
/* 61 */ 3,
/* 62 */ 66,
/* 63 */ 1,
/* 64 */ -50,
/* 65 */ 4,
/* 66 */ 0,
/* 67 */ 1,
/* 68 */ -50,
/* 69 */ 5,
/* 70 */ 76,
/* 71 */ 1,
/* 72 */ 1,
/* 73 */ 1,
/* 74 */ -70,
/* 75 */ 1,
/* 76 */ 0,
/* 77 */ 1,
/* 78 */ 50270,
/* 79 */ 1,
/* 80 */ -70,
/* 81 */ 2,
/* 82 */ 86,
/* 83 */ 50257,
/* 84 */ -82,
/* 85 */ 1,
/* 86 */ 0,
/* 87 */ 1,
/* 88 */ -82,
/* 89 */ 2,
/* 90 */ 94,
/* 91 */ 50257,
/* 92 */ -90,
/* 93 */ 1,
/* 94 */ 98,
/* 95 */ 1,
/* 96 */ -90,
/* 97 */ 2,
/* 98 */ 0,
/* 99 */ 50040,
/* 100 */ 50257,
/* 101 */ 50041,
/* 102 */ -90,
/* 103 */ 3,
/* 104 */ 108,
/* 105 */ 50257,
/* 106 */ -104,
/* 107 */ 1,
/* 108 */ 0,
/* 109 */ 1,
/* 110 */ -104,
/* 111 */ 2,
/* 112 */ 116,
/* 113 */ 50265,
/* 114 */ -112,
/* 115 */ 1,
/* 116 */ 120,
/* 117 */ 50266,
/* 118 */ -112,
/* 119 */ 2,
/* 120 */ 124,
/* 121 */ 50267,
/* 122 */ -112,
/* 123 */ 3,
/* 124 */ 128,
/* 125 */ 50268,
/* 126 */ -112,
/* 127 */ 4,
/* 128 */ 133,
/* 129 */ 50269,
/* 130 */ 1,
/* 131 */ -112,
/* 132 */ 5,
/* 133 */ 137,
/* 134 */ 50270,
/* 135 */ -112,
/* 136 */ 6,
/* 137 */ 142,
/* 138 */ 50278,
/* 139 */ 1,
/* 140 */ -112,
/* 141 */ 7,
/* 142 */ 147,
/* 143 */ 50279,
/* 144 */ 1,
/* 145 */ -112,
/* 146 */ 8,
/* 147 */ 152,
/* 148 */ 50280,
/* 149 */ 1,
/* 150 */ -112,
/* 151 */ 9,
/* 152 */ 0,
/* 153 */ 50271,
/* 154 */ -112,
/* 155 */ 10,
/* 156 */ 0,
/* 157 */ 50258,
/* 158 */ 1,
/* 159 */ 50040,
/* 160 */ 1,
/* 161 */ 50041,
/* 162 */ -156,
/* 163 */ 1,
/* 164 */ 168,
/* 165 */ 50257,
/* 166 */ -164,
/* 167 */ 1,
/* 168 */ 0,
/* 169 */ 1,
/* 170 */ -164,
/* 171 */ 2,
/* 172 */ 0,
/* 173 */ 50259,
/* 174 */ 1,
/* 175 */ 50040,
/* 176 */ 1,
/* 177 */ 50041,
/* 178 */ -172,
/* 179 */ 1,
/* 180 */ 184,
/* 181 */ 50257,
/* 182 */ -180,
/* 183 */ 1,
/* 184 */ 0,
/* 185 */ 1,
/* 186 */ -180,
/* 187 */ 2,
/* 188 */ 194,
/* 189 */ 50257,
/* 190 */ 50260,
/* 191 */ 1,
/* 192 */ -188,
/* 193 */ 1,
/* 194 */ 0,
/* 195 */ 50257,
/* 196 */ 50040,
/* 197 */ 1,
/* 198 */ 50041,
/* 199 */ 50260,
/* 200 */ 1,
/* 201 */ -188,
/* 202 */ 2,
/* 203 */ 211,
/* 204 */ 50261,
/* 205 */ 50257,
/* 206 */ 50040,
/* 207 */ 1,
/* 208 */ 50041,
/* 209 */ -203,
/* 210 */ 1,
/* 211 */ 222,
/* 212 */ 50261,
/* 213 */ 50257,
/* 214 */ 50040,
/* 215 */ 1,
/* 216 */ 50041,
/* 217 */ 50040,
/* 218 */ 1,
/* 219 */ 50041,
/* 220 */ -203,
/* 221 */ 2,
/* 222 */ 0,
/* 223 */ 50261,
/* 224 */ 50040,
/* 225 */ 1,
/* 226 */ 50041,
/* 227 */ 50040,
/* 228 */ 1,
/* 229 */ 50041,
/* 230 */ -203,
/* 231 */ 3,
/* 232 */ 236,
/* 233 */ 50257,
/* 234 */ -232,
/* 235 */ 1,
/* 236 */ 0,
/* 237 */ 1,
/* 238 */ -232,
/* 239 */ 2,
/* 240 */ 244,
/* 241 */ 50257,
/* 242 */ -240,
/* 243 */ 1,
/* 244 */ 0,
/* 245 */ 1,
/* 246 */ -240,
/* 247 */ 2,
/* 248 */ 252,
/* 249 */ 50257,
/* 250 */ -248,
/* 251 */ 1,
/* 252 */ 0,
/* 253 */ 1,
/* 254 */ -248,
/* 255 */ 2,
/* 256 */ 0,
/* 257 */ 1,
/* 258 */ 50277,
/* 259 */ 1,
/* 260 */ 50040,
/* 261 */ 1,
/* 262 */ 50041,
/* 263 */ -256,
/* 264 */ 1,
/* 265 */ 269,
/* 266 */ 1,
/* 267 */ -265,
/* 268 */ 1,
/* 269 */ 0,
/* 270 */ -265,
/* 271 */ 2,
/* 272 */ 276,
/* 273 */ 50257,
/* 274 */ -272,
/* 275 */ 1,
/* 276 */ 0,
/* 277 */ 1,
/* 278 */ -272,
/* 279 */ 2,
/* 280 */ 284,
/* 281 */ 1,
/* 282 */ -280,
/* 283 */ 1,
/* 284 */ 290,
/* 285 */ 1,
/* 286 */ 1,
/* 287 */ 1,
/* 288 */ -280,
/* 289 */ 2,
/* 290 */ 0,
/* 291 */ 50040,
/* 292 */ 1,
/* 293 */ 1,
/* 294 */ 1,
/* 295 */ 50041,
/* 296 */ 1,
/* 297 */ -280,
/* 298 */ 3,
/* 299 */ 304,
/* 300 */ 1,
/* 301 */ 1,
/* 302 */ -299,
/* 303 */ 1,
/* 304 */ 0,
/* 305 */ -299,
/* 306 */ 2,
/* 307 */ 315,
/* 308 */ 50040,
/* 309 */ 1,
/* 310 */ 1,
/* 311 */ 1,
/* 312 */ 50041,
/* 313 */ -307,
/* 314 */ 1,
/* 315 */ 0,
/* 316 */ 1,
/* 317 */ 1,
/* 318 */ 1,
/* 319 */ -307,
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
/* 338 */ 50257,
/* 339 */ -337,
/* 340 */ 1,
/* 341 */ 0,
/* 342 */ 50256,
/* 343 */ -337,
/* 344 */ 2,
/* 345 */ 349,
/* 346 */ 50257,
/* 347 */ -345,
/* 348 */ 1,
/* 349 */ 0,
/* 350 */ 50256,
/* 351 */ -345,
/* 352 */ 2,
/* 353 */ 357,
/* 354 */ 50061,
/* 355 */ -353,
/* 356 */ 1,
/* 357 */ 361,
/* 358 */ 50060,
/* 359 */ -353,
/* 360 */ 2,
/* 361 */ 365,
/* 362 */ 50062,
/* 363 */ -353,
/* 364 */ 3,
/* 365 */ 370,
/* 366 */ 50060,
/* 367 */ 50061,
/* 368 */ -353,
/* 369 */ 4,
/* 370 */ 375,
/* 371 */ 50062,
/* 372 */ 50061,
/* 373 */ -353,
/* 374 */ 5,
/* 375 */ 0,
/* 376 */ 50033,
/* 377 */ 50061,
/* 378 */ -353,
/* 379 */ 6,
/* 380 */ 384,
/* 381 */ 50043,
/* 382 */ -380,
/* 383 */ 1,
/* 384 */ 388,
/* 385 */ 50045,
/* 386 */ -380,
/* 387 */ 2,
/* 388 */ 392,
/* 389 */ 50042,
/* 390 */ -380,
/* 391 */ 3,
/* 392 */ 0,
/* 393 */ 50047,
/* 394 */ -380,
/* 395 */ 4,
/* 396 */ 400,
/* 397 */ 50262,
/* 398 */ -396,
/* 399 */ 1,
/* 400 */ 0,
/* 401 */ 50263,
/* 402 */ -396,
/* 403 */ 2,
/* 404 */ 0,
/* 405 */ 1,
/* 406 */ 1,
/* 407 */ 1,
/* 408 */ -404,
/* 409 */ 1,
/* 410 */ 414,
/* 411 */ 50257,
/* 412 */ -410,
/* 413 */ 1,
/* 414 */ 0,
/* 415 */ 50256,
/* 416 */ -410,
/* 417 */ 2,
/* 418 */ 424,
/* 419 */ 1,
/* 420 */ 1,
/* 421 */ 1,
/* 422 */ -418,
/* 423 */ 1,
/* 424 */ 0,
/* 425 */ -418,
/* 426 */ 2,
/* 427 */ 431,
/* 428 */ 50257,
/* 429 */ -427,
/* 430 */ 1,
/* 431 */ 0,
/* 432 */ 50256,
/* 433 */ -427,
/* 434 */ 2,
/* 435 */ 440,
/* 436 */ 50044,
/* 437 */ 1,
/* 438 */ -435,
/* 439 */ 1,
/* 440 */ 0,
/* 441 */ -435,
/* 442 */ 2,
/* 443 */ 0,
/* 444 */ 1,
/* 445 */ 50257,
/* 446 */ 1,
/* 447 */ -443,
/* 448 */ 1,
/* 449 */ 453,
/* 450 */ 50272,
/* 451 */ -449,
/* 452 */ 1,
/* 453 */ 457,
/* 454 */ 50273,
/* 455 */ -449,
/* 456 */ 2,
/* 457 */ 461,
/* 458 */ 50274,
/* 459 */ -449,
/* 460 */ 3,
/* 461 */ 465,
/* 462 */ 50275,
/* 463 */ -449,
/* 464 */ 4,
/* 465 */ 0,
/* 466 */ 50276,
/* 467 */ -449,
/* 468 */ 5,
/* 469 */ 474,
/* 470 */ 50044,
/* 471 */ 1,
/* 472 */ -469,
/* 473 */ 1,
/* 474 */ 0,
/* 475 */ -469,
/* 476 */ 2,
0
};
extern int yycoordinate[];
int yycoordinate[] = {
0,
/* 1 */ 9999,
/* 2 */ 7009,
/* 3 */ 9999,
/* 4 */ 9999,
/* 5 */ 7009,
/* 6 */ 9999,
/* 7 */ 8027,
/* 8 */ 9999,
/* 9 */ 8005,
/* 10 */ 9999,
/* 11 */ 8029,
/* 12 */ 8045,
/* 13 */ 9999,
/* 14 */ 8045,
/* 15 */ 9999,
/* 16 */ 9999,
/* 17 */ 8045,
/* 18 */ 9999,
/* 19 */ 12009,
/* 20 */ 12042,
/* 21 */ 12081,
/* 22 */ 9999,
/* 23 */ 12009,
/* 24 */ 9999,
/* 25 */ 9999,
/* 26 */ 9999,
/* 27 */ 14018,
/* 28 */ 9999,
/* 29 */ 9999,
/* 30 */ 9999,
/* 31 */ 12011,
/* 32 */ 9999,
/* 33 */ 9999,
/* 34 */ 12011,
/* 35 */ 9999,
/* 36 */ 12044,
/* 37 */ 9999,
/* 38 */ 12058,
/* 39 */ 9999,
/* 40 */ 12062,
/* 41 */ 9999,
/* 42 */ 12077,
/* 43 */ 9999,
/* 44 */ 9999,
/* 45 */ 9999,
/* 46 */ 12083,
/* 47 */ 9999,
/* 48 */ 9999,
/* 49 */ 12083,
/* 50 */ 9999,
/* 51 */ 18009,
/* 52 */ 9999,
/* 53 */ 18015,
/* 54 */ 9999,
/* 55 */ 20009,
/* 56 */ 9999,
/* 57 */ 20016,
/* 58 */ 9999,
/* 59 */ 22009,
/* 60 */ 9999,
/* 61 */ 22019,
/* 62 */ 9999,
/* 63 */ 24009,
/* 64 */ 9999,
/* 65 */ 24019,
/* 66 */ 9999,
/* 67 */ 26009,
/* 68 */ 9999,
/* 69 */ 26019,
/* 70 */ 9999,
/* 71 */ 30009,
/* 72 */ 30073,
/* 73 */ 30095,
/* 74 */ 9999,
/* 75 */ 30009,
/* 76 */ 9999,
/* 77 */ 32009,
/* 78 */ 9999,
/* 79 */ 32125,
/* 80 */ 9999,
/* 81 */ 32009,
/* 82 */ 9999,
/* 83 */ 9999,
/* 84 */ 9999,
/* 85 */ 30014,
/* 86 */ 9999,
/* 87 */ 30053,
/* 88 */ 9999,
/* 89 */ 30069,
/* 90 */ 9999,
/* 91 */ 9999,
/* 92 */ 9999,
/* 93 */ 30100,
/* 94 */ 9999,
/* 95 */ 30139,
/* 96 */ 9999,
/* 97 */ 30155,
/* 98 */ 9999,
/* 99 */ 9999,
/* 100 */ 9999,
/* 101 */ 9999,
/* 102 */ 9999,
/* 103 */ 30159,
/* 104 */ 9999,
/* 105 */ 9999,
/* 106 */ 9999,
/* 107 */ 32014,
/* 108 */ 9999,
/* 109 */ 32053,
/* 110 */ 9999,
/* 111 */ 32069,
/* 112 */ 9999,
/* 113 */ 9999,
/* 114 */ 9999,
/* 115 */ 36013,
/* 116 */ 9999,
/* 117 */ 9999,
/* 118 */ 9999,
/* 119 */ 38019,
/* 120 */ 9999,
/* 121 */ 9999,
/* 122 */ 9999,
/* 123 */ 40017,
/* 124 */ 9999,
/* 125 */ 9999,
/* 126 */ 9999,
/* 127 */ 42026,
/* 128 */ 9999,
/* 129 */ 9999,
/* 130 */ 44016,
/* 131 */ 9999,
/* 132 */ 44014,
/* 133 */ 9999,
/* 134 */ 9999,
/* 135 */ 9999,
/* 136 */ 46022,
/* 137 */ 9999,
/* 138 */ 9999,
/* 139 */ 48033,
/* 140 */ 9999,
/* 141 */ 48031,
/* 142 */ 9999,
/* 143 */ 9999,
/* 144 */ 50032,
/* 145 */ 9999,
/* 146 */ 50030,
/* 147 */ 9999,
/* 148 */ 9999,
/* 149 */ 52033,
/* 150 */ 9999,
/* 151 */ 52031,
/* 152 */ 9999,
/* 153 */ 9999,
/* 154 */ 9999,
/* 155 */ 54015,
/* 156 */ 9999,
/* 157 */ 9999,
/* 158 */ 58011,
/* 159 */ 9999,
/* 160 */ 58077,
/* 161 */ 9999,
/* 162 */ 9999,
/* 163 */ 58009,
/* 164 */ 9999,
/* 165 */ 9999,
/* 166 */ 9999,
/* 167 */ 58082,
/* 168 */ 9999,
/* 169 */ 58121,
/* 170 */ 9999,
/* 171 */ 58137,
/* 172 */ 9999,
/* 173 */ 9999,
/* 174 */ 62008,
/* 175 */ 9999,
/* 176 */ 62077,
/* 177 */ 9999,
/* 178 */ 9999,
/* 179 */ 62006,
/* 180 */ 9999,
/* 181 */ 9999,
/* 182 */ 9999,
/* 183 */ 62082,
/* 184 */ 9999,
/* 185 */ 62121,
/* 186 */ 9999,
/* 187 */ 62137,
/* 188 */ 9999,
/* 189 */ 9999,
/* 190 */ 9999,
/* 191 */ 66093,
/* 192 */ 9999,
/* 193 */ 66012,
/* 194 */ 9999,
/* 195 */ 9999,
/* 196 */ 9999,
/* 197 */ 68021,
/* 198 */ 9999,
/* 199 */ 9999,
/* 200 */ 68117,
/* 201 */ 9999,
/* 202 */ 68012,
/* 203 */ 9999,
/* 204 */ 9999,
/* 205 */ 9999,
/* 206 */ 9999,
/* 207 */ 72117,
/* 208 */ 9999,
/* 209 */ 9999,
/* 210 */ 72011,
/* 211 */ 9999,
/* 212 */ 9999,
/* 213 */ 9999,
/* 214 */ 9999,
/* 215 */ 74100,
/* 216 */ 9999,
/* 217 */ 9999,
/* 218 */ 74207,
/* 219 */ 9999,
/* 220 */ 9999,
/* 221 */ 74011,
/* 222 */ 9999,
/* 223 */ 9999,
/* 224 */ 9999,
/* 225 */ 76050,
/* 226 */ 9999,
/* 227 */ 9999,
/* 228 */ 76159,
/* 229 */ 9999,
/* 230 */ 9999,
/* 231 */ 76011,
/* 232 */ 9999,
/* 233 */ 9999,
/* 234 */ 9999,
/* 235 */ 72122,
/* 236 */ 9999,
/* 237 */ 72161,
/* 238 */ 9999,
/* 239 */ 72177,
/* 240 */ 9999,
/* 241 */ 9999,
/* 242 */ 9999,
/* 243 */ 74212,
/* 244 */ 9999,
/* 245 */ 74251,
/* 246 */ 9999,
/* 247 */ 74267,
/* 248 */ 9999,
/* 249 */ 9999,
/* 250 */ 9999,
/* 251 */ 76164,
/* 252 */ 9999,
/* 253 */ 76203,
/* 254 */ 9999,
/* 255 */ 76219,
/* 256 */ 9999,
/* 257 */ 80005,
/* 258 */ 9999,
/* 259 */ 80032,
/* 260 */ 9999,
/* 261 */ 80091,
/* 262 */ 9999,
/* 263 */ 9999,
/* 264 */ 80005,
/* 265 */ 9999,
/* 266 */ 80006,
/* 267 */ 9999,
/* 268 */ 80020,
/* 269 */ 9999,
/* 270 */ 9999,
/* 271 */ 80020,
/* 272 */ 9999,
/* 273 */ 9999,
/* 274 */ 9999,
/* 275 */ 80096,
/* 276 */ 9999,
/* 277 */ 80135,
/* 278 */ 9999,
/* 279 */ 80151,
/* 280 */ 9999,
/* 281 */ 84009,
/* 282 */ 9999,
/* 283 */ 84016,
/* 284 */ 9999,
/* 285 */ 86009,
/* 286 */ 86018,
/* 287 */ 86036,
/* 288 */ 9999,
/* 289 */ 86016,
/* 290 */ 9999,
/* 291 */ 9999,
/* 292 */ 88044,
/* 293 */ 88053,
/* 294 */ 88071,
/* 295 */ 9999,
/* 296 */ 88116,
/* 297 */ 9999,
/* 298 */ 88009,
/* 299 */ 9999,
/* 300 */ 88117,
/* 301 */ 88135,
/* 302 */ 9999,
/* 303 */ 88133,
/* 304 */ 9999,
/* 305 */ 9999,
/* 306 */ 88133,
/* 307 */ 9999,
/* 308 */ 9999,
/* 309 */ 92041,
/* 310 */ 92142,
/* 311 */ 92162,
/* 312 */ 9999,
/* 313 */ 9999,
/* 314 */ 92005,
/* 315 */ 9999,
/* 316 */ 93007,
/* 317 */ 93109,
/* 318 */ 93129,
/* 319 */ 9999,
/* 320 */ 93007,
/* 321 */ 9999,
/* 322 */ 9999,
/* 323 */ 9999,
/* 324 */ 92046,
/* 325 */ 9999,
/* 326 */ 9999,
/* 327 */ 9999,
/* 328 */ 92097,
/* 329 */ 9999,
/* 330 */ 9999,
/* 331 */ 9999,
/* 332 */ 92167,
/* 333 */ 9999,
/* 334 */ 9999,
/* 335 */ 9999,
/* 336 */ 92218,
/* 337 */ 9999,
/* 338 */ 9999,
/* 339 */ 9999,
/* 340 */ 93012,
/* 341 */ 9999,
/* 342 */ 9999,
/* 343 */ 9999,
/* 344 */ 93063,
/* 345 */ 9999,
/* 346 */ 9999,
/* 347 */ 9999,
/* 348 */ 93134,
/* 349 */ 9999,
/* 350 */ 9999,
/* 351 */ 9999,
/* 352 */ 93185,
/* 353 */ 9999,
/* 354 */ 9999,
/* 355 */ 9999,
/* 356 */ 97009,
/* 357 */ 9999,
/* 358 */ 9999,
/* 359 */ 9999,
/* 360 */ 99009,
/* 361 */ 9999,
/* 362 */ 9999,
/* 363 */ 9999,
/* 364 */ 101009,
/* 365 */ 9999,
/* 366 */ 9999,
/* 367 */ 9999,
/* 368 */ 9999,
/* 369 */ 103009,
/* 370 */ 9999,
/* 371 */ 9999,
/* 372 */ 9999,
/* 373 */ 9999,
/* 374 */ 105009,
/* 375 */ 9999,
/* 376 */ 9999,
/* 377 */ 9999,
/* 378 */ 9999,
/* 379 */ 107009,
/* 380 */ 9999,
/* 381 */ 9999,
/* 382 */ 9999,
/* 383 */ 111009,
/* 384 */ 9999,
/* 385 */ 9999,
/* 386 */ 9999,
/* 387 */ 113009,
/* 388 */ 9999,
/* 389 */ 9999,
/* 390 */ 9999,
/* 391 */ 115009,
/* 392 */ 9999,
/* 393 */ 9999,
/* 394 */ 9999,
/* 395 */ 117009,
/* 396 */ 9999,
/* 397 */ 9999,
/* 398 */ 9999,
/* 399 */ 121011,
/* 400 */ 9999,
/* 401 */ 9999,
/* 402 */ 9999,
/* 403 */ 123010,
/* 404 */ 9999,
/* 405 */ 127005,
/* 406 */ 127112,
/* 407 */ 127245,
/* 408 */ 9999,
/* 409 */ 127005,
/* 410 */ 9999,
/* 411 */ 9999,
/* 412 */ 9999,
/* 413 */ 127010,
/* 414 */ 9999,
/* 415 */ 9999,
/* 416 */ 9999,
/* 417 */ 127063,
/* 418 */ 9999,
/* 419 */ 127114,
/* 420 */ 127134,
/* 421 */ 127132,
/* 422 */ 9999,
/* 423 */ 127132,
/* 424 */ 9999,
/* 425 */ 9999,
/* 426 */ 127132,
/* 427 */ 9999,
/* 428 */ 9999,
/* 429 */ 9999,
/* 430 */ 127139,
/* 431 */ 9999,
/* 432 */ 9999,
/* 433 */ 9999,
/* 434 */ 127192,
/* 435 */ 9999,
/* 436 */ 9999,
/* 437 */ 127284,
/* 438 */ 9999,
/* 439 */ 127247,
/* 440 */ 9999,
/* 441 */ 9999,
/* 442 */ 127247,
/* 443 */ 9999,
/* 444 */ 131005,
/* 445 */ 9999,
/* 446 */ 131278,
/* 447 */ 9999,
/* 448 */ 131005,
/* 449 */ 9999,
/* 450 */ 9999,
/* 451 */ 9999,
/* 452 */ 131011,
/* 453 */ 9999,
/* 454 */ 9999,
/* 455 */ 9999,
/* 456 */ 131059,
/* 457 */ 9999,
/* 458 */ 9999,
/* 459 */ 9999,
/* 460 */ 131105,
/* 461 */ 9999,
/* 462 */ 9999,
/* 463 */ 9999,
/* 464 */ 131147,
/* 465 */ 9999,
/* 466 */ 9999,
/* 467 */ 9999,
/* 468 */ 131189,
/* 469 */ 9999,
/* 470 */ 9999,
/* 471 */ 131317,
/* 472 */ 9999,
/* 473 */ 131280,
/* 474 */ 9999,
/* 475 */ 9999,
/* 476 */ 131280,
0
};
/* only for BIGHASH (see art.c)
extern int DHITS[];
int DHITS[478];
*/
int TABLE[103][256];
init_dirsets() {
TABLE[48][0] = 1;
TABLE[48][281] = 1;
TABLE[48][40] = 1;
TABLE[48][41] = 1;
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
TABLE[1][0] = 1;
TABLE[1][281] = 1;
TABLE[1][41] = 1;
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
TABLE[49][0] = 1;
TABLE[49][281] = 1;
TABLE[49][40] = 1;
TABLE[49][41] = 1;
TABLE[49][270] = 1;
TABLE[49][271] = 1;
TABLE[49][280] = 1;
TABLE[49][279] = 1;
TABLE[49][278] = 1;
TABLE[49][269] = 1;
TABLE[49][268] = 1;
TABLE[49][267] = 1;
TABLE[49][266] = 1;
TABLE[49][265] = 1;
TABLE[49][258] = 1;
TABLE[49][259] = 1;
TABLE[49][257] = 1;
TABLE[49][261] = 1;
TABLE[49][277] = 1;
TABLE[49][256] = 1;
TABLE[95][0] = 1;
TABLE[2][0] = 1;
TABLE[2][270] = 1;
TABLE[2][277] = 1;
TABLE[2][261] = 1;
TABLE[2][257] = 1;
TABLE[2][259] = 1;
TABLE[2][258] = 1;
TABLE[2][265] = 1;
TABLE[2][266] = 1;
TABLE[2][267] = 1;
TABLE[2][268] = 1;
TABLE[2][269] = 1;
TABLE[2][278] = 1;
TABLE[2][279] = 1;
TABLE[2][280] = 1;
TABLE[2][271] = 1;
TABLE[2][281] = 1;
TABLE[2][41] = 1;
TABLE[2][256] = 1;
TABLE[2][40] = 1;
TABLE[3][281] = 1;
TABLE[50][40] = 1;
TABLE[96][281] = 1;
TABLE[96][41] = 1;
TABLE[96][40] = 1;
TABLE[96][270] = 1;
TABLE[96][277] = 1;
TABLE[96][261] = 1;
TABLE[96][257] = 1;
TABLE[96][259] = 1;
TABLE[96][258] = 1;
TABLE[96][265] = 1;
TABLE[96][266] = 1;
TABLE[96][267] = 1;
TABLE[96][268] = 1;
TABLE[96][269] = 1;
TABLE[96][278] = 1;
TABLE[96][279] = 1;
TABLE[96][280] = 1;
TABLE[96][271] = 1;
TABLE[96][256] = 1;
TABLE[96][0] = 1;
TABLE[51][281] = 1;
TABLE[51][41] = 1;
TABLE[51][40] = 1;
TABLE[51][270] = 1;
TABLE[51][265] = 1;
TABLE[51][266] = 1;
TABLE[51][267] = 1;
TABLE[51][268] = 1;
TABLE[51][269] = 1;
TABLE[51][278] = 1;
TABLE[51][279] = 1;
TABLE[51][280] = 1;
TABLE[51][271] = 1;
TABLE[51][0] = 1;
TABLE[51][258] = 1;
TABLE[51][259] = 1;
TABLE[51][257] = 1;
TABLE[51][261] = 1;
TABLE[51][277] = 1;
TABLE[51][256] = 1;
TABLE[52][0] = 1;
TABLE[52][270] = 1;
TABLE[52][281] = 1;
TABLE[52][257] = 1;
TABLE[52][271] = 1;
TABLE[52][280] = 1;
TABLE[52][279] = 1;
TABLE[52][278] = 1;
TABLE[52][269] = 1;
TABLE[52][268] = 1;
TABLE[52][267] = 1;
TABLE[52][266] = 1;
TABLE[52][265] = 1;
TABLE[52][40] = 1;
TABLE[52][41] = 1;
TABLE[52][258] = 1;
TABLE[52][259] = 1;
TABLE[52][261] = 1;
TABLE[52][277] = 1;
TABLE[52][256] = 1;
TABLE[53][41] = 1;
TABLE[97][281] = 1;
TABLE[97][41] = 1;
TABLE[97][40] = 1;
TABLE[97][270] = 1;
TABLE[97][277] = 1;
TABLE[97][261] = 1;
TABLE[97][257] = 1;
TABLE[97][259] = 1;
TABLE[97][258] = 1;
TABLE[97][265] = 1;
TABLE[97][266] = 1;
TABLE[97][267] = 1;
TABLE[97][268] = 1;
TABLE[97][269] = 1;
TABLE[97][278] = 1;
TABLE[97][279] = 1;
TABLE[97][280] = 1;
TABLE[97][271] = 1;
TABLE[97][256] = 1;
TABLE[97][0] = 1;
TABLE[4][258] = 1;
TABLE[5][259] = 1;
TABLE[6][257] = 1;
TABLE[7][261] = 1;
TABLE[8][281] = 1;
TABLE[8][41] = 1;
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
TABLE[8][277] = 1;
TABLE[8][256] = 1;
TABLE[8][257] = 1;
TABLE[9][257] = 1;
TABLE[9][281] = 1;
TABLE[9][41] = 1;
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
TABLE[10][281] = 1;
TABLE[10][41] = 1;
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
TABLE[54][257] = 1;
TABLE[55][281] = 1;
TABLE[55][40] = 1;
TABLE[55][41] = 1;
TABLE[55][270] = 1;
TABLE[55][271] = 1;
TABLE[55][280] = 1;
TABLE[55][279] = 1;
TABLE[55][278] = 1;
TABLE[55][269] = 1;
TABLE[55][268] = 1;
TABLE[55][267] = 1;
TABLE[55][266] = 1;
TABLE[55][265] = 1;
TABLE[55][258] = 1;
TABLE[55][259] = 1;
TABLE[55][257] = 1;
TABLE[55][261] = 1;
TABLE[55][277] = 1;
TABLE[55][256] = 1;
TABLE[56][257] = 1;
TABLE[57][0] = 1;
TABLE[57][281] = 1;
TABLE[57][40] = 1;
TABLE[57][41] = 1;
TABLE[57][270] = 1;
TABLE[57][271] = 1;
TABLE[57][280] = 1;
TABLE[57][279] = 1;
TABLE[57][278] = 1;
TABLE[57][269] = 1;
TABLE[57][268] = 1;
TABLE[57][267] = 1;
TABLE[57][266] = 1;
TABLE[57][265] = 1;
TABLE[57][258] = 1;
TABLE[57][259] = 1;
TABLE[57][257] = 1;
TABLE[57][261] = 1;
TABLE[57][277] = 1;
TABLE[57][256] = 1;
TABLE[58][40] = 1;
TABLE[59][257] = 1;
TABLE[60][281] = 1;
TABLE[60][40] = 1;
TABLE[60][41] = 1;
TABLE[60][270] = 1;
TABLE[60][271] = 1;
TABLE[60][280] = 1;
TABLE[60][279] = 1;
TABLE[60][278] = 1;
TABLE[60][269] = 1;
TABLE[60][268] = 1;
TABLE[60][267] = 1;
TABLE[60][266] = 1;
TABLE[60][265] = 1;
TABLE[60][258] = 1;
TABLE[60][259] = 1;
TABLE[60][257] = 1;
TABLE[60][261] = 1;
TABLE[60][277] = 1;
TABLE[60][256] = 1;
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
TABLE[62][281] = 1;
TABLE[62][40] = 1;
TABLE[62][41] = 1;
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
TABLE[64][281] = 1;
TABLE[64][40] = 1;
TABLE[64][41] = 1;
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
TABLE[24][257] = 1;
TABLE[25][261] = 1;
TABLE[26][261] = 1;
TABLE[27][261] = 1;
TABLE[65][257] = 1;
TABLE[66][281] = 1;
TABLE[66][40] = 1;
TABLE[66][41] = 1;
TABLE[66][270] = 1;
TABLE[66][271] = 1;
TABLE[66][280] = 1;
TABLE[66][279] = 1;
TABLE[66][278] = 1;
TABLE[66][269] = 1;
TABLE[66][268] = 1;
TABLE[66][267] = 1;
TABLE[66][266] = 1;
TABLE[66][265] = 1;
TABLE[66][258] = 1;
TABLE[66][259] = 1;
TABLE[66][257] = 1;
TABLE[66][261] = 1;
TABLE[66][277] = 1;
TABLE[66][256] = 1;
TABLE[67][257] = 1;
TABLE[68][281] = 1;
TABLE[68][40] = 1;
TABLE[68][41] = 1;
TABLE[68][270] = 1;
TABLE[68][271] = 1;
TABLE[68][280] = 1;
TABLE[68][279] = 1;
TABLE[68][278] = 1;
TABLE[68][269] = 1;
TABLE[68][268] = 1;
TABLE[68][267] = 1;
TABLE[68][266] = 1;
TABLE[68][265] = 1;
TABLE[68][258] = 1;
TABLE[68][259] = 1;
TABLE[68][257] = 1;
TABLE[68][261] = 1;
TABLE[68][277] = 1;
TABLE[68][256] = 1;
TABLE[69][257] = 1;
TABLE[70][281] = 1;
TABLE[70][40] = 1;
TABLE[70][41] = 1;
TABLE[70][270] = 1;
TABLE[70][271] = 1;
TABLE[70][280] = 1;
TABLE[70][279] = 1;
TABLE[70][278] = 1;
TABLE[70][269] = 1;
TABLE[70][268] = 1;
TABLE[70][267] = 1;
TABLE[70][266] = 1;
TABLE[70][265] = 1;
TABLE[70][258] = 1;
TABLE[70][259] = 1;
TABLE[70][257] = 1;
TABLE[70][261] = 1;
TABLE[70][277] = 1;
TABLE[70][256] = 1;
TABLE[28][277] = 1;
TABLE[28][257] = 1;
TABLE[28][256] = 1;
TABLE[71][256] = 1;
TABLE[71][257] = 1;
TABLE[98][277] = 1;
TABLE[72][257] = 1;
TABLE[73][281] = 1;
TABLE[73][40] = 1;
TABLE[73][41] = 1;
TABLE[73][270] = 1;
TABLE[73][271] = 1;
TABLE[73][280] = 1;
TABLE[73][279] = 1;
TABLE[73][278] = 1;
TABLE[73][269] = 1;
TABLE[73][268] = 1;
TABLE[73][267] = 1;
TABLE[73][266] = 1;
TABLE[73][265] = 1;
TABLE[73][258] = 1;
TABLE[73][259] = 1;
TABLE[73][257] = 1;
TABLE[73][261] = 1;
TABLE[73][277] = 1;
TABLE[73][256] = 1;
TABLE[29][40] = 1;
TABLE[29][256] = 1;
TABLE[29][257] = 1;
TABLE[30][40] = 1;
TABLE[30][256] = 1;
TABLE[30][257] = 1;
TABLE[31][40] = 1;
TABLE[74][262] = 1;
TABLE[74][263] = 1;
TABLE[99][281] = 1;
TABLE[99][41] = 1;
TABLE[99][40] = 1;
TABLE[99][270] = 1;
TABLE[99][277] = 1;
TABLE[99][261] = 1;
TABLE[99][257] = 1;
TABLE[99][259] = 1;
TABLE[99][258] = 1;
TABLE[99][265] = 1;
TABLE[99][266] = 1;
TABLE[99][267] = 1;
TABLE[99][268] = 1;
TABLE[99][269] = 1;
TABLE[99][278] = 1;
TABLE[99][279] = 1;
TABLE[99][280] = 1;
TABLE[99][271] = 1;
TABLE[99][256] = 1;
TABLE[99][0] = 1;
TABLE[32][40] = 1;
TABLE[33][257] = 1;
TABLE[33][256] = 1;
TABLE[75][257] = 1;
TABLE[76][256] = 1;
TABLE[77][257] = 1;
TABLE[78][256] = 1;
TABLE[79][257] = 1;
TABLE[80][256] = 1;
TABLE[81][257] = 1;
TABLE[82][256] = 1;
TABLE[34][61] = 1;
TABLE[35][60] = 1;
TABLE[36][62] = 1;
TABLE[37][60] = 1;
TABLE[38][62] = 1;
TABLE[39][33] = 1;
TABLE[40][43] = 1;
TABLE[41][45] = 1;
TABLE[42][42] = 1;
TABLE[43][47] = 1;
TABLE[44][262] = 1;
TABLE[45][263] = 1;
TABLE[46][257] = 1;
TABLE[46][256] = 1;
TABLE[83][257] = 1;
TABLE[84][256] = 1;
TABLE[87][43] = 1;
TABLE[87][45] = 1;
TABLE[87][42] = 1;
TABLE[87][47] = 1;
TABLE[100][44] = 1;
TABLE[100][40] = 1;
TABLE[100][41] = 1;
TABLE[100][277] = 1;
TABLE[85][257] = 1;
TABLE[86][256] = 1;
TABLE[88][44] = 1;
TABLE[101][40] = 1;
TABLE[101][41] = 1;
TABLE[101][277] = 1;
TABLE[47][272] = 1;
TABLE[47][273] = 1;
TABLE[47][274] = 1;
TABLE[47][275] = 1;
TABLE[47][276] = 1;
TABLE[89][272] = 1;
TABLE[90][273] = 1;
TABLE[91][274] = 1;
TABLE[92][275] = 1;
TABLE[93][276] = 1;
TABLE[94][44] = 1;
TABLE[102][40] = 1;
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
      case 18: return 1; break;
      case 28: return 1; break;
      case 35: return 1; break;
      case 43: return 1; break;
      case 50: return 1; break;
      case 70: return 1; break;
      case 82: return 1; break;
      case 90: return 1; break;
      case 104: return 1; break;
      case 112: return 0; break;
      case 156: return 0; break;
      case 164: return 1; break;
      case 172: return 0; break;
      case 180: return 1; break;
      case 188: return 0; break;
      case 203: return 0; break;
      case 232: return 1; break;
      case 240: return 1; break;
      case 248: return 1; break;
      case 256: return 1; break;
      case 265: return 1; break;
      case 272: return 1; break;
      case 280: return 0; break;
      case 299: return 1; break;
      case 307: return 0; break;
      case 321: return 0; break;
      case 329: return 0; break;
      case 337: return 0; break;
      case 345: return 0; break;
      case 353: return 0; break;
      case 380: return 0; break;
      case 396: return 0; break;
      case 404: return 0; break;
      case 410: return 0; break;
      case 418: return 1; break;
      case 427: return 0; break;
      case 435: return 1; break;
      case 443: return 0; break;
      case 449: return 0; break;
      case 469: return 1; break;
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
         case 18: return "operacao_consulta"; break;
         case 28: return "Subphrase"; break;
         case 35: return "Subphrase"; break;
         case 43: return "Subphrase"; break;
         case 50: return "operacao_unaria"; break;
         case 70: return "operacao_binaria"; break;
         case 82: return "Subphrase"; break;
         case 90: return "Subphrase"; break;
         case 104: return "Subphrase"; break;
         case 112: return "tipo_operacao_binaria"; break;
         case 156: return "selecao"; break;
         case 164: return "Subphrase"; break;
         case 172: return "projecao"; break;
         case 180: return "Subphrase"; break;
         case 188: return "renomeacao1"; break;
         case 203: return "renomeacao2"; break;
         case 232: return "Subphrase"; break;
         case 240: return "Subphrase"; break;
         case 248: return "Subphrase"; break;
         case 256: return "agrupamento"; break;
         case 265: return "Subphrase"; break;
         case 272: return "Subphrase"; break;
         case 280: return "predicado"; break;
         case 299: return "Subphrase"; break;
         case 307: return "condicao"; break;
         case 321: return "Subphrase"; break;
         case 329: return "Subphrase"; break;
         case 337: return "Subphrase"; break;
         case 345: return "Subphrase"; break;
         case 353: return "operador_comparacao"; break;
         case 380: return "operador_aritmetico"; break;
         case 396: return "operador_booleano"; break;
         case 404: return "lista_atributos"; break;
         case 410: return "Subphrase"; break;
         case 418: return "Subphrase"; break;
         case 427: return "Subphrase"; break;
         case 435: return "Subphrase"; break;
         case 443: return "lista_funcoes_agregadas"; break;
         case 449: return "Subphrase"; break;
         case 469: return "Subphrase"; break;
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
