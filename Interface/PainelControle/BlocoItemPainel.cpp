#include "BlocoItemPainel.hpp"

BlocoItemPainel::BlocoItemPainel(){
    valorItem = 0;
    quantidadeItem = 0;
}

void BlocoItemPainel::inicializar(){
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

}

void BlocoItemPainel::carregarRecursos(){

}

