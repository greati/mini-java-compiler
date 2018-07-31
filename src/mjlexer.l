%{

#include <mjtoken.h>

%}

%%

[\t ]+  ;   // Ignore spaces and tabs

%%

int main(int argc, char *argv[]) {

    yylex();

    return 0;
}

