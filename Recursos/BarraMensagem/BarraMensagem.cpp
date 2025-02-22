#include "BarraMensagem.hpp"

BarraMensagem::BarraMensagem(){
    tituloMensagem.setString("Mensagem: ");
    textoMensagem = "Sua missão começou, nos orgulhe!";
}

void BarraMensagem::draw(sf::RenderTarget& target, sf::RenderStates states) const{
    target.draw(tituloMensagem,sf::RenderStates::Default);
    target.draw(mensagem,sf::RenderStates::Default);
}

void BarraMensagem::render(sf::RenderWindow& window){
    draw(window, sf::RenderStates::Default);
}


