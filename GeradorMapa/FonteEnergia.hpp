#ifndef FONTE_ENERGIA_HPP
#define FONTE_ENERGIA_HPP

#include <iostream>
#include <SFML/Graphics.hpp>
#include "../Animacao/Animacao.hpp"

class FonteEnergia{
public:
    FonteEnergia(float posx, float posy, int energiaFonte);
    virtual ~FonteEnergia() = default;
    void iniciar();
    void processarEventos();
    void atualizar();
    void renderizar(sf::RenderWindow& window);

private:
    int energiaFonte;
    sf::Texture texturaCristalNegro;
    sf::Sprite spriteCristalNegro;
    sf::Vector2f posicao;
    std::vector<Animacao> animacoes;
    void carregarAnimacao(Animacao& animacao, int quantidadeFrames, int linha);
};
#endif
