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
    target.draw(textQuantidadeItem);
    target.draw(textValorItem);
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
        if(!fonte.loadFromFile("Recursos/Fonts/TrulyMadlyDpad-a72o.ttf")){
            std::cerr<<"Falha ao carregar fonte Truly"<<std::endl;
        }
        spriteBloco.setTexture(texturaBloco);
        spriteBloco.setOrigin(spriteBloco.getLocalBounds().left, spriteBloco.getLocalBounds().height/2);
        atribuirFonte(fonte);
    }catch(std::exception& e){
        std::cerr<<"Falha ao carregar recursos no bloco"<<e.what()<<std::endl;
    }
}

void BlocoItemPainel::atribuirFonte(sf::Font& fonte){
    try{
        textQuantidadeItem.setFont(fonte);
        textValorItem.setFont(fonte);

        textQuantidadeItem.setCharacterSize(18);
        textValorItem.setCharacterSize(20);

        textQuantidadeItem.setFillColor(sf::Color::Yellow);
        textValorItem.setFillColor(sf::Color::Green);

        textValorItem.setString("900");
        textQuantidadeItem.setString(std::to_string(quantidadeItem));
        textValorItem.setOrigin(textValorItem.getLocalBounds().left, textValorItem.getLocalBounds().height/2);
        textQuantidadeItem.setOrigin(textQuantidadeItem.getLocalBounds().left, textQuantidadeItem.getLocalBounds().height/2);
    }catch(std::exception& e){
        std::cerr<<"Erro ao atribuir fonte ao bloco"<<e.what()<<std::endl;
    }
}

void BlocoItemPainel::atribuirPosicao(float posx, float posy){
    try{
        spriteBloco.setPosition(posx, posy);

        float posxQuantidadeItem = spriteBloco.getGlobalBounds().left + spriteBloco.getGlobalBounds().width - textQuantidadeItem.getGlobalBounds().width -5.f;
        float posyQuantidadeItem = spriteBloco.getGlobalBounds().top + spriteBloco.getGlobalBounds().height - textQuantidadeItem.getGlobalBounds().height - 5.f;
        textQuantidadeItem.setPosition(posxQuantidadeItem, posyQuantidadeItem);

        float posxValorItem = spriteBloco.getGlobalBounds().left + spriteBloco.getGlobalBounds().width/2 -10.f;
        float posyValorItem = spriteBloco.getGlobalBounds().top + spriteBloco.getGlobalBounds().height + 2.f;
        textValorItem.setPosition(posxValorItem, posyValorItem);
    }catch(std::exception& e){
        std::cerr<<"Erro ao atribuir posição ao bloco"<<e.what()<<std::endl;
    }
}
