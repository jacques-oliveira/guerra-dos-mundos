#ifndef BOTAO_HPP
#define BOTAO_HPP

#include <SFML/Graphics.hpp>
#include <iostream>

class Botao : public sf::Drawable, public sf::Transformable{
public:
    Botao(float width, float height, const sf::Texture& texturaNormal, const sf::Texture& texturaSelecaoMouse, const sf::Texture& texturaSelecioando, std::string nomeBotao);
    ~Botao();
    void atualizar(sf::RenderWindow& window, sf::Event& event);
    void renderizar(sf::RenderWindow& window);
    sf::RectangleShape formaBotao;
    bool obterEventoBotao();
    std::string obterNomebotao();

private:
    virtual void draw(sf::RenderTarget & target, sf::RenderStates states) const override;
    const sf::Texture * texturaNormal;
    const sf::Texture * texturaSelecaoMouse;
    const sf::Texture * texturaSelecioando;
    bool cliqueEnter;
    std::string nomeBotao;
};
#endif
