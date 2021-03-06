%{

#include <stdio.h>
#include <string>
#include "ast/Node.h"
#include "ast/Expr.h"
#include "MJMessage.h"
#include "y.tab.h"
#include "../src/code-generation/MJCodeGenerator.cpp"
#include "frames/Frame.h"
#include "frames/Param.h"

extern int current_line;
extern int offset;
extern char * yytext;
extern int yychar;
extern int yylex();

void yyerror(char *s);

Position getPos();
Position getPos(YYLTYPE);

std::shared_ptr<Program> root;

%}

%locations

%union {
    Var *var;
    Type *type;
    char * typeName;
    FormalParams *formalParams;
    VarInit *varInit;
    VarDeclId *varDeclId;
    ArrayInitVarInit *arrayInit;
    ArrayCreation* arrayCreation;
    AccessOperation *accessOp;
    ConstructList* constructList;
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
    MethodReturnType* methodReturnType;
    MethodDecl* methodDecl;
    Block* block;
    Decls* decls;
    FieldDecl* fieldDecl;
    FieldDeclVar *fieldDeclVar;
    Program* program;
    ClassDecl* classDecl;
    ClassBody* classBody;
}

%type <expr> expr
%type <var> var
%type <accessOp> var_aux
%type <constructList> expr_list_comma
%type <constructList> actual_params_list
%type <constructList> array_dim_decl_list
%type <constructList> stmt_list
%type <constructList> stmt_list_semicolon
%type <constructList> case_list
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
%type <arrayCreation> array_creation_expr
%type <type> type
%type <varInit> var_init
%type <constructList> var_init_list_comma
%type <arrayInit> array_init
%type <varDeclId> var_decl_id
%type <litInt> brackets_opt
%type <litString> type_aux
%type <constructList> formal_params_list_opt
%type <constructList> formal_params_list
%type <formalParams> formal_params
%type <constructList> id_list_comma
%type <methodReturnType> method_return_type
%type <methodDecl> method_decl
%type <block> block
%type <decls> decls
%type <decls> decls_opt
%type <fieldDecl> field_decl
%type <constructList> field_decl_list
%type <fieldDeclVar> field_decl_aux
%type <program> program
%type <constructList> class_decl_list
%type <classDecl> class_decl
%type <classBody> class_body
%type <constructList> method_decl_list
%type <constructList> field_decl_list_decls

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
<typeName> TOK_INT 11
<typeName> TOK_STRING 12
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
program                 : TOK_PROGRAM TOK_IDENTIFIER TOK_SEMICOLON class_decl_list  {$$ = new Program(getPos(@1), 
                                                                                std::make_shared<Id>(getPos(@2), $2),
			                                                                  std::shared_ptr<ConstructList>($4)); 
                                                                                    root = std::shared_ptr<Program>($$);}
class_decl_list         : class_decl                                                {std::deque<std::shared_ptr<Node>> classes;
			                                                             classes.push_front(std::shared_ptr<ClassDecl>($1));
                                                                                     $$ = new ConstructList(getPos(@1),classes);}
			| class_decl class_decl_list                                {auto lst = $2; lst->push_front(std::shared_ptr<ClassDecl>($1));$$=lst;}
class_decl              : TOK_CLASS TOK_IDENTIFIER class_body                       {$$ = new ClassDecl(getPos(@1), 
                                                                                        std::make_shared<Id>(getPos(@2), std::string($2)),
			                                                                  std::shared_ptr<ClassBody>($3));}
                        | TOK_CLASS error class_body                                {$$=nullptr;}
class_body              : TOK_LCURLY decls_opt method_decl_list TOK_RCURLY          {$$ = new ClassBody(getPos(@$), std::shared_ptr<Decls>($2),
			                                                                  std::shared_ptr<ConstructList>($3));}
                        | TOK_LCURLY error TOK_RCURLY                               {$$=nullptr;}
decls_opt               : /* empty */                                               {$$ = nullptr;}
			| decls                                                     {$$ = $1;}
decls                   : TOK_DECLARATIONS field_decl_list_decls TOK_ENDDECLARATIONS{$$ = new Decls(getPos(@1), 
                                                                                            std::shared_ptr<ConstructList>($2));}
                        | TOK_DECLARATIONS error TOK_ENDDECLARATIONS                                 {$$=nullptr;}
method_decl_list        : /* empty */                                               {$$ = nullptr;}
			| method_decl method_decl_list                              {$$=$2; std::deque<std::shared_ptr<Node>> methodDecls;
                                                                                     auto lst = $2 == nullptr
                                                                                              ? new ConstructList(getPos(@1), methodDecls)
                                                                                              : $2;
                                                                                     lst->push_front(std::shared_ptr<MethodDecl>($1));
                                                                                     $$ = lst;}
field_decl_list_decls   : /* empty */                                               {$$ = nullptr;}
			| field_decl TOK_SEMICOLON field_decl_list_decls            {$$=$3; std::deque<std::shared_ptr<Node>> fieldDecls;
                                                                                     auto lst = $3 == nullptr
                                                                                              ? new ConstructList(getPos(@1), fieldDecls)
                                                                                              : $3;
                                                                                     lst->push_front(std::shared_ptr<FieldDecl>($1));
                                                                                     $$ = lst;}
field_decl              : type field_decl_list                                      {$$ = new FieldDecl(getPos(@$), std::shared_ptr<Type>($1),
			                                                                  std::shared_ptr<ConstructList>($2));}
field_decl_aux          : var_decl_id                                               {$$ = new FieldDeclVar(getPos(@1),std::shared_ptr<VarDeclId>($1),
                                                                                        std::shared_ptr<VarInit>(nullptr));}
                        | var_decl_id TOK_EQUALS var_init                           {$$ = new FieldDeclVar(getPos(@1),std::shared_ptr<VarDeclId>($1),
                                                                                          std::shared_ptr<VarInit> ($3));}
field_decl_list         : field_decl_aux                                            {std::deque<std::shared_ptr<Node>> fieldDeclVars;
			                                                             fieldDeclVars.push_front(std::shared_ptr<FieldDeclVar>($1));
                                                                                     $$ = new ConstructList(getPos(@1),fieldDeclVars);}
                        | field_decl_aux TOK_COMMA field_decl_list                  {auto lst = $3; lst->push_front(std::shared_ptr<FieldDeclVar>($1));
                                                                                     $$ = lst;}
type                    : type_aux brackets_opt                                     {$$ = new Type(getPos(@1), $2, $1);}
type_aux                : TOK_IDENTIFIER                                            {$$ = $1;}
                        | TOK_INT                                                   {$$ = $1;}
                        | TOK_STRING                                                {$$ = $1;}
brackets_opt            : /* empty */                                               {$$ = 0;}
                        | TOK_LRSQUARE brackets_opt                                 {$$ = 1 + $2;}
method_decl             : TOK_METHOD method_return_type TOK_IDENTIFIER TOK_LPAREN formal_params_list_opt TOK_RPAREN block
			                                                            {$$ = new MethodDecl(getPos(@1), std::shared_ptr<MethodReturnType>($2),
                                                                                          std::make_shared<Id>(getPos(@3), std::string($3)), 
                                                                                          std::shared_ptr<ConstructList>($5),
                                                                                          std::shared_ptr<Block>($7));}
                        | TOK_METHOD method_return_type TOK_IDENTIFIER TOK_LPAREN error TOK_RPAREN block
                                                                                    {$$=nullptr;}
method_return_type      : TOK_VOID                                                  {$$ = new MethodReturnType(getPos(@1), std::shared_ptr<Type>(nullptr));}
                        | type                                                      {$$ = new MethodReturnType(getPos(@1), std::shared_ptr<Type>($1));}
formal_params           : TOK_VAL type id_list_comma                                {$$ = new FormalParams(getPos(@1), true, std::shared_ptr<Type>($2),
			                                                                  std::shared_ptr<ConstructList>($3));}
                        | type id_list_comma                                        {$$ = new FormalParams(getPos(@$), false, std::shared_ptr<Type>($1),
                                                                                          std::shared_ptr<ConstructList>($2));}
formal_params_list      : formal_params                                             {std::deque<std::shared_ptr<Node>> formalParams;
		                                                                     formalParams.push_front(std::shared_ptr<FormalParams>($1));
                                                                                     $$ = new ConstructList(getPos(@1),formalParams);}
                        | formal_params TOK_SEMICOLON formal_params_list            {auto lst = $3; lst->push_front(std::shared_ptr<FormalParams>($1));
                                                                                     $$ = lst;}
id_list_comma           : TOK_IDENTIFIER                                            {std::deque<std::shared_ptr<Node>> ids;
			                                                             ids.push_front(std::make_shared<Id>(getPos(@1), std::string($1)));
                                                                                     $$ = new ConstructList(getPos(@$),ids);}
                        | TOK_IDENTIFIER TOK_COMMA id_list_comma                    {auto lst = $3; 
                                                                                    lst->push_front(std::make_shared<Id>(getPos(@1), std::string($1)));
                                                                                     $$ = lst;}
formal_params_list_opt  : /* empty */                                               {$$ = nullptr;} 
                        | formal_params_list                                        {$$ = $1;}
var_decl_id             : TOK_IDENTIFIER brackets_opt                               {$$ = new VarDeclId(getPos(@$), 
                                                                                                        std::make_shared<Id>(getPos(@1), 
                                                                                                        std::string($1)), $2);}
var_init                : expr                                                      {$$ = new ExprVarInit(getPos(@1),std::shared_ptr<Expr>($1));}
                        | array_init                                                {$$ = $1;}
                        | array_creation_expr                                       {$$ = $1;}
array_init              : TOK_LCURLY var_init_list_comma TOK_RCURLY                 {$$ = new ArrayInitVarInit(getPos(@$),
			                                                                      std::shared_ptr<ConstructList>($2));}
                        | error TOK_RCURLY                               {$$=nullptr;}
var_init_list_comma     : var_init                                                  {std::deque<std::shared_ptr<Node>> varInits;
		                                                                     varInits.push_front(std::shared_ptr<VarInit>($1));
                                                                                     $$ = new ConstructList(getPos(@$),varInits);}
                        | var_init TOK_COMMA var_init_list_comma                    {auto lst = $3; lst->push_front(std::shared_ptr<VarInit>($1));
                                                                                     $$ = lst;}
array_creation_expr     : TOK_ARROBA type array_dim_decl_list                       {$$ = new ArrayCreation(getPos(@$), std::shared_ptr<Type>($2),
			                                                                      std::shared_ptr<ConstructList>($3));}
array_dim_decl_list     : TOK_LSQUARE expr TOK_RSQUARE                              {std::deque<std::shared_ptr<Node>> exprs;
			                                                             exprs.push_front(std::shared_ptr<Expr>($2));
                                                                                     $$ = new ConstructList(getPos(@$),exprs);}
                        | TOK_LSQUARE expr TOK_RSQUARE array_dim_decl_list          {auto lst = $4; lst->push_front(std::shared_ptr<Expr>($2));
                                                                                     $$ = lst;}
block                   : decls_opt stmt_list                                       {$$ = new Block(getPos(@$), std::shared_ptr<Decls>($1),
			                                                                       std::shared_ptr<ConstructList>($2));}
stmt_list               : TOK_LCURLY stmt_list_semicolon TOK_RCURLY                 {$$ = $2;}
                        | error TOK_RCURLY                               {$$=nullptr;}
stmt_list_semicolon     : stmt                                                      {std::deque<std::shared_ptr<Node>> stmts;
			                                                             stmts.push_front(std::shared_ptr<Stmt>($1));
                                                                                     $$ = new ConstructList(getPos(@$),stmts);}
                        | stmt TOK_SEMICOLON stmt_list_semicolon                    {$$=$3; auto lst = $3; lst->push_front(std::shared_ptr<Stmt>($1));
                                                                                     $$ = lst;}
stmt                    : var TOK_ASSIGN expr                                       {$$ = new AssignStmt(getPos(@$), std::shared_ptr<Var>($1),
			                                                                                 std::shared_ptr<Expr>($3));}
                        | var TOK_LPAREN actual_params_list TOK_RPAREN              {$$ = new FunctionCallStmt(getPos(@$), std::shared_ptr<Var>($1),
                                                                                                         std::shared_ptr<ConstructList>($3));}
                        | error TOK_RPAREN                           {$$=nullptr;}
                        | return_stmt                                               {$$ = $1;}
                        | if_stmt                                                   {$$ = $1;}
                        | while_stmt                                                {$$ = $1;} 
                        | for_stmt                                                  {$$ = $1;}
                        | switch_stmt                                               {$$ = $1;}
                        | print_stmt                                                {$$ = $1;}
                        | read_stmt                                                 {$$ = $1;}
actual_params_list      : /* empty */                                               {$$ = nullptr;}
                        | expr_list_comma                                           {$$ = $1;}
expr_list_comma         : expr                                                      {std::deque<std::shared_ptr<Node>> exps; 
                                                                                     exps.push_front(std::shared_ptr<Expr>($1));
                                                                                     $$ = new ConstructList(getPos(@1),exps);}
                        | expr TOK_COMMA expr_list_comma		            {$$=$3; auto lst = $3; lst->push_front(std::shared_ptr<Expr>($1));
                                                                                     $$ = lst;}
return_stmt             : TOK_RETURN                                                {$$ = new ReturnStmt(getPos(@1), std::shared_ptr<Expr>(nullptr));}
                        | TOK_RETURN expr                                           {$$ = new ReturnStmt(getPos(@1), std::shared_ptr<Expr>($2));}
if_stmt                 : TOK_IF expr stmt_list                                     {$$ = new IfStmt(getPos(@1), std::shared_ptr<Expr>($2),
			                                                                             std::shared_ptr<ConstructList>($3),
                                                                                                     nullptr);}
                        | TOK_IF expr stmt_list TOK_ELSE if_stmt                    {$$ = new IfStmt(getPos(@1), std::shared_ptr<Expr>($2),
                                                                                                     std::shared_ptr<ConstructList>($3),
                                                                                                     std::make_shared<ElseIf>(getPos(@4),
                                                                                                                std::shared_ptr<IfStmt>($5)));}
                        | TOK_IF expr stmt_list TOK_ELSE stmt_list                  {$$ = new IfStmt(getPos(@1), std::shared_ptr<Expr>($2),
                                                                                                     std::shared_ptr<ConstructList>($3),
                                                                                                     std::make_shared<Else>(getPos(@4),
                                                                                                       std::shared_ptr<ConstructList>($5)));}
for_stmt                : TOK_FOR TOK_IDENTIFIER TOK_ASSIGN expr TOK_TO expr TOK_STEP expr stmt_list
			                                                            {$$ = new ForStmt(getPos(@1), std::make_shared<Id>(getPos(@2), std::string($2)), 
                                                                                                    std::shared_ptr<Expr>($4),
                                                                                                      std::shared_ptr<Expr>($6),
                                                                                                      std::shared_ptr<Expr>($8),
                                                                                                      std::shared_ptr<ConstructList>($9));}
                        | TOK_FOR TOK_IDENTIFIER TOK_ASSIGN expr TOK_TO expr stmt_list
                                                                                    {$$ = new ForStmt(getPos(@1), 
                                                                                                    std::make_shared<Id>(getPos(@2), std::string($2)), 
                                                                                                    std::shared_ptr<Expr>($4),
                                                                                                      std::shared_ptr<Expr>($6), nullptr,
                                                                                                      std::shared_ptr<ConstructList>($7));}
while_stmt              : TOK_WHILE expr stmt_list                                  {$$ = new WhileStmt(getPos(@1), std::shared_ptr<Expr>($2),
			                                                                                std::shared_ptr<ConstructList>($3));}
switch_stmt             : TOK_SWITCH expr TOK_LCURLY case_list TOK_RCURLY           {$$ = new SwitchStmt(getPos(@1), std::shared_ptr<Expr>($2),
			                                                                             std::shared_ptr<ConstructList>($4),
                                                                                                     nullptr);}
                        | TOK_SWITCH expr TOK_LCURLY case_list TOK_DEFAULT stmt_list TOK_RCURLY
                                                                                    {$$ = new SwitchStmt(getPos(@1), std::shared_ptr<Expr>($2),
                                                                                                     std::shared_ptr<ConstructList>($4),
                                                                                                     std::shared_ptr<ConstructList>($6));}
                        | error TOK_LCURLY                               {$$=nullptr;}
case                    : TOK_CASE expr stmt_list                                   {$$ = new Case(getPos(@1), std::shared_ptr<Expr>($2),
			                                                                           std::shared_ptr<ConstructList>($3));}
                        | error stmt_list                                  {$$=nullptr;}
case_list               : case                                                      {std::deque<std::shared_ptr<Node>> cases;
			                                                                                     cases.push_front(std::shared_ptr<Case>($1));
                                                                                     $$ = new ConstructList(getPos(@1),cases);}
                        | case case_list                                            {$$=$2; auto lst = $2; lst->push_front(std::shared_ptr<Case>($1));
                                                                                     $$ = lst;}
print_stmt              : TOK_PRINT expr                                            {$$ = new PrintStmt(getPos(@1), std::shared_ptr<Expr>($2));}
read_stmt               : TOK_READ TOK_IDENTIFIER	                            {$$ = new ReadStmt(getPos(@1), 
                                                                                                    std::make_shared<Id>(getPos(@2), std::string($2)));}
expr                    : al_expr TOK_EQEQ al_expr                                  {$$ = new RelExpr(getPos(@2), RelExpr::RelOp::EQEQ,
                                                                                                        std::shared_ptr<AlExpr>($1),
                                                                                                        std::shared_ptr<AlExpr>($3));}
                        | al_expr TOK_LESS al_expr                                  {$$ = new RelExpr(getPos(@2), RelExpr::RelOp::LESS,
                                                                                                        std::shared_ptr<AlExpr>($1),
                                                                                                        std::shared_ptr<AlExpr>($3));}
                        | al_expr TOK_LESSEQ al_expr                                {$$ = new RelExpr(getPos(@2), RelExpr::RelOp::LESS_EQ,
                                                                                                        std::shared_ptr<AlExpr>($1),
                                                                                                        std::shared_ptr<AlExpr>($3));}
                        | al_expr TOK_GREATEREQ al_expr                             {$$ = new RelExpr(getPos(@2), RelExpr::RelOp::GREATER_EQ,
                                                                                                        std::shared_ptr<AlExpr>($1),
                                                                                                        std::shared_ptr<AlExpr>($3));}
                        | al_expr TOK_GREATER al_expr                               {$$ = new RelExpr(getPos(@2), RelExpr::RelOp::GREATER,
                                                                                                        std::shared_ptr<AlExpr>($1),
                                                                                                        std::shared_ptr<AlExpr>($3));}
                        | al_expr TOK_DIFF al_expr                                  {$$ = new RelExpr(getPos(@2), RelExpr::RelOp::DIFF,
                                                                                                        std::shared_ptr<AlExpr>($1),
                                                                                                        std::shared_ptr<AlExpr>($3));}
                        | al_expr                                                   {$$ = $1;}

al_expr                 : TOK_PLUS al_expr %prec TOK_UPLUS                          {$$ = new AlUnExpr(getPos(@1), AlUnExpr::AlUnOp::PLUS,
                                                                                                        std::shared_ptr<AlExpr>($2));}
                        | TOK_MINUS al_expr %prec TOK_UMINUS                        {$$ = new AlUnExpr(getPos(@1), AlUnExpr::AlUnOp::MINUS,
                                                                                                        std::shared_ptr<AlExpr>($2));}
                        | TOK_NOT al_expr                                           {$$ = new AlUnExpr(getPos(@1), AlUnExpr::AlUnOp::NOT,
                                                                                                        std::shared_ptr<AlExpr>($2));}    
                        | al_expr TOK_PLUS al_expr                                  {$$ = new AlBinExpr(getPos(@2), AlBinExpr::AlBinOp::PLUS,
                                                                                                        std::shared_ptr<AlExpr>($1),
                                                                                                        std::shared_ptr<AlExpr>($3));}
                        | al_expr TOK_MINUS al_expr                                 {$$ = new AlBinExpr(getPos(@2), AlBinExpr::AlBinOp::MINUS,
                                                                                                        std::shared_ptr<AlExpr>($1),
                                                                                                        std::shared_ptr<AlExpr>($3));}
                        | al_expr TOK_2PIPE al_expr                                 {$$ = new AlBinExpr(getPos(@2), AlBinExpr::AlBinOp::OR,
                                                                                                        std::shared_ptr<AlExpr>($1),
                                                                                                        std::shared_ptr<AlExpr>($3));}
                        | al_expr TOK_ASTERISK al_expr                              {$$ = new AlBinExpr(getPos(@2), AlBinExpr::AlBinOp::TIMES,
                                                                                                        std::shared_ptr<AlExpr>($1),
                                                                                                        std::shared_ptr<AlExpr>($3));}
                        | al_expr TOK_SLASH al_expr                                 {$$ = new AlBinExpr(getPos(@2), AlBinExpr::AlBinOp::DIV,
                                                                                                        std::shared_ptr<AlExpr>($1),
                                                                                                        std::shared_ptr<AlExpr>($3));}
                        | al_expr TOK_AND al_expr                                   {$$ = new AlBinExpr(getPos(@2), AlBinExpr::AlBinOp::AND,
                                                                                                        std::shared_ptr<AlExpr>($1),
                                                                                                        std::shared_ptr<AlExpr>($3));}
                        | al_expr TOK_MOD al_expr                                   {$$ = new AlBinExpr(getPos(@2), AlBinExpr::AlBinOp::MOD,
                                                                                                        std::shared_ptr<AlExpr>($1),
                                                                                                        std::shared_ptr<AlExpr>($3));}
                        | TOK_LPAREN expr TOK_RPAREN                                {$$ = new ExprParen(getPos(@1), std::shared_ptr<Expr>($2));}
                        | error TOK_RPAREN                               {$$=nullptr;}
                        | TOK_INTEGERCONSTANT                                       {$$ = new LitExpr<int>(getPos(@1), $1);}
                        | TOK_STRINGCONSTANT                                        {$$ = new LitExpr<std::string>(getPos(@1), std::string($1));}
                        | var                                                       {$$ = $1;}
                        | var TOK_LPAREN actual_params_list TOK_RPAREN              {$$ = new FunctionCallExpr(getPos(@2),
                                                                                          std::shared_ptr<Var>($1),
                                                                                          std::shared_ptr<ConstructList>($3));}
var                     : TOK_IDENTIFIER var_aux                                    {$$ = new Var(getPos(@$), 
                                                                                                        std::make_shared<Id>(getPos(@1), std::string($1)), 
                                                                                                        std::shared_ptr<AccessOperation>($2));}
var_aux                 : /* empty */                                               {$$ = nullptr;} 
                        | TOK_DOT TOK_IDENTIFIER var_aux                            {$$ = new DotAccess(getPos(@1), 
                                                                                                        std::make_shared<Id>(getPos(@2), std::string($2)),
                                                                                                        std::shared_ptr<AccessOperation>($3));}
                        | TOK_LSQUARE expr_list_comma TOK_RSQUARE var_aux	    {$$ = new BracketAccess(getPos(@1),
                                                                                          std::shared_ptr<ConstructList>($2),
                                                                                          std::shared_ptr<AccessOperation>($4));}
%%


Position getPos() {
    return Position{-1,-1};
}
Position getPos(YYLTYPE loc) {
    return Position{loc.first_line, loc.first_column};
}

void yyerror(char *s) { 
    std::string parse_error = "parse error near " + get_token_name(yychar) + ", lexeme " + std::string(yytext);
    MJMessage::print(MJMessage::Type::ERROR, parse_error, Lexer::Position {current_line, offset});
}


int main() {
    auto ret = yyparse();
    if (root != nullptr) {
        //root->computeLevel();
        //std::cout << root->print() << std::endl;
        generateCode(root);
    }
    return ret;
}


int yywrap() {
    return 1;
}
