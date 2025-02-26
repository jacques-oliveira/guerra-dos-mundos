#include "BlocoItemPainel.hpp"

BlocoItemPainel::BlocoItemPainel(){
    inicializar();
}

void BlocoItemPainel::inicializar(){
    valorItem = 0;
    quantidadeItem = 0;
    carregarRecursos();
}

unsigned short BlocoItemPainel::obterValorItem(){
    return valorItem;
}

unsigned short BlocoItemPainel::obterQuantidadeItem(){
    return quantidadeItem;
}


void BlocoItemPainel::draw(sf::RenderTarget& target, sf::RenderStates states) const{
    target.draw(spriteBloco, states);
    target.draw(spriteItem);
}

void BlocoItemPainel::renderizar(sf::RenderWindow& window){
    try{
        draw(window, sf::RenderStates::Default);
    }catch(std::exception& e){
        std::cerr<<"Falha ao renderizar Bloco no painel"<<e.what()<<std::endl;
    }
}

void BlocoItemPainel::carregarRecursos(){
    try{
        if(!texturaBloco.loadFromFile("Recursos/Textures/bloco_item.png")){
            std::cerr<<"Falha ao carregar textura no Bloco no painel"<<std::endl;
        }
        spriteBloco.setTexture(texturaBloco);
    }catch(std::exception& e){
        std::cerr<<"Falha ao carregar recursos no bloco"<<e.what()<<std::endl;
    }
}

void BlocoItemPainel::atribuirFonte(sf::Font& fonte){
    try{
        textQuantidadeItem.setFont(fonte);
        textValorItem.setFont(fonte);
    }catch(std::exception& e){
        std::cerr<<"Erro ao atribuir fonte ao bloco"<<e.what()<<std::endl;
    }
}

void BlocoItemPainel::atribuirPosicao(float posx, float posy){
    try{
        spriteBloco.setPosition(posx, posy);
        float posxQuantidadeItem = spriteBloco.getGlobalBounds().left + spriteBloco.getGlobalBounds().width/2 -10.f;
        float posyQuantidadeItem = spriteBloco.getGlobalBounds().top + spriteBloco.getGlobalBounds().height - 10.f;
        textQuantidadeItem.setPosition(posxQuantidadeItem, posyQuantidadeItem);
        float posxValorItem = spriteBloco.getGlobalBounds().left + spriteBloco.getGlobalBounds().width/2 -10.f;
        float posyValorItem = spriteBloco.getGlobalBounds().top + spriteBloco.getGlobalBounds().height - 10.f;
        textValorItem.setPosition(posxValorItem, posyValorItem);
    }catch(std::exception& e){
        std::cerr<<"Erro ao atribuir posição ao bloco"<<e.what()<<std::endl;
    }
}

