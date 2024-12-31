#pragma once

#include <stdio.h>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

class Game{

public :
    Game(const Game&) = delete;
    Game& operator = (const Game&) = delete;

    Game();
    ~Game();

    void run(int frame_per_seconds);
    void clean();

private:
    void processEvents();
    void update(sf::Time deltaTime);
    void render();

    sf::RenderWindow _window;
};
