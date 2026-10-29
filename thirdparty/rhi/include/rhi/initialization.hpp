#pragma once

namespace rhi
{
    enum class GraphicsAPI
    {
        Vulkan,
        D3D12,
        Metal
    };

    enum class Result
    {
        Success,
        InitializationFailed,
        UnsupportedAPI
    };

    struct InitializationInfo
    {
        GraphicsAPI api = GraphicsAPI::Vulkan;
    };

    Result initialize(const InitializationInfo& info);
    void shutdown();
}
