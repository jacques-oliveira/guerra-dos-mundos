#ifndef RELOGIO_PLANETA_HPP
#define RELOGIO_PLANETA_HPP

#include <iostream>
#include <SFML/Graphics.hpp>

class RelogioPlaneta : public sf::Drawable{

public:
    RelogioPlaneta();
    virtual ~RelogioPlaneta() = default;

    void inicializar();
    void renderizar(sf::RenderWindow& window);

private:
    sf::Texture texturaTempo;
    sf::Sprite spriteTempo;
    sf::Text textNumeroDia;
    unsigned short numeroDia;
    sf::Font fonte;
    void draw(sf::RenderTarget & target, sf::RenderStates states) const override;

};
#endif
