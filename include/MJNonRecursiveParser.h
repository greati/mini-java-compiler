#ifndef __MJNONRECPARSER__
#define __MJNONRECPARSER__

#include "MJLL1Parser.h"
#include <string>

/**
 * Top-down recursive parser for the Mini-Java language.
 *
 * @autor Vitor Greati
 * @date 2018-08-23
 * */
class MJNonRecursiveParser : public MJLL1Parser {

    public:

        MJNonRecursiveParser(std::shared_ptr<Lexer> _lexer) : MJLL1Parser{_lexer} {}

    private:

        /**
         * Consume an input if the current symbol
         * matches the argument, and outputs an error
         * and returns false otherwise.
         *
         * @param token Token
         * @return if argument matches the input
         * */
        bool expect(MJToken token);

        /**
         * Consume an input if it matches
         * the argument. Otherwise,
         * returns false.
         *
         * @param token Token
         * @return true if token match the input symbol
         * */
        bool accept(MJToken token);

        /**
         * Check the current input symbol without
         * consuming it anyway.
         *
         * @param token The token
         * @return if the current token is equals to the param
         * */
        bool lookup(MJToken token);

        /**
         * Check if an integer represents a token.
         * 
         * @param token the integer
         * @return if the arg is a token
         * */
        bool isToken(int token);

    protected:

        void _parse(std::string) override;

};

#endif
