#ifndef __MJRESOURCES__
#define __MJRESOURCES__

#include "symbol-table/SymbolTable.h"
#include <memory>
#include <queue>

class MJResources {

    public:
              
        static std::shared_ptr<MJResources> getInstance() {
            static std::shared_ptr<MJResources> d(new MJResources);
            return d;
        }

        Table symbolTable; 
        std::queue<Symbol> scopeQueue;

        void beginScope() {
            this->scopeQueue.push(Symbol::getMarker());
        }

        void endScope() {
            while (auto s = this->scopeQueue.front() != Symbol::getMarker()) {
                 
                this->scopeQueue.pop();
            } 
            // pop the end marker
            this->scopeQueue.pop();
        }

    private:

        MJResources() {}


};

#endif
