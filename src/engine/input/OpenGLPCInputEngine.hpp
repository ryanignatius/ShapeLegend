//
// Created by ryan-i-hadiwijaya on 7/10/18.
//

#ifndef SHAPELEGEND_OPENGLPCINPUTENGINE_HPP
#define SHAPELEGEND_OPENGLPCINPUTENGINE_HPP

#include "InputEngine.hpp"

// Include GLEW
#include <GL/glew.h>

// Include GLFW
#include <GLFW/glfw3.h>

#include "../../common/shader.hpp"

class OpenGLPCInputEngine : public InputEngine {
public:
    explicit OpenGLPCInputEngine(GLFWwindow &);

    Event getInput() override;

private:
    GLFWwindow &window;
};

#endif //SHAPELEGEND_OPENGLPCINPUTENGINE_HPP
