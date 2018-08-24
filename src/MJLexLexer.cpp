#include "MJLexLexer.h"

bool MJLexLexer::next_token() {
    this->_current_token = (MJToken) yylex();
    return !(_current_token == END_OF_FILE);
}

MJLexLexer::Position MJLexLexer::current_position() {
    return Position{current_line, offset - yyleng}; 
}

void MJLexLexer::reset(std::string _text) {
    tearDownBuffer(this->buffer); 
    this->text = _text;
    this->buffer = setUpBuffer(_text.c_str());
}
