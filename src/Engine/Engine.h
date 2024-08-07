#pragma once

#include <functional>

#include "../Events/Events.h"
#include "../Fractal/Fractal.h"
#include "../Parser/Parser.h"

class Engine {
public:
    inline static Engine& Instance(const int window_width, const int window_height, const char* window_title) {
        static Engine instance{window_width, window_height, window_title};
        return instance;
    }

    void MainLoop() const;

public:
    Window* window;
    const float angle_sensitivity = 0.25f;
    const float moving_sensitivity = 50.0f;

private:
    Engine(const int window_width, const int window_height, const char* window_title);
    ~Engine() = default;

    Engine(const Engine&) = delete;
    Engine(Engine&&) = delete;
    Engine& operator=(const Engine&) = delete;
    Engine& operator=(Engine&&) = delete;

    void Animation(bool& scene_is_updated, float delta_time);
    void MousePos(bool& scene_is_updated, float delta_time);
    void Default(bool& scene_is_updated, float delta_time);

    std::function<void(bool& scene_is_updated, float delta_time)> EngineFunction;
};

