#include "Program.h"


GL::Program::Program(const std::string& name) {
    program = glCreateProgram();

    vertex_shader = LoadShader(("res/glsl/" + name + ".vert").c_str(), GL_VERTEX_SHADER);
    fragment_shader = LoadShader(("res/glsl/" + name + ".frag").c_str(), GL_FRAGMENT_SHADER);
}

GL::Program::~Program() {
    glDetachShader(program, vertex_shader);
    glDetachShader(program, fragment_shader);

    glDeleteShader(vertex_shader);
    glDeleteShader(fragment_shader);

    glDeleteProgram(program);
}

void GL::Program::Link() const {
    glAttachShader(program, vertex_shader);
    glAttachShader(program, fragment_shader);
    glLinkProgram(program);

    GLint status;
    glGetProgramiv(program, GL_LINK_STATUS, &status);
    if (!status) {
        char buf[INFO_LOG_LENGTH];
        glGetShaderInfoLog(program, INFO_LOG_LENGTH, nullptr, buf);
        std::cerr << buf << '\n';

        throw OpenGLError("Failed to link shader!");
    }
}

void GL::Program::Use() const {
    glUseProgram(program);
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