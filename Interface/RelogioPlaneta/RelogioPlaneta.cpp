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
    spriteTempo.setOrigin(spriteTempo.getLocalBounds().left, spriteTempo.getLocalBounds().height/2);
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
        textNumeroDia.setCharacterSize(24);
        textNumeroDia.setFillColor(sf::Color::White);
        textNumeroDia.setString("01");
        textNumeroDia.setOrigin(textNumeroDia.getLocalBounds().left, textNumeroDia.getLocalBounds().height/2);
    }catch(std::exception& e){
        std::cerr<<"Falha ao atribuir fonte texto dia relogio planeta"<<e.what()<<std::endl;
    }
}

void RelogioPlaneta::atribuirPosicao(float posx, float posy){
    float espaco = 16.f;
    spriteTempo.setPosition(posx, posy);
    textNumeroDia.setPosition(spriteTempo.getPosition().x + spriteTempo.getGlobalBounds().width + espaco, posy - textNumeroDia.getGlobalBounds().height/2);
}

sf::Vector2f RelogioPlaneta::dimensaoSpriteTempo(){
    float largura = spriteTempo.getGlobalBounds().width;
    float altura = spriteTempo.getGlobalBounds().height;
    return sf::Vector2f(largura,altura);
}

