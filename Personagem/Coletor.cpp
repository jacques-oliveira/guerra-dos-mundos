#include "Coletor.hpp"

Coletor::Coletor(float posx, float posy, TipoPersonagem tipo): Player(posx, posy, tipo){
}

Coletor::~Coletor(){
}

void Coletor::coletarRecurso(){
    std::cout<<"Coleta iniciada!"<<std::endl;
}



