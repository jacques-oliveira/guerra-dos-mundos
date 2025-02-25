#include "Botao.hpp"

Botao::Botao(float width, float height, const sf::Texture& texturaNormal, const sf::Texture& texturaSelecaoMouse, const sf::Texture& texturaSelecionado,std::wstring nomeBotao) : texturaNormal(&texturaNormal), texturaSelecaoMouse(&texturaSelecaoMouse), texturaSelecionado(&texturaSelecionado),nomeBotao(nomeBotao)
{
    try{
        formaBotao.setSize(sf::Vector2f(width, height));
        formaBotao.setTexture(&texturaNormal);
        formaBotao.setOrigin(formaBotao.getLocalBounds().left + formaBotao.getGlobalBounds().width/2, formaBotao.getLocalBounds().height/2);

        cliqueEnter = false;
        if(!fonteBotao.loadFromFile("Recursos/Fonts/TrulyMadlyDpad-a72o.ttf")){
            std::cerr<<"Erro ao carregar fonte botão"<<std::endl;
        }
        textoBotao.setFont(fonteBotao);
        textoBotao.setCharacterSize(34);
        textoBotao.setString(nomeBotao);
        textoBotao.setOrigin(textoBotao.getLocalBounds().left + textoBotao.getGlobalBounds().width/2, textoBotao.getLocalBounds().height/2);
        textoBotao.setPosition(formaBotao.getPosition().x, formaBotao.getPosition().y-textoBotao.getGlobalBounds().height/2);
    }catch(std::exception e){
        std::cerr<<"Erro ao carregar botão menu"<<e.what()<<std::endl;
    }
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
            formaBotao.setTexture(texturaSelecionado);
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
        target.draw(textoBotao,states);
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

std::wstring Botao::obterNomebotao(){
    return nomeBotao;
}

void Botao::atribuirPosicao(float posx, float posy){
    formaBotao.setPosition(posx,posy);
    textoBotao.setPosition(formaBotao.getGlobalBounds().left + formaBotao.getGlobalBounds().width/2 , formaBotao.getGlobalBounds().getPosition().y + textoBotao.getGlobalBounds().height/2);
}


