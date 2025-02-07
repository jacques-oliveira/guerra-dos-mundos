#ifndef COLETOR_HPP
#define COLETOR_HPP

#include "../Player/Player.hpp"

class Coletor : public Player{
public:
    Coletor(float posx, float posy, TipoPersonagem tipo);
    ~Coletor();
    void coletarRecurso();
};
#endif
