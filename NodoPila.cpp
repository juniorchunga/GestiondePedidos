//
// Created by Junior Chunga on 07/11/2020.
//

#include "NodoPila.h"

NodoPila::NodoPila(Pedido *valor, NodoPila *sig) {
    this->valor = valor;
    this->siguiente=sig;
}

NodoPila::~NodoPila() {}

