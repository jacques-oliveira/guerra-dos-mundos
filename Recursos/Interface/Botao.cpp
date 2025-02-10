#include "Botao.hpp"

Botao::Botao(float width, float height, const sf::Texture& texturaNormal, const sf::Texture& texturaSelecaoMouse, const sf::Texture& texturaSelecioando) : texturaNormal(&texturaNormal), texturaSelecaoMouse(&texturaSelecaoMouse), texturaSelecioando(&texturaSelecioando)
{
    formaBotao.setSize(sf::Vector2f(width, height));
    formaBotao.setTexture(&texturaNormal);
    formaBotao.setOrigin(formaBotao.getSize().x/2, formaBotao.getSize().y/2);
}

Botao::~Botao(){
}

void Botao::atualizar(sf::RenderWindow& window){
    sf::Vector2i posicaoMouse = sf::Mouse::getPosition(window);
    sf::FloatRect limites = getTransform().transformRect(formaBotao.getGlobalBounds());


    if(limites.contains(posicaoMouse.x, posicaoMouse.y)){
        formaBotao.setTexture(texturaSelecaoMouse);
        std::cout<<"textura seleção"<<std::endl;
    }else{
        formaBotao.setTexture(texturaNormal);
        std::cout<<"textura normal"<<std::endl;
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && limites.contains(posicaoMouse.x, posicaoMouse.y)){
        formaBotao.setTexture(texturaSelecioando);
        std::cout<<"atualizando"<<std::endl;
    }

}

void Botao::draw(sf::RenderTarget& target, sf::RenderStates states) const{
    states.transform *= getTransform();
    target.draw(formaBotao,states);
}

void Botao::renderizar(sf::RenderWindow& window){
    window.draw(*this);
}



