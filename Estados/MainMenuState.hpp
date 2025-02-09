#ifndef MAIN_MENU_STATE_HPP
#define MAIN_MENU_STATE_HPP

#include "GameState.hpp"
#include <vector>
#include <string>

class MainMenuState : public GameState{
public:
    MainMenuState();
    ~MainMenuState() override = default;
    void processEvents(sf::RenderWindow & window, bool * isRunning) override;
    void update(sf::Time deltaTime) override;
    void render(sf::RenderWindow & window) override;
    bool shouldContinue() const override;
    bool shouldExit() const override;

private:
    sf::Font font;
    sf::Font fontSubMenu;
    sf::Text subTitulo;
    sf::Text motivoTitulo;
    sf::Texture texturaTituloMenu;
    sf::Sprite spriteTituloMenu;
    sf::Texture texturaPainelMenu;
    sf::Sprite spritePainelMenu;

    std::vector<sf::Text> options;
    int selectedOption;
    bool continueGame;
    bool exitGame;

    void updateOptionColors();
    void initMenu();
    sf::Texture texturaAmbienteMenu;
    sf::Sprite spriteAmbienteMenu;
    unsigned short larguraTela;
    unsigned short alturaTela;

};
#endif
