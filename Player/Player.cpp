#include <iostream>
#include "Player.hpp"
#include <cmath>

using namespace std;

Player::Player(float posx, float posy){

    mouseLeftEvent = false;
    selected = false;
    isMoving = false;
    speed = 10.f;
    if(!
    spriteSheet.loadFromFile("Assets/Textures/player-sprite.png")){
        return;
    }

    animations.resize(5);

    for(int i = 0; i < 5; ++i){
        animations[i].setSpriteSheet(spriteSheet);
        loadAnimation(animations[i],8,i);
    }

    currentState = Idle;

    setState(currentState);
    playerSprite.setTexture(animations[currentState].getTexture());
    playerSprite.setTextureRect(animations[currentState].getCurrentFrame());
    initPlayer(posx, posy);
}

Player::~Player(){
    delete playerHealth;
    playerHealth = nullptr;
    delete collider;
    collider = nullptr;
}

void Player::setSelected(bool isSelected){
    selected = isSelected;
}

bool Player::isInside(const sf::FloatRect& selectionArea) const{
    return selectionArea.intersects(playerSprite.getGlobalBounds());
}

void Player::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(selectShape,states);
    target.draw(playerSprite, states);
    target.draw(collider->colliderShape());
}

void Player::render(sf::RenderWindow& window) {
    //window.draw(selectShape);
    //playerHealth->draw(window);
    playerHealth->draw(window);
}

void Player::handleInput() {
    // if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
    //     shape.move(0, -speed * 0.016f);
    // }
    // if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
    //     shape.move(0, speed * 0.016f);
    // }
    // if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
    //     shape.move(-speed * 0.016f, 0);
    // }
    // if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
    //     shape.move(speed * 0.016f, 0);
    // }
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
    }else{
        setState(Idle);
    }
    animations[currentState].update();
    playerSprite.setTextureRect(animations[currentState].getCurrentFrame());
    if(mouseLeftEvent){
        selectShape.setRadius(25.f);
    }else{
        selectShape.setRadius(0.f);
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
            if(abs(direction.x) > abs(direction.y)){
                setState(direction.x > 0 ? walkRight : walkLeft);
            }else{
                setState(direction.y > 0 ? walkDown : walkUp);
            }
            playerSprite.move(direction * moveDistance);
        }
    }else{
        playerSprite.setPosition(destination);
        isMoving = false;
        setState(Idle);
    }
    bindSelectShape();
    playerHealth->setPosition( playerSprite.getGlobalBounds());
    updateColliderPosition();
}

const sf::Sprite & Player::getPlayerSprite() const{
    return playerSprite;
}

bool Player::isPlayerSelected(){
    mouseLeftEvent =  selected;
    return selected;
}

void Player::unselectPlayer(bool rightMouseButton){
    if(rightMouseButton){
        selected = false;
        mouseLeftEvent = false;
    }
}

void Player::bindSelectShape(){
    selectShape.setPosition(playerSprite.getPosition().x + playerSprite.getTextureRect().width*0.1, playerSprite.getPosition().y + playerSprite.getTextureRect().height*0.65);
}

void Player::loadAnimation(Animation& animation, int framecount, int row){
    for(int i = 0; i < framecount; ++i){
        animation.addFrame(sf::IntRect(i * 64, row * 64, 64, 64));
    }
}

void Player::setState(PlayerState state){
    if(currentState != state){
        currentState = state;
        playerSprite.setTexture(animations[currentState].getTexture());
        playerSprite.setTextureRect(animations[currentState].getCurrentFrame());
    }
}

void Player::initPlayer(float posx, float posy){

    if(!isnan(posx) && !isnan(posy)){
        try{
            //playerSprite.scale(2.0,2.0);
            collider = new Collider(sf::Vector2f(50,25));
            playerSprite.setPosition(posx, posy);
            updateColliderPosition();
            this->movementSpeed = 150.f;
            life = 100;
            playerHealth = new HealthBar(40,8);
            playerHealth->setPosition( playerSprite.getGlobalBounds());
            playerHealth->setHealth(0.95f);

            selectShape.setFillColor(sf::Color::Transparent);
            selectShape.setOutlineThickness(5.5f);
            selectShape.setOutlineColor(sf::Color::Green);
            selectShape.setScale(1,0.5f);

            bindSelectShape();
        }catch(exception& e){
            cerr<<"Valores inválidos para criar o player"<<e.what()<<endl;
        }
    }

}

void Player::updateColliderPosition(){
    collider->setPosition(sf::Vector2f(playerSprite.getPosition().x + playerSprite.getTextureRect().width*0.1,
                                       playerSprite.getPosition().y  + 35.f));
}


