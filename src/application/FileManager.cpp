#include "application/FileManager.hpp"
#include "domain/AliveCell.hpp"
#include "domain/DeadCell.hpp"

#include <fstream>
#include <iostream>
#include <filesystem>
#include <random>

Grid* FileManager::loadGrid(const std::string& path, Rule* rule) {
    std::ifstream file(path);
    if (!file.is_open()) {
        std::cerr << "[ERREUR] Impossible d'ouvrir le fichier : " << path << "\n";
        return nullptr;
    }
    int height, width;
    file >> height >> width;

    Grid* grid = new Grid(width, height, rule);

    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            int value;
            file >> value;

            if (value == 1)
                grid->setCell(x, y, std::make_unique<AliveCell>());
            else
                grid->setCell(x, y, std::make_unique<DeadCell>());
        }
    }

    return grid;
}

void FileManager::saveGrid(Grid* grid, const std::string& path) {
    std::ofstream file(path);
    if (!file.is_open()) {
        std::cerr << "[ERREUR] Impossible d'écrire dans : " << path << "\n";
        return;
    }

    int height = grid->getHeight();
    int width = grid->getWidth();

    // première ligne : "rows cols"
    file << height << " " << width << "\n";

    // matrice
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            file << (grid->getCell(x, y)->isAlive() ? 1 : 0);
            if (x < width - 1) file << " ";
        }
        file << "\n";
    }
}

void FileManager::createDirectory(const std::string& path) {
    if (!std::filesystem::exists(path)) {
        std::filesystem::create_directory(path);
    }
}

Grid* FileManager::createRandomGrid(int width, int height, Rule* rule) {
    Grid* grid = new Grid(width, height, rule);

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 1);

    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            if (dis(gen) == 1)
                grid->setCell(x, y, std::make_unique<AliveCell>());
            else
                grid->setCell(x, y, std::make_unique<DeadCell>());
        }
    }
    return grid;
}
