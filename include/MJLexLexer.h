#ifndef __MJLEXLEXER__
#define __MJLEXLEXER__

#include "Lexer.h"
#include <string>

extern int   yylex();
extern char* yytext;
extern int   yyleng;

extern void* setUpBuffer(char const* text);
extern void  tearDownBuffer(void* buffer);

/**
 * Implementation of the mini-java lexer using Lex.
 *
 */
class MJLexLexer : public Lexer {

    private:

        std::string text;
        void* buffer;

    public:

        MJLexLexer(std::string const& input) : text {input} {
            buffer = setUpBuffer(text.c_str());
        }

        ~MJLexLexer() {
            tearDownBuffer(buffer);
        }
        
        MJToken next_token() override;

};

#endif
