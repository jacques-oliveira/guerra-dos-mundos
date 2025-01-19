#ifndef PLAY_STATE_HPP
#define PLAY_STATE_HPP

#include "GameState.hpp"
#include "../Player.hpp"

class PlayState : public GameState{
public:
    PlayState(const std::string& levelName);
    ~PlayState() override = default;

    void processEvents(sf::RenderWindow & window) override;
    void update() override;
    void render(sf::RenderWindow & window) override;

    bool shouldContinue() const override;
    bool shouldExit() const override;


protected:
    sf::Font font;
    sf::Text levelText;
    Player player;
    bool levelCompleted;
    bool exitGame;
};
#endif
