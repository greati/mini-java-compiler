%{

#include <mjtoken.h>

#define YY_USER_ACTION offset += yyleng;

int std_output = 1;                     // Print to the standard output?

int offset = 0;                         // Keep track of the column number
int current_line = 1;                   // Keep track of the line number

FILE* output_file = NULL;               // Output file

/**
 * Print a token to the standard output and/or to a file.
 */
void print_token(enum MJToken);

%}

%%

[\t ]+              ;                                           // Ignore spaces and tabs
\n                  { current_line += 1; offset = 0; }          // Reset counters
;                   { print_token(TOK_SEMICOLON); }      

%%

void print_token(enum MJToken token) {
    if (std_output) 
        printf("%d %d %d %d %s\n", current_line, offset, yyleng, token, yytext);
    if (output_file != NULL)
        fprintf(output_file, "%d %d %d %d %s\n", current_line, offset, yyleng, token, yytext);
}

int main(int argc, char *argv[]) {

    if (argc > 1) {
        output_file = fopen(argv[1], "w");
        if (output_file == NULL) {
            printf("Error when opening file %s", argv[1]);
            return 1;
        }
    }

    if (argc > 2)
        std_output = strtoul(argv[2], NULL, 10);

    yylex();

    if (output_file != NULL)
        fclose(output_file);

    return 0;
}

