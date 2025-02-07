#include "FabricaJogador.hpp"

Player * FabricaJogador::criarJogador(float posx, float posy, TipoPersonagem tipo){

    switch(tipo){
        case Tipo_Soldado:
            return new class Soldado(posx,posy,Tipo_Soldado);
        case Tipo_Coletor:
            return new class Coletor(posx,posy,Tipo_Coletor);
        default:
            return nullptr;
    }
    return nullptr;
}

