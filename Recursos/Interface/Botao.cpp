#include "Botao.hpp"

Botao::Botao(float width, float height, const sf::Texture& texturaNormal, const sf::Texture& texturaSelecaoMouse, const sf::Texture& texturaSelecioando,std::string nomeBotao) : texturaNormal(&texturaNormal), texturaSelecaoMouse(&texturaSelecaoMouse), texturaSelecioando(&texturaSelecioando),nomeBotao(nomeBotao)
{
    try{
        formaBotao.setSize(sf::Vector2f(width, height));
        formaBotao.setTexture(&texturaNormal);
        formaBotao.setOrigin(formaBotao.getSize().x/2, formaBotao.getSize().y/2);
        cliqueEnter = false;
    }catch(std::exception e){
        std::cerr<<"Erro ao carregar botão menu"<<e.what()<<std::endl;
    }
}

Botao::~Botao(){

}

void Botao::atualizar(sf::RenderWindow& window, sf::Event& event){
    try{
        sf::Vector2i posicaoMouse = sf::Mouse::getPosition(window);
        sf::FloatRect limites = getTransform().transformRect(formaBotao.getGlobalBounds());


        if(limites.contains(posicaoMouse.x, posicaoMouse.y)){
            formaBotao.setTexture(texturaSelecaoMouse);
        }else{
            formaBotao.setTexture(texturaNormal);
        }

        if( (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) ||
            (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)) &&
            limites.contains(posicaoMouse.x, posicaoMouse.y)){
            formaBotao.setTexture(texturaSelecioando);
            cliqueEnter = true;

        }
    }catch(std::exception& e){
        std::cerr<<"Erro ao atualizar botão menu"<<e.what()<<std::endl;
    }
}

void Botao::draw(sf::RenderTarget& target, sf::RenderStates states) const{
    try{
        states.transform *= getTransform();
        target.draw(formaBotao,states);
    }catch(std::exception& e){
        std::cerr<<"Erro ao desenhar botão menu"<<e.what()<<std::endl;
    }
}

void Botao::renderizar(sf::RenderWindow& window){
    try{
        window.draw(*this);

    }catch(std::exception& e){
        std::cerr<<"Erro ao renderizar botão menu"<<e.what()<<std::endl;
    }
}

bool Botao::obterEventoBotao(){
    return cliqueEnter;
}

std::string Botao::obterNomebotao(){
    return nomeBotao;
}



