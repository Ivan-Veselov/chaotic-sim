#include "application.h"

#include <stdexcept>
#include <string>


#define CHECK_VULKAN_CALL(call) \
{\
    VkResult result = call;\
    if (result != VK_SUCCESS) {\
        std::string exceptionDescription;\
        exceptionDescription += "Vulkan API call failed!\n";\
        exceptionDescription += __FILE__":" + std::to_string(__LINE__) + "\n";\
        exceptionDescription += #call"\n";\
        exceptionDescription += "Error code: " + std::to_string(result);\
        throw std::runtime_error(exceptionDescription);\
    }\
}\
void(0)


Application::Application() {
    initGLFW();
    initWindow();
    initVulkan();
}

Application::~Application() {
    termVulkan();
    termWindow();
    termGLFW();
}

void Application::run() {
    while (!glfwWindowShouldClose(window)) {
        glfwPollEvents();
    }
}

void Application::initGLFW() {
    glfwInit();
    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
}

void Application::termGLFW() {
    glfwTerminate();
}

void Application::initWindow() {
    window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Chaotic Simulation", nullptr, nullptr);
}

void Application::termWindow() {
    glfwDestroyWindow(window);
}

void Application::initVulkan() {
    createVulkanInstance();
}

void Application::termVulkan() {
    destroyVulkanInstance();
}

void Application::createVulkanInstance() {
    VkApplicationInfo applicationInfo{};
    applicationInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
    applicationInfo.pApplicationName = "chaotic-sim";
    applicationInfo.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
    applicationInfo.pEngineName = "No Engine";
    applicationInfo.engineVersion = VK_MAKE_VERSION(1, 0, 0);
    applicationInfo.apiVersion = VK_API_VERSION_1_3;

    VkInstanceCreateInfo createInfo{};
    createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
    createInfo.pApplicationInfo = &applicationInfo;

    uint32_t glfwExtensionCount = 0;
    const char** glfwExtensions = glfwGetRequiredInstanceExtensions(&glfwExtensionCount);

    createInfo.enabledExtensionCount = glfwExtensionCount;
    createInfo.ppEnabledExtensionNames = glfwExtensions;

    createInfo.enabledLayerCount = 0;
    createInfo.ppEnabledLayerNames = nullptr;

    CHECK_VULKAN_CALL(vkCreateInstance(&createInfo, nullptr, &instance));
}

void Application::destroyVulkanInstance() {
    vkDestroyInstance(instance, nullptr);
}
