#ifndef BARRA_MENSAGEM_HPP
#define BARRA_MENSAGEM_HPP

#include <iostream>
#include <SFML/Graphics.hpp>

class BarraMensagem : sf::Drawable{

public:
    BarraMensagem();
    virtual ~BarraMensagem() = default;
    std::wstring stringMensagem;
    void render(sf::RenderWindow& window);
    void atribuirFonte(sf::Font& fonte);
    void atribuirPosicao(float posx, float posy, float tamanhoRetangulo);
    sf::Text textMensagem;
    sf::Text tituloMensagem;
private:
    void draw(sf::RenderTarget & target, sf::RenderStates states) const override;
    sf::CircleShape csEsquerdo, csDireito;
    sf::RectangleShape retanguloFundo;
    float tamanhoFonte;
};
#endif
