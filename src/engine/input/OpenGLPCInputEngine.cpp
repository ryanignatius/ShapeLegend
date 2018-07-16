//
// Created by ryan-i-hadiwijaya on 7/10/18.
//

#include <iostream>
#include <src/common/Logger.hpp>
#include "OpenGLPCInputEngine.hpp"

OpenGLPCInputEngine::OpenGLPCInputEngine(GLFWwindow &win) : window(win) {
}

Event OpenGLPCInputEngine::getInput(int channel) {
    if (glfwGetKey(&window, GLFW_KEY_ESCAPE ) == GLFW_PRESS ||
        glfwWindowShouldClose(&window) != 0) {
        Logger::info("close window event called");
        return {Event::ESCAPE_EVENT};
    }

    int ev = Event::NULL_EVENT;
    switch (channel) {
        case 0:
            break;
        case 1:
            if (glfwGetKey( &window, GLFW_KEY_UP ) == GLFW_PRESS){
                ev |= Event::UP;
            }
            if (glfwGetKey( &window, GLFW_KEY_DOWN ) == GLFW_PRESS){
                ev |= Event::DOWN;
            }
            if (glfwGetKey( &window, GLFW_KEY_LEFT ) == GLFW_PRESS){
                ev |= Event::LEFT;
            }
            if (glfwGetKey( &window, GLFW_KEY_RIGHT ) == GLFW_PRESS){
                ev |= Event::RIGHT;
            }
            break;
        case 2:
            if (glfwGetKey( &window, GLFW_KEY_W ) == GLFW_PRESS){
                ev |= Event::UP;
            }
            if (glfwGetKey( &window, GLFW_KEY_S ) == GLFW_PRESS){
                ev |= Event::DOWN;
            }
            if (glfwGetKey( &window, GLFW_KEY_A ) == GLFW_PRESS){
                ev |= Event::LEFT;
            }
            if (glfwGetKey( &window, GLFW_KEY_D ) == GLFW_PRESS){
                ev |= Event::RIGHT;
            }
            break;
        case 3:
            if (glfwGetKey( &window, GLFW_KEY_I ) == GLFW_PRESS){
                ev |= Event::UP;
            }
            if (glfwGetKey( &window, GLFW_KEY_K ) == GLFW_PRESS){
                ev |= Event::DOWN;
            }
            if (glfwGetKey( &window, GLFW_KEY_J ) == GLFW_PRESS){
                ev |= Event::LEFT;
            }
            if (glfwGetKey( &window, GLFW_KEY_L ) == GLFW_PRESS){
                ev |= Event::RIGHT;
            }
            break;
    }
    return {ev};
}
