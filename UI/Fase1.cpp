
#include "Fase1.hpp"
#include <stdexcept>

Fase1::Fase1(const std::string& _levelName) : Fase(_levelName){


    if (!font.loadFromFile("Assets/Fonts/Good-Game.ttf")) {
        throw std::runtime_error("Erro ao carregar fonte");
    }
    levelName = _levelName;
    levelCompleted = false;
    exitGame = false;
    //configureTileMap();
    levelText.setFont(font);
    levelText.setString("Playing " + levelName);
    levelText.setCharacterSize(30);
    levelText.setFillColor(sf::Color::White);
    levelText.setPosition(10, 10);
    player = new Player();
    //configureSelectionBox();

}

void Fase1::processEvents(sf::RenderWindow& _window) {
    sf::Event event;
    while (_window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            exitGame = true;
            _window.close();

        }else if(event.type == sf::Event::MouseButtonPressed){
            if(event.mouseButton.button == sf::Mouse::Left &&
                player->isPlayerSelected() == false){
                cout<<"Start selection "<< player->isPlayerSelected()<<endl;
                sf::Vector2f start = _window.mapPixelToCoords(sf::Mouse::getPosition(_window));
                startSelection(start);
            }else  if (event.mouseButton.button == sf::Mouse::Left && player->isPlayerSelected()){
                sf::Vector2f destination = _window.mapPixelToCoords(sf::Mouse::getPosition(_window));
                player->isMoving = true;
                moveSelectedPlayers(destination);
                selectionBox.setSize({0.f,0.f});
                cout<<"Moving player to destination "<<player->isPlayerSelected()<<endl;
            }

        }else if(event.type == sf::Event::MouseMoved){
            if(isSelectingPlayer){
                updateSelection(_window.mapPixelToCoords(sf::Mouse::getPosition(_window)));
                player->setSelected(true);
            }
        }else if(event.type == sf::Event::MouseButtonReleased){
            if(event.mouseButton.button == sf::Mouse::Left){
                if(isSelectingPlayer){
                    endSelection();
                    cout<<"Mouse left released "<<player->isPlayerSelected()<<endl;
                }
            }
        }
        if(event.mouseButton.button == sf::Mouse::Right && player->isPlayerSelected()){
            player->unselectPlayer(true);
            cout<<"Unselect Player"<<endl;
        }
    }
    //player->handleInput();
    player->processEvents();
}

void Fase1::update() {
    //player->update();
    // Lógica de fase aqui
}

void Fase1::render(sf::RenderWindow& window) {
    window.clear();
    tileGen->drawMap(window);
    window.draw(*player);
    window.draw(levelText);
    player->render(window);
    window.display();
}
