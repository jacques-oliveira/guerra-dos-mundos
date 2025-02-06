#ifndef PERSONAGEM_HPP
#define PERSONAGEM_HPP

#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include "../Animation/Animation.hpp"
#include "../Player/PlayerState.hpp"
#include "../Player/HeathBar.hpp"

using namespace std;

class Character : public sf::Drawable{

public:
    Character();
    ~Character();

    string patente;
    sf::CircleShape circuloSelecao;
    void atualizar(sf::Time deltaTime);
    void processarEventos();
    const sf::Sprite& obterSprite() const;
    bool intersecaoAreaSelecionada(const sf::FloatRect& areaSelecao) const;
    void selecionar(bool);
    bool verificarSelecao();
    void deselecionar();
    void atribuirPosicaoDestino(sf::Vector2f& posicao);
    void mover();
    void renderizar();
    float obterBarraVida();
private:
    float valorBarraVida;
    virtual void draw(sf::RenderTarget& objetoRender, sf::RenderStates estados) const override;
    sf::Sprite sprite;
    sf::Texture textura;
    float velocidade;
    bool moverCima, moverBaixo,moverEsquerda, moverDireita;
    bool selecionado;
    sf::Vector2f posicaoDestino;
    void atualizarPosicao();
    void movimentoFormaSelecao();
    std::vector<Animation> animacoes;
    void carregarAnimacao(Animation& animacao, int quantidadeFrames, int linha);
    void atribuirEstado(PlayerState estado);
    sf::Texture texturaAnimacoes;
    PlayerState estadoAtual;
    HealthBar * barraVida;
    void iniciarPersonagem(float posx, float posy);
    sf::Vector2f posicaoAnterior;
};
#endif
