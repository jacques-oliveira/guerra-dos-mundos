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

    void run();
    void clean();

private:
    void processEvents();
    void update();
    void render();

    sf::RenderWindow _window;
};
