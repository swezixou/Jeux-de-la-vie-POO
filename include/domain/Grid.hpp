#pragma once 
#include <vector>
#include <memory>
#include "Cell.hpp"
#include "Rule.hpp"

class Grid {
private:
    int width;
    int height;

    std::vector<std::vector<std::unique_ptr<Cell>>> cells;
    std::vector<std::vector<bool>> previousState;

    Rule* rule;
public:
    Grid(int w, int h, Rule* r);
    ~Grid() = default;

    int getWidth() const { return width; }
    int getHeight() const { return height; }

    Cell* getCell(int x, int y) const {
        return cells[y][x].get();
    }

    void setCell(int x, int y, std::unique_ptr<Cell> c);

    int countNeighbours(int x, int y) const;

    void saveState();
    bool isStable() const;

    void update();
};
