#include <cassert>
#include <iostream>

#include "Game.hpp"
#include "AliveCell.hpp"
#include "DeadCell.hpp"

void setAlive(Grid& g, int x, int y) {
    delete g.cells[y][x];
    g.cells[y][x] = new AliveCell();
}

void setDead(Grid& g, int x, int y) {
    delete g.cells[y][x];
    g.cells[y][x] = new DeadCell();
}

Cell* getCell(const Grid& g, int x, int y) {
    return g.cells[y][x];
}

void test_underpopulation() {
    Game game(3, 3);
    Grid& g = game.getGrid();
    setAlive(g, 1, 1);
    setAlive(g, 0, 1);
    game.update();
    assert(!getCell(game.getGrid(), 1, 1)->isAlive());
    std::cout << "[OK] Sous-population\n";
}

void test_survival() {
    Game game(3, 3);
    Grid& g = game.getGrid();
    setAlive(g, 1, 1);
    setAlive(g, 0, 1);
    setAlive(g, 2, 1);
    game.update();
    assert(getCell(game.getGrid(), 1, 1)->isAlive());
    std::cout << "[OK] Survie\n";
}

void test_overpopulation() {
    Game game(3, 3);
    Grid& g = game.getGrid();
    setAlive(g, 1, 1);
    setAlive(g, 0, 1);
    setAlive(g, 2, 1);
    setAlive(g, 1, 0);
    setAlive(g, 1, 2);
    game.update();
    assert(!getCell(game.getGrid(), 1, 1)->isAlive());
    std::cout << "[OK] Surpopulation\n";
}

void test_reproduction() {
    Game game(3, 3);
    Grid& g = game.getGrid();
    setAlive(g, 0, 1);
    setAlive(g, 1, 0);
    setAlive(g, 2, 1);
    game.update();
    assert(getCell(game.getGrid(), 1, 1)->isAlive());
    std::cout << "[OK] Reproduction\n";
}

int main() {
    test_underpopulation();
    test_survival();
    test_overpopulation();
    test_reproduction();
    std::cout << "Tous les tests sont passes.\n";
    return 0;
}
