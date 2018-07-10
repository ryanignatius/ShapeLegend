cmake_minimum_required(VERSION 3.10)
project(ShapeLegend)

set(CMAKE_CXX_STANDARD 11)

add_executable(ShapeLegend
        main.cpp

        common/shader.cpp
        common/shader.hpp

        shader/SimpleFragmentShader.fragmentshader
        shader/SimpleVertexShader.vertexshader
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

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/shader/SimpleFragmentShader.fragmentshader
        ${CMAKE_CURRENT_BINARY_DIR} COPYONLY)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/shader/SimpleVertexShader.vertexshader
        ${CMAKE_CURRENT_BINARY_DIR} COPYONLY)
