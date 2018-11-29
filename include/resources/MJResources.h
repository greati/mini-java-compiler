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

        std::shared_ptr<Frame> newFrame() {
            std::shared_ptr<Frame> frame = std::make_shared<Frame>();
            frameStack->next = frame;
            frame->prev = frameStack;
            frameStack = frame;
            return frame;
        }


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
