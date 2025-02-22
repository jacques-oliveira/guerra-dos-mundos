#ifndef ANIMACAO_HPP
#define ANIMACAO_HPP

#include <SFML/Graphics.hpp>

class Animacao{
public:
    Animacao(float frameSpeed = 0.125f);
    void addFrame(sf::IntRect frameRect);
    void update();
    const sf::Texture& getTexture() const;
    sf::IntRect getCurrentFrame() const;

    void setSpriteSheet(const sf::Texture& texture);
    void setFrameSpeed(float speed);
    float getFrameSpeed() const;

private:
    std::vector<sf::IntRect> frames;
    int currentFrame;
    float frameSpeed;
    sf::Clock clock;
    const sf::Texture* spriteSheet;
};
#endif
