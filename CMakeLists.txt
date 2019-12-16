cmake_minimum_required(VERSION 3.0)
project(RPGGameGL)

file(GLOB SOURCES "${PROJECT_SOURCE_DIR}/src/*.cpp")

include_directories(include)
include_directories(src)
include_directories(${OPENGL_INCLUDE_DIR}/gl)

find_package(OpenGL REQUIRED)
find_package(GLEW REQUIRED)
find_package(glfw3 CONFIG REQUIRED)
find_package(GLUT REQUIRED)

add_executable(main "src/Main.cpp" ${SOURCES})

target_link_libraries(main PRIVATE ${OPENGL_gl_LIBRARY})
target_link_libraries(main PRIVATE GLEW::GLEW)
target_link_libraries(main PRIVATE GLUT::GLUT)
target_link_libraries(main PRIVATE glfw)