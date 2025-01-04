#include <iostream>
#include "Player.hpp"
#include <cmath>

using namespace std;

Player::Player() : _shape(sf::Vector2f(32,32)){

    _shape.setFillColor(sf::Color::Blue);
    _shape.setOrigin(16,16);
    _shape.setScale(5,5);
}

Player::~Player(){

}


void Player::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(_shape, states);
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
        float angle = (rotation > 0 ? 1:-1);
        _shape.rotate(angle);
    }
    if(isMoving){
        float angle = _shape.getRotation() / 180 *M_PI -M_PI /2;
        _velocity += sf::Vector2f(std::cos(angle),std::sin(angle)) * 60.f *seconds;
    }
    _shape.move(seconds * _velocity);
}




