#ifndef MAIN_MENU_STATE_HPP
#define MAIN_MENU_STATE_HPP

#include "GameState.hpp"
#include <vector>
#include <string>
#include "../Interface/Botao.hpp"

class MainMenuState : public GameState{
public:
    MainMenuState(sf::RenderWindow* _window);
    ~MainMenuState();
    void processEvents(sf::RenderWindow & window, bool * isRunning) override;
    void update(sf::Time deltaTime) override;
    void render(sf::RenderWindow & window) override;
    bool shouldContinue() const override;
    bool shouldExit() const override;

private:
    sf::Font font;
    sf::Texture texturaTituloMenu;

    sf::Texture texturaPainelMenu;
    sf::Sprite spritePainelMenu;
    sf::Texture texturaBotaoJogarNormal;
    sf::Texture texturaBotaoJogarSelecionado;
    sf::Texture texturaBotaoSairNormal;
    sf::Texture texturaBotaoSairSelecionado;
    std::vector<sf::Text> options;
    int selectedOption;
    bool continueGame;
    bool exitGame;

    void updateOptionColors();
    void initMenu(sf::RenderWindow* _window);
    sf::Texture texturaAmbienteMenu;
    sf::Sprite spriteAmbienteMenu;
    unsigned short larguraTela;
    unsigned short alturaTela;
    std::vector<Botao*> botoes;
    void carregarRecursos();
    void tocarMusicaAmbiente();
    sf::View view;
};
#endif
