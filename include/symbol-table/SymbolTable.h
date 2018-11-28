#ifndef __SYMBOLTABLE__
#define __SYMBOLTABLE__

#include <unordered_map>
#include <string>
#include <utility>
#include <memory>
#include <vector>
#include <map>


/**
 * Represents the symbol table.
 *
 * */
class StaticInfo {

   public: 

        typedef std::pair<std::string, int> Type;
};

class VarStaticInfo : public StaticInfo {
    
    public:

        Type varType;
        
};




class Symbol {

    private:

        inline Symbol (std::string n) {
            this->name = n;
        }

        std::string name;
        static std::unordered_multimap<std::string, Symbol> dict;

    public:

        inline std::string to_string() const {
            return this->name;
        }

        static Symbol symbol(const std::string& n);

        inline bool operator==(const Symbol& rhs) const {
            return (to_string() == rhs.to_string());
        }

        inline bool operator!=(const Symbol& rhs) const {
            return (to_string() != rhs.to_string());
        }

        inline bool operator<(const Symbol& rhs) const {
            return (to_string() < rhs.to_string());
        }

        inline static Symbol getMarker() {
            return Symbol("#");            
        }        

};

class MethodStaticInfo : public StaticInfo {
    
    public:
       
       std::map<Symbol, std::shared_ptr<VarStaticInfo>> variables;

        // bool: True if Val
        typedef std::tuple<std::string, Type, bool> FormalParam;
        
        Type retType;
        std::vector<FormalParam> formalParams;
        std::string codeLabel;
};

class ClassStaticInfo : public StaticInfo {
    public:
       std::map<Symbol, std::shared_ptr<MethodStaticInfo>> methods;
       std::map<Symbol, std::shared_ptr<VarStaticInfo>> attributes;
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

        inline Table(){}

        inline void put(Symbol key, std::shared_ptr<StaticInfo> value) {
            table.insert(std::make_pair(key, value));
        }

        inline void remove(Symbol key) {
            auto iterpair = table.equal_range(key);
            if (iterpair.first != iterpair.second)
                table.erase(iterpair.first);
        }

	std::shared_ptr<StaticInfo> get(Symbol key);
};

#endif
