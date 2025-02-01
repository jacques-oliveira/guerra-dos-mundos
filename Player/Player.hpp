#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <SFML/Graphics.hpp>
#include "PlayerState.hpp"
#include "../Animation/Animation.hpp"
#include "HeathBar.hpp"
#include "../Collision/Collider.hpp"

class Player : public sf::Drawable{
public :
    Player(const Player&) = delete;
    Player& operator = (const Player&) = delete;

    Player(float posx, float posy);
    ~Player();

    template<typename ...Args>
    void setPosition(Args&& ... args);
    sf::CircleShape selectShape;
    void update(sf::Time deltaTime);
    bool isMoving;
    float movementSpeed;
    void processEvents();
    const sf::Sprite&  getPlayerSprite() const;
    void setSelected(bool);
    bool isInside(const sf::FloatRect& selectionArea) const;
    bool isPlayerSelected();
    void unselectPlayer(bool);
    void setDestination(sf::Vector2f&);
    void render(sf::RenderWindow& window);
    void handleInput();
    bool mouseLeftEvent;
    Collider * collider;
    bool checkCollision(const Collidable& other) const;

private :
    float life;
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    sf::Sprite playerSprite;
    sf::Texture playerTexture;
    sf::Vector2f _velocity;
    bool moveUp,moveDown,moveLeft, moveRight;
    bool selected;
    sf::Vector2f destination;
    void updatePositionPlayer(float);
    float speed;
    void bindSelectShape();
    std::vector<Animation> animations;
    void loadAnimation(Animation& animation, int framecount, int row);
    void setState(PlayerState state);
    sf::Texture spriteSheet;
    PlayerState currentState;
    HealthBar * playerHealth;
    void initPlayer(float posx, float posy);
    void updateColliderPosition();
};
#endif
