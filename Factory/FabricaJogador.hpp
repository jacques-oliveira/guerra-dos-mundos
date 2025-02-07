#ifndef FABRICAJOGADOR_HPP
#define FABRICAJOGADOR_HPP

#include "../Player/Player.hpp"
#include "../Personagem/Soldado.hpp"
#include "../Personagem/Coletor.hpp"
#include "../Personagem/TipoPersonagem.hpp"

class FabricaJogador{
public:
    static Player* criarJogador(float posx, float posy,TipoPersonagem tipo);
private:
    bool possuiRecurso(TipoPersonagem tipo) const;
    void gastarRecurso(TipoPersonagem tipo);
};
#endif
