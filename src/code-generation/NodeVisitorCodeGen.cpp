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

void NodeVisitorCodeGen::visitFunctionCallStmt(FunctionCallStmt * funcall) {
    
    std::shared_ptr<Var> var = funcall->var;
    std::shared_ptr<ConstructList> actuals = funcall->actualParams;

    // visit each var member
    
    std::shared_ptr<AccessOperation> itAccessOp = var->accessOperation;

    std::string varId = var->id->id;

    std::shared_ptr<ClassStaticInfo> csi = MJResources::getInstance()->symbolTable.get(Symbol::symbol("$"));

    if (itAccessOp == nullptr) {

        try {
            std::shared_ptr<MethodStaticInfo> msi = csi->methods.at(Symbol::symbol(varId));

            std::shared_ptr<Frame> frame = MJResources::getInstance()->newFrame();
            
            frame->label = msi->codeLabel;   

            for (auto & formalParam : msi->formalParams) {
                std::string name = std::get<0>(formalParam);
                StaticInfo::Type type = std::get<1>(formalParam);
                bool val = std::get<2>(formalParam);

                Param p;

                frame->formals.insert(std::make_pair(name, p));
            }

            //TODO frame->classFrame = ?;

        } catch (const std::out_of_range & out) {
            throw std::logic_error("Subprogram not found");
        }
    }

    /*if (csi != nullptr) {
        while (itAccessOp != nullptr) {
            
            
            itAccessOp = itAccessOp->accessOperation; 
        }
    } else throw std::logic_error("Variable " + varId + " not declared");
    */

    // match the function
    // new scope
    // new framestack

    // a.b.c(0)

    std::shared_ptr<ConstructList> actualParams = funcall->actualParams;
}

void NodeVisitorCodeGen::visitReadStmt(ReadStmt * readStmt) {
    //TODO: frame stack
}

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
void NodeVisitorCodeGen::visitCase(Case * casesstmt) {
    casesstmt->stmts->accept(*this);
}
void NodeVisitorCodeGen::visitSwitchStmt(SwitchStmt * switchstmt) {
    
    std::string labelout = makeLabel(LabelType::SWITCH);

    
    while (!switchstmt->caseList->constructs.empty()) {
        std::string labelcase = makeLabel(LabelType::SWITCH);
        std::string nextcase = makeLabel(LabelType::SWITCH);
        auto casestmt = 
            dynamic_cast<Case*>(switchstmt->caseList->constructs.front().get());
        
        this->code += "if (";
        switchstmt->expr->accept(*this);
        this->code += "==";
        casestmt->expr->accept(*this);
        this->code += ")";  
        this->code += makeGotoStmt(labelcase);
        this->code += makeGotoStmt(nextcase);
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
    this->code += "if (";
    whilestmt->expr->accept(*this);
    this->code += ")";
    this->code += makeGotoStmt(labelIn);
    this->code += makeGotoStmt(labelOut);
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

    //Evaluates assignment
    forStmt->id->accept(*this);
    this->code += "=";
    forStmt->assignExpr->accept(*this);
    this->code += "; //TODO\n";

    //Evaluates "from" and "to" Expressions detecting
    //min and max. These expressions are evaluated only
    //ONCE: before the first iteration.
    //e.g. for id := E1 to E2
    std::string min = labelFor + "min";
    std::string max = labelFor + "max";
    //Expr1 was previously evaluated
    this->code += min + "=";
    forStmt->id->accept(*this);
    this->code += ";";
    //Evaluates Expr2
    this->code += max + "=";
    forStmt->toExpr->accept(*this);
    this->code += ";\n";
    //Evaluates step expression
	std::string step = labelFor + "step";
    if (forStmt->stepExpr != nullptr) {
		this->code += step + "=";
		forStmt->stepExpr->accept(*this);
		this->code += ";";
    }
	else
		this->code += step + "=1;";
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
    forStmt->id->accept(*this);
    this->code += " && ";
    this->code += max + ">=";
    forStmt->id->accept(*this);
    this->code += ")";
    this->code += makeGotoStmt(labelIn);
    this->code += makeGotoStmt(labelOut);

    //Processes statement list
    this->code += makeLabelStmt(labelIn);
    forStmt->stmts->accept(*this);

    //Increments control variable and goes back to condition
    //TODO: verify operations of id->accept() and its side
    //effects
    forStmt->id->accept(*this);
    this->code += "+" + step + ";";
    this->code += makeGotoStmt(labelFor);

    //Adds label and implemantation for min and max swapping
    this->code += makeLabelStmt(labelEval);
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
    this->code += "if (";
    ifstmt->expr->accept(*this);
    this->code += ")";
    this->code += makeGotoStmt(labelIn);
    this->code += makeGotoStmt(labelElse);

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

void NodeVisitorCodeGen::visitReturnStmt(ReturnStmt *) {
    //TODO: frame stack
}

void NodeVisitorCodeGen::visitType(Type * type) {}

void NodeVisitorCodeGen::visitVarDeclId(VarDeclId *) {}
void NodeVisitorCodeGen::visitVarInit(VarInit * varinit) {}
void NodeVisitorCodeGen::visitFieldDeclVar(FieldDeclVar * fieldvar) {}
void NodeVisitorCodeGen::visitFieldDecl(FieldDecl * fielddecl) {

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
	
}
void NodeVisitorCodeGen::visitClassBody(ClassBody * classbody) {
    if (classbody->decls != nullptr)
        classbody->decls->accept(*this);
    if (classbody->methods != nullptr)
        classbody->methods->accept(*this);
}
void NodeVisitorCodeGen::visitClassDecl(ClassDecl * classdecl) {

    std::shared_ptr<ClassStaticInfo> csi = std::make_shared<ClassStaticInfo>();

    std::string classId = classdecl->id->id;

    bool isClassMain = (classId == "Main");

    if (isClassMain and MJResources::getInstance()->mainClass != nullptr) {
        throw new std::logic_error("A program must have only one Main class"); 
    } else if (isClassMain) {
        MJResources::getInstance()->mainClass = csi;
    }

    Symbol symbol = Symbol::symbol(classId);

    auto decls = classdecl->body->decls;
    if (decls != nullptr) {
        while (!decls->fields->constructs.empty()) {
            std::shared_ptr<FieldDecl> fielddecl = 
                std::dynamic_pointer_cast<FieldDecl>(decls->fields->constructs.front()); 
            auto mvsi = this->generateDeclaredVars(fielddecl);
            csi->attributes.insert(mvsi.begin(), mvsi.end());    
        }
    }

    auto methods = classdecl->body->methods;
    if (methods != nullptr) {
        bool foundMethodMain = false;
        while (!methods->constructs.empty()) {
            std::shared_ptr<MethodDecl> methodDecl = 
                std::dynamic_pointer_cast<MethodDecl>(methods->constructs.front()); 
            auto msi = this->generateDeclaredMethod(methodDecl);
            csi->methods.insert(std::make_pair(Symbol::symbol(methodDecl->id->id), msi)); 
            if (methodDecl->id->id == "Main") 
                foundMethodMain = true;
        }
        if (isClassMain and not foundMethodMain) 
            throw std::logic_error("The Main class must have a main method");
    }

    MJResources::getInstance()->symbolTable.put(symbol, csi);
}
void NodeVisitorCodeGen::visitProgram(Program * program) {
    program->id->accept(*this);

    if (MJResources::getInstance()->mainClass == nullptr)
        throw std::logic_error("Missing the Main class");

    this->code += "#include <stdio.h>";
    this->code += "int main(void) {";
    program->classes->accept(*this);
    this->code += "return 0;}";
}
void NodeVisitorCodeGen::visitExprVarInit(ExprVarInit * varinit) {
    varinit->expr->accept(*this);
}
void NodeVisitorCodeGen::visitArrayInitVarInit(ArrayInitVarInit *) {}
void NodeVisitorCodeGen::visitArrayCreation(ArrayCreation *) {}
void NodeVisitorCodeGen::visitArrayCreationVarInit(ArrayCreationVarInit *) {}


std::map<Symbol, std::shared_ptr<VarStaticInfo>> NodeVisitorCodeGen::generateDeclaredVars(std::shared_ptr<FieldDecl> fielddecl) {
    std::map<Symbol, std::shared_ptr<VarStaticInfo>> declaredVars;
    std::shared_ptr<Type> type = fielddecl->type;
    std::shared_ptr<ConstructList> varDecls = fielddecl->varsDecls;
    while(!varDecls->constructs.empty()) {
        std::shared_ptr<FieldDeclVar> varDecl =
                std::dynamic_pointer_cast<FieldDeclVar>(varDecls->constructs.front());
        std::shared_ptr<VarDeclId> id = varDecl->varDeclId;
        Symbol symbol = Symbol::symbol(id->id->id); // \o/ =D
        std::shared_ptr<VarStaticInfo> vsi = std::make_shared<VarStaticInfo>();
        vsi->varType = std::make_pair(type->typeName, type->numBrackets);
        //MJResources::getInstance()->symbolTable.put(symbol, vsi);
        std::shared_ptr<VarInit> varInit = varDecl->varInit;
        if (varInit != nullptr) {
            //TODO: frame stack
        }
        declaredVars.insert(std::make_pair(symbol, vsi));
    }
    return declaredVars;
}

std::shared_ptr<MethodStaticInfo> NodeVisitorCodeGen::generateDeclaredMethod(std::shared_ptr<MethodDecl> metdecl) {
	std::string methodlabel = makeLabel(LabelType::METHOD);
    
    auto msi = std::make_shared<MethodStaticInfo>();

    std::shared_ptr<Type> retType = metdecl->returnType->type;
    msi->retType = std::make_pair(retType->typeName, retType->numBrackets);

    if (metdecl->params != nullptr) {
        while(!metdecl->params->constructs.empty()) {
            std::shared_ptr<FormalParams> fparams = 
                std::dynamic_pointer_cast<FormalParams>(metdecl->params->constructs.front()); 
            // get formal type
            std::shared_ptr<Type> ftype = fparams->type;
            StaticInfo::Type sfType = std::make_pair(ftype->typeName, ftype->numBrackets);
            // get val modifier
            bool fval = fparams->val;
            // get formal ids
            while (!fparams->ids->constructs.empty()) {
                std::string fid = std::dynamic_pointer_cast<Id>(fparams->ids->constructs.front())->id;
                MethodStaticInfo::FormalParam fp = std::make_tuple(fid, sfType, fval);
                fparams->ids->constructs.pop_front();
                msi->formalParams.push_back(fp);
            }
            metdecl->params->constructs.pop_front();
        }
    }
	
    auto decls = metdecl->block->decls;
    if (decls != nullptr) {
        while (!decls->fields->constructs.empty()) {
            std::shared_ptr<FieldDecl> fielddecl = 
                std::dynamic_pointer_cast<FieldDecl>(decls->fields->constructs.front()); 
            auto mvsi = this->generateDeclaredVars(fielddecl);
            msi->variables.insert(mvsi.begin(), mvsi.end());    
        }
    }

	makeLabelStmt(msi->codeLabel);
    metdecl->block->accept(*this); 

    return msi;
}

