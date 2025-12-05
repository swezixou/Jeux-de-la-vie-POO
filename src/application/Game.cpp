#include "application/Game.hpp"
#include "presentation/SFMLRenderer.hpp"
#include <thread>
#include <chrono>
#include <iostream>

Game::Game(Grid* g, Renderer* r, int limit)
    : grid(g),
      renderer(r),
      iterationLimit(limit),
      currentIteration(0),
      running(true)
{
}

void Game::stop() {
    running = false;
}

void Game::run() {

    while (renderer->isOpen() && running) {

        if (!renderer->handleEvents()) {
            stop();
            break;
        }

        SFMLRenderer* sfml = dynamic_cast<SFMLRenderer*>(renderer);

        if (sfml != nullptr) {

            std::this_thread::sleep_for(std::chrono::milliseconds(sfml->speed));

            if (!sfml->paused || sfml->stepOnce) {
                grid->update();
                currentIteration++;
                sfml->stepOnce = false;
            }

            renderer->render(grid, currentIteration);
        }
        else {
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
            grid->update();
            currentIteration++;
            renderer->render(grid, currentIteration);
        }

        if (grid->isStable()) {
            std::cout << "[INFO] La grille est stable. Fin.\n";
            stop();
            break;
        }

        if (currentIteration >= iterationLimit) {
            std::cout << "[INFO] Limite atteinte. Fin.\n";
            stop();
            break;
        }
    }
}
