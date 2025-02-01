#include "Collider.hpp"

Collider::Collider(sf::Vector2f size){
    collider.setSize(size);
    collider.setFillColor(sf::Color::Transparent);
    collider.setOutlineColor(sf::Color::Green);
    collider.setOutlineThickness(1.f);
}

void Collider::setPosition(sf::Vector2f& position){
    collider.setPosition(position);
}

const sf::RectangleShape & Collider::getCollider() const{
    return collider;
}



