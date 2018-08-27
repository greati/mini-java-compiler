#include "MJNonRecursiveParser.h"
#include <string>
#include <stack>
#include <iostream>

bool MJNonRecursiveParser::lookup(MJToken token) {
    bool res = (this->lexer->current_token() == token);
    if (!res)
        this->expected_tokens.insert(token);
    else
        this->expected_tokens.clear();
    return res;
}

bool MJNonRecursiveParser::accept(MJToken token) {
    if (lookup(token)) {
        this->lexer->next_token();
        return true;
    }
    return false;
}

bool MJNonRecursiveParser::expect(MJToken token) {
    if (accept(token))
        return true;
    else {
        parse_error();
        return false;
    }
}

bool MJNonRecursiveParser::isToken(int token) {
    return token >= 0 && token < 1000;
}

void MJNonRecursiveParser::_parse(std::string program) {
    this->lexer->next_token();
    std::stack<int> stack;
    stack.push(END_OF_FILE);
    stack.push(PROGRAM);
    while(stack.top() != END_OF_FILE) {
        if (isToken(stack.top())) {
            expect(static_cast<MJToken>(stack.top()));
            stack.pop();
        }
        else if (this->parse_table[static_cast<MJNonterminal>(stack.top())].count(this->lexer->current_token()) == 0){
            parse_error(static_cast<MJNonterminal>(stack.top()));
            stack.pop();
        }
        else {
            int prodution = this->parse_table[static_cast<MJNonterminal>(stack.top())][this->lexer->current_token()];
            std::vector<int> terms = this->productions[prodution].second;
            stack.pop();
            for (std::vector<int>::reverse_iterator term=terms.rbegin(); term!=terms.rend(); ++term)
                stack.push(*term);
        }
    }
}