#ifndef BARRA_MENSAGEM_HPP
#define BARRA_MENSAGEM_HPP

#include <istream>
#include <SFML/Graphics.hpp>

class BarraMensagem : sf::Drawable{

public:
    BarraMensagem();
    virtual ~BarraMensagem() = default;
    std::string textoMensagem;
    void render(sf::RenderWindow& window);
private:
    void draw(sf::RenderTarget & target, sf::RenderStates states) const override;
    sf::Text mensagem;
    sf::Text tituloMensagem;
};
#endif
