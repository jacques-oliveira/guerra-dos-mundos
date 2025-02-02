#pragma once

#include <iostream>
#include <string>

using namespace std;

class Character{

public:
    Character();
    ~Character();
    string name;
    virtual void move() = 0;
    float getHealth();
    void attack();
    void defense();
private:
    float health;
    float damage;
};
