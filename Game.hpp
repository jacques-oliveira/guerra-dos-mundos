#pragma once

#include <stdio.h>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "Player.hpp"
#include "TileGenerator.hpp"
#include "Enemy.hpp"

class Game{

public :
    Game(const Game&) = delete;
    Game& operator = (const Game&) = delete;

    Game();
    ~Game();

    void run(int frame_per_seconds);
    void clean();
    Player* _player;
    Enemy* _enemy;
    sf::Sprite envSprite;
    TileGenerator tileGen;

private:
    void processEvents();
    void update(sf::Time deltaTime);
    void render();

    sf::RenderWindow _window;
    sf::View view;
};
