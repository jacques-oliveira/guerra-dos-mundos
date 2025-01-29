#ifndef HEATHBAR_HPP
#define HEATHBAR_HPP

#include <SFML/Graphics.hpp>

class HealthBar{

public:
    HealthBar(float width, float height);
    ~HealthBar();

    void setPosition(float x, float y);
    void setHealth(float healthValue);
    void draw(sf::RenderWindow& window);

private:
    sf::RectangleShape background;
    sf::RectangleShape healthBar;
};
#endif
