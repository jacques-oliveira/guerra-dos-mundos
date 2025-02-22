#ifndef COLETOR_HPP
#define COLETOR_HPP

#include "../Personagem/Player.hpp"

class Coletor : public Player{
public:
    Coletor(float posx, float posy, TipoPersonagem tipo);
    virtual ~Coletor() = default;
    void coletarRecurso();
};
#endif
