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
            { PROGRAM, { {TOK_PROGRAM, 0} } }
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
