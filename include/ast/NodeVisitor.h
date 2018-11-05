#ifndef __NODEVISITOR__
#define __NODEVISITOR__

#include "Expr.h"

/**
 * Represents a node visitor.
 *
 * */
class NodeVisitor {

    public:
        virtual void visitId(Id *) = 0;
        virtual void visitConstructList(ConstructList *) = 0;
        virtual void visitExpr(Expr *) = 0;
        virtual void visitAlExpr(AlExpr *) = 0;
        virtual void visitExprParen(ExprParen *) = 0;
        virtual void visitRelExpr(RelExpr *) = 0;
        virtual void visitAlBinExpr(AlBinExpr *) = 0;
        virtual void visitAlUnExpr(AlUnExpr *) = 0;
        virtual void visitLitExprString(LitExpr<std::string> *) = 0;
        virtual void visitLitExprInt(LitExpr<int> *) = 0;
        virtual void visitAccessOperation(AccessOperation *) = 0;
        virtual void visitBrackAccess(BracketAccess *) = 0;
        virtual void visitDotAccess(DotAccess *) = 0;
        virtual void visitVar(Var *) = 0;
        virtual void visitFunctionCallExpr(FunctionCallExpr *) = 0;
        virtual void visitStmt(Stmt *) = 0;
        virtual void visitAssignStmt(AssignStmt *) = 0;
        virtual void visitFunctionCallStmt(FunctionCallStmt *) = 0;
        virtual void visitReadStmt(ReadStmt *) = 0;
        virtual void visitPrintStmt(PrintStmt *) = 0;
        virtual void visitCase(Case *) = 0;
        virtual void visitSwitchStmt(SwitchStmt *) = 0;
        virtual void visitWhileStmt(WhileStmt *) = 0;
        virtual void visitForStmt(ForStmt *) = 0;
        virtual void visitElsePart(ElsePart *) = 0;
        virtual void visitElse(Else *) = 0;
        virtual void visitIfStmt(IfStmt *) = 0;
        virtual void visitElseIf(ElseIf *) = 0; 
        virtual void visitReturnStmt(ReturnStmt *) = 0;
        virtual void visitType(Type *) = 0;
        virtual void visitVarDeclId(VarDeclId *) = 0;
        virtual void visitVarInit(VarInit *) = 0;
        virtual void visitFieldDeclVar(FieldDeclVar *) = 0;
        virtual void visitFieldDecl(FieldDecl *) = 0;
        virtual void visitDecls(Decls *) = 0;
        virtual void visitFormalParams(FormalParams *) = 0;
        virtual void visitBlock(Block *) = 0;
        virtual void visitMethodReturnType(MethodReturnType *) = 0;
        virtual void visitMethodDecl(MethodDecl *) = 0;
        virtual void visitClassBody(ClassBody *) = 0;
        virtual void visitClassDecl(ClassDecl *) = 0;
        virtual void visitProgram(Program *) = 0;
        virtual void visitExprVarInit(ExprVarInit *) = 0;
        virtual void visitArrayInitVarInit(ArrayInitVarInit *) = 0;
        virtual void visitArrayCreation(ArrayCreation *) = 0;
        virtual void visitArrayCreationVarInit(ArrayCreationVarInit *) = 0;
};

#endif
