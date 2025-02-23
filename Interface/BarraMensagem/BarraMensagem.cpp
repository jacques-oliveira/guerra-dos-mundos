#include "BarraMensagem.hpp"

BarraMensagem::BarraMensagem(){
    try{
        tituloMensagem.setString("Mensagem: ");
        stringMensagem = L"Sua missão começou, nos orgulhe ! . . .";
        csEsquerdo.setFillColor(sf::Color::Black);
        csDireito.setFillColor(sf::Color::Black);
        retanguloFundo.setFillColor(sf::Color::Black);
        tamanhoFonte = 20.f;

    }catch(std::exception& e){
        std::cerr<<"Falha ao carregar barra de mensagem"<<e.what()<<std::endl;
    }
}

void BarraMensagem::draw(sf::RenderTarget& target, sf::RenderStates states) const{
    target.draw(csEsquerdo,sf::RenderStates::Default);
    target.draw(retanguloFundo,sf::RenderStates::Default);
    target.draw(csDireito,sf::RenderStates::Default);

    target.draw(tituloMensagem,sf::RenderStates::Default);
    target.draw(textMensagem,sf::RenderStates::Default);
}

void BarraMensagem::render(sf::RenderWindow& window){
    draw(window, sf::RenderStates::Default);
}

void BarraMensagem::atribuirFonte(sf::Font& fonte){
    try{
        textMensagem.setFont(fonte);
        tituloMensagem.setFont(fonte);
        textMensagem.setString(stringMensagem);
        textMensagem.setFillColor(sf::Color::Yellow);
        tituloMensagem.setCharacterSize(tamanhoFonte);
        textMensagem.setCharacterSize(tamanhoFonte);
    }catch(std::exception& e){
        std::cerr<<"Falha ao atriubuir Fonte a Barra de Mensagem"<<e.what()<<std::endl;
    }
}

void BarraMensagem::atribuirPosicao(float posx, float posy, float tamanhoRetangulo){
    try{
        csEsquerdo.setRadius(15);
        csDireito.setRadius(15);
        retanguloFundo.setSize(sf::Vector2f(tamanhoRetangulo*0.45f,csEsquerdo.getRadius() * 2));

        csEsquerdo.setPosition(posx,posy);
        retanguloFundo.setPosition(posx + csEsquerdo.getRadius(), posy);
        csDireito.setPosition(csEsquerdo.getPosition().x + retanguloFundo.getGlobalBounds().width, posy);
        std::cout<<retanguloFundo.getGlobalBounds().width<<std::endl;
        tituloMensagem.setOrigin(tituloMensagem.getLocalBounds().left, tituloMensagem.getLocalBounds().height/2);
        tituloMensagem.setPosition(posx + csEsquerdo.getRadius(),
                                   posy + tamanhoFonte/2);
        textMensagem.setOrigin(textMensagem.getLocalBounds().left, textMensagem.getLocalBounds().height/2);
        textMensagem.setPosition(posx + tituloMensagem.getGlobalBounds().width + 24.f, tituloMensagem.getPosition().y);
    }catch(std::exception& e){
        std::cerr<<"Falha ao atriubuir posição a Barra de Mensagem"<<e.what()<<std::endl;
    }
}
