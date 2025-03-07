#pragma once

#include <stdio.h>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "../Personagem/Player.hpp"
#include "../GeradorMapa/TileGenerator.hpp"
#include "../Enemy.hpp"
#include "../Estados/GameState.hpp"
#include "../Estados/MainMenuState.hpp"
#include "../Fases/Fase1.hpp"
#include <memory>

#include <stack>

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
    void update(sf::Time deltaTime);
    void render(GameState&);
    sf::RenderWindow* _window;
    std::stack<std::unique_ptr<GameState>> states;
    void changeState(std::unique_ptr<GameState> newState);
    void processStateChanges();
    void handleStateChanges();
    bool * isRunning;
    const short frame_per_seconds;
};
