%option noyywrap
%option nounput

%{

#include "y.tab.h"

#define YY_USER_ACTION offset += yyleng;

int offset = 1;                         // Keep track of the column number
int current_line = 1;                   // Keep track of the line number

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
{ignore}                ;                                           // Ignore spaces and tabs
\n                      { current_line += 1; offset = 1; }          // Reset counters
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
\[\]                    { return TOK_LRSQUARE; }
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
\@                      { return TOK_ARROBA; }
&&                      { return TOK_AND; }
not                     { return TOK_NOT; }
{id}                    { return TOK_IDENTIFIER; }
{integer}               { return TOK_INTEGERCONSTANT; }
{invalid_id}            { }
.                       { }
%%
