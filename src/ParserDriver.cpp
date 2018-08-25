#include <iostream>
#include "MJLexLexer.h"
#include "MJRecursiveParser.h"

int main(void) {

    MJLexLexer * lexer = new MJLexLexer;

    MJRecursiveParser parser {lexer};

    parser.parse("programa Ola;");

    return 0;

}
