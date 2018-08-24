#include <iostream>
#include "MJLexLexer.h"

int main(void) {

    MJLexLexer lexer{"program oi;"};

    while(lexer.next_token()) {
        std::cout << get_token_name(lexer.current_token()) << std::endl;
    }

    return 0;

}
