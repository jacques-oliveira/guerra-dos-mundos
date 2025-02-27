#include "RelogioPlaneta.hpp"

RelogioPlaneta::RelogioPlaneta(){
    inicializar();
}

void RelogioPlaneta::inicializar(){
    numeroDia = 0;
    if(!texturaDia.loadFromFile("Recursos/Textures/textura_dia.png")){
        std::cerr<<"Falha ao carregar textura tempo dia"<<std::endl;
    }
    if(!texturaNoite.loadFromFile("Recursos/Textures/textura_noite.png")){
        std::cerr<<"Falha ao carregar textura tempo noite"<<std::endl;
    }
    if(!fonte.loadFromFile("Recursos/Fonts/TrulyMadlyDpad-a72o.ttf")){
        std::cerr<<"Falha ao carregar fonte tempo"<<std::endl;
    }
    spriteTempo.setTexture(texturaDia);
    atribuirFonte(fonte);
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

void RelogioPlaneta::atribuirFonte(sf::Font& _fonte){
    try{
        textNumeroDia.setFont(_fonte);
        textNumeroDia.setOrigin(textNumeroDia.getLocalBounds().left, textNumeroDia.getLocalBounds().height/2);
        textNumeroDia.setCharacterSize(16);
        textNumeroDia.setFillColor(sf::Color::Yellow);
        textNumeroDia.setString("01");
    }catch(std::exception& e){
        std::cerr<<"Falha ao atribuir fonte texto dia relogio planeta"<<e.what()<<std::endl;
    }
}


