%{

#include <mjtoken.h>

#define YY_USER_ACTION offset += yyleng;

int std_output = 1;                     // Print to the standard output?

int offset = 0;                         // Keep track of the column number
int current_line = 0;                   // Keep track of the line number

FILE* output_file = NULL;               // Output file

/**
 * Print a token to the standard output and/or to a file.
 * 
 * @param token The token to be printed
 */
void print_token(enum MJToken token);

%}

%%

[\t ]+              ;                                           // Ignore spaces and tabs
\n                  { current_line += 1; offset = 0; }          // Reset counters
;                   { print_token(TOK_SEMICOLON); }      
program             { print_token(TOK_PROGRAM); }      
class               { print_token(TOK_CLASS); }      

%%

void print_token(enum MJToken token) {
    
    char* token_name = get_token_name(token);

    if (std_output) 
        printf("%d %d %d %s %s\n", current_line, offset - yyleng, yyleng, token_name, yytext);

    if (output_file != NULL)
        fprintf(output_file, "%d %d %d %s %s\n", current_line, offset - yyleng, yyleng, token_name, yytext);
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

