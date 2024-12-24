#include <iostream>
#include "Game.hpp"

Game::Game(){

}

Game::~Game(){

}

void Game::init(const char* title, int xpos, int ypos,int width, int height, bool fullscreen){

    if(window->isOpen()){
        std::cout<<"Window created!"<<std::endl;
        isRunning = true;
    }
}

void Game::handleEvents(){
}

void Game::update(){

}

void Game::renderer(){
}

void Game::clean(){

}


