#ifndef __TOKEN__
#define __TOKEN__

#include <string>

/**
 * Tokens of the Mini-Java language. 
 */
enum MJToken {
    TOK_PROGRAM = 0,
    TOK_IDENTIFIER,
    TOK_SEMICOLON,
    TOK_CLASS,
    TOK_LCURLY,
    TOK_RCURLY,
    TOK_DECLARATIONS,
    TOK_ENDDECLARATIONS,
    TOK_COMMA,
    TOK_MOD,
    TOK_ARROBA,
    TOK_LRSQUARE,
    TOK_EQUALS,
    TOK_LSQUARE,
    TOK_RSQUARE,
    TOK_INT,
    TOK_STRING,
    TOK_METHOD,
    TOK_VOID,
    TOK_LPAREN,
    TOK_RPAREN,
    TOK_VAL,
    TOK_DOT,
    TOK_ASSIGN,
    TOK_RETURN,
    TOK_IF,
    TOK_ELSE,
    TOK_WHILE,
    TOK_LESS,
    TOK_LESSEQ,
    TOK_EQEQ,
    TOK_DIFF,
    TOK_GREATER,
    TOK_GREATEREQ,
    TOK_FOR,
    TOK_TO,
    TOK_STEP,
    TOK_SWITCH,
    TOK_CASE,
    TOK_DEFAULT,
    TOK_PLUS,
    TOK_MINUS,
    TOK_2PIPE,
    TOK_ASTERISK,
    TOK_SLASH,
    TOK_AND,
    TOK_NOT,
    TOK_INTEGERCONSTANT,
    TOK_STRINGCONSTANT,
    TOK_PRINT,
    TOK_READ,
    UNDEFINED,
    END_OF_FILE
};

/**
 * Gives the string representation of a token.
 *
 * @param token The token
 * @return The string representation of token
 */
std::string get_token_name(enum MJToken token);

#endif
