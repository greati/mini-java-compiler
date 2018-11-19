#ifndef __SYMBOLTABLE__
#define __SYMBOLTABLE__

#include <unordered_map>
#include <string>
#include <utility>
#include "resources/MJResources.h"

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

        Symbol (std::string n) {
            this->name = n;
        }

        std::string name;
        static std::unordered_multimap<std::string, Symbol> dict;

    public:


        std::string to_string() const {
            return this->name;
        }

        static Symbol symbol(const std::string& n) {
            auto s = dict.find(n);
            if (s == dict.end()) {
                Symbol aux {n};
                Symbol::dict.insert(std::make_pair(n,aux));
                return aux;
            }
            return s->second;
        }

        bool operator==(const Symbol& rhs) const {
            return (to_string() == rhs.to_string());
        }

        static Symbol getMarker() {
            return Symbol("#");            
        }        

};

struct SymbolHash {
    size_t operator()(const Symbol& key) const {
        return std::hash<std::string>()(key.to_string());
    }
};

class Table {

    protected:

        std::unordered_multimap<Symbol, std::shared_ptr<StaticInfo>, SymbolHash> table;
    
    public:

        Table(){}
        void put(Symbol key, std::shared_ptr<StaticInfo> value){
            table.insert(std::make_pair(key, value));
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
