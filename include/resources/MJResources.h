#ifndef __MJRESOURCES__
#define __MJRESOURCES__

#include "symbol-table/SymbolTable.h"
#include <memory>
#include <stack>

class MJResources {

    public:
              
        static std::shared_ptr<MJResources> getInstance() {
            static std::shared_ptr<MJResources> d(new MJResources);
            return d;
        }

        Table symbolTable; 
        std::stack<Symbol> scopeStack;

        void beginScope() {
            this->scopeStack.push(Symbol::getMarker());
        }

        void endScope() {
            Symbol s = this->scopeStack.top();
            while (s != Symbol::getMarker()) {
                this->symbolTable.remove(s);  
                this->scopeStack.pop();
                s = this->scopeStack.top();
            } 
            // pop the end marker
            this->scopeStack.pop();
        }

    private:

        MJResources() {}


};

#endif
