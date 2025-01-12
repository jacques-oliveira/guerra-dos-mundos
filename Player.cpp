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
    moveUp = sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::W);
    moveDown = sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::S);
    moveLeft = sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::A);
    moveRight = sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D);
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

const sf::Sprite & Player::getPlayerSprite() const{
    return playerSprite;
}




