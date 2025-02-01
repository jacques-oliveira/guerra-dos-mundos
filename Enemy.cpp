#include "Enemy.hpp"

Enemy::Enemy(EnemyType type) : enemytype(type){
    if(!enemyTexture.loadFromFile("Assets/Textures/frame0000.png")){
        return;
    }
    collider = new Collider(sf::Vector2f(500,205));
    enemySprite.setTexture(enemyTexture);
    //enemySprite.scale(0.5,0.5);
    enemySprite.setPosition(600,240);

    collider->setPosition(sf::Vector2f(600,240));
}

Enemy::~Enemy(){
    delete collider;
    collider = nullptr;
}

EnemyType Enemy::getEnemytype(){
    return enemytype;
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







