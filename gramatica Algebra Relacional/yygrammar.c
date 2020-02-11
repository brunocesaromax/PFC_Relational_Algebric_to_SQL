#line 1 "spec.acc"

#include "yystype.h"
#include "Node.c"
#include "Tree.c"


# line 9 "yygrammar.c"
#include "yygrammar.h"

YYSTART ()
{
   switch(yyselect()) {
   case 50: {
      init();
      get_lexval();
      } break;
   }
}

init ()
{
   switch(yyselect()) {
   case 1: {
#line 10 "spec.acc"
_tool_initialize();
# line 28 "yygrammar.c"
      consulta();
      } break;
   }
}

consulta ()
{
   switch(yyselect()) {
   case 2: {
      switch (yyselect()) {
      case 51: {
         operacao_consulta();
#line 14 "spec.acc"
_build_tree();
# line 43 "yygrammar.c"
         } break;
      case 52: {
         get_lexval();
         } break;
      default: printf("???\n"); exit(1);
      }
      consulta();
      } break;
   case 3: {
      switch (yyselect()) {
      case 53: {
         operacao_consulta();
#line 16 "spec.acc"
_build_tree();
# line 58 "yygrammar.c"
         } break;
      case 54: {
         get_lexval();
         } break;
      default: printf("???\n"); exit(1);
      }
      } break;
   }
}

operacao_consulta ()
{
   switch(yyselect()) {
   case 4: {
      get_lexval();
#line 20 "spec.acc"
_add_node_stack("(");
# line 76 "yygrammar.c"
      operacao_consulta();
      get_lexval();
#line 22 "spec.acc"
_add_node_stack(")");
# line 81 "yygrammar.c"
      } break;
   case 5: {
      switch (yyselect()) {
      case 55: {
         operacao_unaria();
         } break;
      case 56: {
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
   case 6: {
      selecao();
      } break;
   case 7: {
      projecao();
      } break;
   case 8: {
      renomeacao1();
      } break;
   case 9: {
      renomeacao2();
      } break;
   case 10: {
      agrupamento();
      } break;
   }
}

operacao_binaria ()
{
   YYSTYPE y;
   switch(yyselect()) {
   case 11: {
      switch (yyselect()) {
      case 57: {
         get_lexval();
         y = yylval;
#line 46 "spec.acc"
_add_node_stack(y.stringval);
# line 129 "yygrammar.c"
         } break;
      case 58: {
         operacao_consulta();
         } break;
      case 59: {
         get_lexval();
#line 50 "spec.acc"
_add_node_stack("(");
# line 138 "yygrammar.c"
         get_lexval();
         y = yylval;
#line 51 "spec.acc"
_add_node_stack(y.stringval);
# line 143 "yygrammar.c"
         get_lexval();
#line 52 "spec.acc"
_add_node_stack(")");
# line 147 "yygrammar.c"
         } break;
      default: printf("???\n"); exit(1);
      }
      tipo_operacao_binaria();
      switch (yyselect()) {
      case 60: {
         get_lexval();
         y = yylval;
#line 56 "spec.acc"
_add_node_stack(y.stringval);
# line 158 "yygrammar.c"
         } break;
      case 61: {
         operacao_consulta();
         } break;
      case 62: {
         get_lexval();
#line 60 "spec.acc"
_add_node_stack("(");
# line 167 "yygrammar.c"
         get_lexval();
         y = yylval;
#line 61 "spec.acc"
_add_node_stack(y.stringval);
# line 172 "yygrammar.c"
         get_lexval();
#line 62 "spec.acc"
_add_node_stack(")");
# line 176 "yygrammar.c"
         } break;
      default: printf("???\n"); exit(1);
      }
      } break;
   case 12: {
      switch (yyselect()) {
      case 63: {
         get_lexval();
         y = yylval;
#line 66 "spec.acc"
_add_node_stack(y.stringval);
# line 188 "yygrammar.c"
         } break;
      case 64: {
         operacao_consulta();
         } break;
      case 65: {
         get_lexval();
#line 70 "spec.acc"
_add_node_stack("(");
# line 197 "yygrammar.c"
         get_lexval();
         y = yylval;
#line 71 "spec.acc"
_add_node_stack(y.stringval);
# line 202 "yygrammar.c"
         get_lexval();
#line 72 "spec.acc"
_add_node_stack(")");
# line 206 "yygrammar.c"
         } break;
      default: printf("???\n"); exit(1);
      }
      get_lexval();
#line 74 "spec.acc"
_add_node_stack("NATURAL_JOIN");
# line 213 "yygrammar.c"
      renomeacao2();
      } break;
   }
}

tipo_operacao_binaria ()
{
   switch(yyselect()) {
   case 13: {
      get_lexval();
#line 80 "spec.acc"
_add_node_stack("UNION");
# line 226 "yygrammar.c"
      } break;
   case 14: {
      get_lexval();
#line 82 "spec.acc"
_add_node_stack("INTERSECTION");
# line 232 "yygrammar.c"
      } break;
   case 15: {
      get_lexval();
#line 84 "spec.acc"
_add_node_stack("SUBTRACTION");
# line 238 "yygrammar.c"
      } break;
   case 16: {
      get_lexval();
#line 86 "spec.acc"
_add_node_stack("PRODUCT_CARTESIAN");
# line 244 "yygrammar.c"
      } break;
   case 17: {
      get_lexval();
      predicado();
#line 89 "spec.acc"
_add_node_stack("JOIN");
# line 251 "yygrammar.c"
      } break;
   case 18: {
      get_lexval();
#line 91 "spec.acc"
_add_node_stack("NATURAL_JOIN");
# line 257 "yygrammar.c"
      } break;
   case 19: {
      get_lexval();
      predicado();
#line 94 "spec.acc"
_add_node_stack("LEFT_OUTER_JOIN");
# line 264 "yygrammar.c"
      } break;
   case 20: {
      get_lexval();
      predicado();
#line 97 "spec.acc"
_add_node_stack("RIGHT_OUTER_JOIN");
# line 271 "yygrammar.c"
      } break;
   case 21: {
      get_lexval();
      predicado();
#line 100 "spec.acc"
_add_node_stack("COMPLETE_OUTER_JOIN");
# line 278 "yygrammar.c"
      } break;
   case 22: {
      get_lexval();
#line 102 "spec.acc"
_add_node_stack("DIVISION");
# line 284 "yygrammar.c"
      } break;
   }
}

selecao ()
{
   YYSTYPE y;
   switch(yyselect()) {
   case 23: {
      get_lexval();
      predicado();
#line 107 "spec.acc"
_add_node_stack("SIGMA");
# line 298 "yygrammar.c"
      get_lexval();
#line 108 "spec.acc"
_add_node_stack("(");
# line 302 "yygrammar.c"
      switch (yyselect()) {
      case 66: {
         get_lexval();
         y = yylval;
#line 110 "spec.acc"
_add_node_stack(y.stringval);
# line 309 "yygrammar.c"
         } break;
      case 67: {
         operacao_consulta();
         } break;
      default: printf("???\n"); exit(1);
      }
      get_lexval();
#line 114 "spec.acc"
_add_node_stack(")");
# line 319 "yygrammar.c"
      } break;
   }
}

projecao ()
{
   YYSTYPE y;
   switch(yyselect()) {
   case 24: {
      get_lexval();
      lista_atributos();
#line 119 "spec.acc"
_add_node_stack("PI");
# line 333 "yygrammar.c"
      get_lexval();
#line 120 "spec.acc"
_add_node_stack("(");
# line 337 "yygrammar.c"
      switch (yyselect()) {
      case 68: {
         get_lexval();
         y = yylval;
#line 122 "spec.acc"
_add_node_stack(y.stringval);
# line 344 "yygrammar.c"
         } break;
      case 69: {
         operacao_consulta();
         } break;
      default: printf("???\n"); exit(1);
      }
      get_lexval();
#line 126 "spec.acc"
_add_node_stack(")");
# line 354 "yygrammar.c"
      } break;
   }
}

renomeacao1 ()
{
   YYSTYPE y;
   switch(yyselect()) {
   case 25: {
      get_lexval();
      y = yylval;
#line 130 "spec.acc"
_add_node_stack(y.stringval);
# line 368 "yygrammar.c"
      get_lexval();
#line 131 "spec.acc"
_add_node_stack("ASSIGNMENT");
# line 372 "yygrammar.c"
      operacao_consulta();
      } break;
   case 26: {
      get_lexval();
      y = yylval;
      get_lexval();
      lista_atributos();
#line 136 "spec.acc"
_add_node_stack(y.stringval);
# line 382 "yygrammar.c"
      get_lexval();
      get_lexval();
#line 137 "spec.acc"
_add_node_stack("ASSIGNMENT");
# line 387 "yygrammar.c"
      operacao_consulta();
      } break;
   }
}

renomeacao2 ()
{
   YYSTYPE y;
   switch(yyselect()) {
   case 27: {
      get_lexval();
#line 142 "spec.acc"
 _add_node_stack("RHO");
# line 401 "yygrammar.c"
      get_lexval();
      y = yylval;
#line 143 "spec.acc"
 _add_node_stack(y.stringval);
# line 406 "yygrammar.c"
      get_lexval();
#line 144 "spec.acc"
 _add_node_stack("(");
# line 410 "yygrammar.c"
      switch (yyselect()) {
      case 70: {
         get_lexval();
         y = yylval;
#line 146 "spec.acc"
_add_node_stack(y.stringval);
# line 417 "yygrammar.c"
         } break;
      case 71: {
         operacao_consulta();
         } break;
      default: printf("???\n"); exit(1);
      }
      get_lexval();
#line 150 "spec.acc"
_add_node_stack(")");
# line 427 "yygrammar.c"
      } break;
   case 28: {
      get_lexval();
#line 152 "spec.acc"
 _add_node_stack("RHO");
# line 433 "yygrammar.c"
      get_lexval();
      y = yylval;
#line 153 "spec.acc"
_add_node_stack(y.stringval);
# line 438 "yygrammar.c"
      get_lexval();
#line 154 "spec.acc"
_add_symbols_attribute("(",1);
# line 442 "yygrammar.c"
      lista_atributos();
      get_lexval();
#line 156 "spec.acc"
_add_symbols_attribute(")",1);
# line 447 "yygrammar.c"
      get_lexval();
#line 157 "spec.acc"
_add_node_stack("(");
# line 451 "yygrammar.c"
      switch (yyselect()) {
      case 72: {
         get_lexval();
         y = yylval;
#line 159 "spec.acc"
_add_node_stack(y.stringval);
# line 458 "yygrammar.c"
         } break;
      case 73: {
         operacao_consulta();
         } break;
      default: printf("???\n"); exit(1);
      }
      get_lexval();
#line 163 "spec.acc"
_add_node_stack(")");
# line 468 "yygrammar.c"
      } break;
   case 29: {
      get_lexval();
#line 165 "spec.acc"
 _add_node_stack("RHO");
# line 474 "yygrammar.c"
      get_lexval();
#line 166 "spec.acc"
_add_symbols_attribute("(",1);
# line 478 "yygrammar.c"
      lista_atributos();
      get_lexval();
#line 168 "spec.acc"
_add_symbols_attribute(")",1);
# line 483 "yygrammar.c"
      get_lexval();
#line 169 "spec.acc"
_add_node_stack("(");
# line 487 "yygrammar.c"
      switch (yyselect()) {
      case 74: {
         get_lexval();
         y = yylval;
#line 171 "spec.acc"
_add_node_stack(y.stringval);
# line 494 "yygrammar.c"
         } break;
      case 75: {
         operacao_consulta();
         } break;
      default: printf("???\n"); exit(1);
      }
      get_lexval();
#line 175 "spec.acc"
_add_node_stack(")");
# line 504 "yygrammar.c"
      } break;
   }
}

agrupamento ()
{
   YYSTYPE y;
   switch(yyselect()) {
   case 30: {
      switch (yyselect()) {
      case 76: {
         lista_atributos();
         } break;
      default: ;
      }
      get_lexval();
      lista_funcoes_agregadas();
#line 181 "spec.acc"
 _add_node_stack("FSCRIPT");
# line 524 "yygrammar.c"
      get_lexval();
      switch (yyselect()) {
      case 77: {
         get_lexval();
         y = yylval;
#line 184 "spec.acc"
_add_node_stack(y.stringval);
# line 532 "yygrammar.c"
         } break;
      case 78: {
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
   case 31: {
      condicao();
      } break;
   case 32: {
      condicao();
      operador_booleano();
      predicado();
      } break;
   case 33: {
      get_lexval();
#line 198 "spec.acc"
_add_symbols_predicate("(");
# line 559 "yygrammar.c"
      predicado();
      get_lexval();
#line 200 "spec.acc"
_add_symbols_predicate(")");
# line 564 "yygrammar.c"
      switch (yyselect()) {
      case 79: {
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
   case 34: {
      get_lexval();
#line 205 "spec.acc"
_add_symbols_predicate("(");
# line 584 "yygrammar.c"
      condicao();
      get_lexval();
#line 207 "spec.acc"
_add_symbols_predicate(")");
# line 589 "yygrammar.c"
      } break;
   case 35: {
      switch (yyselect()) {
      case 80: {
         get_lexval();
         a = yylval;
#line 210 "spec.acc"
_add_symbols_predicate(a.stringval);
# line 598 "yygrammar.c"
         } break;
      case 81: {
         get_lexval();
         a = yylval;
#line 212 "spec.acc"
_add_symbols_predicate(a.stringval);
# line 605 "yygrammar.c"
         } break;
      default: printf("???\n"); exit(1);
      }
      operador_comparacao();
      switch (yyselect()) {
      case 82: {
         get_lexval();
         a = yylval;
#line 216 "spec.acc"
_add_symbols_predicate(a.stringval);
# line 616 "yygrammar.c"
         } break;
      case 83: {
         get_lexval();
         a = yylval;
#line 218 "spec.acc"
_add_symbols_predicate(a.stringval);
# line 623 "yygrammar.c"
         } break;
      default: printf("???\n"); exit(1);
      }
      } break;
   }
}

operador_comparacao ()
{
   switch(yyselect()) {
   case 36: {
      get_lexval();
#line 223 "spec.acc"
_add_symbols_predicate("=");
# line 638 "yygrammar.c"
      } break;
   case 37: {
      get_lexval();
#line 225 "spec.acc"
_add_symbols_predicate("<");
# line 644 "yygrammar.c"
      } break;
   case 38: {
      get_lexval();
#line 227 "spec.acc"
_add_symbols_predicate(">");
# line 650 "yygrammar.c"
      } break;
   case 39: {
      get_lexval();
      get_lexval();
#line 229 "spec.acc"
_add_symbols_predicate("<=");
# line 657 "yygrammar.c"
      } break;
   case 40: {
      get_lexval();
      get_lexval();
#line 231 "spec.acc"
_add_symbols_predicate(">=");
# line 664 "yygrammar.c"
      } break;
   case 41: {
      get_lexval();
      get_lexval();
#line 233 "spec.acc"
_add_symbols_predicate("!=");
# line 671 "yygrammar.c"
      } break;
   }
}

operador_aritmetico ()
{
   switch(yyselect()) {
   case 42: {
      get_lexval();
#line 237 "spec.acc"
_add_symbols_attribute("+",1);
# line 683 "yygrammar.c"
      } break;
   case 43: {
      get_lexval();
#line 239 "spec.acc"
_add_symbols_attribute("-",1);
# line 689 "yygrammar.c"
      } break;
   case 44: {
      get_lexval();
#line 241 "spec.acc"
_add_symbols_attribute("*",1);
# line 695 "yygrammar.c"
      } break;
   case 45: {
      get_lexval();
#line 243 "spec.acc"
_add_symbols_attribute("/",1);
# line 701 "yygrammar.c"
      } break;
   }
}

operador_booleano ()
{
   switch(yyselect()) {
   case 46: {
      get_lexval();
#line 247 "spec.acc"
_add_symbols_predicate(" AND ");
# line 713 "yygrammar.c"
      } break;
   case 47: {
      get_lexval();
#line 249 "spec.acc"
_add_symbols_predicate(" OR ");
# line 719 "yygrammar.c"
      } break;
   }
}

lista_atributos ()
{
   YYSTYPE a;
   switch(yyselect()) {
   case 48: {
      switch (yyselect()) {
      case 84: {
         get_lexval();
         a = yylval;
#line 254 "spec.acc"
_add_symbols_attribute(a.stringval,1);
# line 735 "yygrammar.c"
         } break;
      case 85: {
         get_lexval();
         a = yylval;
#line 256 "spec.acc"
_add_symbols_attribute(a.stringval,1);
# line 742 "yygrammar.c"
         } break;
      default: printf("???\n"); exit(1);
      }
      while (1) {
         switch (yyselect()) {
         case 88: {
            operador_aritmetico();
            switch (yyselect()) {
            case 86: {
               get_lexval();
               a = yylval;
#line 261 "spec.acc"
_add_symbols_attribute(a.stringval,1);
# line 756 "yygrammar.c"
               } break;
            case 87: {
               get_lexval();
               a = yylval;
#line 263 "spec.acc"
_add_symbols_attribute(a.stringval,1);
# line 763 "yygrammar.c"
               } break;
            default: printf("???\n"); exit(1);
            }
            } break;
         default: goto yy1;
         }
      }
      yy1: ;
      switch (yyselect()) {
      case 89: {
         get_lexval();
#line 266 "spec.acc"
_add_symbols_attribute(",",1);
# line 777 "yygrammar.c"
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
   case 49: {
      switch (yyselect()) {
      case 90: {
         get_lexval();
#line 271 "spec.acc"
_add_symbols_attribute("COUNT ",2);
# line 796 "yygrammar.c"
         } break;
      case 91: {
         get_lexval();
#line 273 "spec.acc"
_add_symbols_attribute("AVERAGE ",2);
# line 802 "yygrammar.c"
         } break;
      case 92: {
         get_lexval();
#line 275 "spec.acc"
_add_symbols_attribute("MAX ",2);
# line 808 "yygrammar.c"
         } break;
      case 93: {
         get_lexval();
#line 277 "spec.acc"
_add_symbols_attribute("MIN ",2);
# line 814 "yygrammar.c"
         } break;
      case 94: {
         get_lexval();
#line 279 "spec.acc"
_add_symbols_attribute("SUM ",2);
# line 820 "yygrammar.c"
         } break;
      default: printf("???\n"); exit(1);
      }
      get_lexval();
      y = yylval;
#line 281 "spec.acc"
_add_symbols_attribute(y.stringval,2);
# line 828 "yygrammar.c"
      switch (yyselect()) {
      case 95: {
         get_lexval();
#line 282 "spec.acc"
_add_symbols_attribute(",",2);
# line 834 "yygrammar.c"
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
int c_length = 471;
extern int yygrammar[];
int yygrammar[] = {
0,
/* 1 */ 0,
/* 2 */ 6,
/* 3 */ 50000,
/* 4 */ -1,
/* 5 */ 50,
/* 6 */ 0,
/* 7 */ 10,
/* 8 */ -6,
/* 9 */ 1,
/* 10 */ 15,
/* 11 */ 19,
/* 12 */ 10,
/* 13 */ -10,
/* 14 */ 2,
/* 15 */ 0,
/* 16 */ 27,
/* 17 */ -10,
/* 18 */ 3,
/* 19 */ 23,
/* 20 */ 35,
/* 21 */ -19,
/* 22 */ 51,
/* 23 */ 0,
/* 24 */ 50281,
/* 25 */ -19,
/* 26 */ 52,
/* 27 */ 31,
/* 28 */ 35,
/* 29 */ -27,
/* 30 */ 53,
/* 31 */ 0,
/* 32 */ 50281,
/* 33 */ -27,
/* 34 */ 54,
/* 35 */ 41,
/* 36 */ 50040,
/* 37 */ 35,
/* 38 */ 50041,
/* 39 */ -35,
/* 40 */ 4,
/* 41 */ 0,
/* 42 */ 45,
/* 43 */ -35,
/* 44 */ 5,
/* 45 */ 49,
/* 46 */ 53,
/* 47 */ -45,
/* 48 */ 55,
/* 49 */ 0,
/* 50 */ 73,
/* 51 */ -45,
/* 52 */ 56,
/* 53 */ 57,
/* 54 */ 171,
/* 55 */ -53,
/* 56 */ 6,
/* 57 */ 61,
/* 58 */ 187,
/* 59 */ -53,
/* 60 */ 7,
/* 61 */ 65,
/* 62 */ 203,
/* 63 */ -53,
/* 64 */ 8,
/* 65 */ 69,
/* 66 */ 218,
/* 67 */ -53,
/* 68 */ 9,
/* 69 */ 0,
/* 70 */ 271,
/* 71 */ -53,
/* 72 */ 10,
/* 73 */ 79,
/* 74 */ 85,
/* 75 */ 127,
/* 76 */ 99,
/* 77 */ -73,
/* 78 */ 11,
/* 79 */ 0,
/* 80 */ 113,
/* 81 */ 50270,
/* 82 */ 218,
/* 83 */ -73,
/* 84 */ 12,
/* 85 */ 89,
/* 86 */ 50257,
/* 87 */ -85,
/* 88 */ 57,
/* 89 */ 93,
/* 90 */ 35,
/* 91 */ -85,
/* 92 */ 58,
/* 93 */ 0,
/* 94 */ 50040,
/* 95 */ 50257,
/* 96 */ 50041,
/* 97 */ -85,
/* 98 */ 59,
/* 99 */ 103,
/* 100 */ 50257,
/* 101 */ -99,
/* 102 */ 60,
/* 103 */ 107,
/* 104 */ 35,
/* 105 */ -99,
/* 106 */ 61,
/* 107 */ 0,
/* 108 */ 50040,
/* 109 */ 50257,
/* 110 */ 50041,
/* 111 */ -99,
/* 112 */ 62,
/* 113 */ 117,
/* 114 */ 50257,
/* 115 */ -113,
/* 116 */ 63,
/* 117 */ 121,
/* 118 */ 35,
/* 119 */ -113,
/* 120 */ 64,
/* 121 */ 0,
/* 122 */ 50040,
/* 123 */ 50257,
/* 124 */ 50041,
/* 125 */ -113,
/* 126 */ 65,
/* 127 */ 131,
/* 128 */ 50265,
/* 129 */ -127,
/* 130 */ 13,
/* 131 */ 135,
/* 132 */ 50266,
/* 133 */ -127,
/* 134 */ 14,
/* 135 */ 139,
/* 136 */ 50267,
/* 137 */ -127,
/* 138 */ 15,
/* 139 */ 143,
/* 140 */ 50268,
/* 141 */ -127,
/* 142 */ 16,
/* 143 */ 148,
/* 144 */ 50269,
/* 145 */ 295,
/* 146 */ -127,
/* 147 */ 17,
/* 148 */ 152,
/* 149 */ 50270,
/* 150 */ -127,
/* 151 */ 18,
/* 152 */ 157,
/* 153 */ 50278,
/* 154 */ 295,
/* 155 */ -127,
/* 156 */ 19,
/* 157 */ 162,
/* 158 */ 50279,
/* 159 */ 295,
/* 160 */ -127,
/* 161 */ 20,
/* 162 */ 167,
/* 163 */ 50280,
/* 164 */ 295,
/* 165 */ -127,
/* 166 */ 21,
/* 167 */ 0,
/* 168 */ 50271,
/* 169 */ -127,
/* 170 */ 22,
/* 171 */ 0,
/* 172 */ 50258,
/* 173 */ 295,
/* 174 */ 50040,
/* 175 */ 179,
/* 176 */ 50041,
/* 177 */ -171,
/* 178 */ 23,
/* 179 */ 183,
/* 180 */ 50257,
/* 181 */ -179,
/* 182 */ 66,
/* 183 */ 0,
/* 184 */ 35,
/* 185 */ -179,
/* 186 */ 67,
/* 187 */ 0,
/* 188 */ 50259,
/* 189 */ 399,
/* 190 */ 50040,
/* 191 */ 195,
/* 192 */ 50041,
/* 193 */ -187,
/* 194 */ 24,
/* 195 */ 199,
/* 196 */ 50257,
/* 197 */ -195,
/* 198 */ 68,
/* 199 */ 0,
/* 200 */ 35,
/* 201 */ -195,
/* 202 */ 69,
/* 203 */ 209,
/* 204 */ 50257,
/* 205 */ 50260,
/* 206 */ 35,
/* 207 */ -203,
/* 208 */ 25,
/* 209 */ 0,
/* 210 */ 50257,
/* 211 */ 50040,
/* 212 */ 399,
/* 213 */ 50041,
/* 214 */ 50260,
/* 215 */ 35,
/* 216 */ -203,
/* 217 */ 26,
/* 218 */ 226,
/* 219 */ 50261,
/* 220 */ 50257,
/* 221 */ 50040,
/* 222 */ 247,
/* 223 */ 50041,
/* 224 */ -218,
/* 225 */ 27,
/* 226 */ 237,
/* 227 */ 50261,
/* 228 */ 50257,
/* 229 */ 50040,
/* 230 */ 399,
/* 231 */ 50041,
/* 232 */ 50040,
/* 233 */ 255,
/* 234 */ 50041,
/* 235 */ -218,
/* 236 */ 28,
/* 237 */ 0,
/* 238 */ 50261,
/* 239 */ 50040,
/* 240 */ 399,
/* 241 */ 50041,
/* 242 */ 50040,
/* 243 */ 263,
/* 244 */ 50041,
/* 245 */ -218,
/* 246 */ 29,
/* 247 */ 251,
/* 248 */ 50257,
/* 249 */ -247,
/* 250 */ 70,
/* 251 */ 0,
/* 252 */ 35,
/* 253 */ -247,
/* 254 */ 71,
/* 255 */ 259,
/* 256 */ 50257,
/* 257 */ -255,
/* 258 */ 72,
/* 259 */ 0,
/* 260 */ 35,
/* 261 */ -255,
/* 262 */ 73,
/* 263 */ 267,
/* 264 */ 50257,
/* 265 */ -263,
/* 266 */ 74,
/* 267 */ 0,
/* 268 */ 35,
/* 269 */ -263,
/* 270 */ 75,
/* 271 */ 0,
/* 272 */ 280,
/* 273 */ 50277,
/* 274 */ 438,
/* 275 */ 50040,
/* 276 */ 287,
/* 277 */ 50041,
/* 278 */ -271,
/* 279 */ 30,
/* 280 */ 284,
/* 281 */ 399,
/* 282 */ -280,
/* 283 */ 76,
/* 284 */ 0,
/* 285 */ -280,
/* 286 */ 96,
/* 287 */ 291,
/* 288 */ 50257,
/* 289 */ -287,
/* 290 */ 77,
/* 291 */ 0,
/* 292 */ 35,
/* 293 */ -287,
/* 294 */ 78,
/* 295 */ 299,
/* 296 */ 320,
/* 297 */ -295,
/* 298 */ 31,
/* 299 */ 305,
/* 300 */ 320,
/* 301 */ 391,
/* 302 */ 295,
/* 303 */ -295,
/* 304 */ 32,
/* 305 */ 0,
/* 306 */ 50040,
/* 307 */ 295,
/* 308 */ 50041,
/* 309 */ 312,
/* 310 */ -295,
/* 311 */ 33,
/* 312 */ 317,
/* 313 */ 391,
/* 314 */ 295,
/* 315 */ -312,
/* 316 */ 79,
/* 317 */ 0,
/* 318 */ -312,
/* 319 */ 97,
/* 320 */ 326,
/* 321 */ 50040,
/* 322 */ 320,
/* 323 */ 50041,
/* 324 */ -320,
/* 325 */ 34,
/* 326 */ 0,
/* 327 */ 332,
/* 328 */ 348,
/* 329 */ 340,
/* 330 */ -320,
/* 331 */ 35,
/* 332 */ 336,
/* 333 */ 50257,
/* 334 */ -332,
/* 335 */ 80,
/* 336 */ 0,
/* 337 */ 50256,
/* 338 */ -332,
/* 339 */ 81,
/* 340 */ 344,
/* 341 */ 50257,
/* 342 */ -340,
/* 343 */ 82,
/* 344 */ 0,
/* 345 */ 50256,
/* 346 */ -340,
/* 347 */ 83,
/* 348 */ 352,
/* 349 */ 50061,
/* 350 */ -348,
/* 351 */ 36,
/* 352 */ 356,
/* 353 */ 50060,
/* 354 */ -348,
/* 355 */ 37,
/* 356 */ 360,
/* 357 */ 50062,
/* 358 */ -348,
/* 359 */ 38,
/* 360 */ 365,
/* 361 */ 50060,
/* 362 */ 50061,
/* 363 */ -348,
/* 364 */ 39,
/* 365 */ 370,
/* 366 */ 50062,
/* 367 */ 50061,
/* 368 */ -348,
/* 369 */ 40,
/* 370 */ 0,
/* 371 */ 50033,
/* 372 */ 50061,
/* 373 */ -348,
/* 374 */ 41,
/* 375 */ 379,
/* 376 */ 50043,
/* 377 */ -375,
/* 378 */ 42,
/* 379 */ 383,
/* 380 */ 50045,
/* 381 */ -375,
/* 382 */ 43,
/* 383 */ 387,
/* 384 */ 50042,
/* 385 */ -375,
/* 386 */ 44,
/* 387 */ 0,
/* 388 */ 50047,
/* 389 */ -375,
/* 390 */ 45,
/* 391 */ 395,
/* 392 */ 50262,
/* 393 */ -391,
/* 394 */ 46,
/* 395 */ 0,
/* 396 */ 50263,
/* 397 */ -391,
/* 398 */ 47,
/* 399 */ 0,
/* 400 */ 405,
/* 401 */ 413,
/* 402 */ 430,
/* 403 */ -399,
/* 404 */ 48,
/* 405 */ 409,
/* 406 */ 50257,
/* 407 */ -405,
/* 408 */ 84,
/* 409 */ 0,
/* 410 */ 50256,
/* 411 */ -405,
/* 412 */ 85,
/* 413 */ 419,
/* 414 */ 375,
/* 415 */ 422,
/* 416 */ 413,
/* 417 */ -413,
/* 418 */ 88,
/* 419 */ 0,
/* 420 */ -413,
/* 421 */ 98,
/* 422 */ 426,
/* 423 */ 50257,
/* 424 */ -422,
/* 425 */ 86,
/* 426 */ 0,
/* 427 */ 50256,
/* 428 */ -422,
/* 429 */ 87,
/* 430 */ 435,
/* 431 */ 50044,
/* 432 */ 399,
/* 433 */ -430,
/* 434 */ 89,
/* 435 */ 0,
/* 436 */ -430,
/* 437 */ 99,
/* 438 */ 0,
/* 439 */ 444,
/* 440 */ 50257,
/* 441 */ 464,
/* 442 */ -438,
/* 443 */ 49,
/* 444 */ 448,
/* 445 */ 50272,
/* 446 */ -444,
/* 447 */ 90,
/* 448 */ 452,
/* 449 */ 50273,
/* 450 */ -444,
/* 451 */ 91,
/* 452 */ 456,
/* 453 */ 50274,
/* 454 */ -444,
/* 455 */ 92,
/* 456 */ 460,
/* 457 */ 50275,
/* 458 */ -444,
/* 459 */ 93,
/* 460 */ 0,
/* 461 */ 50276,
/* 462 */ -444,
/* 463 */ 94,
/* 464 */ 469,
/* 465 */ 50044,
/* 466 */ 438,
/* 467 */ -464,
/* 468 */ 95,
/* 469 */ 0,
/* 470 */ -464,
/* 471 */ 100,
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
/* 16 */ 1,
/* 17 */ -10,
/* 18 */ 2,
/* 19 */ 23,
/* 20 */ 1,
/* 21 */ -19,
/* 22 */ 1,
/* 23 */ 0,
/* 24 */ 50281,
/* 25 */ -19,
/* 26 */ 2,
/* 27 */ 31,
/* 28 */ 1,
/* 29 */ -27,
/* 30 */ 1,
/* 31 */ 0,
/* 32 */ 50281,
/* 33 */ -27,
/* 34 */ 2,
/* 35 */ 41,
/* 36 */ 50040,
/* 37 */ 1,
/* 38 */ 50041,
/* 39 */ -35,
/* 40 */ 1,
/* 41 */ 0,
/* 42 */ 1,
/* 43 */ -35,
/* 44 */ 2,
/* 45 */ 49,
/* 46 */ 1,
/* 47 */ -45,
/* 48 */ 1,
/* 49 */ 0,
/* 50 */ 1,
/* 51 */ -45,
/* 52 */ 2,
/* 53 */ 57,
/* 54 */ 1,
/* 55 */ -53,
/* 56 */ 1,
/* 57 */ 61,
/* 58 */ 1,
/* 59 */ -53,
/* 60 */ 2,
/* 61 */ 65,
/* 62 */ 1,
/* 63 */ -53,
/* 64 */ 3,
/* 65 */ 69,
/* 66 */ 1,
/* 67 */ -53,
/* 68 */ 4,
/* 69 */ 0,
/* 70 */ 1,
/* 71 */ -53,
/* 72 */ 5,
/* 73 */ 79,
/* 74 */ 1,
/* 75 */ 1,
/* 76 */ 1,
/* 77 */ -73,
/* 78 */ 1,
/* 79 */ 0,
/* 80 */ 1,
/* 81 */ 50270,
/* 82 */ 1,
/* 83 */ -73,
/* 84 */ 2,
/* 85 */ 89,
/* 86 */ 50257,
/* 87 */ -85,
/* 88 */ 1,
/* 89 */ 93,
/* 90 */ 1,
/* 91 */ -85,
/* 92 */ 2,
/* 93 */ 0,
/* 94 */ 50040,
/* 95 */ 50257,
/* 96 */ 50041,
/* 97 */ -85,
/* 98 */ 3,
/* 99 */ 103,
/* 100 */ 50257,
/* 101 */ -99,
/* 102 */ 1,
/* 103 */ 107,
/* 104 */ 1,
/* 105 */ -99,
/* 106 */ 2,
/* 107 */ 0,
/* 108 */ 50040,
/* 109 */ 50257,
/* 110 */ 50041,
/* 111 */ -99,
/* 112 */ 3,
/* 113 */ 117,
/* 114 */ 50257,
/* 115 */ -113,
/* 116 */ 1,
/* 117 */ 121,
/* 118 */ 1,
/* 119 */ -113,
/* 120 */ 2,
/* 121 */ 0,
/* 122 */ 50040,
/* 123 */ 50257,
/* 124 */ 50041,
/* 125 */ -113,
/* 126 */ 3,
/* 127 */ 131,
/* 128 */ 50265,
/* 129 */ -127,
/* 130 */ 1,
/* 131 */ 135,
/* 132 */ 50266,
/* 133 */ -127,
/* 134 */ 2,
/* 135 */ 139,
/* 136 */ 50267,
/* 137 */ -127,
/* 138 */ 3,
/* 139 */ 143,
/* 140 */ 50268,
/* 141 */ -127,
/* 142 */ 4,
/* 143 */ 148,
/* 144 */ 50269,
/* 145 */ 1,
/* 146 */ -127,
/* 147 */ 5,
/* 148 */ 152,
/* 149 */ 50270,
/* 150 */ -127,
/* 151 */ 6,
/* 152 */ 157,
/* 153 */ 50278,
/* 154 */ 1,
/* 155 */ -127,
/* 156 */ 7,
/* 157 */ 162,
/* 158 */ 50279,
/* 159 */ 1,
/* 160 */ -127,
/* 161 */ 8,
/* 162 */ 167,
/* 163 */ 50280,
/* 164 */ 1,
/* 165 */ -127,
/* 166 */ 9,
/* 167 */ 0,
/* 168 */ 50271,
/* 169 */ -127,
/* 170 */ 10,
/* 171 */ 0,
/* 172 */ 50258,
/* 173 */ 1,
/* 174 */ 50040,
/* 175 */ 1,
/* 176 */ 50041,
/* 177 */ -171,
/* 178 */ 1,
/* 179 */ 183,
/* 180 */ 50257,
/* 181 */ -179,
/* 182 */ 1,
/* 183 */ 0,
/* 184 */ 1,
/* 185 */ -179,
/* 186 */ 2,
/* 187 */ 0,
/* 188 */ 50259,
/* 189 */ 1,
/* 190 */ 50040,
/* 191 */ 1,
/* 192 */ 50041,
/* 193 */ -187,
/* 194 */ 1,
/* 195 */ 199,
/* 196 */ 50257,
/* 197 */ -195,
/* 198 */ 1,
/* 199 */ 0,
/* 200 */ 1,
/* 201 */ -195,
/* 202 */ 2,
/* 203 */ 209,
/* 204 */ 50257,
/* 205 */ 50260,
/* 206 */ 1,
/* 207 */ -203,
/* 208 */ 1,
/* 209 */ 0,
/* 210 */ 50257,
/* 211 */ 50040,
/* 212 */ 1,
/* 213 */ 50041,
/* 214 */ 50260,
/* 215 */ 1,
/* 216 */ -203,
/* 217 */ 2,
/* 218 */ 226,
/* 219 */ 50261,
/* 220 */ 50257,
/* 221 */ 50040,
/* 222 */ 1,
/* 223 */ 50041,
/* 224 */ -218,
/* 225 */ 1,
/* 226 */ 237,
/* 227 */ 50261,
/* 228 */ 50257,
/* 229 */ 50040,
/* 230 */ 1,
/* 231 */ 50041,
/* 232 */ 50040,
/* 233 */ 1,
/* 234 */ 50041,
/* 235 */ -218,
/* 236 */ 2,
/* 237 */ 0,
/* 238 */ 50261,
/* 239 */ 50040,
/* 240 */ 1,
/* 241 */ 50041,
/* 242 */ 50040,
/* 243 */ 1,
/* 244 */ 50041,
/* 245 */ -218,
/* 246 */ 3,
/* 247 */ 251,
/* 248 */ 50257,
/* 249 */ -247,
/* 250 */ 1,
/* 251 */ 0,
/* 252 */ 1,
/* 253 */ -247,
/* 254 */ 2,
/* 255 */ 259,
/* 256 */ 50257,
/* 257 */ -255,
/* 258 */ 1,
/* 259 */ 0,
/* 260 */ 1,
/* 261 */ -255,
/* 262 */ 2,
/* 263 */ 267,
/* 264 */ 50257,
/* 265 */ -263,
/* 266 */ 1,
/* 267 */ 0,
/* 268 */ 1,
/* 269 */ -263,
/* 270 */ 2,
/* 271 */ 0,
/* 272 */ 1,
/* 273 */ 50277,
/* 274 */ 1,
/* 275 */ 50040,
/* 276 */ 1,
/* 277 */ 50041,
/* 278 */ -271,
/* 279 */ 1,
/* 280 */ 284,
/* 281 */ 1,
/* 282 */ -280,
/* 283 */ 1,
/* 284 */ 0,
/* 285 */ -280,
/* 286 */ 2,
/* 287 */ 291,
/* 288 */ 50257,
/* 289 */ -287,
/* 290 */ 1,
/* 291 */ 0,
/* 292 */ 1,
/* 293 */ -287,
/* 294 */ 2,
/* 295 */ 299,
/* 296 */ 1,
/* 297 */ -295,
/* 298 */ 1,
/* 299 */ 305,
/* 300 */ 1,
/* 301 */ 1,
/* 302 */ 1,
/* 303 */ -295,
/* 304 */ 2,
/* 305 */ 0,
/* 306 */ 50040,
/* 307 */ 1,
/* 308 */ 50041,
/* 309 */ 1,
/* 310 */ -295,
/* 311 */ 3,
/* 312 */ 317,
/* 313 */ 1,
/* 314 */ 1,
/* 315 */ -312,
/* 316 */ 1,
/* 317 */ 0,
/* 318 */ -312,
/* 319 */ 2,
/* 320 */ 326,
/* 321 */ 50040,
/* 322 */ 1,
/* 323 */ 50041,
/* 324 */ -320,
/* 325 */ 1,
/* 326 */ 0,
/* 327 */ 1,
/* 328 */ 1,
/* 329 */ 1,
/* 330 */ -320,
/* 331 */ 2,
/* 332 */ 336,
/* 333 */ 50257,
/* 334 */ -332,
/* 335 */ 1,
/* 336 */ 0,
/* 337 */ 50256,
/* 338 */ -332,
/* 339 */ 2,
/* 340 */ 344,
/* 341 */ 50257,
/* 342 */ -340,
/* 343 */ 1,
/* 344 */ 0,
/* 345 */ 50256,
/* 346 */ -340,
/* 347 */ 2,
/* 348 */ 352,
/* 349 */ 50061,
/* 350 */ -348,
/* 351 */ 1,
/* 352 */ 356,
/* 353 */ 50060,
/* 354 */ -348,
/* 355 */ 2,
/* 356 */ 360,
/* 357 */ 50062,
/* 358 */ -348,
/* 359 */ 3,
/* 360 */ 365,
/* 361 */ 50060,
/* 362 */ 50061,
/* 363 */ -348,
/* 364 */ 4,
/* 365 */ 370,
/* 366 */ 50062,
/* 367 */ 50061,
/* 368 */ -348,
/* 369 */ 5,
/* 370 */ 0,
/* 371 */ 50033,
/* 372 */ 50061,
/* 373 */ -348,
/* 374 */ 6,
/* 375 */ 379,
/* 376 */ 50043,
/* 377 */ -375,
/* 378 */ 1,
/* 379 */ 383,
/* 380 */ 50045,
/* 381 */ -375,
/* 382 */ 2,
/* 383 */ 387,
/* 384 */ 50042,
/* 385 */ -375,
/* 386 */ 3,
/* 387 */ 0,
/* 388 */ 50047,
/* 389 */ -375,
/* 390 */ 4,
/* 391 */ 395,
/* 392 */ 50262,
/* 393 */ -391,
/* 394 */ 1,
/* 395 */ 0,
/* 396 */ 50263,
/* 397 */ -391,
/* 398 */ 2,
/* 399 */ 0,
/* 400 */ 1,
/* 401 */ 1,
/* 402 */ 1,
/* 403 */ -399,
/* 404 */ 1,
/* 405 */ 409,
/* 406 */ 50257,
/* 407 */ -405,
/* 408 */ 1,
/* 409 */ 0,
/* 410 */ 50256,
/* 411 */ -405,
/* 412 */ 2,
/* 413 */ 419,
/* 414 */ 1,
/* 415 */ 1,
/* 416 */ 1,
/* 417 */ -413,
/* 418 */ 1,
/* 419 */ 0,
/* 420 */ -413,
/* 421 */ 2,
/* 422 */ 426,
/* 423 */ 50257,
/* 424 */ -422,
/* 425 */ 1,
/* 426 */ 0,
/* 427 */ 50256,
/* 428 */ -422,
/* 429 */ 2,
/* 430 */ 435,
/* 431 */ 50044,
/* 432 */ 1,
/* 433 */ -430,
/* 434 */ 1,
/* 435 */ 0,
/* 436 */ -430,
/* 437 */ 2,
/* 438 */ 0,
/* 439 */ 1,
/* 440 */ 50257,
/* 441 */ 1,
/* 442 */ -438,
/* 443 */ 1,
/* 444 */ 448,
/* 445 */ 50272,
/* 446 */ -444,
/* 447 */ 1,
/* 448 */ 452,
/* 449 */ 50273,
/* 450 */ -444,
/* 451 */ 2,
/* 452 */ 456,
/* 453 */ 50274,
/* 454 */ -444,
/* 455 */ 3,
/* 456 */ 460,
/* 457 */ 50275,
/* 458 */ -444,
/* 459 */ 4,
/* 460 */ 0,
/* 461 */ 50276,
/* 462 */ -444,
/* 463 */ 5,
/* 464 */ 469,
/* 465 */ 50044,
/* 466 */ 1,
/* 467 */ -464,
/* 468 */ 1,
/* 469 */ 0,
/* 470 */ -464,
/* 471 */ 2,
0
};
extern int yycoordinate[];
int yycoordinate[] = {
0,
/* 1 */ 9999,
/* 2 */ 9005,
/* 3 */ 9999,
/* 4 */ 9999,
/* 5 */ 9005,
/* 6 */ 9999,
/* 7 */ 10027,
/* 8 */ 9999,
/* 9 */ 10005,
/* 10 */ 9999,
/* 11 */ 14009,
/* 12 */ 14060,
/* 13 */ 9999,
/* 14 */ 14009,
/* 15 */ 9999,
/* 16 */ 16009,
/* 17 */ 9999,
/* 18 */ 16009,
/* 19 */ 9999,
/* 20 */ 14011,
/* 21 */ 9999,
/* 22 */ 14027,
/* 23 */ 9999,
/* 24 */ 9999,
/* 25 */ 9999,
/* 26 */ 14057,
/* 27 */ 9999,
/* 28 */ 16011,
/* 29 */ 9999,
/* 30 */ 16027,
/* 31 */ 9999,
/* 32 */ 9999,
/* 33 */ 9999,
/* 34 */ 16057,
/* 35 */ 9999,
/* 36 */ 9999,
/* 37 */ 21009,
/* 38 */ 9999,
/* 39 */ 9999,
/* 40 */ 20009,
/* 41 */ 9999,
/* 42 */ 24009,
/* 43 */ 9999,
/* 44 */ 24009,
/* 45 */ 9999,
/* 46 */ 25013,
/* 47 */ 9999,
/* 48 */ 25027,
/* 49 */ 9999,
/* 50 */ 27013,
/* 51 */ 9999,
/* 52 */ 27028,
/* 53 */ 9999,
/* 54 */ 33009,
/* 55 */ 9999,
/* 56 */ 33015,
/* 57 */ 9999,
/* 58 */ 35009,
/* 59 */ 9999,
/* 60 */ 35016,
/* 61 */ 9999,
/* 62 */ 37009,
/* 63 */ 9999,
/* 64 */ 37019,
/* 65 */ 9999,
/* 66 */ 39009,
/* 67 */ 9999,
/* 68 */ 39019,
/* 69 */ 9999,
/* 70 */ 41009,
/* 71 */ 9999,
/* 72 */ 41019,
/* 73 */ 9999,
/* 74 */ 45009,
/* 75 */ 54009,
/* 76 */ 55009,
/* 77 */ 9999,
/* 78 */ 45009,
/* 79 */ 9999,
/* 80 */ 65009,
/* 81 */ 9999,
/* 82 */ 75009,
/* 83 */ 9999,
/* 84 */ 65009,
/* 85 */ 9999,
/* 86 */ 9999,
/* 87 */ 9999,
/* 88 */ 46021,
/* 89 */ 9999,
/* 90 */ 48018,
/* 91 */ 9999,
/* 92 */ 48034,
/* 93 */ 9999,
/* 94 */ 9999,
/* 95 */ 9999,
/* 96 */ 9999,
/* 97 */ 9999,
/* 98 */ 50017,
/* 99 */ 9999,
/* 100 */ 9999,
/* 101 */ 9999,
/* 102 */ 56021,
/* 103 */ 9999,
/* 104 */ 58018,
/* 105 */ 9999,
/* 106 */ 58034,
/* 107 */ 9999,
/* 108 */ 9999,
/* 109 */ 9999,
/* 110 */ 9999,
/* 111 */ 9999,
/* 112 */ 60018,
/* 113 */ 9999,
/* 114 */ 9999,
/* 115 */ 9999,
/* 116 */ 66020,
/* 117 */ 9999,
/* 118 */ 68017,
/* 119 */ 9999,
/* 120 */ 68033,
/* 121 */ 9999,
/* 122 */ 9999,
/* 123 */ 9999,
/* 124 */ 9999,
/* 125 */ 9999,
/* 126 */ 70017,
/* 127 */ 9999,
/* 128 */ 9999,
/* 129 */ 9999,
/* 130 */ 80013,
/* 131 */ 9999,
/* 132 */ 9999,
/* 133 */ 9999,
/* 134 */ 82020,
/* 135 */ 9999,
/* 136 */ 9999,
/* 137 */ 9999,
/* 138 */ 84019,
/* 139 */ 9999,
/* 140 */ 9999,
/* 141 */ 9999,
/* 142 */ 86025,
/* 143 */ 9999,
/* 144 */ 9999,
/* 145 */ 89009,
/* 146 */ 9999,
/* 147 */ 88012,
/* 148 */ 9999,
/* 149 */ 9999,
/* 150 */ 9999,
/* 151 */ 91020,
/* 152 */ 9999,
/* 153 */ 9999,
/* 154 */ 94009,
/* 155 */ 9999,
/* 156 */ 93023,
/* 157 */ 9999,
/* 158 */ 9999,
/* 159 */ 97009,
/* 160 */ 9999,
/* 161 */ 96024,
/* 162 */ 9999,
/* 163 */ 9999,
/* 164 */ 100009,
/* 165 */ 9999,
/* 166 */ 99027,
/* 167 */ 9999,
/* 168 */ 9999,
/* 169 */ 9999,
/* 170 */ 102016,
/* 171 */ 9999,
/* 172 */ 9999,
/* 173 */ 107005,
/* 174 */ 9999,
/* 175 */ 109005,
/* 176 */ 9999,
/* 177 */ 9999,
/* 178 */ 106009,
/* 179 */ 9999,
/* 180 */ 9999,
/* 181 */ 9999,
/* 182 */ 110020,
/* 183 */ 9999,
/* 184 */ 112017,
/* 185 */ 9999,
/* 186 */ 112033,
/* 187 */ 9999,
/* 188 */ 9999,
/* 189 */ 119005,
/* 190 */ 9999,
/* 191 */ 121005,
/* 192 */ 9999,
/* 193 */ 9999,
/* 194 */ 118006,
/* 195 */ 9999,
/* 196 */ 9999,
/* 197 */ 9999,
/* 198 */ 122020,
/* 199 */ 9999,
/* 200 */ 124017,
/* 201 */ 9999,
/* 202 */ 124033,
/* 203 */ 9999,
/* 204 */ 9999,
/* 205 */ 9999,
/* 206 */ 132009,
/* 207 */ 9999,
/* 208 */ 130012,
/* 209 */ 9999,
/* 210 */ 9999,
/* 211 */ 9999,
/* 212 */ 136013,
/* 213 */ 9999,
/* 214 */ 9999,
/* 215 */ 138009,
/* 216 */ 9999,
/* 217 */ 135012,
/* 218 */ 9999,
/* 219 */ 9999,
/* 220 */ 9999,
/* 221 */ 9999,
/* 222 */ 145009,
/* 223 */ 9999,
/* 224 */ 9999,
/* 225 */ 142011,
/* 226 */ 9999,
/* 227 */ 9999,
/* 228 */ 9999,
/* 229 */ 9999,
/* 230 */ 155009,
/* 231 */ 9999,
/* 232 */ 9999,
/* 233 */ 158009,
/* 234 */ 9999,
/* 235 */ 9999,
/* 236 */ 152011,
/* 237 */ 9999,
/* 238 */ 9999,
/* 239 */ 9999,
/* 240 */ 167009,
/* 241 */ 9999,
/* 242 */ 9999,
/* 243 */ 170009,
/* 244 */ 9999,
/* 245 */ 9999,
/* 246 */ 165011,
/* 247 */ 9999,
/* 248 */ 9999,
/* 249 */ 9999,
/* 250 */ 146025,
/* 251 */ 9999,
/* 252 */ 148022,
/* 253 */ 9999,
/* 254 */ 148038,
/* 255 */ 9999,
/* 256 */ 9999,
/* 257 */ 9999,
/* 258 */ 159025,
/* 259 */ 9999,
/* 260 */ 161022,
/* 261 */ 9999,
/* 262 */ 161038,
/* 263 */ 9999,
/* 264 */ 9999,
/* 265 */ 9999,
/* 266 */ 171025,
/* 267 */ 9999,
/* 268 */ 173022,
/* 269 */ 9999,
/* 270 */ 173038,
/* 271 */ 9999,
/* 272 */ 179005,
/* 273 */ 9999,
/* 274 */ 181005,
/* 275 */ 9999,
/* 276 */ 183005,
/* 277 */ 9999,
/* 278 */ 9999,
/* 279 */ 179005,
/* 280 */ 9999,
/* 281 */ 179006,
/* 282 */ 9999,
/* 283 */ 179020,
/* 284 */ 9999,
/* 285 */ 9999,
/* 286 */ 179020,
/* 287 */ 9999,
/* 288 */ 9999,
/* 289 */ 9999,
/* 290 */ 184020,
/* 291 */ 9999,
/* 292 */ 186017,
/* 293 */ 9999,
/* 294 */ 186033,
/* 295 */ 9999,
/* 296 */ 192009,
/* 297 */ 9999,
/* 298 */ 192016,
/* 299 */ 9999,
/* 300 */ 194009,
/* 301 */ 195009,
/* 302 */ 196009,
/* 303 */ 9999,
/* 304 */ 194016,
/* 305 */ 9999,
/* 306 */ 9999,
/* 307 */ 199009,
/* 308 */ 9999,
/* 309 */ 201009,
/* 310 */ 9999,
/* 311 */ 198009,
/* 312 */ 9999,
/* 313 */ 201010,
/* 314 */ 201028,
/* 315 */ 9999,
/* 316 */ 201026,
/* 317 */ 9999,
/* 318 */ 9999,
/* 319 */ 201026,
/* 320 */ 9999,
/* 321 */ 9999,
/* 322 */ 206009,
/* 323 */ 9999,
/* 324 */ 9999,
/* 325 */ 205009,
/* 326 */ 9999,
/* 327 */ 209009,
/* 328 */ 214009,
/* 329 */ 215009,
/* 330 */ 9999,
/* 331 */ 209009,
/* 332 */ 9999,
/* 333 */ 9999,
/* 334 */ 9999,
/* 335 */ 210024,
/* 336 */ 9999,
/* 337 */ 9999,
/* 338 */ 9999,
/* 339 */ 212026,
/* 340 */ 9999,
/* 341 */ 9999,
/* 342 */ 9999,
/* 343 */ 216024,
/* 344 */ 9999,
/* 345 */ 9999,
/* 346 */ 9999,
/* 347 */ 218026,
/* 348 */ 9999,
/* 349 */ 9999,
/* 350 */ 9999,
/* 351 */ 223009,
/* 352 */ 9999,
/* 353 */ 9999,
/* 354 */ 9999,
/* 355 */ 225009,
/* 356 */ 9999,
/* 357 */ 9999,
/* 358 */ 9999,
/* 359 */ 227009,
/* 360 */ 9999,
/* 361 */ 9999,
/* 362 */ 9999,
/* 363 */ 9999,
/* 364 */ 229009,
/* 365 */ 9999,
/* 366 */ 9999,
/* 367 */ 9999,
/* 368 */ 9999,
/* 369 */ 231009,
/* 370 */ 9999,
/* 371 */ 9999,
/* 372 */ 9999,
/* 373 */ 9999,
/* 374 */ 233009,
/* 375 */ 9999,
/* 376 */ 9999,
/* 377 */ 9999,
/* 378 */ 237009,
/* 379 */ 9999,
/* 380 */ 9999,
/* 381 */ 9999,
/* 382 */ 239009,
/* 383 */ 9999,
/* 384 */ 9999,
/* 385 */ 9999,
/* 386 */ 241009,
/* 387 */ 9999,
/* 388 */ 9999,
/* 389 */ 9999,
/* 390 */ 243009,
/* 391 */ 9999,
/* 392 */ 9999,
/* 393 */ 9999,
/* 394 */ 247011,
/* 395 */ 9999,
/* 396 */ 9999,
/* 397 */ 9999,
/* 398 */ 249010,
/* 399 */ 9999,
/* 400 */ 253005,
/* 401 */ 258005,
/* 402 */ 266005,
/* 403 */ 9999,
/* 404 */ 253005,
/* 405 */ 9999,
/* 406 */ 9999,
/* 407 */ 9999,
/* 408 */ 254020,
/* 409 */ 9999,
/* 410 */ 9999,
/* 411 */ 9999,
/* 412 */ 256022,
/* 413 */ 9999,
/* 414 */ 259013,
/* 415 */ 260013,
/* 416 */ 259031,
/* 417 */ 9999,
/* 418 */ 259031,
/* 419 */ 9999,
/* 420 */ 9999,
/* 421 */ 259031,
/* 422 */ 9999,
/* 423 */ 9999,
/* 424 */ 9999,
/* 425 */ 261028,
/* 426 */ 9999,
/* 427 */ 9999,
/* 428 */ 9999,
/* 429 */ 263030,
/* 430 */ 9999,
/* 431 */ 9999,
/* 432 */ 266048,
/* 433 */ 9999,
/* 434 */ 266007,
/* 435 */ 9999,
/* 436 */ 9999,
/* 437 */ 266007,
/* 438 */ 9999,
/* 439 */ 270005,
/* 440 */ 9999,
/* 441 */ 282005,
/* 442 */ 9999,
/* 443 */ 270005,
/* 444 */ 9999,
/* 445 */ 9999,
/* 446 */ 9999,
/* 447 */ 271021,
/* 448 */ 9999,
/* 449 */ 9999,
/* 450 */ 9999,
/* 451 */ 273023,
/* 452 */ 9999,
/* 453 */ 9999,
/* 454 */ 9999,
/* 455 */ 275019,
/* 456 */ 9999,
/* 457 */ 9999,
/* 458 */ 9999,
/* 459 */ 277019,
/* 460 */ 9999,
/* 461 */ 9999,
/* 462 */ 9999,
/* 463 */ 279019,
/* 464 */ 9999,
/* 465 */ 9999,
/* 466 */ 282046,
/* 467 */ 9999,
/* 468 */ 282007,
/* 469 */ 9999,
/* 470 */ 9999,
/* 471 */ 282007,
0
};
/* only for BIGHASH (see art.c)
extern int DHITS[];
int DHITS[473];
*/
int TABLE[101][256];
init_dirsets() {
TABLE[50][0] = 1;
TABLE[50][281] = 1;
TABLE[50][40] = 1;
TABLE[50][270] = 1;
TABLE[50][277] = 1;
TABLE[50][261] = 1;
TABLE[50][257] = 1;
TABLE[50][259] = 1;
TABLE[50][258] = 1;
TABLE[50][265] = 1;
TABLE[50][266] = 1;
TABLE[50][267] = 1;
TABLE[50][268] = 1;
TABLE[50][269] = 1;
TABLE[50][278] = 1;
TABLE[50][279] = 1;
TABLE[50][280] = 1;
TABLE[50][271] = 1;
TABLE[50][256] = 1;
TABLE[1][0] = 1;
TABLE[1][281] = 1;
TABLE[1][40] = 1;
TABLE[1][270] = 1;
TABLE[1][271] = 1;
TABLE[1][280] = 1;
TABLE[1][279] = 1;
TABLE[1][278] = 1;
TABLE[1][269] = 1;
TABLE[1][268] = 1;
TABLE[1][267] = 1;
TABLE[1][266] = 1;
TABLE[1][265] = 1;
TABLE[1][258] = 1;
TABLE[1][259] = 1;
TABLE[1][257] = 1;
TABLE[1][261] = 1;
TABLE[1][277] = 1;
TABLE[1][256] = 1;
TABLE[2][0] = 1;
TABLE[2][281] = 1;
TABLE[2][40] = 1;
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
TABLE[2][256] = 1;
TABLE[3][0] = 1;
TABLE[3][281] = 1;
TABLE[3][40] = 1;
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
TABLE[3][256] = 1;
TABLE[51][281] = 1;
TABLE[51][0] = 1;
TABLE[51][40] = 1;
TABLE[51][270] = 1;
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
TABLE[51][257] = 1;
TABLE[51][261] = 1;
TABLE[51][277] = 1;
TABLE[51][256] = 1;
TABLE[52][281] = 1;
TABLE[53][0] = 1;
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
TABLE[54][281] = 1;
TABLE[4][40] = 1;
TABLE[5][281] = 1;
TABLE[5][0] = 1;
TABLE[5][41] = 1;
TABLE[5][270] = 1;
TABLE[5][277] = 1;
TABLE[5][261] = 1;
TABLE[5][257] = 1;
TABLE[5][259] = 1;
TABLE[5][258] = 1;
TABLE[5][265] = 1;
TABLE[5][266] = 1;
TABLE[5][267] = 1;
TABLE[5][268] = 1;
TABLE[5][269] = 1;
TABLE[5][278] = 1;
TABLE[5][279] = 1;
TABLE[5][280] = 1;
TABLE[5][271] = 1;
TABLE[5][40] = 1;
TABLE[5][256] = 1;
TABLE[55][281] = 1;
TABLE[55][40] = 1;
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
TABLE[55][0] = 1;
TABLE[55][41] = 1;
TABLE[55][258] = 1;
TABLE[55][259] = 1;
TABLE[55][257] = 1;
TABLE[55][261] = 1;
TABLE[55][277] = 1;
TABLE[55][256] = 1;
TABLE[56][281] = 1;
TABLE[56][0] = 1;
TABLE[56][41] = 1;
TABLE[56][270] = 1;
TABLE[56][40] = 1;
TABLE[56][257] = 1;
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
TABLE[56][261] = 1;
TABLE[56][277] = 1;
TABLE[56][256] = 1;
TABLE[6][258] = 1;
TABLE[7][259] = 1;
TABLE[8][257] = 1;
TABLE[9][261] = 1;
TABLE[10][281] = 1;
TABLE[10][40] = 1;
TABLE[10][270] = 1;
TABLE[10][271] = 1;
TABLE[10][280] = 1;
TABLE[10][279] = 1;
TABLE[10][278] = 1;
TABLE[10][269] = 1;
TABLE[10][268] = 1;
TABLE[10][267] = 1;
TABLE[10][266] = 1;
TABLE[10][265] = 1;
TABLE[10][258] = 1;
TABLE[10][259] = 1;
TABLE[10][261] = 1;
TABLE[10][0] = 1;
TABLE[10][41] = 1;
TABLE[10][277] = 1;
TABLE[10][256] = 1;
TABLE[10][257] = 1;
TABLE[11][257] = 1;
TABLE[11][40] = 1;
TABLE[11][270] = 1;
TABLE[11][277] = 1;
TABLE[11][261] = 1;
TABLE[11][259] = 1;
TABLE[11][258] = 1;
TABLE[11][265] = 1;
TABLE[11][266] = 1;
TABLE[11][267] = 1;
TABLE[11][268] = 1;
TABLE[11][269] = 1;
TABLE[11][278] = 1;
TABLE[11][279] = 1;
TABLE[11][280] = 1;
TABLE[11][271] = 1;
TABLE[11][256] = 1;
TABLE[12][257] = 1;
TABLE[12][40] = 1;
TABLE[12][270] = 1;
TABLE[12][277] = 1;
TABLE[12][261] = 1;
TABLE[12][259] = 1;
TABLE[12][258] = 1;
TABLE[12][265] = 1;
TABLE[12][266] = 1;
TABLE[12][267] = 1;
TABLE[12][268] = 1;
TABLE[12][269] = 1;
TABLE[12][278] = 1;
TABLE[12][279] = 1;
TABLE[12][280] = 1;
TABLE[12][271] = 1;
TABLE[12][256] = 1;
TABLE[57][257] = 1;
TABLE[58][40] = 1;
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
TABLE[61][0] = 1;
TABLE[61][41] = 1;
TABLE[61][40] = 1;
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
TABLE[63][257] = 1;
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
TABLE[65][40] = 1;
TABLE[13][265] = 1;
TABLE[14][266] = 1;
TABLE[15][267] = 1;
TABLE[16][268] = 1;
TABLE[17][269] = 1;
TABLE[18][270] = 1;
TABLE[19][278] = 1;
TABLE[20][279] = 1;
TABLE[21][280] = 1;
TABLE[22][271] = 1;
TABLE[23][258] = 1;
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
TABLE[24][259] = 1;
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
TABLE[25][257] = 1;
TABLE[26][257] = 1;
TABLE[27][261] = 1;
TABLE[28][261] = 1;
TABLE[29][261] = 1;
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
TABLE[72][257] = 1;
TABLE[73][41] = 1;
TABLE[73][40] = 1;
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
TABLE[74][257] = 1;
TABLE[75][41] = 1;
TABLE[75][40] = 1;
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
TABLE[30][277] = 1;
TABLE[30][257] = 1;
TABLE[30][256] = 1;
TABLE[76][256] = 1;
TABLE[76][257] = 1;
TABLE[96][277] = 1;
TABLE[77][257] = 1;
TABLE[78][41] = 1;
TABLE[78][40] = 1;
TABLE[78][270] = 1;
TABLE[78][271] = 1;
TABLE[78][280] = 1;
TABLE[78][279] = 1;
TABLE[78][278] = 1;
TABLE[78][269] = 1;
TABLE[78][268] = 1;
TABLE[78][267] = 1;
TABLE[78][266] = 1;
TABLE[78][265] = 1;
TABLE[78][258] = 1;
TABLE[78][259] = 1;
TABLE[78][257] = 1;
TABLE[78][261] = 1;
TABLE[78][277] = 1;
TABLE[78][256] = 1;
TABLE[31][40] = 1;
TABLE[31][256] = 1;
TABLE[31][257] = 1;
TABLE[32][40] = 1;
TABLE[32][256] = 1;
TABLE[32][257] = 1;
TABLE[33][40] = 1;
TABLE[79][262] = 1;
TABLE[79][263] = 1;
TABLE[97][281] = 1;
TABLE[97][40] = 1;
TABLE[97][270] = 1;
TABLE[97][271] = 1;
TABLE[97][280] = 1;
TABLE[97][279] = 1;
TABLE[97][278] = 1;
TABLE[97][269] = 1;
TABLE[97][268] = 1;
TABLE[97][267] = 1;
TABLE[97][266] = 1;
TABLE[97][265] = 1;
TABLE[97][258] = 1;
TABLE[97][259] = 1;
TABLE[97][257] = 1;
TABLE[97][261] = 1;
TABLE[97][277] = 1;
TABLE[97][256] = 1;
TABLE[97][0] = 1;
TABLE[97][41] = 1;
TABLE[34][40] = 1;
TABLE[35][257] = 1;
TABLE[35][256] = 1;
TABLE[80][257] = 1;
TABLE[81][256] = 1;
TABLE[82][257] = 1;
TABLE[83][256] = 1;
TABLE[36][61] = 1;
TABLE[37][60] = 1;
TABLE[38][62] = 1;
TABLE[39][60] = 1;
TABLE[40][62] = 1;
TABLE[41][33] = 1;
TABLE[42][43] = 1;
TABLE[43][45] = 1;
TABLE[44][42] = 1;
TABLE[45][47] = 1;
TABLE[46][262] = 1;
TABLE[47][263] = 1;
TABLE[48][257] = 1;
TABLE[48][256] = 1;
TABLE[84][257] = 1;
TABLE[85][256] = 1;
TABLE[88][43] = 1;
TABLE[88][45] = 1;
TABLE[88][42] = 1;
TABLE[88][47] = 1;
TABLE[98][44] = 1;
TABLE[98][40] = 1;
TABLE[98][41] = 1;
TABLE[98][277] = 1;
TABLE[86][257] = 1;
TABLE[87][256] = 1;
TABLE[89][44] = 1;
TABLE[99][40] = 1;
TABLE[99][41] = 1;
TABLE[99][277] = 1;
TABLE[49][272] = 1;
TABLE[49][273] = 1;
TABLE[49][274] = 1;
TABLE[49][275] = 1;
TABLE[49][276] = 1;
TABLE[90][272] = 1;
TABLE[91][273] = 1;
TABLE[92][274] = 1;
TABLE[93][275] = 1;
TABLE[94][276] = 1;
TABLE[95][44] = 1;
TABLE[100][40] = 1;
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
      case 19: return 1; break;
      case 27: return 1; break;
      case 35: return 1; break;
      case 45: return 1; break;
      case 53: return 1; break;
      case 73: return 1; break;
      case 85: return 1; break;
      case 99: return 1; break;
      case 113: return 1; break;
      case 127: return 0; break;
      case 171: return 0; break;
      case 179: return 1; break;
      case 187: return 0; break;
      case 195: return 1; break;
      case 203: return 0; break;
      case 218: return 0; break;
      case 247: return 1; break;
      case 255: return 1; break;
      case 263: return 1; break;
      case 271: return 1; break;
      case 280: return 1; break;
      case 287: return 1; break;
      case 295: return 0; break;
      case 312: return 1; break;
      case 320: return 0; break;
      case 332: return 0; break;
      case 340: return 0; break;
      case 348: return 0; break;
      case 375: return 0; break;
      case 391: return 0; break;
      case 399: return 0; break;
      case 405: return 0; break;
      case 413: return 1; break;
      case 422: return 0; break;
      case 430: return 1; break;
      case 438: return 0; break;
      case 444: return 0; break;
      case 464: return 1; break;
   }
}
char * yyprintname(n)
   int n;
{
   if (n <= 50000)
      switch(n) {
         case 1: return "YYSTART"; break;
         case 6: return "init"; break;
         case 10: return "consulta"; break;
         case 19: return "Subphrase"; break;
         case 27: return "Subphrase"; break;
         case 35: return "operacao_consulta"; break;
         case 45: return "Subphrase"; break;
         case 53: return "operacao_unaria"; break;
         case 73: return "operacao_binaria"; break;
         case 85: return "Subphrase"; break;
         case 99: return "Subphrase"; break;
         case 113: return "Subphrase"; break;
         case 127: return "tipo_operacao_binaria"; break;
         case 171: return "selecao"; break;
         case 179: return "Subphrase"; break;
         case 187: return "projecao"; break;
         case 195: return "Subphrase"; break;
         case 203: return "renomeacao1"; break;
         case 218: return "renomeacao2"; break;
         case 247: return "Subphrase"; break;
         case 255: return "Subphrase"; break;
         case 263: return "Subphrase"; break;
         case 271: return "agrupamento"; break;
         case 280: return "Subphrase"; break;
         case 287: return "Subphrase"; break;
         case 295: return "predicado"; break;
         case 312: return "Subphrase"; break;
         case 320: return "condicao"; break;
         case 332: return "Subphrase"; break;
         case 340: return "Subphrase"; break;
         case 348: return "operador_comparacao"; break;
         case 375: return "operador_aritmetico"; break;
         case 391: return "operador_booleano"; break;
         case 399: return "lista_atributos"; break;
         case 405: return "Subphrase"; break;
         case 413: return "Subphrase"; break;
         case 422: return "Subphrase"; break;
         case 430: return "Subphrase"; break;
         case 438: return "lista_funcoes_agregadas"; break;
         case 444: return "Subphrase"; break;
         case 464: return "Subphrase"; break;
   }
   else 
      switch(n-50000) {
         case 281: return "COMENTARIO"; break;
         case 280: return "COMPLETE_OUTER_JOIN"; break;
         case 279: return "RIGHT_OUTER_JOIN"; break;
         case 278: return "LEFT_OUTER_JOIN"; break;
         case 277: return "FSCRIPT"; break;
         case 276: return "SUM"; break;
         case 275: return "MIN"; break;
         case 274: return "MAX"; break;
         case 273: return "AVERAGE"; break;
         case 272: return "COUNT"; break;
         case 271: return "DIVISION"; break;
         case 270: return "NATURAL_JOIN"; break;
         case 269: return "JOIN"; break;
         case 268: return "PRODUCT_CARTESIAN"; break;
         case 267: return "SUBTRACTION"; break;
         case 266: return "INTERSECTION"; break;
         case 265: return "UNION"; break;
         case 264: return "NOT"; break;
         case 263: return "OR"; break;
         case 262: return "AND"; break;
         case 261: return "RHO"; break;
         case 260: return "ASSIGNMENT"; break;
         case 259: return "PI"; break;
         case 258: return "SIGMA"; break;
         case 257: return "NOME"; break;
         case 256: return "NUMERO"; break;
      }
   return "special_character";
}
