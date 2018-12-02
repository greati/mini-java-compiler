#ifndef __NODEVISITORCODE__
#define __NODEVISITORCODE__

#include <set>
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
        unsigned long labelCallReturnCounter = 0;

    public:

        enum class EntityType {
            METHOD, CLASS
        };

        enum class LabelType {
            IF, FOR, WHILE, SWITCH, METHOD, RETURN_CALL
        };

   private:
        std::shared_ptr<MethodStaticInfo> generateDeclaredMethod(std::shared_ptr<MethodDecl>, std::string&,
                std::shared_ptr<ClassStaticInfo> &);
        std::map<Symbol, std::shared_ptr<VarStaticInfo>> generateDeclaredVars(std::shared_ptr<FieldDecl>, 
                std::string&,std::set<std::string> & alreadyDeclaredVars,
                EntityType entityType = EntityType::METHOD,
                std::string entityName = "");
        std::string findVariableFramePath(Var * var);

        inline int requireExpr() {
            int curr = threeAddressesStacks.top().second;
            threeAddressesStacks.top().first->push(curr + 1);
            threeAddressesStacks.top().second++;
            return curr + 1;
        }

        inline void doneExpr() {
            threeAddressesStacks.top().first->pop();
        }

        inline std::string startExprProc() {
            this->code += "{\n";
            threeAddressesStacks.push(std::make_pair(std::make_shared<std::stack<int>>(), 0));
            threeAddressesStacks.top().first->push(0);
            return "t"+std::to_string(0);
        }
        inline void endExprProc() {
            threeAddressesStacks.pop();
            this->code += "}\n";
        }

        inline std::string makeVarTAC(int i) {
            return "t" + std::to_string(i);
        }
    
        typedef std::pair<std::shared_ptr<std::stack<int>>, int> ThreeAddressState;

        std::stack<ThreeAddressState> threeAddressesStacks;
   
   public:
        inline std::string getCType(std::string mjtype, int numBrackets = 0) const {
            std::string typeRes = "";
            if (mjtype == "string")
                typeRes += "char *";
            else if (mjtype == "int")
                typeRes += "int";
            else typeRes += "struct class$"+mjtype+"*";
            while (numBrackets--) {
                typeRes += "*";
            }
            return typeRes;
        }

        std::string makeLabel(LabelType ltype, std::map<std::string, std::string> attrs = {}) {
            switch (ltype) {
                case LabelType::IF:
                    return "if"+std::to_string(labelIfCounter++);
                case LabelType::FOR:
                    return "for"+std::to_string(labelForCounter++);
                case LabelType::WHILE:
                    return "while"+std::to_string(labelWhileCounter++);
                case LabelType::SWITCH:
                    return "switch"+std::to_string(labelSwitchCounter++);
				case LabelType::METHOD:
                    return attrs["class"]+"$"+attrs["method"]+"$body";
                case LabelType::RETURN_CALL:
                    return attrs["class"]+"$"+attrs["method"]+"$c"+std::to_string(labelCallReturnCounter++)+"$ret";
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
        std::string codeSwitchReturns;

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
