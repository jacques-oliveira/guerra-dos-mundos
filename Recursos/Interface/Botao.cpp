#include "Botao.hpp"

Botao::Botao(float width, float height, const sf::Texture& texturaNormal, const sf::Texture& texturaSelecaoMouse, const sf::Texture& texturaSelecioando,sf::Text textoBotao)
{
    formaBotao.setSize(sf::Vector2f(width, height));
    formaBotao.setTexture(&texturaNormal);

    this->texturaNormal = &texturaNormal;
    this->texturaSelecaoMouse = &texturaSelecaoMouse;
    this->texturaSelecioando = &texturaSelecioando;
    this->textoBotao = textoBotao;
}

Botao::~Botao(){
}

void Botao::atualizar(sf::RenderWindow& window){
    sf::Vector2i posicaoMouse = sf::Mouse::getPosition(window);
    sf::FloatRect limites = formaBotao.getGlobalBounds();

    if(limites.contains(posicaoMouse.x, posicaoMouse.y)){
        formaBotao.setTexture(texturaSelecaoMouse);
    }else{
        formaBotao.setTexture(texturaNormal);
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && limites.contains(posicaoMouse.x, posicaoMouse.y)){
        formaBotao.setTexture(texturaSelecioando);
    }

}

void Botao::draw(sf::RenderTarget& target, sf::RenderStates states) const{
    states.transform *= getTransform();
    target.draw(formaBotao,states);
    target.draw(textoBotao);
}

void Botao::renderizar(sf::RenderWindow& window){
    draw(window, sf::RenderStates::Default);
}



