#include "window/window.hpp"

#include <iostream>
#include <rhi/initialization.hpp>

int main()
{
    Window::create();
    rhi::InitializationInfo info{};
    info.api = rhi::GraphicsAPI::Vulkan;

    rhi::Result result = rhi::initialize(info);

    if (result != rhi::Result::Success)
    {
        std::cerr << "Failed to initialize RHI" << std::endl;
        return 1;
    }

    std::cout << "RHI initialized successfully." << std::endl;

    while (!glfwWindowShouldClose(Window::window))
    {
        glfwPollEvents();
    }

    rhi::shutdown();
    Window::destroy();
    return 0;
}
