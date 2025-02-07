#ifndef GAMEOVER_STATE_HPP
#define GAMEOVER_STATE_HPP
#include "../Estados/GameState.hpp"


class GameOverState : public GameState{
public:
    GameOverState();
    virtual ~GameOverState() = default;

    void processEvents(sf::RenderWindow & window, bool*) override;
    void update(sf::Time deltaTime) override;
    void render(sf::RenderWindow & window) override;
private:
    bool shouldContinue() const override;
    bool shouldExit() const override;
};
#endif
