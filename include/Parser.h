#ifndef __PARSER__
#define __PARSER__

#include "Lexer.h"
#include <iostream>
#include <set>

/**
 * Represents a parser, composed with a 
 * lexical analyser.
 *
 * @author Vitor Greati
 * @date 2018-08-23
 */
class Parser { 

    protected:
        
        Lexer * lexer;              /** A lexical analyser */
        std::set<MJToken> expected_tokens;   /** Store the expected tokens */

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
        Parser(Lexer * _lexer) : lexer {_lexer} {} 

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
        inline void unexpected_error(MJToken expected) {
            std::cout << "[mjc error] " << "(" << this->lexer->current_position().row << "," <<
                this->lexer->current_position().col << ")" 
                << " parse error: expected " << get_token_name(expected) << std::endl;
        }
        
        inline void unexpected_token_error(MJToken unexpected) {
            std::cout << "[mjc error] " << "(" << this->lexer->current_position().row << "," <<
                this->lexer->current_position().col << ")" 
                << " parse error: unexpected " << get_token_name(unexpected) << std::endl;
            this->lexer->next_token();
        }

        inline std::string expected_tokens_string() {
            std::string expected_tokens_str = "";
            for (auto it = this->expected_tokens.begin(); it != this->expected_tokens.end(); ++it) {
                if (it != this->expected_tokens.begin())
                    expected_tokens_str += ",";
                expected_tokens_str += get_token_name(*it);
            }
            return expected_tokens_str;
        }



};

#endif
