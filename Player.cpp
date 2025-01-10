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
}

Player::~Player(){

}


void Player::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(playerSprite, states);
}

void Player::processEvents(){
    isMoving = sf::Keyboard::isKeyPressed(sf::Keyboard::Up);
    rotation = 0;
    rotation-= sf::Keyboard::isKeyPressed(sf::Keyboard::Left);
    rotation+= sf::Keyboard::isKeyPressed(sf::Keyboard::Right);
}

void Player::update(sf::Time deltaTime){

    float seconds = deltaTime.asSeconds();
    if(rotation != 0){
        float angle = rotation *180*seconds;
        playerSprite.rotate(angle);
    }
    if(isMoving){
        float angle = playerSprite.getRotation() / 180 *M_PI -M_PI /2;
        _velocity += sf::Vector2f(std::cos(angle),std::sin(angle)) * 60.f *seconds;
    }
    playerSprite.move(seconds * _velocity);
}




