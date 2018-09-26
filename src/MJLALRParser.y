%{

#include <stdio.h>

extern current_line;
extern offset;

void yyerror(char *s);

%}

%token TOK_PROGRAM TOK_IDENTIFIER TOK_SEMICOLON TOK_CLASS TOK_LCURLY TOK_RCURLY TOK_DECLARATIONS TOK_ENDDECLARATIONS TOK_EQUALS TOK_COMMA TOK_INT TOK_STRING TOK_LRSQUARE TOK_METHOD TOK_LPAREN TOK_RPAREN TOK_VOID TOK_VAL TOK_ARROBA TOK_LSQUARE TOK_RSQUARE TOK_ASSIGN TOK_RETURN TOK_IF TOK_ELSE TOK_FOR TOK_TO TOK_STEP TOK_WHILE TOK_SWITCH TOK_CASE TOK_DEFAULT TOK_PRINT TOK_READ TOK_LESS TOK_LESSEQ TOK_EQEQ TOK_DIFF TOK_GREATEREQ TOK_GREATER TOK_PLUS TOK_UPLUS TOK_MINUS TOK_UMINUS TOK_NOT TOK_2PIPE TOK_ASTERISK TOK_SLASH TOK_AND TOK_MOD TOK_INTEGERCONSTANT TOK_STRINGCONSTANT TOK_DOT

%start program

%nonassoc TOK_EQEQ TOK_DIFF
%left TOK_PLUS TOK_MINUS TOK_2PIPE
%left TOK_ASTERISK TOK_SLASH TOK_AND TOK_MOD
%left TOK_UMINUS TOK_UPLUS TOK_NOT

%%
program             : TOK_PROGRAM TOK_IDENTIFIER TOK_SEMICOLON class_decl class_decl_list
class_decl_list     : /* empty */ | class_decl class_decl_list
class_decl          : TOK_CLASS TOK_IDENTIFIER class_body
class_body          : TOK_LCURLY decls_opt method_decl_list TOK_RCURLY
decls_opt           : /* empty */ | decls 
decls               : TOK_DECLARATIONS field_decl_list_decls TOK_ENDDECLARATIONS
method_decl_list    : /* empty */ | method_decl method_decl_list 
field_decl_list_decls : /* empty */ | field_decl TOK_SEMICOLON field_decl_list_decls
field_decl          : type var_decl_id field_decl_aux1
field_decl_aux1     : field_decl_aux2 | TOK_EQUALS var_init field_decl_aux2
field_decl_aux2     : /* empty */ | TOK_COMMA var_decl_id field_decl_aux1
type                : type_aux brackets_opt
type_aux            : TOK_IDENTIFIER | TOK_INT | TOK_STRING
brackets_opt        : /* empty */ | TOK_LRSQUARE brackets_opt
method_decl         : TOK_METHOD method_return_type TOK_IDENTIFIER TOK_LPAREN formal_params_list_opt TOK_RPAREN block
method_return_type  : TOK_VOID | type
formal_params_list  : TOK_VAL type TOK_IDENTIFIER id_list_comma formal_params_list_aux
                    | type TOK_IDENTIFIER id_list_comma formal_params_list_aux
formal_params_list_aux : /* empty */ | TOK_SEMICOLON formal_params_list
id_list_comma       : /* empty */ | TOK_COMMA TOK_IDENTIFIER id_list_comma
formal_params_list_opt : /* empty */ | formal_params_list
var_decl_id         : TOK_IDENTIFIER brackets_opt
var_init            : expr | array_init | array_creation_expr
array_init          : TOK_LCURLY var_init var_init_list_comma TOK_RCURLY
var_init_list_comma : /* empty */ | TOK_COMMA var_init var_init_list_comma 
array_creation_expr : TOK_ARROBA type array_dim_decl array_dim_decl_list
array_dim_decl      : TOK_LSQUARE expr TOK_RSQUARE
array_dim_decl_list : /* empty */ | array_dim_decl array_dim_decl_list
block               : decls_opt stmt_list
stmt_list           : TOK_LCURLY stmt stmt_list_semicolon TOK_RCURLY
stmt_list_semicolon : /* empty */ | TOK_SEMICOLON stmt stmt_list_semicolon
stmt		    : var var_start_stmt | return_stmt| if_stmt
	  	    | while_stmt | for_stmt | switch_stmt | print_stmt
		    | read_stmt
var_start_stmt : assign_stmt | method_call_stmt
assign_stmt	    : TOK_ASSIGN expr
method_call_stmt    : TOK_LPAREN actual_params_list TOK_RPAREN
actual_params_list  : /* empty */ | expr expr_list_comma
expr_list_comma	    : /* empty */ | TOK_COMMA expr expr_list_comma		    
return_stmt	    : TOK_RETURN expr_opt
expr_opt	    : /* empty */ | expr
if_stmt		    : TOK_IF expr stmt_list else_part
else_part	    : /* empty */ | TOK_ELSE if_stmt_aux	     
if_stmt_aux	    : if_stmt | stmt_list
for_stmt	    : TOK_FOR for_init_expr TOK_TO expr step_opt stmt_list
for_init_expr	    : TOK_IDENTIFIER assign_stmt
step_opt	    : /* empty */ | TOK_STEP expr
while_stmt	    : TOK_WHILE expr stmt_list
switch_stmt	    : TOK_SWITCH expr TOK_LCURLY case case_list TOK_RCURLY
case		    : TOK_CASE expr stmt_list
case_list	    : /* empty */ | case case_list | TOK_DEFAULT stmt_list
print_stmt	    : TOK_PRINT expr
read_stmt	    : TOK_READ TOK_IDENTIFIER	      
expr                : al_expr TOK_EQEQ al_expr 
                    | al_expr TOK_LESS al_expr 
                    | al_expr TOK_LESSEQ al_expr 
                    | al_expr TOK_GREATEREQ al_expr 
                    | al_expr TOK_GREATER al_expr 
                    | al_expr TOK_DIFF al_expr 
                    | al_expr
al_expr             : TOK_PLUS al_expr %prec TOK_UPLUS 
                    | TOK_MINUS al_expr %prec TOK_UMINUS 
                    | TOK_NOT al_expr
                    | al_expr TOK_PLUS al_expr 
                    | al_expr TOK_MINUS al_expr
                    | al_expr TOK_2PIPE al_expr
                    | al_expr TOK_ASTERISK al_expr
                    | al_expr TOK_SLASH al_expr
                    | al_expr TOK_AND al_expr
                    | al_expr TOK_MOD al_expr
                    | TOK_LPAREN expr TOK_RPAREN
                    | TOK_INTEGERCONSTANT 
                    | TOK_STRINGCONSTANT
                    | var method_call_opt
method_call_opt     : /* empty */ | method_call_stmt
var		            : TOK_IDENTIFIER var_aux
var_aux		        : /* empty */ | TOK_DOT TOK_IDENTIFIER var_aux
    		        | TOK_LSQUARE expr expr_list_comma TOK_RSQUARE var_aux	     
%%

void yyerror(char *s) { 
    printf("[mjc error] (%d, %d)\n", current_line, offset); 
}

main() {
    return (yyparse());
}

yywrap() {
    return 1;
}
