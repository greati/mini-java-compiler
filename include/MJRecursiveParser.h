#ifndef __MJRECPARSER__
#define __MJRECPARSER__

#include "Parser.h"
#include <string>

/**
 * Top-down recursive parser for the Mini-Java language.
 *
 * @autor Vitor Greati
 * @date 2018-08-23
 * */
class MJRecursiveParser : public Parser {

    private:

        // recursive parsing methods go here

    protected:

        void _parse(std::string) override;

};

#endif
