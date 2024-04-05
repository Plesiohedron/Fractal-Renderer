#include <iostream>

#include "Engine/Engine.h"

int main() {

    try {
        Engine& engine = Engine::Instance(1280, 720, "GLFW Works!");
        engine.MainLoop();
    } catch (const GLFWError& e) {
        std::cerr << e.what() << std::endl;
    }

}