#include <rhi/initialization.hpp>
#include "vulkan/initialization.hpp"

namespace rhi
{
    Result initialize(const InitializationInfo& info)
    {
        switch (info.api)
        {
            case GraphicsAPI::Vulkan:
                return initialize_vulkan();

            case GraphicsAPI::D3D12:
            case GraphicsAPI::Metal:
                return Result::UnsupportedAPI;
        }

        return Result::UnsupportedAPI;
    }

    void shutdown()
    {
        shutdown_vulkan();
    }
}
