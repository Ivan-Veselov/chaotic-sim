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

    void initVulkan();
    void termVulkan();

    void createVulkanInstance();
    void destroyVulkanInstance();

private:
    constexpr static uint32_t WINDOW_WIDTH = 800;
    constexpr static uint32_t WINDOW_HEIGHT = 600;

    GLFWwindow* window;
    VkInstance instance;
};
