#include <iostream>
#include "Game.hpp"
#include "Player.hpp"
#include "TileGenerator.hpp"
#include "Enemy.hpp"
#include "UI/MainMenuState.hpp"
#include "UI/Fase1.hpp"

Game::Game()  {
    _window = new sf::RenderWindow(sf::VideoMode(1024,768),"Guerra dos Mundos");

    states.push(std::make_unique<MainMenuState>());
}

Game::~Game(){}

void Game::processEvents(){
    while (_window->isOpen() && !states.empty()) {
        auto& currentState = states.top();
        currentState->processEvents(*_window);
    }
}

void Game::run(int frame_per_seconds){

    sf::Clock clock;
    sf::Time timeSinceLastUpdate = sf::Time::Zero;
    sf::Time TimePerFrame = sf::seconds(1.f/frame_per_seconds);

    _window->setFramerateLimit(frame_per_seconds);
    _window->setVerticalSyncEnabled(true);

    while(_window->isOpen() && !states.empty()){
        auto& currentState = states.top();
        currentState->processEvents(*_window);
        bool repaint = false;

        timeSinceLastUpdate += clock.restart();

        while(timeSinceLastUpdate > TimePerFrame){
            timeSinceLastUpdate -= TimePerFrame;
            repaint = true;
            currentState->update(TimePerFrame);
            //update(TimePerFrame);
            handleStateChanges();
        }
        if(repaint){
            //render();
            currentState->render(*_window);
        }

    }
}

void Game::handleStateChanges() {
    auto& currentState = states.top();
    try{
        if (currentState->shouldExit()) {
            states.pop();
            if (states.empty()) {
                _window->close();
            }
        } else if (currentState->shouldContinue()) {
            if (dynamic_cast<MainMenuState*>(currentState.get())) {
                changeState(std::make_unique<Fase1>("Phase 1"));
            }/* else if (dynamic_cast<PlayState*>(currentState.get())) {
                changeState(std::make_unique<GameOverState>(true)); // Fim da fase 1
            } else if (dynamic_cast<GameOverState*>(currentState.get())) {
                if (currentState->shouldContinue()) {
                    changeState(std::make_unique<PlayState>("Phase 2"));
                }
            }*/
            else{
                throw runtime_error("Estado inválido!");
            }
        }

    }catch(exception& ex){
        cerr <<"Não foi possivel manipulas os estados"<<endl;
    }
}
void Game::update(sf::Time deltaTime){
    //_player->update(deltaTime);
    states.top()->update(deltaTime);
}

void Game::render(){
    _window->clear();
    //tileGen->drawMap(*_window);
    //_window->draw(_enemy->getEnemySprite());
    //_window->draw(_player->getPlayerSprite());
    // if(isSelectingPlayer){
    //     _window->draw(selectionBox);
    // }
    _window->display();
}

void Game::changeState(std::unique_ptr<GameState> newState) {
    if (!states.empty()) {
        states.pop();
    }
    states.push(std::move(newState));
}

void Game::clean(){

}

