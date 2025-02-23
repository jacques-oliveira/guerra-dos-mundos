#include "Animacao.hpp"

Animacao::Animacao(float frameSpeed) : currentFrame(0), frameSpeed(frameSpeed),
spriteSheet(nullptr){
    clock.restart();
}

void Animacao::setSpriteSheet(const sf::Texture& texture){
    spriteSheet = &texture;
}

void Animacao::addFrame(sf::IntRect frameRect){
    frames.push_back(frameRect);
}

void Animacao::update(){
    if(clock.getElapsedTime().asSeconds() > frameSpeed){
        currentFrame = (currentFrame + 1) % frames.size();
        clock.restart();
    }
}

const sf::Texture& Animacao::getTexture() const{
    return *spriteSheet;
}

sf::IntRect Animacao::getCurrentFrame() const{
    return frames[currentFrame];
}

void Animacao::setFrameSpeed(float speed){
    frameSpeed = speed;
}

float Animacao::getFrameSpeed() const{
    return frameSpeed;
}






