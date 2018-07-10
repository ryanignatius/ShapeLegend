//
// Created by ryan-i-hadiwijaya on 7/10/18.
//

#ifndef SHAPELEGEND_OPENGLRENDERENGINE_HPP
#define SHAPELEGEND_OPENGLRENDERENGINE_HPP

#include "RenderEngine.hpp"

// Include GLEW
#include <GL/glew.h>

// Include GLFW
#include <GLFW/glfw3.h>

#include "../../common/shader.hpp"
#include "../../event/EventObserver.hpp"

class OpenGLRenderEngine : public RenderEngine, public EventObserver {
public:
    OpenGLRenderEngine();

    int init() override;

    void draw() override;

    void clear() override;

    void onEvent(Event);

    GLFWwindow &getWindow();

private:
    const GLfloat g_vertex_buffer_data[9] = {
            -1.0f, -1.0f, 0.0f,
            1.0f, -1.0f, 0.0f,
            0.0f,  1.0f, 0.0f,
    };
    GLFWwindow* window;
    GLuint VertexArrayID;
    GLuint programID;
    GLuint vertexbuffer;
};

#endif //SHAPELEGEND_OPENGLRENDERENGINE_HPP
