#include <iostream>

#include "Engine/Engine.h"

int main(const int argc, const char* argv[]) {

    try {
        Parser::argc = argc;
        Parser::argv = argv;

        Parser::Parse();

        Engine& engine = Engine::Instance(720, 480, "Fractal Renderer");
        engine.MainLoop();
    } catch (const GLFWError& e) {
        std::cerr << e.what() << std::endl;
    } catch (const OpenGLError& e) {
        std::cerr << e.what() << std::endl;
    } catch (const STBImageError& e) {
        std::cerr << e.what() << std::endl;
    } catch (const ParserError& e) {
        std::cerr << e.what() << std::endl;
    }

}