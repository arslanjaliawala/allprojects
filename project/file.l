%{
#include <stdio.h>
#include <stdlib.h>
%}

%option noyywrap

%%
"CREATE"    { printf("CREATE\t%s\t%d\n", yytext, yylineno); }
"ALTER"     { printf("ALTER\t%s\t%d\n", yytext, yylineno); }
"DROP"      { printf("DROP\t%s\t%d\n", yytext, yylineno); }
"SELECT"    { printf("SELECT\t%s\t%d\n", yytext, yylineno); }
"DELETE"    { printf("DELETE\t%s\t%d\n", yytext, yylineno); }
"FROM"	    { printf("FROM\t%s\t%d\n", yytext, yylineno); }
"INSERT"    { printf("INSERT\t%s\t%d\n", yytext, yylineno); }
"UPDATE"    { printf("UPDATE\t%s\t%d\n", yytext, yylineno); }
"WHERE"     { printf("WHERE\t%s\t%d\n", yytext, yylineno); }

[0-9]+      { printf("NUMBER\t%s\t%d\n", yytext, yylineno); }
[a-zA-Z_][a-zA-Z0-9_]*   { printf("IDENTIFIER\t%s\t%d\n", yytext, yylineno); }

%%

int main(int argc, char** argv) {
    if (argc != 2) {
        printf("Usage: ./lexer <input_file>\n");
        return 1;
    }

    FILE* input_file = fopen(argv[1], "r");
    if (input_file == NULL) {
        printf("Error opening input file\n");
        return 1;
    }

    yyin = input_file;
    yylex();

    fclose(input_file);

    return 0;
}

