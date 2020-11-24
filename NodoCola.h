//
// Created by Junior Chunga on 07/11/2020.
//

#ifndef PRACTICA1_NODOCOLA_H
#define PRACTICA1_NODOCOLA_H

#include "Pedido.h"

using namespace std;


class NodoCola {
public:
    NodoCola(Pedido* valor, NodoCola* sig);
    ~NodoCola();

private:
    Pedido* valor;
    NodoCola* siguiente;

    friend class Cola;
};


#endif //PRACTICA1_NODOCOLA_H
