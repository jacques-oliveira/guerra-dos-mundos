#ifndef SOLIDER_HPP
#define SOLIDER_HPP

#include "../Player/Player.hpp"

class Soldier : public Player{
public:
    Soldier(float posx, float posy, CharacterType type);
    ~Soldier();

};
#endif
