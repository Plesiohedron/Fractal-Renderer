#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "../Exceptions/Exceptions.h"

class Window {
public:
    inline static Window* Instance(const int window_width, const int window_height, const char* window_title) {
        static Window* instance = new Window{window_width, window_height, window_title};
        return instance;
    }

    bool IsShouldClose() const;
    void SetShouldClose(bool flag) const;
    void SwapBuffers() const;

public:
    int width;
    int height;

    bool is_iconfied{false};
    bool is_resized{false};

    GLFWwindow* window;

private:
    Window(const int window_width, const int window_height, const char* window_title);
    ~Window();

    Window(const Window&) = delete;
    Window(Window&&) = delete;
    Window& operator=(const Window&) = delete;
    Window& operator=(Window&&) = delete;
};

