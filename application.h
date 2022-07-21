#pragma once


#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>


class Application {
public:
    Application();
     ~Application();

     void run();

private:
    void initGLFW();
    void termGLFW();

    void initWindow();
    void termWindow();

private:
    constexpr static uint32_t WINDOW_WIDTH = 800;
    constexpr static uint32_t WINDOW_HEIGHT = 600;

    GLFWwindow* window;
};
