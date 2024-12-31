#pragma once

class Player{
public :
    Player();
    ~Player();
    void move();
    void draw();
    void update();
private :
    float life;
};
