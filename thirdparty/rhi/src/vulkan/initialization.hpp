#pragma once

#include <rhi/initialization.hpp>

#ifdef NDEBUG
const bool enableValidationLayers = false;
#else
const bool enableValidationLayers = true;
#endif

namespace rhi {
    Result initialize_vulkan();
    void shutdown_vulkan();
}
