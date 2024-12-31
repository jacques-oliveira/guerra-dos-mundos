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

void Game::run(int frame_per_seconds){

    sf::Clock clock;
    sf::Time timeSinceLastUpdate = sf::Time::Zero;
    sf::Time TimePerFrame = sf::seconds(1.f/frame_per_seconds);

    while(_window.isOpen()){
        processEvents();
        bool repaint = false;

        timeSinceLastUpdate += clock.restart();
        while(timeSinceLastUpdate > TimePerFrame){
            timeSinceLastUpdate -= TimePerFrame;
            repaint = true;
            update(TimePerFrame);
        }
        if(repaint)
            render();
    }
}

void Game::update(sf::Time deltaTime){

}

void Game::render(){
    _window.clear();
    _window.display();
}

void Game::clean(){

}


