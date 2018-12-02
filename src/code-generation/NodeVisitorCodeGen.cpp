#include "code-generation/NodeVisitorCodeGen.h"
#include "ast/Expr.h"
#include <set>
#include "resources/MJUtils.h"

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
    //this->startExprProc();
    expr->expr->accept(*this);
    //this->code += "(t0)";
    //this->endExprProc();
}

void NodeVisitorCodeGen::visitRelExpr(RelExpr * expr) {
    auto tac = this->threeAddressesStacks.top().first;
    //int retNumberL = tac->top() + 1;
    //int retNumberR = tac->top() + 2;
    //tac->push(retNumberL); 
    //tac->push(retNumberR); 
    int retNumberL = requireExpr();
    int retNumberR = requireExpr();

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
    expr->lhs->accept(*this);
    expr->rhs->accept(*this);
    //this->code += opstr;
    this->code += "int " + makeVarTAC(tac->top()) + "=" + makeVarTAC(retNumberR) + opstr + makeVarTAC(retNumberL) + ";\n";
    doneExpr();
}

void NodeVisitorCodeGen::visitAlBinExpr(AlBinExpr * expr) {

    auto tac = this->threeAddressesStacks.top().first;
    //int retNumberL = tac->top() + 1;
    //int retNumberR = tac->top() + 2;
    //tac->push(retNumberL); 
    //tac->push(retNumberR); 
    int retNumberL = requireExpr();
    int retNumberR = requireExpr();

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
    expr->lhs->accept(*this);
    expr->rhs->accept(*this);
    this->code += "int " + makeVarTAC(tac->top()) + "=" + makeVarTAC(retNumberR) + opstr + makeVarTAC(retNumberL) + ";\n";
    tac->pop();
}

void NodeVisitorCodeGen::visitAlUnExpr(AlUnExpr * expr) {

    auto tac = this->threeAddressesStacks.top().first;
    int retNumberL = requireExpr();
    //int retNumberL = tac->top() + 1;
    //tac->push(retNumberL); 

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

    expr->alexpr->accept(*this);
    this->code += "int " + makeVarTAC(tac->top()) + "=" + opstr + "(" + makeVarTAC(retNumberL) + ")" + ";\n";
    //tac->pop();
    doneExpr();
}

void NodeVisitorCodeGen::visitLitExprString(LitExpr<std::string> * strlit) {
   auto p = this->threeAddressesStacks;
   if (p.empty())
      this->code += strlit->val;
   else {
      this->code += "char* t"+std::to_string(p.top().first->top())+ " = " + strlit->val + ";\n";
      p.top().first->pop();
   }
}
void NodeVisitorCodeGen::visitLitExprInt(LitExpr<int> * intlit) {
   // this->code += std::to_string(intlit->val);
   auto p = this->threeAddressesStacks;
   if (p.empty())
     this->code += intlit->val;
   else {
     this->code += "int t"+std::to_string(p.top().first->top())+ " = " + std::to_string(intlit->val) + ";\n";
     p.top().first->pop();
   }
}
void NodeVisitorCodeGen::visitAccessOperation(AccessOperation *) {}
void NodeVisitorCodeGen::visitBrackAccess(BracketAccess *) {}
void NodeVisitorCodeGen::visitDotAccess(DotAccess *) {}
void NodeVisitorCodeGen::visitVar(Var * var) {
    auto p = this->threeAddressesStacks;

    auto varPath = findVariableFramePath(var);

    std::string framePath = "stackFrame->" + std::get<0>(varPath);

    if (!p.empty()) {
        std::shared_ptr<VarStaticInfo> varDecl = 
            std::static_pointer_cast<VarStaticInfo>(MJResources::getInstance()->symbolTable.get(Symbol::symbol(var->id->id)));
        auto varType = varDecl->varType;

        if ((std::get<2>(varPath) == RHandReference::IS_FORMAL_NEEDS_REF
                    || std::get<2>(varPath) == RHandReference::IS_NOT_FORMAL)) {
            this->code += std::get<1>(varPath) +" t"+std::to_string(p.top().first->top())+ " = " + framePath + ";\n";
        } else {
            this->code += std::get<1>(varPath) +" t"+std::to_string(p.top().first->top())+ " = *" + framePath + ";\n";
        }

        p.top().first->pop();
    } else 
        this->code += var->id->id;

    // TODO: access operation
}
void NodeVisitorCodeGen::visitFunctionCallExpr(FunctionCallExpr * funcall) {

    std::shared_ptr<Var> var = funcall->var;
    std::shared_ptr<ConstructList> actuals = funcall->actualParams;

    // visit each var member
    
    std::shared_ptr<AccessOperation> itAccessOp = var->accessOperation;

    std::string varId = var->id->id;

    std::shared_ptr<ClassStaticInfo> csi = 
        std::static_pointer_cast<ClassStaticInfo>(MJResources::getInstance()->symbolTable.get(Symbol::symbol("$$")));

    if (itAccessOp == nullptr) {

        try {
            std::string newMFrameName = "newMFrame";
            std::string mFrameName = "method$" +csi->className+"$"+varId;
            std::string newFrameName = "newFrame";
            std::string unionName = csi->className + "$" + varId;
            this->code += "{\n";
            this->code += "struct "+ mFrameName + " *"+ newMFrameName +"= malloc(sizeof(struct "+mFrameName + "));\n";
            this->code += "struct Frame * " + newFrameName + " = malloc(sizeof(struct Frame));\n";
            this->code += newFrameName + "->mframe."+unionName + " = " + newMFrameName + ";\n";
            this->code += newFrameName + "->ftype = " + mFrameName + ";\n";
            this->code += newFrameName + "->prev = " + "stackFrame;\n"; 
            this->code += newFrameName + "->next = " + "NULL;\n"; 
            this->code += "stackFrame->next = " + newFrameName + ";\n";
            //this->code += "stackFrame = " + newFrameName + ";\n";

            std::string labelReturn = makeLabel(LabelType::RETURN_CALL, {{"class", csi->className},{"method", varId}});

            this->codeSwitchReturns += "if (strcmp(currentReturn,\""+ labelReturn + "\") == 0) {\n";
            this->codeSwitchReturns += "goto "+ labelReturn +";\n";
            this->codeSwitchReturns += "}\n";

            this->code += newMFrameName + "->retLabel = \""+labelReturn+"\";\n";

            //TODO first load methods
            std::shared_ptr<MethodStaticInfo> msi = csi->methods.at(Symbol::symbol(varId));
            if (actuals != nullptr) {
                auto itFormals = msi->formalParams.begin();
                auto itActuals = actuals->constructs.begin();

                while (itFormals != msi->formalParams.end()) {
                    std::string name = std::get<0>(*itFormals);
                    StaticInfo::Type type = std::get<1>(*itFormals);
                    bool val = std::get<2>(*itFormals);
                    this->startExprProc();

                    if (!val || (type.second > 0)) {
                        // is it a variable?!
                        if (Var * varRef = dynamic_cast<Var *>((*itActuals).get())) {
                            if (varRef->accessOperation != nullptr) {
                                throw std::logic_error("References must be simple variables!");
                            } else {
                                auto varFramePath = findVariableFramePath(varRef);
                                if (std::get<2>(varFramePath) == RHandReference::IS_FORMAL_NEEDS_REF
                                        ||(std::get<2>(varFramePath) == RHandReference::IS_NOT_FORMAL && type.second==0)) {
                                    this->code += newFrameName + "->mframe." + unionName + "->" + name + "= &"
                                    + "stackFrame->" + std::get<0>(varFramePath) + ";\n";
                                }
                                else {
                                    this->code += newFrameName + "->mframe." + unionName + "->" + name + "="
                                    + "stackFrame->" + std::get<0>(varFramePath)+";\n" ;
                                }
                                //this->code += newFrameName + "->mframe." + unionName + "->" + name + "= &"
                                //   + "stackFrame->" + std::get<0>(findVariableFramePath(varRef));
                            }
                        } else 
                            throw std::logic_error("References must be simple variables!");
                    } else {
                        (*itActuals)->accept(*this);
                        if (val || (type.second > 0))
                            this->code += newFrameName + "->mframe." + unionName + "->" + name + "= t0;\n";
                        else
                            this->code += newFrameName + "->mframe." + unionName + "->" + name + "= &t0;\n";
                    }
                    this->code += ";\n";
                    this->endExprProc();
                    itFormals++;
                    itActuals++;
                }
            }
            
            this->code += "stackFrame = " + newFrameName + ";\n";
            this->code += "goto " + msi->codeLabel + ";\n";
            this->code += "}\n";
            this->code += labelReturn + ":;\n";

            auto p = this->threeAddressesStacks;
            if (!p.empty()){
               std::string retType = getCType(msi->retType.first, msi->retType.second);
               this->code += retType + " t"+std::to_string(p.top().first->top())+ " = *(("+retType+"*) returnPointer);\n";
               this->code += "if (returnPointer != NULL) free(returnPointer);\n";
               this->code += "returnPointer = NULL;\n";
               p.top().first->pop();
            }
        } catch (const std::out_of_range & out) {
            throw std::logic_error("Subprogram not found");
        }
    }

    std::shared_ptr<ConstructList> actualParams = funcall->actualParams;






}

void NodeVisitorCodeGen::visitStmt(Stmt *) {}
void NodeVisitorCodeGen::visitAssignStmt(AssignStmt * assignStmt) {

    auto var = assignStmt->var;
    auto expr = assignStmt->expr;

    std::shared_ptr<VarStaticInfo> vsi = std::static_pointer_cast<VarStaticInfo>(
            MJResources::getInstance()->symbolTable.get(Symbol::symbol(var->id->id))
            );

    std::string entityStruct = vsi->entityName;

   std::shared_ptr<MethodStaticInfo> msi = 
       std::static_pointer_cast<MethodStaticInfo>(
               MJResources::getInstance()->symbolTable.get(Symbol::symbol("$")));
   std::shared_ptr<ClassStaticInfo> csi = 
       std::static_pointer_cast<ClassStaticInfo>(
               MJResources::getInstance()->symbolTable.get(Symbol::symbol("$$")));

    std::string methodName = csi->className + "$" + msi->methodName;

    MethodStaticInfo::FormalParam f;
    std::deque<MethodStaticInfo::FormalParam>::iterator formalIt;
    for (formalIt = msi->formalParams.begin(); formalIt != msi->formalParams.end(); ++formalIt) {
        if (std::get<0>(*formalIt) == var->id->id) break;
    }

    this->startExprProc();
    expr->accept(*this);
    bool conditionForReference = !std::get<2>(*formalIt) && (std::get<1>(*formalIt).second == 0);
    if (formalIt != msi->formalParams.end() and conditionForReference) 
        this->code += "*stackFrame->" + std::get<0>(findVariableFramePath(var.get())) + "= t0;";
    else
        this->code += "stackFrame->" + std::get<0>(findVariableFramePath(var.get())) + "= t0;";
    this->endExprProc();
}

void NodeVisitorCodeGen::visitFunctionCallStmt(FunctionCallStmt * funcall) {

    std::shared_ptr<Var> var = funcall->var;
    std::shared_ptr<ConstructList> actuals = funcall->actualParams;

    // visit each var member
    
    std::shared_ptr<AccessOperation> itAccessOp = var->accessOperation;

    std::string varId = var->id->id;

    std::shared_ptr<ClassStaticInfo> csi = 
        std::static_pointer_cast<ClassStaticInfo>(MJResources::getInstance()->symbolTable.get(Symbol::symbol("$$")));

    if (itAccessOp == nullptr) {

        try {
            std::string newMFrameName = "newMFrame";
            std::string mFrameName = "method$" +csi->className+"$"+varId;
            std::string newFrameName = "newFrame";
            std::string unionName = csi->className + "$" + varId;
            this->code += "{\n";
            this->code += "struct "+ mFrameName + " *"+ newMFrameName +"= malloc(sizeof(struct "+mFrameName + "));\n";
            this->code += "struct Frame * " + newFrameName + " = malloc(sizeof(struct Frame));\n";
            this->code += newFrameName + "->mframe."+unionName + " = " + newMFrameName + ";\n";
            this->code += newFrameName + "->ftype = " + mFrameName + ";\n";
            this->code += newFrameName + "->prev = " + "stackFrame;\n"; 
            this->code += newFrameName + "->next = " + "NULL;\n"; 
            this->code += "stackFrame->next = " + newFrameName + ";\n";

            std::string labelReturn = makeLabel(LabelType::RETURN_CALL, {{"class", csi->className},{"method", varId}});

            this->codeSwitchReturns += "if (strcmp(currentReturn,\""+ labelReturn + "\") == 0) {\n";
            this->codeSwitchReturns += "goto "+ labelReturn +";\n";
            this->codeSwitchReturns += "}\n";

            this->code += newMFrameName + "->retLabel = \""+labelReturn+"\";\n";

            std::shared_ptr<MethodStaticInfo> msi = csi->methods.at(Symbol::symbol(varId));

            if (actuals != nullptr){
                //TODO first load methods
                auto itFormals = msi->formalParams.begin();
                auto itActuals = actuals->constructs.begin();

                while (itFormals != msi->formalParams.end()) {
                    std::string name = std::get<0>(*itFormals);
                    StaticInfo::Type type = std::get<1>(*itFormals);
                    bool val = std::get<2>(*itFormals);
                    this->startExprProc();
                    if (!val || (type.second > 0)) {
                        // is it a variable?!
                        if (Var * varRef = dynamic_cast<Var *>((*itActuals).get())) {
                            if (varRef->accessOperation != nullptr) {
                                throw std::logic_error("References must be simple variables!");
                            } else {
                                auto varFramePath = findVariableFramePath(varRef);
                                if (std::get<2>(varFramePath) == RHandReference::IS_FORMAL_NEEDS_REF
                                        ||(std::get<2>(varFramePath) == RHandReference::IS_NOT_FORMAL && type.second==0)) {
                                    this->code += newFrameName + "->mframe." + unionName + "->" + name + "= &"
                                    + "stackFrame->" + std::get<0>(varFramePath) + ";\n";
                                }
                                else {
                                    this->code += newFrameName + "->mframe." + unionName + "->" + name + "="
                                    + "stackFrame->" + std::get<0>(varFramePath)+";\n" ;
                                }
                                //this->code += newFrameName + "->mframe." + unionName + "->" + name + "= &"
                                //   + "stackFrame->" + std::get<0>(findVariableFramePath(varRef));
                            }
                        } else 
                            throw std::logic_error("References must be simple variables!");
                    } else {
                        (*itActuals)->accept(*this);
                        if (val || (type.second > 0))
                            this->code += newFrameName + "->mframe." + unionName + "->" + name + "= t0;\n";
                        else
                            this->code += newFrameName + "->mframe." + unionName + "->" + name + "= &t0;\n";
                    }
                    this->code += ";\n";
                    this->endExprProc();
                    itFormals++;
                    itActuals++;
                }
            }
            
            this->code += "stackFrame = " + newFrameName + ";\n";
            this->code += "goto " + msi->codeLabel + ";\n";
            this->code += "}\n";
            this->code += labelReturn + ":\n";
            /*
            std::shared_ptr<Frame> frame = MJResources::getInstance()->newFrame();
            
            frame->label = msi->codeLabel;   

            //TODO frame->classFrame = ?;
            */
        } catch (const std::out_of_range & out) {
            throw std::logic_error("Subprogram not found");
        }
    }

    std::shared_ptr<ConstructList> actualParams = funcall->actualParams;
}

void NodeVisitorCodeGen::visitReadStmt(ReadStmt * readStmt) {
    //TODO: frame stack
}

void NodeVisitorCodeGen::visitPrintStmt(PrintStmt * print) {
    if (LitExpr<std::string> * v = dynamic_cast<LitExpr<std::string>*>(print->expr.get())) {
        std::string retVal = this->startExprProc();
        v->accept(*this);
        this->code += std::string("printf(\"%s\"," + retVal + ");");
        this->endExprProc();
    } else {
        //this->code += std::string("printf(\"%s\", std::to_string(");
        std::string retVal = this->startExprProc();
        print->expr->accept(*this);
        this->code += std::string("printf(\"%d\"," + retVal + ");");
        this->endExprProc();
    }
}
void NodeVisitorCodeGen::visitCase(Case * casesstmt) {
    casesstmt->stmts->accept(*this);
}
void NodeVisitorCodeGen::visitSwitchStmt(SwitchStmt * switchstmt) {
    
    std::string labelout = makeLabel(LabelType::SWITCH);

    std::shared_ptr<Var> varExpr = std::static_pointer_cast<Var>(switchstmt->expr);

    if (varExpr.get() == nullptr)
        throw new std::logic_error("Invalid switch expression, use only an identifier");
    
    while (!switchstmt->caseList->constructs.empty()) {
        std::string labelcase = makeLabel(LabelType::SWITCH);
        std::string nextcase = makeLabel(LabelType::SWITCH);
        auto casestmt = 
            dynamic_cast<Case*>(switchstmt->caseList->constructs.front().get());

        this->startExprProc();
        casestmt->expr->accept(*this);
        this->code += "if (";
        this->code += "stackFrame->" + std::get<0>(findVariableFramePath(varExpr.get()));
        this->code += "== t0)\n";  
        this->code += makeGotoStmt(labelcase);
        this->code += makeGotoStmt(nextcase);
        this->endExprProc();
        this->code += makeLabelStmt(labelcase); 
        casestmt->stmts->accept(*this);
        this->code += makeGotoStmt(labelout);
        this->code += makeLabelStmt(nextcase);

        switchstmt->caseList->constructs.pop_front();
    }

    if (switchstmt->defaultStmts != nullptr)
        switchstmt->defaultStmts->accept(*this);
    this->code += makeLabelStmt(labelout);

}
void NodeVisitorCodeGen::visitWhileStmt(WhileStmt * whilestmt) {
    std::string labelWhile = this->makeLabel(LabelType::WHILE);
    std::string labelIn = this->makeLabel(LabelType::WHILE);
    std::string labelOut = this->makeLabel(LabelType::WHILE);
    this->code += makeLabelStmt(labelWhile);
    this->startExprProc();
    whilestmt->expr->accept(*this);
    this->code += "if (t0)\n";
    this->code += makeGotoStmt(labelIn);
    this->code += makeGotoStmt(labelOut);
    this->endExprProc();
    this->code += makeLabelStmt(labelIn);
    whilestmt->stmts->accept(*this);
    this->code += makeGotoStmt(labelWhile);
    this->code += makeLabelStmt(labelOut);
    
}
void NodeVisitorCodeGen::visitForStmt(ForStmt * forStmt) {
    //TODO
    std::string labelFor = this->makeLabel(LabelType::FOR);
    std::string labelIn = this->makeLabel(LabelType::FOR);
    std::string labelEval = this->makeLabel(LabelType::FOR);
    std::string labelOut = this->makeLabel(LabelType::FOR);

    std::shared_ptr<Var> var = std::make_shared<Var>(forStmt->pos, forStmt->id, nullptr);

    std::string iterVarPath = "stackFrame->" + std::get<0>(findVariableFramePath(var.get()));

    this->startExprProc();
    forStmt->assignExpr->accept(*this);
    this->code += iterVarPath;
    this->code += "=";
    this->code += "t0;\n";
    this->endExprProc();

    //Evaluates "from" and "to" Expressions detecting
    //min and max. These expressions are evaluated only
    //ONCE: before the first iteration.
    //e.g. for id := E1 to E2
    std::string min = labelFor + "min";
    std::string max = labelFor + "max";
    this->code += "int " + min + ";\n";
    this->code += "int " + max + ";\n";
    //Expr1 was previously evaluated
    this->code += min + "=";
    this->code += iterVarPath;
    this->code += ";\n";
    //Evaluates Expr2
    this->startExprProc();
    forStmt->toExpr->accept(*this);
    this->code += max + "= t0;\n";
    this->endExprProc();
    //Evaluates step expression
	std::string step = labelFor + "step";
    this->code += "int "+ step + " = 1;\n";
    if (forStmt->stepExpr != nullptr) {
        this->startExprProc();
		forStmt->stepExpr->accept(*this);
		this->code += step + "= t0;\n";
        this->endExprProc();
    }
    //Swaps min and max if necessary
    this->code += "if (" + min + ">" + max + ")";
    this->code += makeGotoStmt(labelEval);

    //Starts For statement loop
    //TODO: verify operations of id->accept().
    //does it change the id name? Does it allocate memory?
    //does it override variable with the same name?
    this->code += makeLabelStmt(labelFor);
    this->code += "if (";
    this->code += min + "<=";
    this->code += iterVarPath;
    this->code += " && ";
    this->code += max + ">=";
    this->code += iterVarPath;
    this->code += ")";
    this->code += makeGotoStmt(labelIn);
    this->code += makeGotoStmt(labelOut);

    //Processes statement list
    this->code += makeLabelStmt(labelIn);
    forStmt->stmts->accept(*this);

    //Increments control variable and goes back to condition
    //TODO: verify operations of id->accept() and its side
    //effects
    this->code += iterVarPath + "+=" + step + ";";
    this->code += makeGotoStmt(labelFor);

    //Adds label and implemantation for min and max swapping
    this->code += makeLabelStmt(labelEval);
    this->code += ";int " + labelEval + "swap;\n";
    std::string swap = labelEval + "swap";
    this->code += swap + "=" + min + ";";
    this->code += min + "=" + max + ";";
    this->code += max + "=" + swap + ";";
    this->code += makeGotoStmt(labelFor);

    this->code += makeLabelStmt(labelOut);

}
void NodeVisitorCodeGen::visitElsePart(ElsePart *) {}
void NodeVisitorCodeGen::visitElse(Else * elsestmt) {
    elsestmt->stmts->accept(*this);
}
void NodeVisitorCodeGen::visitIfStmt(IfStmt * ifstmt) {
    std::string labelIn = this->makeLabel(LabelType::IF);
    std::string labelElse = this->makeLabel(LabelType::IF);
    std::string labelOut = this->makeLabel(LabelType::IF);
    this->startExprProc();
    ifstmt->expr->accept(*this);
    this->code += "if (t0) \n";
    this->code += makeGotoStmt(labelIn);
    this->code += makeGotoStmt(labelElse);
    this->endExprProc();

    this->code += makeLabelStmt(labelIn);
    ifstmt->stmts->accept(*this);
    this->code += makeGotoStmt(labelOut);

    this->code += makeLabelStmt(labelElse);
    if (ifstmt->elsePart != nullptr) {
        ifstmt->elsePart->accept(*this);
    }

    this->code += makeLabelStmt(labelOut);
}
void NodeVisitorCodeGen::visitElseIf(ElseIf * elseifstmt) {
    elseifstmt->ifStmt->accept(*this);
} 

void NodeVisitorCodeGen::visitReturnStmt(ReturnStmt * returnStmt) {

    std::shared_ptr<MethodStaticInfo> msi = 
        std::static_pointer_cast<MethodStaticInfo>(MJResources::getInstance()->symbolTable.get(Symbol::symbol("$")));
    this->startExprProc();
    returnStmt->expr->accept(*this);
    std::string retType = getCType(msi->retType.first, msi->retType.second);
    this->code += retType + " * $returnPointerValue = (" + retType + " *) malloc(sizeof("+ retType +"));\n";
    this->code += "*$returnPointerValue = (" + retType + ") t0;\n";
    this->code += "returnPointer = $returnPointerValue;\n";
    this->code += "int n = strlen(stackFrame->mframe." + msi->className+"$"+ msi->methodName + "->retLabel);\n";
    this->code += "currentReturn = (char *) realloc(currentReturn, n+1);\n";
    this->code += "strcpy(currentReturn, stackFrame->mframe." + msi->className+"$"+ msi->methodName + "->retLabel);\n";

    this->code += "stackFrame->prev->next = NULL;\n";
    this->code += "struct Frame * toDelete = stackFrame;\n";
    this->code += "stackFrame = toDelete->prev;\n";
    this->code += "free(toDelete);\n";

    this->code += "goto retSwitch;\n";
    this->endExprProc();
}

void NodeVisitorCodeGen::visitType(Type * type) {}

void NodeVisitorCodeGen::visitVarDeclId(VarDeclId *) {}
void NodeVisitorCodeGen::visitVarInit(VarInit * varinit) {}
void NodeVisitorCodeGen::visitFieldDeclVar(FieldDeclVar * fieldvar) {}
void NodeVisitorCodeGen::visitFieldDecl(FieldDecl * fielddecl) {

}
void NodeVisitorCodeGen::visitDecls(Decls * decls) {
    if (decls->fields != nullptr)
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
	
}
void NodeVisitorCodeGen::visitClassBody(ClassBody * classbody) {
    if (classbody->decls != nullptr)
        classbody->decls->accept(*this);
    if (classbody->methods != nullptr)
        classbody->methods->accept(*this);
}
void NodeVisitorCodeGen::visitClassDecl(ClassDecl * classdecl) {

    std::string classId = classdecl->id->id;

    std::shared_ptr<ClassStaticInfo> csi = std::make_shared<ClassStaticInfo>();
    csi->className = classId;

    auto res = MJResources::getInstance();
    res->beginScope(MJResources::ScopeType::CLASS);
    res->symbolTable.put(Symbol::symbol("$$"), csi);

    bool isClassMain = (classId == "Main");

    if (isClassMain and MJResources::getInstance()->mainClass != nullptr) {
        throw new std::logic_error("A program must have only one Main class"); 
    } else if (isClassMain) {
        MJResources::getInstance()->mainClass = csi;
    }

    Symbol symbol = Symbol::symbol(classId);

    std::string structClass = "struct class$" + classId + "\n{\n"; 

    frameTypesEnum += "class$"+classId+",\n"; // add field to frame types enum
    baseFrameDefinition += "struct class$" + classId + " *" + classId + ";\n"; // add to union in a frame

    auto decls = classdecl->body->decls;
    std::string genDeclsStructFields = "";
    if (decls != nullptr && decls->fields != nullptr) {
        while (!decls->fields->constructs.empty()) {
            std::shared_ptr<FieldDecl> fielddecl = 
                std::dynamic_pointer_cast<FieldDecl>(decls->fields->constructs.front()); 
            std::set<std::string> locals;
            auto mvsi = this->generateDeclaredVars(fielddecl, genDeclsStructFields, locals, NodeVisitorCodeGen::EntityType::CLASS, classId);
            csi->attributes.insert(mvsi.begin(), mvsi.end());    
            decls->fields->constructs.pop_front();
        }
    }
    structClass += genDeclsStructFields;
    structClass += "};\n";
    
    this->frameStructDefinitions += structClass;

    auto methods = classdecl->body->methods;
    if (methods != nullptr) {
        bool foundMethodMain = false;

        while (!methods->constructs.empty()) {
            std::shared_ptr<MethodDecl> methodDecl = 
                std::dynamic_pointer_cast<MethodDecl>(methods->constructs.front()); 

            std::string methodid = methodDecl->id->id;

            frameTypesEnum += "method$"+classId+"$"+methodid+",\n"; // add field to frame types enum
            baseFrameDefinition += "struct method$" + classId + "$" + methodid+ " *" +classId + "$"+methodid + ";\n"; // add to union in a frame

            std::string structMethod = "struct method$" + classId + "$" + methodid + "{\n"; 
            structMethod += "char * retLabel;\n";

            auto msi = this->generateDeclaredMethod(methodDecl, structMethod, csi);
            structMethod += "};\n";

            this->frameStructDefinitions += structMethod;

            //csi->methods.insert(std::make_pair(Symbol::symbol(methodDecl->id->id), msi)); 
            if (methodDecl->id->id == "main") {
                MJResources::getInstance()->mainMethod = msi;
                foundMethodMain = true;
            }
            methods->constructs.pop_front();
        }

        if (isClassMain and not foundMethodMain) 
            throw std::logic_error("The Main class must have a main method");
    }

    res->endScope(MJResources::ScopeType::CLASS);

    MJResources::getInstance()->staticInfoTable.put(symbol, csi);
}
void NodeVisitorCodeGen::visitProgram(Program * program) {

    program->id->accept(*this); // no matter what

    this->baseFrameDefinition += "struct Frame {\n";
    this->baseFrameDefinition += "enum FType ftype;\n";
    this->baseFrameDefinition += "struct Frame* next;\n";
    this->baseFrameDefinition += "struct Frame* prev;\n";
    this->baseFrameDefinition += "union {\n";

    this->frameTypesEnum += "enum FType {\n";

    std::string mainDecl = "int main(void) {\n";

    mainDecl += "void * returnPointer = NULL;\n";

    this->codeSwitchReturns += "// switch for return points\n";
    mainDecl += "struct Frame * stackFrame = malloc(sizeof(struct Frame));\n";
    mainDecl += "char * currentReturn = (char*) malloc(5*sizeof(char));\n";
    mainDecl += "strcpy(currentReturn, \"exit\");\n";
    this->codeSwitchReturns += "retSwitch:\n";
    this->codeSwitchReturns += "if (strcmp(currentReturn,\"exit\") == 0) {\n";
    this->codeSwitchReturns += "free(stackFrame);\n";
    this->codeSwitchReturns += "return 0;\n";
    this->codeSwitchReturns += "}\n";

    program->classes->accept(*this);

    std::string newMFrameName = "newMFrame";
    std::string mFrameName = "method$Main$main";
    std::string newFrameName = "newFrame";
    std::string unionName = "Main$main";
   
    mainDecl += "{"; 
    mainDecl += "struct "+ mFrameName + " *"+ newMFrameName +"= malloc(sizeof(struct "+mFrameName + "));\n";
    mainDecl += "struct Frame * " + newFrameName + " = malloc(sizeof(struct Frame));\n";
    mainDecl += newMFrameName + "->retLabel = \"exit\";\n";
    mainDecl += newFrameName + "->mframe."+unionName + " = " + newMFrameName + ";\n";
    mainDecl += newFrameName + "->ftype = " + mFrameName + ";\n";
    mainDecl += newFrameName + "->prev = " + "stackFrame;\n"; 
    mainDecl += newFrameName + "->next = " + "NULL;\n"; 
    mainDecl += "stackFrame->next = " + newFrameName + ";\n";
    mainDecl += "stackFrame = " + newFrameName + ";\n";
    mainDecl += "goto " + MJResources::getInstance()->mainMethod->codeLabel + ";\n";
    mainDecl += "}\n";

    this->code += "return 0;\n}\n";

    // close union and base frame definition
    this->baseFrameDefinition += "} mframe;\n";
    this->baseFrameDefinition += "};\n";

    // close frame Types enum
    this->frameTypesEnum += "};\n";

    std::string includePart = "#include <stdio.h>\n";
    includePart += "#include <stdlib.h>\n";
    includePart += "#include <string.h>\n";

    this->code = includePart + frameTypesEnum + baseFrameDefinition + frameStructDefinitions + mainDecl + codeSwitchReturns + this->code;

    if (MJResources::getInstance()->mainClass == nullptr)
        throw std::logic_error("Missing the Main class");
}
void NodeVisitorCodeGen::visitExprVarInit(ExprVarInit * varinit) {
    varinit->expr->accept(*this);
}

void NodeVisitorCodeGen::visitArrayInitVarInit(ArrayInitVarInit *) {}

void NodeVisitorCodeGen::visitArrayCreation(ArrayCreation * arrcreation) {
    std::shared_ptr<Type> type = arrcreation->type;
    std::string ctype = getCType(type->typeName, type->numBrackets); 
    
    std::shared_ptr<ConstructList> dims = arrcreation->dims;
    int dimsCount = 0;
    std::vector<std::string> dimsVars;

    while (!dims->constructs.empty()) {
        std::string dimVarName = "k"+std::to_string(dimsCount);        
        this->code += "int " + dimVarName + ";\n"; 
        this->startExprProc();
        dims->constructs.front()->accept(*this);
        this->code += dimVarName + " = t0;\n"; 
        this->endExprProc();
        dimsVars.push_back(dimVarName);
        dimsCount++;
        dims->constructs.pop_front();
    }

    auto tac = threeAddressesStacks.top().first;
    this->code += MJUtils::arrayCreationString(ctype, dimsVars, "t"+std::to_string(tac->top()));
    doneExpr();
}

void NodeVisitorCodeGen::visitArrayCreationVarInit(ArrayCreationVarInit * acvi) {
    acvi->accept(*this);
}

std::map<Symbol, std::shared_ptr<VarStaticInfo>> NodeVisitorCodeGen::generateDeclaredVars(
        std::shared_ptr<FieldDecl> fielddecl, std::string & structFields, std::set<std::string> & alreadyDeclaredVars,NodeVisitorCodeGen::EntityType entityType,
        std::string entityName) {

    std::map<Symbol, std::shared_ptr<VarStaticInfo>> declaredVars;
    std::shared_ptr<Type> type = fielddecl->type;
    std::shared_ptr<ConstructList> varDecls = fielddecl->varsDecls;
    if (varDecls != nullptr) {
        while(!varDecls->constructs.empty()) {
            std::shared_ptr<FieldDeclVar> varDecl =
                    std::dynamic_pointer_cast<FieldDeclVar>(varDecls->constructs.front());
            std::shared_ptr<VarDeclId> id = varDecl->varDeclId;

            if (alreadyDeclaredVars.find(id->id->id) != alreadyDeclaredVars.end())
                throw new std::logic_error("Already defined variable " + id->id->id);
            else alreadyDeclaredVars.insert(id->id->id);

            structFields += getCType(type->typeName, type->numBrackets) + " " + id->id->id + ";\n";

            if (entityType == NodeVisitorCodeGen::EntityType::METHOD)
                this->code += getCType(type->typeName, type->numBrackets) + " " + id->id->id + " = " + "methodFrame->mframe." + entityName + "->" + id->id->id  + ";\n";
            Symbol symbol = Symbol::symbol(id->id->id); // \o/ =D
            std::shared_ptr<VarStaticInfo> vsi = std::make_shared<VarStaticInfo>();
            vsi->varType = std::make_pair(getCType(type->typeName), type->numBrackets);

            if (entityType == NodeVisitorCodeGen::EntityType::METHOD) {
                vsi->scope = VarStaticInfo::ScopeType::METHOD;
            }
            else {
                vsi->scope = VarStaticInfo::ScopeType::CLASS;
            }
            vsi->entityName = entityName;

            MJResources::getInstance()->declareVar(symbol, vsi);
            std::shared_ptr<VarInit> varInit = varDecl->varInit;
            if (varInit != nullptr) {
                this->startExprProc();
                varInit->accept(*this);
                this->code += "methodFrame->mframe." + entityName + "->" + id->id->id + "=t0;\n";
                this->endExprProc();
            }
            declaredVars.insert(std::make_pair(symbol, vsi));
            varDecls->constructs.pop_front();
        }
    }
    return declaredVars;
}

std::shared_ptr<MethodStaticInfo> NodeVisitorCodeGen::generateDeclaredMethod(std::shared_ptr<MethodDecl> metdecl,
        std::string & genCode, std::shared_ptr<ClassStaticInfo> & csi) {

    std::set<std::string> locals;

    std::string methodid = metdecl->id->id;

	std::string methodlabel = makeLabel(LabelType::METHOD, {{"class", csi->className},{"method",methodid}});

    auto msi = std::make_shared<MethodStaticInfo>();
    msi->methodName = methodid;

    csi->methods.insert(std::make_pair(Symbol::symbol(methodid), msi)); 
    msi->codeLabel = methodlabel;

    auto res = MJResources::getInstance();
    res->beginScope(MJResources::ScopeType::METHOD);
    res->symbolTable.put(Symbol::symbol("$"), msi);

    msi->className = csi->className;

    genCode += "struct Frame* classFrame;\n";

    std::shared_ptr<Type> retType = metdecl->returnType->type;

    if (retType != nullptr)
        msi->retType = std::make_pair(getCType(retType->typeName), retType->numBrackets);

	this->code += makeLabelStmt(methodlabel);
    this->code += "{\n";
    this->code += "struct Frame* methodFrame = stackFrame;\n";
    this->code += "struct Frame* classFrame = methodFrame->mframe." + csi->className+"$"+ methodid + "->classFrame;\n";

    if (metdecl->params != nullptr) {
        while(!metdecl->params->constructs.empty()) {
            std::shared_ptr<FormalParams> fparams = 
                std::dynamic_pointer_cast<FormalParams>(metdecl->params->constructs.front()); 
            if (fparams != nullptr) {
                // get formal type
                std::shared_ptr<Type> ftype = fparams->type;
                StaticInfo::Type sfType = std::make_pair(getCType(ftype->typeName), ftype->numBrackets);
                // get val modifier
                bool fval = fparams->val;
                // get formal ids
                while (!fparams->ids->constructs.empty()) {
                    std::string fid = std::dynamic_pointer_cast<Id>(fparams->ids->constructs.front())->id;

                    if (locals.find(fid) != locals.end())
                        throw new std::logic_error("Multiple defined variable " + fid);

                    locals.insert(fid);

                    bool testIfPointer = (fval || (ftype->numBrackets > 0));

                    genCode += getCType(ftype->typeName, sfType.second) + " " + (testIfPointer ? "" : "*") + fid + ";\n";
                    this->code += getCType(ftype->typeName, sfType.second) + " " + (testIfPointer ? "" : "*") + fid + " = " + "methodFrame->mframe." + csi->className + "$" + methodid + "->" + fid  + ";\n";

                    // add to symbol table
                    std::shared_ptr<VarStaticInfo> vsi = std::make_shared<VarStaticInfo>();
                    vsi->varType = sfType;
                    vsi->scope = VarStaticInfo::ScopeType::METHOD;
                    MJResources::getInstance()->declareVar(Symbol::symbol(fid), vsi);

                    MethodStaticInfo::FormalParam fp = std::make_tuple(fid, sfType, fval);
                    msi->formalParams.push_back(fp);
                    fparams->ids->constructs.pop_front();
                }
                metdecl->params->constructs.pop_front();
            }
        }
    }

    auto decls = metdecl->block->decls;
    if (decls != nullptr && decls->fields != nullptr) {
        while (!decls->fields->constructs.empty()) {
            std::shared_ptr<FieldDecl> fielddecl = 
                std::dynamic_pointer_cast<FieldDecl>(decls->fields->constructs.front()); 
            auto mvsi = this->generateDeclaredVars(fielddecl, genCode, locals, NodeVisitorCodeGen::EntityType::METHOD, csi->className + "$" + methodid);
            msi->variables.insert(mvsi.begin(), mvsi.end());    
            decls->fields->constructs.pop_front();
        }
    }

    for (auto it = csi->attributes.begin(); it != csi->attributes.end(); ++it) {
        std::string id = it->first.to_string();

        if (locals.find(id) != locals.end()) {
            continue;
        } else locals.insert(id);

        std::shared_ptr<VarStaticInfo> vsi = it->second;     
        MJResources::getInstance()->declareVar(Symbol::symbol(id), vsi);
        StaticInfo::Type type = vsi->varType;
        this->code += type.first + " " + id + " = " + "classFrame->mframe." +csi->className+"->" + id  + ";\n";
    } 

    metdecl->block->accept(*this); 

    this->code += "int n = strlen(stackFrame->mframe." + csi->className+"$"+ methodid + "->retLabel);\n";
    this->code += "currentReturn = (char *) realloc(currentReturn, n+1);\n";
    this->code += "strcpy(currentReturn, stackFrame->mframe." + csi->className+"$"+ methodid + "->retLabel);\n";
    this->code += "stackFrame->prev->next = NULL;\n";
    this->code += "struct Frame * toDelete = stackFrame;\n";
    this->code += "stackFrame = toDelete->prev;\n";
    this->code += "free(toDelete);\n";
    this->code += "}\n";
    this->code += "goto retSwitch;\n";

    res->endScope(MJResources::ScopeType::METHOD);
    return msi;
}

std::tuple<std::string, std::string, NodeVisitorCodeGen::RHandReference> NodeVisitorCodeGen::findVariableFramePath(Var * var) {

    std::string varId = var->id->id;

    std::shared_ptr<VarStaticInfo> vsi = std::static_pointer_cast<VarStaticInfo>(
            MJResources::getInstance()->symbolTable.get(Symbol::symbol(varId))
            );

    std::string entityStruct = vsi->entityName;

   std::shared_ptr<MethodStaticInfo> msi = 
       std::static_pointer_cast<MethodStaticInfo>(
               MJResources::getInstance()->symbolTable.get(Symbol::symbol("$")));
   std::shared_ptr<ClassStaticInfo> csi = 
       std::static_pointer_cast<ClassStaticInfo>(
               MJResources::getInstance()->symbolTable.get(Symbol::symbol("$$")));

    std::string methodName = csi->className + "$" + msi->methodName;

    std::string resPath = "";
    std::string retType = getCType(vsi->varType.first, vsi->varType.second);

    if (vsi->scope == VarStaticInfo::ScopeType::METHOD)
        resPath += "mframe." + methodName + "->" + varId;
    else
        resPath += "mframe." + methodName + "->classFrame->mframe." + csi->className +"->" + varId;

    MethodStaticInfo::FormalParam f;
    std::deque<MethodStaticInfo::FormalParam>::iterator formalIt;
    for (formalIt = msi->formalParams.begin(); formalIt != msi->formalParams.end(); ++formalIt) {
        if (std::get<0>(*formalIt) == var->id->id) break;
    }

    RHandReference rhandreference = RHandReference::IS_NOT_FORMAL;

    if (formalIt != msi->formalParams.end()) {
        bool conditionForDemandReference = std::get<2>(*formalIt) && (std::get<1>(*formalIt).second == 0);
        if (conditionForDemandReference)
            rhandreference = RHandReference::IS_FORMAL_NEEDS_REF;
        else
            rhandreference = RHandReference::IS_FORMAL_NO_NEEDS_REF;
    }

    if (var->accessOperation != nullptr) {

       if (BracketAccess * brackAcc = dynamic_cast<BracketAccess*>(var->accessOperation.get())){

           std::shared_ptr<ConstructList> exprs = brackAcc->expressionList;

           std::vector<std::string> indexes;

           int resultingDimension = vsi->varType.second-exprs->constructs.size();

           retType = getCType(vsi->varType.first,vsi->varType.second-exprs->constructs.size());

            if (resultingDimension == 0 && rhandreference != RHandReference::IS_NOT_FORMAL) 
                rhandreference = RHandReference::IS_FORMAL_NEEDS_REF;           

           while(!exprs->constructs.empty()) {
               std::string indexVarName = "i"+std::to_string(getIndexLabel());
               this->code += "int " + indexVarName + ";\n";
               this->startExprProc();
               exprs->constructs.front()->accept(*this); 
               this->code += indexVarName + " = t0;\n";
               this->endExprProc();
               indexes.push_back(indexVarName);
               exprs->constructs.pop_front();
           }

           resPath += MJUtils::makeLhs("", indexes);

       } else if (DotAccess * dotAcc = dynamic_cast<DotAccess*>(var->accessOperation.get())) {
            //TODO class access       
       }
    }

    return std::make_tuple(resPath, retType, rhandreference);
}
