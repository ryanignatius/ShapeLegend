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
        src/entity/World.hpp
        src/entity/World.cpp
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
        src/entity/core/Transform.cpp src/entity/core/Transform.hpp src/entity/core/Vector3.cpp src/entity/core/Vector3.hpp src/entity/shape/Shape.cpp src/entity/shape/Shape.hpp src/entity/core/BaseEntity.cpp src/entity/core/BaseEntity.hpp src/common/Logger.cpp src/common/Logger.hpp src/entity/core/renderer/Renderer.cpp src/entity/core/renderer/Renderer.hpp src/entity/core/renderer/TriangleRenderer.cpp src/entity/core/renderer/TriangleRenderer.hpp src/entity/core/renderer/SquareRenderer.cpp src/entity/core/renderer/SquareRenderer.hpp src/entity/core/renderer/CircleRenderer.cpp src/entity/core/renderer/CircleRenderer.hpp src/entity/shape/Triangle.cpp src/entity/shape/Triangle.hpp src/entity/shape/Square.cpp src/entity/shape/Square.hpp src/entity/shape/Circle.cpp src/entity/shape/Circle.hpp src/entity/core/player/Player.cpp src/entity/core/player/Player.hpp src/entity/core/player/PlayerInput.cpp src/entity/core/player/PlayerInput.hpp src/common/Time.cpp src/common/Time.hpp src/entity/core/player/CircleMove.cpp src/entity/core/player/CircleMove.hpp src/entity/core/player/TriangleMove.cpp src/entity/core/player/TriangleMove.hpp src/entity/core/player/SquareMove.cpp src/entity/core/player/SquareMove.hpp src/entity/core/player/PlayerMove.cpp src/entity/core/player/PlayerMove.hpp)

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

# glm
include_directories(
        external/glm-0.9.7.1/
        .
)

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
