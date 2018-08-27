#ifndef __NONTERM__
#define __NONTERM__

enum MJNonterminal {
    PROGRAM = 1000,
    CLASS_DECL_LIST,
    CLASS_DECL,
    CLASS_BODY,
    DECLS_OPT,
    DECLS,
    METHOD_DECL_LIST,
    FIELD_DECL_LIST_DECLS,
    FIELD_DECL,
    FIELD_DECL_AUX1,
    FIELD_DECL_AUX2,
    TYPE,
    TYPE_AUX,
    BRACKETS_OPT,
    METHOD_DECL,
    METHOD_RETURN_TYPE,
    FORMAL_PARAMS_LIST,
    FORMAL_PARAMS_LIST_AUX,
    ID_LIST_COMMA,
    FORMAL_PARAMS_LIST_OPT,
    VAR_DECL_ID,
    VAR_INIT,
    ARRAY_INIT,
    VAR_INIT_LIST_COMMA,
    ARRAY_CREATION_EXPR,
    ARRAY_DIM_DECL,
    ARRAY_DIM_DECL_LIST,
    BLOCK,
    STMT_LIST,
    STMT_LIST_SEMICOLON,
    STMT,
    VAL_OPT,
    VARIABLE_START_STMT,
    ASSIGN_STMT,
    METHOD_CALL_STMT,
    ACTUAL_PARAMS_LIST,
    EXPRESSION_LIST_COMMA,
    RETURN_STMT,
    EXPRESSION_OPT,
    IF_STMT,
    ELSE_PART,
    IF_STMT_AUX,
    FOR_STMT,
    FOR_INIT_EXPR,
    STEP_OPT,
    WHILE_STMT,
    SWITCH_STMT,
    CASE,
    CASE_LIST,
    PRINT_STMT,
    READ_STMT,
    EXPRESSION,
    REL_EXPR,
    REL_EXPR_AUX,
    ADD_EXPR,
    ADD_EXPR_AUX,
    MULT_EXPR,
    MULT_EXPR_AUX,
    UNARY_EXPR,
    METHOD_CALL_OPT,
    REL_OP,
    UNARY_OP,
    ADD_OP,
    MULT_OP,
    UNSIG_LIT,
    VARIABLE,
    VARIABLE_AUX
};

#endif

