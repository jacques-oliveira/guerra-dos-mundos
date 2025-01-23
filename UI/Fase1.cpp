
#include "Fase1.hpp"
#include <stdexcept>

Fase1::Fase1(const std::string& _levelName) : Fase(_levelName){

    if (!font.loadFromFile("Assets/Fonts/Good-Game.ttf")) {
        throw std::runtime_error("Erro ao carregar fonte");
    }
    levelName = _levelName;
    levelCompleted = false;
    exitGame = false;

    levelText.setFont(font);
    levelText.setString("Playing " + levelName);
    levelText.setCharacterSize(30);
    levelText.setFillColor(sf::Color::White);
    levelText.setPosition(10, 10);
    player = new Player();
    enemy = new Enemy(Boss);
    isRunning = false;

}

Fase1::~Fase1(){
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

void Fase1::processEvents(sf::RenderWindow& _window) {
    sf::Event event;
    window = &_window;
    while (_window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            exitGame = true;
            _window.close();

        }else if(event.type == sf::Event::MouseButtonPressed){
            if(event.mouseButton.button == sf::Mouse::Left &&
                player->isPlayerSelected() == false){
                cout<<"Start selection "<< player->isPlayerSelected()<<endl;
                sf::Vector2f start = _window.mapPixelToCoords(sf::Mouse::getPosition(_window),view);
                startSelection(start);
            }else  if (event.mouseButton.button == sf::Mouse::Left && player->isPlayerSelected()){
                sf::Vector2f destination = _window.mapPixelToCoords(sf::Mouse::getPosition(_window),view);
                player->isMoving = true;
                moveSelectedPlayers(destination);
                selectionBox.setSize({0.f,0.f});
                cout<<"Moving player to destination "<<player->isPlayerSelected()<<endl;
            }

        }else if(event.type == sf::Event::MouseMoved){
            if(isSelectingPlayer){
                updateSelection(_window.mapPixelToCoords(sf::Mouse::getPosition(_window),view));
                player->setSelected(true);
            }
        }else if(event.type == sf::Event::MouseButtonReleased){
            if(event.mouseButton.button == sf::Mouse::Left){
                if(isSelectingPlayer){
                    endSelection();
                    cout<<"Mouse left released "<<player->isPlayerSelected()<<endl;
                    selectionBox.setSize({0,0});
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

void Fase1::update(sf::Time deltaTime) {
    player->update(deltaTime);
    sf::Vector2f playerPosition = player->getPlayerSprite().getPosition();
    sf::Vector2f targetCenter(playerPosition.x +100, playerPosition.y + 100);
    sf::Vector2f currentCenter = view.getCenter();

    sf::Vector2f smoothedCenter = currentCenter + (targetCenter - currentCenter) * 0.05f;
    view.setCenter(smoothedCenter);
    view.move(10,5);
    float ratio = (float)window->getSize().y / (float)window->getSize().x;
    setViewSize(ratio);
    window->setView(view);


}

void Fase1::render(sf::RenderWindow& window) {
    try{
        window.clear();
        tileGen->drawMap(window);
        window.draw(*player);
        window.draw(enemy->getEnemySprite());
        window.draw(selectionBox);
        player->render(window);
        window.setView(uiView);

        window.draw(levelText);
        window.display();

    }catch(exception&){
        cerr<<"Falha ao renderizar estado"<<endl;
    }
}
