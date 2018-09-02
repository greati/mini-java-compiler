#ifndef __MJMESSAGE__
#define __MJMESSAGE__

#include "colormod.h"
#include <map>
#include <iostream>
#include <iomanip>
#include "Lexer.h"

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

        /**
         * Print a message according to its type.
         *
         * */
        static void print(Type type, std::string text, Lexer::Position pos = Lexer::Position {-1, -1}) {
            std::string position_string = "";
            if (pos.row != -1 && pos.col != -1)
                position_string = "(" + std::to_string(pos.row) + "," + std::to_string(pos.col) + ") ";
            std::cout << "[" << Color::Modifier {Color::BG_DEFAULT} << "mjc" << Color::Modifier {Color::BG_DEFAULT} 
                << Color::Modifier {type_to_color[type]} << " " <<
                std::setw(7) << type_to_string[type] << Color::Modifier {Color::FG_DEFAULT} << "] " 
                << position_string
                << text << std::endl;
        }

    private:

        /**
         * Map type of messages to color codes.
         *
         * */
        static std::map<Type, Color::Code> type_to_color;

        /**
         * Map type to string representation.
         *
         * */
        static std::map<Type, std::string> type_to_string;
};

#endif
