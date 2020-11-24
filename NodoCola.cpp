//
// Created by Junior Chunga on 07/11/2020.
//

#include "NodoCola.h"


NodoCola::NodoCola(Pedido* ped, NodoCola* sig)
{
    this ->valor = ped;
    this->siguiente = sig;
}

NodoCola::~NodoCola()
{
}