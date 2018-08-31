#ifndef __MJMESSAGE__
#define __MJMESSAGE__

#include "colormod.h"
#include <map>

/**
 * A message to be printed to the
 * user.
 *
 * @author Vitor Greati
 * */
class MJMessage {

    public:

        /**
         * Type of the message.
         *
         * */
        enum class Type {
            SUCCESS,
            ERROR,
            NOTE,
            WARNING,
        };

        static void print(Type type, std::string text) {
            std::cout << Color::Modifier {type_to_color[type]} << text << std::endl;
        }

    private:

        /**
         * Map type of messages to color codes.
         *
         * */
        static std::map<Type, Color::Code> type_to_color;
};

std::map<MJMessage::Type, Color::Code> MJMessage::type_to_color = 
    {
        {MJMessage::Type::SUCCESS, Color::FG_GREEN},
        {MJMessage::Type::ERROR, Color::FG_RED},
        {MJMessage::Type::NOTE, Color::FG_BLUE},
        {MJMessage::Type::WARNING, Color::FG_YELLOW},
    };

#endif
