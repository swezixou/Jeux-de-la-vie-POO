#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "presentation/Renderer.hpp"
#include "domain/Grid.hpp"

class SFMLRenderer : public Renderer {

private:
    sf::RenderWindow window;
    float cellSize;

    sf::Font font;
    sf::Text hudText;

    bool mousePressed = false;
    sf::Mouse::Button mouseButton;

    
    sf::Texture backgroundTexture;
    sf::Sprite bg1, bg2;
    float bgOffset = 0;

    sf::Music music;

public:
    bool paused;
    bool stepOnce;
    int speed;

    SFMLRenderer(int width, int height, float size);

    bool isOpen() override;
    bool handleEvents() override;
    void render(Grid* grid, int iteration) override;

private:
    void updateHUD(int iteration);
    void handleMouse(Grid* grid);
    void drawCells(Grid* grid);
};
