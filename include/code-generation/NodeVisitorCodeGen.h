#ifndef __NODEVISITORCODE__
#define __NODEVISITORCODE__

#include "ast/NodeVisitor.h"
#include "resources/MJResources.h"
#include "symbol-table/SymbolTable.h"
#include "frames/Param.h"

/**
 * Represents a node visitor for code generation.
 *
 * */
class NodeVisitorCodeGen : public NodeVisitor {

    private:
        unsigned long labelIfCounter = 0;
        unsigned long labelForCounter = 0;
        unsigned long labelWhileCounter = 0;
        unsigned long labelSwitchCounter = 0;
        unsigned long labelMethodCounter = 0;

        std::shared_ptr<MethodStaticInfo> generateDeclaredMethod(std::shared_ptr<MethodDecl>, std::string&);
        std::map<Symbol, std::shared_ptr<VarStaticInfo>> generateDeclaredVars(std::shared_ptr<FieldDecl>, std::string&);

    public:

        enum class LabelType {
            IF, FOR, WHILE, SWITCH, METHOD
        };

        std::string makeLabel(LabelType ltype) {
            switch (ltype) {
                case LabelType::IF:
                    return "if"+std::to_string(labelIfCounter++);
                break;
                case LabelType::FOR:
                    return "for"+std::to_string(labelForCounter++);
                break;
                case LabelType::WHILE:
                    return "while"+std::to_string(labelWhileCounter++);
                break;
                case LabelType::SWITCH:
                    return "switch"+std::to_string(labelSwitchCounter++);
                break;
				case LabelType::METHOD:
                    return "method"+std::to_string(labelMethodCounter++);
            } 
            return "no label";
        }

        std::string makeLabelStmt(std::string label) {
            return label + ":\n";
        }

        std::string makeGotoStmt(std::string label) {
            return "goto " + label + ";\n";
        }

        std::string fileName;
        std::string code;
        std::string frameStructDefinitions;
        std::string frameTypesEnum;
        std::string baseFrameDefinition;

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
