#include "MJToken.h"
#include <string>

std::string get_token_name(enum MJToken token) {
    switch (token) {
        case TOK_PROGRAM: return "program";
        case TOK_IDENTIFIER: return "identifier";
        case TOK_SEMICOLON: return ";";
        case TOK_CLASS: return "class";
        case TOK_LCURLY: return "{";
        case TOK_RCURLY: return "}";
        case TOK_DECLARATIONS: return "declarations";
        case TOK_ENDDECLARATIONS: return "enddeclarations";
        case TOK_COMMA: return ",";
        case TOK_EQUALS: return "=";
        case TOK_LSQUARE: return "[";
        case TOK_RSQUARE: return "]";
        case TOK_INT: return "int";
        case TOK_STRING: return "string";
        case TOK_METHOD: return "method";
        case TOK_VOID: return "void";
        case TOK_LPAREN: return "(";
        case TOK_RPAREN: return ")";
        case TOK_VAL: return "val";
        case TOK_DOT: return ".";
        case TOK_ASSIGN: return ":=";
        case TOK_RETURN: return "return";
        case TOK_IF: return "if";
        case TOK_TO: return "to";
        case TOK_STEP: return "step";
        case TOK_ELSE: return "else";
        case TOK_WHILE: return "while";
        case TOK_LESS: return "<";
        case TOK_LESSEQ: return "<=";
        case TOK_MOD: return "%";
        case TOK_EQEQ: return "==";
        case TOK_DIFF: return "!=";
        case TOK_GREATER: return ">";
        case TOK_GREATEREQ: return ">=";
        case TOK_FOR: return "for";
        case TOK_SWITCH: return "switch";
        case TOK_CASE: return "case";
        case TOK_DEFAULT: return "default";
        case TOK_PLUS: return "+";
        case TOK_MINUS: return "-";
        case TOK_2PIPE: return "||";
        case TOK_ASTERISK: return "*";
        case TOK_SLASH: return "/";
        case TOK_AND: return "&&";
        case TOK_NOT: return "not";
        case TOK_INTEGERCONSTANT: return "integer literal";
        case TOK_STRINGCONSTANT: return "string literal";
        case TOK_READ: return "read";
        case TOK_PRINT: return "print";
        case TOK_ARROBA: return "@";
        case TOK_LRSQUARE: return "[]";
        case END_OF_FILE: return "eof";
        case LAMBDA: return "LAMBDA";
        default: return "UNDEFINED";
    }
}
