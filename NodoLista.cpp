//
// Created by Junior Chunga on 23/11/20.
//

#include "NodoLista.h"

NodoLista::NodoLista(Pedido *valor, NodoLista *sig) {
    this->valor = valor;
    this->siguiente=sig;
}

NodoLista::~NodoLista() {}