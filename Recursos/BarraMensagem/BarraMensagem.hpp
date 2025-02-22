#ifndef BARRA_MENSAGEM_HPP
#define BARRA_MENSAGEM_HPP

#include <iostream>
#include <SFML/Graphics.hpp>

class BarraMensagem : sf::Drawable{

public:
    BarraMensagem();
    virtual ~BarraMensagem() = default;
    std::string stringMensagem;
    void render(sf::RenderWindow& window);
    void atribuirFonte(sf::Font& fonte);
    sf::Text textMensagem;
    sf::Text tituloMensagem;
private:
    void draw(sf::RenderTarget & target, sf::RenderStates states) const override;
};
#endif
