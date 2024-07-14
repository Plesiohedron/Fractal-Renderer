#pragma once

#include <cmath>

#include "../Window/Window.h"

namespace Events {
    void Initialize(Window* window);
    void PollEvents();

    bool KeyIsClicked(int key);
    bool KeyIsPressed(int key);
    bool MouseIsPressed(int button);

    void WindowResizeCallback(GLFWwindow* window, int width, int height);
    void KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
    void MouseCallback(GLFWwindow* window, int button, int action, int mods);
    void CursorPosCallback(GLFWwindow* window, double xpos, double ypos);
    void WindowIconifyCallback(GLFWwindow* window, int iconified);
    void ScrollCallback(GLFWwindow* window, double xoffset, double yoffset);


    extern const int MOUSE_BUTTONS_OFFSET;
    extern bool keys[1032];

    extern unsigned long long int current_frame;
    extern unsigned long long int frames[1032];

    extern float scale_factor;
    extern float cursor_x;
    extern float cursor_y;
    extern float cursor_delta_x;
    extern float cursor_delta_y;
    extern bool cursor_is_moving;
    extern bool wheel_is_scrolled;

    extern Window* window;
};

