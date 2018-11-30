#ifndef __MJRESOURCES__
#define __MJRESOURCES__

#include "symbol-table/SymbolTable.h"
#include "frames/Frame.h"
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
        std::shared_ptr<Frame> frameStack; // nullptr by default
        std::shared_ptr<ClassStaticInfo> mainClass; // nullptr by default
        std::shared_ptr<MethodStaticInfo> mainMethod; // nullptr by default
        Table staticInfoTable;

        std::shared_ptr<Frame> newFrame() {
            std::shared_ptr<Frame> frame = std::make_shared<Frame>();
            frameStack->next = frame;
            frame->prev = frameStack;
            frameStack = frame;
            return frame;
        }

        enum class ScopeType {
            CLASS, METHOD
        };

        Symbol fromScopeType(ScopeType scopeType) {
            switch (scopeType) {
                case ScopeType::CLASS:
                    return Symbol::symbol("$$");
                case ScopeType::METHOD:
                    return Symbol::symbol("$");
                default:
                    return Symbol::getMarker();
            }
        }

        void beginScope(ScopeType scopeType) {
            this->scopeStack.push(fromScopeType(scopeType));
        }

        void endScope(ScopeType scopeType) {
            Symbol scopeSymbol = fromScopeType(scopeType);
            Symbol s = this->scopeStack.top();
            while (s != scopeSymbol) {
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
