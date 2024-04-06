#include "Engine.h"

Engine::Engine(const int window_width, const int window_height, const char* window_title) {
    window = Window::Instance(window_width, window_height, window_title);
    Events::Initialize(window);
    Fractal::Initialize(window);

    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glClearColor(1, 1, 1, 1);
    //glfwSwapInterval(0);
}

void Engine::MainLoop() const {
    unsigned int iteration = 0;
    
    double a = 0;
    double b = 0;

    float last_time = static_cast<float>(glfwGetTime());
    float delta_time = 0.0f;
    float current_time = 0.0f;

    bool scene_is_changed = true;


    while (!window->IsShouldClose()) {
        current_time = static_cast<float>(glfwGetTime());
        delta_time = current_time - last_time;
        last_time = current_time;

        if (!window->is_iconfied) {
            if (window->is_resized) {
                Fractal::window_size = {window->width, window->height};
                window->is_resized = false;
                scene_is_changed = true;
            }

            if (Events::wheel_is_scrolled) {
                Fractal::scale = {Events::scale_factor * window->height / window->width, Events::scale_factor};
                Events::wheel_is_scrolled = false;
                scene_is_changed = true;
            }

            if (Events::MouseIsPressed(GLFW_MOUSE_BUTTON_1)) {
                Fractal::offset.x -= Events::cursor_delta_x * delta_time * sensitivity / Events::scale_factor;
                Fractal::offset.y += Events::cursor_delta_y * delta_time * sensitivity / Events::scale_factor;
                scene_is_changed = true;
            }

            if (Events::KeyIsPressed(GLFW_KEY_Q)) {
                iteration -= 1000 * delta_time;

                a = static_cast<double>(iteration) / 100000;
                b = a / 100;

                Fractal::C.x -= b * std::sin(a);
                Fractal::C.y -= b* std::cos(a);
                scene_is_changed = true;
            }

            if (Events::KeyIsPressed(GLFW_KEY_E)) {
                iteration += 1000 * delta_time;

                a = static_cast<double>(iteration) / 100000;
                b = a / 100;

                Fractal::C.x += b * std::sin(a);
                Fractal::C.y += b * std::cos(a);
                scene_is_changed = true;
            }

            if (scene_is_changed) {
                glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
                Fractal::Draw();
                window->SwapBuffers();
                scene_is_changed = false;
            }
        }

        Events::PollEvents();
    }
}


