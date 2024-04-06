#include "Engine.h"

Engine::Engine(const int window_width, const int window_height, const char* window_title) {
    window = Window::Instance(window_width, window_height, window_title);
    Events::Initialize(window);
    Fractal::Initialize(window);

    EngineFunction = std::bind(&Engine::MousePos, this, std::placeholders::_1, std::placeholders::_2);

    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glClearColor(1, 1, 1, 1);
    //glfwSwapInterval(0);
}

void Engine::Animation(bool& scene_is_updated, float delta_time) {
    Fractal::angle += delta_time * angle_sensitivity;

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    Fractal::Draw();
    window->SwapBuffers();
}

void Engine::MousePos(bool& scene_is_updated, float delta_time) {
    if (Events::MouseIsPressed(GLFW_MOUSE_BUTTON_1)) {
        Fractal::mouse_pos = {Events::cursor_x, -Events::cursor_y};
        scene_is_updated = true;
    }

    if (scene_is_updated) {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        Fractal::Draw();
        window->SwapBuffers();

        scene_is_updated = false;
    }
}

void Engine::Default(bool& scene_is_updated, float delta_time) {
    if (Events::MouseIsPressed(GLFW_MOUSE_BUTTON_1)) {
        Fractal::offset.x -= Events::cursor_delta_x * delta_time * moving_sensitivity / Events::scale_factor;
        Fractal::offset.y += Events::cursor_delta_y * delta_time * moving_sensitivity / Events::scale_factor;
        scene_is_updated = true;
    }

    if (Events::KeyIsPressed(GLFW_KEY_Q)) {
        Fractal::angle -= delta_time * angle_sensitivity;;
        scene_is_updated = true;
    }

    if (Events::KeyIsPressed(GLFW_KEY_E)) {
        Fractal::angle += delta_time * angle_sensitivity;;
        scene_is_updated = true;
    }

    if (scene_is_updated) {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        Fractal::Draw();
        window->SwapBuffers();

        scene_is_updated = false;
    }
}

void Engine::MainLoop() const {
    float last_time = static_cast<float>(glfwGetTime());
    float delta_time = 0.0f;
    float current_time = 0.0f;

    bool scene_is_updated = true;


    while (!window->IsShouldClose()) {
        current_time = static_cast<float>(glfwGetTime());
        delta_time = current_time - last_time;
        last_time = current_time;

        if (!window->is_iconfied) {
            if (window->is_resized) {
                Fractal::window_size = {window->width, window->height};
                window->is_resized = false;
                scene_is_updated = true;
            }

            if (Events::wheel_is_scrolled) {
                Fractal::scale = {Events::scale_factor * window->height / window->width, Events::scale_factor};
                Events::wheel_is_scrolled = false;
                scene_is_updated = true;
            }

            EngineFunction(scene_is_updated, delta_time);
        }

        Events::PollEvents();
    }
}


