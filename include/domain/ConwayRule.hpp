#pragma once 
#include "Cell.hpp"
#include "Rule.hpp"
#include "AliveCell.hpp"
#include "DeadCell.hpp"

class ConwayRule : public Rule {
public:
        Cell* apply(Cell* current, int aliveNeighbours) const override {
        bool alive = current->isAlive();

        if (alive) {
            if (aliveNeighbours == 2 || aliveNeighbours == 3)
                return new AliveCell();
            else
                return new DeadCell();
        } else {
            if (aliveNeighbours == 3)
                return new AliveCell();
            else
                return new DeadCell();
        }
    }
};
