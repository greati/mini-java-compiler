#ifndef __EXPR__
#define __EXPR__

#include "Node.h"
#include <memory>
#include <vector>
#include <exception>
#include <sstream>
#include <deque>

class Id : public Node {
    public:
        std::string id;
        Id (Position _pos, std::string _id) : Node {_pos}, id {_id} {}

        std::string show() const override {
            std::stringstream ss;
            ss << "idName: " << id << std::endl;
            return ss.str();
        }

        void computeLevel() override {};

        void accept(NodeVisitor & visitor) override;
};

class ConstructList : public Node {
    public:
        std::deque<std::shared_ptr<Node>> constructs;
        ConstructList (Position _pos, std::deque<std::shared_ptr<Node>> _constructs) 
        : Node {_pos}, constructs {_constructs} {}
        
        void push_back(std::shared_ptr<Node> elem) {
            this->constructs.push_back(elem);
        }

        void push_front(std::shared_ptr<Node> elem) {
            this->constructs.push_front(elem);
        }

        bool empty() {return constructs.empty();}

        std::string show() const override {
            std::stringstream ss;
            ss << "[" << std::endl;
            for (auto i : this->constructs) {
                if (i != nullptr)
                    ss << (*i) << std::endl;
            }
            ss << "]";
            return ss.str();
        }

        void computeLevel() override {
            for (auto i : this->constructs) {
                if (i != nullptr) {
                    (*i).level = this->level + 1;
                    (*i).computeLevel();
                }
            }
        }

        void accept(NodeVisitor & visitor) override;
};

class Expr : public Node {

    public:
        Expr(Position _pos) : Node {_pos} {};

        std::string show() const override {
            return "";
        }
        void computeLevel() override {};

        void accept(NodeVisitor & visitor) override;
};

class AlExpr : public Expr {

    public:
        AlExpr(Position _pos) : Expr {_pos} {};

        void accept(NodeVisitor & visitor) override;
};

class ExprParen : public AlExpr {
    public:
        std::shared_ptr<Expr> expr;
        ExprParen(Position _pos, std::shared_ptr<Expr> _expr)
        : AlExpr {_pos}, expr {_expr} {}

        std::string show() const override {
            return expr->show();
        }

        void computeLevel() override {
            expr->level = this->level + 1;
            expr->computeLevel();
        };

        void accept(NodeVisitor & visitor) override;
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


        RelOp op;
        std::shared_ptr<AlExpr> lhs;
        std::shared_ptr<AlExpr> rhs;

    public:
        RelExpr(Position _pos, RelOp _op, std::shared_ptr<AlExpr> _lhs, std::shared_ptr<AlExpr> _rhs) 
            : Expr {_pos}, op{_op}, lhs{_lhs}, rhs{_rhs} {}

        std::string show() const override {
            std::stringstream ss;
            ss << "op: ";
            switch (op) {
                case RelOp::LESS:
                    ss << "<";
                    break;
                case RelOp::LESS_EQ:
                    ss << "<=";
                    break;
                case RelOp::EQEQ:
                    ss << "==";
                    break;
                case RelOp::GREATER:
                    ss << ">";
                    break;
                case RelOp::GREATER_EQ:
                    ss << ">=";
                    break;
                case RelOp::DIFF:
                    ss << "!=";
                    break;
            }
            ss << std::endl;
            ss << "lhs" << *lhs << std::endl;
            ss << "rhs" << *rhs << std::endl;
            return ss.str();
        }
        void computeLevel() override {
            lhs->level = this->level + 1;
            rhs->level = this->level + 1;
            lhs->computeLevel();
            rhs->computeLevel();
        };

        void accept(NodeVisitor & visitor) override;
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


        AlBinOp op;
        std::shared_ptr<AlExpr> lhs;
        std::shared_ptr<AlExpr> rhs;

        AlBinExpr(Position _pos, AlBinOp _op, std::shared_ptr<AlExpr> _lhs, std::shared_ptr<AlExpr> _rhs) 
            : AlExpr {_pos}, op{_op}, lhs{_lhs}, rhs{_rhs} {}

        std::string show() const override {
            std::stringstream ss;
            ss << "op: ";
            switch (op) {
                case AlBinOp::PLUS:
                    ss << "+";
                    break;
                case AlBinOp::MINUS:
                    ss << "-";
                    break;
                case AlBinOp::TIMES:
                    ss << "*";
                    break;
                case AlBinOp::DIV:
                    ss << "/";
                    break;
                case AlBinOp::MOD:
                    ss << "%";
                    break;
                case AlBinOp::AND:
                    ss << "&&";
                    break;
                case AlBinOp::OR:
                    ss << "||";
                    break;
            }
            ss << std::endl;
            ss << "lhs: "<< *lhs << std::endl;
            ss << "rhs: " << *rhs << std::endl;
            return ss.str();
        }

        void computeLevel() override {
            lhs->level = this->level + 1;
            rhs->level = this->level + 1;
            lhs->computeLevel();
            rhs->computeLevel();
        };

        void accept(NodeVisitor & visitor) override;
};

class AlUnExpr : public AlExpr {
    
    public:
        
        enum class AlUnOp {
            PLUS,
            MINUS,
            NOT
        };

        AlUnOp op;
        std::shared_ptr<AlExpr> alexpr;

        AlUnExpr(Position _pos, AlUnOp _op, std::shared_ptr<AlExpr> _alexpr) 
            : AlExpr{_pos}, op{_op}, alexpr{_alexpr} {};

        std::string show() const override {
            std::stringstream ss;
            ss << "op: ";
            switch(op) {
                case AlUnOp::PLUS:
                    ss << "+";
                    break;
                case AlUnOp::MINUS:
                    ss << "-";
                    break;
                case AlUnOp::NOT:
                    ss << "not";
                    break;
            }
            ss << std::endl;
            ss << "expr: " << *alexpr << std::endl;
            return ss.str();
        }

        void computeLevel() override {
            alexpr->level = this->level + 1;
            alexpr->computeLevel();
        };

        void accept(NodeVisitor & visitor) override;
};

template<typename T>
class LitExpr : public AlExpr {

    public:
        T val;

        LitExpr(Position _pos, T _val) : AlExpr{_pos}, val {_val} {}

        std::string show() const override {
            std::stringstream ss;
            ss << "value: " << val << std::endl;
            return ss.str();
        }

        void computeLevel() override {}

        void accept(NodeVisitor & visitor) override;
};



class AccessOperation : public Node {
    public:
        AccessOperation(Position _pos) : Node {_pos} {};

        std::string show() const override {
            return "";
        }

        void computeLevel() override {};

        void accept(NodeVisitor & visitor) override;
};

class BracketAccess : public AccessOperation {
    
    protected:
        std::shared_ptr<ConstructList> expressionList; 
        std::shared_ptr<AccessOperation> accessOperation;

    public:
        BracketAccess(
                Position _pos, 
                std::shared_ptr<ConstructList> _expressionList,
                std::shared_ptr<AccessOperation> _accessOperation) 
            : AccessOperation{_pos}, expressionList{_expressionList}, accessOperation{_accessOperation} {}

        std::string show() const override {
            std::stringstream ss;
            ss << "exprList: " << *expressionList << std::endl;
            if (accessOperation != nullptr)
                ss << "accessOp: " << *accessOperation << std::endl;
            return ss.str();
        }

        void computeLevel() override {
            this->expressionList->level = this->level + 1;
            expressionList->computeLevel();
            if (accessOperation != nullptr) {
                this->accessOperation->level = this->level + 1;
                accessOperation->computeLevel();
            }
        }

        void accept(NodeVisitor & visitor) override;
};

class DotAccess : public AccessOperation {
    protected:
        std::shared_ptr<Id> id;
        std::shared_ptr<AccessOperation> accessOperation;
    public:
        DotAccess(
                Position _pos, 
                std::shared_ptr<Id> _id,
                std::shared_ptr<AccessOperation> _accessOperation) 
            : AccessOperation{_pos}, id{_id}, accessOperation{_accessOperation} {}

        std::string show() const override {
            std::stringstream ss;
            ss << "id: " << *id << std::endl;
            if (accessOperation != nullptr)
                ss << "accessOp: " << *accessOperation << std::endl;
            return ss.str();
        }

        void computeLevel() override {
            id->level = this->level + 1;
            id->computeLevel();
            if (accessOperation != nullptr) {
                accessOperation->level = this->level + 1;
                accessOperation->computeLevel();
            }
        }

        void accept(NodeVisitor & visitor) override;
};

class Var : public AlExpr {
    protected:
        std::shared_ptr<Id> id;
        std::shared_ptr<AccessOperation> accessOperation;
    public:
        Var(
                Position _pos, 
                std::shared_ptr<Id> _id,
                std::shared_ptr<AccessOperation> _accessOperation) 
            : AlExpr{_pos}, id{_id}, accessOperation{_accessOperation} {}

        std::string show() const override {
            std::stringstream ss;
            ss << "id: " << *id << std::endl;
            if (accessOperation != nullptr)
                ss << "accessOp: " << *accessOperation << std::endl;
            return ss.str();
        }

        void computeLevel() override {
            id->level = this->level + 1;
            id->computeLevel();
            if (accessOperation != nullptr) {
                accessOperation->level = this->level + 1;
                accessOperation->computeLevel();
            }
        }

        void accept(NodeVisitor & visitor) override;
};

class FunctionCallExpr : public AlExpr {
    protected:
        std::shared_ptr<Var> var;
        std::shared_ptr<ConstructList> actualParams;
    public:
        FunctionCallExpr(
                Position _pos,
                std::shared_ptr<Var> _var,
                std::shared_ptr<ConstructList> _actualParams) 
        : AlExpr{_pos}, var{_var}, actualParams{_actualParams}{}

        std::string show() const override {
            std::stringstream ss;
            ss << "var: " << *var << std::endl;
            if (actualParams != nullptr)
                ss << "actualParams: " << *actualParams << std::endl;
            return ss.str();
        }

        void computeLevel() override {
            var->level = this->level + 1;
            var->computeLevel();
            if (actualParams != nullptr) {
                actualParams->level = this->level + 1;
                actualParams->computeLevel();
            }
        }

        void accept(NodeVisitor & visitor) override;
};


class Stmt : public Node {
    public:
        Stmt(Position _pos) : Node {_pos} {};

        std::string show() const override {
            return "";
        }
        void computeLevel() override {};

        void accept(NodeVisitor &) override;
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

        std::string show() const override {
            std::stringstream ss;
            ss << "what: " << "assignStmt" << std::endl;
            ss << "var: " << *var << std::endl;
            ss << "expr: " << *expr << std::endl;
            return ss.str();
        }

        void computeLevel() override {
            var->level = this->level + 1;
            expr->level = this->level + 1;
            var->computeLevel();
            expr->computeLevel();
        }

        void accept(NodeVisitor & visitor) override;
};

class FunctionCallStmt : public Stmt {
    protected:
        std::shared_ptr<Var> var;
        std::shared_ptr<ConstructList> actualParams;
    public:
        FunctionCallStmt(
                Position _pos,
                std::shared_ptr<Var> _var,
                std::shared_ptr<ConstructList> _actualParams) 
        : Stmt{_pos}, var{_var}, actualParams{_actualParams}{}

        std::string show() const override {
            std::stringstream ss;
            ss << "what: " << "functionCallStmt" << std::endl;
            ss << "var: " << *var << std::endl;
            if (actualParams != nullptr)
                ss << "actualParams: " << *actualParams << std::endl;
            return ss.str();
        }

        void computeLevel() override {
            var->level = this->level + 1;
            var->computeLevel();
            if (actualParams != nullptr) {
                actualParams->level = this->level + 1;
                actualParams->computeLevel();
            }
        }

        void accept(NodeVisitor & visitor) override;
};

class ReadStmt : public Stmt {
    protected:
        std::shared_ptr<Id> id;
    public:
        ReadStmt(Position _pos, std::shared_ptr<Id> _id) : Stmt {_pos}, id{_id} {}

        std::string show() const override {
            std::stringstream ss;
            ss << "what: " << "readStmt" << std::endl;
            ss << "id: " << *id << std::endl;
            return ss.str();
        }

        void computeLevel() override {
            id->level = this->level + 1;
            id->computeLevel();
        }

        void accept(NodeVisitor & visitor) override;
};

class PrintStmt : public Stmt {
    public:
	std::shared_ptr<Expr> expr;
        PrintStmt(Position _pos, std::shared_ptr<Expr> _expr)
		: Stmt {_pos}, expr{_expr} {}

        std::string show() const override {
            std::stringstream ss;
            ss << "what: " << "printStmt" << std::endl;
            ss << "expr: " << *expr << std::endl;
            return ss.str();
        }
        void computeLevel() override {
            expr->level = this->level + 1;
            expr->computeLevel();
        }

        void accept(NodeVisitor & visitor) override;
};

class Case : public Node {
    public:
        std::shared_ptr<Expr> expr;
        std::shared_ptr<ConstructList> stmts;

        Case(
                Position _pos,
                std::shared_ptr<Expr> _expr,
                std::shared_ptr<ConstructList> _stmts)
            : Node {_pos}, expr {_expr}, stmts {_stmts} {}

        std::string show() const override {
            std::stringstream ss;
            ss << "what: " << "case" << std::endl;
            ss << "expr: " << *expr << std::endl;
            ss << "stmts: " << *stmts << std::endl;
            return ss.str();
        }
        void computeLevel() override {
            expr->level = this->level + 1;
            stmts->level = this->level + 1;
            expr->computeLevel();
            stmts->computeLevel();
        };

        void accept(NodeVisitor & visitor) override;
};

class SwitchStmt : public Stmt {
    public:
        std::shared_ptr<Expr> expr;
        std::shared_ptr<ConstructList> caseList;
        std::shared_ptr<ConstructList> defaultStmts;

        SwitchStmt(
                Position _pos,
                std::shared_ptr<Expr> _expr,
                std::shared_ptr<ConstructList> _caseList,
                std::shared_ptr<ConstructList> _defaultsStmts) 
        : Stmt{_pos}, expr {_expr}, defaultStmts {_defaultsStmts} {

            if (_caseList->empty()) 
                throw std::invalid_argument("case list can't be empty in a switch");
            else
                this->caseList = _caseList;

        }

        std::string show() const override {
            std::stringstream ss;
            ss << "what: " << "switchStmt" << std::endl;
            ss << "expr: " << *expr << std::endl;
            ss << "caseList: " << *caseList << std::endl;
            if (defaultStmts  != nullptr) 
                ss << "defaultStmts" << *defaultStmts << std::endl;
            return ss.str();
        }
        void computeLevel() override {
            expr->level = this->level + 1;
            expr->computeLevel();
            caseList->level = this->level + 1;
            caseList->computeLevel();
            if (defaultStmts != nullptr) {
                defaultStmts->level = this->level + 1;
                defaultStmts->computeLevel();
            }
        }

        void accept(NodeVisitor & visitor) override;
};

class WhileStmt : public Stmt {
    public:
        std::shared_ptr<Expr> expr;
        std::shared_ptr<ConstructList> stmts;

        WhileStmt(
                Position _pos,
                std::shared_ptr<Expr> _expr,
                std::shared_ptr<ConstructList> _stmts)
            : Stmt {_pos}, expr {_expr}, stmts {_stmts} {}

        std::string show() const override {
            std::stringstream ss;
            ss << "what: " << "whileStmt" << std::endl;
            ss << "expr: " << *expr << std::endl;
            return ss.str();
        }

        void computeLevel() override {
            expr->level = this->level + 1;
            stmts->level = this->level + 1;
            expr->computeLevel();
            stmts->computeLevel();
        }

        void accept(NodeVisitor & visitor) override;
};

class ForStmt : public Stmt {
    public:
        std::shared_ptr<Id> id;
        std::shared_ptr<Expr> assignExpr;
        std::shared_ptr<Expr> toExpr;
        std::shared_ptr<Expr> stepExpr;
        std::shared_ptr<ConstructList> stmts;

        ForStmt(
                Position _pos,
                std::shared_ptr<Id> _id,
                std::shared_ptr<Expr> _assignExpr,
                std::shared_ptr<Expr> _toExpr,
                std::shared_ptr<Expr> _stepExpr,
                std::shared_ptr<ConstructList> _stmts)
            : Stmt {_pos}, id {_id}, assignExpr {_assignExpr}, 
            toExpr{_toExpr}, stepExpr{_stepExpr}, stmts {_stmts} {}

        std::string show() const override {
            std::stringstream ss;
            ss << "what: " << "forStmt" << std::endl;
            ss << "id: " << *id << std::endl;
            ss << "assignExpr: " << *assignExpr << std::endl;
            if (stepExpr != nullptr)
                ss << "stepExpr: " << *stepExpr << std::endl;
            ss << "toExpr: " << *toExpr << std::endl;
            ss <<"stmts: " << *stmts << std::endl;
            return ss.str();
        }

        void computeLevel() override {
            id->level = this->level + 1;
            id->computeLevel();
            assignExpr->level = this->level + 1;
            assignExpr->computeLevel();
            toExpr->level = this->level + 1;
            toExpr->computeLevel();
            if (stepExpr != nullptr) {
                stepExpr->level = this->level + 1;
                stepExpr->computeLevel();
            }
            stmts->level = this->level + 1;
            stmts->computeLevel();
        }

        void accept(NodeVisitor & visitor) override;
};

class ElsePart : public Node {
    public:
        ElsePart(Position _pos) : Node {_pos} {}

        std::string show() const override {
            return "";
        }

        void computeLevel() override {};

        void accept(NodeVisitor & visitor) override;
};

class Else : public ElsePart {
    public:

        std::shared_ptr<ConstructList> stmts;

        Else (
                Position _pos,
                std::shared_ptr<ConstructList> _stmts) 
            : ElsePart {_pos}, stmts {_stmts} {}

        std::string show() const override {
            std::stringstream ss;
            ss << "stmts: " << *stmts << std::endl;
            return ss.str();
        }
        void computeLevel() override {
            stmts->level = this->level + 1;
            stmts->computeLevel();
        }

        void accept(NodeVisitor & visitor) override;
};

class IfStmt : public Stmt {
    public:
	std::shared_ptr<Expr> expr;
	std::shared_ptr<ConstructList> stmts;
	std::shared_ptr<ElsePart> elsePart;

	IfStmt (
		Position _pos,
		std::shared_ptr<Expr> _expr,
		std::shared_ptr<ConstructList> _stmts,
		std::shared_ptr<ElsePart> _elsePart)
	    : Stmt {_pos}, expr {_expr}, stmts {_stmts}, elsePart {_elsePart} {}

        std::string show() const override {
            std::stringstream ss;
            ss << "expr: " << *expr << std::endl;
            ss << "stmts: " << *stmts << std::endl;
            if (elsePart != nullptr)
                ss << "elsePart: " << *elsePart << std::endl;
            return ss.str();
        }
        
        void computeLevel() override {
            expr->level = this->level + 1;
            expr->computeLevel();
            stmts->level = this->level + 1;
            stmts->computeLevel();
            if (elsePart != nullptr) {
                elsePart->level = this->level + 1;
                elsePart->computeLevel();
            }
        }

        void accept(NodeVisitor & visitor) override;
};

class ElseIf : public ElsePart {
    public:
	std::shared_ptr<IfStmt> ifStmt;
        ElseIf(
                Position _pos,
                std::shared_ptr<IfStmt> _ifStmt) 
            : ElsePart {_pos}, ifStmt {_ifStmt} {}

        std::string show() const override {
            std::stringstream ss;
            ss << "ifStmt: " << *ifStmt << std::endl;
            return ss.str();
        }

        void computeLevel() override {
            ifStmt->level = this->level + 1; 
            ifStmt->computeLevel();
        }

        void accept(NodeVisitor & visitor) override;
};

class ReturnStmt : public Stmt {
    public:
        std::shared_ptr<Expr> expr;
        ReturnStmt (
                Position _pos,
                std::shared_ptr<Expr> _expr)
            : Stmt {_pos}, expr {_expr} {}

        std::string show() const override {
            std::stringstream ss;
            ss << "stmt: " << "return" << std::endl;
            if (expr != nullptr)
                ss << "expr: " << *expr << std::endl;
            return ss.str();
        }

        void computeLevel() override {
            if (expr != nullptr) {
                expr->level = this->level + 1;
                expr->computeLevel();
            }
        }

        void accept(NodeVisitor & visitor) override;
};



class Type : public Node {
    public:
        int numBrackets;
        std::string typeName;

        Type(
            Position _pos,
	    int _numBrackets,
            std::string _typeName)
        : Node {_pos}, numBrackets {_numBrackets}, typeName {_typeName} {}

        std::string show() const override {
            std::stringstream ss;
            ss << "name: " << typeName << std::endl;
            ss << "numBrackets: " << numBrackets << std::endl;
            return ss.str();
        }

        void computeLevel() override {}

        void accept(NodeVisitor & visitor) override;
};

class VarDeclId : public Node {
    protected:
        std::shared_ptr<Id> id;
        int numBrackets;
    public:
        VarDeclId(Position _pos, std::shared_ptr<Id> _id, int _numBrackets) 
        : Node {_pos}, id {_id}, numBrackets {_numBrackets} {}

        std::string show() const override {
            std::stringstream ss;
            ss << "id: " << *id << std::endl;
            ss << "numBrackets: " << numBrackets << std::endl;
            return ss.str();
        }

        void computeLevel() override {
            id->level = this->level + 1;
            id->computeLevel();
        }


        void accept(NodeVisitor & visitor) override;
};

class VarInit : public Node {
    public:
        VarInit(Position _pos) : Node {_pos} {}

        std::string show() const override {
            return "";
        }
        void computeLevel() override {};
        void accept(NodeVisitor & visitor) override;
};

class FieldDeclVar : public Node {
    public:
        std::shared_ptr<VarDeclId> varDeclId;
        std::shared_ptr<VarInit> varInit;
        FieldDeclVar (
            Position _pos,
            std::shared_ptr<VarDeclId> _varDeclId,
            std::shared_ptr<VarInit> _varInit) 
        : Node {_pos}, varDeclId {_varDeclId}, varInit {_varInit} {}

        std::string show() const override {
            std::stringstream ss;
            if (varDeclId != nullptr)
                ss << "varDeclId: " << *varDeclId << std::endl;
            if (varInit != nullptr) 
                ss << "varInit: " << *varInit << std::endl; 
            return ss.str();
        }

        void computeLevel() override {
            if (varDeclId != nullptr) {
                varDeclId->level = this->level + 1;
                varDeclId->computeLevel();
            }
            if (varInit != nullptr) {
                varInit->level = this->level + 1;
                varInit->computeLevel();
            }
        }

        void accept(NodeVisitor & visitor) override;
};

class FieldDecl : public Node {
    public:
        std::shared_ptr<Type> type;
        std::shared_ptr<ConstructList> varsDecls;
        FieldDecl (
            Position _pos,
            std::shared_ptr<Type> _type,
            std::shared_ptr<ConstructList> _varDecls) 
        : Node {_pos}, type {_type}, varsDecls {_varDecls} {} 

        std::string show() const override {
            std::stringstream ss;
            ss << "type: " << *type << std::endl;
            ss << "varsDecls: " << *varsDecls << std::endl;
            return ss.str();
        }

        void computeLevel() override {
            type->level = this->level + 1;
            varsDecls->level = this->level + 1;
            type->computeLevel();
            varsDecls->computeLevel();
        }
        void accept(NodeVisitor & visitor) override;
};

class Decls : public Node {
    public:
        std::shared_ptr<ConstructList> fields;
        Decls(
            Position _pos,
            std::shared_ptr<ConstructList> _fields)
        : Node {_pos}, fields{_fields} {}

        std::string show() const override {
            std::stringstream ss;
            if (fields != nullptr)
                ss << "fields: " << *fields << std::endl;
            return ss.str();
        }

        void computeLevel() override {
            if (fields != nullptr) {
                fields->level = this->level + 1;
                fields->computeLevel();
            }
        }

        void accept(NodeVisitor & visitor) override;
};

class FormalParams : public Node {
    public:
        bool val;
        std::shared_ptr<Type> type;
        std::shared_ptr<ConstructList> ids;

        FormalParams (
            Position _pos,
	    bool _val,
            std::shared_ptr<Type> _type,
            std::shared_ptr<ConstructList> _ids) 
        : Node {_pos}, val {_val}, type {_type}, ids{_ids} {}

        std::string show() const override {
            std::stringstream ss;
            ss << "val: " << val << std::endl;
            ss << "type: " << *type << std::endl;
            ss << "ids: " << *ids << std::endl; 
            return ss.str();
        }

        void computeLevel() override {
            type->level = this->level + 1;
            ids->level = this->level + 1;
            type->computeLevel();
            ids->computeLevel();
        }
        void accept(NodeVisitor & visitor) override;
};

class Block : public Node {
    public:
        std::shared_ptr<Decls> decls;
        std::shared_ptr<ConstructList> stmts;

        Block(
            Position _pos,
            std::shared_ptr<Decls> _decls,
            std::shared_ptr<ConstructList> _stmts) 
        : Node {_pos}, decls {_decls}, stmts {_stmts} {}

        std::string show() const override {
            std::stringstream ss;
            if (decls != nullptr) {
                ss << "decls: " << *decls << std::endl; 
            }
            if (stmts != nullptr)
                ss << "stmts: " << *stmts << std::endl;
            return ss.str();
        }

        void computeLevel() override {
            if (decls != nullptr) {
                decls->level = this->level + 1;
                decls->computeLevel();
            }
            if (stmts != nullptr) {
                stmts->level = this->level + 1;
                stmts->computeLevel();
            }
        }
        void accept(NodeVisitor & visitor) override;
};

class MethodReturnType : public Node {
    public:
        std::shared_ptr<Type> type;

        MethodReturnType(Position _pos, std::shared_ptr<Type> _type)
        : Node {_pos}, type {_type} {}

        std::string show() const override {
            std::stringstream ss;
            if (type != nullptr)
                ss << "type: " << *type << std::endl;
            return ss.str();
        }

        void computeLevel() override {
            if (type != nullptr) {
                type->level = this->level + 1;
                type->computeLevel();
            }
        }
        void accept(NodeVisitor & visitor) override;
};

class MethodDecl : public Node {
    public:
        std::shared_ptr<MethodReturnType> returnType;
        std::shared_ptr<Id> id;
        std::shared_ptr<ConstructList> params;
        std::shared_ptr<Block> block;

        MethodDecl(
            Position _pos,
            std::shared_ptr<MethodReturnType> _returnType,
            std::shared_ptr<Id> _id,
            std::shared_ptr<ConstructList> _params,
            std::shared_ptr<Block> _block) 
        : Node {_pos}, returnType {_returnType}, id {_id}, params {_params}, block {_block} {}

        std::string show() const override {
            std::stringstream ss;
            if (returnType != nullptr)
                ss << "return: " << *returnType << std::endl;
            ss << "methodName: " << *id << std::endl;
            if (params != nullptr) {
                ss << "params: " << *params << std::endl;
            }
            if (block != nullptr)
                ss << "block: " << *block << std::endl;
            return ss.str();
        }

        void computeLevel() override {
            if (returnType != nullptr) {
                returnType->level = this->level + 1;
                returnType->computeLevel();
            }

            id->level = this->level + 1;
            id->computeLevel();

            if (params != nullptr) {
                params->level = this->level + 1;
                params->computeLevel();
            }

            if (block != nullptr) {
                block->level = this->level + 1;
                block->computeLevel();
            }
        }
        void accept(NodeVisitor & visitor) override;
};

class ClassBody : public Node {
    public:
        std::shared_ptr<Decls> decls;
        std::shared_ptr<ConstructList> methods;
        ClassBody (
            Position _pos,
            std::shared_ptr<Decls> _decls,
            std::shared_ptr<ConstructList> _methods) 
        : Node {_pos}, decls {_decls}, methods {_methods} {}

        std::string show() const override {
            std::stringstream ss;
            if (decls != nullptr) {
                ss << "decls: " << *decls << std::endl;
            }
            if (methods != nullptr) {
                ss << "methods: " << *methods << std::endl;
            }
            return ss.str();
        }

        void computeLevel() override {
            if (decls != nullptr) {
                decls->level = this->level + 1;
                decls->computeLevel();
            }

            if (methods != nullptr) {
                methods->level = this->level + 1;
                methods->computeLevel();
            }
        }
        void accept(NodeVisitor & visitor) override;
};

class ClassDecl : public Node {
    public:
        std::shared_ptr<Id> id;
        std::shared_ptr<ClassBody> body;
        ClassDecl (
            Position _pos,
            std::shared_ptr<Id> _id,
            std::shared_ptr<ClassBody> _body) 
        : Node {_pos}, id {_id}, body {_body} {} 

        std::string show() const override {
            std::stringstream ss;
            ss << "className: " << *id << std::endl;
            if (body != nullptr) 
                ss << "body: " << *body << std::endl;
            return ss.str();
        }
        void computeLevel() override {
            if (id != nullptr) {
                id->level = this->level + 1;
                id->computeLevel();
            }

            if (body != nullptr) {
                body->level = this->level + 1;
                body->computeLevel();
            }
        }
        void accept(NodeVisitor & visitor) override;
};

class Program : public Node {
    public:
        std::shared_ptr<Id> id;
        std::shared_ptr<ConstructList> classes;

        Program (
            Position _pos,
            std::shared_ptr<Id> _id,
            std::shared_ptr<ConstructList> _classes) 
        : Node {_pos}, id {_id}, classes {_classes} {}
    
        std::string show() const override {
            std::stringstream ss;
            if (id != nullptr)
                ss << "programName: " << *id << std::endl;
            if (classes != nullptr)
                ss << "classes: " << *classes << std::endl;
            return ss.str();
        }
        void computeLevel() override {
            if (id != nullptr) {
                id->level = this->level + 1;
                id->computeLevel();
            }
            if (classes != nullptr) {
                classes->level = this->level + 1;
                classes->computeLevel();
            }
        }
        void accept(NodeVisitor & visitor) override;
};

class ExprVarInit : public VarInit {
    public:
        std::shared_ptr<Expr> expr;
        ExprVarInit (Position _pos, std::shared_ptr<Expr> _expr) 
        : VarInit {_pos}, expr {_expr} {}

        std::string show() const override {
            std::stringstream ss;
            ss << "expr: " << *expr << std::endl;
            return ss.str();
        }
        void computeLevel() override {
            expr->level = this->level + 1;
            expr->computeLevel();
        }
        void accept(NodeVisitor & visitor) override;
};

class ArrayInitVarInit : public VarInit {
    protected:
        std::shared_ptr<ConstructList> arrayInit;
    public:
        ArrayInitVarInit (Position _pos,
			std::shared_ptr<ConstructList> _arrayInit) 
        : VarInit {_pos}, arrayInit {_arrayInit} {}

        std::string show() const override {
            std::stringstream ss;
            ss << "arrayInit: " << *arrayInit << std::endl;
            return ss.str();
        }
        void computeLevel() override {
            arrayInit->level = this->level + 1;
            arrayInit->computeLevel();
        }
        void accept(NodeVisitor & visitor) override;
};

class ArrayCreation : public VarInit {
    protected:
	std::shared_ptr<Type> type;
	std::shared_ptr<ConstructList> dims;
    public:
        ArrayCreation(
            Position _pos, 
            std::shared_ptr<Type> _type, 
            std::shared_ptr<ConstructList> _dims)
        : VarInit {_pos}, type {_type}, dims {_dims} {}

        std::string show() const override {
            std::stringstream ss;
            ss << "type: " << *type << std::endl;
            ss << "dims: " << *dims << std::endl;
            return ss.str();
        }
        void computeLevel() override {
            type->level = this->level + 1;
            dims->level = this->level + 1;
            type->computeLevel();
            dims->computeLevel();
        }
        void accept(NodeVisitor & visitor) override;
};

class ArrayCreationVarInit : public VarInit {
     protected:
        ArrayCreation arrayInit;
    public:
        ArrayCreationVarInit (Position _pos, ArrayCreation _arrayCreation) 
        : VarInit {_pos}, arrayInit {_arrayCreation} {}

        std::string show() const override {
            std::stringstream ss;
            ss << "arrayInit: " << arrayInit << std::endl;
            return ss.str();
        }

        void computeLevel() override {
            arrayInit.level = this->level + 1;
            arrayInit.computeLevel();
        }
        void accept(NodeVisitor & visitor) override;
};

#endif
