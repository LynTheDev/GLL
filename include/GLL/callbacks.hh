#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace Callbacks {
    void framebuffer_size_callback(GLFWwindow *window, int width, int height);
    void process_input(GLFWwindow *window);
}