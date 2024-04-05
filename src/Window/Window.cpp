#include "Window.h"

Window::Window(const int window_width, const int window_height, const char* window_title)
    : width(window_width), height(window_height) {
    if (glfwInit() < 0) {
        throw GLFWError("Failed to initialize GLFW.");
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_RESIZABLE, GLFW_TRUE);

    window = glfwCreateWindow(width, height, window_title, nullptr, nullptr);
    if (!window) {
        throw GLFWError("Failed to create window.");
    }

    glfwMakeContextCurrent(window);

    glewExperimental = true;
    if (glewInit() != GLEW_OK) {
        throw GLFWError("Failed to initialize GLEW.");
    }

    glViewport(0, 0, width, height);
}

Window::~Window() {
    glfwDestroyWindow(window);
    glfwTerminate();
}

bool Window::IsShouldClose() const {
    return glfwWindowShouldClose(window);
}

void Window::SetShouldClose(bool flag) const {
    glfwSetWindowShouldClose(window, flag);
}

void Window::SwapBuffers() const {
    glfwSwapBuffers(window);
}
