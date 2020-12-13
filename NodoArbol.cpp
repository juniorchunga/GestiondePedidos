//
// Created by Junior Chunga on 10/12/20.
//

#include "NodoArbol.h"


NodoArbol::NodoArbol(Pedido *pedido, NodoArbol *izq, NodoArbol *der) {
    this->pedido = pedido;
    this->izquierda = izq;
    this->derecha = der;
}

NodoArbol::~NodoArbol() {}