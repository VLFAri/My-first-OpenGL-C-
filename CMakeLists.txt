cmake_minimum_required(VERSION 3.28.3)
project(my_opengl_project VERSION 0.1.0)

add_executable(my_opengl_project 
src/main.cpp
src/glad.h
src/glad.c
src/khrplatform.h
)

target_link_libraries(my_opengl_project glfw)
