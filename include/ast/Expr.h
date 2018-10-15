#ifndef __EXPR__
#define __EXPR__

#include "Node.h"
#include <memory>
#include <vector>
#include <exception>


template<typename T>
class NullableConstructList : public Node {
    protected:
        std::vector<T> constructs;
    public:
        NullableConstructList (Position _pos, std::vector<T> _constructs) 
        : Node {_pos}, constructs {_constructs} {}
};

template<typename T>
class NonEmptyConstructList : public Node {
    protected:
        std::vector<T> constructs;
    public:
        NonEmptyConstructList (Position _pos, std::vector<T> _constructs) 
        : Node {_pos}, constructs {_constructs} {
            if (_constructs.empty())
                throw std::invalid_argument("this list can't be empty");
            else
                this->constructs = _constructs;
        }
};

class Expr : public Node {

    public:
        Expr(Position _pos) : Node {_pos} {};

};

class AlExpr : public Expr {

    public:
        AlExpr(Position _pos) : Expr {_pos} {};

};

class RelExpr : public Expr {

 
    public:

        enum class RelOp {
            LESS,
            LESS_EQ,
            EQEQ,
            GREATER,
            GREATER_EQ,
            DIFF
        };

   protected:

        RelOp op;
        std::shared_ptr<AlExpr> lhs;
        std::shared_ptr<AlExpr> rhs;

    public:
        RelExpr(Position _pos, RelOp _op, std::shared_ptr<AlExpr> _lhs, std::shared_ptr<AlExpr> _rhs) 
            : Expr {_pos}, op{_op}, lhs{_lhs}, rhs{_rhs} {}

};


class AlBinExpr : public AlExpr {

    public:

        enum class AlBinOp {
            PLUS,
            MINUS,
            TIMES,
            DIV,
            MOD,
            AND,
            OR            
        };

    protected:

        AlBinOp op;
        std::shared_ptr<AlExpr> lhs;
        std::shared_ptr<AlExpr> rhs;

    public:
        AlBinExpr(Position _pos, AlBinOp _op, std::shared_ptr<AlExpr> _lhs, std::shared_ptr<AlExpr> _rhs) 
            : AlExpr {_pos}, op{_op}, lhs{_lhs}, rhs{_rhs} {}
};

class AlUnExpr : public AlExpr {
    
    public:
        
        enum class AlUnOp {
            PLUS,
            MINUS,
            NOT
        };

    protected:
        
        AlUnOp op;
        std::shared_ptr<AlExpr> alexpr;

    public:
        AlUnExpr(Position _pos, AlUnOp _op, std::shared_ptr<AlExpr> _alexpr) 
            : AlExpr{_pos}, op{_op}, alexpr{_alexpr} {};
};

template<typename T>
class LitExpr : public AlExpr {

    protected:
        T val;

    public:
        LitExpr(Position _pos, T _val) : AlExpr{_pos}, val {_val} {}
};



class AccessOperation : public Node {
    public:
        AccessOperation(Position _pos) : Node {_pos} {};
};

class BracketAccess : public AccessOperation {
    
    protected:
        std::shared_ptr<NonEmptyConstructList<Expr>> expressionList; 
        std::shared_ptr<AccessOperation> accessOperation;

    public:
        BracketAccess(
                Position _pos, 
                std::shared_ptr<NonEmptyConstructList<Expr>> _expressionList,
                std::shared_ptr<AccessOperation> _accessOperation) 
            : AccessOperation{_pos}, expressionList{_expressionList}, accessOperation{_accessOperation} {}
};

class DotAccess : public AccessOperation {
    protected:
        std::string id;
        std::shared_ptr<AccessOperation> accessOperation;
    public:
        DotAccess(
                Position _pos, 
                std::string _id,
                std::shared_ptr<AccessOperation> _accessOperation) 
            : AccessOperation{_pos}, id{_id}, accessOperation{_accessOperation} {}
};

class Var : public AlExpr {
    protected:
        std::string id;
        std::shared_ptr<AccessOperation> accessOperation;
    public:
        Var(
                Position _pos, 
                std::string _id,
                std::shared_ptr<AccessOperation> _accessOperation) 
            : AlExpr{_pos}, id{_id}, accessOperation{_accessOperation} {}
};

class FunctionCallExpr : public AlExpr {
    protected:
        std::shared_ptr<Var> var;
        std::shared_ptr<NullableConstructList<Expr>> actualParams;
    public:
        FunctionCallExpr(
                Position _pos,
                std::shared_ptr<Var> _var,
                std::shared_ptr<NullableConstructList<Expr>> _actualParams) 
        : AlExpr{_pos}, var{_var}, actualParams{_actualParams}{}
};


class Stmt : public Node {
    public:
        Stmt(Position _pos) : Node {_pos} {};
};

class ReadStmt : public Stmt {
    protected:
        std::string id;
    public:
        ReadStmt(Position _pos, std::string _id) : Stmt {_pos}, id{_id} {}
};

class PrintStmt : public Stmt {
    protected:
        Expr expr;
    public:
        PrintStmt(Position _pos, Expr _expr) : Stmt {_pos}, expr{_expr} {}
};

class Case : public Node {
    protected:
        Expr expr;
        std::vector<Stmt> stmts;
    public:
        Case(
                Position _pos,
                Expr _expr,
                std::vector<Stmt> _stmts)
            : Node {_pos}, expr {_expr}, stmts {_stmts} {}
};

class SwitchStmt : public Stmt {
    protected:
        Expr expr;
        std::vector<Case> caseList;
        std::vector<Stmt> defaultStmts;
    public:
        SwitchStmt(
                Position _pos,
                Expr _expr,
                std::vector<Case> _caseList,
                std::vector<Stmt> _defaultsStmts) 
        : Stmt{_pos}, expr {_expr}, defaultStmts {_defaultsStmts} {

            if (_caseList.empty()) 
                throw std::invalid_argument("case list can't be empty in a switch");
            else
                this->caseList = _caseList;

        }
};

class WhileStmt : public Stmt {
    protected:
        Expr expr;
        std::vector<Stmt> stmts;
    public:
        WhileStmt(
                Position _pos,
                Expr _expr,
                std::vector<Stmt> _stmts)
            : Stmt {_pos}, expr {_expr}, stmts {_stmts} {}
};

class ForStmt : public Stmt {
    protected:
        std::string id;
        Expr assignExpr;
        Expr toExpr;
        std::shared_ptr<Expr> stepExpr;
        std::vector<Stmt> stmts;
    public:
        ForStmt(
                Position _pos,
                std::string _id,
                Expr _assignExpr,
                Expr _toExpr,
                std::shared_ptr<Expr> _stepExpr,
                std::vector<Stmt> _stmts)
            : Stmt {_pos}, id {_id}, assignExpr {_assignExpr}, 
            toExpr{_toExpr}, stepExpr{_stepExpr}, stmts {_stmts} {}
};

class ElsePart : public Node {
    public:
        ElsePart(Position _pos) : Node {_pos} {}
};

class Else : public ElsePart {
    protected:
        std::vector<Stmt> stmts;
    public:
        Else (
                Position _pos,
                std::vector<Stmt> _stmts) 
            : ElsePart {_pos}, stmts {_stmts} {}
};

class IfStmt : public Stmt {
    protected:
        Expr expr;
        std::vector<Stmt> stmts;
        ElsePart elsePart;
};

class ElseIf : public ElsePart {
    protected:
        IfStmt ifStmt;
    public:
        ElseIf(
                Position _pos,
                IfStmt _ifStmt) 
            : ElsePart {_pos}, ifStmt {_ifStmt} {}
};

class ReturnStmt : public Stmt {
    protected:
        std::shared_ptr<Expr> expr;
    public:
        ReturnStmt (
                Position _pos,
                std::shared_ptr<Expr> _expr)
            : Stmt {_pos}, expr {_expr} {}
};



class Type : public Node {
    protected:
        int numBrackets;
        std::string typeName;
    public:
        Type(
            Position _pos,
            std::string _typeName)
        : Node {_pos}, typeName {_typeName} {}
};

class VarDeclId : public Node {
    protected:
        std::string id;
        int numBrackets;
    public:
        VarDeclId(Position _pos, std::string _id, int _numBrackets) 
        : Node {_pos}, id {_id}, numBrackets {_numBrackets} {}
};


class VarInit : public Node {
    public:
        VarInit(Position _pos) : Node {_pos} {}
};

class FieldDeclVar : public Node {
    protected:
        VarDeclId varDeclId;
        std::shared_ptr<VarInit> varInit;
    public:
        FieldDeclVar (
            Position _pos,
            VarDeclId _varDeclId,
            std::shared_ptr<VarInit> _varInit) 
        : Node {_pos}, varDeclId {_varDeclId}, varInit {_varInit} {}
};

class FieldDecl : public Node {
    protected:
        Type type;
        NonEmptyConstructList<FieldDeclVar> varsDecls;
    public:
        FieldDecl (
            Position _pos,
            Type _type,
            NonEmptyConstructList<FieldDeclVar> _varDecls) 
        : Node {_pos}, type {_type}, varsDecls {_varDecls} {} 
};

class Decls : public Node {
    protected:
        NullableConstructList<FieldDecl> fields;
    public:
        Decls(
            Position _pos,
            NullableConstructList<FieldDecl> _fields) 
        : Node {_pos}, fields{_fields} {}
};

class FormalParams : public Node {

    protected:
        bool val;
        Type type;
        NonEmptyConstructList<std::string> ids;
    public:
        FormalParams (
            Position _pos,
            Type _type,
            NonEmptyConstructList<std::string> _ids) 
        : Node {_pos}, type {_type}, ids{_ids} {}

};

class Block : public Node {

    protected:
        std::shared_ptr<Decls> decls;
        std::vector<Stmt> stmts;
    public:
        Block(
            Position _pos,
            std::shared_ptr<Decls> _decls,
            std::vector<Stmt> _stmts) 
        : Node {_pos}, decls {_decls}, stmts {_stmts} {}
};

class MethodReturnType : public Node {
    protected:
        std::shared_ptr<Type> type;
    public:
        MethodReturnType(Position _pos, std::shared_ptr<Type> _type)
        : Node {_pos}, type {_type} {}
    
};

class MethodDecl : public Node {
    protected:
        MethodReturnType returnType;
        std::string id;
        NullableConstructList<FormalParams> params;
        Block block;
    public:
        MethodDecl(
            Position _pos,
            MethodReturnType _returnType,
            std::string _id,
            NullableConstructList<FormalParams> _params,
            Block _block) 
        : Node {_pos}, returnType {_returnType}, id {_id}, params {_params}, block {_block} {}
};

class ClassBody : public Node {
    protected:
        std::shared_ptr<Decls> decls;
        NullableConstructList<MethodDecl> methods;
    public:
        ClassBody (
            Position _pos,
            std::shared_ptr<Decls> _decls,
            NullableConstructList<MethodDecl> _methods) 
        : Node {_pos}, decls {_decls}, methods {_methods} {}
};

class ClassDecl : public Node {
    protected:
        std::string id;
        ClassBody body;
    public:
        ClassDecl (
            Position _pos,
            std::string _id,
            ClassBody _body) 
        : Node {_pos}, id {_id}, body {_body} {} 
};

class Program : public Node {
    protected:
        std::string id;
        NonEmptyConstructList<ClassDecl> classes;
    public:
        Program (
            Position _pos,
            std::string _id,
            NonEmptyConstructList<ClassDecl> _classes) 
        : Node {_pos}, id {_id}, classes {_classes} {}
};

class ExprVarInit : public VarInit {
    protected:
        Expr expr;
    public:
        ExprVarInit (Position _pos, Expr _expr) 
        : VarInit {_pos}, expr {_expr} {}
};

class ArrayInitVarInit : public VarInit {
    protected:
        NullableConstructList<VarInit> arrayInit;
    public:
        ArrayInitVarInit (Position _pos, NullableConstructList<VarInit> _arrayInit) 
        : VarInit {_pos}, arrayInit {_arrayInit} {}
};

class ArrayCreation : public Node {
    protected:
        Type type;
        NonEmptyConstructList<Expr> dims;
    public:
        ArrayCreation(
            Position _pos, 
            Type _type, 
            NonEmptyConstructList<Expr> _dims)
        : Node {_pos}, type {_type}, dims {_dims} {}
};

class ArrayCreationVarInit : public VarInit {
     protected:
        ArrayCreation arrayInit;
    public:
        ArrayCreationVarInit (Position _pos, ArrayCreation _arrayCreation) 
        : VarInit {_pos}, arrayInit {_arrayCreation} {}
};


#endif
