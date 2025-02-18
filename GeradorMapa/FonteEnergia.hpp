#ifndef FONTE_ENERGIA_HPP
#define FONTE_ENERGIA_HPP

#include <iostream>
#include <SFML/Graphics.hpp>
#include "../Animation/Animation.hpp"

class FonteEnergia{
public:
    FonteEnergia(float posx, float posy, float energiaFonte);
    ~FonteEnergia();
    void iniciar();
    void processarEventos();
    void atualizar();
    void renderizar();

private:
    float energiaFonte;
    sf::Texture texturaCristalNegro;
    sf::Sprite spriteCristalNegro;
    sf::Vector2f posicao;
    std::vector<Animation> animacoes;
    void carregarAnimacao(Animation& animacao, int quantidadeFrames, int linha);
};
#endif
