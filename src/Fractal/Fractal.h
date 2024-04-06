#pragma once

#include "../GL/Program.h"
#include "../GL/VAO.h"
#include "../GL/Texture.h"
#include "../Events/Events.h"

namespace Fractal {
    void Initialize(const Window* window);
    void Draw();

    extern std::unique_ptr<GL::Program> shader;
    extern std::unique_ptr<GL::Texture> texture;
    extern std::unique_ptr<GL::VAO> VAO;

    extern std::vector<glm::vec3> vertices_pos;
    extern std::vector<unsigned int> indexes;

    extern GLint uniform_scale_loc;
    extern GLint uniform_window_size_loc;
    extern GLint uniform_offset_loc;
    extern GLint uniform_mouse_pos_loc;
    extern GLint uniform_angle_loc;
    extern GLint uniform_texture_loc;

    extern glm::dvec2 scale;
    extern glm::dvec2 window_size;
    extern glm::dvec2 offset;
    extern glm::dvec2 mouse_pos;
    extern float angle;
};

