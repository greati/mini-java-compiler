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
        MJMessage::print(MJMessage::Type::NOTE,  
                "inserting " + get_token_name(token), 
                this->lexer->current_position());
        this->lexer->next_token();
        return false;
    }
}

void MJRecursiveParser::variable_aux() {
    if (lookup(TOK_DOT)) {
        expect(TOK_DOT);
        expect(TOK_IDENTIFIER);
        variable_aux();
    } else if (lookup(TOK_LSQUARE)) {
        expect(TOK_LSQUARE);
        expression();
        expression_list_comma();
        expect(TOK_RSQUARE);
        variable_aux();
    }
}

void MJRecursiveParser::variable() {
    if (lookup(TOK_IDENTIFIER)) {
        expect(TOK_IDENTIFIER);
        variable_aux();
    } else {
        parse_error(VARIABLE);
    }
} 

void MJRecursiveParser::unsig_lit() {
    if (lookup(TOK_INTEGERCONSTANT)) {
        expect(TOK_INTEGERCONSTANT);
    } else if (lookup(TOK_STRINGCONSTANT)) {
        expect(TOK_STRINGCONSTANT);
    } else {
        parse_error(UNSIG_LIT);
    }
}

void MJRecursiveParser::mult_op() {
    if (lookup(TOK_ASTERISK))
        expect(TOK_ASTERISK);
    else if (lookup(TOK_SLASH))
        expect(TOK_SLASH);
    else if (lookup(TOK_AND))
        expect(TOK_AND);
    else if (lookup(TOK_MOD))
        expect(TOK_MOD);
    else
        parse_error(MULT_OP);
}

void MJRecursiveParser::add_op() {
    if (lookup(TOK_PLUS))
        expect(TOK_PLUS);
    else if (lookup(TOK_MINUS))
        expect(TOK_MINUS);
    else if (lookup(TOK_2PIPE))
        expect(TOK_2PIPE);
    else
        parse_error(ADD_OP);
}

void MJRecursiveParser::unary_op() {
    if (lookup(TOK_PLUS))
        expect(TOK_PLUS);
    else if (lookup(TOK_MINUS))
        expect(TOK_MINUS);
    else if (lookup(TOK_NOT))
        expect(TOK_NOT);
    else
        parse_error(UNARY_OP);
}

void MJRecursiveParser::method_call_opt() {
    if (lookup(TOK_LPAREN)) {
        method_call_stmt(); 
    }
}

void MJRecursiveParser::rel_op() {
    if (lookup(TOK_LESS))
        expect(TOK_LESS);
    else if (lookup(TOK_LESSEQ))
        expect(TOK_LESSEQ);
    else if (lookup(TOK_EQEQ))
        expect(TOK_EQEQ);
    else if (lookup(TOK_DIFF))
        expect(TOK_DIFF);
    else if (lookup(TOK_GREATEREQ))
        expect(TOK_GREATEREQ);
    else if (lookup(TOK_GREATER))
        expect(TOK_GREATER);
    else
        parse_error(REL_OP);
}

void MJRecursiveParser::unary_expr() {
    if (lookup(TOK_NOT) || lookup(TOK_PLUS) || lookup(TOK_MINUS)) {
        unary_op();
        unary_expr();
    } else if (lookup(TOK_INTEGERCONSTANT) || lookup(TOK_STRINGCONSTANT)) {
        unsig_lit();
    } else if (lookup(TOK_LPAREN)) {
        expect(TOK_LPAREN);
        expression();
        expect(TOK_RPAREN);
    } else if (lookup(TOK_IDENTIFIER)) {
        variable();
        method_call_opt();
    } else {
        parse_error(UNARY_EXPR);
    }
}

void MJRecursiveParser::mult_expr_aux() {
    if (lookup(TOK_ASTERISK) || lookup(TOK_SLASH) ||
        lookup(TOK_AND) || lookup(TOK_MOD)) {
        mult_op();
        unary_expr();
        mult_expr_aux();
    }
}

void MJRecursiveParser::mult_expr() {
    if(lookup(TOK_LPAREN) || lookup(TOK_PLUS) ||
       lookup(TOK_MINUS) || lookup(TOK_NOT) ||
       lookup(TOK_INTEGERCONSTANT) || lookup(TOK_STRINGCONSTANT) ||
       lookup(TOK_IDENTIFIER)) {
        unary_expr();
        mult_expr_aux();
    } else {
        parse_error(MULT_EXPR);
    }
}

void MJRecursiveParser::add_expr_aux() {
    if (lookup(TOK_PLUS) || lookup(TOK_MINUS) || lookup(TOK_2PIPE)) {
        add_op();
        mult_expr();
        add_expr_aux();
    } 
}

void MJRecursiveParser::add_expr() {
    if(lookup(TOK_LPAREN) || lookup(TOK_PLUS) ||
       lookup(TOK_MINUS) || lookup(TOK_NOT) ||
       lookup(TOK_INTEGERCONSTANT) || lookup(TOK_STRINGCONSTANT) ||
       lookup(TOK_IDENTIFIER)) {
        mult_expr();
        add_expr_aux();
    } else {
        parse_error(ADD_EXPR);
    }
}

void MJRecursiveParser::rel_expr_aux() {
    if (lookup(TOK_LESS) || lookup(TOK_LESSEQ) ||
        lookup(TOK_EQEQ) || lookup(TOK_DIFF) ||
        lookup(TOK_GREATEREQ) || lookup(TOK_GREATER)) {
        rel_op();
        add_expr();
    }
}

void MJRecursiveParser::rel_expr() {
    if(lookup(TOK_LPAREN) || lookup(TOK_PLUS) ||
       lookup(TOK_MINUS) || lookup(TOK_NOT) ||
       lookup(TOK_INTEGERCONSTANT) || lookup(TOK_STRINGCONSTANT) ||
       lookup(TOK_IDENTIFIER)) {
        add_expr();
        rel_expr_aux();
    } else {
        parse_error(REL_EXPR);
    }
}

void MJRecursiveParser::expression() {
    if(lookup(TOK_LPAREN) || lookup(TOK_PLUS) ||
       lookup(TOK_MINUS) || lookup(TOK_NOT) ||
       lookup(TOK_INTEGERCONSTANT) || lookup(TOK_STRINGCONSTANT) ||
       lookup(TOK_IDENTIFIER)) {
        rel_expr();
    } else {
        parse_error(EXPRESSION);
    }
}

void MJRecursiveParser::read_stmt() {
    if (lookup(TOK_READ)) {
        expect(TOK_READ);
        expect(TOK_IDENTIFIER);
    } else {
        parse_error(READ_STMT);
    }
}

void MJRecursiveParser::print_stmt() {
    if (lookup(TOK_PRINT)) {
        expect(TOK_PRINT);
        expression();
    } else {
        parse_error(PRINT_STMT);
    }
}

void MJRecursiveParser::case_list() {
    if (lookup(TOK_CASE)) {
        _case();
        case_list();
    } else if (lookup(TOK_DEFAULT)) {
        expect(TOK_DEFAULT);
        stmt_list();
    }
}

void MJRecursiveParser::_case() {
    if (lookup(TOK_CASE)) {
        expect(TOK_CASE);
        expression();
        stmt_list();
    } else {
        parse_error(CASE);
    }
}

void MJRecursiveParser::switch_stmt() {
    if (lookup(TOK_SWITCH)) {
        expect(TOK_SWITCH);
        expression(); 
        expect(TOK_LCURLY);
        _case();
        case_list();
        expect(TOK_RCURLY);
    } else {
        parse_error(SWITCH_STMT);
    }
}

void MJRecursiveParser::while_stmt() {
    if (lookup(TOK_WHILE)) {
        expect(TOK_WHILE);
        expression();
        stmt_list();
    } else {
        parse_error(WHILE_STMT);
    }
}

void MJRecursiveParser::step_opt() {
    if (lookup(TOK_STEP)) {
        expect(TOK_STEP);
        expression();
    }
}

void MJRecursiveParser::for_init_expr() {
    if (lookup(TOK_IDENTIFIER)) {
        expect(TOK_IDENTIFIER);
        assign_stmt();
    } else {
        parse_error(FOR_INIT_EXPR);
    }
}

void MJRecursiveParser::for_stmt() {
    if (lookup(TOK_FOR)) {
        expect(TOK_FOR);
        for_init_expr();
        expect(TOK_TO);
        expression();
        step_opt();
        stmt_list();
    } else {
        parse_error(FOR_STMT);
    }
}

void MJRecursiveParser::if_stmt_aux() {
    if (lookup(TOK_IF)) {
        if_stmt();
    } else if (lookup(TOK_LCURLY)) {
        stmt_list(); 
    } else {
        parse_error(IF_STMT_AUX);
    }
}

void MJRecursiveParser::else_part() {
    if (lookup(TOK_ELSE)) {
        expect(TOK_ELSE);
        if_stmt_aux();
    }
}

void MJRecursiveParser::if_stmt() {
    if (lookup(TOK_IF)) {
        expect(TOK_IF);
        expression();
        stmt_list();
        else_part();
    } else {
        parse_error(IF_STMT);
    }
}

void MJRecursiveParser::expression_opt() {
    if(lookup(TOK_LPAREN) || lookup(TOK_PLUS) ||
       lookup(TOK_MINUS) || lookup(TOK_NOT) ||
       lookup(TOK_INTEGERCONSTANT) || lookup(TOK_STRINGCONSTANT) ||
       lookup(TOK_IDENTIFIER)) {
        expression();
    }   
}

void MJRecursiveParser::return_stmt() {
    if (lookup(TOK_RETURN)) {
        expect(TOK_RETURN);
        expression_opt();
    } else {
        parse_error(RETURN_STMT);
    }
}

void MJRecursiveParser::expression_list_comma() {
    if (lookup(TOK_COMMA)) {
        expect(TOK_COMMA);
        expression();
        expression_list_comma();
    }
}

void MJRecursiveParser::actual_params_list() {
    if(lookup(TOK_LPAREN) || lookup(TOK_PLUS) ||
       lookup(TOK_MINUS) || lookup(TOK_NOT) ||
       lookup(TOK_INTEGERCONSTANT) || lookup(TOK_STRINGCONSTANT) ||
       lookup(TOK_IDENTIFIER)) {
        expression();
        expression_list_comma();
    }
}

void MJRecursiveParser::method_call_stmt() {
    if (lookup(TOK_LPAREN)) {
        expect(TOK_LPAREN);
        actual_params_list();
        expect(TOK_RPAREN);
    } else {
        parse_error(METHOD_CALL_STMT);
    }
}

void MJRecursiveParser::assign_stmt() {
    if (lookup(TOK_ASSIGN)) {
        expect(TOK_ASSIGN);
        expression();
    } else {
        parse_error(ASSIGN_STMT);
    }
}

void MJRecursiveParser::variable_start_stmt() {
    if (lookup(TOK_ASSIGN)) {
        assign_stmt();
    } else if (lookup(TOK_LPAREN)) {
        method_call_stmt();
    } else {
        parse_error(VARIABLE_START_STMT);
    }
}

void MJRecursiveParser::stmt() {

    if (lookup(TOK_IDENTIFIER)) {
        variable();
        variable_start_stmt();
    } else if (lookup(TOK_RETURN)) {
        return_stmt(); 
    } else if (lookup(TOK_IF)) {
        if_stmt();
    } else if (lookup(TOK_WHILE)) {
        while_stmt();
    } else if (lookup(TOK_FOR)) {
        for_stmt();
    } else if (lookup(TOK_SWITCH)) {
        switch_stmt(); 
    } else if (lookup(TOK_PRINT)) {
        print_stmt();
    } else if (lookup(TOK_READ)) {
        read_stmt();
    } else {
        parse_error(STMT);
    }
}

void MJRecursiveParser::stmt_list_semicolon() {
    if (lookup(TOK_SEMICOLON)) {
        expect(TOK_SEMICOLON);
        stmt();
        stmt_list_semicolon();
    }
}

void MJRecursiveParser::stmt_list() {
    if (lookup(TOK_LCURLY)) {
        expect(TOK_LCURLY);
        stmt();
        stmt_list_semicolon();
        expect(TOK_RCURLY);
    } else {
        parse_error(STMT_LIST);
    }
}

void MJRecursiveParser::block() {
    if (lookup(TOK_DECLARATIONS) || lookup(TOK_LCURLY)) {
        decls_opt(); 
        stmt_list();
    } else {
        parse_error(BLOCK);
    }
}

void MJRecursiveParser::array_dim_decl_list() {
    if (lookup(TOK_LSQUARE)) {
        array_dim_decl();
        array_dim_decl_list();
    }
}

void MJRecursiveParser::array_dim_decl() {
    if (lookup(TOK_LSQUARE)) {
        expect(TOK_LSQUARE);
        expression();
        expect(TOK_RSQUARE);
    } else {
        parse_error(ARRAY_DIM_DECL);
    }
}

void MJRecursiveParser::array_creation_expr() {
    if (lookup(TOK_ARROBA)) {
        expect(TOK_ARROBA);
        type();
        array_dim_decl();
        array_dim_decl_list(); 
    } else {
        parse_error(ARRAY_CREATION_EXPR);
    }
}

void MJRecursiveParser::var_init_list_comma() {
    if (lookup(TOK_COMMA)) {
        expect(TOK_COMMA);
        var_init();
        var_init_list_comma();
    }
}

void MJRecursiveParser::array_init() {
    if (lookup(TOK_LCURLY)) {
        expect(TOK_LCURLY);
        var_init();
        var_init_list_comma();
        expect(TOK_RCURLY); 
    } else {
        parse_error(ARRAY_INIT);
    }
}

void MJRecursiveParser::var_init() {
    if(lookup(TOK_LPAREN) || lookup(TOK_PLUS) ||
       lookup(TOK_MINUS) || lookup(TOK_NOT) ||
       lookup(TOK_INTEGERCONSTANT) || lookup(TOK_STRINGCONSTANT) ||
       lookup(TOK_IDENTIFIER)) {
        expression();
    } else if (lookup(TOK_LCURLY)) {
        array_init();
    } else if (lookup(TOK_ARROBA)) {
        array_creation_expr();
    } else {
        parse_error(VAR_INIT);
    }
}

void MJRecursiveParser::var_decl_id() {
    if (lookup(TOK_IDENTIFIER)) {
        expect(TOK_IDENTIFIER);
        brackets_opt();
    } else {
        parse_error(VAR_DECL_ID);
    }
}

void MJRecursiveParser::val_opt() {
    if (lookup(TOK_VAL)) {
        expect(TOK_VAL);
    }
}

void MJRecursiveParser::formal_params_list_opt() {
    if (lookup(TOK_IDENTIFIER) || lookup(TOK_VAL) || 
        lookup(TOK_INT) || lookup(TOK_STRING)) {
        formal_params_list();
    }
}

void MJRecursiveParser::id_list_comma() {
    if (lookup(TOK_COMMA)) {
        expect(TOK_COMMA);
        expect(TOK_IDENTIFIER);
        id_list_comma();
    }    
}

void MJRecursiveParser::formal_params_list_aux() {
    if (lookup(TOK_SEMICOLON)) {
        expect(TOK_SEMICOLON);
        formal_params_list();
    }
}

void MJRecursiveParser::formal_params_list() {
    if (lookup(TOK_VAL) || lookup(TOK_IDENTIFIER) ||
        lookup(TOK_INT) || lookup(TOK_STRING)) {
        val_opt();
        type();
        expect(TOK_IDENTIFIER);
        id_list_comma();
        formal_params_list_aux();
    } else {
        parse_error(FORMAL_PARAMS_LIST);
    }    
}

void MJRecursiveParser::method_return_type() {
    if (lookup(TOK_VOID)) {
        expect(TOK_VOID);
    } else if (lookup(TOK_INT) || lookup(TOK_STRING) || lookup(TOK_IDENTIFIER)) {
        type();
    } else {
        parse_error(METHOD_RETURN_TYPE);
    }
}

void MJRecursiveParser::method_decl() {
    if (lookup(TOK_METHOD)) {
        expect(TOK_METHOD);
        method_return_type();
        expect(TOK_IDENTIFIER);
        expect(TOK_LPAREN); 
        formal_params_list_opt();
        expect(TOK_RPAREN);
        block();
    } else {
        parse_error(METHOD_DECL);
    }
}

void MJRecursiveParser::brackets_opt() {
    if (lookup(TOK_LRSQUARE)) {
        expect(TOK_LRSQUARE);
        brackets_opt();
    }
}

void MJRecursiveParser::type_aux() {
    if (lookup(TOK_IDENTIFIER))
        expect(TOK_IDENTIFIER);
    else if (lookup(TOK_INT)) 
        expect(TOK_INT);
    else if (lookup(TOK_STRING))
        expect(TOK_STRING);
    else {
        parse_error(TYPE_AUX);
    };
}

void MJRecursiveParser::type() {
    if (lookup(TOK_IDENTIFIER) || 
        lookup(TOK_INT) ||
        lookup(TOK_STRING)) {
        type_aux();
        brackets_opt();
    }
}

void MJRecursiveParser::field_decl_aux_2() {
    if (lookup(TOK_COMMA)) {
        expect(TOK_COMMA);  
        var_decl_id();
        field_decl_aux_1();
    }
}

void MJRecursiveParser::field_decl_aux_1() {
    if (lookup(TOK_COMMA)) {
        field_decl_aux_2();
    } else if (lookup(TOK_EQUALS)) {
        expect(TOK_EQUALS);
        var_init();
        field_decl_aux_2();
    }
}

void MJRecursiveParser::field_decl() {
    if (lookup(TOK_IDENTIFIER) || 
        lookup(TOK_INT) ||
        lookup(TOK_STRING)) {
        type();
        var_decl_id();
        field_decl_aux_1();
    } else {
        parse_error(FIELD_DECL);
    }
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

void MJRecursiveParser::method_decl_list() {
    if (lookup(TOK_METHOD)) {
        method_decl();
        method_decl_list();
    }
}

void MJRecursiveParser::decls() {
    if (lookup(TOK_DECLARATIONS)) {
        expect(TOK_DECLARATIONS);
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

void MJRecursiveParser::class_body() {
    if (lookup(TOK_LCURLY)) {
        expect(TOK_LCURLY);
        decls_opt();
        method_decl_list();
        expect(TOK_RCURLY);
    } else {
        parse_error(CLASS_BODY);
    }
}

void MJRecursiveParser::class_decl(){
    if (lookup(TOK_CLASS)) {
        expect(TOK_CLASS);
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
        //expect(END_OF_FILE);       
    } else {
        parse_error(PROGRAM);
    }
}
