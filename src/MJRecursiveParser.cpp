#include "MJRecursiveParser.h"
#include <string>

void MJRecursiveParser::_parse(std::string program) {
    this->lexer->next_token();
    this->program();
}

bool MJRecursiveParser::lookup(MJToken token) {
    bool res = (this->lexer->current_token() == token);
    if (!res)
        this->expected_tokens.insert(token);
    else
        this->expected_tokens.clear();
    return res;
}

bool MJRecursiveParser::accept(MJToken token) {
    if (lookup(token)) {
        this->lexer->next_token();
        return true;
    }
    return false;
}

bool MJRecursiveParser::expect(MJToken token, MJNonterminal curnonterm) {
    if (accept(token))
        return true;
    else {
        parse_error(curnonterm);
        return false;
    }
}

bool MJRecursiveParser::expect(MJToken token) {
    if (accept(token))
        return true;
    else {
        parse_error();
        this->lexer->next_token();
        return false;
    }
}

void MJRecursiveParser::brackets_opt() {
    if (accept(TOK_LRSQUARE)) {
        brackets_opt();
    }
}

void MJRecursiveParser::type_aux() {
    if (accept(TOK_IDENTIFIER));
    else if (accept(TOK_INT));
    else if (accept(TOK_STRING));
    else {
        parse_error(TYPE_AUX);
    };
}

void MJRecursiveParser::type() {
    type_aux();
    brackets_opt();
}

void MJRecursiveParser::field_decl() {
    type();
    //var_decl_id();
    //field_decl_aux_1();
}

void MJRecursiveParser::field_decl_list_decls() {
    if (lookup(TOK_IDENTIFIER) || 
        lookup(TOK_INT) ||
        lookup(TOK_STRING)) {
        field_decl();
        expect(TOK_SEMICOLON);
        field_decl_list_decls();
    } 
}

void MJRecursiveParser::decls() {

    if (lookup(TOK_DECLARATIONS)) {
        this->lexer->next_token();
        field_decl_list_decls();
        expect(TOK_ENDDECLARATIONS);
    } else parse_error(DECLS);
}

void MJRecursiveParser::decls_opt() {
    if (lookup(TOK_DECLARATIONS)) {
        decls(); 
    } 
}

void MJRecursiveParser::method_decl() {

}

void MJRecursiveParser::method_decl_list() {
    if (lookup(TOK_METHOD)) {
        method_decl();
        method_decl_list();
    }
}

void MJRecursiveParser::class_body() {
    if (expect(TOK_LCURLY)) {
        decls_opt();
        //method_decl_list();
        expect(TOK_RCURLY);
    }
}

void MJRecursiveParser::class_decl(){
    if (expect(TOK_CLASS)) {
        if (expect(TOK_IDENTIFIER)) {
            class_body();
        }
    }
}

void MJRecursiveParser::class_decl_list() {
    if (lookup(TOK_CLASS)) {
        class_decl();
        class_decl_list();
    } 
}

void MJRecursiveParser::program() {
    if (lookup(TOK_PROGRAM)) {
        expect(TOK_PROGRAM);
        expect(TOK_IDENTIFIER);
        expect(TOK_SEMICOLON);
        class_decl();
        class_decl_list();
        expect(END_OF_FILE);       
    } else {
        parse_error(PROGRAM);
    }
}
