#include <iostream>
#include <string>

#include "application/FileManager.hpp"
#include "application/Game.hpp"

#include "presentation/ConsoleRenderer.hpp"
#include "presentation/SFMLRenderer.hpp"

#include "domain/ConwayRule.hpp"

int main() {

    std::cout << "===== JEU DE LA VIE =====\n\n";

    int mode = 0;
    while (mode != 1 && mode != 2) {
        std::cout << "Choisir le mode :\n";
        std::cout << "  1 - Mode Console\n";
        std::cout << "  2 - Mode Graphique (SFML)\n";
        std::cout << "Votre choix : ";
        std::cin >> mode;
    }
    int init = 0;
    while (init != 1 && init != 2) {
        std::cout << "\nInitialisation de la grille :\n";
        std::cout << "  1 - Fichier\n";
        std::cout << "  2 - Aléatoire\n";
        std::cout << "Votre choix : ";
        std::cin >> init;
    }

    Grid* grid = nullptr;
    Rule* rule = new ConwayRule();

    std::string filePath;

    if (init == 1) {
        std::cout << "\nChemin du fichier : ";
        std::cin >> filePath;

        grid = FileManager::loadGrid(filePath, rule);
        if (!grid) {
            std::cerr << "Erreur : impossible de charger la grille.\n";
            return 1;
        }
    }

    if (init == 2) {
        int w, h;
        std::cout << "\nLargeur de la grille : ";
        std::cin >> w;

        std::cout << "Hauteur de la grille : ";
        std::cin >> h;

        grid = FileManager::createRandomGrid(w, h, rule);
    }

    int limit;
    std::cout << "\nNombre maximum d'iterations : ";
    std::cin >> limit;

    Renderer* renderer = nullptr;

    if (mode == 1) {
        std::string outDir = filePath + "_out";
        FileManager::createDirectory(outDir);
        renderer = new ConsoleRenderer(outDir);
    }
    else {
        renderer = new SFMLRenderer(grid->getWidth(), grid->getHeight(), 20.f);
    }

    Game game(grid, renderer, limit);

    std::cout << "\n--- Simulation en cours ---\n";
    game.run();

    std::cout << "\n--- Simulation terminee ---\n";

    return 0;
}

