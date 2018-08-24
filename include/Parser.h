#ifndef __PARSER__
#define __PARSER__

#include "Lexer.h"

/**
 * Represents a parser, composed with a 
 * lexical analyser.
 *
 * @author Vitor Greati
 * @date 2018-08-23
 */
template<typename TLexer>
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
        Parser(const Lexer* & _lexer) : lexer {_lexer} {} 

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
        virtual void parse_error() = 0;

};

#endif
