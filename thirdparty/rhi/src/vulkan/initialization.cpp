
#include "initialization.hpp"

#include <vulkan/vulkan.h>
#include <GLFW/glfw3.h>

#include <rhi/initialization.hpp>
#include "rhi/src/vulkan/instance.hpp"
#include "validation_layers.hpp"

#include <vector>
#include <cstring>
#include <iostream>

namespace rhi {

    std::vector<const char*> getRequiredExtensions() {
        uint32_t glfwExtensionCount = 0;

        const char** glfwExtensions =
            glfwGetRequiredInstanceExtensions(&glfwExtensionCount);

        if (glfwExtensions == nullptr) {
            return {};
        }

        std::vector<const char*> extensions(
            glfwExtensions,
            glfwExtensions + glfwExtensionCount
        );

        if (enableValidationLayers) {
            extensions.push_back(VK_EXT_DEBUG_UTILS_EXTENSION_NAME);
        }

        return extensions;
    }

    bool checkValidationLayerSupport() {
        uint32_t layerCount = 0;

        vkEnumerateInstanceLayerProperties(&layerCount, nullptr);

        std::vector<VkLayerProperties> availableLayers(layerCount);

        vkEnumerateInstanceLayerProperties(
            &layerCount,
            availableLayers.data()
        );

        for (const char* layerName : validationLayers) {
            bool layerFound = false;

            for (const auto& layerProperties : availableLayers) {
                if (std::strcmp(
                    layerName,
                    layerProperties.layerName
                ) == 0) {
                    layerFound = true;
                    break;
                }
            }

            if (!layerFound) {
                return false;
            }
        }

        return true;
    }

    namespace {
        Instance instance;
    }

    Result initialize_vulkan() {
        if (enableValidationLayers &&
            !checkValidationLayerSupport()) {
            return Result::InitializationFailed;
        }

        auto extensions = getRequiredExtensions();

        if (extensions.empty()) {
            return Result::InitializationFailed;
        }

        std::vector<const char*> layers;

        if (enableValidationLayers) {
            layers = validationLayers;
        }

        if (instance.create(extensions, layers) != VK_SUCCESS) {
            return Result::InitializationFailed;
        }

        std::cout << "Sucessfully created VkInstance." << std::endl;

        return Result::Success;
    }

    void shutdown_vulkan() {
        instance.destroy();
    }

}
