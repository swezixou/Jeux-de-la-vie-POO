#pragma once

#include <memory>
#include "domain/Grid.hpp"
#include "presentation/Renderer.hpp"

class Game {
private:
    Grid* grid;
    Renderer* renderer;

    int iterationLimit;
    int currentIteration;
    bool running;

public:
    Game(Grid* g, Renderer* r, int limit);
    ~Game() = default;

    void run(); 
    void stop();
};
