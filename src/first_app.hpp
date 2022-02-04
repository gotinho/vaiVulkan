#pragma once

#include "lve_window.hpp"
#include "lve_pipeline.hpp"
#include "lve_device.hpp"

namespace lve
{
    class FirstApp
    {
    private:
        LveWindow lveWindow{WIDTH, HEIGTH, "Vai Vulkan"};
        LveDevice lveDevice{lveWindow};
        LvePipeline lvePipeline{
            lveDevice,
            "shaders/simple_shader.vert.spv",
            "shaders/simple_shader.frag.spv",
            LvePipeline::defaultPipelineConfigInfo(WIDTH, HEIGTH)};

    public:
        static constexpr int WIDTH = 800;
        static constexpr int HEIGTH = 600;
        void run();
    };

} // namespace lve