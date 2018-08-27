#ifndef __PARSER__
#define __PARSER__

#include "Lexer.h"
#include <iostream>
#include <memory>
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
        
        std::shared_ptr<Lexer> lexer;
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
        Parser(std::shared_ptr<Lexer> _lexer) : lexer {_lexer} {} 

	virtual ~Parser() {}

        /**
         * Parse a program, reseting the lexer.
         *
         */
        inline void parse(std::string program) {
            this->lexer->reset(program);
            _parse(program);
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
