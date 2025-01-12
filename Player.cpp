#include <iostream>
#include "Player.hpp"
#include <cmath>

using namespace std;

Player::Player(){

    if(!playerTexture.loadFromFile("/home/jacques/Documents/game-development/guerra-dos-mundos/Assets/Textures/jaco_sprite.png")){
        return;
    }
    playerSprite.setTexture(playerTexture);
    playerSprite.scale(0.25,0.25);
    playerSprite.setPosition(100,100);
    this->movementSpeed = 4.f;
    life = 100;
}

Player::~Player(){

}


void Player::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(playerSprite, states);
}

void Player::processEvents(){
    moveUp = sf::Keyboard::isKeyPressed(sf::Keyboard::Up);
    moveDown = sf::Keyboard::isKeyPressed(sf::Keyboard::Down);
    moveLeft = sf::Keyboard::isKeyPressed(sf::Keyboard::Left);
    moveRight = sf::Keyboard::isKeyPressed(sf::Keyboard::Right);
}

void Player::update(sf::Time deltaTime){

    float seconds = deltaTime.asSeconds();

    // if(isMoving){
    //
    // }
    if(moveUp){
        _velocity = sf::Vector2f(0,-movementSpeed);
        playerSprite.move(_velocity * 60.f *seconds);
    }else if(moveDown){
        _velocity = sf::Vector2f(0,movementSpeed);
        playerSprite.move(_velocity * 60.f *seconds);
    }else if(moveLeft){
        _velocity = sf::Vector2f(-movementSpeed,0);
        playerSprite.move(_velocity * 60.f *seconds);
    }else if(moveRight){
        _velocity = sf::Vector2f(movementSpeed,0);
        playerSprite.move(_velocity * 60.f *seconds);
    }
}




