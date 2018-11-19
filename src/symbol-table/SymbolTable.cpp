#include "symbol-table/SymbolTable.h"

std::unordered_multimap<std::string, Symbol> Symbol::dict;

StaticInfo Table::get(Symbol key) {
    auto value = this->table.find(key);
    if (value != this->table.end()){
        value->second;
    }
}

Symbol Symbol::symbol(const std::string& n) {
    auto s = dict.find(n);
    if (s == dict.end()) {
        Symbol aux {n};
        Symbol::dict.insert(std::make_pair(n,aux));
        return aux;
    }
    return s->second;
}
