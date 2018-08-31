#ifndef __MJLL1PARSER__
#define __MJLL1PARSER__

#include "Parser.h"
#include "MJNonterminal.h"
#include <map>
#include <vector>
#include <memory>

class MJLL1Parser : public Parser {

    public:

        MJLL1Parser(std::shared_ptr<Lexer>_lexer) : Parser{_lexer} {}

    protected:

        typedef std::pair<MJNonterminal, std::vector<int>> Production;

        std::map<MJNonterminal, std::set<MJToken>> first =
        {
            { PROGRAM, {TOK_PROGRAM} },
            { CLASS_DECL_LIST, {LAMBDA,TOK_CLASS} },
            { CLASS_DECL, {TOK_CLASS} },
            { CLASS_BODY, {TOK_LCURLY} },
            { DECLS_OPT, {LAMBDA,TOK_DECLARATIONS} },
            { DECLS, {TOK_DECLARATIONS} },
            { METHOD_DECL_LIST, {LAMBDA,TOK_METHOD} },
            { FIELD_DECL_LIST_DECLS, {LAMBDA,TOK_IDENTIFIER,TOK_INT,TOK_STRING} },
            { FIELD_DECL, {TOK_IDENTIFIER,TOK_INT,TOK_STRING} },
            { FIELD_DECL_AUX1, {TOK_EQUALS,TOK_COMMA,LAMBDA} },
            { FIELD_DECL_AUX2, {TOK_COMMA,LAMBDA} },
            { TYPE, {TOK_IDENTIFIER,TOK_INT,TOK_STRING} },
            { TYPE_AUX, {TOK_IDENTIFIER,TOK_INT,TOK_STRING} },
            { BRACKETS_OPT, {TOK_LRSQUARE,LAMBDA} },
            { METHOD_DECL, {TOK_METHOD} },
            { METHOD_RETURN_TYPE, {TOK_VOID,TOK_IDENTIFIER,TOK_INT,TOK_STRING} },
            { FORMAL_PARAMS_LIST, {TOK_VAL,TOK_IDENTIFIER,TOK_INT,TOK_STRING} },
            { VAL_OPT, {TOK_VAL,LAMBDA} },
            { FORMAL_PARAMS_LIST_AUX, {TOK_SEMICOLON,LAMBDA} },
            { ID_LIST_COMMA, {TOK_COMMA,LAMBDA} },
            { FORMAL_PARAMS_LIST_OPT, {LAMBDA,TOK_VAL,TOK_IDENTIFIER,TOK_INT,TOK_STRING} },
            { VAR_DECL_ID, {TOK_IDENTIFIER} },
            { VAR_INIT, {TOK_LCURLY,TOK_ARROBA,TOK_LPAREN,TOK_PLUS,TOK_MINUS,TOK_NOT,TOK_INTEGERCONSTANT,TOK_STRINGCONSTANT,TOK_IDENTIFIER} },
            { ARRAY_INIT, {TOK_LCURLY} },
            { VAR_INIT_LIST_COMMA, {TOK_COMMA,LAMBDA} },
            { ARRAY_CREATION_EXPR, {TOK_ARROBA} },
            { ARRAY_DIM_DECL, {TOK_LSQUARE} },
            { ARRAY_DIM_DECL_LIST, {LAMBDA,TOK_LSQUARE} },
            { BLOCK, {TOK_DECLARATIONS,TOK_LCURLY} },
            { STMT_LIST, {TOK_LCURLY} },
            { STMT_LIST_SEMICOLON, {TOK_SEMICOLON,LAMBDA} },
            { STMT, {TOK_IDENTIFIER,TOK_RETURN,TOK_IF,TOK_WHILE,TOK_FOR,TOK_SWITCH,TOK_PRINT,TOK_READ} },
            { VARIABLE_START_STMT, {TOK_ASSIGN,TOK_LPAREN} },
            { ASSIGN_STMT, {TOK_ASSIGN} },
            { METHOD_CALL_STMT, {TOK_LPAREN} },
            { ACTUAL_PARAMS_LIST, {LAMBDA,TOK_LPAREN,TOK_PLUS,TOK_MINUS,TOK_NOT,TOK_INTEGERCONSTANT,TOK_STRINGCONSTANT,TOK_IDENTIFIER} },
            { EXPRESSION_LIST_COMMA, {TOK_COMMA,LAMBDA} },
            { RETURN_STMT, {TOK_RETURN} },
            { EXPRESSION_OPT, {LAMBDA,TOK_LPAREN,TOK_PLUS,TOK_MINUS,TOK_NOT,TOK_INTEGERCONSTANT,TOK_STRINGCONSTANT,TOK_IDENTIFIER} },
            { IF_STMT, {TOK_IF} },
            { ELSE_PART, {TOK_ELSE,LAMBDA} },
            { IF_STMT_AUX, {TOK_IF,TOK_LCURLY} },
            { FOR_STMT, {TOK_FOR} },
            { FOR_INIT_EXPR, {TOK_IDENTIFIER} },
            { STEP_OPT, {TOK_STEP,LAMBDA} },
            { WHILE_STMT, {TOK_WHILE} },
            { SWITCH_STMT, {TOK_SWITCH} },
            { CASE, {TOK_CASE} },
            { CASE_LIST, {TOK_DEFAULT,LAMBDA,TOK_CASE} },
            { PRINT_STMT, {TOK_PRINT} },
            { READ_STMT, {TOK_READ} },
            { EXPRESSION, {TOK_LPAREN,TOK_PLUS,TOK_MINUS,TOK_NOT,TOK_INTEGERCONSTANT,TOK_STRINGCONSTANT,TOK_IDENTIFIER} },
            { REL_EXPR, {TOK_LPAREN,TOK_PLUS,TOK_MINUS,TOK_NOT,TOK_INTEGERCONSTANT,TOK_STRINGCONSTANT,TOK_IDENTIFIER} },
            { REL_EXPR_AUX, {LAMBDA,TOK_LESS,TOK_LESSEQ,TOK_EQEQ,TOK_DIFF,TOK_GREATEREQ,TOK_GREATER} },
            { ADD_EXPR, {TOK_LPAREN,TOK_PLUS,TOK_MINUS,TOK_NOT,TOK_INTEGERCONSTANT,TOK_STRINGCONSTANT,TOK_IDENTIFIER} },
            { ADD_EXPR_AUX, {LAMBDA,TOK_PLUS,TOK_MINUS,TOK_2PIPE} },
            { MULT_EXPR, {TOK_LPAREN,TOK_PLUS,TOK_MINUS,TOK_NOT,TOK_INTEGERCONSTANT,TOK_STRINGCONSTANT,TOK_IDENTIFIER} },
            { MULT_EXPR_AUX, {LAMBDA,TOK_ASTERISK,TOK_SLASH,TOK_AND,TOK_MOD} },
            { UNARY_EXPR, {TOK_LPAREN,TOK_PLUS,TOK_MINUS,TOK_NOT,TOK_INTEGERCONSTANT,TOK_STRINGCONSTANT,TOK_IDENTIFIER} },
            { METHOD_CALL_OPT, {LAMBDA,TOK_LPAREN} },
            { REL_OP, {TOK_LESS,TOK_LESSEQ,TOK_EQEQ,TOK_DIFF,TOK_GREATEREQ,TOK_GREATER} },
            { UNARY_OP, {TOK_PLUS,TOK_MINUS,TOK_NOT} },
            { ADD_OP, {TOK_PLUS,TOK_MINUS,TOK_2PIPE} },
            { MULT_OP, {TOK_ASTERISK,TOK_SLASH,TOK_AND,TOK_MOD} },
            { UNSIG_LIT, {TOK_INTEGERCONSTANT,TOK_STRINGCONSTANT} },
            { VARIABLE, {TOK_IDENTIFIER} },
            { VARIABLE_AUX, {TOK_DOT,LAMBDA,TOK_LSQUARE} }
        };

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
            { VAL_OPT, {TOK_IDENTIFIER,TOK_INT,TOK_STRING} },
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
            { 26, { FORMAL_PARAMS_LIST, {VAL_OPT,TYPE,TOK_IDENTIFIER,ID_LIST_COMMA,FORMAL_PARAMS_LIST_AUX} } },
            { 27, { VAL_OPT, {TOK_VAL} } },
            { 28, { VAL_OPT, {} } },
            { 29, { FORMAL_PARAMS_LIST_AUX, {TOK_SEMICOLON,FORMAL_PARAMS_LIST} } },
            { 30, { FORMAL_PARAMS_LIST_AUX, {} } },
            { 31, { ID_LIST_COMMA, {TOK_COMMA,TOK_IDENTIFIER,ID_LIST_COMMA} } },
            { 32, { ID_LIST_COMMA, {} } },
            { 33, { FORMAL_PARAMS_LIST_OPT, {FORMAL_PARAMS_LIST} } },
            { 34, { FORMAL_PARAMS_LIST_OPT, {} } },
            { 35, { VAR_DECL_ID, {TOK_IDENTIFIER,BRACKETS_OPT} } },
            { 36, { VAR_INIT, {EXPRESSION} } },
            { 37, { VAR_INIT, {ARRAY_INIT} } },
            { 38, { VAR_INIT, {ARRAY_CREATION_EXPR} } },
            { 39, { ARRAY_INIT, {TOK_LCURLY,VAR_INIT,VAR_INIT_LIST_COMMA,TOK_RCURLY} } },
            { 40, { VAR_INIT_LIST_COMMA, {TOK_COMMA,VAR_INIT,VAR_INIT_LIST_COMMA} } },
            { 41, { VAR_INIT_LIST_COMMA, {} } },
            { 42, { ARRAY_CREATION_EXPR, {TOK_ARROBA,TYPE,ARRAY_DIM_DECL,ARRAY_DIM_DECL_LIST} } },
            { 43, { ARRAY_DIM_DECL, {TOK_LSQUARE,EXPRESSION,TOK_RSQUARE} } },
            { 44, { ARRAY_DIM_DECL_LIST, {ARRAY_DIM_DECL,ARRAY_DIM_DECL_LIST} } },
            { 45, { ARRAY_DIM_DECL_LIST, {} } },
            { 46, { BLOCK, {DECLS_OPT,STMT_LIST} } },
            { 47, { STMT_LIST, {TOK_LCURLY,STMT,STMT_LIST_SEMICOLON,TOK_RCURLY} } },
            { 48, { STMT_LIST_SEMICOLON, {TOK_SEMICOLON,STMT,STMT_LIST_SEMICOLON} } },
            { 49, { STMT_LIST_SEMICOLON, {} } },
            { 50, { STMT, {VARIABLE,VARIABLE_START_STMT} } },
            { 51, { STMT, {RETURN_STMT} } },
            { 52, { STMT, {IF_STMT} } },
            { 53, { STMT, {WHILE_STMT} } },
            { 54, { STMT, {FOR_STMT} } },
            { 55, { STMT, {SWITCH_STMT} } },
            { 56, { STMT, {PRINT_STMT} } },
            { 57, { STMT, {READ_STMT} } },
            { 58, { VARIABLE_START_STMT, {ASSIGN_STMT} } },
            { 59, { VARIABLE_START_STMT, {METHOD_CALL_STMT} } },
            { 60, { ASSIGN_STMT, {TOK_ASSIGN,EXPRESSION} } },
            { 61, { METHOD_CALL_STMT, {TOK_LPAREN,ACTUAL_PARAMS_LIST,TOK_RPAREN} } },
            { 62, { ACTUAL_PARAMS_LIST, {EXPRESSION,EXPRESSION_LIST_COMMA} } },
            { 63, { ACTUAL_PARAMS_LIST, {} } },
            { 64, { EXPRESSION_LIST_COMMA, {TOK_COMMA,EXPRESSION,EXPRESSION_LIST_COMMA} } },
            { 65, { EXPRESSION_LIST_COMMA, {} } },
            { 66, { RETURN_STMT, {TOK_RETURN,EXPRESSION_OPT} } },
            { 67, { EXPRESSION_OPT, {EXPRESSION} } },
            { 68, { EXPRESSION_OPT, {} } },
            { 69, { IF_STMT, {TOK_IF,EXPRESSION,STMT_LIST,ELSE_PART} } },
            { 70, { ELSE_PART, {TOK_ELSE,IF_STMT_AUX} } },
            { 71, { ELSE_PART, {} } },
            { 72, { IF_STMT_AUX, {IF_STMT} } },
            { 73, { IF_STMT_AUX, {STMT_LIST} } },
            { 74, { FOR_STMT, {TOK_FOR,FOR_INIT_EXPR,TOK_TO,EXPRESSION,STEP_OPT,STMT_LIST} } },
            { 75, { FOR_INIT_EXPR, {TOK_IDENTIFIER,ASSIGN_STMT} } },
            { 76, { STEP_OPT, {TOK_STEP,EXPRESSION} } },
            { 77, { STEP_OPT, {} } },
            { 78, { WHILE_STMT, {TOK_WHILE,EXPRESSION,STMT_LIST} } },
            { 79, { SWITCH_STMT, {TOK_SWITCH,EXPRESSION,TOK_LCURLY,CASE,CASE_LIST,TOK_RCURLY} } },
            { 80, { CASE, {TOK_CASE,EXPRESSION,STMT_LIST} } },
            { 81, { CASE_LIST, {CASE,CASE_LIST} } },
            { 82, { CASE_LIST, {TOK_DEFAULT,STMT_LIST} } },
            { 83, { CASE_LIST, {} } },
            { 84, { PRINT_STMT, {TOK_PRINT,EXPRESSION} } },
            { 85, { READ_STMT, {TOK_READ,TOK_IDENTIFIER} } },
            { 86, { EXPRESSION, {REL_EXPR} } },
            { 87, { REL_EXPR, {ADD_EXPR,REL_EXPR_AUX} } },
            { 88, { REL_EXPR_AUX, {REL_OP,ADD_EXPR} } },
            { 89, { REL_EXPR_AUX, {} } },
            { 90, { ADD_EXPR, {MULT_EXPR,ADD_EXPR_AUX} } },
            { 91, { ADD_EXPR_AUX, {ADD_OP,MULT_EXPR,ADD_EXPR_AUX} } },
            { 92, { ADD_EXPR_AUX, {} } },
            { 93, { MULT_EXPR, {UNARY_EXPR,MULT_EXPR_AUX} } },
            { 94, { MULT_EXPR_AUX, {MULT_OP,UNARY_EXPR,MULT_EXPR_AUX} } },
            { 95, { MULT_EXPR_AUX, {} } },
            { 96, { UNARY_EXPR, {UNARY_OP,UNARY_EXPR} } },
            { 97, { UNARY_EXPR, {UNSIG_LIT} } },
            { 98, { UNARY_EXPR, {VARIABLE,METHOD_CALL_OPT} } },
            { 99, { UNARY_EXPR, {TOK_LPAREN,EXPRESSION,TOK_RPAREN} } },
            { 100, { METHOD_CALL_OPT, {METHOD_CALL_STMT} } },
            { 101, { METHOD_CALL_OPT, {} } },
            { 102, { REL_OP, {TOK_LESS} } },
            { 103, { REL_OP, {TOK_LESSEQ} } },
            { 104, { REL_OP, {TOK_EQEQ} } },
            { 105, { REL_OP, {TOK_DIFF} } },
            { 106, { REL_OP, {TOK_GREATEREQ} } },
            { 107, { REL_OP, {TOK_GREATER} } },
            { 108, { UNARY_OP, {TOK_PLUS} } },
            { 109, { UNARY_OP, {TOK_MINUS} } },
            { 110, { UNARY_OP, {TOK_NOT} } },
            { 111, { ADD_OP, {TOK_PLUS} } },
            { 112, { ADD_OP, {TOK_MINUS} } },
            { 113, { ADD_OP, {TOK_2PIPE} } },
            { 114, { MULT_OP, {TOK_ASTERISK} } },
            { 115, { MULT_OP, {TOK_SLASH} } },
            { 116, { MULT_OP, {TOK_AND} } },
            { 117, { MULT_OP, {TOK_MOD} } },
            { 118, { UNSIG_LIT, {TOK_INTEGERCONSTANT} } },
            { 119, { UNSIG_LIT, {TOK_STRINGCONSTANT} } },
            { 120, { VARIABLE, {TOK_IDENTIFIER,VARIABLE_AUX} } },
            { 121, { VARIABLE_AUX, {TOK_DOT,TOK_IDENTIFIER,VARIABLE_AUX} } },
            { 122, { VARIABLE_AUX, {} } },
            { 123, { VARIABLE_AUX, {TOK_LSQUARE,EXPRESSION,EXPRESSION_LIST_COMMA,TOK_RSQUARE,VARIABLE_AUX} } }
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
            { FORMAL_PARAMS_LIST, { { TOK_IDENTIFIER, 26 },{ TOK_INT, 26 },{ TOK_STRING, 26 },{ TOK_VAL, 26 } } },
            { VAL_OPT, { { TOK_IDENTIFIER, 28 },{ TOK_INT, 28 },{ TOK_STRING, 28 },{ TOK_VAL, 27 } } },
            { FORMAL_PARAMS_LIST_AUX, { { TOK_SEMICOLON, 29 },{ TOK_RPAREN, 30 } } },
            { ID_LIST_COMMA, { { TOK_SEMICOLON, 32 },{ TOK_COMMA, 31 },{ TOK_RPAREN, 32 } } },
            { FORMAL_PARAMS_LIST_OPT, { { TOK_IDENTIFIER, 33 },{ TOK_INT, 33 },{ TOK_STRING, 33 },{ TOK_RPAREN, 34 },{ TOK_VAL, 33 } } },
            { VAR_DECL_ID, { { TOK_IDENTIFIER, 35 } } },
            { VAR_INIT, { { TOK_IDENTIFIER, 36 },{ TOK_LCURLY, 37 },{ TOK_LPAREN, 36 },{ TOK_ARROBA, 38 },{ TOK_PLUS, 36 },{ TOK_MINUS, 36 },{ TOK_NOT, 36 },{ TOK_INTEGERCONSTANT, 36 },{ TOK_STRINGCONSTANT, 36 } } },
            { ARRAY_INIT, { { TOK_LCURLY, 39 } } },
            { VAR_INIT_LIST_COMMA, { { TOK_RCURLY, 41 },{ TOK_COMMA, 40 } } },
            { ARRAY_CREATION_EXPR, { { TOK_ARROBA, 42 } } },
            { ARRAY_DIM_DECL, { { TOK_LSQUARE, 43 } } },
            { ARRAY_DIM_DECL_LIST, { { TOK_SEMICOLON, 45 },{ TOK_RCURLY, 45 },{ TOK_COMMA, 45 },{ TOK_LSQUARE, 44 } } },
            { BLOCK, { { TOK_LCURLY, 46 },{ TOK_DECLARATIONS, 46 } } },
            { STMT_LIST, { { TOK_LCURLY, 47 } } },
            { STMT_LIST_SEMICOLON, { { TOK_SEMICOLON, 48 },{ TOK_RCURLY, 49 } } },
            { STMT, { { TOK_IDENTIFIER, 50 },{ TOK_RETURN, 51 },{ TOK_IF, 52 },{ TOK_FOR, 54 },{ TOK_WHILE, 53 },{ TOK_SWITCH, 55 },{ TOK_PRINT, 56 },{ TOK_READ, 57 } } },
            { VARIABLE_START_STMT, { { TOK_LPAREN, 59 },{ TOK_ASSIGN, 58 } } },
            { ASSIGN_STMT, { { TOK_ASSIGN, 60 } } },
            { METHOD_CALL_STMT, { { TOK_LPAREN, 61 } } },
            { ACTUAL_PARAMS_LIST, { { TOK_IDENTIFIER, 62 },{ TOK_LPAREN, 62 },{ TOK_RPAREN, 63 },{ TOK_PLUS, 62 },{ TOK_MINUS, 62 },{ TOK_NOT, 62 },{ TOK_INTEGERCONSTANT, 62 },{ TOK_STRINGCONSTANT, 62 } } },
            { EXPRESSION_LIST_COMMA, { { TOK_COMMA, 64 },{ TOK_RPAREN, 65 },{ TOK_RSQUARE, 65 } } },
            { RETURN_STMT, { { TOK_RETURN, 66 } } },
            { EXPRESSION_OPT, { { TOK_IDENTIFIER, 67 },{ TOK_SEMICOLON, 68 },{ TOK_RCURLY, 68 },{ TOK_LPAREN, 67 },{ TOK_PLUS, 67 },{ TOK_MINUS, 67 },{ TOK_NOT, 67 },{ TOK_INTEGERCONSTANT, 67 },{ TOK_STRINGCONSTANT, 67 } } },
            { IF_STMT, { { TOK_IF, 69 } } },
            { ELSE_PART, { { TOK_SEMICOLON, 71 },{ TOK_RCURLY, 71 },{ TOK_ELSE, 70 } } },
            { IF_STMT_AUX, { { TOK_LCURLY, 73 },{ TOK_IF, 72 } } },
            { FOR_STMT, { { TOK_FOR, 74 } } },
            { FOR_INIT_EXPR, { { TOK_IDENTIFIER, 75 } } },
            { STEP_OPT, { { TOK_LCURLY, 77 },{ TOK_STEP, 76 } } },
            { WHILE_STMT, { { TOK_WHILE, 78 } } },
            { SWITCH_STMT, { { TOK_SWITCH, 79 } } },
            { CASE, { { TOK_CASE, 80 } } },
            { CASE_LIST, { { TOK_RCURLY, 83 },{ TOK_CASE, 81 },{ TOK_DEFAULT, 82 } } },
            { PRINT_STMT, { { TOK_PRINT, 84 } } },
            { READ_STMT, { { TOK_READ, 85 } } },
            { EXPRESSION, { { TOK_IDENTIFIER, 86 },{ TOK_LPAREN, 86 },{ TOK_PLUS, 86 },{ TOK_MINUS, 86 },{ TOK_NOT, 86 },{ TOK_INTEGERCONSTANT, 86 },{ TOK_STRINGCONSTANT, 86 } } },
            { REL_EXPR, { { TOK_IDENTIFIER, 87 },{ TOK_LPAREN, 87 },{ TOK_PLUS, 87 },{ TOK_MINUS, 87 },{ TOK_NOT, 87 },{ TOK_INTEGERCONSTANT, 87 },{ TOK_STRINGCONSTANT, 87 } } },
            { REL_EXPR_AUX, { { TOK_SEMICOLON, 89 },{ TOK_LCURLY, 89 },{ TOK_RCURLY, 89 },{ TOK_COMMA, 89 },{ TOK_RPAREN, 89 },{ TOK_RSQUARE, 89 },{ TOK_TO, 89 },{ TOK_STEP, 89 },{ TOK_LESS, 88 },{ TOK_LESSEQ, 88 },{ TOK_EQEQ, 88 },{ TOK_DIFF, 88 },{ TOK_GREATEREQ, 88 },{ TOK_GREATER, 88 } } },
            { ADD_EXPR, { { TOK_IDENTIFIER, 90 },{ TOK_LPAREN, 90 },{ TOK_PLUS, 90 },{ TOK_MINUS, 90 },{ TOK_NOT, 90 },{ TOK_INTEGERCONSTANT, 90 },{ TOK_STRINGCONSTANT, 90 } } },
            { ADD_EXPR_AUX, { { TOK_SEMICOLON, 92 },{ TOK_LCURLY, 92 },{ TOK_RCURLY, 92 },{ TOK_COMMA, 92 },{ TOK_RPAREN, 92 },{ TOK_RSQUARE, 92 },{ TOK_TO, 92 },{ TOK_STEP, 92 },{ TOK_LESS, 92 },{ TOK_LESSEQ, 92 },{ TOK_EQEQ, 92 },{ TOK_DIFF, 92 },{ TOK_GREATEREQ, 92 },{ TOK_GREATER, 92 },{ TOK_PLUS, 91 },{ TOK_MINUS, 91 },{ TOK_2PIPE, 91 } } },
            { MULT_EXPR, { { TOK_IDENTIFIER, 93 },{ TOK_LPAREN, 93 },{ TOK_PLUS, 93 },{ TOK_MINUS, 93 },{ TOK_NOT, 93 },{ TOK_INTEGERCONSTANT, 93 },{ TOK_STRINGCONSTANT, 93 } } },
            { MULT_EXPR_AUX, { { TOK_SEMICOLON, 95 },{ TOK_LCURLY, 95 },{ TOK_RCURLY, 95 },{ TOK_COMMA, 95 },{ TOK_RPAREN, 95 },{ TOK_RSQUARE, 95 },{ TOK_TO, 95 },{ TOK_STEP, 95 },{ TOK_LESS, 95 },{ TOK_LESSEQ, 95 },{ TOK_EQEQ, 95 },{ TOK_DIFF, 95 },{ TOK_GREATEREQ, 95 },{ TOK_GREATER, 95 },{ TOK_PLUS, 95 },{ TOK_MINUS, 95 },{ TOK_2PIPE, 95 },{ TOK_ASTERISK, 94 },{ TOK_SLASH, 94 },{ TOK_AND, 94 },{ TOK_MOD, 94 } } },
            { UNARY_EXPR, { { TOK_IDENTIFIER, 98 },{ TOK_LPAREN, 99 },{ TOK_PLUS, 96 },{ TOK_MINUS, 96 },{ TOK_NOT, 96 },{ TOK_INTEGERCONSTANT, 97 },{ TOK_STRINGCONSTANT, 97 } } },
            { METHOD_CALL_OPT, { { TOK_SEMICOLON, 101 },{ TOK_LCURLY, 101 },{ TOK_RCURLY, 101 },{ TOK_COMMA, 101 },{ TOK_LPAREN, 100 },{ TOK_RPAREN, 101 },{ TOK_RSQUARE, 101 },{ TOK_TO, 101 },{ TOK_STEP, 101 },{ TOK_LESS, 101 },{ TOK_LESSEQ, 101 },{ TOK_EQEQ, 101 },{ TOK_DIFF, 101 },{ TOK_GREATEREQ, 101 },{ TOK_GREATER, 101 },{ TOK_PLUS, 101 },{ TOK_MINUS, 101 },{ TOK_2PIPE, 101 },{ TOK_ASTERISK, 101 },{ TOK_SLASH, 101 },{ TOK_AND, 101 },{ TOK_MOD, 101 } } },
            { REL_OP, { { TOK_LESS, 102 },{ TOK_LESSEQ, 103 },{ TOK_EQEQ, 104 },{ TOK_DIFF, 105 },{ TOK_GREATEREQ, 106 },{ TOK_GREATER, 107 } } },
            { UNARY_OP, { { TOK_PLUS, 108 },{ TOK_MINUS, 109 },{ TOK_NOT, 110 } } },
            { ADD_OP, { { TOK_PLUS, 111 },{ TOK_MINUS, 112 },{ TOK_2PIPE, 113 } } },
            { MULT_OP, { { TOK_ASTERISK, 114 },{ TOK_SLASH, 115 },{ TOK_AND, 116 },{ TOK_MOD, 117 } } },
            { UNSIG_LIT, { { TOK_INTEGERCONSTANT, 118 },{ TOK_STRINGCONSTANT, 119 } } },
            { VARIABLE, { { TOK_IDENTIFIER, 120 } } },
            { VARIABLE_AUX, { { TOK_SEMICOLON, 122 },{ TOK_LCURLY, 122 },{ TOK_RCURLY, 122 },{ TOK_COMMA, 122 },{ TOK_LPAREN, 122 },{ TOK_RPAREN, 122 },{ TOK_LSQUARE, 123 },{ TOK_RSQUARE, 122 },{ TOK_ASSIGN, 122 },{ TOK_TO, 122 },{ TOK_STEP, 122 },{ TOK_LESS, 122 },{ TOK_LESSEQ, 122 },{ TOK_EQEQ, 122 },{ TOK_DIFF, 122 },{ TOK_GREATEREQ, 122 },{ TOK_GREATER, 122 },{ TOK_PLUS, 122 },{ TOK_MINUS, 122 },{ TOK_2PIPE, 122 },{ TOK_ASTERISK, 122 },{ TOK_SLASH, 122 },{ TOK_AND, 122 },{ TOK_MOD, 122 },{ TOK_DOT, 121 } } }
        };

        std::map<MJNonterminal, std::set<MJToken>> predict = get_predict();

        inline std::map<MJNonterminal, std::set<MJToken>> get_predict() {
            std::map<MJNonterminal, std::set<MJToken>> p;
            for (std::map<MJNonterminal, std::set<MJToken>>::iterator it=first.begin(); it!=first.end(); ++it){
                std::set<MJToken> firsts = it->second;
                std::set<MJToken>::iterator lambda = firsts.find(LAMBDA);
                if (lambda != firsts.end()){
                    firsts.erase(lambda);
                    firsts.insert(follow[it->first].begin(), follow[it->first].end());
                }
                p.insert(std::pair<MJNonterminal,std::set<MJToken>> (it->first,firsts));
            }
            return p;
        }

        /**
         * Skip until a token in the follow set is reached.
         *
         * @param nonterm nonterm to consider the follow from
         * */
        inline void skip_to_follow(MJNonterminal nonterm) {
            auto follow_set = follow[nonterm];
            auto synchr_set = first[nonterm];
            synchr_set.insert(follow_set.begin(), follow_set.end());
            while (synchr_set.find(this->lexer->current_token()) == synchr_set.end() &&
                    this->lexer->current_token() != END_OF_FILE) {
                this->lexer->next_token();
            }
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

#endif
