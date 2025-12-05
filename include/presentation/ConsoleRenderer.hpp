#pragma once

#include <string>
#include "Renderer.hpp"
#include "application/FileManager.hpp"

class ConsoleRenderer : public Renderer {
private:
    std::string outputDir;
    int iteration;
public:
    ConsoleRenderer(const std::string& dir);
    void render(Grid* grid, int iteration) override;
    bool isOpen() override;
    bool handleEvents() override;
};

