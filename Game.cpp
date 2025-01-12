#include <iostream>
#include "Game.hpp"
#include "Player.hpp"
#include "TileGenerator.hpp"

Game::Game() : _window(sf::VideoMode(1024,768),"Guerra dos Mundos"){

    char path[100] =  {"/home/jacques/Documents/game-development/guerra-dos-mundos/Assets/Textures/forest.png\0"};
    tileGen.generateTileMap(path);
    view = _window.getDefaultView();
}

Game::~Game(){

}

void Game::processEvents(){
    sf::Event event;

    while(_window.pollEvent(event)){
        if( (event.type == sf::Event::Closed) or ( (event.type == sf::Event::KeyPressed) and (event.key.code == sf::Keyboard::Escape)) ){
            _window.close();
        }else if (event.type == sf::Event::KeyPressed)
        {
            if(event.key.code == sf::Keyboard::Up || event.key.code == sf::Keyboard::Down ||
                event.key.code == sf::Keyboard::Left || event.key.code == sf::Keyboard::Right){
                _player.isMoving = true;
            }
        }
        else if (event.type == sf::Event::KeyReleased)
        {
            if(event.key.code == sf::Keyboard::Up || event.key.code == sf::Keyboard::Down ||
                event.key.code == sf::Keyboard::Left || event.key.code == sf::Keyboard::Right
            ){

                _player.isMoving = false;
            }
        }
    }
    _player.processEvents();
}

void Game::run(int frame_per_seconds){

    sf::Clock clock;
    sf::Time timeSinceLastUpdate = sf::Time::Zero;
    sf::Time TimePerFrame = sf::seconds(1.f/frame_per_seconds);

    _window.setFramerateLimit(frame_per_seconds);
    _window.setVerticalSyncEnabled(true);

    while(_window.isOpen()){
        processEvents();
        bool repaint = false;
        view.setCenter(_player.getPlayerSprite().getPosition().x*60.f*0.005,_player.getPlayerSprite().getPosition().y*60.f*0.005);
        view.move(300,200);
        _window.setView(view);
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
    _player.update(deltaTime);
}

void Game::render(){
    //const sf::Sprite& sprite = tileGen.getEnvSprite();
    //sf::Sprite sp(tileGen.listBaseTexture[1]);
    _window.clear();
    //_window.draw(sp);
    tileGen.drawMap(_window);
    _window.draw(_player);

    _window.display();
}

void Game::clean(){

}



