//
// Created by Junior Chunga on 23/11/20.
//

#ifndef PRACTICA1_LISTA_H
#define PRACTICA1_LISTA_H
#include "NodoLista.h"
#include "Pedido.h"
#include "Cola.h"

class Lista {
public:
    Lista();
    ~Lista();
    void insertarLista(Pedido* valor);
    void quitarLista();
    bool vacia();
    void deCola_a_Lista(Cola cola);
    void insertarLista_Registrados(Pedido* valor);
    void insertarLista_NoRegistrados(Pedido* valor);
    void ordenar();
    void juntarListas(Lista lista);
    void mostrarLista();




private:
    NodoLista* primero;
    NodoLista* ultimo;
};


#endif //PRACTICA1_LISTA_H
