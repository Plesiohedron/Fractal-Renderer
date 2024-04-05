#include "Engine.h"

Engine::Engine(const int window_width, const int window_height, const char* window_title) {
    window = Window::Instance(window_width, window_height, window_title);
    Events::Initialize(window);
    Fractal::Initialize();
    Fractal::UpdateModel(window_width, window_height);

    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glClearColor(0, 0, 0, 1);
}

void Engine::MainLoop() const {
    Fractal::shader->Use();

    float last_cursor_pos_x = 0.0f;
    float last_cursor_pos_y = 0.0f;
    bool RMB_is_pressed = false;


    float lastTime = static_cast<float>(glfwGetTime());
    float deltaTime = 0.0f;
    float currentTime = 0.0f;


    while (!window->IsShouldClose()) {
        currentTime = static_cast<float>(glfwGetTime());
        deltaTime = currentTime - lastTime;
        lastTime = currentTime;

        if (!window->is_iconfied) {
            if (window->is_resized) {
                Fractal::UpdateModel(window->width, window->height);
                window->is_resized = false;
            }

            if (Events::MouseIsPressed(GLFW_MOUSE_BUTTON_1)) {
                if (!RMB_is_pressed) {
                    RMB_is_pressed = true;
                    last_cursor_pos_x = Events::cursor_x;
                    last_cursor_pos_y = Events::cursor_y;
                } else {
                    float cursor_delta_x = Events::cursor_x - last_cursor_pos_x;
                    float cursor_delta_y = Events::cursor_y - last_cursor_pos_y;

                    Fractal::model = glm::translate(Fractal::model, glm::vec3(cursor_delta_x * sensitivity, -cursor_delta_y * sensitivity, 0.0f));

                    last_cursor_pos_x = Events::cursor_x;
                    last_cursor_pos_y = Events::cursor_y;
                }
            } else {
                RMB_is_pressed = false;
            }

            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
            Fractal::Draw();
        }

        window->SwapBuffers();
        Events::PollEvents();
    }
}


