#line 1 "spec.acc"

#include "yystype.h"

# line 6 "yygrammar.c"
#include "yygrammar.h"

YYSTART ()
{
   switch(yyselect()) {
   case 11: {
      expression();
      get_lexval();
      } break;
   }
}

expression ()
{
   YYSTYPE t_regra;
   switch(yyselect()) {
   case 1: {
      term(&t_regra);
#line 8 "spec.acc"
printf("Resultado = %d\n",t_regra);
# line 27 "yygrammar.c"
      } break;
   }
}

term (t_regra)
   YYSTYPE *t_regra;
{
   YYSTYPE t;
   YYSTYPE f;
   YYSTYPE f_regra;
   switch(yyselect()) {
   case 2: {
      term(&t);
      get_lexval();
      factor(&f);
#line 12 "spec.acc"
f_regra = t + f;
# line 45 "yygrammar.c"
      } break;
   case 3: {
      term(&t);
      get_lexval();
      factor(&f);
#line 13 "spec.acc"
f_regra = t - f;
# line 53 "yygrammar.c"
      } break;
   case 4: {
      factor(&f_regra);
      } break;
   }
}

factor (f_regra)
   YYSTYPE *f_regra;
{
   YYSTYPE f;
   YYSTYPE p;
   switch(yyselect()) {
   case 5: {
      factor(&f);
      get_lexval();
      primary(&p);
#line 18 "spec.acc"
f_regra = f * p;
# line 73 "yygrammar.c"
      } break;
   case 6: {
      factor(&f);
      get_lexval();
      primary(&p);
#line 19 "spec.acc"
f_regra = f / p;
# line 81 "yygrammar.c"
      } break;
   case 7: {
      primary(&p);
#line 20 "spec.acc"
f_regra = p;
# line 87 "yygrammar.c"
      } break;
   }
}

primary (p_regra)
   YYSTYPE *p_regra;
{
   YYSTYPE n;
   YYSTYPE t;
   YYSTYPE x;
   switch(yyselect()) {
   case 8: {
      get_lexval();
      n = yylval;
#line 24 "spec.acc"
p_regra = n.intval;
# line 104 "yygrammar.c"
      } break;
   case 9: {
      get_lexval();
      term(&t);
      get_lexval();
#line 25 "spec.acc"
p_regra = t;
# line 112 "yygrammar.c"
      } break;
   case 10: {
      get_lexval();
      primary(&x);
#line 26 "spec.acc"
p_regra -= x;
# line 119 "yygrammar.c"
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
int c_length = 56;
extern int yygrammar[];
int yygrammar[] = {
0,
/* 1 */ 0,
/* 2 */ 6,
/* 3 */ 50000,
/* 4 */ -1,
/* 5 */ 11,
/* 6 */ 0,
/* 7 */ 10,
/* 8 */ -6,
/* 9 */ 1,
/* 10 */ 16,
/* 11 */ 10,
/* 12 */ 50043,
/* 13 */ 26,
/* 14 */ -10,
/* 15 */ 2,
/* 16 */ 22,
/* 17 */ 10,
/* 18 */ 50045,
/* 19 */ 26,
/* 20 */ -10,
/* 21 */ 3,
/* 22 */ 0,
/* 23 */ 26,
/* 24 */ -10,
/* 25 */ 4,
/* 26 */ 32,
/* 27 */ 26,
/* 28 */ 50042,
/* 29 */ 42,
/* 30 */ -26,
/* 31 */ 5,
/* 32 */ 38,
/* 33 */ 26,
/* 34 */ 50047,
/* 35 */ 42,
/* 36 */ -26,
/* 37 */ 6,
/* 38 */ 0,
/* 39 */ 42,
/* 40 */ -26,
/* 41 */ 7,
/* 42 */ 46,
/* 43 */ 50256,
/* 44 */ -42,
/* 45 */ 8,
/* 46 */ 52,
/* 47 */ 50040,
/* 48 */ 10,
/* 49 */ 50041,
/* 50 */ -42,
/* 51 */ 9,
/* 52 */ 0,
/* 53 */ 50045,
/* 54 */ 42,
/* 55 */ -42,
/* 56 */ 10,
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
/* 10 */ 16,
/* 11 */ 1,
/* 12 */ 50043,
/* 13 */ 1,
/* 14 */ -10,
/* 15 */ 1,
/* 16 */ 22,
/* 17 */ 1,
/* 18 */ 50045,
/* 19 */ 1,
/* 20 */ -10,
/* 21 */ 2,
/* 22 */ 0,
/* 23 */ 1,
/* 24 */ -10,
/* 25 */ 3,
/* 26 */ 32,
/* 27 */ 1,
/* 28 */ 50042,
/* 29 */ 1,
/* 30 */ -26,
/* 31 */ 1,
/* 32 */ 38,
/* 33 */ 1,
/* 34 */ 50047,
/* 35 */ 1,
/* 36 */ -26,
/* 37 */ 2,
/* 38 */ 0,
/* 39 */ 1,
/* 40 */ -26,
/* 41 */ 3,
/* 42 */ 46,
/* 43 */ 50256,
/* 44 */ -42,
/* 45 */ 1,
/* 46 */ 52,
/* 47 */ 50040,
/* 48 */ 1,
/* 49 */ 50041,
/* 50 */ -42,
/* 51 */ 2,
/* 52 */ 0,
/* 53 */ 50045,
/* 54 */ 1,
/* 55 */ -42,
/* 56 */ 3,
0
};
extern int yycoordinate[];
int yycoordinate[] = {
0,
/* 1 */ 9999,
/* 2 */ 7012,
/* 3 */ 9999,
/* 4 */ 9999,
/* 5 */ 7012,
/* 6 */ 9999,
/* 7 */ 8002,
/* 8 */ 9999,
/* 9 */ 8005,
/* 10 */ 9999,
/* 11 */ 12002,
/* 12 */ 9999,
/* 13 */ 12014,
/* 14 */ 9999,
/* 15 */ 12005,
/* 16 */ 9999,
/* 17 */ 13004,
/* 18 */ 9999,
/* 19 */ 13016,
/* 20 */ 9999,
/* 21 */ 13007,
/* 22 */ 9999,
/* 23 */ 14004,
/* 24 */ 9999,
/* 25 */ 14009,
/* 26 */ 9999,
/* 27 */ 18002,
/* 28 */ 9999,
/* 29 */ 18016,
/* 30 */ 9999,
/* 31 */ 18007,
/* 32 */ 9999,
/* 33 */ 19004,
/* 34 */ 9999,
/* 35 */ 19018,
/* 36 */ 9999,
/* 37 */ 19009,
/* 38 */ 9999,
/* 39 */ 20004,
/* 40 */ 9999,
/* 41 */ 20010,
/* 42 */ 9999,
/* 43 */ 9999,
/* 44 */ 9999,
/* 45 */ 24007,
/* 46 */ 9999,
/* 47 */ 9999,
/* 48 */ 25008,
/* 49 */ 9999,
/* 50 */ 9999,
/* 51 */ 25004,
/* 52 */ 9999,
/* 53 */ 9999,
/* 54 */ 26008,
/* 55 */ 9999,
/* 56 */ 26004,
0
};
/* only for BIGHASH (see art.c)
extern int DHITS[];
int DHITS[58];
*/
int TABLE[12][256];
init_dirsets() {
TABLE[11][45] = 1;
TABLE[11][40] = 1;
TABLE[11][256] = 1;
TABLE[1][256] = 1;
TABLE[1][40] = 1;
TABLE[1][45] = 1;
TABLE[2][256] = 1;
TABLE[2][40] = 1;
TABLE[2][45] = 1;
TABLE[3][256] = 1;
TABLE[3][40] = 1;
TABLE[3][45] = 1;
TABLE[4][45] = 1;
TABLE[4][40] = 1;
TABLE[4][256] = 1;
TABLE[5][45] = 1;
TABLE[5][40] = 1;
TABLE[5][256] = 1;
TABLE[6][45] = 1;
TABLE[6][40] = 1;
TABLE[6][256] = 1;
TABLE[7][256] = 1;
TABLE[7][40] = 1;
TABLE[7][45] = 1;
TABLE[8][256] = 1;
TABLE[9][40] = 1;
TABLE[10][45] = 1;
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
      case 1: return 0; break;
      case 6: return 0; break;
      case 10: return 0; break;
      case 26: return 0; break;
      case 42: return 0; break;
   }
}
char * yyprintname(n)
   int n;
{
   if (n <= 50000)
      switch(n) {
         case 1: return "YYSTART"; break;
         case 6: return "expression"; break;
         case 10: return "term"; break;
         case 26: return "factor"; break;
         case 42: return "primary"; break;
   }
   else 
      switch(n-50000) {
         case 256: return "NUMBER"; break;
      }
   return "special_character";
}
