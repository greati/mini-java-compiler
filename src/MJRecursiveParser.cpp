#include "MJRecursiveParser.h"
#include <string>

void MJRecursiveParser::_parse(std::string program) {
    this->lexer->next_token();
    this->program();
}

bool MJRecursiveParser::accept(MJToken token) {
    if (this->lexer->current_token() == token) {
        this->lexer->next_token();
        return true;
    }
    return false;
}

bool MJRecursiveParser::expect(MJToken token) {
    if (accept(token))
        return true;
    else {
        unexpected_error(token);
        return false;
    }
}

void MJRecursiveParser::program() {
    expect(TOK_PROGRAM);
    expect(TOK_IDENTIFIER);
    expect(TOK_SEMICOLON);
}
