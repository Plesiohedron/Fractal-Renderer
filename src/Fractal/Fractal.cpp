#include "Fractal.h"

namespace Fractal {
    std::unique_ptr<GL::Program> shader = nullptr;
    std::unique_ptr<GL::VAO> VAO = nullptr;
    glm::mat4 model(1.0f);

    std::vector<glm::vec3> vertices_pos{
        {-10.0f, -10.0f, 0.0f},
        {10.0f, -10.0f, 0.0f},
        {-10.0f, 10.0f, 0.0f},
        {10.0f, 10.0f, 0.0f}
    };

    std::vector<unsigned int> indexes{
        0, 1, 2, 2, 1, 3
    };

    GLint uniform_model_loc = 0;
};

void Fractal::Initialize() {
    shader = std::make_unique<GL::Program>("Shader");
    VAO = std::make_unique<GL::VAO>();

    shader->BindAttribute(0, "position");
    shader->Link();
    uniform_model_loc = shader->GetUniformLocation("model");

    VAO->Bind();
    VAO->InitializeVBO(vertices_pos);
    VAO->InitializeEBO(indexes);
    VAO->PostInitialization();
}

void Fractal::Draw() {
    shader->UniformMatrix(uniform_model_loc, model);

    VAO->Draw(GL_TRIANGLES);
}