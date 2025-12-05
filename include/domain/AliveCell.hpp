#pragma once 
#include "Cell.hpp"

class AliveCell : public Cell {
public:
    bool isAlive() const override {
        return true;
    }
    Cell* clone() const override {
        return new AliveCell(*this);
    }
};
