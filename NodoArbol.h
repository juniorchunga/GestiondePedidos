//
// Created by Junior Chunga on 10/12/20.
//

#ifndef PRACTICA1_NODOARBOL_H
#define PRACTICA1_NODOARBOL_H
#include <iostream>
#include "Pedido.h"

using namespace std;

class NodoArbol {

public:
    NodoArbol(Pedido *pedido, NodoArbol *izq=NULL, NodoArbol *der=NULL);
    ~NodoArbol();

private:
    Pedido *pedido;
    NodoArbol *izquierda;
    NodoArbol *derecha;

    friend class Arbol;

};

#endif //PRACTICA1_NODOARBOL_H
