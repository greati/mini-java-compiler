#ifndef __NODE__
#define __NODE__

#include "../Position.h"
#include <sstream>
#include <iostream>
#include <iomanip>

class Node {

    public:

        int level;

        Position pos;
        
        Node (Position _pos) : pos {_pos}, level {0} {}
    
        std::string print() const {
            std::stringstream ss;
            ss << "{\n";
            ss << "pos: [" << std::to_string(pos.row) << "," << std::to_string(pos.col) << "]\n";
            ss << this->show();
            ss << "}";
            return ss.str();
        };

        virtual std::string show() const = 0;

        virtual void computeLevel() = 0;

        friend std::ostream& operator<<(std::ostream& os, const Node& dt) {
            return os << dt.print();
        }

    protected:

        /**
         * From the Visitor pattern. Allows
         * operations to be performed over the tree
         * structure, without changing the node
         * classes.
         *
         * @param visitor The visitor
         * */
        virtual void accept(class NodeVisitor &) {};

}; 

#endif
