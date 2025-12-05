#include "presentation/SFMLRenderer.hpp"
#include "domain/AliveCell.hpp"
#include "domain/DeadCell.hpp"
#include <iostream>

SFMLRenderer::SFMLRenderer(int width, int height, float size)
    : window(sf::VideoMode(width * size, height * size), "Game of Life"),
      cellSize(size),
      paused(false),
      stepOnce(false),
      speed(120)
{
    window.setFramerateLimit(60);

    if (!font.loadFromFile("DejaVuSans.ttf"))
        std::cerr << "Erreur : police introuvable.\n";

    hudText.setFont(font);
    hudText.setCharacterSize(18);
    hudText.setFillColor(sf::Color::White);
    hudText.setPosition(10.f, 10.f);

    if (!backgroundTexture.loadFromFile("data/backgrounds/background.png"))
    {
        std::cerr << "Erreur chargement background\n";
    }
    else
    {
        bg1.setTexture(backgroundTexture);
        bg2.setTexture(backgroundTexture);

        float scaleX = (width * size) / backgroundTexture.getSize().x;
        float scaleY = (height * size) / backgroundTexture.getSize().y;

        bg1.setScale(scaleX, scaleY);
        bg2.setScale(scaleX, scaleY);

        bg1.setPosition(0, 0);
        bg2.setPosition(backgroundTexture.getSize().x * scaleX, 0);
    }

    if (!music.openFromFile("data/audio/mario_theme.mp3"))
    {
        std::cerr << "Erreur : impossible de charger la musique.\n";
    }
    else
    {
        music.setLoop(true);
        music.setVolume(50);
        music.play();
    }
}

bool SFMLRenderer::isOpen() {
    return window.isOpen();
}

bool SFMLRenderer::handleEvents() {

    sf::Event event;
    while (window.pollEvent(event)) {

        if (event.type == sf::Event::Closed)
            return false;

        if (event.type == sf::Event::KeyPressed) {

            if (event.key.code == sf::Keyboard::Space)
                paused = !paused;

            if (event.key.code == sf::Keyboard::Right)
                speed = std::max(10, speed - 20);

            if (event.key.code == sf::Keyboard::Left)
                speed += 20;

            if (paused && event.key.code == sf::Keyboard::Enter)
                stepOnce = true;

            if (event.key.code == sf::Keyboard::M)
                music.setVolume(music.getVolume() == 0 ? 50 : 0);
        }

        if (event.type == sf::Event::MouseButtonPressed) {
            mousePressed = true;
            mouseButton = event.mouseButton.button;
        }

        if (event.type == sf::Event::MouseButtonReleased)
            mousePressed = false;
    }

    return true;
}

void SFMLRenderer::handleMouse(Grid* grid) {

    if (!mousePressed) return;

    sf::Vector2i pos = sf::Mouse::getPosition(window);

    int x = pos.x / cellSize;
    int y = pos.y / cellSize;

    if (x < 0 || x >= grid->getWidth()) return;
    if (y < 0 || y >= grid->getHeight()) return;

    if (mouseButton == sf::Mouse::Left)
        grid->setCell(x, y, std::make_unique<AliveCell>());

    if (mouseButton == sf::Mouse::Right)
        grid->setCell(x, y, std::make_unique<DeadCell>());
}

void SFMLRenderer::updateHUD(int iteration) {

    sf::Text shadow = hudText;
    shadow.move(1,1);
    shadow.setFillColor(sf::Color(0, 0, 0, 180));

    hudText.setString(
        "Iteration: " + std::to_string(iteration) +
        "\nSpeed: " + std::to_string(speed) +
        "\nPaused: " + (paused ? "YES" : "NO")
    );

    window.draw(shadow);
    window.draw(hudText);
}

void SFMLRenderer::drawCells(Grid* grid) {

    sf::RectangleShape rect(sf::Vector2f(cellSize - 1, cellSize - 1));

    for (int y = 0; y < grid->getHeight(); ++y) {
        for (int x = 0; x < grid->getWidth(); ++x) {

            rect.setPosition(x * cellSize, y * cellSize);

            if (!grid->getCell(x,y)->isAlive()) {
                rect.setFillColor(sf::Color::Transparent);
            } else {
                rect.setFillColor(sf::Color(255, 215, 0));
            }

            window.draw(rect);
        }
    }
}

void SFMLRenderer::render(Grid* grid, int iteration) {

    window.clear();

    window.draw(bg1);

    bgOffset -= 1.2f;

    float scaledWidth = backgroundTexture.getSize().x * bg1.getScale().x;

    if (bgOffset <= -scaledWidth)
        bgOffset
bg1.setPosition(bgOffset, 0);
bg2.setPosition(bgOffset + scaledWidth, 0);

window.draw(bg1);
window.draw(bg2);

    // --- GRILLE + CELLULES ---
    drawCells(grid);

    // --- HUD ---
    updateHUD(iteration);

    window.display();
}

