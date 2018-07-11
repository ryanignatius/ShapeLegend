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

// Include GLM
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "../../common/shader.hpp"
#include "../../event/EventObserver.hpp"

#include <iostream>
#include <vector>

#define NUM_TRIANGLES 20
#define WINDOW_SIZE 800

using namespace glm;

class OpenGLRenderEngine : public RenderEngine, public EventObserver {
public:
    OpenGLRenderEngine();

    int init() override;

    void draw() override;

    void drawTriangle(Transform&, Vector3&) override;

    void drawSquare(Transform&, Vector3&) override;

    void drawCircle(Transform&, Vector3&) override;

    void clear() override;

    void onEvent(Event) override;

    GLFWwindow &getWindow();

private:
    static constexpr double pi() { return std::atan(1)*4; }

    GLfloat *g_vertex_buffer_data;
    /*
    GLfloat g_vertex_buffer_data[9] = {
            -1.0f, -1.0f, 0.0f,
            1.0f, -1.0f, 0.0f,
            0.0f,  1.0f, 0.0f,
    };
     */
    GLfloat *g_color_buffer_data;
    /*
    [9] = {
            1.0f,  1.0f, 0.0f,
            1.0f,  1.0f, 0.0f,
            1.0f,  1.0f, 0.0f,
    };
     */
    GLFWwindow* window;
    GLuint VertexArrayID;
    GLuint programID;
    GLuint vertexbuffer;
    GLuint colorbuffer;
    GLuint MatrixID;
    glm::mat4 MVP;
    std::vector<GLfloat> tempVertex;
    std::vector<GLfloat> tempColor;
};

#endif //SHAPELEGEND_OPENGLRENDERENGINE_HPP
