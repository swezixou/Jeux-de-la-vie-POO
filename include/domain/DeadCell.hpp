#pragma once
#include "Cell.hpp"

class DeadCell : public Cell {
public:
    bool isAlive() const override {
        return false;
    }
    Cell* clone() const override {
        return new DeadCell(*this);;
    }
};
