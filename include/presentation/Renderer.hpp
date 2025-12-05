#pragma once

#include "domain/Grid.hpp"

class Renderer {
public:
    virtual ~Renderer() = default;
    virtual void render(Grid* grid, int iteration) = 0;
    virtual bool isOpen() = 0;
    virtual bool handleEvents() = 0;
};
