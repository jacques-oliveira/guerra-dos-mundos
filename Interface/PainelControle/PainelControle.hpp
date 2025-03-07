#ifndef PAINEL_CONTROLE_HPP
#define PAINEL_CONTROLE_HPP

#include <iostream>
#include <SFML/Graphics.hpp>
#include "../Botao.hpp"
#include "../Interface.hpp"
#include "BlocoItemPainel.hpp"
#include "../RelogioPlaneta/RelogioPlaneta.hpp"

class PainelControle : sf::Drawable{

public:
    PainelControle();
    virtual ~PainelControle() = default;
    void renderizar(sf::RenderWindow& window);
    void atribuirPosicao(float posx, float posy);
    sf::Vector2f obterPosicaoPainel();
    void atribuirFonte(sf::Font& fonte);
    void criandoItemsPainel();
    sf::RectangleShape areaAnulaMoverView;
private:
    int valorNeon;
    short numeroDia;
    sf::Sprite spriteFundoPainel;
    sf::Texture texturaFundoPainel;
    sf::Sprite spriteComandante;
    sf::Texture texturaComandante;
    sf::Texture texturaNeonPainel;
    sf::Sprite spriteNeonPainel;
    sf::Text textValorNeon;
    sf::Text textTituloNeon;
    void inicializarPainel();
    void draw(sf::RenderTarget & target, sf::RenderStates states) const override;
    std::vector<Botao*> botoes;
    sf::Texture texturaBotaoNormal;
    sf::Texture texturaBotaoSelecionado;
    std::vector<BlocoItemPainel*> blocosItemPainel;
    sf::Texture texturaBlocoItem;
    RelogioPlaneta relogioPlaneta;
    std::vector<Botao*> botoesOperacao;
    sf::Texture texturaBotaoOperacaoNormal;
    sf::Texture texturaBotaoOperacaoSelecionado;
};
#endif
