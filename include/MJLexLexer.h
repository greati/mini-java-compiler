#ifndef __MJLEXLEXER__
#define __MJLEXLEXER__

#include "Lexer.h"
#include <string>

extern int   yylex();
extern char* yytext;
extern int   yyleng;
extern int   current_line;
extern int   offset;

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

        MJLexLexer() {
           buffer = setUpBuffer(std::string("").c_str());
	}

        MJLexLexer(std::string const& input) : text {input} {
            buffer = setUpBuffer(text.c_str());
        }

        ~MJLexLexer() {
            if (buffer != nullptr)
                tearDownBuffer(buffer);
        }
        
        bool next_token() override;

        Position current_position() override;

        void reset(std::string) override;
};

#endif
