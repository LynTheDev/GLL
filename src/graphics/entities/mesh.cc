#include "GLL/mesh.hh"

Mesh::Mesh(GenericShader shader, float vertices[], unsigned long vertices_size, unsigned int indices[], unsigned long indices_size) : generic_shader(shader)
{
    unsigned int VBO;
    glGenBuffers(1, &VBO);

    unsigned int VAO;
    glGenVertexArrays(1, &VAO);

    if (indices != nullptr)
    {
        this->has_ebo = true;

        unsigned int EBO;
        glGenBuffers(1, &EBO);

        this->EBO = EBO;
    }

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, vertices_size, vertices, GL_STATIC_DRAW);

    if (indices != nullptr)
    {
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->EBO);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices_size, indices, GL_STATIC_DRAW);
    }

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 12, (void*)0);

    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);

    this->VAO = VAO;
}

void Mesh::draw_mesh(unsigned int indices_count, unsigned int start_index, GLenum mode)
{
    this->generic_shader.use_program();
    glBindVertexArray(this->VAO);

    if (this->has_ebo)
        glDrawElements(mode, 6, GL_UNSIGNED_INT, 0);
    else
        glDrawArrays(mode, start_index, indices_count);
}