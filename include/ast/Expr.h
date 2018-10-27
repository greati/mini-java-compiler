#ifndef __EXPR__
#define __EXPR__

#include "Node.h"
#include <memory>
#include <vector>
#include <exception>
#include <sstream>


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

        std::string show() const override {
            std::stringstream ss;
            ss << "{" << std::endl;
            for (auto i : this->constructs) {
                if (i != nullptr)
                    ss << (*i) << std::endl;
            }
            ss << "}" << std::endl;
            return ss.str();
        }
};

class Expr : public Node {

    public:
        Expr(Position _pos) : Node {_pos} {};

        std::string show() const override {
            return "";
        }
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

        std::string show() const override {
            return expr->show();
        }
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

        std::string show() const override {
            std::stringstream ss;
            ss << "Relational ";
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
            ss << "(" << *lhs << ") ";
            ss << "(" << *rhs << ") ";
            return ss.str();
        }

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

        std::string show() const override {
            std::stringstream ss;
            ss << "Binary ";
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
            ss << "(" << *lhs << ") ";
            ss << "(" << *rhs << ") ";
            return ss.str();
        }
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

        std::string show() const override {
            std::stringstream ss;
            ss << "Unary ";
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
            ss << *alexpr;
            return ss.str();
        }
};

template<typename T>
class LitExpr : public AlExpr {

    protected:
        T val;

    public:
        LitExpr(Position _pos, T _val) : AlExpr{_pos}, val {_val} {}

        std::string show() const override {
            std::stringstream ss;
            ss << "Literal (" << val << ")";
            return ss.str();
        }
};



class AccessOperation : public Node {
    public:
        AccessOperation(Position _pos) : Node {_pos} {};

        std::string show() const override {
            return "";
        }
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

        std::string show() const override {
            std::stringstream ss;
            ss << "BracketAccess ";
            ss << *expressionList << std::endl;
            if (accessOperation != nullptr)
                ss << *accessOperation;
            return ss.str();
        }
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

        std::string show() const override {
            std::stringstream ss;
            ss << "DotAccess ";
            ss << id << std::endl;
            if (accessOperation != nullptr)
                ss << *accessOperation;
            return ss.str();
        }
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

        std::string show() const override {
            std::stringstream ss;
            ss << "Var ";
            ss << id << std::endl;
            if (accessOperation != nullptr)
                ss << *accessOperation;
            return ss.str();
        }
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

        std::string show() const override {
            std::stringstream ss;
            ss << "FunctionCallExpr ";
            ss << *var << std::endl;
            if (actualParams != nullptr)
                ss << *actualParams;
            return ss.str();
        }
};


class Stmt : public Node {
    public:
        Stmt(Position _pos) : Node {_pos} {};

        std::string show() const override {
            return "";
        }
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
            ss << "AssignStmt ";
            ss << *var << std::endl << *expr;
            return ss.str();
        }
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

        std::string show() const override {
            std::stringstream ss;
            ss << "FunctionCallStmt ";
            ss << *var << std::endl;
            if (actualParams != nullptr)
                ss << *actualParams;
            return ss.str();
        }
};

class ReadStmt : public Stmt {
    protected:
        std::string id;
    public:
        ReadStmt(Position _pos, std::string _id) : Stmt {_pos}, id{_id} {}

        std::string show() const override {
            std::stringstream ss;
            ss << "ReadStmt ";
            ss << id;
            return ss.str();
        }
};

class PrintStmt : public Stmt {
    protected:
	std::shared_ptr<Expr> expr;
    public:
        PrintStmt(Position _pos, std::shared_ptr<Expr> _expr)
		: Stmt {_pos}, expr{_expr} {}

        std::string show() const override {
            std::stringstream ss;
            ss << "PrintStmt " << *expr;
            return ss.str();
        }

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

        std::string show() const override {
            std::stringstream ss;
            ss << "Case " << *expr << std::endl << *stmts;
            return ss.str();
        }

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

        std::string show() const override {
            std::stringstream ss;
            ss << "SwitchStmt " << *expr << std::endl << *caseList;
            if (defaultStmts  != nullptr) 
                ss << *defaultStmts;
            return ss.str();
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

        std::string show() const override {
            std::stringstream ss;
            ss << "WhileStmt " << *expr << std::endl << *stmts;
            return ss.str();
        }

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

        std::string show() const override {
            std::stringstream ss;
            ss << "ForStmt " << id << std::endl << assignExpr << std::endl;
            if (stepExpr != nullptr)
                ss << *stepExpr << std::endl;
            ss << *toExpr << std::endl;
            ss << *stmts;
            return ss.str();
        }

};

class ElsePart : public Node {
    public:
        ElsePart(Position _pos) : Node {_pos} {}

        std::string show() const override {
            return "";
        }
};

class Else : public ElsePart {
    protected:
        std::shared_ptr<ConstructList<Stmt>> stmts;
    public:
        Else (
                Position _pos,
                std::shared_ptr<ConstructList<Stmt>> _stmts) 
            : ElsePart {_pos}, stmts {_stmts} {}

        std::string show() const override {
            std::stringstream ss;
            ss << "Else " << *stmts;
            return ss.str();
        }

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

        std::string show() const override {
            std::stringstream ss;
            ss << "IfStmt " << *expr << std::endl << *stmts << std::endl;
            if (elsePart != nullptr)
                ss << *elsePart;
            return ss.str();
        }
};

class ElseIf : public ElsePart {
    protected:
	std::shared_ptr<IfStmt> ifStmt;
    public:
        ElseIf(
                Position _pos,
                std::shared_ptr<IfStmt> _ifStmt) 
            : ElsePart {_pos}, ifStmt {_ifStmt} {}

        std::string show() const override {
            std::stringstream ss;
            ss << "ElseIf " << *ifStmt;
            return ss.str();
        }
};

class ReturnStmt : public Stmt {
    protected:
        std::shared_ptr<Expr> expr;
    public:
        ReturnStmt (
                Position _pos,
                std::shared_ptr<Expr> _expr)
            : Stmt {_pos}, expr {_expr} {}

        std::string show() const override {
            std::stringstream ss;
            ss << "ReturnStmt ";
            if (expr != nullptr)
                ss << *expr;
            return ss.str();
        }
};



class Type : public Node {
    protected:
        int numBrackets;
        std::string typeName;
    public:
        Type(
            Position _pos,
	    int _numBrackets,
            std::string _typeName)
        : Node {_pos}, numBrackets {_numBrackets}, typeName {_typeName} {}

        std::string show() const override {
            std::stringstream ss;
            ss << "Type " << typeName << "(" << numBrackets << ")";
            return ss.str();
        }

};

class VarDeclId : public Node {
    protected:
        std::string id;
        int numBrackets;
    public:
        VarDeclId(Position _pos, std::string _id, int _numBrackets) 
        : Node {_pos}, id {_id}, numBrackets {_numBrackets} {}

        std::string show() const override {
            std::stringstream ss;
            ss << "VarDeclId " << id << "(" << numBrackets << ")";
            return ss.str();
        }

};

class VarInit : public Node {
    public:
        VarInit(Position _pos) : Node {_pos} {}

        std::string show() const override {
            return "";
        }
};

class FieldDeclVar : public Node {
    protected:
        std::shared_ptr<VarDeclId> varDeclId;
        std::shared_ptr<VarInit> varInit;
    public:
        FieldDeclVar (
            Position _pos,
            std::shared_ptr<VarDeclId> _varDeclId,
            std::shared_ptr<VarInit> _varInit) 
        : Node {_pos}, varDeclId {_varDeclId}, varInit {_varInit} {}

        std::string show() const override {
            std::stringstream ss;
            ss << "FieldDeclVar ";
            if (varDeclId != nullptr)
                ss << *varDeclId;
            if (varInit != nullptr) 
                ss << *varInit; 
            return ss.str();
        }

};

class FieldDecl : public Node {
    protected:
	std::shared_ptr<Type> type;
	std::shared_ptr<ConstructList<FieldDeclVar>> varsDecls;
    public:
        FieldDecl (
            Position _pos,
            std::shared_ptr<Type> _type,
            std::shared_ptr<ConstructList<FieldDeclVar>> _varDecls) 
        : Node {_pos}, type {_type}, varsDecls {_varDecls} {} 

        std::string show() const override {
            std::stringstream ss;
            ss << "FieldDecl " << *type << std::endl << *varsDecls;
            return ss.str();
        }

};

class Decls : public Node {
    protected:
	std::shared_ptr<ConstructList<FieldDecl>> fields;
    public:
        Decls(
            Position _pos,
            std::shared_ptr<ConstructList<FieldDecl>> _fields)
        : Node {_pos}, fields{_fields} {}

        std::string show() const override {
            std::stringstream ss;
            ss << "Decls ";
            if (fields != nullptr)
                ss << *fields;
            return ss.str();
        }

};

class FormalParams : public Node {

    protected:
        bool val;
        std::shared_ptr<Type> type;
        std::shared_ptr<ConstructList<std::string>> ids;

    public:
        FormalParams (
            Position _pos,
	    bool _val,
            std::shared_ptr<Type> _type,
            std::shared_ptr<ConstructList<std::string>> _ids) 
        : Node {_pos}, val {_val}, type {_type}, ids{_ids} {}

        std::string show() const override {
            std::stringstream ss;
            ss << "FormalParams " << val << std::endl << *type << std::endl << *ids;
            return ss.str();
        }

};

class Block : public Node {

    protected:
        std::shared_ptr<Decls> decls;
        std::shared_ptr<ConstructList<Stmt>> stmts;
    public:
        Block(
            Position _pos,
            std::shared_ptr<Decls> _decls,
            std::shared_ptr<ConstructList<Stmt>> _stmts) 
        : Node {_pos}, decls {_decls}, stmts {_stmts} {}

        std::string show() const override {
            std::stringstream ss;
            ss << "Block ";
            if (decls != nullptr) {
                ss << *decls << std::endl; 
            }
            if (stmts != nullptr)
                ss << *stmts;
            return ss.str();
        }

};

class MethodReturnType : public Node {
    protected:
        std::shared_ptr<Type> type;
    public:
        MethodReturnType(Position _pos, std::shared_ptr<Type> _type)
        : Node {_pos}, type {_type} {}

        std::string show() const override {
            std::stringstream ss;
            ss << "MethodReturnType ";
            if (type != nullptr)
                ss << *type;
            return ss.str();
        }

};

class MethodDecl : public Node {
    protected:
        std::shared_ptr<MethodReturnType> returnType;
        std::string id;
        std::shared_ptr<ConstructList<FormalParams>> params;
        std::shared_ptr<Block> block;
    public:
        MethodDecl(
            Position _pos,
            std::shared_ptr<MethodReturnType> _returnType,
            std::string _id,
            std::shared_ptr<ConstructList<FormalParams>> _params,
            std::shared_ptr<Block> _block) 
        : Node {_pos}, returnType {_returnType}, id {_id}, params {_params}, block {_block} {}

        std::string show() const override {
            std::stringstream ss;
            ss << "MethodDecl ";
            if (returnType != nullptr)
                ss << *returnType << std::endl;
            ss << id << std::endl;
            if (params != nullptr) {
                ss << *params << std::endl; 
            }
            if (block != nullptr)
                ss << *block;
            return ss.str();
        }

};

class ClassBody : public Node {
    protected:
        std::shared_ptr<Decls> decls;
        std::shared_ptr<ConstructList<MethodDecl>> methods;
    public:
        ClassBody (
            Position _pos,
            std::shared_ptr<Decls> _decls,
            std::shared_ptr<ConstructList<MethodDecl>> _methods) 
        : Node {_pos}, decls {_decls}, methods {_methods} {}

        std::string show() const override {
            std::stringstream ss;
            ss << "ClassBody ";
            if (decls != nullptr) {
                ss << *decls << std::endl;
            }
            if (methods != nullptr) {
                ss << *methods;
            }
            return ss.str();
        }

};

class ClassDecl : public Node {
    protected:
        std::string id;
        std::shared_ptr<ClassBody> body;
    public:
        ClassDecl (
            Position _pos,
            std::string _id,
            std::shared_ptr<ClassBody> _body) 
        : Node {_pos}, id {_id}, body {_body} {} 

        std::string show() const override {
            std::stringstream ss;
            ss << "ClassDecl " << id << std::endl;
            if (body != nullptr) {
                ss << *body;
            }
            return ss.str();
        }

};

class Program : public Node {
    protected:
        std::string id;
        std::shared_ptr<ConstructList<ClassDecl>> classes;
    public:
        Program (
            Position _pos,
            std::string _id,
            std::shared_ptr<ConstructList<ClassDecl>> _classes) 
        : Node {_pos}, id {_id}, classes {_classes} {}
    
        std::string show() const override {
            std::stringstream ss;
            ss << "program (" + id + ")" << std::endl << *classes;
            return ss.str();
        }
};

class ExprVarInit : public VarInit {
    protected:
        std::shared_ptr<Expr> expr;
    public:
        ExprVarInit (Position _pos, std::shared_ptr<Expr> _expr) 
        : VarInit {_pos}, expr {_expr} {}

        std::string show() const override {
            std::stringstream ss;
            ss << "ExprVarInit " << *expr;
            return ss.str();
        }

};

class ArrayInitVarInit : public VarInit {
    protected:
	std::shared_ptr<ConstructList<VarInit>> arrayInit;
    public:
        ArrayInitVarInit (Position _pos,
			std::shared_ptr<ConstructList<VarInit>> _arrayInit) 
        : VarInit {_pos}, arrayInit {_arrayInit} {}

        std::string show() const override {
            std::stringstream ss;
            ss << "ArrayInitVarInit " << *arrayInit;
            return ss.str();
        }

};

class ArrayCreation : public VarInit {
    protected:
	std::shared_ptr<Type> type;
	std::shared_ptr<ConstructList<Expr>> dims;
    public:
        ArrayCreation(
            Position _pos, 
            std::shared_ptr<Type> _type, 
            std::shared_ptr<ConstructList<Expr>> _dims)
        : VarInit {_pos}, type {_type}, dims {_dims} {}

        std::string show() const override {
            std::stringstream ss;
            ss << "ArrayCreation " << type << std::endl << dims;
            return ss.str();
        }

};

class ArrayCreationVarInit : public VarInit {
     protected:
        ArrayCreation arrayInit;
    public:
        ArrayCreationVarInit (Position _pos, ArrayCreation _arrayCreation) 
        : VarInit {_pos}, arrayInit {_arrayCreation} {}

        std::string show() const override {
            std::stringstream ss;
            ss << "ArrayCreationVarInit " << arrayInit;
            return ss.str();
        }

};


#endif
