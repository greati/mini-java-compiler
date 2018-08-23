#include <iostream>
#include "MJLexLexer.h"

int main(void) {

    MJLexLexer lexer{"program oi;"};

    MJToken token = UNDEFINED;

    while (token != END_OF_FILE) {
        token = lexer.next_token();
        std::cout << get_token_name(token) << std::endl;
    }

    return 0;

}
