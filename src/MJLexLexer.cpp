#include "MJLexLexer.h"

MJToken MJLexLexer::next_token() {
    return (MJToken) yylex();
}
