#pragma once

#include <iostream>

#include "GLL/shader.hh"

class Mesh
{
private:
    bool has_ebo = false;
    unsigned int VAO;
    unsigned int EBO;
    GenericShader generic_shader;
public:
    Mesh(GenericShader shader, float vertices[], unsigned long vertices_size, unsigned int indices[] = nullptr, unsigned long indices_size = 0);

    void draw_mesh(unsigned int indices_count, unsigned int start_index = 0, GLenum mode = GL_TRIANGLES);
};