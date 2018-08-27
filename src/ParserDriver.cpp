#include <iostream>
#include "MJLexLexer.h"
#include "MJRecursiveParser.h"
#include "MJNonterminal.h"
#include <map>
#include <vector>
#include <memory>

int main(int argn, char** args) {

    std::string program = "";

    std::string program_line;
    while(std::getline(std::cin, program_line)) {
        program += program_line + "\n";
    }

    auto lexer = std::make_shared<MJLexLexer>();

    MJRecursiveParser parser {lexer};

    parser.parse(program);

    return 0;

}
