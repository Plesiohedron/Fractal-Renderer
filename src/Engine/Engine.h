#pragma once

#include "../Events/Events.h"
#include "../Fractal/Fractal.h"

class Engine {
public:
    inline static Engine& Instance(const int window_width, const int window_height, const char* window_title) {
        static Engine instance{window_width, window_height, window_title};
        return instance;
    }

    void MainLoop() const;

public:
    Window* window;

private:
    Engine(const int window_width, const int window_height, const char* window_title);
    ~Engine() = default;

    Engine(const Engine&) = delete;
    Engine(Engine&&) = delete;
    Engine& operator=(const Engine&) = delete;
    Engine& operator=(Engine&&) = delete;
};

