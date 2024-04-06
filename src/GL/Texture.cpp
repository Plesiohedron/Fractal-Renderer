#include "Texture.h"
#include <iostream>

GL::Texture::Texture() {
    glGenTextures(1, &handle_);
}

GL::Texture::~Texture() {
    glDeleteTextures(1, &handle_);
}

void GL::Texture::Bind() const {
    glBindTexture(GL_TEXTURE_2D, handle_);
}

void GL::Texture::SetImage(const Image& image) {
    switch (image.GetFormat()) {
        case Image::RGB:
            GL_format = GL_RGB;
            break;

        case Image::RGBA:
            GL_format = GL_RGBA;
            break;
    }

    width = image.GetWidth();
    height = image.GetHeight();


    glBindTexture(GL_TEXTURE_2D, handle_);

    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_format, width, height, 0, GL_format, GL_UNSIGNED_BYTE, image.GetData().data());

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    glBindTexture(GL_TEXTURE_2D, 0);

    GLenum error = glGetError();
    if (error != GL_NO_ERROR) {
        std::cerr << "OpenGL error after glBindTexture: " << error << std::endl;
    }
}
