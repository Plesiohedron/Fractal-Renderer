#include <iostream>

#include "Engine/Engine.h"

int main() {

    try {
        Engine& engine = Engine::Instance(720, 480, "Fractal Renderer");
        engine.MainLoop();
    } catch (const GLFWError& e) {
        std::cerr << e.what() << std::endl;
    }

}