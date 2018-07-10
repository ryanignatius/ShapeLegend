//
// Created by ryan-i-hadiwijaya on 7/10/18.
//

#include <iostream>
#include "OpenGLPCInputEngine.hpp"

OpenGLPCInputEngine::OpenGLPCInputEngine(GLFWwindow &win) : window(win) {
}

Event OpenGLPCInputEngine::getInput() {
    if (glfwGetKey(&window, GLFW_KEY_ESCAPE ) == GLFW_PRESS ||
        glfwWindowShouldClose(&window) != 0) {
        std::cout << "close window called" << std::endl;
        return {Event::ESCAPE_EVENT};
    }
    return {Event::NULL_EVENT};
}