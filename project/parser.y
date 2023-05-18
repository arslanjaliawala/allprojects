%{
#include <stdio.h>
#include <stdlib.h>

// Token definitions
#define T_CREATE 1
#define T_ALTER 2
#define T_DROP 3
#define T_SELECT 4
#define T_DELETE 5
#define T_INSERT 6
#define T_UPDATE 7
#define T_WHERE 8
#define T_NUMBER 9
#define T_IDENTIFIER 10

int yylex();
void yyerror(const char* msg);

%}

%token T_CREATE T_ALTER T_DROP T_SELECT T_DELETE T_INSERT T_UPDATE T_WHERE
%token <num> T_NUMBER
%token <str> T_IDENTIFIER

%start statement

%%

statement_list : statement
               | statement_list statement
               ;

statement : T_CREATE
          | T_ALTER
          | T_DROP
          | T_SELECT
          | T_DELETE
          | T_INSERT
          | T_UPDATE
          ;

%%

int main() {
    yyparse();
    return 0;
}

void yyerror(const char* msg) {
    fprintf(stderr, "Syntax Error: %s\n", msg);
}

