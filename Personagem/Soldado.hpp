#ifndef SOLIDER_HPP
#define SOLIDER_HPP

#include "../Personagem/Player.hpp"

class Soldado : public Player{
public:
    Soldado(float posx, float posy, TipoPersonagem tipo);
    virtual ~Soldado() = default;

    void gritoAtaque();
private:
};
#endif
