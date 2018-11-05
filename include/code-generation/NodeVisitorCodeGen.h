#ifndef __NODEVISITORCODE__
#define __NODEVISITORCODE__

#include "ast/NodeVisitor.h"

/**
 * Represents a node visitor for code generation.
 *
 * */
class NodeVisitorCodeGen : public NodeVisitor {

    public:
        void visitId(Id *) override;
        void visitConstructList(ConstructList *) override;
        void visitExpr(Expr *) override;
        void visitAlExpr(AlExpr *) override;
        void visitExprParen(ExprParen *) override;
        void visitRelExpr(RelExpr *) override;
        void visitAlBinExpr(AlBinExpr *) override;
        void visitAlUnExpr(AlUnExpr *) override;
        void visitLitExprString(LitExpr<std::string> *) override;
        void visitLitExprInt(LitExpr<int> *) override;
        void visitAccessOperation(AccessOperation *) override;
        void visitBrackAccess(BracketAccess *) override;
        void visitDotAccess(DotAccess *) override;
        void visitVar(Var *) override;
        void visitFunctionCallExpr(FunctionCallExpr *) override;
        void visitStmt(Stmt *) override;
        void visitAssignStmt(AssignStmt *) override;
        void visitFunctionCallStmt(FunctionCallStmt *) override;
        void visitReadStmt(ReadStmt *) override;
        void visitPrintStmt(PrintStmt *) override;
        void visitCase(Case *) override;
        void visitSwitchStmt(SwitchStmt *) override;
        void visitWhileStmt(WhileStmt *) override;
        void visitForStmt(ForStmt *) override;
        void visitElsePart(ElsePart *) override;
        void visitElse(Else *) override;
        void visitIfStmt(IfStmt *) override;
        void visitElseIf(ElseIf *) override; 
        void visitReturnStmt(ReturnStmt *) override;
        void visitType(Type *) override;
        void visitVarDeclId(VarDeclId *) override;
        void visitVarInit(VarInit *) override;
        void visitFieldDeclVar(FieldDeclVar *) override;
        void visitFieldDecl(FieldDecl *) override;
        void visitDecls(Decls *) override;
        void visitFormalParams(FormalParams *) override;
        void visitBlock(Block *) override;
        void visitMethodReturnType(MethodReturnType *) override;
        void visitMethodDecl(MethodDecl *) override;
        void visitClassBody(ClassBody *) override;
        void visitClassDecl(ClassDecl *) override;
        void visitProgram(Program *) override;
        void visitExprVarInit(ExprVarInit *) override;
        void visitArrayInitVarInit(ArrayInitVarInit *) override;
        void visitArrayCreation(ArrayCreation *) override;
        void visitArrayCreationVarInit(ArrayCreationVarInit *) override;
};

#endif
