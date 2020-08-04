cmake_minimum_required(VERSION 3.12)
project(GL-game VERSION 1.0)

add_subdirectory(deps/glfw)

include_directories(include)

add_executable(myapp src/main.cpp
src/glad.c)

target_link_libraries(myapp glfw)

find_package(OpenGL REQUIRED)

target_link_libraries(myapp OpenGL::GL)
