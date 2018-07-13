//
// Created by ryan-i-hadiwijaya on 7/10/18.
//

#include <iostream>
#include <src/common/Logger.hpp>
#include "OpenGLRenderEngine.hpp"

int OpenGLRenderEngine::init() {
    // Initialise GLFW
    if( !glfwInit() )
    {
        fprintf( stderr, "Failed to initialize GLFW\n" );
        getchar();
        return -1;
    }

    glfwWindowHint(GLFW_SAMPLES, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // To make MacOS happy; should not be needed
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // Open a window and create its OpenGL context
    window = glfwCreateWindow( WINDOW_SIZE, WINDOW_SIZE, "Shape Legend", nullptr, nullptr);
    if( window == nullptr ){
        fprintf( stderr, "Failed to open GLFW window. If you have an Intel GPU, they are not 3.3 compatible. Try the 2.1 version of the tutorials.\n" );
        getchar();
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);

    // Initialize GLEW
    glewExperimental = true; // Needed for core profile
    if (glewInit() != GLEW_OK) {
        fprintf(stderr, "Failed to initialize GLEW\n");
        getchar();
        glfwTerminate();
        return -1;
    }

    // Ensure we can capture the escape key being pressed below
    glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);

    // White background
    glClearColor(1.0f, 1.0f, 1.0f, 0.0f);

    // Enable depth test
    glEnable(GL_DEPTH_TEST);
    // Accept fragment if it closer to the camera than the former one
    glDepthFunc(GL_LESS);

    // Cull triangles which normal is not towards the camera
    glEnable(GL_CULL_FACE);

    glGenVertexArrays(1, &VertexArrayID);
    glBindVertexArray(VertexArrayID);

    // Create and compile our GLSL program from the shaders
    programID = LoadShaders( "SimpleVertexShader.vertexshader", "SimpleFragmentShader.fragmentshader" );

    // Get a handle for our "MVP" uniform
    MatrixID = glGetUniformLocation(programID, "MVP");
    ViewMatrixID = glGetUniformLocation(programID, "V");
    ModelMatrixID = glGetUniformLocation(programID, "M");
    LightID = glGetUniformLocation(programID, "LightPosition_worldspace");
    LightColorID = glGetUniformLocation(programID, "LightColor");
    LightPowerID = glGetUniformLocation(programID, "LightPower");

    // Projection matrix : 45° Field of View, 4:3 ratio, display range : 0.1 unit <-> 100 units
    //glm::mat4 Projection = glm::perspective(glm::radians(45.0f), 4.0f / 3.0f, 0.1f, 100.0f);
    glm::mat4 Projection = glm::ortho(-10.0f,10.0f,-10.0f,10.0f,0.0f,100.0f); // In world coordinates

    // Camera matrix
    View  = glm::lookAt(
            glm::vec3(0,0,10), // Camera is at (0,0,10), in World Space
            glm::vec3(0,0,0), // and looks at the origin
            glm::vec3(0,1,0)  // Head is up (set to 0,-1,0 to look upside-down)
    );
    // Model matrix : an identity matrix (model will be at the origin)
    Model      = glm::mat4(1.0f);
    // Our ModelViewProjection : multiplication of our 3 matrices
    MVP        = Projection * View * Model; // Remember, matrix multiplication is the other way around

    glGenBuffers(1, &vertexbuffer);
    glGenBuffers(1, &colorbuffer);
    glGenBuffers(1, &normalbuffer);

    return 0;
}

OpenGLRenderEngine::OpenGLRenderEngine() = default;

void OpenGLRenderEngine::draw() {
    tempVertex.clear();
    tempColor.clear();
    tempNormal.clear();
    for (BaseEntity *entity : entityList) {
        if (entity->isActive() && entity->isRender()) {
            entity->getRenderer().render(entity->getTransform());
        }
    }
    g_vertex_buffer_data = new GLfloat[tempVertex.size()];
    for (int i = 0; i < tempVertex.size(); i++) {
        g_vertex_buffer_data[i] = tempVertex[i];
    }
    g_color_buffer_data = new GLfloat[tempColor.size()];
    for (int i = 0; i < tempColor.size(); i++) {
        g_color_buffer_data[i] = tempColor[i];
    }
    g_normal_buffer_data = new GLfloat[tempNormal.size()];
    for (int i = 0; i < tempNormal.size(); i++) {
        g_normal_buffer_data[i] = tempNormal[i];
    }

    // Use our shader
    glUseProgram(programID);

    // Send our transformation to the currently bound shader,
    // in the "MVP" uniform
    glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &MVP[0][0]);
    glUniformMatrix4fv(ModelMatrixID, 1, GL_FALSE, &Model[0][0]);
    glUniformMatrix4fv(ViewMatrixID, 1, GL_FALSE, &View[0][0]);
    glUniform3f(LightID, 4, 4, 4);
    glUniform3f(LightColorID, 1, 1, 1);
    glUniform1f(LightPowerID, 50);

    // 1rst attribute buffer : vertices
    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * tempVertex.size(), g_vertex_buffer_data, GL_STATIC_DRAW);
    glVertexAttribPointer(
            0,                  // attribute 0. No particular reason for 0, but must match the layout in the shader.
            3,                  // size
            GL_FLOAT,           // type
            GL_FALSE,           // normalized?
            0,                  // stride
            (void*)0            // array buffer offset
    );

    // 2nd attribute buffer : colors
    glEnableVertexAttribArray(1);
    glBindBuffer(GL_ARRAY_BUFFER, colorbuffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * tempColor.size(), g_color_buffer_data, GL_STATIC_DRAW);
    glVertexAttribPointer(
            1,                                // attribute. No particular reason for 1, but must match the layout in the shader.
            3,                                // size
            GL_FLOAT,                         // type
            GL_FALSE,                         // normalized?
            0,                                // stride
            (void*)0                          // array buffer offset
    );

    // 3rd attribute buffer : normals
    glEnableVertexAttribArray(2);
    glBindBuffer(GL_ARRAY_BUFFER, normalbuffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * tempColor.size(), g_normal_buffer_data, GL_STATIC_DRAW);
    glVertexAttribPointer(
            2,                                // attribute
            3,                                // size
            GL_FLOAT,                         // type
            GL_FALSE,                         // normalized?
            0,                                // stride
            (void*)0                          // array buffer offset
    );

    glDrawArrays(GL_TRIANGLES, 0, (GLsizei) tempVertex.size());

    glDisableVertexAttribArray(0);
    glDisableVertexAttribArray(1);
    glDisableVertexAttribArray(2);

    // Swap buffers
    glfwSwapBuffers(window);
    glfwPollEvents();
}

void OpenGLRenderEngine::clear() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void OpenGLRenderEngine::onEvent(Event event) {
    switch (event.getValue()) {
        case Event::ESCAPE_EVENT:
            // Cleanup VBO
            glDeleteBuffers(1, &vertexbuffer);
            glDeleteBuffers(1, &colorbuffer);
            glDeleteBuffers(1, &normalbuffer);
            glDeleteVertexArrays(1, &VertexArrayID);
            glDeleteProgram(programID);

            // Close OpenGL window and terminate GLFW
            glfwTerminate();
            break;
        default:
            break;
    }
}

GLFWwindow &OpenGLRenderEngine::getWindow() {
    return *window;
}

void OpenGLRenderEngine::drawTriangle(Transform &transform, Vector3& color) {
    float w = transform.getScale().x;
    float h = transform.getScale().y;
    tempVertex.push_back(transform.getPosition().x - w/2);
    tempVertex.push_back(transform.getPosition().y - h/2);
    tempVertex.push_back(transform.getPosition().z);
    tempVertex.push_back(transform.getPosition().x + w/2);
    tempVertex.push_back(transform.getPosition().y - h/2);
    tempVertex.push_back(transform.getPosition().z);
    tempVertex.push_back(transform.getPosition().x);
    tempVertex.push_back(transform.getPosition().y + h/2);
    tempVertex.push_back(transform.getPosition().z);
    tempColor.push_back(color.x);
    tempColor.push_back(color.y);
    tempColor.push_back(color.z);
    tempColor.push_back(color.x);
    tempColor.push_back(color.y);
    tempColor.push_back(color.z);
    tempColor.push_back(color.x);
    tempColor.push_back(color.y);
    tempColor.push_back(color.z);
    tempNormal.push_back(0);
    tempNormal.push_back(0);
    tempNormal.push_back(1);
    tempNormal.push_back(0);
    tempNormal.push_back(0);
    tempNormal.push_back(1);
    tempNormal.push_back(0);
    tempNormal.push_back(0);
    tempNormal.push_back(1);
}

void OpenGLRenderEngine::drawSquare(Transform &transform, Vector3& color) {
    float w = transform.getScale().x;
    float h = transform.getScale().y;
    tempVertex.push_back(transform.getPosition().x - w/2);
    tempVertex.push_back(transform.getPosition().y - h/2);
    tempVertex.push_back(transform.getPosition().z);
    tempVertex.push_back(transform.getPosition().x + w/2);
    tempVertex.push_back(transform.getPosition().y - h/2);
    tempVertex.push_back(transform.getPosition().z);
    tempVertex.push_back(transform.getPosition().x - w/2);
    tempVertex.push_back(transform.getPosition().y + h/2);
    tempVertex.push_back(transform.getPosition().z);
    tempVertex.push_back(transform.getPosition().x + w/2);
    tempVertex.push_back(transform.getPosition().y - h/2);
    tempVertex.push_back(transform.getPosition().z);
    tempVertex.push_back(transform.getPosition().x + w/2);
    tempVertex.push_back(transform.getPosition().y + h/2);
    tempVertex.push_back(transform.getPosition().z);
    tempVertex.push_back(transform.getPosition().x - w/2);
    tempVertex.push_back(transform.getPosition().y + h/2);
    tempVertex.push_back(transform.getPosition().z);
    tempColor.push_back(color.x);
    tempColor.push_back(color.y);
    tempColor.push_back(color.z);
    tempColor.push_back(color.x);
    tempColor.push_back(color.y);
    tempColor.push_back(color.z);
    tempColor.push_back(color.x);
    tempColor.push_back(color.y);
    tempColor.push_back(color.z);
    tempColor.push_back(color.x);
    tempColor.push_back(color.y);
    tempColor.push_back(color.z);
    tempColor.push_back(color.x);
    tempColor.push_back(color.y);
    tempColor.push_back(color.z);
    tempColor.push_back(color.x);
    tempColor.push_back(color.y);
    tempColor.push_back(color.z);
    tempNormal.push_back(0);
    tempNormal.push_back(0);
    tempNormal.push_back(1);
    tempNormal.push_back(0);
    tempNormal.push_back(0);
    tempNormal.push_back(1);
    tempNormal.push_back(0);
    tempNormal.push_back(0);
    tempNormal.push_back(1);
    tempNormal.push_back(0);
    tempNormal.push_back(0);
    tempNormal.push_back(1);
    tempNormal.push_back(0);
    tempNormal.push_back(0);
    tempNormal.push_back(1);
    tempNormal.push_back(0);
    tempNormal.push_back(0);
    tempNormal.push_back(1);
}

void OpenGLRenderEngine::drawCircle(Transform &transform, Vector3& color) {
    float w = transform.getScale().x;
    GLfloat x = transform.getPosition().x;
    GLfloat y = transform.getPosition().y;
    GLfloat z = transform.getPosition().z;
    GLfloat radius = w/2;

    int triangleAmount = NUM_TRIANGLES; //# of triangles used to draw circle

    GLfloat twicePi = 2.0f * (GLfloat) OpenGLRenderEngine::pi();
    for (int i = 1; i <= triangleAmount; i++) {
        tempVertex.push_back(x);
        tempVertex.push_back(y);
        tempVertex.push_back(z);
        tempVertex.push_back(x + (radius * cos(i * twicePi / triangleAmount)));
        tempVertex.push_back(y + (radius * sin(i * twicePi / triangleAmount)));
        tempVertex.push_back(z);
        tempVertex.push_back(x + (radius * cos((i + 1) * twicePi / triangleAmount)));
        tempVertex.push_back(y + (radius * sin((i + 1) * twicePi / triangleAmount)));
        tempVertex.push_back(z);
        tempColor.push_back(color.x);
        tempColor.push_back(color.y);
        tempColor.push_back(color.z);
        tempColor.push_back(color.x);
        tempColor.push_back(color.y);
        tempColor.push_back(color.z);
        tempColor.push_back(color.x);
        tempColor.push_back(color.y);
        tempColor.push_back(color.z);
        tempNormal.push_back(0);
        tempNormal.push_back(0);
        tempNormal.push_back(1);
        tempNormal.push_back(0);
        tempNormal.push_back(0);
        tempNormal.push_back(1);
        tempNormal.push_back(0);
        tempNormal.push_back(0);
        tempNormal.push_back(1);
    }
    tempVertex.push_back(x);
    tempVertex.push_back(y);
    tempVertex.push_back(z);
    tempVertex.push_back(x + (radius * cos(triangleAmount * twicePi / triangleAmount)));
    tempVertex.push_back(y + (radius * sin(triangleAmount * twicePi / triangleAmount)));
    tempVertex.push_back(z);
    tempVertex.push_back(x + (radius * cos(0 * twicePi / triangleAmount)));
    tempVertex.push_back(y + (radius * sin(0 * twicePi / triangleAmount)));
    tempVertex.push_back(z);
    tempColor.push_back(color.x);
    tempColor.push_back(color.y);
    tempColor.push_back(color.z);
    tempColor.push_back(color.x);
    tempColor.push_back(color.y);
    tempColor.push_back(color.z);
    tempColor.push_back(color.x);
    tempColor.push_back(color.y);
    tempColor.push_back(color.z);
    tempNormal.push_back(0);
    tempNormal.push_back(0);
    tempNormal.push_back(1);
    tempNormal.push_back(0);
    tempNormal.push_back(0);
    tempNormal.push_back(1);
    tempNormal.push_back(0);
    tempNormal.push_back(0);
    tempNormal.push_back(1);
}
