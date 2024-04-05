#pragma once

#include <iostream>
#include <fstream>

#include <GL/glew.h>
#include <GL/GL.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "../Exceptions/Exceptions.h"

namespace GL {
    class Program {
    public:
        Program(const std::string& name);
        ~Program();

        void Link() const;
        void Use() const;

        void BindAttribute(GLuint index, const char* name);
        GLint GetUniformLocation(const char* name);
        void UniformMatrix(GLint uniform, glm::mat4 matrix);

    private:
        GLuint LoadShader(const char* path, const GLenum shaderType) const;

    private:
        GLuint program_;
        GLuint vertex_shader_;
        GLuint fragment_shader_;

        static const int INFO_LOG_LENGTH = 512;
    };
}
