#ifndef COLLIDABLE_HPP
#define COLLIDABLE_HPP

#include <SFML/Graphics.hpp>

class Collidable{

public:
    virtual const sf::RectangleShape& getCollider() const = 0;
    virtual ~Collidable() = default;
};
#endif
