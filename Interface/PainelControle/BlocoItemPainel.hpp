#ifndef BLOCO_ITEM_PAINEL_HPP
#define BLOCO_ITEM_PAINEL_HPP

#include <iostream>
#include <SFML/Graphics.hpp>

class BlocoItemPainel : sf::Drawable{
public:
    BlocoItemPainel();
    virtual ~BlocoItemPainel() = default;

    unsigned short obterValorItem();
    unsigned short obterQuantidadeItem();
private:
    void inicializar();
    void draw(sf::RenderTarget & target, sf::RenderStates states) const override;
    void renderizar(sf::RenderWindow& window);
    sf::Texture texturaBloco;
    sf::Sprite spriteBloco;
    sf::Texture texturaItem;
    sf::Sprite spriteItem;
    unsigned short valorItem;
    unsigned short quantidadeItem;
    sf::Text textValorItem;
    sf::Text textQuantidadeItem;
    void carregarRecursos();
};
#endif
