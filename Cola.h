//
// Created by Junior Chunga on 07/11/2020.
//

#ifndef PRACTICA1_COLA_H
#define PRACTICA1_COLA_H

#include "Pedido.h"
#include "NodoCola.h"



class Cola {
public:
    Cola();
    ~Cola();

    void encolar(Pedido* v);
    Pedido* desencolar();
    Pedido* primero();
    bool esVacia();
    void verCola(Cola());

    void clasificar(Pedido* v, Cola cola1, Cola cola2);

    Cola clasificar(Pedido* v);

private:
    NodoCola *frente, *ultimo;
};


#endif //PRACTICA1_COLA_H
