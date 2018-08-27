#include <iostream>
#include "MJLexLexer.h"
#include "MJNonterminal.h"
#include <map>
#include <vector>
#include <memory>
#include "MJToken.h"
#include "MJRecursiveParser.h"
#include "MJNonRecursiveParser.h"

int main(int argn, char** args) {

    std::string program = "";

    std::string program_line;
    while(std::getline(std::cin, program_line)) {
        program += program_line + "\n";
    }

    auto lexer = std::make_shared<MJLexLexer>();

    MJRecursiveParser recparser {lexer};

    recparser.parse(program);

	MJNonRecursiveParser nonrecparser {lexer};

    nonrecparser.parse(program);

    return 0;

}
