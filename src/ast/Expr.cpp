#include "ast/NodeVisitor.h"
#include "ast/Expr.h"

void Id::accept(NodeVisitor & visitor) {
    visitor.visitId(this);
};

void ConstructList::accept(NodeVisitor & visitor) {
    visitor.visitConstructList(this);
}

void Expr::accept(NodeVisitor & visitor) {
    visitor.visitExpr(this);
}

void AlExpr::accept(NodeVisitor & visitor) {
    visitor.visitAlExpr(this);
}

void ExprParen::accept(NodeVisitor & visitor) {
    visitor.visitExprParen(this);
}

void RelExpr::accept(NodeVisitor & visitor) {
    visitor.visitRelExpr(this);
}

void AlBinExpr::accept(NodeVisitor & visitor) {
    visitor.visitAlBinExpr(this);
}

void AlUnExpr::accept(NodeVisitor & visitor) {
    visitor.visitAlUnExpr(this);
}

template<>
void LitExpr<std::string>::accept(NodeVisitor & visitor) {
    visitor.visitLitExprString(this);
}

template<>
void LitExpr<int>::accept(NodeVisitor & visitor) {
    visitor.visitLitExprInt(this);
}

void AccessOperation::accept(NodeVisitor & visitor) {
    visitor.visitAccessOperation(this);
}

void BracketAccess::accept(NodeVisitor & visitor) {
    visitor.visitBrackAccess(this);
}

void DotAccess::accept(NodeVisitor & visitor) {
    visitor.visitDotAccess(this);
}

void Var::accept(NodeVisitor & visitor) {
    visitor.visitVar(this);
}

void FunctionCallExpr::accept(NodeVisitor & visitor) {
    visitor.visitFunctionCallExpr(this);
}

void Stmt::accept(NodeVisitor & visitor) {
    visitor.visitStmt(this);
}

void AssignStmt::accept(NodeVisitor & visitor) {
    visitor.visitAssignStmt(this);
}

void FunctionCallStmt::accept(NodeVisitor & visitor) {
    visitor.visitFunctionCallStmt(this);
}

void ReadStmt::accept(NodeVisitor & visitor) {
    visitor.visitReadStmt(this);
}

void PrintStmt::accept(NodeVisitor & visitor) {
    visitor.visitPrintStmt(this);
}

void Case::accept(NodeVisitor & visitor) {
    visitor.visitCase(this);
}

void SwitchStmt::accept(NodeVisitor & visitor) {
    visitor.visitSwitchStmt(this);
}

void WhileStmt::accept(NodeVisitor & visitor) {
    visitor.visitWhileStmt(this);
}

void ForStmt::accept(NodeVisitor & visitor) {
    visitor.visitForStmt(this);
}

void ElsePart::accept(NodeVisitor & visitor) {
    visitor.visitElsePart(this);
}

void Else::accept(NodeVisitor & visitor) {
    visitor.visitElse(this);
}

void IfStmt::accept(NodeVisitor & visitor) {
    visitor.visitIfStmt(this);
}

void ElseIf::accept(NodeVisitor & visitor) {
    visitor.visitElseIf(this);
}

void ReturnStmt::accept(NodeVisitor & visitor) {
    visitor.visitReturnStmt(this);
}

void Type::accept(NodeVisitor & visitor) {
    visitor.visitType(this);
}

void VarDeclId::accept(NodeVisitor & visitor) {
    visitor.visitVarDeclId(this);
}

void VarInit::accept(NodeVisitor & visitor) {
    visitor.visitVarInit(this);
}

void FieldDeclVar::accept(NodeVisitor & visitor) {
    visitor.visitFieldDeclVar(this);
}

void FieldDecl::accept(NodeVisitor & visitor) {
    visitor.visitFieldDecl(this);
}

void Decls::accept(NodeVisitor & visitor) {
    visitor.visitDecls(this);
}

void FormalParams::accept(NodeVisitor & visitor) {
    visitor.visitFormalParams(this);
}

void Block::accept(NodeVisitor & visitor) {
    visitor.visitBlock(this);
}

void MethodReturnType::accept(NodeVisitor & visitor) {
    visitor.visitMethodReturnType(this);
}

void MethodDecl::accept(NodeVisitor & visitor) {
    visitor.visitMethodDecl(this);
}

void ClassBody::accept(NodeVisitor & visitor) {
    visitor.visitClassBody(this);
}

void ClassDecl::accept(NodeVisitor & visitor) {
    visitor.visitClassDecl(this);
}

void Program::accept(NodeVisitor & visitor) {
    visitor.visitProgram(this);
}

void ExprVarInit::accept(NodeVisitor & visitor) {
    visitor.visitExprVarInit(this);
}

void ArrayInitVarInit::accept(NodeVisitor & visitor) {
    visitor.visitArrayInitVarInit(this);
}

void ArrayCreation::accept(NodeVisitor & visitor) {
    visitor.visitArrayCreation(this);
}

void ArrayCreationVarInit::accept(NodeVisitor & visitor) {
    visitor.visitArrayCreationVarInit(this);
}

