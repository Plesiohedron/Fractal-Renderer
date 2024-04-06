#pragma once

#define GLEW_STATIC
#include <GL/glew.h>
#include <GL/GL.h>

#include "../Image/Image.h"

namespace GL {
    class Texture {
    private:
        GLuint handle_;

    public:
        GLenum GL_format;
        unsigned int width;
        unsigned int height;

        Texture();
        Texture(const Texture&) = delete;
        ~Texture();

        void Bind() const;
        void SetImage(const Image& image);
    };
}