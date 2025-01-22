#include "Enemy.hpp"

Enemy::Enemy(EnemyType type) : enemytype(type){
    if(!enemyTexture.loadFromFile("Assets/Textures/frame0000.png")){
        return;
    }
    enemySprite.setTexture(enemyTexture);
    enemySprite.scale(0.5,0.5);
    enemySprite.setPosition(600,240);
}

Enemy::~Enemy(){
}

EnemyType Enemy::getEnemytype(){
    return enemytype;
}

void Enemy::draw(sf::RenderTarget& target, sf::RenderStates states) const{
    target.draw(enemySprite);
}

sf::Sprite Enemy::getEnemySprite(){
    return enemySprite;
}






