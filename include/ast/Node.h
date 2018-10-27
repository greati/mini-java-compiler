#ifndef __NODE__
#define __NODE__

#include "../Position.h"
#include <iostream>

class Node {

    public:

        Position pos;
        
        Node (Position _pos) : pos {_pos} {}
    
        std::string print() const {
            std::string s = "{\n";
            s += "pos: [" + std::to_string(pos.row) + "," + std::to_string(pos.col) + "]\n";
            s += this->show();
            s += "}\n";
            return s;
        };

        virtual std::string show() const = 0;

        friend std::ostream& operator<<(std::ostream& os, const Node& dt) {
            return os << dt.print();
        }

}; 

#endif
