#ifndef __LEXER__
#define __LEXER__

#include "MJToken.h"
#include <iostream>

/**
 * Lexical analyser.
 *
 * @author Vitor Greati
 * @date 2018-08-23
 */
class Lexer {

    protected:

        MJToken _current_token;              /** Current token */

    public:

        /**
         * Position in the lexical analysis.
         *
         **/
        struct Position {
            int row, col;        
            Position(int _row, int _col) : row {_row}, col{_col} {}; 
        };

        /**
         * Pass to the next token.
         *
         * @return false when end of file
         */
        virtual bool next_token() = 0;

        /**
         * Return the current position in the parsing.
         *
         */
        virtual Position current_position() = 0;

        /**
         * The current token.
         *
         * */
        inline MJToken current_token() { return _current_token; };

        /**
         * Reset the lexer, passing a new string.
         *
         * */
        virtual void reset(std::string) = 0;

        /**
         * Print the current token.
         */
        inline void print_current_token() { std::cout << get_token_name(current_token()) << std::endl; }

};

#endif
