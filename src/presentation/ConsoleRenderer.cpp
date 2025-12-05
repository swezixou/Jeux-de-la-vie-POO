#include "presentation/ConsoleRenderer.hpp"
#include "application/FileManager.hpp"
#include <filesystem>
#include <iostream>

ConsoleRenderer::ConsoleRenderer(const std::string& dir)
    : outputDir(dir), iteration(0)
{
    std::filesystem::create_directory(outputDir);
}

bool ConsoleRenderer::isOpen() {

    return true;
}

bool ConsoleRenderer::handleEvents() {
    return true;
}

void ConsoleRenderer::render(Grid* grid, int iteration) {
    int w = grid->getWidth();
    int h = grid->getHeight();

    std::cout << "\n=== Iteration " << iteration << " ===\n";

    for (int y = 0; y < h; ++y) {
        for (int x = 0; x < w; ++x) {
            std::cout << (grid->getCell(x, y)->isAlive() ? "1 " : "0 ");
        }
        std::cout << "\n";
    }
    std::string filename =
        outputDir + "/iter_" + std::to_string(iteration) + ".txt";

    FileManager::saveGrid(grid, filename);

    std::cout << "[CONSOLE] Fichier enregistré : " << filename << "\n";

    iteration++;
}
