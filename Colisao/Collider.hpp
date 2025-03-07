#ifndef COLLIDER_HPP
#define COLLIDER_HPP

#include "Collidable.hpp"

class Collider : public Collidable{
public:
    Collider(sf::Vector2f size);
    void setPosition(const sf::Vector2f& position);
    const sf::RectangleShape & getCollider() const override;
    sf::RectangleShape colliderShape();
private:
    sf::RectangleShape collider;
};
#endif
