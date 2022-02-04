cmake_minimum_required(VERSION 3.22.2)

project(vaiVulkan)

set(vulkan_dir "C:/VulkanSDK/1.2.198.1/")
set(source_dir "${PROJECT_SOURCE_DIR}/src/")
file(GLOB source_files "${source_dir}*.cpp")

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/shaders/ DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/shaders/)

add_executable(vaiVulkan ${source_files})

target_include_directories(vaiVulkan PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src)
target_include_directories(vaiVulkan PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/lib/glm)

target_include_directories(vaiVulkan PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/lib/glfw-3.3.6.bin.WIN64/include)
target_link_directories(vaiVulkan PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/lib/glfw-3.3.6.bin.WIN64/lib-mingw-w64)
target_link_libraries(vaiVulkan PUBLIC glfw3)

target_include_directories(vaiVulkan PUBLIC ${vulkan_dir}/Include)
target_link_directories(vaiVulkan PUBLIC ${vulkan_dir}/Lib)
target_link_libraries(vaiVulkan PUBLIC vulkan-1)