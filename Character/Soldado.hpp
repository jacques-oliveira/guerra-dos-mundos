#ifndef SOLIDER_HPP
#define SOLIDER_HPP

#include "../Player/Player.hpp"

class Soldado : public Player{
public:
    Soldado(float posx, float posy, CharacterType type);
    ~Soldado();

    void gritoAtaque();
private:
};
#endif
