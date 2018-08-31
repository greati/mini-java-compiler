#include <iostream>
#include "MJLexLexer.h"
#include "MJNonterminal.h"
#include <map>
#include <vector>
#include <memory>
#include "MJToken.h"
#include "MJRecursiveParser.h"
#include "MJNonRecursiveParser.h"
#include "MJMessage.h"

int main(int argn, char** args) {

    std::string program = "";

    std::string program_line;
    while(std::getline(std::cin, program_line)) {
        program += program_line + "\n";
    }

    auto lexer = std::make_shared<MJLexLexer>();

    char parser_type = 'R';

    if (argn > 1) {
        parser_type = args[1][0];
        if (parser_type != 'R' && parser_type != 'N') {
            std::cout << "Invalid parser type. Pass R for recursive or N for non-recursive" << std::endl; 
            return 1;
        }
    }

    if (parser_type == 'R') {
        std::cout << "Parsing with LL(1) recursive parsing." << std::endl;
        MJRecursiveParser recparser {lexer};
        recparser.parse(program);
    } else {
        std::cout << "Parsing with LL(1) non-recursive parsing." << std::endl;
        MJNonRecursiveParser nonrecparser {lexer};
        nonrecparser.parse(program);
    }

    std::cout << "Parsing finished. No output means no parse errors." << std::endl;

    MJMessage::print(MJMessage::Type::SUCCESS, "testing");
    
    return 0;

}
