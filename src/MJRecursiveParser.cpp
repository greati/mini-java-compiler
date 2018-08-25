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
        return false;
    }
}

void MJRecursiveParser::brackets_opt() {
    if (accept(TOK_LRSQUARE)) {
        brackets_opt();
    }
}

void MJRecursiveParser::type_aux() {
    if (accept(TOK_IDENTIFIER) ||
        accept(TOK_INT) ||
        accept(TOK_STRING)) 
        ;
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
    if (accept(TOK_DECLARATIONS)) {
        field_decl_list_decls();
        expect(TOK_ENDDECLARATIONS);
    } else {
        parse_error(DECLS);
    }
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
    if (accept(TOK_LCURLY)) {
        decls_opt();
        //method_decl_list();
        expect(TOK_RCURLY);
    } else {
        parse_error(CLASS_BODY);
    }
}

void MJRecursiveParser::class_decl(){
    if (accept(TOK_CLASS)) {
        expect(TOK_IDENTIFIER);
        class_body();
    } else {
        parse_error(CLASS_DECL);
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
