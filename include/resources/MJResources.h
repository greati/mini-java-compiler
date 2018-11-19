#ifndef __MJRESOURCES__
#define __MJRESOURCES__

#include "symbol-table/SymbolTable.h"
#include <memory>
#include <queue>

class Table;
class Symbol;

class MJResources {

    public:
              
        static std::shared_ptr<MJResources> getInstance() {
            static std::shared_ptr<MJResources> d(new MJResources);
            return d;
        }

        Table symbolTable; 
        std::queue<Symbol> scopeQueue;

    private:

        MJResources() {}


};

#endif
