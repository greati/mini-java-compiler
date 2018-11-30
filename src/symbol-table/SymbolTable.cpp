#include "symbol-table/SymbolTable.h"
#include <cstddef>

std::unordered_multimap<std::string, Symbol> Symbol::dict;

std::shared_ptr<StaticInfo> Table::get(Symbol key) {
    auto value = this->table.find(key);
    if (value != this->table.end()){
        return value->second;
    }
    return nullptr; //return std::shared_ptr<StaticInfo> n;
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
