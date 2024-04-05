#include "Program.h"


GL::Program::Program(const std::string& name) {
    program_ = glCreateProgram();

    vertex_shader_ = LoadShader(("res/glsl/" + name + ".vert").c_str(), GL_VERTEX_SHADER);
    fragment_shader_ = LoadShader(("res/glsl/" + name + ".frag").c_str(), GL_FRAGMENT_SHADER);
}

GL::Program::~Program() {
    glDetachShader(program_, vertex_shader_);
    glDetachShader(program_, fragment_shader_);

    glDeleteShader(vertex_shader_);
    glDeleteShader(fragment_shader_);

    glDeleteProgram(program_);
}

void GL::Program::Link() const {
    glAttachShader(program_, vertex_shader_);
    glAttachShader(program_, fragment_shader_);
    glLinkProgram(program_);

    GLint status;
    glGetProgramiv(program_, GL_LINK_STATUS, &status);
    if (!status) {
        char buf[INFO_LOG_LENGTH];
        glGetShaderInfoLog(program_, INFO_LOG_LENGTH, nullptr, buf);
        std::cerr << buf << '\n';

        throw OpenGLError("Failed to link shader!");
    }
}

void GL::Program::Use() const {
    glUseProgram(program_);
}

void GL::Program::BindAttribute(GLuint index, const char* name) {
    glBindAttribLocation(program_, index, name);
}

GLint GL::Program::GetUniformLocation(const char* name) {
    return glGetUniformLocation(program_, name);
}

void GL::Program::UniformMatrix(GLint location, glm::mat4 matrix) {
    glUniformMatrix4fv(location, 1, GL_FALSE, glm::value_ptr(matrix));
}

GLuint GL::Program::LoadShader(const char* path, const GLenum shaderType) const {
    GLuint shader = glCreateShader(shaderType);

    std::ifstream fin(path);
    std::string shaderCode = {std::istreambuf_iterator<char>(fin), std::istreambuf_iterator<char>()};

    const char* code = shaderCode.c_str();
    glShaderSource(shader, 1, &code, nullptr);
    glCompileShader(shader);

    GLint status;
    glGetShaderiv(shader, GL_COMPILE_STATUS, &status);
    if (!status) {
        char buf[INFO_LOG_LENGTH];
        glGetShaderInfoLog(shader, INFO_LOG_LENGTH, nullptr, buf);
        std::cerr << path << ": " << buf << '\n';

        throw OpenGLError("Failed to compile shader!");
    }

    return shader;
}