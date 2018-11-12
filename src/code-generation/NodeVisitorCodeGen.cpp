#include "code-generation/NodeVisitorCodeGen.h"
#include "ast/Expr.h"

void NodeVisitorCodeGen::visitId(Id * id) {
    this->fileName = id->id;
}
void NodeVisitorCodeGen::visitConstructList(ConstructList * cl) {
    while (!cl->constructs.empty()) {
        cl->constructs.front()->accept(*this);
        this->code += ";\n";
        cl->constructs.pop_front();
    }
}

void NodeVisitorCodeGen::visitExpr(Expr *) {}
void NodeVisitorCodeGen::visitAlExpr(AlExpr *) {}

void NodeVisitorCodeGen::visitExprParen(ExprParen * expr) {
    this->code += "(";
    expr->expr->accept(*this);
    this->code += ")";
}

void NodeVisitorCodeGen::visitRelExpr(RelExpr * expr) {
    expr->lhs->accept(*this);
    std::string opstr;
    switch(expr->op) {
        case RelExpr::RelOp::LESS:
            opstr = "<";
            break;
        case RelExpr::RelOp::LESS_EQ:
            opstr = "<=";
            break;
        case RelExpr::RelOp::EQEQ:
            opstr = "==";
            break;
        case RelExpr::RelOp::GREATER:
            opstr = ">";
            break;
        case RelExpr::RelOp::GREATER_EQ:
            opstr = ">=";
            break;
        case RelExpr::RelOp::DIFF:
            opstr = "!=";
            break;
    }
    this->code += opstr;
    expr->rhs->accept(*this);
}

void NodeVisitorCodeGen::visitAlBinExpr(AlBinExpr * expr) {
    expr->lhs->accept(*this);
    std::string opstr;
    switch(expr->op) {
        case AlBinExpr::AlBinOp::PLUS:
            opstr = "+";
            break;
        case AlBinExpr::AlBinOp::MINUS:
            opstr = "-";
            break;
        case AlBinExpr::AlBinOp::TIMES:
            opstr = "*";
            break;
        case AlBinExpr::AlBinOp::DIV:
            opstr = "/";
            break;
        case AlBinExpr::AlBinOp::MOD:
            opstr = "%";
            break;
        case AlBinExpr::AlBinOp::AND:
            opstr = "&&";
            break;
        case AlBinExpr::AlBinOp::OR:
            opstr = "||";
            break;
    }
    this->code += opstr;
    expr->rhs->accept(*this);
}

void NodeVisitorCodeGen::visitAlUnExpr(AlUnExpr * expr) {
    std::string opstr;
    switch(expr->op) {
        case AlUnExpr::AlUnOp::PLUS:
            opstr = "+";
            break;
        case AlUnExpr::AlUnOp::MINUS:
            opstr = "-";
            break;
        case AlUnExpr::AlUnOp::NOT:
            opstr = "!";
            break;
    }
    this->code += opstr + "(";
    expr->alexpr->accept(*this);
    this->code += ")";
}

void NodeVisitorCodeGen::visitLitExprString(LitExpr<std::string> * strlit) {
    this->code += strlit->val;
}
void NodeVisitorCodeGen::visitLitExprInt(LitExpr<int> * intlit) {
    this->code += std::to_string(intlit->val);
}
void NodeVisitorCodeGen::visitAccessOperation(AccessOperation *) {}
void NodeVisitorCodeGen::visitBrackAccess(BracketAccess *) {}
void NodeVisitorCodeGen::visitDotAccess(DotAccess *) {}
void NodeVisitorCodeGen::visitVar(Var *) {}
void NodeVisitorCodeGen::visitFunctionCallExpr(FunctionCallExpr *) {}
void NodeVisitorCodeGen::visitStmt(Stmt *) {}
void NodeVisitorCodeGen::visitAssignStmt(AssignStmt *) {}
void NodeVisitorCodeGen::visitFunctionCallStmt(FunctionCallStmt *) {}
void NodeVisitorCodeGen::visitReadStmt(ReadStmt *) {}
void NodeVisitorCodeGen::visitPrintStmt(PrintStmt * print) {
    if (LitExpr<std::string> * v = dynamic_cast<LitExpr<std::string>*>(print->expr.get())) {
        this->code += std::string("printf(\"%s\",");
        v->accept(*this);
        this->code += ")";
    } else {
        this->code += std::string("printf(\"%s\", std::to_string(");
        print->expr->accept(*this);
        this->code += "))";
    }
}
void NodeVisitorCodeGen::visitCase(Case *) {}
void NodeVisitorCodeGen::visitSwitchStmt(SwitchStmt *) {}
void NodeVisitorCodeGen::visitWhileStmt(WhileStmt * whilestmt) {
}
void NodeVisitorCodeGen::visitForStmt(ForStmt *) {}
void NodeVisitorCodeGen::visitElsePart(ElsePart *) {}
void NodeVisitorCodeGen::visitElse(Else *) {}
void NodeVisitorCodeGen::visitIfStmt(IfStmt *) {

}
void NodeVisitorCodeGen::visitElseIf(ElseIf *) {} 
void NodeVisitorCodeGen::visitReturnStmt(ReturnStmt *) {}
void NodeVisitorCodeGen::visitType(Type *) {}
void NodeVisitorCodeGen::visitVarDeclId(VarDeclId *) {}
void NodeVisitorCodeGen::visitVarInit(VarInit * varinit) {}
void NodeVisitorCodeGen::visitFieldDeclVar(FieldDeclVar * fieldvar) {
    //TODO varDeclId
    fieldvar->varInit->accept(*this);
}
void NodeVisitorCodeGen::visitFieldDecl(FieldDecl * fielddecl) {
    //TODO type
    fielddecl->varsDecls->accept(*this); 
}
void NodeVisitorCodeGen::visitDecls(Decls * decls) {
    decls->fields->accept(*this);
}
void NodeVisitorCodeGen::visitFormalParams(FormalParams *) {}
void NodeVisitorCodeGen::visitBlock(Block * block) {
    if (block->decls != nullptr)
        block->decls->accept(*this);
    block->stmts->accept(*this);
}
void NodeVisitorCodeGen::visitMethodReturnType(MethodReturnType *) {}
void NodeVisitorCodeGen::visitMethodDecl(MethodDecl * metdecl) {
    // return
    // id
    // params
    metdecl->block->accept(*this); 
}
void NodeVisitorCodeGen::visitClassBody(ClassBody * classbody) {
    classbody->decls->accept(*this);
    classbody->methods->accept(*this);
}
void NodeVisitorCodeGen::visitClassDecl(ClassDecl * classdecl) {
    // id
    // TODO
    classdecl->body->accept(*this);
     
}
void NodeVisitorCodeGen::visitProgram(Program * program) {
    program->id->accept(*this);
    program->classes->accept(*this);
    
}
void NodeVisitorCodeGen::visitExprVarInit(ExprVarInit * varinit) {
    varinit->expr->accept(*this);
}
void NodeVisitorCodeGen::visitArrayInitVarInit(ArrayInitVarInit *) {}
void NodeVisitorCodeGen::visitArrayCreation(ArrayCreation *) {}
void NodeVisitorCodeGen::visitArrayCreationVarInit(ArrayCreationVarInit *) {}

