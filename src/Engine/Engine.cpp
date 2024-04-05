#include "Engine.h"

Engine::Engine(const int window_width, const int window_height, const char* window_title) {
    window = Window::Instance(window_width, window_height, window_title);
    Events::Initialize(window);
    Fractal::Initialize();

    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glClearColor(0, 0, 0, 1);
}

void Engine::MainLoop() const {
    Fractal::shader->Use();


    float lastTime = static_cast<float>(glfwGetTime());
    float deltaTime = 0.0f;
    float currentTime = 0.0f;

    float speed = 5.0f;

    while (!window->IsShouldClose()) {
        currentTime = static_cast<float>(glfwGetTime());
        deltaTime = currentTime - lastTime;
        lastTime = currentTime;

        if (!window->is_iconfied) {
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
            Fractal::Draw();
        }

        window->SwapBuffers();
        Events::PollEvents();
    }
}


