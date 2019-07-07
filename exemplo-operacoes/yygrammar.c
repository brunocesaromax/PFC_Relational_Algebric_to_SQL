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
   switch(yyselect()) {
   case 1: {
      term();
      } break;
   }
}

term ()
{
   switch(yyselect()) {
   case 2: {
      term();
      get_lexval();
      factor();
      } break;
   case 3: {
      term();
      get_lexval();
      factor();
      } break;
   case 4: {
      factor();
      } break;
   }
}

factor ()
{
   switch(yyselect()) {
   case 5: {
      factor();
      get_lexval();
      primary();
      } break;
   case 6: {
      factor();
      get_lexval();
      primary();
      } break;
   case 7: {
      primary();
      } break;
   }
}

primary ()
{
   switch(yyselect()) {
   case 8: {
      get_lexval();
      } break;
   case 9: {
      get_lexval();
      term();
      get_lexval();
      } break;
   case 10: {
      get_lexval();
      primary();
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
/* 2 */ 3012,
/* 3 */ 9999,
/* 4 */ 9999,
/* 5 */ 3012,
/* 6 */ 9999,
/* 7 */ 4002,
/* 8 */ 9999,
/* 9 */ 4005,
/* 10 */ 9999,
/* 11 */ 8002,
/* 12 */ 9999,
/* 13 */ 8011,
/* 14 */ 9999,
/* 15 */ 8005,
/* 16 */ 9999,
/* 17 */ 9004,
/* 18 */ 9999,
/* 19 */ 9013,
/* 20 */ 9999,
/* 21 */ 9007,
/* 22 */ 9999,
/* 23 */ 10004,
/* 24 */ 9999,
/* 25 */ 10009,
/* 26 */ 9999,
/* 27 */ 14002,
/* 28 */ 9999,
/* 29 */ 14013,
/* 30 */ 9999,
/* 31 */ 14007,
/* 32 */ 9999,
/* 33 */ 15004,
/* 34 */ 9999,
/* 35 */ 15015,
/* 36 */ 9999,
/* 37 */ 15009,
/* 38 */ 9999,
/* 39 */ 16004,
/* 40 */ 9999,
/* 41 */ 16010,
/* 42 */ 9999,
/* 43 */ 9999,
/* 44 */ 9999,
/* 45 */ 20007,
/* 46 */ 9999,
/* 47 */ 9999,
/* 48 */ 21008,
/* 49 */ 9999,
/* 50 */ 9999,
/* 51 */ 21004,
/* 52 */ 9999,
/* 53 */ 9999,
/* 54 */ 22008,
/* 55 */ 9999,
/* 56 */ 22004,
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
