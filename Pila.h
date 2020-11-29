//
// Created by Junior Chunga on 07/11/2020.
//

#ifndef PRACTICA1_PILA_H
#define PRACTICA1_PILA_H

#include <iostream>
#include "Pedido.h"
#include "NodoPila.h"
#include "Cola.h"

using namespace std;

class Pila {
public:
    Pila();

    ~Pila();

    void apilar(Pedido *valor);

    Pedido* desapilar();

    bool vacia();

private:
    NodoPila *ultimo;
};


#endif //PRACTICA1_PILA_H
