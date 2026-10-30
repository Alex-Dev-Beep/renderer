find_package(Vulkan REQUIRED)

add_library(rhi STATIC
    src/initialization.cpp
    src/vulkan/initialization.cpp
    src/vulkan/debug_messenger.cpp
    src/vulkan/instance.cpp
    src/vulkan/validation_layers.cpp
)

target_include_directories(rhi PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_link_libraries(rhi PRIVATE
    Vulkan::Vulkan
)
