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
    this->movementSpeed = 100.f;
    life = 100;

    shape.setRadius(10.f);
    shape.setFillColor(sf::Color::Green);
    shape.setPosition(100, 100);
    selected = false;
    isMoving = false;
}

Player::~Player(){

}

void Player::setSelected(bool isSelected){
    selected = isSelected;

}

bool Player::isInside(const sf::FloatRect& selectionArea) const{
    return selectionArea.intersects(playerSprite.getGlobalBounds());
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

    if(isMoving){
        updatePositionPlayer(seconds);
    }
}

void Player::setDestination(sf::Vector2f& dest){
    sf::FloatRect bounds= playerSprite.getGlobalBounds();
    sf::Vector2f spriteCenter(bounds.width/2.f, bounds.height/2.f);

    destination = dest - spriteCenter;
}

void Player::updatePositionPlayer(float deltaTime){
    sf::Vector2f currentPosition = playerSprite.getPosition();
    sf::Vector2f direction = destination - currentPosition;

    float distance = std::sqrt(direction.x * direction.x + direction.y * direction.y);
    if(distance > 1.f){
        direction/= distance;
        float moveDistance = movementSpeed * deltaTime;

        if (moveDistance >= distance){
            playerSprite.setPosition(destination);
            isMoving = false;
        }else{
            playerSprite.move(direction * moveDistance);
        }
    }else{
        playerSprite.setPosition(destination);
        isMoving = false;
    }
}

const sf::Sprite & Player::getPlayerSprite() const{
    return playerSprite;
}

void Player::move(float seconds){
    float speed = 600.0f;
    if(moveUp){
        _velocity = sf::Vector2f(0,-movementSpeed);
        playerSprite.move(_velocity * speed *seconds);
    }else if(moveDown){
        _velocity = sf::Vector2f(0,movementSpeed);
        playerSprite.move(_velocity * speed *seconds);
    }else if(moveLeft){
        _velocity = sf::Vector2f(-movementSpeed,0);
        playerSprite.move(_velocity * speed *seconds);
    }else if(moveRight){
        _velocity = sf::Vector2f(movementSpeed,0);
        playerSprite.move(_velocity * speed *seconds);
    }
}

bool Player::isPlayerSelected(){
    return selected;
}

void Player::unselectPlayer(bool rightMouseButton){
    if(rightMouseButton)
        selected = false;
}



