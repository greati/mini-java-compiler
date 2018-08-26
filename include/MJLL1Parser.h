#include "Parser.h"
#include "MJNonterminal.h"
#include <map>
#include <vector>

class MJLL1Parser : public Parser {

    public:

        MJLL1Parser(Lexer * _lexer) : Parser{_lexer} {}

    protected:

        typedef std::pair<MJNonterminal, std::vector<int>> Production;

        std::map<MJNonterminal, std::set<MJToken>> follow =
        {
            { PROGRAM, {END_OF_FILE} },
            { CLASS_DECL_LIST, {END_OF_FILE} },
            { CLASS_DECL, {TOK_CLASS,END_OF_FILE} },
            { CLASS_BODY, {TOK_CLASS,END_OF_FILE} },
            { DECLS_OPT, {TOK_METHOD,TOK_RCURLY,TOK_LCURLY} },
            { DECLS, {TOK_METHOD,TOK_RCURLY,TOK_LCURLY} },
            { METHOD_DECL_LIST, {TOK_RCURLY} },
            { FIELD_DECL_LIST_DECLS, {TOK_ENDDECLARATIONS} },
            { FIELD_DECL, {TOK_SEMICOLON} },
            { FIELD_DECL_AUX1, {TOK_SEMICOLON} },
            { FIELD_DECL_AUX2, {TOK_SEMICOLON} },
            { TYPE, {TOK_IDENTIFIER,TOK_LSQUARE} },
            { TYPE_AUX, {TOK_LRSQUARE,TOK_IDENTIFIER,TOK_LSQUARE} },
            { BRACKETS_OPT, {TOK_IDENTIFIER,TOK_EQUALS,TOK_COMMA,TOK_SEMICOLON,TOK_LSQUARE} },
            { METHOD_DECL, {TOK_METHOD,TOK_RCURLY} },
            { METHOD_RETURN_TYPE, {TOK_IDENTIFIER} },
            { FORMAL_PARAMS_LIST, {TOK_RPAREN} },
            { FORMAL_PARAMS_LIST_AUX, {TOK_RPAREN} },
            { ID_LIST_COMMA, {TOK_SEMICOLON,TOK_RPAREN} },
            { FORMAL_PARAMS_LIST_OPT, {TOK_RPAREN} },
            { VAR_DECL_ID, {TOK_EQUALS,TOK_COMMA,TOK_SEMICOLON} },
            { VAR_INIT, {TOK_COMMA,TOK_SEMICOLON,TOK_RCURLY} },
            { ARRAY_INIT, {TOK_COMMA,TOK_SEMICOLON,TOK_RCURLY} },
            { VAR_INIT_LIST_COMMA, {TOK_RCURLY} },
            { ARRAY_CREATION_EXPR, {TOK_COMMA,TOK_SEMICOLON,TOK_RCURLY} },
            { ARRAY_DIM_DECL, {TOK_LSQUARE,TOK_COMMA,TOK_SEMICOLON,TOK_RCURLY} },
            { ARRAY_DIM_DECL_LIST, {TOK_COMMA,TOK_SEMICOLON,TOK_RCURLY} },
            { BLOCK, {TOK_METHOD,TOK_RCURLY} },
            { STMT_LIST, {TOK_METHOD,TOK_RCURLY,TOK_ELSE,TOK_SEMICOLON,TOK_DEFAULT,TOK_CASE} },
            { STMT_LIST_SEMICOLON, {TOK_RCURLY} },
            { STMT, {TOK_SEMICOLON,TOK_RCURLY} },
            { VARIABLE_START_STMT, {TOK_SEMICOLON,TOK_RCURLY} },
            { ASSIGN_STMT, {TOK_SEMICOLON,TOK_RCURLY,TOK_TO} },
            { METHOD_CALL_STMT, {TOK_SEMICOLON,TOK_RCURLY,TOK_ASTERISK,TOK_SLASH,TOK_AND,TOK_MOD,TOK_PLUS,TOK_MINUS,TOK_2PIPE,TOK_LESS,TOK_LESSEQ,TOK_EQEQ,TOK_DIFF,TOK_GREATEREQ,TOK_GREATER,TOK_COMMA,TOK_RSQUARE,TOK_RPAREN,TOK_LCURLY,TOK_STEP,TOK_TO} },
            { ACTUAL_PARAMS_LIST, {TOK_RPAREN} },
            { EXPRESSION_LIST_COMMA, {TOK_RPAREN,TOK_RSQUARE} },
            { RETURN_STMT, {TOK_SEMICOLON,TOK_RCURLY} },
            { EXPRESSION_OPT, {TOK_SEMICOLON,TOK_RCURLY} },
            { IF_STMT, {TOK_SEMICOLON,TOK_RCURLY} },
            { ELSE_PART, {TOK_SEMICOLON,TOK_RCURLY} },
            { IF_STMT_AUX, {TOK_SEMICOLON,TOK_RCURLY} },
            { FOR_STMT, {TOK_SEMICOLON,TOK_RCURLY} },
            { FOR_INIT_EXPR, {TOK_TO} },
            { STEP_OPT, {TOK_LCURLY} },
            { WHILE_STMT, {TOK_SEMICOLON,TOK_RCURLY} },
            { SWITCH_STMT, {TOK_SEMICOLON,TOK_RCURLY} },
            { CASE, {TOK_DEFAULT,TOK_CASE,TOK_RCURLY} },
            { CASE_LIST, {TOK_RCURLY} },
            { PRINT_STMT, {TOK_SEMICOLON,TOK_RCURLY} },
            { READ_STMT, {TOK_SEMICOLON,TOK_RCURLY} },
            { EXPRESSION, {TOK_COMMA,TOK_SEMICOLON,TOK_RSQUARE,TOK_RCURLY,TOK_RPAREN,TOK_LCURLY,TOK_STEP,TOK_TO} },
            { REL_EXPR, {TOK_COMMA,TOK_SEMICOLON,TOK_RSQUARE,TOK_RCURLY,TOK_RPAREN,TOK_LCURLY,TOK_STEP,TOK_TO} },
            { REL_EXPR_AUX, {TOK_COMMA,TOK_SEMICOLON,TOK_RSQUARE,TOK_RCURLY,TOK_RPAREN,TOK_LCURLY,TOK_STEP,TOK_TO} },
            { ADD_EXPR, {TOK_LESS,TOK_LESSEQ,TOK_EQEQ,TOK_DIFF,TOK_GREATEREQ,TOK_GREATER,TOK_COMMA,TOK_SEMICOLON,TOK_RSQUARE,TOK_RCURLY,TOK_RPAREN,TOK_LCURLY,TOK_STEP,TOK_TO} },
            { ADD_EXPR_AUX, {TOK_LESS,TOK_LESSEQ,TOK_EQEQ,TOK_DIFF,TOK_GREATEREQ,TOK_GREATER,TOK_COMMA,TOK_SEMICOLON,TOK_RSQUARE,TOK_RCURLY,TOK_RPAREN,TOK_LCURLY,TOK_STEP,TOK_TO} },
            { MULT_EXPR, {TOK_PLUS,TOK_MINUS,TOK_2PIPE,TOK_LESS,TOK_LESSEQ,TOK_EQEQ,TOK_DIFF,TOK_GREATEREQ,TOK_GREATER,TOK_COMMA,TOK_SEMICOLON,TOK_RSQUARE,TOK_RCURLY,TOK_RPAREN,TOK_LCURLY,TOK_STEP,TOK_TO} },
            { MULT_EXPR_AUX, {TOK_PLUS,TOK_MINUS,TOK_2PIPE,TOK_LESS,TOK_LESSEQ,TOK_EQEQ,TOK_DIFF,TOK_GREATEREQ,TOK_GREATER,TOK_COMMA,TOK_SEMICOLON,TOK_RSQUARE,TOK_RCURLY,TOK_RPAREN,TOK_LCURLY,TOK_STEP,TOK_TO} },
            { UNARY_EXPR, {TOK_ASTERISK,TOK_SLASH,TOK_AND,TOK_MOD,TOK_PLUS,TOK_MINUS,TOK_2PIPE,TOK_LESS,TOK_LESSEQ,TOK_EQEQ,TOK_DIFF,TOK_GREATEREQ,TOK_GREATER,TOK_COMMA,TOK_SEMICOLON,TOK_RSQUARE,TOK_RCURLY,TOK_RPAREN,TOK_LCURLY,TOK_STEP,TOK_TO} },
            { METHOD_CALL_OPT, {TOK_ASTERISK,TOK_SLASH,TOK_AND,TOK_MOD,TOK_PLUS,TOK_MINUS,TOK_2PIPE,TOK_LESS,TOK_LESSEQ,TOK_EQEQ,TOK_DIFF,TOK_GREATEREQ,TOK_GREATER,TOK_COMMA,TOK_SEMICOLON,TOK_RSQUARE,TOK_RCURLY,TOK_RPAREN,TOK_LCURLY,TOK_STEP,TOK_TO} },
            { REL_OP, {TOK_LPAREN,TOK_PLUS,TOK_MINUS,TOK_NOT,TOK_INTEGERCONSTANT,TOK_STRINGCONSTANT,TOK_IDENTIFIER} },
            { UNARY_OP, {TOK_LPAREN,TOK_PLUS,TOK_MINUS,TOK_NOT,TOK_INTEGERCONSTANT,TOK_STRINGCONSTANT,TOK_IDENTIFIER} },
            { ADD_OP, {TOK_LPAREN,TOK_PLUS,TOK_MINUS,TOK_NOT,TOK_INTEGERCONSTANT,TOK_STRINGCONSTANT,TOK_IDENTIFIER} },
            { MULT_OP, {TOK_LPAREN,TOK_PLUS,TOK_MINUS,TOK_NOT,TOK_INTEGERCONSTANT,TOK_STRINGCONSTANT,TOK_IDENTIFIER} },
            { UNSIG_LIT, {TOK_ASTERISK,TOK_SLASH,TOK_AND,TOK_MOD,TOK_PLUS,TOK_MINUS,TOK_2PIPE,TOK_LESS,TOK_LESSEQ,TOK_EQEQ,TOK_DIFF,TOK_GREATEREQ,TOK_GREATER,TOK_COMMA,TOK_SEMICOLON,TOK_RSQUARE,TOK_RCURLY,TOK_RPAREN,TOK_LCURLY,TOK_STEP,TOK_TO} },
            { VARIABLE, {TOK_ASSIGN,TOK_LPAREN,TOK_ASTERISK,TOK_SLASH,TOK_AND,TOK_MOD,TOK_PLUS,TOK_MINUS,TOK_2PIPE,TOK_LESS,TOK_LESSEQ,TOK_EQEQ,TOK_DIFF,TOK_GREATEREQ,TOK_GREATER,TOK_COMMA,TOK_SEMICOLON,TOK_RSQUARE,TOK_RCURLY,TOK_RPAREN,TOK_LCURLY,TOK_STEP,TOK_TO} },
            { VARIABLE_AUX, {TOK_ASSIGN,TOK_LPAREN,TOK_ASTERISK,TOK_SLASH,TOK_AND,TOK_MOD,TOK_PLUS,TOK_MINUS,TOK_2PIPE,TOK_LESS,TOK_LESSEQ,TOK_EQEQ,TOK_DIFF,TOK_GREATEREQ,TOK_GREATER,TOK_COMMA,TOK_SEMICOLON,TOK_RSQUARE,TOK_RCURLY,TOK_RPAREN,TOK_LCURLY,TOK_STEP,TOK_TO} }
        };

        std::map<int, Production> productions =
        {
            { 0, { PROGRAM, {TOK_PROGRAM,TOK_IDENTIFIER,TOK_SEMICOLON,CLASS_DECL,CLASS_DECL_LIST} } },
            { 1, { CLASS_DECL_LIST, {CLASS_DECL,CLASS_DECL_LIST} } },
            { 2, { CLASS_DECL_LIST, {} } },
            { 3, { CLASS_DECL, {TOK_CLASS,TOK_IDENTIFIER,CLASS_BODY} } },
            { 4, { CLASS_BODY, {TOK_LCURLY,DECLS_OPT,METHOD_DECL_LIST,TOK_RCURLY} } },
            { 5, { DECLS_OPT, {DECLS} } },
            { 6, { DECLS_OPT, {} } },
            { 7, { DECLS, {TOK_DECLARATIONS,FIELD_DECL_LIST_DECLS,TOK_ENDDECLARATIONS} } },
            { 8, { METHOD_DECL_LIST, {METHOD_DECL,METHOD_DECL_LIST} } },
            { 9, { METHOD_DECL_LIST, {} } },
            { 10, { FIELD_DECL_LIST_DECLS, {FIELD_DECL,TOK_SEMICOLON,FIELD_DECL_LIST_DECLS} } },
            { 11, { FIELD_DECL_LIST_DECLS, {} } },
            { 12, { FIELD_DECL, {TYPE,VAR_DECL_ID,FIELD_DECL_AUX1} } },
            { 13, { FIELD_DECL_AUX1, {FIELD_DECL_AUX2} } },
            { 14, { FIELD_DECL_AUX1, {TOK_EQUALS,VAR_INIT,FIELD_DECL_AUX2} } },
            { 15, { FIELD_DECL_AUX2, {TOK_COMMA,VAR_DECL_ID,FIELD_DECL_AUX1} } },
            { 16, { FIELD_DECL_AUX2, {} } },
            { 17, { TYPE, {TYPE_AUX,BRACKETS_OPT} } },
            { 18, { TYPE_AUX, {TOK_IDENTIFIER} } },
            { 19, { TYPE_AUX, {TOK_INT} } },
            { 20, { TYPE_AUX, {TOK_STRING} } },
            { 21, { BRACKETS_OPT, {TOK_LRSQUARE,BRACKETS_OPT} } },
            { 22, { BRACKETS_OPT, {} } },
            { 23, { METHOD_DECL, {TOK_METHOD,METHOD_RETURN_TYPE,TOK_IDENTIFIER,TOK_LPAREN,FORMAL_PARAMS_LIST_OPT,TOK_RPAREN,BLOCK} } },
            { 24, { METHOD_RETURN_TYPE, {TOK_VOID} } },
            { 25, { METHOD_RETURN_TYPE, {TYPE} } },
            { 26, { FORMAL_PARAMS_LIST, {TOK_VAL,TYPE,TOK_IDENTIFIER,ID_LIST_COMMA,FORMAL_PARAMS_LIST_AUX} } },
            { 27, { FORMAL_PARAMS_LIST, {TYPE,TOK_IDENTIFIER,ID_LIST_COMMA,FORMAL_PARAMS_LIST_AUX} } },
            { 28, { FORMAL_PARAMS_LIST_AUX, {TOK_SEMICOLON,FORMAL_PARAMS_LIST} } },
            { 29, { FORMAL_PARAMS_LIST_AUX, {} } },
            { 30, { ID_LIST_COMMA, {TOK_COMMA,TOK_IDENTIFIER,ID_LIST_COMMA} } },
            { 31, { ID_LIST_COMMA, {} } },
            { 32, { FORMAL_PARAMS_LIST_OPT, {FORMAL_PARAMS_LIST} } },
            { 33, { FORMAL_PARAMS_LIST_OPT, {} } },
            { 34, { VAR_DECL_ID, {TOK_IDENTIFIER,BRACKETS_OPT} } },
            { 35, { VAR_INIT, {EXPRESSION} } },
            { 36, { VAR_INIT, {ARRAY_INIT} } },
            { 37, { VAR_INIT, {ARRAY_CREATION_EXPR} } },
            { 38, { ARRAY_INIT, {TOK_LCURLY,VAR_INIT,VAR_INIT_LIST_COMMA,TOK_RCURLY} } },
            { 39, { VAR_INIT_LIST_COMMA, {TOK_COMMA,VAR_INIT,VAR_INIT_LIST_COMMA} } },
            { 40, { VAR_INIT_LIST_COMMA, {} } },
            { 41, { ARRAY_CREATION_EXPR, {TOK_ARROBA,TYPE,ARRAY_DIM_DECL,ARRAY_DIM_DECL_LIST} } },
            { 42, { ARRAY_DIM_DECL, {TOK_LSQUARE,EXPRESSION,TOK_RSQUARE} } },
            { 43, { ARRAY_DIM_DECL_LIST, {ARRAY_DIM_DECL,ARRAY_DIM_DECL_LIST} } },
            { 44, { ARRAY_DIM_DECL_LIST, {} } },
            { 45, { BLOCK, {DECLS_OPT,STMT_LIST} } },
            { 46, { STMT_LIST, {TOK_LCURLY,STMT,STMT_LIST_SEMICOLON,TOK_RCURLY} } },
            { 47, { STMT_LIST_SEMICOLON, {TOK_SEMICOLON,STMT,STMT_LIST_SEMICOLON} } },
            { 48, { STMT_LIST_SEMICOLON, {} } },
            { 49, { STMT, {VARIABLE,VARIABLE_START_STMT} } },
            { 50, { STMT, {RETURN_STMT} } },
            { 51, { STMT, {IF_STMT} } },
            { 52, { STMT, {WHILE_STMT} } },
            { 53, { STMT, {FOR_STMT} } },
            { 54, { STMT, {SWITCH_STMT} } },
            { 55, { STMT, {PRINT_STMT} } },
            { 56, { STMT, {READ_STMT} } },
            { 57, { VARIABLE_START_STMT, {ASSIGN_STMT} } },
            { 58, { VARIABLE_START_STMT, {METHOD_CALL_STMT} } },
            { 59, { ASSIGN_STMT, {TOK_ASSIGN,EXPRESSION} } },
            { 60, { METHOD_CALL_STMT, {TOK_LPAREN,ACTUAL_PARAMS_LIST,TOK_RPAREN} } },
            { 61, { ACTUAL_PARAMS_LIST, {EXPRESSION,EXPRESSION_LIST_COMMA} } },
            { 62, { ACTUAL_PARAMS_LIST, {} } },
            { 63, { EXPRESSION_LIST_COMMA, {TOK_COMMA,EXPRESSION,EXPRESSION_LIST_COMMA} } },
            { 64, { EXPRESSION_LIST_COMMA, {} } },
            { 65, { RETURN_STMT, {TOK_RETURN,EXPRESSION_OPT} } },
            { 66, { EXPRESSION_OPT, {EXPRESSION} } },
            { 67, { EXPRESSION_OPT, {} } },
            { 68, { IF_STMT, {TOK_IF,EXPRESSION,STMT_LIST,ELSE_PART} } },
            { 69, { ELSE_PART, {TOK_ELSE,IF_STMT_AUX} } },
            { 70, { ELSE_PART, {} } },
            { 71, { IF_STMT_AUX, {IF_STMT} } },
            { 72, { IF_STMT_AUX, {STMT_LIST} } },
            { 73, { FOR_STMT, {TOK_FOR,FOR_INIT_EXPR,TOK_TO,EXPRESSION,STEP_OPT,STMT_LIST} } },
            { 74, { FOR_INIT_EXPR, {TOK_IDENTIFIER,ASSIGN_STMT} } },
            { 75, { STEP_OPT, {TOK_STEP,EXPRESSION} } },
            { 76, { STEP_OPT, {} } },
            { 77, { WHILE_STMT, {TOK_WHILE,EXPRESSION,STMT_LIST} } },
            { 78, { SWITCH_STMT, {TOK_SWITCH,EXPRESSION,TOK_LCURLY,CASE,CASE_LIST,TOK_RCURLY} } },
            { 79, { CASE, {TOK_CASE,EXPRESSION,STMT_LIST} } },
            { 80, { CASE_LIST, {CASE,CASE_LIST} } },
            { 81, { CASE_LIST, {TOK_DEFAULT,STMT_LIST} } },
            { 82, { CASE_LIST, {} } },
            { 83, { PRINT_STMT, {TOK_PRINT,EXPRESSION} } },
            { 84, { READ_STMT, {TOK_READ,TOK_IDENTIFIER} } },
            { 85, { EXPRESSION, {REL_EXPR} } },
            { 86, { REL_EXPR, {ADD_EXPR,REL_EXPR_AUX} } },
            { 87, { REL_EXPR_AUX, {REL_OP,ADD_EXPR} } },
            { 88, { REL_EXPR_AUX, {} } },
            { 89, { ADD_EXPR, {MULT_EXPR,ADD_EXPR_AUX} } },
            { 90, { ADD_EXPR_AUX, {ADD_OP,MULT_EXPR,ADD_EXPR_AUX} } },
            { 91, { ADD_EXPR_AUX, {} } },
            { 92, { MULT_EXPR, {UNARY_EXPR,MULT_EXPR_AUX} } },
            { 93, { MULT_EXPR_AUX, {MULT_OP,UNARY_EXPR,MULT_EXPR_AUX} } },
            { 94, { MULT_EXPR_AUX, {} } },
            { 95, { UNARY_EXPR, {UNARY_OP,UNARY_EXPR} } },
            { 96, { UNARY_EXPR, {UNSIG_LIT} } },
            { 97, { UNARY_EXPR, {VARIABLE,METHOD_CALL_OPT} } },
            { 98, { UNARY_EXPR, {TOK_LPAREN,EXPRESSION,TOK_RPAREN} } },
            { 99, { METHOD_CALL_OPT, {METHOD_CALL_STMT} } },
            { 100, { METHOD_CALL_OPT, {} } },
            { 101, { REL_OP, {TOK_LESS} } },
            { 102, { REL_OP, {TOK_LESSEQ} } },
            { 103, { REL_OP, {TOK_EQEQ} } },
            { 104, { REL_OP, {TOK_DIFF} } },
            { 105, { REL_OP, {TOK_GREATEREQ} } },
            { 106, { REL_OP, {TOK_GREATER} } },
            { 107, { UNARY_OP, {TOK_PLUS} } },
            { 108, { UNARY_OP, {TOK_MINUS} } },
            { 109, { UNARY_OP, {TOK_NOT} } },
            { 110, { ADD_OP, {TOK_PLUS} } },
            { 111, { ADD_OP, {TOK_MINUS} } },
            { 112, { ADD_OP, {TOK_2PIPE} } },
            { 113, { MULT_OP, {TOK_ASTERISK} } },
            { 114, { MULT_OP, {TOK_SLASH} } },
            { 115, { MULT_OP, {TOK_AND} } },
            { 116, { MULT_OP, {TOK_MOD} } },
            { 117, { UNSIG_LIT, {TOK_INTEGERCONSTANT} } },
            { 118, { UNSIG_LIT, {TOK_STRINGCONSTANT} } },
            { 119, { VARIABLE, {TOK_IDENTIFIER,VARIABLE_AUX} } },
            { 120, { VARIABLE_AUX, {TOK_DOT,TOK_IDENTIFIER,VARIABLE_AUX} } },
            { 121, { VARIABLE_AUX, {} } },
            { 122, { VARIABLE_AUX, {TOK_LSQUARE,EXPRESSION,EXPRESSION_LIST_COMMA,TOK_RSQUARE,VARIABLE_AUX} } },
        }; 

        std::map<MJNonterminal, std::map<MJToken,int>> parse_table = 
        {
            { PROGRAM, { { TOK_PROGRAM, 0 } } },
            { CLASS_DECL_LIST, { { TOK_CLASS, 1 },{ END_OF_FILE, 2 } } },
            { CLASS_DECL, { { TOK_CLASS, 3 } } },
            { CLASS_BODY, { { TOK_LCURLY, 4 } } },
            { DECLS_OPT, { { TOK_LCURLY, 6 },{ TOK_RCURLY, 6 },{ TOK_DECLARATIONS, 5 },{ TOK_METHOD, 6 } } },
            { DECLS, { { TOK_DECLARATIONS, 7 } } },
            { METHOD_DECL_LIST, { { TOK_RCURLY, 9 },{ TOK_METHOD, 8 } } },
            { FIELD_DECL_LIST_DECLS, { { TOK_IDENTIFIER, 10 },{ TOK_ENDDECLARATIONS, 11 },{ TOK_INT, 10 },{ TOK_STRING, 10 } } },
            { FIELD_DECL, { { TOK_IDENTIFIER, 12 },{ TOK_INT, 12 },{ TOK_STRING, 12 } } },
            { FIELD_DECL_AUX1, { { TOK_SEMICOLON, 13 },{ TOK_EQUALS, 14 },{ TOK_COMMA, 13 } } },
            { FIELD_DECL_AUX2, { { TOK_SEMICOLON, 16 },{ TOK_COMMA, 15 } } },
            { TYPE, { { TOK_IDENTIFIER, 17 },{ TOK_INT, 17 },{ TOK_STRING, 17 } } },
            { TYPE_AUX, { { TOK_IDENTIFIER, 18 },{ TOK_INT, 19 },{ TOK_STRING, 20 } } },
            { BRACKETS_OPT, { { TOK_IDENTIFIER, 22 },{ TOK_SEMICOLON, 22 },{ TOK_EQUALS, 22 },{ TOK_COMMA, 22 },{ TOK_LRSQUARE, 21 },{ TOK_LSQUARE, 22 } } },
            { METHOD_DECL, { { TOK_METHOD, 23 } } },
            { METHOD_RETURN_TYPE, { { TOK_IDENTIFIER, 25 },{ TOK_INT, 25 },{ TOK_STRING, 25 },{ TOK_VOID, 24 } } },
            { FORMAL_PARAMS_LIST, { { TOK_IDENTIFIER, 27 },{ TOK_INT, 27 },{ TOK_STRING, 27 },{ TOK_VAL, 26 } } },
            { FORMAL_PARAMS_LIST_AUX, { { TOK_SEMICOLON, 28 },{ TOK_RPAREN, 29 } } },
            { ID_LIST_COMMA, { { TOK_SEMICOLON, 31 },{ TOK_COMMA, 30 },{ TOK_RPAREN, 31 } } },
            { FORMAL_PARAMS_LIST_OPT, { { TOK_IDENTIFIER, 32 },{ TOK_INT, 32 },{ TOK_STRING, 32 },{ TOK_RPAREN, 33 },{ TOK_VAL, 32 } } },
            { VAR_DECL_ID, { { TOK_IDENTIFIER, 34 } } },
            { VAR_INIT, { { TOK_IDENTIFIER, 35 },{ TOK_LCURLY, 36 },{ TOK_LPAREN, 35 },{ TOK_ARROBA, 37 },{ TOK_PLUS, 35 },{ TOK_MINUS, 35 },{ TOK_NOT, 35 },{ TOK_INTEGERCONSTANT, 35 },{ TOK_STRINGCONSTANT, 35 } } },
            { ARRAY_INIT, { { TOK_LCURLY, 38 } } },
            { VAR_INIT_LIST_COMMA, { { TOK_RCURLY, 40 },{ TOK_COMMA, 39 } } },
            { ARRAY_CREATION_EXPR, { { TOK_ARROBA, 41 } } },
            { ARRAY_DIM_DECL, { { TOK_LSQUARE, 42 } } },
            { ARRAY_DIM_DECL_LIST, { { TOK_SEMICOLON, 44 },{ TOK_RCURLY, 44 },{ TOK_COMMA, 44 },{ TOK_LSQUARE, 43 } } },
            { BLOCK, { { TOK_LCURLY, 45 },{ TOK_DECLARATIONS, 45 } } },
            { STMT_LIST, { { TOK_LCURLY, 46 } } },
            { STMT_LIST_SEMICOLON, { { TOK_SEMICOLON, 47 },{ TOK_RCURLY, 48 } } },
            { STMT, { { TOK_IDENTIFIER, 49 },{ TOK_RETURN, 50 },{ TOK_IF, 51 },{ TOK_FOR, 53 },{ TOK_WHILE, 52 },{ TOK_SWITCH, 54 },{ TOK_PRINT, 55 },{ TOK_READ, 56 } } },
            { VARIABLE_START_STMT, { { TOK_LPAREN, 58 },{ TOK_ASSIGN, 57 } } },
            { ASSIGN_STMT, { { TOK_ASSIGN, 59 } } },
            { METHOD_CALL_STMT, { { TOK_LPAREN, 60 } } },
            { ACTUAL_PARAMS_LIST, { { TOK_IDENTIFIER, 61 },{ TOK_LPAREN, 61 },{ TOK_RPAREN, 62 },{ TOK_PLUS, 61 },{ TOK_MINUS, 61 },{ TOK_NOT, 61 },{ TOK_INTEGERCONSTANT, 61 },{ TOK_STRINGCONSTANT, 61 } } },
            { EXPRESSION_LIST_COMMA, { { TOK_COMMA, 63 },{ TOK_RPAREN, 64 },{ TOK_RSQUARE, 64 } } },
            { RETURN_STMT, { { TOK_RETURN, 65 } } },
            { EXPRESSION_OPT, { { TOK_IDENTIFIER, 66 },{ TOK_SEMICOLON, 67 },{ TOK_RCURLY, 67 },{ TOK_LPAREN, 66 },{ TOK_PLUS, 66 },{ TOK_MINUS, 66 },{ TOK_NOT, 66 },{ TOK_INTEGERCONSTANT, 66 },{ TOK_STRINGCONSTANT, 66 } } },
            { IF_STMT, { { TOK_IF, 68 } } },
            { ELSE_PART, { { TOK_SEMICOLON, 70 },{ TOK_RCURLY, 70 },{ TOK_ELSE, 69 } } },
            { IF_STMT_AUX, { { TOK_LCURLY, 72 },{ TOK_IF, 71 } } },
            { FOR_STMT, { { TOK_FOR, 73 } } },
            { FOR_INIT_EXPR, { { TOK_IDENTIFIER, 74 } } },
            { STEP_OPT, { { TOK_LCURLY, 76 },{ TOK_STEP, 75 } } },
            { WHILE_STMT, { { TOK_WHILE, 77 } } },
            { SWITCH_STMT, { { TOK_SWITCH, 78 } } },
            { CASE, { { TOK_CASE, 79 } } },
            { CASE_LIST, { { TOK_RCURLY, 82 },{ TOK_CASE, 80 },{ TOK_DEFAULT, 81 } } },
            { PRINT_STMT, { { TOK_PRINT, 83 } } },
            { READ_STMT, { { TOK_READ, 84 } } },
            { EXPRESSION, { { TOK_IDENTIFIER, 85 },{ TOK_LPAREN, 85 },{ TOK_PLUS, 85 },{ TOK_MINUS, 85 },{ TOK_NOT, 85 },{ TOK_INTEGERCONSTANT, 85 },{ TOK_STRINGCONSTANT, 85 } } },
            { REL_EXPR, { { TOK_IDENTIFIER, 86 },{ TOK_LPAREN, 86 },{ TOK_PLUS, 86 },{ TOK_MINUS, 86 },{ TOK_NOT, 86 },{ TOK_INTEGERCONSTANT, 86 },{ TOK_STRINGCONSTANT, 86 } } },
            { REL_EXPR_AUX, { { TOK_SEMICOLON, 88 },{ TOK_LCURLY, 88 },{ TOK_RCURLY, 88 },{ TOK_COMMA, 88 },{ TOK_RPAREN, 88 },{ TOK_RSQUARE, 88 },{ TOK_TO, 88 },{ TOK_STEP, 88 },{ TOK_LESS, 87 },{ TOK_LESSEQ, 87 },{ TOK_EQEQ, 87 },{ TOK_DIFF, 87 },{ TOK_GREATEREQ, 87 },{ TOK_GREATER, 87 } } },
            { ADD_EXPR, { { TOK_IDENTIFIER, 89 },{ TOK_LPAREN, 89 },{ TOK_PLUS, 89 },{ TOK_MINUS, 89 },{ TOK_NOT, 89 },{ TOK_INTEGERCONSTANT, 89 },{ TOK_STRINGCONSTANT, 89 } } },
            { ADD_EXPR_AUX, { { TOK_SEMICOLON, 91 },{ TOK_LCURLY, 91 },{ TOK_RCURLY, 91 },{ TOK_COMMA, 91 },{ TOK_RPAREN, 91 },{ TOK_RSQUARE, 91 },{ TOK_TO, 91 },{ TOK_STEP, 91 },{ TOK_LESS, 91 },{ TOK_LESSEQ, 91 },{ TOK_EQEQ, 91 },{ TOK_DIFF, 91 },{ TOK_GREATEREQ, 91 },{ TOK_GREATER, 91 },{ TOK_PLUS, 90 },{ TOK_MINUS, 90 },{ TOK_2PIPE, 90 } } },
            { MULT_EXPR, { { TOK_IDENTIFIER, 92 },{ TOK_LPAREN, 92 },{ TOK_PLUS, 92 },{ TOK_MINUS, 92 },{ TOK_NOT, 92 },{ TOK_INTEGERCONSTANT, 92 },{ TOK_STRINGCONSTANT, 92 } } },
            { MULT_EXPR_AUX, { { TOK_SEMICOLON, 94 },{ TOK_LCURLY, 94 },{ TOK_RCURLY, 94 },{ TOK_COMMA, 94 },{ TOK_RPAREN, 94 },{ TOK_RSQUARE, 94 },{ TOK_TO, 94 },{ TOK_STEP, 94 },{ TOK_LESS, 94 },{ TOK_LESSEQ, 94 },{ TOK_EQEQ, 94 },{ TOK_DIFF, 94 },{ TOK_GREATEREQ, 94 },{ TOK_GREATER, 94 },{ TOK_PLUS, 94 },{ TOK_MINUS, 94 },{ TOK_2PIPE, 94 },{ TOK_ASTERISK, 93 },{ TOK_SLASH, 93 },{ TOK_AND, 93 },{ TOK_MOD, 93 } } },
            { UNARY_EXPR, { { TOK_IDENTIFIER, 97 },{ TOK_LPAREN, 98 },{ TOK_PLUS, 95 },{ TOK_MINUS, 95 },{ TOK_NOT, 95 },{ TOK_INTEGERCONSTANT, 96 },{ TOK_STRINGCONSTANT, 96 } } },
            { METHOD_CALL_OPT, { { TOK_SEMICOLON, 100 },{ TOK_LCURLY, 100 },{ TOK_RCURLY, 100 },{ TOK_COMMA, 100 },{ TOK_LPAREN, 99 },{ TOK_RPAREN, 100 },{ TOK_RSQUARE, 100 },{ TOK_TO, 100 },{ TOK_STEP, 100 },{ TOK_LESS, 100 },{ TOK_LESSEQ, 100 },{ TOK_EQEQ, 100 },{ TOK_DIFF, 100 },{ TOK_GREATEREQ, 100 },{ TOK_GREATER, 100 },{ TOK_PLUS, 100 },{ TOK_MINUS, 100 },{ TOK_2PIPE, 100 },{ TOK_ASTERISK, 100 },{ TOK_SLASH, 100 },{ TOK_AND, 100 },{ TOK_MOD, 100 } } },
            { REL_OP, { { TOK_LESS, 101 },{ TOK_LESSEQ, 102 },{ TOK_EQEQ, 103 },{ TOK_DIFF, 104 },{ TOK_GREATEREQ, 105 },{ TOK_GREATER, 106 } } },
            { UNARY_OP, { { TOK_PLUS, 107 },{ TOK_MINUS, 108 },{ TOK_NOT, 109 } } },
            { ADD_OP, { { TOK_PLUS, 110 },{ TOK_MINUS, 111 },{ TOK_2PIPE, 112 } } },
            { MULT_OP, { { TOK_ASTERISK, 113 },{ TOK_SLASH, 114 },{ TOK_AND, 115 },{ TOK_MOD, 116 } } },
            { UNSIG_LIT, { { TOK_INTEGERCONSTANT, 117 },{ TOK_STRINGCONSTANT, 118 } } },
            { VARIABLE, { { TOK_IDENTIFIER, 119 } } },
            { VARIABLE_AUX, { { TOK_SEMICOLON, 121 },{ TOK_LCURLY, 121 },{ TOK_RCURLY, 121 },{ TOK_COMMA, 121 },{ TOK_LPAREN, 121 },{ TOK_RPAREN, 121 },{ TOK_LSQUARE, 122 },{ TOK_RSQUARE, 121 },{ TOK_ASSIGN, 121 },{ TOK_TO, 121 },{ TOK_STEP, 121 },{ TOK_LESS, 121 },{ TOK_LESSEQ, 121 },{ TOK_EQEQ, 121 },{ TOK_DIFF, 121 },{ TOK_GREATEREQ, 121 },{ TOK_GREATER, 121 },{ TOK_PLUS, 121 },{ TOK_MINUS, 121 },{ TOK_2PIPE, 121 },{ TOK_ASTERISK, 121 },{ TOK_SLASH, 121 },{ TOK_AND, 121 },{ TOK_MOD, 121 },{ TOK_DOT, 120 } } }
        };

        /**
         * Skip until a token in the follow set is reached.
         *
         * @param nonterm nonterm to consider the follow from
         * */
        inline void skip_to_follow(MJNonterminal nonterm) {
            auto follow_set = follow[nonterm];
            while (follow_set.find(this->lexer->current_token()) == follow_set.end()) 
                this->lexer->next_token();
        }

        inline void parse_error(MJNonterminal nonterm) {
            this->parse_error();
            this->skip_to_follow(nonterm); 
        }

        inline void parse_error() {
            std::cout << "[mjc error] " << 
                "(" << this->lexer->current_position().row << "," <<
                this->lexer->current_position().col << ")" 
                << " parse error: unexpected " << get_token_name(lexer->current_token()) 
                << ", expecting " << expected_tokens_string()
                << std::endl;
            this->expected_tokens.clear();
        }

};
