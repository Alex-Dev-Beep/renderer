cmake_minimum_required(VERSION 3.25)

project(renderer LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(glfw3 REQUIRED)

add_subdirectory(thirdparty/rhi)

add_executable(renderer
    src/main.cpp
    src/window/window.cpp
)

target_link_libraries(renderer PRIVATE
    rhi
    glfw
)

target_include_directories(rhi
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/thirdparty
)
