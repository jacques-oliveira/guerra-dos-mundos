#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

using namespace std;

struct TileBlock {

public:
    TileBlock(const sf::Image& image);
    bool isTransparent() const;
    const sf::Sprite& getSprite() const;

private:
    sf::Image image;
    sf::Sprite sprite;

};
