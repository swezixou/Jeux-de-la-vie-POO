#pragma once 

class Cell;

class Rule {
public:
    virtual ~Rule() = default;
    virtual Cell* apply(Cell* current, int aliveNeighbors) const = 0;
};
