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
      case 56: {
         get_lexval();
#line 30 "spec.acc"
_add_node_stack("(");
# line 122 "yygrammar.c"
         get_lexval();
         y = yylval;
#line 30 "spec.acc"
_add_node_stack(y.stringval);
# line 127 "yygrammar.c"
         get_lexval();
#line 30 "spec.acc"
_add_node_stack(")");
# line 131 "yygrammar.c"
         } break;
      default: printf("???\n"); exit(1);
      }
      tipo_operacao_binaria();
      switch (yyselect()) {
      case 57: {
         get_lexval();
         y = yylval;
#line 30 "spec.acc"
_add_node_stack(y.stringval);
# line 142 "yygrammar.c"
         } break;
      case 58: {
         operacao_consulta();
         } break;
      case 59: {
         get_lexval();
#line 30 "spec.acc"
_add_node_stack("(");
# line 151 "yygrammar.c"
         get_lexval();
         y = yylval;
#line 30 "spec.acc"
_add_node_stack(y.stringval);
# line 156 "yygrammar.c"
         get_lexval();
#line 30 "spec.acc"
_add_node_stack(")");
# line 160 "yygrammar.c"
         } break;
      default: printf("???\n"); exit(1);
      }
      } break;
   case 10: {
      switch (yyselect()) {
      case 60: {
         get_lexval();
         y = yylval;
#line 32 "spec.acc"
_add_node_stack(y.stringval);
# line 172 "yygrammar.c"
         } break;
      case 61: {
         operacao_consulta();
         } break;
      case 62: {
         get_lexval();
#line 32 "spec.acc"
_add_node_stack("(");
# line 181 "yygrammar.c"
         get_lexval();
         y = yylval;
#line 32 "spec.acc"
_add_node_stack(y.stringval);
# line 186 "yygrammar.c"
         get_lexval();
#line 32 "spec.acc"
_add_node_stack(")");
# line 190 "yygrammar.c"
         } break;
      default: printf("???\n"); exit(1);
      }
      get_lexval();
#line 32 "spec.acc"
_add_node_stack("JUNCAO_NATURAL");
# line 197 "yygrammar.c"
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
# line 210 "yygrammar.c"
      } break;
   case 12: {
      get_lexval();
#line 38 "spec.acc"
_add_node_stack("INTERSECCAO");
# line 216 "yygrammar.c"
      } break;
   case 13: {
      get_lexval();
#line 40 "spec.acc"
_add_node_stack("SUBTRACAO");
# line 222 "yygrammar.c"
      } break;
   case 14: {
      get_lexval();
#line 42 "spec.acc"
_add_node_stack("PRODUTO_CARTESIANO");
# line 228 "yygrammar.c"
      } break;
   case 15: {
      get_lexval();
      predicado();
#line 44 "spec.acc"
_add_node_stack("JUNCAO");
# line 235 "yygrammar.c"
      } break;
   case 16: {
      get_lexval();
#line 46 "spec.acc"
_add_node_stack("JUNCAO_NATURAL");
# line 241 "yygrammar.c"
      } break;
   case 17: {
      get_lexval();
      predicado();
#line 48 "spec.acc"
_add_node_stack("JUNCAO_EXTERNA_ESQUERDA");
# line 248 "yygrammar.c"
      } break;
   case 18: {
      get_lexval();
      predicado();
#line 50 "spec.acc"
_add_node_stack("JUNCAO_EXTERNA_DIREITA");
# line 255 "yygrammar.c"
      } break;
   case 19: {
      get_lexval();
      predicado();
#line 52 "spec.acc"
_add_node_stack("JUNCAO_EXTERNA_COMPLETA");
# line 262 "yygrammar.c"
      } break;
   case 20: {
      get_lexval();
#line 54 "spec.acc"
_add_node_stack("DIVISAO");
# line 268 "yygrammar.c"
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
# line 282 "yygrammar.c"
      get_lexval();
#line 58 "spec.acc"
_add_node_stack("(");
# line 286 "yygrammar.c"
      switch (yyselect()) {
      case 63: {
         get_lexval();
         y = yylval;
#line 58 "spec.acc"
_add_node_stack(y.stringval);
# line 293 "yygrammar.c"
         } break;
      case 64: {
         operacao_consulta();
         } break;
      default: printf("???\n"); exit(1);
      }
      get_lexval();
#line 58 "spec.acc"
_add_node_stack(")");
# line 303 "yygrammar.c"
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
# line 317 "yygrammar.c"
      get_lexval();
#line 62 "spec.acc"
_add_node_stack("(");
# line 321 "yygrammar.c"
      switch (yyselect()) {
      case 65: {
         get_lexval();
         y = yylval;
#line 62 "spec.acc"
_add_node_stack(y.stringval);
# line 328 "yygrammar.c"
         } break;
      case 66: {
         operacao_consulta();
         } break;
      default: printf("???\n"); exit(1);
      }
      get_lexval();
#line 62 "spec.acc"
_add_node_stack(")");
# line 338 "yygrammar.c"
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
# line 352 "yygrammar.c"
      get_lexval();
#line 66 "spec.acc"
_add_node_stack("ATRIBUICAO");
# line 356 "yygrammar.c"
      operacao_consulta();
      } break;
   case 24: {
      get_lexval();
      y = yylval;
      get_lexval();
      lista_atributos();
#line 68 "spec.acc"
_add_node_stack(y.stringval);
# line 366 "yygrammar.c"
      get_lexval();
      get_lexval();
#line 68 "spec.acc"
_add_node_stack("ATRIBUICAO");
# line 371 "yygrammar.c"
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
# line 387 "yygrammar.c"
#line 72 "spec.acc"
 _add_node_stack("RHO");
# line 390 "yygrammar.c"
      get_lexval();
#line 72 "spec.acc"
_add_node_stack("(");
# line 394 "yygrammar.c"
      switch (yyselect()) {
      case 67: {
         get_lexval();
         y = yylval;
#line 72 "spec.acc"
_add_node_stack(y.stringval);
# line 401 "yygrammar.c"
         } break;
      case 68: {
         operacao_consulta();
         } break;
      default: printf("???\n"); exit(1);
      }
      get_lexval();
#line 72 "spec.acc"
_add_node_stack(")");
# line 411 "yygrammar.c"
      } break;
   case 26: {
      get_lexval();
      get_lexval();
      y = yylval;
#line 74 "spec.acc"
_add_symbols_attribute(y.stringval,1);
# line 419 "yygrammar.c"
      get_lexval();
#line 74 "spec.acc"
_add_symbols_attribute("(",1);
# line 423 "yygrammar.c"
      lista_atributos();
      get_lexval();
#line 74 "spec.acc"
_add_symbols_attribute(")",1);
# line 428 "yygrammar.c"
#line 74 "spec.acc"
_add_node_stack("RHO");
# line 431 "yygrammar.c"
      get_lexval();
#line 74 "spec.acc"
_add_node_stack("(");
# line 435 "yygrammar.c"
      switch (yyselect()) {
      case 69: {
         get_lexval();
         y = yylval;
#line 74 "spec.acc"
_add_node_stack(y.stringval);
# line 442 "yygrammar.c"
         } break;
      case 70: {
         operacao_consulta();
         } break;
      default: printf("???\n"); exit(1);
      }
      get_lexval();
#line 74 "spec.acc"
_add_node_stack(")");
# line 452 "yygrammar.c"
      } break;
   case 27: {
      get_lexval();
      get_lexval();
#line 76 "spec.acc"
_add_symbols_attribute("(",1);
# line 459 "yygrammar.c"
      lista_atributos();
      get_lexval();
#line 76 "spec.acc"
_add_symbols_attribute(")",1);
# line 464 "yygrammar.c"
#line 76 "spec.acc"
_add_node_stack("RHO");
# line 467 "yygrammar.c"
      get_lexval();
#line 76 "spec.acc"
_add_node_stack("(");
# line 471 "yygrammar.c"
      switch (yyselect()) {
      case 71: {
         get_lexval();
         y = yylval;
#line 76 "spec.acc"
_add_node_stack(y.stringval);
# line 478 "yygrammar.c"
         } break;
      case 72: {
         operacao_consulta();
         } break;
      default: printf("???\n"); exit(1);
      }
      get_lexval();
#line 76 "spec.acc"
_add_node_stack(")");
# line 488 "yygrammar.c"
      } break;
   }
}

agrupamento ()
{
   YYSTYPE y;
   switch(yyselect()) {
   case 28: {
      switch (yyselect()) {
      case 73: {
         lista_atributos();
         } break;
      default: ;
      }
      get_lexval();
      lista_funcoes_agregadas();
#line 80 "spec.acc"
 _add_node_stack("FSCRIPT");
# line 508 "yygrammar.c"
      get_lexval();
      switch (yyselect()) {
      case 74: {
         get_lexval();
         y = yylval;
#line 80 "spec.acc"
_add_node_stack(y.stringval);
# line 516 "yygrammar.c"
         } break;
      case 75: {
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
# line 543 "yygrammar.c"
      condicao();
      operador_booleano();
      predicado();
      get_lexval();
#line 88 "spec.acc"
_add_symbols_predicate(")");
# line 550 "yygrammar.c"
      switch (yyselect()) {
      case 76: {
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
# line 570 "yygrammar.c"
      switch (yyselect()) {
      case 77: {
         get_lexval();
         a = yylval;
#line 92 "spec.acc"
_add_symbols_predicate(a.stringval);
# line 577 "yygrammar.c"
         } break;
      case 78: {
         get_lexval();
         a = yylval;
#line 92 "spec.acc"
_add_symbols_predicate(a.stringval);
# line 584 "yygrammar.c"
         } break;
      default: printf("???\n"); exit(1);
      }
      operador_comparacao();
      switch (yyselect()) {
      case 79: {
         get_lexval();
         a = yylval;
#line 92 "spec.acc"
_add_symbols_predicate(a.stringval);
# line 595 "yygrammar.c"
         } break;
      case 80: {
         get_lexval();
         a = yylval;
#line 92 "spec.acc"
_add_symbols_predicate(a.stringval);
# line 602 "yygrammar.c"
         } break;
      default: printf("???\n"); exit(1);
      }
      get_lexval();
#line 92 "spec.acc"
_add_symbols_predicate(")");
# line 609 "yygrammar.c"
      } break;
   case 33: {
      switch (yyselect()) {
      case 81: {
         get_lexval();
         a = yylval;
#line 93 "spec.acc"
_add_symbols_predicate(a.stringval);
# line 618 "yygrammar.c"
         } break;
      case 82: {
         get_lexval();
         a = yylval;
#line 93 "spec.acc"
_add_symbols_predicate(a.stringval);
# line 625 "yygrammar.c"
         } break;
      default: printf("???\n"); exit(1);
      }
      operador_comparacao();
      switch (yyselect()) {
      case 83: {
         get_lexval();
         a = yylval;
#line 93 "spec.acc"
_add_symbols_predicate(a.stringval);
# line 636 "yygrammar.c"
         } break;
      case 84: {
         get_lexval();
         a = yylval;
#line 93 "spec.acc"
_add_symbols_predicate(a.stringval);
# line 643 "yygrammar.c"
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
# line 658 "yygrammar.c"
      } break;
   case 35: {
      get_lexval();
#line 99 "spec.acc"
_add_symbols_predicate("<");
# line 664 "yygrammar.c"
      } break;
   case 36: {
      get_lexval();
#line 101 "spec.acc"
_add_symbols_predicate(">");
# line 670 "yygrammar.c"
      } break;
   case 37: {
      get_lexval();
      get_lexval();
#line 103 "spec.acc"
_add_symbols_predicate("<=");
# line 677 "yygrammar.c"
      } break;
   case 38: {
      get_lexval();
      get_lexval();
#line 105 "spec.acc"
_add_symbols_predicate(">=");
# line 684 "yygrammar.c"
      } break;
   case 39: {
      get_lexval();
      get_lexval();
#line 107 "spec.acc"
_add_symbols_predicate("!=");
# line 691 "yygrammar.c"
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
# line 703 "yygrammar.c"
      } break;
   case 41: {
      get_lexval();
#line 113 "spec.acc"
_add_symbols_attribute("-",1);
# line 709 "yygrammar.c"
      } break;
   case 42: {
      get_lexval();
#line 115 "spec.acc"
_add_symbols_attribute("*",1);
# line 715 "yygrammar.c"
      } break;
   case 43: {
      get_lexval();
#line 117 "spec.acc"
_add_symbols_attribute("/",1);
# line 721 "yygrammar.c"
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
# line 733 "yygrammar.c"
      } break;
   case 45: {
      get_lexval();
#line 123 "spec.acc"
_add_symbols_predicate(" OR ");
# line 739 "yygrammar.c"
      } break;
   }
}

lista_atributos ()
{
   YYSTYPE a;
   switch(yyselect()) {
   case 46: {
      switch (yyselect()) {
      case 85: {
         get_lexval();
         a = yylval;
#line 127 "spec.acc"
_add_symbols_attribute(a.stringval,1);
# line 755 "yygrammar.c"
         } break;
      case 86: {
         get_lexval();
         a = yylval;
#line 127 "spec.acc"
_add_symbols_attribute(a.stringval,1);
# line 762 "yygrammar.c"
         } break;
      default: printf("???\n"); exit(1);
      }
      while (1) {
         switch (yyselect()) {
         case 89: {
            operador_aritmetico();
            switch (yyselect()) {
            case 87: {
               get_lexval();
               a = yylval;
#line 127 "spec.acc"
_add_symbols_attribute(a.stringval,1);
# line 776 "yygrammar.c"
               } break;
            case 88: {
               get_lexval();
               a = yylval;
#line 127 "spec.acc"
_add_symbols_attribute(a.stringval,1);
# line 783 "yygrammar.c"
               } break;
            default: printf("???\n"); exit(1);
            }
            } break;
         default: goto yy2;
         }
      }
      yy2: ;
      switch (yyselect()) {
      case 90: {
         get_lexval();
#line 127 "spec.acc"
_add_symbols_attribute(",",1);
# line 797 "yygrammar.c"
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
      case 91: {
         get_lexval();
#line 131 "spec.acc"
_add_symbols_attribute("COUNT ",2);
# line 816 "yygrammar.c"
         } break;
      case 92: {
         get_lexval();
#line 131 "spec.acc"
_add_symbols_attribute("AVERAGE ",2);
# line 822 "yygrammar.c"
         } break;
      case 93: {
         get_lexval();
#line 131 "spec.acc"
_add_symbols_attribute("MAX ",2);
# line 828 "yygrammar.c"
         } break;
      case 94: {
         get_lexval();
#line 131 "spec.acc"
_add_symbols_attribute("MIN ",2);
# line 834 "yygrammar.c"
         } break;
      case 95: {
         get_lexval();
#line 131 "spec.acc"
_add_symbols_attribute("SUM ",2);
# line 840 "yygrammar.c"
         } break;
      default: printf("???\n"); exit(1);
      }
      get_lexval();
      y = yylval;
#line 131 "spec.acc"
_add_symbols_attribute(y.stringval,2);
# line 848 "yygrammar.c"
      switch (yyselect()) {
      case 96: {
         get_lexval();
#line 131 "spec.acc"
_add_symbols_attribute(",",2);
# line 854 "yygrammar.c"
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
int c_length = 488;
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
/* 17 */ 97,
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
/* 34 */ 98,
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
/* 49 */ 99,
/* 50 */ 54,
/* 51 */ 168,
/* 52 */ -50,
/* 53 */ 4,
/* 54 */ 58,
/* 55 */ 184,
/* 56 */ -50,
/* 57 */ 5,
/* 58 */ 62,
/* 59 */ 200,
/* 60 */ -50,
/* 61 */ 6,
/* 62 */ 66,
/* 63 */ 215,
/* 64 */ -50,
/* 65 */ 7,
/* 66 */ 0,
/* 67 */ 268,
/* 68 */ -50,
/* 69 */ 8,
/* 70 */ 76,
/* 71 */ 82,
/* 72 */ 124,
/* 73 */ 96,
/* 74 */ -70,
/* 75 */ 9,
/* 76 */ 0,
/* 77 */ 110,
/* 78 */ 50270,
/* 79 */ 215,
/* 80 */ -70,
/* 81 */ 10,
/* 82 */ 86,
/* 83 */ 50257,
/* 84 */ -82,
/* 85 */ 54,
/* 86 */ 90,
/* 87 */ 18,
/* 88 */ -82,
/* 89 */ 55,
/* 90 */ 0,
/* 91 */ 50040,
/* 92 */ 50257,
/* 93 */ 50041,
/* 94 */ -82,
/* 95 */ 56,
/* 96 */ 100,
/* 97 */ 50257,
/* 98 */ -96,
/* 99 */ 57,
/* 100 */ 104,
/* 101 */ 18,
/* 102 */ -96,
/* 103 */ 58,
/* 104 */ 0,
/* 105 */ 50040,
/* 106 */ 50257,
/* 107 */ 50041,
/* 108 */ -96,
/* 109 */ 59,
/* 110 */ 114,
/* 111 */ 50257,
/* 112 */ -110,
/* 113 */ 60,
/* 114 */ 118,
/* 115 */ 18,
/* 116 */ -110,
/* 117 */ 61,
/* 118 */ 0,
/* 119 */ 50040,
/* 120 */ 50257,
/* 121 */ 50041,
/* 122 */ -110,
/* 123 */ 62,
/* 124 */ 128,
/* 125 */ 50265,
/* 126 */ -124,
/* 127 */ 11,
/* 128 */ 132,
/* 129 */ 50266,
/* 130 */ -124,
/* 131 */ 12,
/* 132 */ 136,
/* 133 */ 50267,
/* 134 */ -124,
/* 135 */ 13,
/* 136 */ 140,
/* 137 */ 50268,
/* 138 */ -124,
/* 139 */ 14,
/* 140 */ 145,
/* 141 */ 50269,
/* 142 */ 292,
/* 143 */ -124,
/* 144 */ 15,
/* 145 */ 149,
/* 146 */ 50270,
/* 147 */ -124,
/* 148 */ 16,
/* 149 */ 154,
/* 150 */ 50278,
/* 151 */ 292,
/* 152 */ -124,
/* 153 */ 17,
/* 154 */ 159,
/* 155 */ 50279,
/* 156 */ 292,
/* 157 */ -124,
/* 158 */ 18,
/* 159 */ 164,
/* 160 */ 50280,
/* 161 */ 292,
/* 162 */ -124,
/* 163 */ 19,
/* 164 */ 0,
/* 165 */ 50271,
/* 166 */ -124,
/* 167 */ 20,
/* 168 */ 0,
/* 169 */ 50258,
/* 170 */ 292,
/* 171 */ 50040,
/* 172 */ 176,
/* 173 */ 50041,
/* 174 */ -168,
/* 175 */ 21,
/* 176 */ 180,
/* 177 */ 50257,
/* 178 */ -176,
/* 179 */ 63,
/* 180 */ 0,
/* 181 */ 18,
/* 182 */ -176,
/* 183 */ 64,
/* 184 */ 0,
/* 185 */ 50259,
/* 186 */ 416,
/* 187 */ 50040,
/* 188 */ 192,
/* 189 */ 50041,
/* 190 */ -184,
/* 191 */ 22,
/* 192 */ 196,
/* 193 */ 50257,
/* 194 */ -192,
/* 195 */ 65,
/* 196 */ 0,
/* 197 */ 18,
/* 198 */ -192,
/* 199 */ 66,
/* 200 */ 206,
/* 201 */ 50257,
/* 202 */ 50260,
/* 203 */ 18,
/* 204 */ -200,
/* 205 */ 23,
/* 206 */ 0,
/* 207 */ 50257,
/* 208 */ 50040,
/* 209 */ 416,
/* 210 */ 50041,
/* 211 */ 50260,
/* 212 */ 18,
/* 213 */ -200,
/* 214 */ 24,
/* 215 */ 223,
/* 216 */ 50261,
/* 217 */ 50257,
/* 218 */ 50040,
/* 219 */ 244,
/* 220 */ 50041,
/* 221 */ -215,
/* 222 */ 25,
/* 223 */ 234,
/* 224 */ 50261,
/* 225 */ 50257,
/* 226 */ 50040,
/* 227 */ 416,
/* 228 */ 50041,
/* 229 */ 50040,
/* 230 */ 252,
/* 231 */ 50041,
/* 232 */ -215,
/* 233 */ 26,
/* 234 */ 0,
/* 235 */ 50261,
/* 236 */ 50040,
/* 237 */ 416,
/* 238 */ 50041,
/* 239 */ 50040,
/* 240 */ 260,
/* 241 */ 50041,
/* 242 */ -215,
/* 243 */ 27,
/* 244 */ 248,
/* 245 */ 50257,
/* 246 */ -244,
/* 247 */ 67,
/* 248 */ 0,
/* 249 */ 18,
/* 250 */ -244,
/* 251 */ 68,
/* 252 */ 256,
/* 253 */ 50257,
/* 254 */ -252,
/* 255 */ 69,
/* 256 */ 0,
/* 257 */ 18,
/* 258 */ -252,
/* 259 */ 70,
/* 260 */ 264,
/* 261 */ 50257,
/* 262 */ -260,
/* 263 */ 71,
/* 264 */ 0,
/* 265 */ 18,
/* 266 */ -260,
/* 267 */ 72,
/* 268 */ 0,
/* 269 */ 277,
/* 270 */ 50277,
/* 271 */ 455,
/* 272 */ 50040,
/* 273 */ 284,
/* 274 */ 50041,
/* 275 */ -268,
/* 276 */ 28,
/* 277 */ 281,
/* 278 */ 416,
/* 279 */ -277,
/* 280 */ 73,
/* 281 */ 0,
/* 282 */ -277,
/* 283 */ 100,
/* 284 */ 288,
/* 285 */ 50257,
/* 286 */ -284,
/* 287 */ 74,
/* 288 */ 0,
/* 289 */ 18,
/* 290 */ -284,
/* 291 */ 75,
/* 292 */ 296,
/* 293 */ 319,
/* 294 */ -292,
/* 295 */ 29,
/* 296 */ 302,
/* 297 */ 319,
/* 298 */ 408,
/* 299 */ 292,
/* 300 */ -292,
/* 301 */ 30,
/* 302 */ 0,
/* 303 */ 50040,
/* 304 */ 319,
/* 305 */ 408,
/* 306 */ 292,
/* 307 */ 50041,
/* 308 */ 311,
/* 309 */ -292,
/* 310 */ 31,
/* 311 */ 316,
/* 312 */ 408,
/* 313 */ 292,
/* 314 */ -311,
/* 315 */ 76,
/* 316 */ 0,
/* 317 */ -311,
/* 318 */ 101,
/* 319 */ 327,
/* 320 */ 50040,
/* 321 */ 333,
/* 322 */ 365,
/* 323 */ 341,
/* 324 */ 50041,
/* 325 */ -319,
/* 326 */ 32,
/* 327 */ 0,
/* 328 */ 349,
/* 329 */ 365,
/* 330 */ 357,
/* 331 */ -319,
/* 332 */ 33,
/* 333 */ 337,
/* 334 */ 50257,
/* 335 */ -333,
/* 336 */ 77,
/* 337 */ 0,
/* 338 */ 50256,
/* 339 */ -333,
/* 340 */ 78,
/* 341 */ 345,
/* 342 */ 50257,
/* 343 */ -341,
/* 344 */ 79,
/* 345 */ 0,
/* 346 */ 50256,
/* 347 */ -341,
/* 348 */ 80,
/* 349 */ 353,
/* 350 */ 50257,
/* 351 */ -349,
/* 352 */ 81,
/* 353 */ 0,
/* 354 */ 50256,
/* 355 */ -349,
/* 356 */ 82,
/* 357 */ 361,
/* 358 */ 50257,
/* 359 */ -357,
/* 360 */ 83,
/* 361 */ 0,
/* 362 */ 50256,
/* 363 */ -357,
/* 364 */ 84,
/* 365 */ 369,
/* 366 */ 50061,
/* 367 */ -365,
/* 368 */ 34,
/* 369 */ 373,
/* 370 */ 50060,
/* 371 */ -365,
/* 372 */ 35,
/* 373 */ 377,
/* 374 */ 50062,
/* 375 */ -365,
/* 376 */ 36,
/* 377 */ 382,
/* 378 */ 50060,
/* 379 */ 50061,
/* 380 */ -365,
/* 381 */ 37,
/* 382 */ 387,
/* 383 */ 50062,
/* 384 */ 50061,
/* 385 */ -365,
/* 386 */ 38,
/* 387 */ 0,
/* 388 */ 50033,
/* 389 */ 50061,
/* 390 */ -365,
/* 391 */ 39,
/* 392 */ 396,
/* 393 */ 50043,
/* 394 */ -392,
/* 395 */ 40,
/* 396 */ 400,
/* 397 */ 50045,
/* 398 */ -392,
/* 399 */ 41,
/* 400 */ 404,
/* 401 */ 50042,
/* 402 */ -392,
/* 403 */ 42,
/* 404 */ 0,
/* 405 */ 50047,
/* 406 */ -392,
/* 407 */ 43,
/* 408 */ 412,
/* 409 */ 50262,
/* 410 */ -408,
/* 411 */ 44,
/* 412 */ 0,
/* 413 */ 50263,
/* 414 */ -408,
/* 415 */ 45,
/* 416 */ 0,
/* 417 */ 422,
/* 418 */ 430,
/* 419 */ 447,
/* 420 */ -416,
/* 421 */ 46,
/* 422 */ 426,
/* 423 */ 50257,
/* 424 */ -422,
/* 425 */ 85,
/* 426 */ 0,
/* 427 */ 50256,
/* 428 */ -422,
/* 429 */ 86,
/* 430 */ 436,
/* 431 */ 392,
/* 432 */ 439,
/* 433 */ 430,
/* 434 */ -430,
/* 435 */ 89,
/* 436 */ 0,
/* 437 */ -430,
/* 438 */ 102,
/* 439 */ 443,
/* 440 */ 50257,
/* 441 */ -439,
/* 442 */ 87,
/* 443 */ 0,
/* 444 */ 50256,
/* 445 */ -439,
/* 446 */ 88,
/* 447 */ 452,
/* 448 */ 50044,
/* 449 */ 416,
/* 450 */ -447,
/* 451 */ 90,
/* 452 */ 0,
/* 453 */ -447,
/* 454 */ 103,
/* 455 */ 0,
/* 456 */ 461,
/* 457 */ 50257,
/* 458 */ 481,
/* 459 */ -455,
/* 460 */ 47,
/* 461 */ 465,
/* 462 */ 50272,
/* 463 */ -461,
/* 464 */ 91,
/* 465 */ 469,
/* 466 */ 50273,
/* 467 */ -461,
/* 468 */ 92,
/* 469 */ 473,
/* 470 */ 50274,
/* 471 */ -461,
/* 472 */ 93,
/* 473 */ 477,
/* 474 */ 50275,
/* 475 */ -461,
/* 476 */ 94,
/* 477 */ 0,
/* 478 */ 50276,
/* 479 */ -461,
/* 480 */ 95,
/* 481 */ 486,
/* 482 */ 50044,
/* 483 */ 455,
/* 484 */ -481,
/* 485 */ 96,
/* 486 */ 0,
/* 487 */ -481,
/* 488 */ 104,
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
/* 86 */ 90,
/* 87 */ 1,
/* 88 */ -82,
/* 89 */ 2,
/* 90 */ 0,
/* 91 */ 50040,
/* 92 */ 50257,
/* 93 */ 50041,
/* 94 */ -82,
/* 95 */ 3,
/* 96 */ 100,
/* 97 */ 50257,
/* 98 */ -96,
/* 99 */ 1,
/* 100 */ 104,
/* 101 */ 1,
/* 102 */ -96,
/* 103 */ 2,
/* 104 */ 0,
/* 105 */ 50040,
/* 106 */ 50257,
/* 107 */ 50041,
/* 108 */ -96,
/* 109 */ 3,
/* 110 */ 114,
/* 111 */ 50257,
/* 112 */ -110,
/* 113 */ 1,
/* 114 */ 118,
/* 115 */ 1,
/* 116 */ -110,
/* 117 */ 2,
/* 118 */ 0,
/* 119 */ 50040,
/* 120 */ 50257,
/* 121 */ 50041,
/* 122 */ -110,
/* 123 */ 3,
/* 124 */ 128,
/* 125 */ 50265,
/* 126 */ -124,
/* 127 */ 1,
/* 128 */ 132,
/* 129 */ 50266,
/* 130 */ -124,
/* 131 */ 2,
/* 132 */ 136,
/* 133 */ 50267,
/* 134 */ -124,
/* 135 */ 3,
/* 136 */ 140,
/* 137 */ 50268,
/* 138 */ -124,
/* 139 */ 4,
/* 140 */ 145,
/* 141 */ 50269,
/* 142 */ 1,
/* 143 */ -124,
/* 144 */ 5,
/* 145 */ 149,
/* 146 */ 50270,
/* 147 */ -124,
/* 148 */ 6,
/* 149 */ 154,
/* 150 */ 50278,
/* 151 */ 1,
/* 152 */ -124,
/* 153 */ 7,
/* 154 */ 159,
/* 155 */ 50279,
/* 156 */ 1,
/* 157 */ -124,
/* 158 */ 8,
/* 159 */ 164,
/* 160 */ 50280,
/* 161 */ 1,
/* 162 */ -124,
/* 163 */ 9,
/* 164 */ 0,
/* 165 */ 50271,
/* 166 */ -124,
/* 167 */ 10,
/* 168 */ 0,
/* 169 */ 50258,
/* 170 */ 1,
/* 171 */ 50040,
/* 172 */ 1,
/* 173 */ 50041,
/* 174 */ -168,
/* 175 */ 1,
/* 176 */ 180,
/* 177 */ 50257,
/* 178 */ -176,
/* 179 */ 1,
/* 180 */ 0,
/* 181 */ 1,
/* 182 */ -176,
/* 183 */ 2,
/* 184 */ 0,
/* 185 */ 50259,
/* 186 */ 1,
/* 187 */ 50040,
/* 188 */ 1,
/* 189 */ 50041,
/* 190 */ -184,
/* 191 */ 1,
/* 192 */ 196,
/* 193 */ 50257,
/* 194 */ -192,
/* 195 */ 1,
/* 196 */ 0,
/* 197 */ 1,
/* 198 */ -192,
/* 199 */ 2,
/* 200 */ 206,
/* 201 */ 50257,
/* 202 */ 50260,
/* 203 */ 1,
/* 204 */ -200,
/* 205 */ 1,
/* 206 */ 0,
/* 207 */ 50257,
/* 208 */ 50040,
/* 209 */ 1,
/* 210 */ 50041,
/* 211 */ 50260,
/* 212 */ 1,
/* 213 */ -200,
/* 214 */ 2,
/* 215 */ 223,
/* 216 */ 50261,
/* 217 */ 50257,
/* 218 */ 50040,
/* 219 */ 1,
/* 220 */ 50041,
/* 221 */ -215,
/* 222 */ 1,
/* 223 */ 234,
/* 224 */ 50261,
/* 225 */ 50257,
/* 226 */ 50040,
/* 227 */ 1,
/* 228 */ 50041,
/* 229 */ 50040,
/* 230 */ 1,
/* 231 */ 50041,
/* 232 */ -215,
/* 233 */ 2,
/* 234 */ 0,
/* 235 */ 50261,
/* 236 */ 50040,
/* 237 */ 1,
/* 238 */ 50041,
/* 239 */ 50040,
/* 240 */ 1,
/* 241 */ 50041,
/* 242 */ -215,
/* 243 */ 3,
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
/* 260 */ 264,
/* 261 */ 50257,
/* 262 */ -260,
/* 263 */ 1,
/* 264 */ 0,
/* 265 */ 1,
/* 266 */ -260,
/* 267 */ 2,
/* 268 */ 0,
/* 269 */ 1,
/* 270 */ 50277,
/* 271 */ 1,
/* 272 */ 50040,
/* 273 */ 1,
/* 274 */ 50041,
/* 275 */ -268,
/* 276 */ 1,
/* 277 */ 281,
/* 278 */ 1,
/* 279 */ -277,
/* 280 */ 1,
/* 281 */ 0,
/* 282 */ -277,
/* 283 */ 2,
/* 284 */ 288,
/* 285 */ 50257,
/* 286 */ -284,
/* 287 */ 1,
/* 288 */ 0,
/* 289 */ 1,
/* 290 */ -284,
/* 291 */ 2,
/* 292 */ 296,
/* 293 */ 1,
/* 294 */ -292,
/* 295 */ 1,
/* 296 */ 302,
/* 297 */ 1,
/* 298 */ 1,
/* 299 */ 1,
/* 300 */ -292,
/* 301 */ 2,
/* 302 */ 0,
/* 303 */ 50040,
/* 304 */ 1,
/* 305 */ 1,
/* 306 */ 1,
/* 307 */ 50041,
/* 308 */ 1,
/* 309 */ -292,
/* 310 */ 3,
/* 311 */ 316,
/* 312 */ 1,
/* 313 */ 1,
/* 314 */ -311,
/* 315 */ 1,
/* 316 */ 0,
/* 317 */ -311,
/* 318 */ 2,
/* 319 */ 327,
/* 320 */ 50040,
/* 321 */ 1,
/* 322 */ 1,
/* 323 */ 1,
/* 324 */ 50041,
/* 325 */ -319,
/* 326 */ 1,
/* 327 */ 0,
/* 328 */ 1,
/* 329 */ 1,
/* 330 */ 1,
/* 331 */ -319,
/* 332 */ 2,
/* 333 */ 337,
/* 334 */ 50257,
/* 335 */ -333,
/* 336 */ 1,
/* 337 */ 0,
/* 338 */ 50256,
/* 339 */ -333,
/* 340 */ 2,
/* 341 */ 345,
/* 342 */ 50257,
/* 343 */ -341,
/* 344 */ 1,
/* 345 */ 0,
/* 346 */ 50256,
/* 347 */ -341,
/* 348 */ 2,
/* 349 */ 353,
/* 350 */ 50257,
/* 351 */ -349,
/* 352 */ 1,
/* 353 */ 0,
/* 354 */ 50256,
/* 355 */ -349,
/* 356 */ 2,
/* 357 */ 361,
/* 358 */ 50257,
/* 359 */ -357,
/* 360 */ 1,
/* 361 */ 0,
/* 362 */ 50256,
/* 363 */ -357,
/* 364 */ 2,
/* 365 */ 369,
/* 366 */ 50061,
/* 367 */ -365,
/* 368 */ 1,
/* 369 */ 373,
/* 370 */ 50060,
/* 371 */ -365,
/* 372 */ 2,
/* 373 */ 377,
/* 374 */ 50062,
/* 375 */ -365,
/* 376 */ 3,
/* 377 */ 382,
/* 378 */ 50060,
/* 379 */ 50061,
/* 380 */ -365,
/* 381 */ 4,
/* 382 */ 387,
/* 383 */ 50062,
/* 384 */ 50061,
/* 385 */ -365,
/* 386 */ 5,
/* 387 */ 0,
/* 388 */ 50033,
/* 389 */ 50061,
/* 390 */ -365,
/* 391 */ 6,
/* 392 */ 396,
/* 393 */ 50043,
/* 394 */ -392,
/* 395 */ 1,
/* 396 */ 400,
/* 397 */ 50045,
/* 398 */ -392,
/* 399 */ 2,
/* 400 */ 404,
/* 401 */ 50042,
/* 402 */ -392,
/* 403 */ 3,
/* 404 */ 0,
/* 405 */ 50047,
/* 406 */ -392,
/* 407 */ 4,
/* 408 */ 412,
/* 409 */ 50262,
/* 410 */ -408,
/* 411 */ 1,
/* 412 */ 0,
/* 413 */ 50263,
/* 414 */ -408,
/* 415 */ 2,
/* 416 */ 0,
/* 417 */ 1,
/* 418 */ 1,
/* 419 */ 1,
/* 420 */ -416,
/* 421 */ 1,
/* 422 */ 426,
/* 423 */ 50257,
/* 424 */ -422,
/* 425 */ 1,
/* 426 */ 0,
/* 427 */ 50256,
/* 428 */ -422,
/* 429 */ 2,
/* 430 */ 436,
/* 431 */ 1,
/* 432 */ 1,
/* 433 */ 1,
/* 434 */ -430,
/* 435 */ 1,
/* 436 */ 0,
/* 437 */ -430,
/* 438 */ 2,
/* 439 */ 443,
/* 440 */ 50257,
/* 441 */ -439,
/* 442 */ 1,
/* 443 */ 0,
/* 444 */ 50256,
/* 445 */ -439,
/* 446 */ 2,
/* 447 */ 452,
/* 448 */ 50044,
/* 449 */ 1,
/* 450 */ -447,
/* 451 */ 1,
/* 452 */ 0,
/* 453 */ -447,
/* 454 */ 2,
/* 455 */ 0,
/* 456 */ 1,
/* 457 */ 50257,
/* 458 */ 1,
/* 459 */ -455,
/* 460 */ 1,
/* 461 */ 465,
/* 462 */ 50272,
/* 463 */ -461,
/* 464 */ 1,
/* 465 */ 469,
/* 466 */ 50273,
/* 467 */ -461,
/* 468 */ 2,
/* 469 */ 473,
/* 470 */ 50274,
/* 471 */ -461,
/* 472 */ 3,
/* 473 */ 477,
/* 474 */ 50275,
/* 475 */ -461,
/* 476 */ 4,
/* 477 */ 0,
/* 478 */ 50276,
/* 479 */ -461,
/* 480 */ 5,
/* 481 */ 486,
/* 482 */ 50044,
/* 483 */ 1,
/* 484 */ -481,
/* 485 */ 1,
/* 486 */ 0,
/* 487 */ -481,
/* 488 */ 2,
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
/* 72 */ 30171,
/* 73 */ 30193,
/* 74 */ 9999,
/* 75 */ 30009,
/* 76 */ 9999,
/* 77 */ 32009,
/* 78 */ 9999,
/* 79 */ 32223,
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
/* 93 */ 9999,
/* 94 */ 9999,
/* 95 */ 30073,
/* 96 */ 9999,
/* 97 */ 9999,
/* 98 */ 9999,
/* 99 */ 30198,
/* 100 */ 9999,
/* 101 */ 30237,
/* 102 */ 9999,
/* 103 */ 30253,
/* 104 */ 9999,
/* 105 */ 9999,
/* 106 */ 9999,
/* 107 */ 9999,
/* 108 */ 9999,
/* 109 */ 30257,
/* 110 */ 9999,
/* 111 */ 9999,
/* 112 */ 9999,
/* 113 */ 32014,
/* 114 */ 9999,
/* 115 */ 32053,
/* 116 */ 9999,
/* 117 */ 32069,
/* 118 */ 9999,
/* 119 */ 9999,
/* 120 */ 9999,
/* 121 */ 9999,
/* 122 */ 9999,
/* 123 */ 32073,
/* 124 */ 9999,
/* 125 */ 9999,
/* 126 */ 9999,
/* 127 */ 36013,
/* 128 */ 9999,
/* 129 */ 9999,
/* 130 */ 9999,
/* 131 */ 38019,
/* 132 */ 9999,
/* 133 */ 9999,
/* 134 */ 9999,
/* 135 */ 40017,
/* 136 */ 9999,
/* 137 */ 9999,
/* 138 */ 9999,
/* 139 */ 42026,
/* 140 */ 9999,
/* 141 */ 9999,
/* 142 */ 44016,
/* 143 */ 9999,
/* 144 */ 44014,
/* 145 */ 9999,
/* 146 */ 9999,
/* 147 */ 9999,
/* 148 */ 46022,
/* 149 */ 9999,
/* 150 */ 9999,
/* 151 */ 48033,
/* 152 */ 9999,
/* 153 */ 48031,
/* 154 */ 9999,
/* 155 */ 9999,
/* 156 */ 50032,
/* 157 */ 9999,
/* 158 */ 50030,
/* 159 */ 9999,
/* 160 */ 9999,
/* 161 */ 52033,
/* 162 */ 9999,
/* 163 */ 52031,
/* 164 */ 9999,
/* 165 */ 9999,
/* 166 */ 9999,
/* 167 */ 54015,
/* 168 */ 9999,
/* 169 */ 9999,
/* 170 */ 58011,
/* 171 */ 9999,
/* 172 */ 58077,
/* 173 */ 9999,
/* 174 */ 9999,
/* 175 */ 58009,
/* 176 */ 9999,
/* 177 */ 9999,
/* 178 */ 9999,
/* 179 */ 58082,
/* 180 */ 9999,
/* 181 */ 58121,
/* 182 */ 9999,
/* 183 */ 58137,
/* 184 */ 9999,
/* 185 */ 9999,
/* 186 */ 62008,
/* 187 */ 9999,
/* 188 */ 62077,
/* 189 */ 9999,
/* 190 */ 9999,
/* 191 */ 62006,
/* 192 */ 9999,
/* 193 */ 9999,
/* 194 */ 9999,
/* 195 */ 62082,
/* 196 */ 9999,
/* 197 */ 62121,
/* 198 */ 9999,
/* 199 */ 62137,
/* 200 */ 9999,
/* 201 */ 9999,
/* 202 */ 9999,
/* 203 */ 66093,
/* 204 */ 9999,
/* 205 */ 66012,
/* 206 */ 9999,
/* 207 */ 9999,
/* 208 */ 9999,
/* 209 */ 68021,
/* 210 */ 9999,
/* 211 */ 9999,
/* 212 */ 68117,
/* 213 */ 9999,
/* 214 */ 68012,
/* 215 */ 9999,
/* 216 */ 9999,
/* 217 */ 9999,
/* 218 */ 9999,
/* 219 */ 72117,
/* 220 */ 9999,
/* 221 */ 9999,
/* 222 */ 72011,
/* 223 */ 9999,
/* 224 */ 9999,
/* 225 */ 9999,
/* 226 */ 9999,
/* 227 */ 74100,
/* 228 */ 9999,
/* 229 */ 9999,
/* 230 */ 74207,
/* 231 */ 9999,
/* 232 */ 9999,
/* 233 */ 74011,
/* 234 */ 9999,
/* 235 */ 9999,
/* 236 */ 9999,
/* 237 */ 76050,
/* 238 */ 9999,
/* 239 */ 9999,
/* 240 */ 76159,
/* 241 */ 9999,
/* 242 */ 9999,
/* 243 */ 76011,
/* 244 */ 9999,
/* 245 */ 9999,
/* 246 */ 9999,
/* 247 */ 72122,
/* 248 */ 9999,
/* 249 */ 72161,
/* 250 */ 9999,
/* 251 */ 72177,
/* 252 */ 9999,
/* 253 */ 9999,
/* 254 */ 9999,
/* 255 */ 74212,
/* 256 */ 9999,
/* 257 */ 74251,
/* 258 */ 9999,
/* 259 */ 74267,
/* 260 */ 9999,
/* 261 */ 9999,
/* 262 */ 9999,
/* 263 */ 76164,
/* 264 */ 9999,
/* 265 */ 76203,
/* 266 */ 9999,
/* 267 */ 76219,
/* 268 */ 9999,
/* 269 */ 80005,
/* 270 */ 9999,
/* 271 */ 80032,
/* 272 */ 9999,
/* 273 */ 80091,
/* 274 */ 9999,
/* 275 */ 9999,
/* 276 */ 80005,
/* 277 */ 9999,
/* 278 */ 80006,
/* 279 */ 9999,
/* 280 */ 80020,
/* 281 */ 9999,
/* 282 */ 9999,
/* 283 */ 80020,
/* 284 */ 9999,
/* 285 */ 9999,
/* 286 */ 9999,
/* 287 */ 80096,
/* 288 */ 9999,
/* 289 */ 80135,
/* 290 */ 9999,
/* 291 */ 80151,
/* 292 */ 9999,
/* 293 */ 84009,
/* 294 */ 9999,
/* 295 */ 84016,
/* 296 */ 9999,
/* 297 */ 86009,
/* 298 */ 86018,
/* 299 */ 86036,
/* 300 */ 9999,
/* 301 */ 86016,
/* 302 */ 9999,
/* 303 */ 9999,
/* 304 */ 88044,
/* 305 */ 88053,
/* 306 */ 88071,
/* 307 */ 9999,
/* 308 */ 88116,
/* 309 */ 9999,
/* 310 */ 88009,
/* 311 */ 9999,
/* 312 */ 88117,
/* 313 */ 88135,
/* 314 */ 9999,
/* 315 */ 88133,
/* 316 */ 9999,
/* 317 */ 9999,
/* 318 */ 88133,
/* 319 */ 9999,
/* 320 */ 9999,
/* 321 */ 92041,
/* 322 */ 92142,
/* 323 */ 92162,
/* 324 */ 9999,
/* 325 */ 9999,
/* 326 */ 92005,
/* 327 */ 9999,
/* 328 */ 93007,
/* 329 */ 93109,
/* 330 */ 93129,
/* 331 */ 9999,
/* 332 */ 93007,
/* 333 */ 9999,
/* 334 */ 9999,
/* 335 */ 9999,
/* 336 */ 92046,
/* 337 */ 9999,
/* 338 */ 9999,
/* 339 */ 9999,
/* 340 */ 92097,
/* 341 */ 9999,
/* 342 */ 9999,
/* 343 */ 9999,
/* 344 */ 92167,
/* 345 */ 9999,
/* 346 */ 9999,
/* 347 */ 9999,
/* 348 */ 92218,
/* 349 */ 9999,
/* 350 */ 9999,
/* 351 */ 9999,
/* 352 */ 93012,
/* 353 */ 9999,
/* 354 */ 9999,
/* 355 */ 9999,
/* 356 */ 93063,
/* 357 */ 9999,
/* 358 */ 9999,
/* 359 */ 9999,
/* 360 */ 93134,
/* 361 */ 9999,
/* 362 */ 9999,
/* 363 */ 9999,
/* 364 */ 93185,
/* 365 */ 9999,
/* 366 */ 9999,
/* 367 */ 9999,
/* 368 */ 97009,
/* 369 */ 9999,
/* 370 */ 9999,
/* 371 */ 9999,
/* 372 */ 99009,
/* 373 */ 9999,
/* 374 */ 9999,
/* 375 */ 9999,
/* 376 */ 101009,
/* 377 */ 9999,
/* 378 */ 9999,
/* 379 */ 9999,
/* 380 */ 9999,
/* 381 */ 103009,
/* 382 */ 9999,
/* 383 */ 9999,
/* 384 */ 9999,
/* 385 */ 9999,
/* 386 */ 105009,
/* 387 */ 9999,
/* 388 */ 9999,
/* 389 */ 9999,
/* 390 */ 9999,
/* 391 */ 107009,
/* 392 */ 9999,
/* 393 */ 9999,
/* 394 */ 9999,
/* 395 */ 111009,
/* 396 */ 9999,
/* 397 */ 9999,
/* 398 */ 9999,
/* 399 */ 113009,
/* 400 */ 9999,
/* 401 */ 9999,
/* 402 */ 9999,
/* 403 */ 115009,
/* 404 */ 9999,
/* 405 */ 9999,
/* 406 */ 9999,
/* 407 */ 117009,
/* 408 */ 9999,
/* 409 */ 9999,
/* 410 */ 9999,
/* 411 */ 121011,
/* 412 */ 9999,
/* 413 */ 9999,
/* 414 */ 9999,
/* 415 */ 123010,
/* 416 */ 9999,
/* 417 */ 127005,
/* 418 */ 127112,
/* 419 */ 127245,
/* 420 */ 9999,
/* 421 */ 127005,
/* 422 */ 9999,
/* 423 */ 9999,
/* 424 */ 9999,
/* 425 */ 127010,
/* 426 */ 9999,
/* 427 */ 9999,
/* 428 */ 9999,
/* 429 */ 127063,
/* 430 */ 9999,
/* 431 */ 127114,
/* 432 */ 127134,
/* 433 */ 127132,
/* 434 */ 9999,
/* 435 */ 127132,
/* 436 */ 9999,
/* 437 */ 9999,
/* 438 */ 127132,
/* 439 */ 9999,
/* 440 */ 9999,
/* 441 */ 9999,
/* 442 */ 127139,
/* 443 */ 9999,
/* 444 */ 9999,
/* 445 */ 9999,
/* 446 */ 127192,
/* 447 */ 9999,
/* 448 */ 9999,
/* 449 */ 127284,
/* 450 */ 9999,
/* 451 */ 127247,
/* 452 */ 9999,
/* 453 */ 9999,
/* 454 */ 127247,
/* 455 */ 9999,
/* 456 */ 131005,
/* 457 */ 9999,
/* 458 */ 131278,
/* 459 */ 9999,
/* 460 */ 131005,
/* 461 */ 9999,
/* 462 */ 9999,
/* 463 */ 9999,
/* 464 */ 131011,
/* 465 */ 9999,
/* 466 */ 9999,
/* 467 */ 9999,
/* 468 */ 131059,
/* 469 */ 9999,
/* 470 */ 9999,
/* 471 */ 9999,
/* 472 */ 131105,
/* 473 */ 9999,
/* 474 */ 9999,
/* 475 */ 9999,
/* 476 */ 131147,
/* 477 */ 9999,
/* 478 */ 9999,
/* 479 */ 9999,
/* 480 */ 131189,
/* 481 */ 9999,
/* 482 */ 9999,
/* 483 */ 131317,
/* 484 */ 9999,
/* 485 */ 131280,
/* 486 */ 9999,
/* 487 */ 9999,
/* 488 */ 131280,
0
};
/* only for BIGHASH (see art.c)
extern int DHITS[];
int DHITS[490];
*/
int TABLE[105][256];
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
TABLE[97][0] = 1;
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
TABLE[98][281] = 1;
TABLE[98][41] = 1;
TABLE[98][40] = 1;
TABLE[98][270] = 1;
TABLE[98][277] = 1;
TABLE[98][261] = 1;
TABLE[98][257] = 1;
TABLE[98][259] = 1;
TABLE[98][258] = 1;
TABLE[98][265] = 1;
TABLE[98][266] = 1;
TABLE[98][267] = 1;
TABLE[98][268] = 1;
TABLE[98][269] = 1;
TABLE[98][278] = 1;
TABLE[98][279] = 1;
TABLE[98][280] = 1;
TABLE[98][271] = 1;
TABLE[98][256] = 1;
TABLE[98][0] = 1;
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
TABLE[52][40] = 1;
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
TABLE[52][41] = 1;
TABLE[52][258] = 1;
TABLE[52][259] = 1;
TABLE[52][261] = 1;
TABLE[52][277] = 1;
TABLE[52][256] = 1;
TABLE[53][41] = 1;
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
TABLE[9][40] = 1;
TABLE[9][41] = 1;
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
TABLE[10][40] = 1;
TABLE[10][41] = 1;
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
TABLE[56][40] = 1;
TABLE[57][257] = 1;
TABLE[58][0] = 1;
TABLE[58][281] = 1;
TABLE[58][40] = 1;
TABLE[58][41] = 1;
TABLE[58][270] = 1;
TABLE[58][271] = 1;
TABLE[58][280] = 1;
TABLE[58][279] = 1;
TABLE[58][278] = 1;
TABLE[58][269] = 1;
TABLE[58][268] = 1;
TABLE[58][267] = 1;
TABLE[58][266] = 1;
TABLE[58][265] = 1;
TABLE[58][258] = 1;
TABLE[58][259] = 1;
TABLE[58][257] = 1;
TABLE[58][261] = 1;
TABLE[58][277] = 1;
TABLE[58][256] = 1;
TABLE[59][40] = 1;
TABLE[60][257] = 1;
TABLE[61][281] = 1;
TABLE[61][40] = 1;
TABLE[61][41] = 1;
TABLE[61][270] = 1;
TABLE[61][271] = 1;
TABLE[61][280] = 1;
TABLE[61][279] = 1;
TABLE[61][278] = 1;
TABLE[61][269] = 1;
TABLE[61][268] = 1;
TABLE[61][267] = 1;
TABLE[61][266] = 1;
TABLE[61][265] = 1;
TABLE[61][258] = 1;
TABLE[61][259] = 1;
TABLE[61][257] = 1;
TABLE[61][261] = 1;
TABLE[61][277] = 1;
TABLE[61][256] = 1;
TABLE[62][40] = 1;
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
TABLE[22][259] = 1;
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
TABLE[23][257] = 1;
TABLE[24][257] = 1;
TABLE[25][261] = 1;
TABLE[26][261] = 1;
TABLE[27][261] = 1;
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
TABLE[71][257] = 1;
TABLE[72][281] = 1;
TABLE[72][40] = 1;
TABLE[72][41] = 1;
TABLE[72][270] = 1;
TABLE[72][271] = 1;
TABLE[72][280] = 1;
TABLE[72][279] = 1;
TABLE[72][278] = 1;
TABLE[72][269] = 1;
TABLE[72][268] = 1;
TABLE[72][267] = 1;
TABLE[72][266] = 1;
TABLE[72][265] = 1;
TABLE[72][258] = 1;
TABLE[72][259] = 1;
TABLE[72][257] = 1;
TABLE[72][261] = 1;
TABLE[72][277] = 1;
TABLE[72][256] = 1;
TABLE[28][277] = 1;
TABLE[28][257] = 1;
TABLE[28][256] = 1;
TABLE[73][256] = 1;
TABLE[73][257] = 1;
TABLE[100][277] = 1;
TABLE[74][257] = 1;
TABLE[75][281] = 1;
TABLE[75][40] = 1;
TABLE[75][41] = 1;
TABLE[75][270] = 1;
TABLE[75][271] = 1;
TABLE[75][280] = 1;
TABLE[75][279] = 1;
TABLE[75][278] = 1;
TABLE[75][269] = 1;
TABLE[75][268] = 1;
TABLE[75][267] = 1;
TABLE[75][266] = 1;
TABLE[75][265] = 1;
TABLE[75][258] = 1;
TABLE[75][259] = 1;
TABLE[75][257] = 1;
TABLE[75][261] = 1;
TABLE[75][277] = 1;
TABLE[75][256] = 1;
TABLE[29][40] = 1;
TABLE[29][256] = 1;
TABLE[29][257] = 1;
TABLE[30][40] = 1;
TABLE[30][256] = 1;
TABLE[30][257] = 1;
TABLE[31][40] = 1;
TABLE[76][262] = 1;
TABLE[76][263] = 1;
TABLE[101][281] = 1;
TABLE[101][41] = 1;
TABLE[101][40] = 1;
TABLE[101][270] = 1;
TABLE[101][277] = 1;
TABLE[101][261] = 1;
TABLE[101][257] = 1;
TABLE[101][259] = 1;
TABLE[101][258] = 1;
TABLE[101][265] = 1;
TABLE[101][266] = 1;
TABLE[101][267] = 1;
TABLE[101][268] = 1;
TABLE[101][269] = 1;
TABLE[101][278] = 1;
TABLE[101][279] = 1;
TABLE[101][280] = 1;
TABLE[101][271] = 1;
TABLE[101][256] = 1;
TABLE[101][0] = 1;
TABLE[32][40] = 1;
TABLE[33][257] = 1;
TABLE[33][256] = 1;
TABLE[77][257] = 1;
TABLE[78][256] = 1;
TABLE[79][257] = 1;
TABLE[80][256] = 1;
TABLE[81][257] = 1;
TABLE[82][256] = 1;
TABLE[83][257] = 1;
TABLE[84][256] = 1;
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
TABLE[85][257] = 1;
TABLE[86][256] = 1;
TABLE[89][43] = 1;
TABLE[89][45] = 1;
TABLE[89][42] = 1;
TABLE[89][47] = 1;
TABLE[102][44] = 1;
TABLE[102][40] = 1;
TABLE[102][41] = 1;
TABLE[102][277] = 1;
TABLE[87][257] = 1;
TABLE[88][256] = 1;
TABLE[90][44] = 1;
TABLE[103][40] = 1;
TABLE[103][41] = 1;
TABLE[103][277] = 1;
TABLE[47][272] = 1;
TABLE[47][273] = 1;
TABLE[47][274] = 1;
TABLE[47][275] = 1;
TABLE[47][276] = 1;
TABLE[91][272] = 1;
TABLE[92][273] = 1;
TABLE[93][274] = 1;
TABLE[94][275] = 1;
TABLE[95][276] = 1;
TABLE[96][44] = 1;
TABLE[104][40] = 1;
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
      case 96: return 1; break;
      case 110: return 1; break;
      case 124: return 0; break;
      case 168: return 0; break;
      case 176: return 1; break;
      case 184: return 0; break;
      case 192: return 1; break;
      case 200: return 0; break;
      case 215: return 0; break;
      case 244: return 1; break;
      case 252: return 1; break;
      case 260: return 1; break;
      case 268: return 1; break;
      case 277: return 1; break;
      case 284: return 1; break;
      case 292: return 0; break;
      case 311: return 1; break;
      case 319: return 0; break;
      case 333: return 0; break;
      case 341: return 0; break;
      case 349: return 0; break;
      case 357: return 0; break;
      case 365: return 0; break;
      case 392: return 0; break;
      case 408: return 0; break;
      case 416: return 0; break;
      case 422: return 0; break;
      case 430: return 1; break;
      case 439: return 0; break;
      case 447: return 1; break;
      case 455: return 0; break;
      case 461: return 0; break;
      case 481: return 1; break;
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
         case 96: return "Subphrase"; break;
         case 110: return "Subphrase"; break;
         case 124: return "tipo_operacao_binaria"; break;
         case 168: return "selecao"; break;
         case 176: return "Subphrase"; break;
         case 184: return "projecao"; break;
         case 192: return "Subphrase"; break;
         case 200: return "renomeacao1"; break;
         case 215: return "renomeacao2"; break;
         case 244: return "Subphrase"; break;
         case 252: return "Subphrase"; break;
         case 260: return "Subphrase"; break;
         case 268: return "agrupamento"; break;
         case 277: return "Subphrase"; break;
         case 284: return "Subphrase"; break;
         case 292: return "predicado"; break;
         case 311: return "Subphrase"; break;
         case 319: return "condicao"; break;
         case 333: return "Subphrase"; break;
         case 341: return "Subphrase"; break;
         case 349: return "Subphrase"; break;
         case 357: return "Subphrase"; break;
         case 365: return "operador_comparacao"; break;
         case 392: return "operador_aritmetico"; break;
         case 408: return "operador_booleano"; break;
         case 416: return "lista_atributos"; break;
         case 422: return "Subphrase"; break;
         case 430: return "Subphrase"; break;
         case 439: return "Subphrase"; break;
         case 447: return "Subphrase"; break;
         case 455: return "lista_funcoes_agregadas"; break;
         case 461: return "Subphrase"; break;
         case 481: return "Subphrase"; break;
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
