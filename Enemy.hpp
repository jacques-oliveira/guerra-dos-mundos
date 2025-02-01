#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include "./Collision/Collider.hpp"
enum EnemyType{
    Boss,
    Soldier,
    Guardian
};

class Enemy : sf::Drawable{
public:
    Enemy(EnemyType e);
    ~Enemy();
    const EnemyType enemytype;
    sf::Sprite getEnemySprite();
    Collider * collider;
    bool checkCollision(const Collidable& other) const;
    void render(sf::RenderWindow& window);

private:
    EnemyType getEnemytype();
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    sf::Sprite enemySprite;
    sf::Texture enemyTexture;
    void updateColliderPosition();
};


