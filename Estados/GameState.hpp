#ifndef GAME_STATE_HPP
#define GAME_STATE_HPP

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>

class GameState{
public:
    virtual ~GameState() = default;
    virtual void processEvents(sf::RenderWindow& window, bool * isRunning) = 0;
    virtual void update(sf::Time deltaTime) = 0;
    virtual void render(sf::RenderWindow& window) = 0;
    virtual bool shouldContinue() const = 0;
    virtual bool shouldExit() const = 0;

protected:
    sf::Music musicaAmbiente;
    void modoFullScreen(sf::RenderWindow& window, sf::View& view);
    void fatorEscala(sf::RenderWindow& window, sf::Sprite& sprite);
};
#endif



