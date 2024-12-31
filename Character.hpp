#pragma once

#include <iostream>
#include <string>

using namespace std;

class Character{

public:
    Character();
    ~Character();
    string name;
    virtual void move();
    float getHealth();
private:
    float health;
};
