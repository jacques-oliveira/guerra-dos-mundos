#include "RelogioPlaneta.hpp"

RelogioPlaneta::RelogioPlaneta(){

}

void RelogioPlaneta::inicializar(){
    numeroDia = 0;
}

void RelogioPlaneta::draw(sf::RenderTarget& target, sf::RenderStates states) const{
    target.draw(spriteTempo);
    target.draw(textNumeroDia);
}

void RelogioPlaneta::renderizar(sf::RenderWindow& window){
    try{
        draw(window, sf::RenderStates::Default);
    }catch(std::exception& e){
        std::cerr<<"Falha ao renderizar RelogioPlaneta"<<e.what()<<std::endl;
    }
}

