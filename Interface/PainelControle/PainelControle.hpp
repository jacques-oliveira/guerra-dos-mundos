#ifndef PAINEL_CONTROLE_HPP
#define PAINEL_CONTROLE_HPP

#include <iostream>
#include <SFML/Graphics.hpp>

class PainelControle : sf::Drawable{

public:
    PainelControle();
    virtual ~PainelControle() = default;
    void renderizar(sf::RenderWindow& window);
    void atribuirPosicao(float posx, float posy);
    sf::Vector2f obterPosicaoPainel();
private:
    float valorNeon;
    short numeroDia;
    sf::Sprite spriteFundoPainel;
    sf::Texture texturaFundoPainel;
    void inicializarPainel();
    void draw(sf::RenderTarget & target, sf::RenderStates states) const override;
};
#endif
