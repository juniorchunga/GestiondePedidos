//
// Created by Junior Chunga on 23/11/20.
//

#ifndef PRACTICA1_GESTOR_H
#define PRACTICA1_GESTOR_H

#include "Cola.h"
#include "Pila.h"
#include "Lista.h"
#include "Pedido.h"

// Programa en el que vendrá el núcleo del programa

class gestor {
public:
    gestor();

    ~gestor();

    int conteo();

    void encolar();

    void clasificar();

    void apilar();

    void alistar();

    void tipo_cliente(Pedido *pedido);

    void reiniciar();

    // Comprobaciones
    void mostrarCola();

    void mostrarPila();

    void mostrarLista();

private:
    Cola cola_reg;
    Cola cola_Noreg;
    Pila pilaErroneos;
    Pila pilaRegistrados;
    Pila pilaNoRegistrados;
    Lista listaPedidos;
    Lista listaRegistrados;
    Lista listaNoRegistrados;
    Pedido *valor;
    int contador;


};


#endif //PRACTICA1_GESTOR_H
