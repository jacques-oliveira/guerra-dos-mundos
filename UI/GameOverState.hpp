#ifndef GAMEOVER_STATE_HPP
#define GAMEOVER_STATE_HPP

#include "GameState.hpp"

class GameOverState : public GameState{
public:
    GameOverState();
    virtual ~GameOverState() = default;

    void processEvents(sf::RenderWindow & window) override;
    void update(sf::Time deltaTime) override;
    void render(sf::RenderWindow & window) override;
private:
    bool shouldContinue() const override;
    bool shouldExit() const override;
};
#endif
