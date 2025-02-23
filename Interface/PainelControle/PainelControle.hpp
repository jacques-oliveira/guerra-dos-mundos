#ifndef PAINEL_CONTROLE_HPP
#define PAINEL_CONTROLE_HPP

#include <iostream>
#include <SFML/Graphics.hpp>

class PainelControle : sf::Drawable{

public:
    PainelControle();
    virtual ~PainelControle() = default;
private:
    float valorNeon;
    short numeroDia;
    sf::Sprite spriteFundoPainel;
    void inicializarPainel();
    void draw(sf::RenderTarget & target, sf::RenderStates states) const override;
    void atribuirPosicao(float posx, float posy);
};
#endif
