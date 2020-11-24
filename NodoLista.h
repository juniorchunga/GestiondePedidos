//
// Created by Junior Chunga on 23/11/20.
//

#ifndef PRACTICA1_NODOLISTA_H
#define PRACTICA1_NODOLISTA_H

#include "Pedido.h"

class NodoLista {
public:
    NodoLista(Pedido* valor, NodoLista* sig);
    ~NodoLista();

private:
    Pedido* valor;
    NodoLista* siguiente;

    friend class Lista;

};


#endif //PRACTICA1_NODOLISTA_H
