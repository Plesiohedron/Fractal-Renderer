#include "VAO.h"

GL::VAO::VAO() {
    glGenVertexArrays(1, &VAO_);
}

GL::VAO::~VAO() {
    glDeleteBuffers(VBOs_.size(), VBOs_.data());
    glDeleteBuffers(1, &EBO_);
    glDeleteVertexArrays(1, &VAO_);
}

void GL::VAO::Bind() {
    glBindVertexArray(VAO_);
}

void GL::VAO::Draw(unsigned int primitive_type) {
    assert(EBO_ != 0);

    glBindVertexArray(VAO_);

    for (int i = 0; i < VBOs_.size(); ++i) {
        glEnableVertexAttribArray(i);
    }

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO_);
    glDrawElements(primitive_type, indexes_count_, GL_UNSIGNED_INT, nullptr);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

    for (int i = 0; i < VBOs_.size(); ++i) {
        glDisableVertexAttribArray(i);
    }

    glBindVertexArray(0);
}

void GL::VAO::InitializeVBO(const std::vector<glm::vec3>& vertices_data) {
    GLuint VBO;

    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, vertices_data.size() * sizeof(glm::vec3), vertices_data.data(), GL_STATIC_DRAW);
    glVertexAttribPointer(VBOs_.size(), 3, GL_FLOAT, GL_FALSE, 0, nullptr);

    VBOs_.push_back(VBO);
}

void GL::VAO::InitializeEBO(const std::vector<unsigned int>& indexes_data) {
    assert(EBO_ == 0);

    glGenBuffers(1, &EBO_);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO_);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indexes_data.size() * sizeof(unsigned int), indexes_data.data(), GL_STATIC_DRAW);

    indexes_count_ = indexes_data.size();
}

void GL::VAO::PostInitialization() {
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
}