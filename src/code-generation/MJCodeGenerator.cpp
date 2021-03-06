#include "code-generation/NodeVisitorCodeGen.h"
#include "y.tab.h"
#include "ast/Node.h"
#include <iostream>

int generateCode(std::shared_ptr<Node> root) {
    if (root != nullptr) {
        std::cout << "Generating code..." << std::endl;
        NodeVisitorCodeGen codeGenVisitor;
        root->accept(codeGenVisitor); 
        std::cout << "Done." << std::endl;
    } else {
        std::cout << "Impossible to generate code.";
        return 1;
    }
    return 0;
}
