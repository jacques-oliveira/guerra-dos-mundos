#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include "./Colisao/Collider.hpp"
#include "Personagem/TipoPersonagem.hpp"

class Enemy : sf::Drawable{
public:
    Enemy(TipoPersonagem tipo);
    ~Enemy();
    const TipoPersonagem characterType;
    sf::Sprite getEnemySprite();
    Collider * collider;
    bool checkCollision(const Collidable& other) const;
    void render(sf::RenderWindow& window);

private:
    TipoPersonagem getEnemytype();
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    sf::Sprite enemySprite;
    sf::Texture enemyTexture;
    void updateColliderPosition();
};


