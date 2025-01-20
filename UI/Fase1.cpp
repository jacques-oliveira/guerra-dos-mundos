
#include "Fase1.hpp"
#include <stdexcept>

constexpr float SIZE(1024.0f);

Fase1::Fase1(const std::string& levelName) : levelCompleted(false), exitGame(false) {
    if (!font.loadFromFile("Assets/Fonts/Good-Game.ttf")) {
        throw std::runtime_error("Erro ao carregar fonte");
    }

    levelText.setFont(font);
    levelText.setString("Playing " + levelName);
    levelText.setCharacterSize(30);
    levelText.setFillColor(sf::Color::White);
    levelText.setPosition(10, 10);
    player = new Player();
    //configureSelectionBox();
    isRunning = false;
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

void Fase1::configureSelectionBox(){
    selectionBox.setFillColor(sf::Color(0, 0, 255, 25)); // Azul translúcido
    selectionBox.setOutlineThickness(1.f);
    selectionBox.setOutlineColor(sf::Color::Blue);
    isSelectingPlayer = false;
}

void Fase1::startSelection(sf::Vector2f& start){
    isSelectingPlayer = true;
    selectionStart = start;
    selectionBox.setPosition(start);
    selectionBox.setSize({0.f,0.f});
}

void Fase1::render(sf::RenderWindow& window) {
    window.clear();
    window.draw(levelText);
    player->render(window);
    window.display();
}

bool Fase1::shouldContinue() const {
    return levelCompleted;
}

bool Fase1::shouldExit() const {
    return exitGame;
}

void Fase1::updateSelection(const sf::Vector2f& current){
    sf::Vector2f size = current - selectionStart;
    selectionBox.setSize(size);
    selectionBox.setPosition({
        min(selectionStart.x,  current.x),
        min(selectionStart.y,current.y)
    });
}

void Fase1::endSelection(){
    isSelectingPlayer = false;
    sf::FloatRect selectionArea(
        selectionBox.getPosition(),
                                selectionBox.getSize()
    );
    player->setSelected(player->isInside(selectionArea));
}

void Fase1::moveSelectedPlayers(sf::Vector2f& dest){
    player->setDestination(dest);
}

void Fase1::updateViewSize(sf::View& view, sf::RenderWindow& _window){
    float ratio = (float)_window.getSize().y / (float)_window.getSize().x;
    view.setSize(SIZE, SIZE * ratio);
}
