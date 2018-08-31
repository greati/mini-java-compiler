#ifndef __MJRECPARSER__
#define __MJRECPARSER__

#include "MJLL1Parser.h"
#include <string>
#include <memory>

/**
 * Top-down recursive parser for the Mini-Java language.
 *
 * @autor Vitor Greati
 * @date 2018-08-23
 * */
class MJRecursiveParser : public MJLL1Parser {

    public:

        MJRecursiveParser(std::shared_ptr<Lexer> _lexer) : MJLL1Parser{_lexer} {}

        ~MJRecursiveParser(){}

    private:

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
         * Consume an input if the current symbol
         * matches the argument, and outputs an error
         * and returns false otherwise.
         *
         * @param token Token
         * @return if argument matches the input
         * */
        bool expect(MJToken token);
        bool expect(MJToken token, MJNonterminal curnonterm);

        /**
         * Check the current input symbol without
         * consuming it anyway.
         *
         * @param token The token
         * @return if the current token is equals to the param
         * */
        bool lookup(MJToken token);

        /**
         * Grammar implementation.
         *
         * */
        void program();
        void class_decl_list();
        void class_decl();
        void class_body();
        void decls_opt();
        void decls();
        void method_decl_list();
        void field_decl_list_decls();
        void field_decl();
        void field_decl_aux_1();
        void field_decl_aux_2();
        void type();
        void type_aux();
        void brackets_opt();
        void method_decl();
        void method_return_type();
        void formal_params_list();
        void formal_params_list_aux();
        void id_list_comma();
        void formal_params_list_opt();
        void val_opt();
        void var_decl_id();
        void var_init();
        void array_init();
        void var_init_list_comma();
        void array_creation_expr();
        void array_dim_decl();
        void array_dim_decl_list();
        void block();
        void stmt_list();
        void stmt_list_semicolon();
        void stmt();
        void variable_start_stmt();
        void assign_stmt();
        void method_call_stmt();
        void actual_params_list();
        void expression_list_comma();
        void return_stmt();
        void expression_opt();
        void if_stmt();
        void else_part();
        void if_stmt_aux();
        void for_stmt();
        void for_init_expr();
        void step_opt();
        void while_stmt();
        void switch_stmt();
        void _case();
        void case_list();
        void print_stmt();
        void read_stmt();
        void expression();
        void rel_expr();
        void rel_expr_aux();
        void add_expr();
        void add_expr_aux();
        void mult_expr();
        void mult_expr_aux();
        void unary_expr();
        void rel_op();
        void method_call_opt();
        void unary_op();
        void add_op();
        void mult_op();
        void unsig_lit();
        void variable();
        void variable_aux();

    protected:

        void _parse(std::string) override;

};

#endif
