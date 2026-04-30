cmake_minimum_required(VERSION 4.2)
project(Graphics)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(Graphics
	src/main.cpp
    src/math/Vec2.cpp
    src/math/Vec3.cpp
    src/math/Vec4.cpp
    src/math/VecConversions.cpp
    src/math/Mat4.cpp
    src/objects/Color.cpp
    src/objects/Object.cpp
    src/objects/Camera.cpp
    src/render/Projection.cpp
    src/render/ASCII/render/Color.cpp
    src/render/ASCII/window/Window.cpp
    src/fstream/FObj.cpp
)

target_include_directories(${PROJECT_NAME} PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/include")

set_target_properties(${PROJECT_NAME} PROPERTIES
    CXX_STANDARD 20
    CXX_STANDARD_REQUIRED ON
)
