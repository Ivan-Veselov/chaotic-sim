#include "application.h"


Application::Application() {
    initGLFW();
    initWindow();
}

Application::~Application() {
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