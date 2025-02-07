#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

using namespace std;

struct TileBlock {

public:
    TileBlock(const sf::Image& image);
    bool isTransparent() const;
    sf::Sprite& getSprite();

private:
    sf::Image image;
    sf::Sprite sprite;
    sf::Texture texture;
};
