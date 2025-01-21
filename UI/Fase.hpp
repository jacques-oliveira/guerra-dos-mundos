#ifndef FASE_HPP
#define FASE_HPP

#include "GameState.hpp"
#include "../TileGenerator.hpp"
#include "../Player.hpp"

class Fase : public GameState{
public:
    Fase(const std::string& levelName);
    virtual ~Fase() = default;

    void processEvents(sf::RenderWindow & window) override;
    void update() override;
    void render(sf::RenderWindow & window) override;
    TileGenerator* tileGen;
    virtual void setSelected(bool) = 0;
    virtual void startSelection(sf::Vector2f&) = 0;
    virtual void endSelection() = 0;

protected:
    sf::Font font;
    sf::Text levelText;
    Player* player;
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
