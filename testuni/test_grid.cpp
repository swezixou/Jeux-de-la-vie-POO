#include <cassert>
#include <iostream>
#include "../include/Game.hpp"
#include "../include/AliveCell.hpp"
#include "../include/DeadCell.hpp"

void setAlive(Grid& g, int x, int y) {
  g.setCell(x, y, new AliveCell());
}
void setDead(Grid& g, int x, int y) {
   g.setCell(x, y, new DeadCell());
}

void test_underpopulation() {
    Game game(3, 3);
    setAlive(game.getGrid(), 1, 1);
    game.update();
    assert(!game.getGrid().getCell(1, 1)->isAlive());
    std::cout << "[OK] Sous-population.\n";
}
void test_overpopulation() {
    Game game(3, 3);
    setAlive(game.getGrid(), 1, 1);
    setAlive(game.getGrid(), 0, 1);
    setAlive(game.getGrid(), 2, 1);
    setAlive(game.getGrid(), 1, 0);
    setAlive(game.getGrid(), 1, 2);
    game.update();
    assert(!game.getGrid().getCell(1, 1)->isAlive());
    std::cout << "[OK] Surpopulation.\n";
}
void test_birth() {
    Game game(3, 3);
    setAlive(game.getGrid(), 1, 0);
    setAlive(game.getGrid(), 0, 1);
    setAlive(game.getGrid(), 2, 1);
    game.update();
    assert(game.getGrid().getCell(1, 1)->isAlive());
    std::cout << "[OK] N

