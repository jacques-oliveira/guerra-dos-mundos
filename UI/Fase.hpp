#ifndef FASE_HPP
#define FASE_HPP

#include "GameState.hpp"
#include "../TileGenerator.hpp"
#include "../Player.hpp"

class Fase : public GameState{
public:
    Fase(const std::string& levelName);
    ~Fase();

    void processEvents(sf::RenderWindow & window) override = 0;
    void update() override = 0;
    void render(sf::RenderWindow & window) override = 0;

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
    std::string levelName;
    bool levelCompleted;
    bool  exitGame;

    sf::RectangleShape selectionBox;
    sf::Vector2f selectionStart;
    void configureSelectionBox();
    void configureTileMap();
    bool isSelectingPlayer;
    void moveSelectedPlayers(sf::Vector2f& dest);
    void updateSelection(const sf::Vector2f& current);
    void updateViewSize(sf::View&, sf::RenderWindow&);
    bool isRunning;

};
#endif
