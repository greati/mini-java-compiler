%{

#include <mjtoken.h>

#define YY_USER_ACTION offset += yyleng;

int offset = 0;                         // Keep track of the column number
int current_line = 0;                   // Keep track of the line number

/**
 * Print an error in lexical analysis.
 */
void lexer_error(char *);

%}

ws                  [\t ]+
comment             #.*
ignore              ({ws}|{comment})
digit               [0-9]
integer             {digit}+
string              \".*\"
alpha               [a-zA-Z]
id                  ({alpha}|_)({alpha}|{digit}|_)*
invalid_id          {digit}+({alpha}|_)+

%%

<<EOF>>                 { return END_OF_FILE; }
{ignore}                ;                                           // Ignore spaces and tabs
\n                      { current_line += 1; offset = 0; }          // Reset counters
{string}                { return TOK_STRINGCONSTANT; }
;                       { return TOK_SEMICOLON; }      
program                 { return TOK_PROGRAM; }      
class                   { return TOK_CLASS; }      
\{                      { return TOK_LCURLY; }
\}                      { return TOK_RCURLY; }
declarations            { return TOK_DECLARATIONS; }
enddeclarations         { return TOK_ENDDECLARATIONS; }
,                       { return TOK_COMMA; }
=                       { return TOK_EQUALS; }
\[                      { return TOK_LSQUARE; }
\]                      { return TOK_RSQUARE; }
int                     { return TOK_INT; }
string                  { return TOK_STRING; }
method                  { return TOK_METHOD; }
void                    { return TOK_VOID; }
\(                      { return TOK_LPAREN; }
\)                      { return TOK_RPAREN; }
val                     { return TOK_VAL; }
\.                      { return TOK_DOT; }
:=                      { return TOK_ASSIGN; }
return                  { return TOK_RETURN; }
if                      { return TOK_IF; }
else                    { return TOK_ELSE; }
while                   { return TOK_WHILE; }
for                     { return TOK_FOR; }
to                      { return TOK_TO; }
step                    { return TOK_STEP; }
switch                  { return TOK_SWITCH; }
case                    { return TOK_CASE; } 
default                 { return TOK_DEFAULT; }
print                   { return TOK_PRINT; }
read                    { return TOK_READ; }
\<                      { return TOK_LESS; }
\<=                     { return TOK_LESSEQ; }
==                      { return TOK_EQEQ; }
!=                      { return TOK_DIFF; }
\>                      { return TOK_GREATER; }
\>=                     { return TOK_GREATEREQ; }
\+                      { return TOK_PLUS; }
\-                      { return TOK_MINUS; }
\|\|                    { return TOK_2PIPE; }
\*                      { return TOK_ASTERISK; }
\%                      { return TOK_MOD; }
\/                      { return TOK_SLASH; }
&&                      { return TOK_AND; }
not                     { return TOK_NOT; }
{id}                    { return TOK_IDENTIFIER; }
{integer}               { return TOK_INTEGERCONSTANT; }
{invalid_id}            { lexer_error("invalid identifier"); }
.                       { lexer_error("unknown character or sequence"); }

%%

void lexer_error(char * msg) {
    fprintf(stderr, "[mjc warning] (row %d, col %lu) %s: %s\n", current_line, offset - yyleng, msg, yytext); 
}

#ifdef __EXECUTABLE__

/**
 * Print a token to the standard output and/or to a file.
 * 
 * @param token The token to be printed
 */
void print_token(enum MJToken token, FILE* output_file, int std_output) {
    
    char* token_name = get_token_name(token);

    if (std_output) 
        printf("%-6d %-6lu %-6lu %-25s %-50s\n", current_line, offset - yyleng, yyleng, token_name, yytext);

    if (output_file != NULL)
        fprintf(output_file, "%d %lu %lu %s %s\n", current_line, offset - yyleng, yyleng, token_name, yytext);
}

/**
 * Main function to allow using the lexer as
 * an individual program.
 */
int main(int argc, char *argv[]) {

    int std_output = 1;                     // Print to the standard output?
    FILE* output_file = NULL;               // Output file

    if (argc > 1) {
        output_file = fopen(argv[1], "w");
        if (output_file == NULL) {
            printf("Error when opening file %s", argv[1]);
            return 1;
        }
    }

    if (argc > 2)
        std_output = strtoul(argv[2], NULL, 10);

    enum MJToken token = UNDEFINED;

    while ((token = yylex()) != END_OF_FILE)
        print_token(token, output_file, std_output);

    if (output_file != NULL)
        fclose(output_file);

    return 0;
}

#endif

