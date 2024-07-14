#pragma once

#include <string>

#include "../Exceptions/Exceptions.h"

namespace Parser {
    extern int argc;
    extern const char** argv;

    extern std::string fractal;
    extern std::string shader;
    extern std::string texture;

    extern bool flags[3];

    void Parse();
};

