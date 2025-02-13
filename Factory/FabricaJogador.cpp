#include "FabricaJogador.hpp"

std::unordered_map<TipoPersonagem, FabricaJogador::CriadorFuncao> FabricaJogador::registradores;

Player * FabricaJogador::criarJogador(float posx, float posy, TipoPersonagem tipo){

    auto it = registradores.find(tipo);
    if(it !=  registradores.end()){
        return it->second(posx, posy);
    }
    return nullptr;
}




