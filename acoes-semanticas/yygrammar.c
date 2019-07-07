#include "yygrammar.h"

YYSTART ()
{
   switch(yyselect()) {
   case 6: {
      root();
      get_lexval();
      } break;
   }
}

root ()
{
   switch(yyselect()) {
   case 1: {
#line 3 "spec.acc"
 printf("1\n");
# line 20 "yygrammar.c"
      A();
#line 3 "spec.acc"
 printf("2\n");
# line 24 "yygrammar.c"
      B();
#line 3 "spec.acc"
 printf("3\n");
# line 28 "yygrammar.c"
      while (1) {
         switch (yyselect()) {
         case 7: {
            root();
            } break;
         default: goto yy1;
         }
      }
      yy1: ;
      } break;
   case 2: {
#line 4 "spec.acc"
 printf("x\n"); 
# line 42 "yygrammar.c"
      C();
#line 4 "spec.acc"
 printf("y\n"); 
# line 46 "yygrammar.c"
      while (1) {
         switch (yyselect()) {
         case 8: {
            root();
            } break;
         default: goto yy2;
         }
      }
      yy2: ;
      } break;
   }
}

A ()
{
   switch(yyselect()) {
   case 3: {
      get_lexval();
#line 7 "spec.acc"
 printf("Inside A\n");
# line 67 "yygrammar.c"
      } break;
   }
}

B ()
{
   switch(yyselect()) {
   case 4: {
      get_lexval();
#line 8 "spec.acc"
 printf("Inside B\n");
# line 79 "yygrammar.c"
      } break;
   }
}

C ()
{
   switch(yyselect()) {
   case 5: {
      get_lexval();
#line 9 "spec.acc"
 printf("Inside C\n");
# line 91 "yygrammar.c"
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
int c_length = 44;
extern int yygrammar[];
int yygrammar[] = {
0,
/* 1 */ 0,
/* 2 */ 6,
/* 3 */ 50000,
/* 4 */ -1,
/* 5 */ 6,
/* 6 */ 12,
/* 7 */ 33,
/* 8 */ 37,
/* 9 */ 17,
/* 10 */ -6,
/* 11 */ 1,
/* 12 */ 0,
/* 13 */ 41,
/* 14 */ 25,
/* 15 */ -6,
/* 16 */ 2,
/* 17 */ 22,
/* 18 */ 6,
/* 19 */ 17,
/* 20 */ -17,
/* 21 */ 7,
/* 22 */ 0,
/* 23 */ -17,
/* 24 */ 9,
/* 25 */ 30,
/* 26 */ 6,
/* 27 */ 25,
/* 28 */ -25,
/* 29 */ 8,
/* 30 */ 0,
/* 31 */ -25,
/* 32 */ 10,
/* 33 */ 0,
/* 34 */ 50097,
/* 35 */ -33,
/* 36 */ 3,
/* 37 */ 0,
/* 38 */ 50098,
/* 39 */ -37,
/* 40 */ 4,
/* 41 */ 0,
/* 42 */ 50099,
/* 43 */ -41,
/* 44 */ 5,
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
/* 6 */ 12,
/* 7 */ 1,
/* 8 */ 1,
/* 9 */ 1,
/* 10 */ -6,
/* 11 */ 1,
/* 12 */ 0,
/* 13 */ 1,
/* 14 */ 1,
/* 15 */ -6,
/* 16 */ 2,
/* 17 */ 22,
/* 18 */ 1,
/* 19 */ 1,
/* 20 */ -17,
/* 21 */ 1,
/* 22 */ 0,
/* 23 */ -17,
/* 24 */ 2,
/* 25 */ 30,
/* 26 */ 1,
/* 27 */ 1,
/* 28 */ -25,
/* 29 */ 1,
/* 30 */ 0,
/* 31 */ -25,
/* 32 */ 2,
/* 33 */ 0,
/* 34 */ 50097,
/* 35 */ -33,
/* 36 */ 1,
/* 37 */ 0,
/* 38 */ 50098,
/* 39 */ -37,
/* 40 */ 1,
/* 41 */ 0,
/* 42 */ 50099,
/* 43 */ -41,
/* 44 */ 1,
0
};
extern int yycoordinate[];
int yycoordinate[] = {
0,
/* 1 */ 9999,
/* 2 */ 2006,
/* 3 */ 9999,
/* 4 */ 9999,
/* 5 */ 2006,
/* 6 */ 9999,
/* 7 */ 3020,
/* 8 */ 3040,
/* 9 */ 3060,
/* 10 */ 9999,
/* 11 */ 3002,
/* 12 */ 9999,
/* 13 */ 4024,
/* 14 */ 4045,
/* 15 */ 9999,
/* 16 */ 4005,
/* 17 */ 9999,
/* 18 */ 3061,
/* 19 */ 3064,
/* 20 */ 9999,
/* 21 */ 3064,
/* 22 */ 9999,
/* 23 */ 9999,
/* 24 */ 3064,
/* 25 */ 9999,
/* 26 */ 4046,
/* 27 */ 4049,
/* 28 */ 9999,
/* 29 */ 4049,
/* 30 */ 9999,
/* 31 */ 9999,
/* 32 */ 4049,
/* 33 */ 9999,
/* 34 */ 9999,
/* 35 */ 9999,
/* 36 */ 7004,
/* 37 */ 9999,
/* 38 */ 9999,
/* 39 */ 9999,
/* 40 */ 8004,
/* 41 */ 9999,
/* 42 */ 9999,
/* 43 */ 9999,
/* 44 */ 9004,
0
};
/* only for BIGHASH (see art.c)
extern int DHITS[];
int DHITS[46];
*/
int TABLE[11][256];
init_dirsets() {
TABLE[6][97] = 1;
TABLE[6][99] = 1;
TABLE[1][97] = 1;
TABLE[2][99] = 1;
TABLE[7][97] = 1;
TABLE[7][99] = 1;
TABLE[9][0] = 1;
TABLE[9][97] = 1;
TABLE[9][99] = 1;
TABLE[8][97] = 1;
TABLE[8][99] = 1;
TABLE[10][0] = 1;
TABLE[10][97] = 1;
TABLE[10][99] = 1;
TABLE[3][97] = 1;
TABLE[4][98] = 1;
TABLE[5][99] = 1;
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
      case 17: return 1; break;
      case 25: return 1; break;
      case 33: return 0; break;
      case 37: return 0; break;
      case 41: return 0; break;
   }
}
char * yyprintname(n)
   int n;
{
   if (n <= 50000)
      switch(n) {
         case 1: return "YYSTART"; break;
         case 6: return "root"; break;
         case 17: return "Subphrase"; break;
         case 25: return "Subphrase"; break;
         case 33: return "A"; break;
         case 37: return "B"; break;
         case 41: return "C"; break;
   }
   else 
      switch(n-50000) {
         case 256: return "NUMBER"; break;
      }
   return "special_character";
}
