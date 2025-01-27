#include "Animation.hpp"

Animation::Animation(float frameSpeed) : currentFrame(0), frameSpeed(frameSpeed),
spriteSheet(nullptr){
    clock.restart();
}

void Animation::setSpriteSheet(const sf::Texture& texture){
    spriteSheet = &texture;
}

void Animation::addFrame(sf::IntRect frameRect){
    frames.push_back(frameRect);
}

void Animation::update(){
    if(clock.getElapsedTime().asSeconds() > frameSpeed){
        currentFrame = (currentFrame + 1) % frames.size();
        clock.restart();
    }
}

const sf::Texture& Animation::getTexture() const{
    return *spriteSheet;
}

sf::IntRect Animation::getCurrentFrame() const{
    return frames[currentFrame];
}

void Animation::setFrameSpeed(float speed){
    frameSpeed = speed;
}

float Animation::getFrameSpeed() const{
    return frameSpeed;
}






