#ifndef COLLIDER_HPP
#define COLLIDER_HPP

#include "Collidable.hpp"

class Collider : public Collidable{
public:
    Collider(sf::Vector2f size);
    void setPosition(sf::Vector2f& position);
    const sf::RectangleShape & getCollider() const override;
private:
    sf::RectangleShape collider;
};
#endif
