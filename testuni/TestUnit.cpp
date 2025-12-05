#include <iostream>
#include "application/FileManager.hpp"
#include "application/Game.hpp"
#include "domain/ConwayRule.hpp"

bool compareGrids(Grid* g1, Grid* g2) {
    if (g1->getWidth() != g2->getWidth() ||
        g1->getHeight() != g2->getHeight())
        return false;

    for (int y = 0; y < g1->getHeight(); ++y) {
        for (int x = 0; x < g1->getWidth(); ++x) {
            if (g1->getCell(x, y)->isAlive() != g2->getCell(x, y)->isAlive()) {
                std::cout << "Difference at (" << x << "," << y << ")\n";
                return false;
            }
        }
    }
    return true;
}

void runTest(const std::string& inputPath,
             const std::string& expectedPath,
             int iterations)
{
    Rule* rule = new ConwayRule();

    Grid* grid = FileManager::loadGrid(inputPath, rule);
    Grid* expected = FileManager::loadGrid(expectedPath, rule);

    if (!grid || !expected) {
        std::cerr << "Error: cannot load test files.\n";
        return;
    }

    // appliquer N updates
    for (int i = 0; i < iterations; i++)
        grid->update();

    if (compareGrids(grid, expected))
        std::cout << "[TEST OK] " << inputPath << " after "
                  << iterations << " iteration(s)\n";
    else
        std::cout << "[TEST FAILED]\n";
}

int main() {
    runTest("data/test_cases/blinker.txt",
            "data/test_cases/blinker_expected_1.txt",
            1);

    return 0;
}
