#include "initialization.hpp"
#include <vulkan/vulkan.h>
#include <rhi/initialization.hpp>

namespace rhi
{
    static VkInstance instance = VK_NULL_HANDLE;

    Result initialize_vulkan()
    {
        VkApplicationInfo app_info{};
        app_info.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
        app_info.pApplicationName = "Renderer";
        app_info.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
        app_info.pEngineName = "RHI";
        app_info.engineVersion = VK_MAKE_VERSION(1, 0, 0);
        app_info.apiVersion = VK_API_VERSION_1_0;

        VkInstanceCreateInfo create_info{};
        create_info.sType =
            VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
        create_info.pApplicationInfo = &app_info;

        VkResult result = vkCreateInstance(
            &create_info,
            nullptr,
            &instance
        );

        if (result != VK_SUCCESS)
        {
            instance = VK_NULL_HANDLE;
            return Result::InitializationFailed;
        }

        return Result::Success;
    }

    void shutdown_vulkan()
    {
        if (instance != VK_NULL_HANDLE)
        {
            vkDestroyInstance(instance, nullptr);
            instance = VK_NULL_HANDLE;
        }
    }
}
