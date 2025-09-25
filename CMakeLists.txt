cmake_minimum_required(VERSION 3.20)
project(opengl)

set(CMAKE_EXPORT_COMPILE_COMMANDS on)
set(CMAKE_CXX_STANDARD 23)

include(FetchContent)

FetchContent_Declare(GLFW
    GIT_REPOSITORY https://github.com/glfw/glfw
    GIT_TAG 3.4
)
FetchContent_Declare(glad
    GIT_REPOSITORY https://github.com/Dav1dde/glad
    GIT_TAG v2.0.8
    SOURCE_SUBDIR cmake
)
FetchContent_MakeAvailable(GLFW glad)

glad_add_library(glad_gl_core_mx_33 REPRODUCIBLE API gl:core=3.3)

file(GLOB CXX_SOURCES ./src/*.cpp)

add_executable(${PROJECT_NAME} ${CXX_SOURCES})
target_link_libraries(${PROJECT_NAME} PRIVATE glfw glad_gl_core_mx_33)
target_include_directories(${PROJECT_NAME} PRIVATE ./include)
