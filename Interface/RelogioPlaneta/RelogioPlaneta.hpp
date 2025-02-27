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
    void atribuirPosicao(float posx, float posy);
    sf::Vector2f dimensaoSpriteTempo();
private:
    sf::Texture texturaDia;
    sf::Texture texturaNoite;
    sf::Sprite spriteTempo;
    sf::Text textNumeroDia;
    unsigned short numeroDia;
    sf::Font fonte;
    void draw(sf::RenderTarget & target, sf::RenderStates states) const override;
    void atribuirFonte(sf::Font& fonte);
};
#endif
