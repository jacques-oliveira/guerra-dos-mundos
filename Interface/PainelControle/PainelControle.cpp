#include "PainelControle.hpp"

PainelControle::PainelControle(){
    inicializarPainel();
}

void PainelControle::inicializarPainel(){
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
    target.draw(spriteFundoPainel,states);
}

void PainelControle::atribuirPosicao(float posx, float posy){
    float borda = 2.f;
    spriteFundoPainel.setOrigin(spriteFundoPainel.getLocalBounds().left, spriteFundoPainel.getLocalBounds().height/2);
    spriteFundoPainel.setPosition(posx, posy - spriteFundoPainel.getGlobalBounds().height/2 -borda);
}

void PainelControle::renderizar(sf::RenderWindow& window){
    draw(window, sf::RenderStates::Default);
}

sf::Vector2f PainelControle::obterPosicaoPainel(){
    float distanciaPainel = 50.f;
    sf::Vector2f posicaoTotal(sf::Vector2f(spriteFundoPainel.getLocalBounds().width + spriteFundoPainel.getPosition().x + distanciaPainel, spriteFundoPainel.getPosition().y));
    return posicaoTotal;
}
