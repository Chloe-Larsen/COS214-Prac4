#ifndef COLOURHELPER_H
#define COLOURHELPER_H

namespace ColourHelper {
    // Reset / Styles
    const char* const RESET       = "\033[0m";
    const char* const BOLD        = "\033[1m";
    const char* const UNDERLINE   = "\033[4m";

    // Standard Colors
    const char* const RED         = "\033[31m";
    const char* const GREEN       = "\033[32m";
    const char* const YELLOW      = "\033[33m";
    const char* const BLUE        = "\033[34m";
    const char* const MAGENTA     = "\033[35m";
    const char* const CYAN        = "\033[36m";
    const char* const WHITE       = "\033[37m";

    // Bright / Bold Colors
    const char* const B_RED       = "\033[1;31m";
    const char* const B_GREEN     = "\033[1;32m";
    const char* const B_YELLOW    = "\033[1;33m";
    const char* const B_BLUE      = "\033[1;34m";
    const char* const B_MAGENTA   = "\033[1;35m";
    const char* const B_CYAN      = "\033[1;36m";
}

#endif // COLORS_H