#include <iostream>
#include "Game.hpp"
#include "Player.hpp"
#include "TileGenerator.hpp"
#include "Enemy.hpp"

constexpr float SIZE(1024.0f);

Game::Game()  {
    _window = new sf::RenderWindow(sf::VideoMode(1024,768),"Guerra dos Mundos");
    configureTileMap();
    view = _window->getDefaultView();
    _enemy = new Enemy(Boss);
    _player = new Player();

    configureSelectionBox();
}

Game::~Game(){
    delete _enemy;
    delete _player;
    delete _window;
}

void Game::processEvents(){
    sf::Event event;

    while(_window->pollEvent(event)){
        if( (event.type == sf::Event::Closed) or ( (event.type == sf::Event::KeyPressed) and (event.key.code == sf::Keyboard::Escape)) ){
            _window->close();
        }else
        if(event.type == sf::Event::MouseButtonPressed){
            if(event.mouseButton.button == sf::Mouse::Left && _player->isPlayerSelected() == false){
                cout<<"Start selection "<<_player->isPlayerSelected()<<endl;
                sf::Vector2f start = _window->mapPixelToCoords(sf::Mouse::getPosition(*_window));
                startSelection(start);
            }else  if (event.mouseButton.button == sf::Mouse::Left && _player->isPlayerSelected()){
                sf::Vector2f destination = _window->mapPixelToCoords(sf::Mouse::getPosition(*_window));
                _player->isMoving = true;
                moveSelectedPlayers(destination);
                selectionBox.setSize({0.f,0.f});
                cout<<"Moving player to destination "<<_player->isPlayerSelected()<<endl;
            }

        }else if(event.type == sf::Event::MouseMoved){
            if(isSelectingPlayer){
                updateSelection(_window->mapPixelToCoords(sf::Mouse::getPosition(*_window)));
                _player->setSelected(true);
            }
        }else if(event.type == sf::Event::MouseButtonReleased){
            if(event.mouseButton.button == sf::Mouse::Left){
                if(isSelectingPlayer){
                    endSelection();
                    cout<<"Mouse left released "<<_player->isPlayerSelected()<<endl;
                }
            }
        }
        if(event.mouseButton.button == sf::Mouse::Right && _player->isPlayerSelected()){
            _player->unselectPlayer(true);
            cout<<"Unselect Player"<<endl;
        }
    }
    _player->processEvents();
}

void Game::run(int frame_per_seconds){

    sf::Clock clock;
    sf::Time timeSinceLastUpdate = sf::Time::Zero;
    sf::Time TimePerFrame = sf::seconds(1.f/frame_per_seconds);

    _window->setFramerateLimit(frame_per_seconds);
    _window->setVerticalSyncEnabled(true);

    while(_window->isOpen()){
        processEvents();
        bool repaint = false;

        sf::Vector2f playerPosition = _player->getPlayerSprite().getPosition();
        sf::Vector2f targetCenter(playerPosition.x +100, playerPosition.y + 100);
        sf::Vector2f currentCenter = view.getCenter();

        sf::Vector2f smoothedCenter = currentCenter + (targetCenter - currentCenter) * 0.05f;
        view.setCenter(smoothedCenter);
        view.move(10,5);
        updateViewSize(view);
        _window->setView(view);
        timeSinceLastUpdate += clock.restart();
        while(timeSinceLastUpdate > TimePerFrame){
            timeSinceLastUpdate -= TimePerFrame;
            repaint = true;
            update(TimePerFrame);
        }
        if(repaint){
            render();
        }

    }
}

void Game::update(sf::Time deltaTime){
    _player->update(deltaTime);
}

void Game::render(){
    _window->clear();
    tileGen->drawMap(*_window);
    _window->draw(_enemy->getEnemySprite());
    _window->draw(_player->getPlayerSprite());
    if(isSelectingPlayer){
        _window->draw(selectionBox);
    }
    _window->display();
}

void Game::clean(){

}

void Game::configureSelectionBox(){
    selectionBox.setFillColor(sf::Color(0, 0, 255, 25)); // Azul translúcido
    selectionBox.setOutlineThickness(1.f);
    selectionBox.setOutlineColor(sf::Color::Blue);
    isSelectingPlayer = false;
}

void Game::configureTileMap(){
    char path[100] =  {"/home/jacques/Documents/game-development/guerra-dos-mundos/Assets/Textures/forest.png\0"};
    tileGen = new TileGenerator();
    tileGen->generateTileMap(path);
}

void Game:: startSelection(sf::Vector2f& start){
    isSelectingPlayer = true;
    selectionStart = start;
    selectionBox.setPosition(start);
    selectionBox.setSize({0.f,0.f});
}

void Game::updateSelection(const sf::Vector2f& current){
    sf::Vector2f size = current - selectionStart;
    selectionBox.setSize(size);
    selectionBox.setPosition({
        min(selectionStart.x,  current.x),
        min(selectionStart.y,current.y)
    });
}

void Game::endSelection(){
    isSelectingPlayer = false;
    sf::FloatRect selectionArea(
        selectionBox.getPosition(),
        selectionBox.getSize()
    );
    _player->setSelected(_player->isInside(selectionArea));
}

void Game::moveSelectedPlayers(sf::Vector2f& dest){
    _player->setDestination(dest);
}

void Game::updateViewSize(sf::View& view){
    float ratio = (float)_window->getSize().y / (float)_window->getSize().x;
    view.setSize(SIZE, SIZE * ratio);
}
