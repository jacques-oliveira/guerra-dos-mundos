#include "Enemy.hpp"

Enemy::Enemy(EnemyType type) : enemytype(type){
    if(!enemyTexture.loadFromFile("/home/jacques/Documents/game-development/guerra-dos-mundos/Assets/Textures/jaco_sprite.png")){
        return;
    }
    enemySprite.setTexture(enemyTexture);
    enemySprite.scale(0.25,0.25);
    enemySprite.setPosition(200,200);
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






