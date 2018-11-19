#ifndef __SYMBOLTABLE__
#define __SYMBOLTABLE__

#include <unordered_multimap>
#include "ast/Node.h"
#include <string>

/**
 * Represents the symbol table.
 *
 * */

class StaticInfo {
}

class Symbol {

    private:

        std::string name;
        Symbol (std::string n) {
            this.name = n
        }
        static std::unordered_multimap<std::string, Symbol> dict;

    public:

        std::string to_string() {
            return this.name;
        }
        static Symbol symbol(std::string n){
            Symbol s = dict.get(n)
            if (s = nullptr){
                s = new Symbol(u);
                dict.put(u,s);
            }
            return s;
        }

}

class Table {

    protected:

        std::unordered_multimap<Symbol, StaticInfo> table;
    
    public:

        Table();
        void put(Symbol key, StaticInfo value);
        Object get(Symbol key);
        void beginScope();
        void endScope();
        
}

#endif
