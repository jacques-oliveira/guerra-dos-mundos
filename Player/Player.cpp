#include <iostream>
#include "Player.hpp"
#include <cmath>

using namespace std;

Player::Player(float posx, float posy,CharacterType characterType){

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
    bool intersecao =  selectionArea.intersects(playerSprite.getGlobalBounds());
    cout<<"interseção do player"<<intersecao<<endl;
    return intersecao;
}

void Player::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(selectShape,states);
    target.draw(playerSprite, states);
    target.draw(collider->colliderShape());
}

void Player::render(sf::RenderWindow& window) {
    draw(window, sf::RenderStates::Default);
    playerHealth->draw(window);
}

void Player::handleInput() {

}

void Player::processEvents(){

}

void Player::update(sf::Time deltaTime){

    float seconds = deltaTime.asSeconds();
    if(isMoving){
        updatePositionPlayer(seconds);
        previousPosition = playerSprite.getPosition();
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

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<float> dis(-50.f,50.f);

    sf::Vector2f randomOffset(dis(gen),dis(gen));

    destination = dest - spriteCenter + randomOffset;
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
        cout<<"seleção "<<selected<<endl;
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
            playerHealth = new HealthBar(40,6);
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

bool Player::checkCollision(const Collidable& other) const{
    return collider->getCollider().getGlobalBounds().intersects(other.getCollider().getGlobalBounds());
}

void Player::resolveCollision(const Collidable& other){
    if(checkCollision(other)){
        cout<<"Collision"<<endl;
        sf::FloatRect playerBounds = collider->getCollider().getGlobalBounds();
        sf::FloatRect otherBounds = other.getCollider().getGlobalBounds();

        if (playerBounds.intersects(otherBounds)) {

            float overlapLeft = playerBounds.left + playerBounds.width - otherBounds.left;
            float overlapRight = otherBounds.left + otherBounds.width - playerBounds.left;
            float overlapTop = playerBounds.top + playerBounds.height - otherBounds.top;
            float overlapBottom = otherBounds.top + otherBounds.height - playerBounds.top;

            if (overlapLeft < overlapRight && overlapLeft < overlapTop && overlapLeft < overlapBottom) {
                playerSprite.move(-overlapLeft, 0.f);
            } else if (overlapRight < overlapLeft && overlapRight < overlapTop && overlapRight < overlapBottom) {
                playerSprite.move(overlapRight, 0.f);
            } else if (overlapTop < overlapLeft && overlapTop < overlapRight && overlapTop < overlapBottom) {
                playerSprite.move(0.f, -overlapTop);
            } else if (overlapBottom < overlapLeft && overlapBottom < overlapRight && overlapBottom < overlapTop) {
                playerSprite.move(0.f, overlapBottom);
            }
        }
    }
    updateColliderPosition();
}


