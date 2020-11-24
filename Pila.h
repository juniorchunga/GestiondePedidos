//
// Created by Junior Chunga on 07/11/2020.
//

#ifndef PRACTICA1_PILA_H
#define PRACTICA1_PILA_H


#include "Pedido.h"
#include "NodoPila.h"
#include "Cola.h"

class Pila {
public:
    Pila();
    ~Pila();
    void apilar(Pedido* valor);
    int cima();
    void desapilar();
    void verPila();
    bool vacia();
    void apilarPrioridad( Cola c);
    void dePilaACola(Cola cola);

private:
    NodoPila* ultimo;
};


#endif //PRACTICA1_PILA_H
