#ifndef __FRAME__
#define __FRAME__

#include <string>
#include <memory>
#include <map>
#include "frames/Param.h"

class Frame {

    public:
        std::string label;
        std::map<std::string, Param> formals;
        std::map<std::string, Param> locals;
        std::shared_ptr<Frame> classFrame;
        std::shared_ptr<Frame> next;
        std::shared_ptr<Frame> prev;
};

#endif
