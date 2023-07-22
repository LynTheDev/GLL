#include "GLL/shader.hh"

std::string GenericShader::read_path_to_string(std::string path)
{
    std::string content;
    std::ifstream file(path);

    std::ostringstream str;
    str << file.rdbuf();
    content = str.str();

    file.close();

    return content;
}

void GenericShader::check_shader_compiled(unsigned int shader)
{
    int success;
    char infoLog[512];

    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(shader, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::PROGRAM::COMPILATION_FAILED\n" << infoLog << std::endl;
    }
}

void GenericShader::check_program_linked(unsigned int program)
{
    int success;
    char infoLog[512];

    glGetProgramiv(program, GL_LINK_STATUS, &success);
    if (!success)
    {
        glGetProgramInfoLog(program, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
    }
}

void GenericShader::use_program()
{
    glUseProgram(this->program);
}

GenericShader::GenericShader(std::string shader_path, std::string fragment_path) : shader_path(shader_path), fragment_path(fragment_path) 
{
    std::string shader = this->read_path_to_string(shader_path);
    const char *shader_c = shader.c_str();

    unsigned int vertex_shader;
    vertex_shader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertex_shader, 1, &shader_c, nullptr);
    glCompileShader(vertex_shader);

    this->check_shader_compiled(vertex_shader);

    std::string fragment = this->read_path_to_string(fragment_path);
    const char *fragment_c = fragment.c_str();

    unsigned int fragment_shader;
    fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragment_shader, 1, &fragment_c, nullptr);
    glCompileShader(fragment_shader);

    this->check_shader_compiled(fragment_shader);

    unsigned int shader_program;
    shader_program = glCreateProgram();
    glAttachShader(shader_program, vertex_shader);
    glAttachShader(shader_program, fragment_shader);
    glLinkProgram(shader_program);

    this->check_program_linked(shader_program);

    this->program = shader_program;
};