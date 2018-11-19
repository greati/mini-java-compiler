#ifndef __SYMBOLTABLE__
#define __SYMBOLTABLE__

#include <unordered_map>
#include "ast/Node.h"
#include <string>
#include <utility>

/**
 * Represents the symbol table.
 *
 * */

class StaticInfo {

   public: 
        typedef std::pair<std::string, int> Type;
};

class MethodStaticInfo : public StaticInfo {
    
    public:
       
        // bool: True if Val
        typedef std::tuple<std::string, Type, bool> FormalParam;
        
        Type retType;
        std::vector<FormalParam> formalParams;
        std::string codeLabel;
};

class VarStaticInfo : public StaticInfo {
    
    public:

        Type varType;
        
};

class Symbol {

    private:

        std::string name;
        static std::unordered_multimap<std::string, Symbol> dict;

    public:

        Symbol (std::string n) {
            this->name = n;
        }

        std::string to_string() {
            return this->name;
        }
        static Symbol symbol(std::string n) {
            auto s = dict.find(n);
            if (s == dict.end()) {
                Symbol aux {n};
                Symbol::dict.insert(std::make_pair<std::string, Symbol>(n,aux));
                return aux;
            }
            return s->second;
        }

};

class Table {

    protected:

        std::unordered_multimap<Symbol, std::shared_ptr<StaticInfo>> table;
    
    public:

        Table(){}
        void put(Symbol key, std::shared_ptr<StaticInfo> value){
            table.insert(std::make_pair<Symbol, std::shared_ptr<StaticInfo>>(key, value));
        }
        StaticInfo get(Symbol key){
            auto value = table.find(key);
            if (value != table.end()){
                value->second;
            }
        }
        void beginScope(){
            
        }
        void endScope(){
            
        }
        
};

#endif
