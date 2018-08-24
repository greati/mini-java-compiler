#ifndef __PARSER__
#define __PARSER__

#include "Lexer.h"
#include <iostream>

/**
 * Represents a parser, composed with a 
 * lexical analyser.
 *
 * @author Vitor Greati
 * @date 2018-08-23
 */
class Parser { 

    private:
        
        Lexer * lexer;              /** A lexical analyser */

    protected:

        /**
         * Implements the parsing algorithm.
         *
         * */
        virtual void _parse(std::string program) = 0;

    public:

        /**
         * Simple constructor.
         *
         */
        Parser(Lexer* & _lexer) : lexer {_lexer} {} 

        /**
         * Parse a program, reseting the lexer.
         *
         */
        inline void parse(std::string program) {
            this->lexer->reset(program);
            _parse(program);
        }

        /**
         * Prints a parse error in the standard output.
         *
         * */
        inline void unexpected_error(MJToken unexpected) {
            std::cout << "[mjc error] " << "(" << this->lexer->current_position().row << "," <<
                this->lexer->current_position().col << ")" 
                << " parse error: unexpected " << get_token_name(unexpected) << std::endl;
        }

};

#endif
