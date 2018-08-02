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

digit               [0-9]
alpha               [a-zA-Z]
id                  [a-zA-z_][a-zA-Z0-9_]*

%%

[\t ]+                  ;                                           // Ignore spaces and tabs
\n                      { current_line += 1; offset = 0; }          // Reset counters
\".*\"                  { print_token(TOK_STRINGCONSTANT); }
#.*                     ;
;                       { print_token(TOK_SEMICOLON); }      
program                 { print_token(TOK_PROGRAM); }      
class                   { print_token(TOK_CLASS); }      
\{                      { print_token(TOK_LCURLY); }
\}                      { print_token(TOK_RCURLY); }
declarations            { print_token(TOK_DECLARATIONS); }
enddeclarations         { print_token(TOK_ENDDECLARATIONS); }
,                       { print_token(TOK_COMMA); }
=                       { print_token(TOK_EQUALS); }
\[                      { print_token(TOK_LSQUARE); }
\]                      { print_token(TOK_RSQUARE); }
int                     { print_token(TOK_INT); }
string                  { print_token(TOK_STRING); }
method                  { print_token(TOK_METHOD); }
void                    { print_token(TOK_VOID); }
\(                      { print_token(TOK_LPAREN); }
\)                      { print_token(TOK_RPAREN); }
val                     { print_token(TOK_VAL); }
\.                      { print_token(TOK_DOT); }
:=                      { print_token(TOK_ASSIGN); }
return                  { print_token(TOK_RETURN); }
if                      { print_token(TOK_IF); }
else                    { print_token(TOK_ELSE); }
while                   { print_token(TOK_WHILE); }
for                     { print_token(TOK_FOR); }
switch                  { print_token(TOK_SWITCH); }
case                    { print_token(TOK_CASE); } 
\<                      { print_token(TOK_LESS); }
\<=                     { print_token(TOK_LESSEQ); }
==                      { print_token(TOK_EQEQ); }
!=                      { print_token(TOK_DIFF); }
\>                      { print_token(TOK_GREATER); }
\>=                     { print_token(TOK_GREATEREQ); }
\+                      { print_token(TOK_PLUS); }
\-                      { print_token(TOK_MINUS); }
\|\|                    { print_token(TOK_2PIPE); }
\*                      { print_token(TOK_ASTERISK); }
\/                      { print_token(TOK_SLASH); }
&&                      { print_token(TOK_AND); }
not                     { print_token(TOK_NOT); }
{id}                    { print_token(TOK_IDENTIFIER); }
{digit}+                { print_token(TOK_INTEGERCONSTANT); }
{digit}+({alpha}|_)+    { print_token(UNDEFINED); }             // Invalid identifier
.                       { print_token(UNDEFINED); }

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

