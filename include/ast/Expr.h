#ifndef __EXPR__
#define __EXPR__

#include "Node.h"
#include <memory>
#include <vector>
#include <exception>

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
        std::vector<Expr> expressionList;
        std::shared_ptr<AccessOperation> accessOperation;

    public:
        BracketAccess(
                Position _pos, 
                std::vector<Expr> _expressionList,
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

class ActualParamsList : public Node {}; //TODO

class FunctionCallExpr : public AlExpr {
    protected:
        Var var;
        ActualParamsList actualParams;
    public:
        FunctionCallExpr(
                Position _pos,
                Var _var,
                ActualParamsList _actualParams) 
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

#endif
