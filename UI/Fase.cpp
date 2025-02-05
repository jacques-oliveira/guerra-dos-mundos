#include "Fase.hpp"

constexpr float SIZE(1024.0f);

Fase::Fase(const std::string& levelName) : levelCompleted(false), exitGame(false){
    configureTileMap();
    configureSelectionBox();
    exitGame =false;
    isSelectingPlayer = false;

}

Fase::~Fase(){
    // if (player) {
    //     delete player;
    //     player = nullptr;
    // }
    // if (enemy) {
    //     delete enemy;
    //     enemy = nullptr;
    // }
    // if (tileGen) {
    //     delete tileGen;
    //     tileGen = nullptr;
    // }
}
void Fase::startSelection(sf::Vector2f& start){
    cout<<"iniciando seleção"<<endl;
    isSelectingPlayer = true;
    selectionStart = start;
    selectionBox.setPosition(start);
    selectionBox.setSize({0.f,0.f});
}

void Fase::configureSelectionBox(){
    try{
        selectionBox.setFillColor(sf::Color(0, 0, 255, 25)); // Azul translúcido
        selectionBox.setOutlineThickness(1.f);
        selectionBox.setOutlineColor(sf::Color::Blue);
        isSelectingPlayer = false;
    }catch(exception& e){
        cerr<<"Erro ao configurar selectionBox"<<e.what()<<endl;
    }
}

void Fase::updateSelection(const sf::Vector2f& current){
    cout<<"atualizando seleção"<<endl;
    sf::Vector2f size = current - selectionStart;
    selectionBox.setSize(size);
    selectionBox.setPosition({
        min(selectionStart.x,  current.x),
        min(selectionStart.y,current.y)
    });
}

void Fase::endSelection(){
    sf::FloatRect selectionArea(
        selectionBox.getPosition(),
        selectionBox.getSize()
    );
    for(auto& player : players){
        player->setSelected(player->isInside(selectionArea));
    }
    selectionBox.setSize({0,0});
    isSelectingPlayer = false;
    cout<<"seleção finalizada"<<endl;

}

void Fase::moveSelectedPlayers(sf::Vector2f& dest){
    for(auto& player : players){
        player->setDestination(dest);
        player->isMoving =true;
    }
}

void Fase::configureTileMap(){
    try{
        char path[100] =  {"Assets/Textures/forest.png\0"};
        tileGen = new TileGenerator();
        tileGen->generateTileMap(path);
    }catch(exception& e){
        cerr<<"Erro ao configurar tilemap"<<e.what()<<endl;
    }
}

bool Fase::shouldContinue() const {
    return levelCompleted;
}

bool Fase::shouldExit() const {
    return exitGame;
}

void Fase::setViewSize(float ratio){
    view.setSize(SIZE, SIZE * ratio);
}


void Fase::updateViewSize(sf::View& view, sf::RenderWindow& window){
    float ratio = (float)window.getSize().y / (float)window.getSize().x;
    view.setSize(SIZE, SIZE * ratio);
}

