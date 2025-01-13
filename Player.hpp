#pragma once

#include <SFML/Graphics.hpp>

class Player : public sf::Drawable{
public :
    Player(const Player&) = delete;
    Player& operator = (const Player&) = delete;

    Player();
    ~Player();

    template<typename ...Args>
    void setPosition(Args&& ... args);

    void update(sf::Time deltaTime);
    bool isMoving;
    float movementSpeed;
    void processEvents();
    const sf::Sprite&  getPlayerSprite() const;

private :
    float life;
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    sf::Sprite playerSprite;
    sf::Texture playerTexture;
    sf::Vector2f _velocity;
    bool moveUp,moveDown,moveLeft, moveRight;
    void move(float);

};
