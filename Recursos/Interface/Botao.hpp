#ifndef BOTAO_HPP
#define BOTAO_HPP

#include <SFML/Graphics.hpp>

class Botao : public sf::Drawable, public sf::Transformable{
public:
    Botao(float width, float height, const sf::Texture& texturaNormal, const sf::Texture& texturaSelecaoMouse, const sf::Texture& texturaSelecioando);
    ~Botao();
    void atualizar(sf::RenderWindow& window);
private:
    virtual void draw(sf::RenderTarget & target, sf::RenderStates states) const override;
    sf::RectangleShape formaBotao;
    const sf::Texture * texturaNormal;
    const sf::Texture * texturaSelecaoMouse;
    const sf::Texture * texturaSelecioando;
};
#endif
