cmake_minimum_required(VERSION 3.10)
project(ShapeLegend)

set(CMAKE_CXX_STANDARD 11)

add_executable(ShapeLegend
        src/main.cpp
        src/common/shader.cpp
        src/common/shader.hpp
        src/engine/render/RenderEngine.hpp
        src/engine/render/RenderEngine.cpp
        src/engine/render/OpenGLRenderEngine.cpp
        src/engine/render/OpenGLRenderEngine.hpp
        src/configuration/Configuration.hpp
        src/configuration/World.hpp
        src/configuration/World.cpp
        src/engine/input/InputEngine.cpp
        src/engine/input/InputEngine.hpp
        src/event/Event.hpp
        src/event/EventObserver.hpp
        src/event/EventObservable.hpp
        src/event/Event.cpp
        src/event/EventObservable.cpp
        src/engine/input/OpenGLPCInputEngine.cpp
        src/engine/input/OpenGLPCInputEngine.hpp
        src/engine/GameEngine.cpp
        src/engine/GameEngine.hpp
)

# glfw
find_package(glfw3 REQUIRED)
include_directories(${GLFW_INCLUDE_DIRS})
link_libraries(${GLFW_LIBRARY_DIRS})

# opengl
find_package(OpenGL REQUIRED)
include_directories(${OPENGL_INCLUDE_DIRS})

# glew
find_package(GLEW REQUIRED)
include_directories(${GLEW_INCLUDE_DIRS})

target_link_libraries(
        ShapeLegend
        glfw
        ${OPENGL_LIBRARIES}
        ${GLEW_LIBRARIES}
        ${EXTRA_LIBS}
)

configure_file(src/shader/SimpleFragmentShader.fragmentshader
        ${CMAKE_CURRENT_BINARY_DIR} COPYONLY)
configure_file(src/shader/SimpleVertexShader.vertexshader
        ${CMAKE_CURRENT_BINARY_DIR} COPYONLY)
