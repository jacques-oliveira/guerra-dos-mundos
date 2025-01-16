#pragma once

#include <stdio.h>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "Player.hpp"
#include "TileGenerator.hpp"
#include "Enemy.hpp"

using namespace std;

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
    TileGenerator* tileGen;
    void setSelected(bool);
    void startSelection(sf::Vector2f&);
    void endSelection();

private:
    void processEvents();
    void update(sf::Time deltaTime);
    void render();
    sf::RenderWindow* _window;
    sf::View view;
    bool isSelectingPlayer;
    sf::RectangleShape selectionBox;
    sf::Vector2f selectionStart;
    void updateSelection(const sf::Vector2f& current);
    bool isInside(const sf::FloatRect& selectionArea) const;
    void moveSelectedPlayers(sf::Vector2f&);
    void configureSelectionBox();
    void configureTileMap();
};
