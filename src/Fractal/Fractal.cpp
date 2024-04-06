#include "Fractal.h"

namespace Fractal {
    std::unique_ptr<GL::Program> shader = nullptr;
    std::unique_ptr<GL::Texture> texture = nullptr;
    std::unique_ptr<GL::VAO> VAO = nullptr;
    

    std::vector<glm::vec3> vertices_pos{
        {-10.0f, -10.0f, 0.0f},
        {10.0f, -10.0f, 0.0f},
        {-10.0f, 10.0f, 0.0f},
        {10.0f, 10.0f, 0.0f}
    };

    std::vector<unsigned int> indexes{
        0, 1, 2, 2, 1, 3
    };


    GLint uniform_scale_loc = 0;
    GLint uniform_window_size_loc = 0;
    GLint uniform_offset_loc = 0;
    GLint uniform_mouse_pos_loc;
    GLint uniform_angle_loc = 0;
    GLint uniform_texture_loc = 0;

    glm::dvec2 scale{};
    glm::dvec2 window_size{};
    glm::dvec2 offset{0.0, 0.0};
    glm::dvec2 mouse_pos{0.0, 0.0};
    float angle = 0.0f;
};

void Fractal::Initialize(const Window* window) {
    shader = std::make_unique<GL::Program>("MainShader");
    texture = std::make_unique<GL::Texture>();
    texture->SetImage(Image::LoadImage("inferno.png"));
    VAO = std::make_unique<GL::VAO>();

    shader->BindAttribute(0, "position");
    shader->Link();

    uniform_scale_loc = shader->GetUniformLocation("scale");
    uniform_window_size_loc = shader->GetUniformLocation("window_size");
    uniform_offset_loc = shader->GetUniformLocation("offset");
    uniform_mouse_pos_loc = shader->GetUniformLocation("mouse_pos");
    uniform_angle_loc = shader->GetUniformLocation("angle");
    uniform_texture_loc = shader->GetUniformLocation("texture0");
    Fractal::shader->Use();

    VAO->Bind();
    VAO->InitializeVBO(vertices_pos);
    VAO->InitializeEBO(indexes);
    VAO->PostInitialization();

    glActiveTexture(GL_TEXTURE0);
    texture->Bind();
    shader->UniformTexture(uniform_texture_loc, 0);

    window_size = {window->width, window->height};
    shader->UniformVec2(uniform_window_size_loc, window_size);
    scale = {Events::scale_factor * window->height / window->width, Events::scale_factor};
}

void Fractal::Draw() {
    shader->UniformVec2(uniform_scale_loc, scale);
    shader->UniformVec2(uniform_offset_loc, offset);
    shader->UniformVec2(uniform_mouse_pos_loc, mouse_pos);
    shader->UniformFloat(uniform_angle_loc, angle);

    VAO->Draw(GL_TRIANGLES);
}