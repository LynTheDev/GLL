#include <iostream>

#include <boost/dll/runtime_symbol_info.hpp>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "GLL/init.hh"
#include "GLL/colour.hh"
#include "GLL/shader.hh"
#include "GLL/mesh.hh"

#define WIDTH 800
#define HEIGHT 600

int main()
{
    const char *title = "GLL";
    GLFWwindow *window = GLL::init_window(HEIGHT, WIDTH, title);

    std::string shader_path = (boost::dll::program_location().parent_path() / "glsl" / "triangle_shader.glsl").generic_string();
    
    std::string vertex_shader_path = (boost::dll::program_location().parent_path() / "glsl" / "fragments" / "white.frag").generic_string();
    GenericShader white_triangle = GenericShader(shader_path, vertex_shader_path);

    std::string vertex_red_shader_path = (boost::dll::program_location().parent_path() / "glsl" / "fragments" / "red.frag").generic_string();
    GenericShader red_triangle = GenericShader(shader_path, vertex_red_shader_path);

    GenericShader red_rect = GenericShader(shader_path, vertex_red_shader_path);

    // Rectangle Indecies
    float rect_vertices[] = {
        -0.9f, 0.9f, 0.0f, // Top Left
        -0.9f, 0.6f, 0.0f, // Bottom Left
        -0.6f, 0.6f, 0.0f, // Bottom Right
        -0.6f, 0.9f, 0.0f // Top Right
    };

    unsigned int rect_indices[] = {
        0, 1, 3, // First Triangle
        1, 2, 3  // Second Triangle
    };

    float white_vertices[] = {
        -0.5f, 0.5f, 0.0f, // Top Left
        -0.5f, -0.5f, 0.0f, // Bottom Left
        0.5f, -0.5f, 0.0f, // Bottom Right
    };

    float red_vertices[] = {
        0.5f, 0.5f, 0.0f, // Top Right
        0.5f, -0.5f, 0.0f, // Bottom Right
        -0.5f, 0.5f, 0.0f, // Top Left
    };

    Mesh white_triangle_mesh = Mesh(white_triangle, white_vertices, sizeof(white_vertices));
    Mesh red_triangle_mesh = Mesh(red_triangle, red_vertices, sizeof(red_vertices));

    Mesh red_rect_mesh = Mesh(red_rect, rect_vertices, sizeof(rect_vertices), rect_indices, sizeof(rect_indices));

    while (!glfwWindowShouldClose(window))
    {
        Callbacks::process_input(window);
        
        Colour orange = GLL::to_normalised_RGBA(227, 130, 27, 255);
        glClearColor(orange.r, orange.g, orange.b, orange.a);
        glClear(GL_COLOR_BUFFER_BIT);

        white_triangle_mesh.draw_mesh(3);
        red_triangle_mesh.draw_mesh(3);
        
        red_rect_mesh.draw_mesh(6);

        glfwPollEvents();
        glfwSwapBuffers(window);
    }
}