%{

#include <stdio.h>
#include <string>
#include "ast/Node.h"
#include "ast/Expr.h"
#include "MJMessage.h"
#include "y.tab.h"

extern int current_line;
extern int offset;
extern char * yytext;
extern int yychar;
extern int yylex();

void yyerror(char *s);

Position getPos();


%}

%union {
    Node *node;
    Var *var;
    AccessOperation *accessOp;
    ConstructList<Expr>* constructList;
    ConstructList<Case>* caseList;
    ConstructList<Stmt>* stmtList;
    Stmt* stmt;
    ReadStmt* readStmt;
    PrintStmt* printStmt;
    ReturnStmt* returnStmt;
    IfStmt* ifStmt;
    WhileStmt* whileStmt;
    ForStmt* forStmt;
    SwitchStmt* switchStmt;
    Case *case_;
    Expr *expr;
    AlExpr *alExpr;
    char* id;
    char* litString;
    int litInt;
}

%type <expr> expr
%type <var> var
%type <accessOp> var_aux
%type <constructList> expr_list_comma
%type <constructList> actual_params_list
%type <stmtList> stmt_list
%type <stmtList> stmt_list_semicolon
%type <caseList> case_list
%type <alExpr> al_expr
%type <case_> case
%type <stmt> stmt
%type <readStmt> read_stmt
%type <printStmt> print_stmt
%type <returnStmt> return_stmt
%type <ifStmt> if_stmt
%type <whileStmt> while_stmt
%type <forStmt> for_stmt
%type <switchStmt> switch_stmt

%token 
TOK_PROGRAM 1 
<id> TOK_IDENTIFIER 2
TOK_SEMICOLON 3
TOK_CLASS 4
TOK_LCURLY 5
TOK_RCURLY 6
TOK_DECLARATIONS 7
TOK_ENDDECLARATIONS 8
TOK_EQUALS 9
TOK_COMMA 10
TOK_INT 11
TOK_STRING 12
TOK_LRSQUARE 13
TOK_METHOD 14
TOK_LPAREN 15
TOK_RPAREN 16
TOK_VOID 17
TOK_VAL 18
TOK_ARROBA 19
TOK_LSQUARE 20
TOK_RSQUARE 21
TOK_ASSIGN 22
TOK_RETURN 23
TOK_IF 24
TOK_ELSE 25
TOK_FOR 26
TOK_TO 27
TOK_STEP 28
TOK_WHILE 29
TOK_SWITCH 30
TOK_CASE 31
TOK_DEFAULT 32
TOK_PRINT 33
TOK_READ 34
TOK_LESS 35
TOK_LESSEQ 36
TOK_EQEQ 37
TOK_DIFF 38
TOK_GREATEREQ 39
TOK_GREATER 40
TOK_PLUS 41
TOK_UPLUS 42
TOK_MINUS 43
TOK_UMINUS 44
TOK_NOT 45
TOK_2PIPE 46
TOK_ASTERISK 47
TOK_SLASH 48
TOK_AND 49
TOK_MOD 50
<litInt>TOK_INTEGERCONSTANT 51
<litString>TOK_STRINGCONSTANT 52
TOK_DOT 53
END_OF_FILE 0
LAMBDA 55

%start program

%nonassoc TOK_EQEQ TOK_DIFF
%left TOK_PLUS TOK_MINUS TOK_2PIPE
%left TOK_ASTERISK TOK_SLASH TOK_AND TOK_MOD
%left TOK_UMINUS TOK_UPLUS TOK_NOT

%%
program                 : TOK_PROGRAM TOK_IDENTIFIER TOK_SEMICOLON class_decl class_decl_list
class_decl_list         : /* empty */ | class_decl class_decl_list
class_decl              : TOK_CLASS TOK_IDENTIFIER class_body
                        | TOK_CLASS error class_body
class_body              : TOK_LCURLY decls_opt method_decl_list TOK_RCURLY
                        | TOK_LCURLY error TOK_RCURLY
decls_opt               : /* empty */ | decls 
decls                   : TOK_DECLARATIONS field_decl_list_decls TOK_ENDDECLARATIONS
                        | TOK_DECLARATIONS error TOK_ENDDECLARATIONS
method_decl_list        : /* empty */ | method_decl method_decl_list 
field_decl_list_decls   : /* empty */ | field_decl TOK_SEMICOLON field_decl_list_decls
field_decl              : type field_decl_aux1
field_decl_aux1         : var_decl_id field_decl_aux2
                        | var_decl_id TOK_EQUALS var_init field_decl_aux2
field_decl_aux2         : /*empty*/
                        | TOK_COMMA field_decl_aux1
type                    : type_aux brackets_opt
type_aux                : TOK_IDENTIFIER 
                        | TOK_INT 
                        | TOK_STRING
brackets_opt            : /* empty */ 
                        | TOK_LRSQUARE brackets_opt
method_decl             : TOK_METHOD method_return_type TOK_IDENTIFIER TOK_LPAREN formal_params_list_opt TOK_RPAREN block
                        | TOK_METHOD method_return_type TOK_IDENTIFIER TOK_LPAREN error TOK_RPAREN block
method_return_type      : TOK_VOID 
                        | type
formal_params           : TOK_VAL type TOK_IDENTIFIER id_list_comma
                        | type TOK_IDENTIFIER id_list_comma
formal_params_list      : formal_params 
                        | formal_params TOK_SEMICOLON formal_params_list
id_list_comma           : /* empty */ 
                        | TOK_COMMA TOK_IDENTIFIER id_list_comma
formal_params_list_opt  : /* empty */ 
                        | formal_params_list
var_decl_id             : TOK_IDENTIFIER brackets_opt
var_init                : expr 
                        | array_init 
                        | array_creation_expr
array_init              : TOK_LCURLY var_init var_init_list_comma TOK_RCURLY
                        | TOK_LCURLY error TOK_RCURLY
var_init_list_comma     : /* empty */ 
                        | TOK_COMMA var_init var_init_list_comma 
array_creation_expr     : TOK_ARROBA type array_dim_decl array_dim_decl_list
array_dim_decl          : TOK_LSQUARE expr TOK_RSQUARE
array_dim_decl_list     : /* empty */ 
                        | array_dim_decl array_dim_decl_list
block                   : decls_opt stmt_list
stmt_list               : TOK_LCURLY stmt_list_semicolon TOK_RCURLY                 {$$ = $2;}
                        | TOK_LCURLY error TOK_RCURLY                               {}
stmt_list_semicolon     : stmt                                                      {std::vector<std::shared_ptr<Stmt>> stmts;
			                                                             stmts.push_back(std::shared_ptr<Stmt>($1));
                                                                                     $$ = new ConstructList<Stmt>(getPos(),stmts);}
                        | stmt TOK_SEMICOLON stmt_list_semicolon                    {auto lst = $3; lst->push_back(std::shared_ptr<Stmt>($1));
                                                                                     $$ = lst;}
stmt                    : var TOK_ASSIGN expr                                       {$$ = new AssignStmt(getPos(), std::shared_ptr<Var>($1),
			                                                                                 std::shared_ptr<Expr>($3));}
                        | var TOK_LPAREN actual_params_list TOK_RPAREN              {$$ = new FunctionCallStmt(getPos(), std::shared_ptr<Var>($1),
                                                                                                         std::shared_ptr<ConstructList<Expr>>($3));}
                        | var TOK_LPAREN error TOK_RPAREN                           {}
                        | return_stmt                                               {$$ = $1;}
                        | if_stmt                                                   {$$ = $1;}
                        | while_stmt                                                {$$ = $1;} 
                        | for_stmt                                                  {$$ = $1;}
                        | switch_stmt                                               {$$ = $1;}
                        | print_stmt                                                {$$ = $1;}
                        | read_stmt                                                 {$$ = $1;}
actual_params_list      : /* empty */                                               {$$ = nullptr;}
                        | expr_list_comma                                           {$$ = $1;}
expr_list_comma         : expr                                                      {std::vector<std::shared_ptr<Expr>> exps; 
                                                                                     exps.push_back(std::shared_ptr<Expr>($1));
                                                                                     $$ = new ConstructList<Expr>(getPos(),exps);}
                        | expr TOK_COMMA expr_list_comma		            {auto lst = $3; lst->push_back(std::shared_ptr<Expr>($1));
                                                                                     $$ = lst;}
return_stmt             : TOK_RETURN                                                {$$ = new ReturnStmt(getPos(), nullptr);}
                        | TOK_RETURN expr                                           {$$ = new ReturnStmt(getPos(), std::shared_ptr<Expr>($2));}
if_stmt                 : TOK_IF expr stmt_list                                     {$$ = new IfStmt(getPos(), std::shared_ptr<Expr>($2),
			                                                                             std::shared_ptr<ConstructList<Stmt>>($3),
                                                                                                     nullptr);}
                        | TOK_IF expr stmt_list TOK_ELSE if_stmt                    {$$ = new IfStmt(getPos(), std::shared_ptr<Expr>($2),
                                                                                                     std::shared_ptr<ConstructList<Stmt>>($3),
                                                                                                     std::make_shared<ElseIf>(getPos(),
                                                                                                                std::shared_ptr<IfStmt>($5)));}
                        | TOK_IF expr stmt_list TOK_ELSE stmt_list                  {$$ = new IfStmt(getPos(), std::shared_ptr<Expr>($2),
                                                                                                     std::shared_ptr<ConstructList<Stmt>>($3),
                                                                                                     std::make_shared<Else>(getPos(),
                                                                                                       std::shared_ptr<ConstructList<Stmt>>($5)));}
for_stmt                : TOK_FOR TOK_IDENTIFIER TOK_ASSIGN expr TOK_TO expr TOK_STEP expr stmt_list
			                                                            {$$ = new ForStmt(getPos(), $2, std::shared_ptr<Expr>($4),
                                                                                                      std::shared_ptr<Expr>($6),
                                                                                                      std::shared_ptr<Expr>($8),
                                                                                                      std::shared_ptr<ConstructList<Stmt>>($9));}
                        | TOK_FOR TOK_IDENTIFIER TOK_ASSIGN expr TOK_TO expr stmt_list
                                                                                    {$$ = new ForStmt(getPos(), $2, std::shared_ptr<Expr>($4),
                                                                                                      std::shared_ptr<Expr>($6), nullptr,
                                                                                                      std::shared_ptr<ConstructList<Stmt>>($7));}
while_stmt              : TOK_WHILE expr stmt_list                                  {$$ = new WhileStmt(getPos(), std::shared_ptr<Expr>($2),
			                                                                                std::shared_ptr<ConstructList<Stmt>>($3));}
switch_stmt             : TOK_SWITCH expr TOK_LCURLY case_list TOK_RCURLY           {$$ = new SwitchStmt(getPos(), std::shared_ptr<Expr>($2),
			                                                                             std::shared_ptr<ConstructList<Case>>($4),
                                                                                                     nullptr);}
                        | TOK_SWITCH expr TOK_LCURLY case_list TOK_DEFAULT stmt_list TOK_RCURLY
                                                                                    {$$ = new SwitchStmt(getPos(), std::shared_ptr<Expr>($2),
                                                                                                     std::shared_ptr<ConstructList<Case>>($4),
                                                                                                     std::shared_ptr<ConstructList<Stmt>>($6));}
                        | TOK_SWITCH error TOK_LCURLY                               {}
                        | TOK_SWITCH expr TOK_LCURLY error TOK_RCURLY               {}
case                    : TOK_CASE expr stmt_list                                   {$$ = new Case(getPos(), std::shared_ptr<Expr>($2),
			                                                                           std::shared_ptr<ConstructList<Stmt>>($3));}
                        | TOK_CASE error stmt_list                                  {}
case_list               : case                                                      {std::vector<std::shared_ptr<Case>> cases;
			                                                                                     cases.push_back(std::shared_ptr<Case>($1));
                                                                                     $$ = new ConstructList<Case>(getPos(),cases);}
                        | case case_list                                            {auto lst = $2; lst->push_back(std::shared_ptr<Case>($1));
                                                                                     $$ = lst;}
print_stmt              : TOK_PRINT expr                                            {$$ = new PrintStmt(getPos(), std::shared_ptr<Expr>($2));}
read_stmt               : TOK_READ TOK_IDENTIFIER	                            {$$ = new ReadStmt(getPos(), $2);}
expr                    : al_expr TOK_EQEQ al_expr                                  {$$ = new RelExpr(getPos(), RelExpr::RelOp::EQEQ,
                                                                                                        std::shared_ptr<AlExpr>($1),
                                                                                                        std::shared_ptr<AlExpr>($3));}
                        | al_expr TOK_LESS al_expr                                  {$$ = new RelExpr(getPos(), RelExpr::RelOp::LESS,
                                                                                                        std::shared_ptr<AlExpr>($1),
                                                                                                        std::shared_ptr<AlExpr>($3));}
                        | al_expr TOK_LESSEQ al_expr                                {$$ = new RelExpr(getPos(), RelExpr::RelOp::LESS_EQ,
                                                                                                        std::shared_ptr<AlExpr>($1),
                                                                                                        std::shared_ptr<AlExpr>($3));}
                        | al_expr TOK_GREATEREQ al_expr                             {$$ = new RelExpr(getPos(), RelExpr::RelOp::GREATER_EQ,
                                                                                                        std::shared_ptr<AlExpr>($1),
                                                                                                        std::shared_ptr<AlExpr>($3));}
                        | al_expr TOK_GREATER al_expr                               {$$ = new RelExpr(getPos(), RelExpr::RelOp::GREATER,
                                                                                                        std::shared_ptr<AlExpr>($1),
                                                                                                        std::shared_ptr<AlExpr>($3));}
                        | al_expr TOK_DIFF al_expr                                  {$$ = new RelExpr(getPos(), RelExpr::RelOp::DIFF,
                                                                                                        std::shared_ptr<AlExpr>($1),
                                                                                                        std::shared_ptr<AlExpr>($3));}
                        | al_expr                                                   {$$ = $1;}

al_expr                 : TOK_PLUS al_expr %prec TOK_UPLUS                          {$$ = new AlUnExpr(getPos(), AlUnExpr::AlUnOp::PLUS,
                                                                                                        std::shared_ptr<AlExpr>($2));}
                        | TOK_MINUS al_expr %prec TOK_UMINUS                        {$$ = new AlUnExpr(getPos(), AlUnExpr::AlUnOp::MINUS,
                                                                                                        std::shared_ptr<AlExpr>($2));}
                        | TOK_NOT al_expr                                           {$$ = new AlUnExpr(getPos(), AlUnExpr::AlUnOp::NOT,
                                                                                                        std::shared_ptr<AlExpr>($2));}    
                        | al_expr TOK_PLUS al_expr                                  {$$ = new AlBinExpr(getPos(), AlBinExpr::AlBinOp::PLUS,
                                                                                                        std::shared_ptr<AlExpr>($1),
                                                                                                        std::shared_ptr<AlExpr>($3));}
                        | al_expr TOK_MINUS al_expr                                 {$$ = new AlBinExpr(getPos(), AlBinExpr::AlBinOp::MINUS,
                                                                                                        std::shared_ptr<AlExpr>($1),
                                                                                                        std::shared_ptr<AlExpr>($3));}
                        | al_expr TOK_2PIPE al_expr                                 {$$ = new AlBinExpr(getPos(), AlBinExpr::AlBinOp::OR,
                                                                                                        std::shared_ptr<AlExpr>($1),
                                                                                                        std::shared_ptr<AlExpr>($3));}
                        | al_expr TOK_ASTERISK al_expr                              {$$ = new AlBinExpr(getPos(), AlBinExpr::AlBinOp::TIMES,
                                                                                                        std::shared_ptr<AlExpr>($1),
                                                                                                        std::shared_ptr<AlExpr>($3));}
                        | al_expr TOK_SLASH al_expr                                 {$$ = new AlBinExpr(getPos(), AlBinExpr::AlBinOp::DIV,
                                                                                                        std::shared_ptr<AlExpr>($1),
                                                                                                        std::shared_ptr<AlExpr>($3));}
                        | al_expr TOK_AND al_expr                                   {$$ = new AlBinExpr(getPos(), AlBinExpr::AlBinOp::AND,
                                                                                                        std::shared_ptr<AlExpr>($1),
                                                                                                        std::shared_ptr<AlExpr>($3));}
                        | al_expr TOK_MOD al_expr                                   {$$ = new AlBinExpr(getPos(), AlBinExpr::AlBinOp::MOD,
                                                                                                        std::shared_ptr<AlExpr>($1),
                                                                                                        std::shared_ptr<AlExpr>($3));}
                        | TOK_LPAREN expr TOK_RPAREN                                {$$ = new ExprParen(getPos(), std::shared_ptr<Expr>($2));}
                        | TOK_LPAREN error TOK_RPAREN                               {}
                        | TOK_INTEGERCONSTANT                                       {$$ = new LitExpr<int>(getPos(), $1);}
                        | TOK_STRINGCONSTANT                                        {$$ = new LitExpr<std::string>(getPos(), std::string($1));}
                        | var                                                       {$$ = $1;}
                        | var TOK_LPAREN actual_params_list TOK_RPAREN              {$$ = new FunctionCallExpr(getPos(),
                                                                                          std::shared_ptr<Var>($1),
                                                                                          std::shared_ptr<ConstructList<Expr>>($3));}
                        | var TOK_LPAREN error TOK_RPAREN                           {}
var                     : TOK_IDENTIFIER var_aux                                    {$$ = new Var(getPos(), std::string($1), 
                                                                                                        std::shared_ptr<AccessOperation>($2));}
var_aux                 : /* empty */                                               {$$ = nullptr;} 
                        | TOK_DOT TOK_IDENTIFIER var_aux                            {$$ = new DotAccess(getPos(), std::string($2),
                                                                                                        std::shared_ptr<AccessOperation>($3));}
                        | TOK_LSQUARE expr_list_comma TOK_RSQUARE var_aux	    {$$ = new BracketAccess(getPos(),
                                                                                          std::shared_ptr<ConstructList<Expr>>($2),
                                                                                          std::shared_ptr<AccessOperation>($4));}
%%


Position getPos() {
    return Position{current_line, offset};
}

void yyerror(char *s) { 
    std::string parse_error = "parse error near " + get_token_name(yychar) + ", lexeme " + std::string(yytext);
    MJMessage::print(MJMessage::Type::ERROR, parse_error, Lexer::Position {current_line, offset});
}

int main() {
    return (yyparse());
}

int yywrap() {
    return 1;
}
