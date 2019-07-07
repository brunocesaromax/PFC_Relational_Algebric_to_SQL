typedef union{
      int intval;
      int floatval;
      char charval;
      char *stringval;
} _ATTRIBUTE;

#define YYSTYPE _ATTRIBUTE

