#include <iostream>
#include "Game.hpp"

Game::Game() : _window(sf::VideoMode(800,600),"Guerra dos Mundos"){

}

Game::~Game(){

}

void Game::processEvents(){
    sf::Event event;

    while(_window.pollEvent(event)){
        if( (event.type == sf::Event::Closed) or ( (event.type == sf::Event::KeyPressed) and (event.key.code == sf::Keyboard::Escape)) ){
            _window.close();
        }
    }
}

void Game::run(){
    while(_window.isOpen()){
        processEvents();
        update();
        render();
    }
}

void Game::update(){

}

void Game::render(){
    _window.clear();
    _window.display();
}

void Game::clean(){

}


