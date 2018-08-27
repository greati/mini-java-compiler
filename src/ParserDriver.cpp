#include <iostream>
#include "MJLexLexer.h"
#include "MJRecursiveParser.h"
#include "MJNonterminal.h"
#include <map>
#include <vector>
#include <memory>
#include "MJToken.h"

int main(int argn, char** args) {

    std::string program = "";

    std::string program_line;
    while(std::getline(std::cin, program_line)) {
        program += program_line + "\n";
    }

    auto lexer = std::make_shared<MJLexLexer>();

    //lexer->reset(program);

    //while (lexer->current_token() != END_OF_FILE) {
	//lexer->next_token();	
	//std::cout << lexer->current_token() << std::endl;
    //}


    MJRecursiveParser parser {lexer};

    parser.parse(program);

    return 0;

}
