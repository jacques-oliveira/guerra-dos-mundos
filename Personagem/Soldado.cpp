#include "Soldado.hpp"

Soldado::Soldado(float posx, float posy, TipoPersonagem tipo) : Player(posx, posy, tipo){

}

Soldado::~Soldado(){
}

void Soldado::gritoAtaque(){
    std::cout<<"Soldado Combate!"<<std::endl;
}




