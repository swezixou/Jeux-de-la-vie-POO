#include "domain/Grid.hpp"
#include "domain/AliveCell.hpp"
#include "domain/DeadCell.hpp"

Grid::Grid(int w, int h, Rule* r)
    : width(w), height(h), rule(r)
{
    cells.resize(height);
    previousState.resize(height);

    for (int y = 0; y < height; ++y) {
        cells[y].resize(width);
        previousState[y].resize(width);

        for (int x = 0; x < width; ++x) {
            cells[y][x] = std::make_unique<DeadCell>(); // par défaut
            previousState[y][x] = false;
        }
    }
}

void Grid::setCell(int x, int y, std::unique_ptr<Cell> c) {
    cells[y][x] = std::move(c);
}

int Grid::countNeighbours(int x, int y) const {
    int count = 0;

    // 8 directions
    static const int dx[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
    static const int dy[8] = {-1, -1,-1,  0, 0,  1, 1, 1};

    for (int i = 0; i < 8; ++i) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        // Hors de la grille
        if (nx < 0 || nx >= width || ny < 0 || ny >= height)
            continue;

        if (cells[ny][nx]->isAlive())
            count++;
    }

    return count;
}

void Grid::saveState() {
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            previousState[y][x] = cells[y][x]->isAlive();
        }
    }
}

bool Grid::isStable() const {
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            if (previousState[y][x] != cells[y][x]->isAlive())
                return false;
        }
    }
    return true;
}

void Grid::update() {
    // sauvegarder l’état courant
    saveState();

    // créer une nouvelle grille temporaire
    std::vector<std::vector<std::unique_ptr<Cell>>> newCells;
    newCells.resize(height);

    for (int y = 0; y < height; ++y) {
        newCells[y].resize(width);

        for (int x = 0; x < width; ++x) {
            int aliveNeighbours = countNeighbours(x, y);

            Cell* current = cells[y][x].get();

            // apply() retourne un Cell* brut → on wrap dans unique_ptr
            newCells[y][x] = std::unique_ptr<Cell>(
                rule->apply(current, aliveNeighbours)
            );
        }
    }

    // remplacer l'ancienne grille
    cells = std::move(newCells);
}
