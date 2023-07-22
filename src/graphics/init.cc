#include "GLL/init.hh"

GLFWwindow* GLL::init_window(int height, int width, const char *title)
{
    GLL::display_platform();

    int init = glfwInit();
    if (init == GLFW_FALSE)
    {
        std::cout << "Failed to initialize GLFW" << std::endl;
        exit(1);
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    std::cout << "Using OpenGL version 3.3" << std::endl;

    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    std::cout << "Using OpenGL Profile Core" << std::endl;

    #ifdef __APPLE__
        glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    #endif

    GLFWwindow *window = glfwCreateWindow(width, height, title, NULL, NULL);
    if (window == nullptr)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        exit(1);
    }

    glfwMakeContextCurrent(window);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        glfwDestroyWindow(window);
        glfwTerminate();
        exit(1);
    }

    glViewport(0, 0, width, height);

    glfwSetFramebufferSizeCallback(window, Callbacks::framebuffer_size_callback);

    return window;
}