#ifndef __TOKEN__
#define __TOKEN__

#include <string>
#include "ast/Node.h"
#include "ast/Expr.h"
#include "y.tab.h"

typedef int MJToken;

/**
 * Tokens of the Mini-Java language. 
 */
/*enum MJToken {
    TOK_PROGRAM = 0,
    TOK_IDENTIFIER,
    TOK_SEMICOLON,
    TOK_CLASS,
    TOK_LCURLY,
    TOK_RCURLY,
    TOK_DECLARATIONS,
    TOK_ENDDECLARATIONS,
    TOK_EQUALS,
    TOK_COMMA,
    TOK_INT,
    TOK_STRING,
    TOK_LRSQUARE,
    TOK_METHOD,
    TOK_LPAREN,
    TOK_RPAREN,
    TOK_VOID,
    TOK_VAL,
    TOK_ARROBA,
    TOK_LSQUARE,
    TOK_RSQUARE,
    TOK_ASSIGN,
    TOK_RETURN,
    TOK_IF,
    TOK_ELSE,
    TOK_FOR,
    TOK_TO,
    TOK_STEP,
    TOK_WHILE,
    TOK_SWITCH,
    TOK_CASE,
    TOK_DEFAULT,
    TOK_PRINT,
    TOK_READ,
    TOK_LESS,
    TOK_LESSEQ,
    TOK_EQEQ,
    TOK_DIFF,
    TOK_GREATEREQ,
    TOK_GREATER,
    TOK_PLUS,
    TOK_MINUS,
    TOK_NOT,
    TOK_2PIPE,
    TOK_ASTERISK,
    TOK_SLASH,
    TOK_AND,
    TOK_MOD,
    TOK_INTEGERCONSTANT,
    TOK_STRINGCONSTANT,
    TOK_DOT,
    END_OF_FILE,
    LAMBDA,
    UNDEFINED
};*/

/**
 * Gives the string representation of a token.
 *
 * @param token The token
 * @return The string representation of token
 */
std::string get_token_name(MJToken token);

#endif
