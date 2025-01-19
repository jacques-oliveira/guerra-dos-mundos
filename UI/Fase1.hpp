#ifndef FASE_HPP
#define FASE_HPP

#include "GameState.hpp"
#include "../Player.hpp"

class Fase1 : public GameState{
public:
    Fase1(const std::string& levelName);
    ~Fase1() override = default;

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
