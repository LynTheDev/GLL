#pragma once

#include <iostream>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "GLL/callbacks.hh"
#include "GLL/platform.hh"

namespace GLL {
    GLFWwindow* init_window(int height, int width, const char *title);
}
