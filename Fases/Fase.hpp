#ifndef FASE_HPP
#define FASE_HPP

#include "../Estados/GameState.hpp"
#include "../GeradorMapa/TileGenerator.hpp"
#include "../Personagem/Player.hpp"
#include "../Enemy.hpp"
#include "../Personagem/Soldado.hpp"
#include "../Recursos/BarraMensagem/BarraMensagem.hpp"

class Fase : public GameState{
public:
    Fase(const std::string& levelName);
    virtual ~Fase() override;

    void processEvents(sf::RenderWindow & window, bool*) override = 0;
    void update(sf::Time deltaTime) override = 0;
    void render(sf::RenderWindow & window) override = 0;

    bool shouldContinue() const override;
    bool shouldExit() const override;

    TileGenerator* tileGen;
    void startSelection(sf::Vector2f&);
    void endSelection();

protected:
    sf::Font font;
    Enemy * enemy;
    std::string levelName;
    bool levelCompleted;
    bool exitGame;

    sf::RectangleShape selectionBox;
    sf::Vector2f selectionStart;
    void configureSelectionBox();
    void configureTileMap();
    bool isSelectingPlayer;
    void moveSelectedPlayers(sf::Vector2f& dest);
    void updateSelection(const sf::Vector2f& current);
    void updateViewSize(sf::View& view, sf::RenderWindow& window);
    bool isInside(const sf::FloatRect& selectionArea) const;
    sf::View view;
    sf::View uiView;
    void setViewSize(sf::View& _view, float ratio);
    sf::RenderWindow * window;
    std::vector<Player*> players;
    sf::Sprite spriteFundoNeon;
    sf::Text quantidadeNeon;
    sf::Texture texturaFundoNeon;
    sf::Text textoNeon;
    sf::Text valorNeon;
    sf::Sprite spriteMiniMapa;
    sf::Texture texturaMiniMapa;
    BarraMensagem barraMensagem;
};
#endif
