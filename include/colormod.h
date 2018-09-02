#include <ostream>

/**
 * Tools for dealing with colors
 * when printing in the stdout.
 *
 * */
namespace Color {

    /**
     * Code colors, following
     * the terminal codes.
     *
     * */
    enum Code {
        FG_RED      = 31,
        FG_GREEN    = 32,
        FG_BLUE     = 34,
        FG_YELLOW   = 33,
        FG_DEFAULT  = 39,
        BG_RED      = 41,
        BG_GREEN    = 42,
        BG_BLUE     = 44,
        BG_DEFAULT  = 49
    };

    /**
     * Modifier to be used when printing
     * with cout.
     *
     * */
    class Modifier {

        private:
            Code code;

        public:

            Modifier(Code pCode) : code(pCode) {}

            friend std::ostream&
            operator<<(std::ostream& os, const Modifier& mod) {
                return os << "\033[" << mod.code << "m";
            }
    };
}
