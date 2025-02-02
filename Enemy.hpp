#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include "./Collision/Collider.hpp"
#include "./Character/CharacterType.hpp"

class Enemy : sf::Drawable{
public:
    Enemy(CharacterType type);
    ~Enemy();
    const CharacterType characterType;
    sf::Sprite getEnemySprite();
    Collider * collider;
    bool checkCollision(const Collidable& other) const;
    void render(sf::RenderWindow& window);

private:
    CharacterType getEnemytype();
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    sf::Sprite enemySprite;
    sf::Texture enemyTexture;
    void updateColliderPosition();
};


