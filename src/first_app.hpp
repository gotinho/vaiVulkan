#pragma once

#include "lve_window.hpp"
#include "lve_pipeline.hpp"
#include "lve_swap_chain.hpp"
#include "lve_device.hpp"

#include <memory>
#include <vector>

namespace lve
{
    class FirstApp
    {
    private:
        LveWindow lveWindow{WIDTH, HEIGTH, "Vai Vulkan"};
        LveDevice lveDevice{lveWindow};
        LveSwapChain lveSwapChain{lveDevice, lveWindow.getExtent()};
        std::unique_ptr<LvePipeline> lvePipeline;
        // LvePipeline lvePipeline{
        //     lveDevice,
        //     "shaders/simple_shader.vert.spv",
        //     "shaders/simple_shader.frag.spv",
        //     LvePipeline::defaultPipelineConfigInfo(WIDTH, HEIGTH)};
        VkPipelineLayout pipelineLayout;
        std::vector<VkCommandBuffer> commandBuffers;

        void createPipelineLayout();
        void createPipeline();
        void createCommandBuffers();
        void drawFrame();

    public:
        FirstApp();
        ~FirstApp();

        FirstApp(const FirstApp &) = delete;
        FirstApp &operator=(const FirstApp &) = delete;

        static constexpr int WIDTH = 800;
        static constexpr int HEIGTH = 600;
        void run();
    };

} // namespace lve