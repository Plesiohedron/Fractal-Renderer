#include "Parser.h"
#include <iostream>

namespace Parser {
    int argc = 0;
    const char** argv = nullptr;

    std::string fractal = "Julia";
    std::string shader = "Default";
    std::string texture = "Argon.jpg";

    bool flags[3]{};
};

void Parser::Parse() {

    if (argc % 2 == 0) {
        throw ParserError {"Wrong input!"};
    }

    for (int i = 1; i < argc; i += 2) {
        std::string flag{argv[i]};
        std::string value{argv[i + 1]};

        if (flag == "-fractal") {
            flags[0] = !flags[0];

            if (!flags[0]) {
                throw ParserError{"Double fractal input!"};
            }

            if (value == "Julia") {
                ;
            } else if (value == "Mondelbrot") {
                fractal = "Mondelbrot";
            } else {
                throw ParserError{"Wrong fractal input!"};
            }
        } else if (flag == "-shader") {
            flags[1] = !flags[1];

            if (!flags[1]) {
                throw ParserError{"Double shader input!"};
            }

            if (value == "Default") {
                ;
            } else if (value == "Animation") {
                shader = "Animation";
            } else if (value == "MousePos") {
                shader = "MousePos";
            } else {
                throw ParserError {"Wrong shader input!"};
            }
        } else if (flag == "-texture") {
            flags[2] = !flags[2];

            if (!flags[2]) {
                throw ParserError{"Double texture input!"};
            }

            if (value == "Argon.jpg") {
                ;
            } else if (value == "Inferno.png") {
                texture = "Inferno.png";
            } else if (value == "Wikipedia.png") {
                texture = "Wikipedia.png";
            } else {
                throw ParserError{"Wrong texture input!"};
            }
        } else {
            std::cout << flag << ' ' << (flag == "-fractal");

            throw ParserError{"Wrong flag input!"};
        }
    }

    if (fractal != "Julia" && shader != "Default") {
        throw ParserError{fractal + " fractal does not support " + shader + " shader!"};
    }

}
