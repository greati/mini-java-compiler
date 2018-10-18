#ifndef __EXPR__
#define __EXPR__

#include "Node.h"
#include <memory>
#include <vector>
#include <exception>


template<typename T>
class ConstructList : public Node {
    protected:
        std::vector<std::shared_ptr<T>> constructs;
    public:
        ConstructList (Position _pos, std::vector<std::shared_ptr<T>> _constructs) 
        : Node {_pos}, constructs {_constructs} {}
        
        void push_back(std::shared_ptr<T> elem) {
            this->constructs.push_back(elem);
        }

	bool empty() {return constructs.empty();}
};

class Expr : public Node {

    public:
        Expr(Position _pos) : Node {_pos} {};

};

class AlExpr : public Expr {

    public:
        AlExpr(Position _pos) : Expr {_pos} {};

};

class ExprParen : public AlExpr {
    protected:
        std::shared_ptr<Expr> expr;
    public:
        ExprParen(Position _pos, std::shared_ptr<Expr> _expr)
        : AlExpr {_pos}, expr {_expr} {}
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
        std::shared_ptr<ConstructList<Expr>> expressionList; 
        std::shared_ptr<AccessOperation> accessOperation;

    public:
        BracketAccess(
                Position _pos, 
                std::shared_ptr<ConstructList<Expr>> _expressionList,
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
        std::shared_ptr<ConstructList<Expr>> actualParams;
    public:
        FunctionCallExpr(
                Position _pos,
                std::shared_ptr<Var> _var,
                std::shared_ptr<ConstructList<Expr>> _actualParams) 
        : AlExpr{_pos}, var{_var}, actualParams{_actualParams}{}
};


class Stmt : public Node {
    public:
        Stmt(Position _pos) : Node {_pos} {};
};

class AssignStmt : public Stmt {
    protected:
	std::shared_ptr<Var> var;
	std::shared_ptr<Expr> expr;
    public:
        AssignStmt(
            Position _pos,
	    std::shared_ptr<Var> _var,
	    std::shared_ptr<Expr> _expr)
	: Stmt {_pos}, var {_var}, expr {_expr} {}
};

class FunctionCallStmt : public Stmt {
    protected:
        std::shared_ptr<Var> var;
        std::shared_ptr<ConstructList<Expr>> actualParams;
    public:
        FunctionCallStmt(
                Position _pos,
                std::shared_ptr<Var> _var,
                std::shared_ptr<ConstructList<Expr>> _actualParams) 
        : Stmt{_pos}, var{_var}, actualParams{_actualParams}{}
};



class ReadStmt : public Stmt {
    protected:
        std::string id;
    public:
        ReadStmt(Position _pos, std::string _id) : Stmt {_pos}, id{_id} {}
};

class PrintStmt : public Stmt {
    protected:
	std::shared_ptr<Expr> expr;
    public:
        PrintStmt(Position _pos, std::shared_ptr<Expr> _expr)
		: Stmt {_pos}, expr{_expr} {}
};

class Case : public Node {
    protected:
	std::shared_ptr<Expr> expr;
	std::shared_ptr<ConstructList<Stmt>> stmts;
    public:
        Case(
                Position _pos,
                std::shared_ptr<Expr> _expr,
                std::shared_ptr<ConstructList<Stmt>> _stmts)
            : Node {_pos}, expr {_expr}, stmts {_stmts} {}
};

class SwitchStmt : public Stmt {
    protected:
	std::shared_ptr<Expr> expr;
        std::shared_ptr<ConstructList<Case>> caseList;
        std::shared_ptr<ConstructList<Stmt>> defaultStmts;
    public:
        SwitchStmt(
                Position _pos,
                std::shared_ptr<Expr> _expr,
                std::shared_ptr<ConstructList<Case>> _caseList,
                std::shared_ptr<ConstructList<Stmt>> _defaultsStmts) 
        : Stmt{_pos}, expr {_expr}, defaultStmts {_defaultsStmts} {

            if (_caseList->empty()) 
                throw std::invalid_argument("case list can't be empty in a switch");
            else
                this->caseList = _caseList;

        }
};

class WhileStmt : public Stmt {
    protected:
	std::shared_ptr<Expr> expr;
        std::shared_ptr<ConstructList<Stmt>> stmts;
    public:
        WhileStmt(
                Position _pos,
                std::shared_ptr<Expr> _expr,
                std::shared_ptr<ConstructList<Stmt>> _stmts)
            : Stmt {_pos}, expr {_expr}, stmts {_stmts} {}
};

class ForStmt : public Stmt {
    protected:
        std::string id;
	std::shared_ptr<Expr> assignExpr;
	std::shared_ptr<Expr> toExpr;
        std::shared_ptr<Expr> stepExpr;
        std::shared_ptr<ConstructList<Stmt>> stmts;
    public:
        ForStmt(
                Position _pos,
                std::string _id,
                std::shared_ptr<Expr> _assignExpr,
                std::shared_ptr<Expr> _toExpr,
                std::shared_ptr<Expr> _stepExpr,
                std::shared_ptr<ConstructList<Stmt>> _stmts)
            : Stmt {_pos}, id {_id}, assignExpr {_assignExpr}, 
            toExpr{_toExpr}, stepExpr{_stepExpr}, stmts {_stmts} {}
};

class ElsePart : public Node {
    public:
        ElsePart(Position _pos) : Node {_pos} {}
};

class Else : public ElsePart {
    protected:
        std::shared_ptr<ConstructList<Stmt>> stmts;
    public:
        Else (
                Position _pos,
                std::shared_ptr<ConstructList<Stmt>> _stmts) 
            : ElsePart {_pos}, stmts {_stmts} {}
};

class IfStmt : public Stmt {
    protected:
	std::shared_ptr<Expr> expr;
	std::shared_ptr<ConstructList<Stmt>> stmts;
	std::shared_ptr<ElsePart> elsePart;
    public:
	IfStmt (
		Position _pos,
		std::shared_ptr<Expr> _expr,
		std::shared_ptr<ConstructList<Stmt>> _stmts,
		std::shared_ptr<ElsePart> _elsePart)
	    : Stmt {_pos}, expr {_expr}, stmts {_stmts}, elsePart {_elsePart} {}
};

class ElseIf : public ElsePart {
    protected:
	std::shared_ptr<IfStmt> ifStmt;
    public:
        ElseIf(
                Position _pos,
                std::shared_ptr<IfStmt> _ifStmt) 
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
        ConstructList<FieldDeclVar> varsDecls;
    public:
        FieldDecl (
            Position _pos,
            Type _type,
            ConstructList<FieldDeclVar> _varDecls) 
        : Node {_pos}, type {_type}, varsDecls {_varDecls} {} 
};

class Decls : public Node {
    protected:
        ConstructList<FieldDecl> fields;
    public:
        Decls(
            Position _pos,
            ConstructList<FieldDecl> _fields) 
        : Node {_pos}, fields{_fields} {}
};

class FormalParams : public Node {

    protected:
        bool val;
        Type type;
        ConstructList<std::string> ids;
    public:
        FormalParams (
            Position _pos,
            Type _type,
            ConstructList<std::string> _ids) 
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
        ConstructList<FormalParams> params;
        Block block;
    public:
        MethodDecl(
            Position _pos,
            MethodReturnType _returnType,
            std::string _id,
            ConstructList<FormalParams> _params,
            Block _block) 
        : Node {_pos}, returnType {_returnType}, id {_id}, params {_params}, block {_block} {}
};

class ClassBody : public Node {
    protected:
        std::shared_ptr<Decls> decls;
        ConstructList<MethodDecl> methods;
    public:
        ClassBody (
            Position _pos,
            std::shared_ptr<Decls> _decls,
            ConstructList<MethodDecl> _methods) 
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
        ConstructList<ClassDecl> classes;
    public:
        Program (
            Position _pos,
            std::string _id,
            ConstructList<ClassDecl> _classes) 
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
        ConstructList<VarInit> arrayInit;
    public:
        ArrayInitVarInit (Position _pos, ConstructList<VarInit> _arrayInit) 
        : VarInit {_pos}, arrayInit {_arrayInit} {}
};

class ArrayCreation : public Node {
    protected:
	std::shared_ptr<Type> type;
	std::shared_ptr<ConstructList<Expr>> dims;
    public:
        ArrayCreation(
            Position _pos, 
            std::shared_ptr<Type> _type, 
            std::shared_ptr<ConstructList<Expr>> _dims)
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
