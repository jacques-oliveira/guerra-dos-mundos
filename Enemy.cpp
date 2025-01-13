#include "Enemy.hpp"

Enemy::Enemy(EnemyType type) : enemytype(type){
}

Enemy::~Enemy(){
}

EnemyType Enemy::getEnemytype(){
    return enemytype;
}





