#include <iostream>
#include "MJLexLexer.h"
#include "MJRecursiveParser.h"
#include "MJNonterminal.h"
#include <map>
#include <vector>

int main(int argn, char** args) {

    std::string program = "";

    std::string program_line;
    while(std::getline(std::cin, program_line)) {
        program += program_line + "\n";
    }

    MJLexLexer * lexer = new MJLexLexer;

    MJRecursiveParser parser {lexer};

    parser.parse(program);

    return 0;

}
