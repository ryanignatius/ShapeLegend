//
// Created by ryan-i-hadiwijaya on 7/10/18.
//

#include <iostream>
#include <src/common/Logger.hpp>
#include "OpenGLPCInputEngine.hpp"

OpenGLPCInputEngine::OpenGLPCInputEngine(GLFWwindow &win) : window(win) {
}

Event OpenGLPCInputEngine::getInput() {
    if (glfwGetKey(&window, GLFW_KEY_ESCAPE ) == GLFW_PRESS ||
        glfwWindowShouldClose(&window) != 0) {
        Logger::info("close window event called");
        return {Event::ESCAPE_EVENT};
    }

    // player 1
    if (glfwGetKey( &window, GLFW_KEY_UP ) == GLFW_PRESS){
        return {Event::PLAYER1_UP_EVENT};
    }
    if (glfwGetKey( &window, GLFW_KEY_DOWN ) == GLFW_PRESS){
        return {Event::PLAYER1_DOWN_EVENT};
    }
    if (glfwGetKey( &window, GLFW_KEY_LEFT ) == GLFW_PRESS){
        return {Event::PLAYER1_LEFT_EVENT};
    }
    if (glfwGetKey( &window, GLFW_KEY_RIGHT ) == GLFW_PRESS){
        return {Event::PLAYER1_RIGHT_EVENT};
    }
    return {Event::NULL_EVENT};
}
