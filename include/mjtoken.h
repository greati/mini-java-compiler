#ifndef __TOKEN__
#define __TOKEN__

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
char* get_token_name(enum MJToken token) {
    switch (token) {
        case TOK_PROGRAM: return "TOK_PROGRAM";
        case TOK_IDENTIFIER: return "TOK_IDENTIFIER";
        case TOK_SEMICOLON: return "TOK_SEMICOLON";
        case TOK_CLASS: return "TOK_CLASS";
        case TOK_LCURLY: return "TOK_LCURLY";
        case TOK_RCURLY: return "TOK_RCURLY";
        case TOK_DECLARATIONS: return "TOK_DECLARATIONS";
        case TOK_ENDDECLARATIONS: return "TOK_ENDDECLARATIONS";
        case TOK_COMMA: return "TOK_COMMA";
        case TOK_EQUALS: return "TOK_EQUALS";
        case TOK_LSQUARE: return "TOK_LSQUARE";
        case TOK_RSQUARE: return "TOK_RSQUARE";
        case TOK_INT: return "TOK_INT";
        case TOK_STRING: return "TOK_STRING";
        case TOK_METHOD: return "TOK_METHOD";
        case TOK_VOID: return "TOK_VOID";
        case TOK_LPAREN: return "TOK_LPAREN";
        case TOK_RPAREN: return "TOK_RPAREN";
        case TOK_VAL: return "TOK_VAL";
        case TOK_DOT: return "TOK_DOT";
        case TOK_ASSIGN: return "TOK_ASSIGN";
        case TOK_RETURN: return "TOK_RETURN";
        case TOK_IF: return "TOK_IF";
        case TOK_TO: return "TOK_TO";
        case TOK_STEP: return "TOK_STEP";
        case TOK_ELSE: return "TOK_ELSE";
        case TOK_WHILE: return "TOK_WHILE";
        case TOK_LESS: return "TOK_LESS";
        case TOK_LESSEQ: return "TOK_LESSEQ";
        case TOK_MOD: return "TOK_MOD";
        case TOK_EQEQ: return "TOK_EQEQ";
        case TOK_DIFF: return "TOK_DIFF";
        case TOK_GREATER: return "TOK_GREATER";
        case TOK_GREATEREQ: return "TOK_GREATEREQ";
        case TOK_FOR: return "TOK_FOR";
        case TOK_SWITCH: return "TOK_SWITCH";
        case TOK_CASE: return "TOK_CASE";
        case TOK_PLUS: return "TOK_PLUS";
        case TOK_MINUS: return "TOK_MINUS";
        case TOK_2PIPE: return "TOK_2PIPE";
        case TOK_ASTERISK: return "TOK_ASTERISK";
        case TOK_SLASH: return "TOK_SLASH";
        case TOK_AND: return "TOK_AND";
        case TOK_NOT: return "TOK_NOT";
        case TOK_INTEGERCONSTANT: return "TOK_INTEGERCONSTANT";
        case TOK_STRINGCONSTANT: return "TOK_STRINGCONSTANT";
        case TOK_READ: return "TOK_READ";
        case TOK_PRINT: return "TOK_PRINT";
        default: return "UNDEFINED";
    }
}

#endif
