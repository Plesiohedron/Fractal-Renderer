#pragma once

#include "../GL/Program.h"
#include "../GL/VAO.h"

namespace Fractal {
    void Initialize();
    void UpdateModel(const int window_width, const int window_height);
    void Draw();

    extern std::unique_ptr<GL::Program> shader;
    extern std::unique_ptr<GL::VAO> VAO;
    extern glm::mat4 model;

    extern std::vector<glm::vec3> vertices_pos;
    extern std::vector<unsigned int> indexes;

    extern GLint uniform_model_loc;
};

