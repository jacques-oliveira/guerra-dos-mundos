#ifndef GAME_STATE_HPP
#define GAME_STATE_HPP

#include <SFML/Graphics.hpp>

class GameState{
public:
    virtual ~GameState() = default;
    virtual void processEvents(sf::RenderWindow& window) = 0;
    virtual void update(sf::Time deltaTime) = 0;
    virtual void render(sf::RenderWindow& window) = 0;
    virtual bool shouldContinue() const = 0;
    virtual bool shouldExit() const = 0;
private:
};
#endif



