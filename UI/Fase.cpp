#include "Fase.hpp"

constexpr float SIZE(1024.0f);

Fase::Fase(const std::string& levelName) : levelCompleted(false), exitGame(false){
    configureTileMap();
    configureSelectionBox();
    exitGame =false;
    isSelectingPlayer = false;

}

Fase::~Fase(){
    if (player) {
        delete player;
        player = nullptr;
    }
    if (enemy) {
        delete enemy;
        enemy = nullptr;
    }
    if (tileGen) {
        delete tileGen;
        tileGen = nullptr;
    }
}
void Fase::startSelection(sf::Vector2f& start){
    isSelectingPlayer = true;
    selectionStart = start;
    selectionBox.setPosition(start);
    selectionBox.setSize({0.f,0.f});
}

void Fase::configureSelectionBox(){
    selectionBox.setFillColor(sf::Color(0, 0, 255, 25)); // Azul translúcido
    selectionBox.setOutlineThickness(1.f);
    selectionBox.setOutlineColor(sf::Color::Blue);
    isSelectingPlayer = false;
}

void Fase::updateSelection(const sf::Vector2f& current){
    sf::Vector2f size = current - selectionStart;
    selectionBox.setSize(size);
    selectionBox.setPosition({
        min(selectionStart.x,  current.x),
        min(selectionStart.y,current.y)
    });
}

void Fase::endSelection(){
    isSelectingPlayer = false;
    sf::FloatRect selectionArea(
        selectionBox.getPosition(),
        selectionBox.getSize()
    );
    player->setSelected(player->isInside(selectionArea));
}

void Fase::moveSelectedPlayers(sf::Vector2f& dest){
    player->setDestination(dest);
}

void Fase::configureTileMap(){
    char path[100] =  {"Assets/Textures/forest.png\0"};
    tileGen = new TileGenerator();
    tileGen->generateTileMap(path);
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

