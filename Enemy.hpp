#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>

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

private:
    EnemyType getEnemytype();
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    sf::Sprite enemySprite;
    sf::Texture enemyTexture;

};


