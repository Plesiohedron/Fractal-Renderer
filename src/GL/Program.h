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

    private:
        GLuint LoadShader(const char* path, const GLenum shaderType) const;

    private:
        GLuint program;
        GLuint vertex_shader;
        GLuint fragment_shader;

        static const int INFO_LOG_LENGTH = 512;
    };
}
