#ifndef FASE_HPP
#define FASE_HPP

#include "GameState.hpp"
#include "../Player.hpp"
#include "../TileGenerator.hpp"

class Fase1 : public GameState{
public:
    Fase1(const std::string& levelName);
    ~Fase1() override = default;

    void processEvents(sf::RenderWindow & window) override;
    void update() override;
    void render(sf::RenderWindow & window) override;

    bool shouldContinue() const override;
    bool shouldExit() const override;

    TileGenerator* tileGen;
    void setSelected(bool);
    void startSelection(sf::Vector2f&);
    void endSelection();

protected:
    sf::Font font;
    sf::Text levelText;
    Player* player;
    bool levelCompleted;
    bool exitGame;

    sf::RectangleShape selectionBox;
    sf::Vector2f selectionStart;
    void configureSelectionBox();
    bool isSelectingPlayer;
    void moveSelectedPlayers(sf::Vector2f& dest);
    void updateSelection(const sf::Vector2f& current);
    void updateViewSize(sf::View&, sf::RenderWindow&);
    bool isRunning;
};
#endif
