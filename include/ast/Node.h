#ifndef __NODE__
#define __NODE__

#include "../Position.h"

class Node {

    public:

        Position pos;
        
        Node (Position _pos) : pos {_pos} {}

}; 

#endif
