#include <iostream>
#include "Game.hpp"
#include "Player.hpp"
#include "TileGenerator.hpp"
#include "Enemy.hpp"


Game::Game()  {
    _window = new sf::RenderWindow(sf::VideoMode(1024,768),"Guerra dos Mundos");
    char path[100] =  {"/home/jacques/Documents/game-development/guerra-dos-mundos/Assets/Textures/forest.png\0"};
    tileGen = new TileGenerator();
    tileGen->generateTileMap(path);
    view = _window->getDefaultView();
    _enemy = new Enemy(Boss);
    _player = new Player();
    std::cout<<_enemy->enemytype<<std::endl;

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
        }else if (event.type == sf::Event::KeyPressed)
        {
            if(event.key.code == sf::Keyboard::Up || event.key.code == sf::Keyboard::Down ||
                event.key.code == sf::Keyboard::Left || event.key.code == sf::Keyboard::Right){
                _player->isMoving = true;
            }
        }
        else if (event.type == sf::Event::KeyReleased)
        {
            if(event.key.code == sf::Keyboard::Up || event.key.code == sf::Keyboard::Down ||
                event.key.code == sf::Keyboard::Left || event.key.code == sf::Keyboard::Right
            ){

                _player->isMoving = false;
            }
        }else if(event.type == sf::Event::MouseButtonPressed){
            if(event.mouseButton.button == sf::Mouse::Left){
                cout<<"Mouse left click"<<endl;
                //primeiro vértice do retângulo da seleção
            }

        }else if(event.type == sf::Event::MouseButtonReleased){
            if(event.mouseButton.button == sf::Mouse::Left){
                cout<<"Mouse left released"<<endl;
                //ultimo vértice do retângulo da seleção
            }
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
    _window->display();
}

void Game::clean(){

}



