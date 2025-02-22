#include "BarraMensagem.hpp"

BarraMensagem::BarraMensagem(){
    try{
        tituloMensagem.setString("Mensagem: ");
        stringMensagem = "Sua missão começou, nos orgulhe!";
        tituloMensagem.setPosition(200,100);
        textMensagem.setPosition(250,100);
    }catch(std::exception& e){
        std::cerr<<"Falha ao carregar barra de mensagem"<<e.what()<<std::endl;
    }
}

void BarraMensagem::draw(sf::RenderTarget& target, sf::RenderStates states) const{
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
    }catch(std::exception& e){
        std::cerr<<"Falha ao atriubuir Fonte a Barra de Mensagem"<<e.what()<<std::endl;
    }
}



