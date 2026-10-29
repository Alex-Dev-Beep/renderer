find_package(Vulkan REQUIRED)

add_library(rhi STATIC
    src/initialization.cpp
    src/vulkan/initialization.cpp
)

target_include_directories(rhi PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_link_libraries(rhi PRIVATE
    Vulkan::Vulkan
)
