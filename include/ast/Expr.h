#ifndef __EXPR__
#define __EXPR__

#include "Node.h"
#include <memory>

class Expr : public Node {

    public:
        Expr(Node::Position _pos) : Node {_pos} {};

};

class RelExpr : public Expr {

    protected:

        RelOp op;
        std::shared_ptr<AlExpr> lhs;
        std::shared_ptr<AlExpr> rhs;

    public:

        enum class RelOp {
            LESS,
            LESS_EQ,
            EQEQ,
            GREATER,
            GREATER_EQ,
            DIFF
        };

        RelExpr(Node::Position _pos, RelOp _op, std::shared_ptr<AlExpr> _lhs, std::shared_ptr<AlExpr> _rhs) 
            : Expr {_pos}, op{_op}, lhs{_lhs}, rhs{_rhs} {}

};

class AlExpr : public Expr {

    public:
        AlExpr(Node::Position _pos) : Expr {_pos} {};

};

class AlBinExpr : public AlExpr {

    protected:

        AlBinOp op;
        std::shared_ptr<AlExpr> lhs;
        std::shared_ptr<AlExpr> rhs;

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

        AlExpr(Node::Position _pos, AlBinOp _op, std::shared_ptr<AlExpr> _lhs, std::shared_ptr<AlExpr> _rhs) 
            : AlExpr {_pos}, op{_op}, lhs{_lhs}, rhs{_rhs} {}
};

class AlUnExpr : public AlExpr {
    
    protected:
        
        AlUnOp op;
        std::shared_ptr<AlExpr> alexpr;
        
    public:
        
        enum class AlUnOp {
            PLUS,
            MINUS,
            NOT
        };

        AlUnExpr(Node::Position _pos, AlUnOp _op, std::shared_ptr<AlExpr> _alexpr) 
            : AlExpr{_pos}, op{_op}, alexpr{_alexpr} {};
};

template<typename T>
class LitExpr : public AlExpr {

    protected:
        T val;

    public:
        LitExpr(Node::Position _pos, T _val) : AlExpr{_pos}, val {_val} {}
};

class AccessOperation : public Node {
    public:
        AccessOperation(Node::Position _pos) : Node {_pos} {};
}

class BracketAccess : public AccessOperation {
    
    protected:
        std::vector<Expr> expressionList;
        std::shared_ptr<AccessOperation> accessOperation;

    public:
        BracketAccess(
                Node::Position _pos, 
                std::vector _expressionList,
                std::shared_ptr<AccessOperation> _accessOperation) 
            : AccessOperation{_pos}, expressionList{_expressionList}, accessOperation{_accessOperation} {}
};

class DotAccess : public AccessOperation {
    protected:
        std::string id;
        std::shared_ptr<AccessOperation> accessOperation;
    public:
        DotAccess(
                Node::Position _pos, 
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
                Node::Position _pos, 
                std::string _id,
                std::shared_ptr<AccessOperation> _accessOperation) 
            : AccessOperation{_pos}, id{_id}, accessOperation{_accessOperation} {}
};

class FunctionCallExpr : public AlExpr {
    protected:
        Var var;
        ActualParamsList actualParams;
    public:
        FunctionCallExpr(
                Node::Position _pos,
                Var _var,
                ActualParamsList _actualParams) 
        : AlExpr{_pos}, var{_var}, actualParams{_actualParams}{}
};

class Stmt : public Node {
    public:
        Stmt(Node::Position _pos) : Node {_pos} {};
};


#endif
