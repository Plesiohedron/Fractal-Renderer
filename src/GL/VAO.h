#pragma once

#include <vector>

#define GLEW_STATIC
#include <GL/glew.h>
#include <GL/GL.h>
#include <glm/glm.hpp>

namespace GL {
    class VAO {
    private:
        GLuint VAO_ = 0;
        std::vector<GLuint> VBOs_;
        GLuint EBO_ = 0;

        size_t indexes_count_ = 0;

    public:
        VAO();
        VAO(const VAO&) = delete;
        ~VAO();

        void Bind() const;
        void Draw(const unsigned int primitive_type) const;

        void InitializeVBO(const std::vector<glm::vec3>& vertices_data);
        void InitializeEBO(const std::vector<unsigned int>& indexes_data);
        void PostInitialization();
    };
}