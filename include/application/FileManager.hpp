#pragma once
#include <string>
#include "domain/Grid.hpp"
#include "domain/Rule.hpp"

class FileManager {
public:
    static Grid* loadGrid(const std::string& path, Rule* rule);
    static void saveGrid(Grid* grid, const std::string& path);
    static void createDirectory(const std::string& path);

    static Grid* createRandomGrid(int width, int height, Rule* rule);
};
