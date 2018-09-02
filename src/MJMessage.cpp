#include "MJMessage.h"

std::map<MJMessage::Type, Color::Code> MJMessage::type_to_color = 
    {
        {MJMessage::Type::SUCCESS, Color::FG_GREEN},
        {MJMessage::Type::ERROR, Color::FG_RED},
        {MJMessage::Type::NOTE, Color::FG_BLUE},
        {MJMessage::Type::WARNING, Color::FG_YELLOW},
    };

std::map<MJMessage::Type, std::string> MJMessage::type_to_string = 
    {
        {MJMessage::Type::SUCCESS, "success"},
        {MJMessage::Type::ERROR, "error"},
        {MJMessage::Type::NOTE, "note"},
        {MJMessage::Type::WARNING, "warning"},
    };
