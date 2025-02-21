#include "GameState.hpp"

void GameState::modoFullScreen(sf::RenderWindow& window, sf::View& view){
    float aspectoJanela = window.getSize().x / static_cast<float>(window.getSize().y);
    float aspectoView = view.getSize().x / static_cast<float>(view.getSize().y);
    float tamanhoX = 1;
    float tamanhoY = 1;
    float posX = 0;
    float posY = 0;

    bool espacoHorizontal = aspectoJanela < aspectoView;
    if(espacoHorizontal){
        tamanhoX = aspectoJanela / aspectoView;
        posX = (1 - tamanhoX) / 2.f;
    }else {
        tamanhoY = aspectoView / aspectoJanela;
        posY = (1 - tamanhoY) / 2.f;
    }
    view.setViewport(sf::FloatRect(posX, posY, tamanhoX, tamanhoY));
    window.setView(view);
}

void GameState::fatorEscala(sf::RenderWindow& window, sf::Sprite& sprite){
    float aspectoX = (sprite.getTexture()->getSize().x /static_cast<float>(window.getSize().x));
    float escalaX = aspectoX + 1;
    float aspectoY = (sprite.getTexture()->getSize().y / static_cast<float>(window.getSize().y));
    float escalaY = aspectoY +1 ;
    float escala = std::min(escalaX, escalaY);
    if(aspectoX < 1 && aspectoY < 1 ){
        sprite.setScale(escala, escala);
    }
}

