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
    isRunning = false;
}

Game::~Game(){
    clean();
}

void Game::processEvents(){
    while (_window->isOpen() && !states.empty()) {
        auto& currentState = states.top();
        currentState->processEvents(*_window);
    }
}

void Game::run(int frame_per_seconds){
    try{
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
    }catch(exception& e){
        cerr<<"Erro ao executar método run no Game.cpp "<<e.what()<<endl;
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

    }catch(exception& e){
        cerr <<"Não foi possivel manipulas os estados "<<e.what()<<endl;
    }
}
void Game::update(sf::Time deltaTime){
    //_player->update(deltaTime);
    try{
        states.top()->update(deltaTime);
    }catch(exception& e){
        cerr<<"Erro ao atualizar game."<<e.what()<<endl;
    }
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
    try{
        if (!states.empty()) {
            states.pop();
        }
        states.push(std::move(newState));
    }catch(exception& e){
        cerr<<"Erro na mudança de estado "<<e.what()<<endl;
    }
}

void Game::clean(){
    try{
        delete _window;
        _window = nullptr;
        while(!states.empty()){
            states.pop();
        }
    }catch(exception& e){
        cerr<<"Erro: "<<e.what()<<endl;
    }
}

