#include "PainelControle.hpp"

PainelControle::PainelControle(){
    inicializarPainel();
}

void PainelControle::inicializarPainel(){
    sf::Texture texturaFundoPainel;
    try{
        valorNeon = 0;
        numeroDia = 0;
        if(!texturaFundoPainel.loadFromFile("Recursos/Textures/fundo_painel_controle.png")){
            std::cerr<<"Erro ao carregar textura fundo do painel"<<std::endl;
        }
        spriteFundoPainel.setTexture(texturaFundoPainel);
    }catch(std::exception& e){
        std::cerr<<"Erro ao carregar textura do painel"<<e.what()<<std::endl;
    }
}

void PainelControle::draw(sf::RenderTarget& target, sf::RenderStates states) const{
    target.draw(spriteFundoPainel);
}

void PainelControle::atribuirPosicao(float posx, float posy){

}
