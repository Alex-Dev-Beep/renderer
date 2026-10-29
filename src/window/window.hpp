#pragma once

#include <GLFW/glfw3.h>

struct Window {
    static void create();
    static void destroy();

    inline static GLFWwindow* window;
};
