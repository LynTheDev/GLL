#pragma once

#include <iostream>
#include <sstream>
#include <fstream>
#include <string>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

class GenericShader
{
private:
    // These are the paths
    std::string shader_path;
    std::string fragment_path;

    // This will be used to get the shader/fragment file contents
    std::string read_path_to_string(std::string path);

    // Error handlers
    void check_shader_compiled(unsigned int shader);
    void check_program_linked(unsigned int program);

    // Program
    unsigned int program;

public:
    // No idea anymore
    GenericShader(std::string shader_path, std::string fragment_path);

    // Program Functions
    void use_program();
};