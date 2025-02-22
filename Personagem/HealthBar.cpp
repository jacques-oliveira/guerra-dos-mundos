#include "HeathBar.hpp"

HealthBar::HealthBar(float width, float heigth){
    background.setSize(sf::Vector2f(width, heigth));
    background.setFillColor(sf::Color::Black);
    background.setOutlineColor(sf::Color::White);
    background.setOutlineThickness(2.f);
    healthBar.setSize(sf::Vector2f(width,heigth));
    healthBar.setFillColor(sf::Color::Green);
}

HealthBar::~HealthBar(){
}

void HealthBar::setPosition(const sf::FloatRect& globalBounds){
    float x = globalBounds.left + globalBounds.getSize().x*0.2;
    float y = globalBounds.top - globalBounds.getSize().y*0.2;
    background.setPosition(x,y);
    healthBar.setPosition(x,y);
}

void HealthBar::setHealth(float healthValue){
    healthBar.setSize(sf::Vector2f(background.getSize().x * healthValue, background.getSize().y));
}

void HealthBar::draw(sf::RenderWindow& window){
    window.draw(background);
    window.draw(healthBar);
}





