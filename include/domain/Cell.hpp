#pragma once

class Cell {
public:
    virtual ~Cell() = default;

    virtual bool isAlive() const = 0;
    virtual Cell* clone() const = 0;
};
