#ifndef __LEXER__
#define __LEXER__

#include "MJToken.h"

/**
 * Lexical analyser.
 *
 * @author Vitor Greati
 * @date 2018-08-23
 */
class Lexer {

    public:
        /**
         * Returns the next token.
         *
         */
        virtual MJToken next_token() = 0;

};

#endif
