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
    GLfloat *g_color_buffer_data;
    GLfloat *g_normal_buffer_data;

    GLFWwindow* window;
    GLuint VertexArrayID;
    GLuint programID;

    GLuint vertexbuffer;
    GLuint colorbuffer;
    GLuint normalbuffer;

    GLuint MatrixID;
    GLuint ViewMatrixID;
    GLuint ModelMatrixID;
    GLuint LightID;
    GLuint LightPowerID;
    GLuint LightColorID;

    glm::mat4 MVP;
    glm::mat4 View;
    glm::mat4 Model;

    std::vector<GLfloat> tempVertex;
    std::vector<GLfloat> tempColor;
    std::vector<GLfloat> tempNormal;
};

#endif //SHAPELEGEND_OPENGLRENDERENGINE_HPP
