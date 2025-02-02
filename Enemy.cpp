#include "Enemy.hpp"

Enemy::Enemy(CharacterType type) : characterType(type){
    if(!enemyTexture.loadFromFile("Assets/Textures/frame0000.png")){
        return;
    }
    enemySprite.setTexture(enemyTexture);
    //enemySprite.scale(0.5,0.5);
    enemySprite.setPosition(600,240);
    collider = new Collider(sf::Vector2f(120,80));
    collider->setPosition(sf::Vector2f(
        enemySprite.getGlobalBounds().getPosition().x + collider->colliderShape().getGlobalBounds().width/2,
        enemySprite.getPosition().y + enemySprite.getTextureRect().height*0.60f));
}

Enemy::~Enemy(){
    delete collider;
    collider = nullptr;
}

CharacterType Enemy::getEnemytype(){
    return characterType;
}

void Enemy::draw(sf::RenderTarget& target, sf::RenderStates states) const{
    target.draw(enemySprite);
    target.draw(collider->colliderShape());
}

sf::Sprite Enemy::getEnemySprite(){
    return enemySprite;
}

void Enemy::render(sf::RenderWindow& window){
    draw(window,sf::RenderStates::Default);
}







