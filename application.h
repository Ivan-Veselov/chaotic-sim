#pragma once


#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include <array>


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

    constexpr static std::array<const char*, 1> validationLayers = {
        "VK_LAYER_KHRONOS_validation"
    };

#ifdef _DEBUG
    constexpr static bool enableValidationLayers = true;
#else
    constexpr static bool enableValidationLayers = false;
#endif

    GLFWwindow* window;
    VkInstance instance;
};
