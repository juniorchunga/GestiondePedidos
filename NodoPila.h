//
// Created by Junior Chunga on 07/11/2020.
//

#ifndef PRACTICA1_NODOPILA_H
#define PRACTICA1_NODOPILA_H

#include "Pedido.h"

class NodoPila {
public:
    NodoPila(Pedido* valor, NodoPila* sig);
    ~NodoPila();

private:
    Pedido* valor;
    NodoPila* siguiente;

    friend class Pila;
    friend class Lista;
};


#endif //PRACTICA1_NODOPILA_H
